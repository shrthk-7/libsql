#ifndef STATEMENT_H
#define STATEMENT_T

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "constants.h"
#include "buffer.h"

#define USERNAME_SIZE 32
#define EMAIL_SIZE		255

typedef enum { 
	STATEMENT_PREP_FAILURE, 
	STATEMENT_PREP_SUCCESS,
	STATEMENT_PREP_UNRECOGNIZED 
} Statement_prep_status;

typedef enum {
	STATEMENT_INSERT,
	STATEMENT_SELECT
} Statement_type;

typedef struct {
	uint32_t id;
	char username[USERNAME_SIZE];
	char email[EMAIL_SIZE];
} Row;

typedef struct {
	Statement_type type;
	Row row_to_insert;
} Statement;

Statement_prep_status prepare_statement(Buffer *input_buffer, Statement *statement);
void 									execute_statement(Statement *statement);

#endif