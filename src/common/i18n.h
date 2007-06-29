/* i18n.h
 *	Copyright (C) 1998, 2001 Free Software Foundation, Inc.
 *
 * This file is free software; as a special exception the author gives
 * unlimited permission to copy and/or distribute it, with or without
 * modifications, as long as this notice is preserved.
 * 
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, to the extent permitted by law; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 */

#ifndef GNUPG_COMMON_I18N_H
#define GNUPG_COMMON_I18N_H

#ifdef USE_SIMPLE_GETTEXT
  int set_gettext_file( const char *filename );
  const char *gettext( const char *msgid );
# define _(a) gettext (a)
# define N_(a) (a)
#else
# ifdef HAVE_LOCALE_H
#  include <locale.h>	
# endif
# ifdef ENABLE_NLS
#  include <libintl.h>
#  define _(a) gettext (a)
#  ifdef gettext_noop
#   define N_(a) gettext_noop (a)
#  else
#   define N_(a) (a)
#  endif
# else
#  define _(a) (a)
#  define N_(a) (a)
# endif
#endif /*!USE_SIMPLE_GETTEXT*/

#endif /*GNUPG_COMMON_I18N_H*/
