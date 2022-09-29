
/* This file was generated by idltool 53.24. Do not edit */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif
#ifndef PROTO_EXEC_H
#include <proto/exec.h>
#endif
#ifndef PROTO_DOS_H
#include <proto/dos.h>
#endif
#ifndef LIBRARIES_DUMMY_CHIP_H
#include <libraries/dummy_chip.h>
#endif
#ifndef LIBRARIES_MAYBE_BOARDINFO_H
#include <libraries/maybe_boardinfo.h>
#endif

/* forward declaration */
struct DummyChipIFace;

extern ULONG                VARARGS68K _dummy_chip_Obtain(struct DummyChipIFace *);
extern ULONG                VARARGS68K _dummy_chip_Release(struct DummyChipIFace *);
extern BOOL                 VARARGS68K _dummy_chip_FindCard(struct DummyChipIFace *, struct BoardInfo * bi);
extern void                 VARARGS68K _dummy_chip_InitCard(struct DummyChipIFace *, struct BoardInfo * bi, char ** ToolTypes);
extern BOOL                 VARARGS68K _dummy_chip_InitChip(struct DummyChipIFace *, struct BoardInfo * bi);
