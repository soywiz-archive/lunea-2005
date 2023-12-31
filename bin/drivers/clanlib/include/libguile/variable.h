/* classes: h_files */

#ifndef VARIABLEH
#define VARIABLEH
/*	Copyright (C) 1995,1996, 2000 Free Software Foundation, Inc.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA
 *
 * As a special exception, the Free Software Foundation gives permission
 * for additional uses of the text contained in its release of GUILE.
 *
 * The exception is that, if you link the GUILE library with other files
 * to produce an executable, this does not by itself cause the
 * resulting executable to be covered by the GNU General Public License.
 * Your use of that executable is in no way restricted on account of
 * linking the GUILE library code into it.
 *
 * This exception does not however invalidate any other reasons why
 * the executable file might be covered by the GNU General Public License.
 *
 * This exception applies only to the code released by the
 * Free Software Foundation under the name GUILE.  If you copy
 * code from other Free Software Foundation releases into a copy of
 * GUILE, as the General Public License permits, the exception does
 * not apply to the code that you add in this way.  To avoid misleading
 * anyone as to the status of such modified files, you must delete
 * this exception notice from them.
 *
 * If you write modifications of your own for GUILE, it is your choice
 * whether to permit this exception to apply to your modifications.
 * If you do not wish that, delete this exception notice.  */

/* Software engineering face-lift by Greg J. Badros, 11-Dec-1999,
   gjb@cs.washington.edu, http://www.cs.washington.edu/homes/gjb */

#include "libguile/__scm.h"




/* Variables 
 */
GUILE_API extern int scm_tc16_variable;

#define SCM_VARVCELL(V) 	SCM_CDR(V)
#define SCM_VARIABLEP(X)   	(!SCM_IMP (X) && SCM_CELL_TYPE (X) == scm_tc16_variable)
#define SCM_UDVARIABLEP(X) 	(SCM_VARIABLEP(X) && SCM_UNBNDP (SCM_CDR (SCM_VARVCELL (X))))
#define SCM_DEFVARIABLEP(X) 	(SCM_VARIABLEP(X) && !SCM_UNBNDP (SCM_CDR (SCM_VARVCELL (X))))



GUILE_API extern SCM scm_make_variable (SCM init, SCM name_hint);
GUILE_API extern SCM scm_make_undefined_variable (SCM name_hint);
GUILE_API extern SCM scm_variable_p (SCM obj);
GUILE_API extern SCM scm_variable_ref (SCM var);
GUILE_API extern SCM scm_variable_set_x (SCM var, SCM val);
GUILE_API extern SCM scm_builtin_variable (SCM name);
GUILE_API extern SCM scm_variable_bound_p (SCM var);
GUILE_API extern void scm_init_variable (void);

#endif  /* VARIABLEH */

/*
  Local Variables:
  c-file-style: "gnu"
  End:
*/
