#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "headers/constants.h"
#include "headers/buffer.h"
#include "headers/statement.h"

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