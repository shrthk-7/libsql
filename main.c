#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "headers/constants.h"
#include "headers/buffer.h"
#include "headers/statement.h"

void prompt() {
	printf(">>> ");
}

Meta_command_status perform_meta_command(Buffer *input_buffer) {
	if(strcmp(input_buffer->buffer, ".exit") == 0) {
		printf("Exiting...");
		exit(EXIT_SUCCESS);
	}
	return META_COMMAND_UNRECOGNIZED;
}

int main(int argc, char** argv){
	Buffer* input_buffer = create_input_buffer();

	while(1) {
		prompt();
		read_input(input_buffer);

		if(input_buffer->buffer[0] == '.') {
			switch(perform_meta_command(input_buffer)) {
				case META_COMMAND_SUCCESS: {

				}
				case META_COMMAND_FAILURE: {

				}
				case META_COMMAND_UNRECOGNIZED: {
					printf("Unrecognized Meta Command: %s\n", input_buffer->buffer);
					continue;
				}
				default: break;
			}
		}

		Statement statement;
		switch (prepare_statement(input_buffer, &statement)) {
			case STATEMENT_PREP_SUCCESS: {
				break;
			}
			case STATEMENT_PREP_UNRECOGNIZED: {
				printf("Unrecognized Keyword at start of '%s'\n", input_buffer->buffer);
				continue;
			}
			default: break;
		}

		execute_statement(&statement);
	}
}