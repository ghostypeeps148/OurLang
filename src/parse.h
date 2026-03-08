#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Parse into lines and passes it down to the line compiler
int parse_lines(char* source);

// Parses individual lines
int parse_line(char* line, int line_number);

#endif
