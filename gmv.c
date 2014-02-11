
/*
* © 2014 Ilya I. Averkov (WST)
* http://averkov.net
*/

#include "gmv.h"

void readMovieHeader(FILE *handle, MovieHeader *header) {
	fseek(handle, 0, SEEK_SET);
	fread(header, sizeof(MovieHeader), 1, handle);
}

uint8_t getInputFrameRate(MovieHeader *header) {
	return (header->flags & (1 << 7)) ? 50 : 60;
}

uint8_t movieRequiresSavestate(MovieHeader *header) {
	return (header->flags & (1 << 6));
}

uint8_t getInputControllerNumber(MovieHeader *header) {
	return (header->flags & (1 << 5)) ? 3 : 2;
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
	if(!handle) RETURN_FALSE;

	// Reading file header
	MovieHeader header;
	readMovieHeader(handle, & header);

	// Checking if the file is a proper GMV file
	char signature[16];
	signature[15] = 0;
	memcpy(signature, header.signature, 15);
	if(strcmp(signature, "Gens Movie TEST")) RETURN_FALSE;

	// Closing the opened GMV file
	fclose(handle);

	// Initializing the return value
	array_init(return_value);

	// Getting the GMV comment
	char comment[41];
	comment[40] = 0;
	memcpy(comment, header.comment, 40);

	// Appending items to the return array
	add_index_string(return_value, 0, comment, 1);
	add_index_long(return_value, 1, header.rerecords);
	add_index_long(return_value, 2, getInputFrameRate(& header));
	add_index_bool(return_value, 3, movieRequiresSavestate(& header));
	add_index_long(return_value, 4, getInputControllerNumber(& header));
}
