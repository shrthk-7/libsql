#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/constants.h"
#include "headers/buffer.h"

typedef struct {
	Statement_type type; 
} Statement;

void prompt() {
	printf(">>> ");
}

Statement_prep_status prepare_statement(Buffer *buffer, Statement *statement) {
	if(strncmp(buffer->buffer, "insert", 6) == 0) {
		statement->type = STATEMENT_INSERT;
		return STATEMENT_PREP_SUCCESS;
	}
	if(strncmp(buffer->buffer, "select", 6) == 0) {
		statement->type = STATEMENT_SELECT;
		return STATEMENT_PREP_SUCCESS;
	}

	return STATEMENT_PREP_UNRECOGNIZED;
}

Meta_command_status perform_meta_command(Buffer *buffer) {
	if(strcmp(buffer->buffer, ".exit") == 0) {
		printf("Exiting...");
		exit(EXIT_SUCCESS);
	}
	return META_COMMAND_UNRECOGNIZED;
}

void execute_statement(Statement *statement) {
	switch (statement->type) {
		case STATEMENT_INSERT:
			printf("=> insert function called\n");
			break;
		
		case STATEMENT_SELECT:
			printf("=> select function called\n");
			break;

		default:
			break;
	}
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