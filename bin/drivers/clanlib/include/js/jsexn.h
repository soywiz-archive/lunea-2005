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

/*
 * JS runtime exception classes.
 */

#ifndef jsexn_h___
#define jsexn_h___

JS_BEGIN_EXTERN_C

/*
 * Initialize the exception constructor/prototype hierarchy.
 */
extern JSObject *
js_InitExceptionClasses(JSContext *cx, JSObject *obj);

/*
 * String constants naming the exception classes.
 */
extern const char js_Error_str[];
extern const char js_InternalError_str[];
extern const char js_EvalError_str[];
extern const char js_RangeError_str[];
extern const char js_ReferenceError_str[];
extern const char js_SyntaxError_str[];
extern const char js_TypeError_str[];
extern const char js_URIError_str[];

/*
 * Given a JSErrorReport, check to see if there is an exception associated with
 * the error number.  If there is, then create an appropriate exception object,
 * set it as the pending exception, and set the JSREPORT_EXCEPTION flag on the
 * error report.  Exception-aware host error reporters should probably ignore
 * error reports so flagged.  Returns JS_TRUE if an associated exception is
 * found and set, JS_FALSE otherwise..
 */
extern JSBool
js_ErrorToException(JSContext *cx, const char *message, JSErrorReport *reportp);

/*
 * Called if a JS API call to js_Execute or js_InternalCall fails; calls the
 * error reporter with the error report associated with any uncaught exception
 * that has been raised.  Returns true if there was an exception pending, and
 * the error reporter was actually called.
 *
 * The JSErrorReport * that the error reporter is called with is currently
 * associated with a JavaScript object, and is not guaranteed to persist after
 * the object is collected.  Any persistent uses of the JSErrorReport contents
 * should make their own copy.
 *
 * The flags field of the JSErrorReport will have the JSREPORT_EXCEPTION flag
 * set; embeddings that want to silently propagate JavaScript exceptions to
 * other contexts may want to use an error reporter that ignores errors with
 * this flag.
 */
extern JSBool
js_ReportUncaughtException(JSContext *cx);

extern JSErrorReport *
js_ErrorFromException(JSContext *cx, jsval exn);

JS_END_EXTERN_C

#endif /* jsexn_h___ */
