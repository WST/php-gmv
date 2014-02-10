
#include "gmv.h"

PHP_FUNCTION(gmv_info);

const zend_function_entry gmv_functions[] = { PHP_FE(gmv_info, 0) {0, 0, 0} };

zend_module_entry gmv_module_entry = { STANDARD_MODULE_HEADER, "gmv", gmv_functions, 0, 0, 0, 0, 0, "0.1", STANDARD_MODULE_PROPERTIES };

ZEND_GET_MODULE(gmv)

PHP_FUNCTION(gmv_info) {
    char *filename;
    int length;

    // Our return value
    array_init(return_value);
    add_index_long(return_value, 123, 456);

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &length)) return;

    //RETURN_ZVAL(return_value, 1, 1);
}
