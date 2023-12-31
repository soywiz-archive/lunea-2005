/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express oqr
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is Mozilla Communicator client code, released
 * March 31, 1998.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 *
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU Public License (the "GPL"), in which case the
 * provisions of the GPL are applicable instead of those above.
 * If you wish to allow use of your version of this file only
 * under the terms of the GPL and not to allow others to use your
 * version of this file under the NPL, indicate your decision by
 * deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL.  If you do not delete
 * the provisions above, a recipient may use your version of this
 * file under either the NPL or the GPL.
 */

#ifndef jsopcode_h___
#define jsopcode_h___
/*
 * JS bytecode definitions.
 */
#include <stddef.h>
#include "jsprvtd.h"
#include "jspubtd.h"

JS_BEGIN_EXTERN_C

/*
 * JS operation bytecodes.
 */
typedef enum JSOp {
#define OPDEF(op,val,name,token,length,nuses,ndefs,prec,format) \
    op = val,
#include "jsopcode.tbl"
#undef OPDEF
    JSOP_LIMIT
} JSOp;

/*
 * JS bytecode formats.
 */
#define JOF_BYTE          0       /* single bytecode, no immediates */
#define JOF_JUMP          1       /* signed 16-bit jump offset immediate */
#define JOF_CONST         2       /* unsigned 16-bit constant pool index */
#define JOF_UINT16        3       /* unsigned 16-bit immediate operand */
#define JOF_TABLESWITCH   4       /* table switch */
#define JOF_LOOKUPSWITCH  5       /* lookup switch */
#define JOF_QARG          6       /* quickened get/set function argument ops */
#define JOF_QVAR          7       /* quickened get/set local variable ops */
#define JOF_DEFLOCALVAR   8       /* define local var with initial value */
#define JOF_TYPEMASK      0x000f  /* mask for above immediate types */
#define JOF_NAME          0x0010  /* name operation */
#define JOF_PROP          0x0020  /* obj.prop operation */
#define JOF_ELEM          0x0030  /* obj[index] operation */
#define JOF_MODEMASK      0x0030  /* mask for above addressing modes */
#define JOF_SET           0x0040  /* set (i.e., assignment) operation */
#define JOF_DEL           0x0080  /* delete operation */
#define JOF_DEC           0x0100  /* decrement (--, not ++) opcode */
#define JOF_INC           0x0200  /* increment (++, not --) opcode */
#define JOF_INCDEC        0x0300  /* increment or decrement opcode */
#define JOF_POST          0x0400  /* postorder increment or decrement */
#define JOF_IMPORT        0x0800  /* import property op */

/*
 * Immediate operand getters, setters, and bounds.
 */
#define JUMP_OFFSET_LEN         2
#define JUMP_OFFSET_HI(off)     ((jsbytecode)((off) >> 8))
#define JUMP_OFFSET_LO(off)     ((jsbytecode)(off))
#define GET_JUMP_OFFSET(pc)     ((int16)(((pc)[1] << 8) | (pc)[2]))
#define SET_JUMP_OFFSET(pc,off) ((pc)[1] = JUMP_OFFSET_HI(off),               \
				 (pc)[2] = JUMP_OFFSET_LO(off))
#define JUMP_OFFSET_MIN         ((int16)0x8000)
#define JUMP_OFFSET_MAX         ((int16)0x7fff)

#define ATOM_INDEX_LEN          2
#define ATOM_INDEX_HI(index)    ((jsbytecode)((index) >> 8))
#define ATOM_INDEX_LO(index)    ((jsbytecode)(index))
#define GET_ATOM_INDEX(pc)      ((jsatomid)(((pc)[1] << 8) | (pc)[2]))
#define SET_ATOM_INDEX(pc,index)((pc)[1] = ATOM_INDEX_HI(index),              \
				 (pc)[2] = ATOM_INDEX_LO(index))
#define GET_ATOM(cx,script,pc)  js_GetAtom((cx), &(script)->atomMap,          \
					   GET_ATOM_INDEX(pc))
#define ATOM_INDEX_LIMIT_LOG2   16
#define ATOM_INDEX_LIMIT        ((uint32)1 << ATOM_INDEX_LIMIT_LOG2)

