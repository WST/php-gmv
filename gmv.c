
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
    if(!handle) {
    	RETURN_FALSE;
    }

    // Allocating some memory for the header
    MovieHeader *header = (MovieHeader *) malloc(sizeof(MovieHeader));

    // Reading file header
    readMovieHeader(handle, header);

    // Checking if the file is a proper GMV file
    // TODO

    // Closing the opened GMV file
    fclose(handle);

    // Initializing the return value
    array_init(return_value);

    // Getting the GMV comment
    char *comment = (char *) malloc(41);
    comment[40] = 0;
    memcpy(comment, header->comment, 40);

    // Appending items to the return array
    add_index_string(return_value, 0, comment, 1);
    add_index_long(return_value, 1, header->rerecords);

    // Cleanup
    free(header);
    free(comment);
}
