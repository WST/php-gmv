
#include "gmv.h"

// Function to read GMV header
void readMovieHeader(FILE *handle, MovieHeader *header) {
	fseek(handle, 0, SEEK_SET);
	fread(header, sizeof(MovieHeader), 1, handle);
}

PHP_FUNCTION(gmv_info);

const zend_function_entry gmv_functions[] = { PHP_FE(gmv_info, 0) {0, 0, 0} };

zend_module_entry gmv_module_entry = { STANDARD_MODULE_HEADER, "gmv", gmv_functions, 0, 0, 0, 0, 0, "0.1", STANDARD_MODULE_PROPERTIES };

ZEND_GET_MODULE(gmv)

PHP_FUNCTION(gmv_info) {
    char *filename;
    int length;

    // Parsing the arguments
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &length)) return;

    // Trying to open the provided GMV file
    FILE *handle = fopen(filename, "r");

    // Allocating some memory for the header
    MovieHeader *header = (MovieHeader *) malloc(sizeof(MovieHeader));

    // Reading file header
    readMovieHeader(handle, header);

    // Closing the opened GMV file
    fclose(handle);

    // Initializing the return value
    array_init(return_value);

    // Appending items to the return array
    // FIXME WARNING: there may be no ending zero in the comment!!!
    add_index_string(return_value, 0, header->comment, 1);
    add_index_long(return_value, 1, header->rerecords);
}
