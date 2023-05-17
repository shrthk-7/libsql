#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

typedef struct {
	char *buffer;
	int 	buffer_length;
	int 	input_length;
} Buffer;

typedef struct {
	char *value;
} Statement;

Buffer *create_input_buffer() {
	Buffer *input_buffer 				= (Buffer*)malloc(sizeof(Buffer));
	input_buffer->buffer 				= NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length 	= 0;

	return input_buffer;
}

void prompt() {
	printf(">>> ");
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

int perform_meta_command(Buffer *buffer) {
	return META_COMMAND_SUCCESS;
}

int main(int argc, char** argv){
	Buffer* input_buffer = create_input_buffer();

	while(1) {
		prompt();
		read_input(input_buffer);

		if(strcmp(input_buffer->buffer, ".exit") == 0) {
			printf("Exiting...");
			exit(EXIT_SUCCESS);
		}

		if(input_buffer->buffer[0] == '.') {
			switch(perform_meta_command(input_buffer)) {
				case META_COMMAND_SUCCESS: {

				}
				case META_COMMAND_FAILURE: {

				}
				case META_COMMAND_UNRECOGNIZED: {
					printf("Unrecognized meta command: %s\n", input_buffer->buffer);
					break;
				}
				default: continue;
			}
		}

		printf("Unrecognized Command: %s \n", input_buffer->buffer);
	}
}