#define ARGC_HI(argc)           ((jsbytecode)((argc) >> 8))
#define ARGC_LO(argc)           ((jsbytecode)(argc))
#define GET_ARGC(pc)            ((uintN)(((pc)[1] << 8) | (pc)[2]))
#define ARGC_LIMIT              ((uint32)1 << 16)

/* Synonyms for quick JOF_QARG and JOF_QVAR bytecodes. */
#define GET_ARGNO(pc)           GET_ARGC(pc)
#define SET_ARGNO(pc,argno)     SET_JUMP_OFFSET(pc,argno)
#define ARGNO_LEN               JUMP_OFFSET_LEN
#define GET_VARNO(pc)           GET_ARGC(pc)
#define SET_VARNO(pc,varno)     SET_JUMP_OFFSET(pc,varno)
#define VARNO_LEN               JUMP_OFFSET_LEN

struct JSCodeSpec {
    const char          *name;          /* JS bytecode name */
    const char          *token;         /* JS source literal or null */
    int8                length;         /* length including opcode byte */
    int8                nuses;          /* arity, -1 if variadic */
    int8                ndefs;          /* number of stack results */
    uint8               prec;           /* operator precedence */
    uint32              format;         /* immediate operand format */
};

extern char             js_const_str[];
extern char             js_var_str[];
extern char             js_function_str[];
extern char             js_in_str[];
extern char             js_instanceof_str[];
extern char             js_new_str[];
extern char             js_delete_str[];
extern char             js_typeof_str[];
extern char             js_void_str[];
extern char             js_null_str[];
extern char             js_this_str[];
extern char             js_false_str[];
extern char             js_true_str[];
extern JSCodeSpec       js_CodeSpec[];
extern uintN            js_NumCodeSpecs;
extern jschar           js_EscapeMap[];

/*
 * Return a GC'ed string containing the chars in str, with any non-printing
 * chars or quotes (' or " as specified by the quote argument) escaped, and
 * with the quote character at the beginning and end of the result string.
 */
extern JSString *
js_QuoteString(JSContext *cx, JSString *str, jschar quote);

/*
 * JSPrinter operations, for printf style message formatting.  The return
 * value from js_GetPrinterOutput() is the printer's cumulative output, in
 * a GC'ed string.
 */
extern JSPrinter *
js_NewPrinter(JSContext *cx, const char *name, uintN indent, JSBool pretty);

extern void
js_DestroyPrinter(JSPrinter *jp);

extern JSString *
js_GetPrinterOutput(JSPrinter *jp);

extern int
js_printf(JSPrinter *jp, const char *format, ...);

extern JSBool
js_puts(JSPrinter *jp, const char *s);

#ifdef DEBUG
/*
 * Disassemblers, for debugging only.
 */
#include <stdio.h>

extern JS_FRIEND_API(void)
js_Disassemble(JSContext *cx, JSScript *script, JSBool lines, FILE *fp);

extern JS_FRIEND_API(uintN)
js_Disassemble1(JSContext *cx, JSScript *script, jsbytecode *pc, uintN loc,
		JSBool lines, FILE *fp);
#endif /* DEBUG */

/*
 * Decompilers, for script, function, and expression pretty-printing.
 */
extern JSBool
js_DecompileCode(JSPrinter *jp, JSScript *script, jsbytecode *pc, uintN len);

extern JSBool
js_DecompileScript(JSPrinter *jp, JSScript *script);

extern JSBool
js_DecompileFunctionBody(JSPrinter *jp, JSFunction *fun);

extern JSBool
js_DecompileFunction(JSPrinter *jp, JSFunction *fun);

/*
 * Find the source expression that resulted in v, and return a new string
 * containing it.  Fall back on v's string conversion (fallback) if we can't
 * find the bytecode that generated and pushed v on the operand stack.
 *
 * Search the current stack frame if spindex is JSDVG_SEARCH_STACK.  Don't
 * look for v on the stack if spindex is JSDVG_IGNORE_STACK.  Otherwise,
 * spindex is the negative index of v, measured from cx->fp->sp, or from a
 * lower frame's sp if cx->fp is native.
 */
extern JSString *
js_DecompileValueGenerator(JSContext *cx, intN spindex, jsval v,
			   JSString *fallback);

#define JSDVG_IGNORE_STACK      0
#define JSDVG_SEARCH_STACK      1

JS_END_EXTERN_C

#endif /* jsopcode_h___ */
