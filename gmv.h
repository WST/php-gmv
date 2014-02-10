
#ifndef PHP_EXTGMV_H
#define PHP_EXTGMV_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#define PHP_EXTGMV_VERSION "0.0.1"
extern zend_module_entry gmv_module_entry;
#define phpext_extgmv_ptr &gmv_module_entry

#include <stdint.h>

typedef struct {
	uint8_t signature[15];
	uint8_t gmv_version;
	uint32_t rerecords;
	uint8_t joypad_keys[2];
	uint8_t flags;
	uint8_t ext_flags;
	uint8_t comment[40];
} MovieHeader;

#endif /* PHP_EXTSAMPLE_H */
