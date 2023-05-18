#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "headers/constants.h"
#include "headers/buffer.h"

#define USERNAME_SIZE 32
#define EMAIL_SIZE		255

typedef struct {
	uint32_t id;
	char username[USERNAME_SIZE];
	char email[EMAIL_SIZE];
} Row;

typedef struct {
	Statement_type type;
	Row row_to_insert;
} Statement;

void prompt() {
	printf(">>> ");
}

Statement_prep_status prepare_statement(Buffer *input_buffer, Statement *statement) {
	/*
		General format of insert:
			insert <row number> <username> <email>
	*/
	if(strncmp(input_buffer->buffer, "insert", 6) == 0) {
		statement->type = STATEMENT_INSERT;
		int args = sscanf(
			input_buffer->buffer, 
			"insert %d %s %s",
			&(statement->row_to_insert.id),
			statement->row_to_insert.username,
			statement->row_to_insert.email
		);

		if(args < 3) return STATEMENT_PREP_FAILURE;
		return STATEMENT_PREP_SUCCESS;
	}
	
	if(strncmp(input_buffer->buffer, "select", 6) == 0) {
		statement->type = STATEMENT_SELECT;
		return STATEMENT_PREP_SUCCESS;
	}

	return STATEMENT_PREP_UNRECOGNIZED;
}

Meta_command_status perform_meta_command(Buffer *input_buffer) {
	if(strcmp(input_buffer->buffer, ".exit") == 0) {
		printf("Exiting...");
		exit(EXIT_SUCCESS);
	}
	return META_COMMAND_UNRECOGNIZED;
}

void execute_statement(Statement *statement) {
	switch (statement->type) {
		case STATEMENT_INSERT:
			printf("=> row 		: %u \n", statement->row_to_insert.id);
			printf("=> email 	: %s \n", statement->row_to_insert.email);
			printf("=> user 	: %s \n", statement->row_to_insert.username);
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