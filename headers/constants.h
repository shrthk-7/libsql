#ifndef CONSTANTS_H
#define CONSTANTS_H

#define READ_ERROR 		1932
#define EXIT_SUCCESS 	0
#define EXIT_FAILURE	1

typedef enum { 
	META_COMMAND_FAILURE, 
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED
} Meta_command_status;

typedef enum { 
	STATEMENT_PREP_FAILURE, 
	STATEMENT_PREP_SUCCESS,
	STATEMENT_PREP_UNRECOGNIZED 
} Statement_prep_status;

typedef enum {
	STATEMENT_INSERT,
	STATEMENT_SELECT
} Statement_type;

#endif