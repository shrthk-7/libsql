#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/constants.h"
#include "headers/buffer.h"

Buffer *create_input_buffer() {
	Buffer *input_buffer 				= (Buffer*)malloc(sizeof(Buffer));
	input_buffer->buffer 				= NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length 	= 0;

	return input_buffer;
}

void read_input(Buffer *input_buffer) {
	int bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
	
	if(bytes_read <= 0) {
		printf("Error reading input\n");
		exit(READ_ERROR);
	}

	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;
}

void close_input_buffer(Buffer *buffer) {
	free(buffer->buffer);
	free(buffer);
}
