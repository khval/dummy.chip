/* :ts=4
 *  $VER: InitCard.c $Revision$ (29-Sep-2022)
 *
 *  This file is part of dummy_chip.
 *
 *  Copyright (c) 2022 LiveForIt Software.
 *  LGPL.
 *
 * $Id$
 *
 * $Log$
 *
 *
 */

#define __USE_INLINE__

#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <exec/Interrupts.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <libraries/dummy_card.h>
#include <proto/dummy_card.h>
#include <stdarg.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../functions.h"

/****** dummy_card/main/InitCard ******************************************
*
*   NAME
*      InitCard -- Description
*
*   SYNOPSIS
*      void InitCard(struct BoardInfo * bi, char ** ToolTypes);
*
*   FUNCTION
*
*   INPUTS
*       bi - 
*       ToolTypes - 
*
*   RESULT
*       This function does not return a result
*
*   EXAMPLE
*
*   NOTES
*
*   BUGS
*
*   SEE ALSO
*
*****************************************************************************
*
*/

extern struct Library *ExecBase;

struct SignalSemaphore *BoardLock;

struct ChipBase chipbase;
//struct CardBase cardbase;


void hard()
{
	DebugPrintF("hard\n");
}

void soft()
{
	DebugPrintF("soft\n");
}


void init_int( struct Interrupt *i, VOID (*ifn)() )
{
	i -> is_Node.ln_Pri  = 50;  
	i -> is_Node.ln_Name = "Example Handler";  
	i -> is_Node.ln_Type = NT_INTERRUPT;
	i -> is_Data = 0;
	i -> is_Code = ifn;
}

extern void init_api( struct BoardInfo * bi );

const char *name = "test dummy card";

void _dummy_card_InitCard(struct DummycardIFace *Self, struct BoardInfo * bi, char ** ToolTypes)
{
//	struct ExecBase *ExecBase = (struct ExecIFace *)(*(struct ExecBase **)4);

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("%s:%s:%d ExecBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, bi-> ExecBase);
	printf("%s:%s:%d UtilBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, bi-> UtilBase);
	printf("%s:%s:%d CardBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, bi-> CardBase);
	printf("%s:%s:%d ChipBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, bi-> ChipBase);

	// setup init data.

	bi -> BoardName = name;
	sprintf(bi -> VBIName,"%s",name);

//	bi -> CardBase = &cardbase;		// this one looks like is setup from before.

	bi -> ChipBase = &chipbase;		// we can setup this... maybe not needed.

//	bi -> ExecBase = ExecBase;		// this one is setup by rtg.library !!
//	bi -> UtilBase = NULL;			// this one is setup by rtg.library !!

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("%s:%s:%d ExecBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, bi-> ExecBase);
	printf("%s:%s:%d UtilBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, bi-> UtilBase);
	printf("%s:%s:%d CardBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, bi-> CardBase);
	printf("%s:%s:%d ChipBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, bi-> ChipBase);

	init_int( &(bi -> HardInterrupt), hard );
	init_int( &(bi -> SoftInterrupt), soft ) ;

	InitSemaphore( &bi -> BoardLock );
	NewMinList( &bi -> ResolutionsList );

	bi -> BoardType = BT_powerfb;

	bi -> PaletteChipType = 0;
	bi -> GraphicsControllerType = 0;
	bi -> MoniSwitch = 0;
	bi -> BitsPerCannon = 8;
	bi -> Flags = BIF_NOBLITTER | BIF_NOP2CBLITS |  BIF_NOMASKBLITS | BIF_NEEDSALIGNMENT;
	bi -> SoftSpriteFlags = 0;

	bi -> RGBFormats = MAXMODES;


	// setup functions.

	init_api( bi );

	printf("%s:%s:%d End of Function\n",__FILE__,__FUNCTION__,__LINE__);

}
