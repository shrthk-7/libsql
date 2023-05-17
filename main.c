#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/constants.h"
#include "headers/buffer.h"

typedef struct {
	char *value;
} Statement;

void prompt() {
	printf(">>> ");
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