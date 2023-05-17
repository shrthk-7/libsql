#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

typedef struct {
	char *buffer;
	int buffer_length;
	int input_length;
} Buffer;

Buffer 	*create_input_buffer();
void 		read_input(Buffer *input_buffer);
void 		close_input_buffer(Buffer *buffer);

#endif
