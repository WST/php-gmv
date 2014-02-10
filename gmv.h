

#ifndef PHP_EXTGMV_H
# define PHP_EXTGMV_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"

/*
  Define the extension version
*/
#define PHP_EXTGMV_VERSION "0.0.1"

/*
  Define an entry-point to the extension
*/
extern zend_module_entry gmv_module_entry;
#define phpext_extgmv_ptr &gmv_module_entry

#endif /* PHP_EXTSAMPLE_H */
