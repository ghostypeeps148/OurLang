/** file for the parser: 
should: (mostly in order, shouldn't all be in this file)
  * 1. Seperate each line
  * 2. Evaluate Macros and constants (ex, x + (0x20 + 8) -> x + 0x28)
  * 3. Import normal modules and include normal files (ex, files for IO, files for string operations, etc.)
Import.c
  * 4. include additional files by just copying the contents of the file in the position of the include directive (simplest way)
  * 5. Import additional modules (not python modules) from a directory specified
Functions.c
  * 6. Initialize global variables
  * 7. create a function table for calls to function

  * 8. Return an error if anything doesnt match the syntax

if possible:

Optimize.c
  * Optimize files to remove redundant and slow calls/ operations (optional but highly encouraged, also encourgaed to put in different file)
        1. Evaluate common functions (ex, len("string") -> 6, printf("hello\n") > puts("hello");
        2. Optimize memory operations (ex, 
var = 5 useless
var = 6
> var = 6
,
var = 5
func(var) 
> func(5)
)

should not:

interpret.c
  * 1. Execute actual code
  
*/
#include "parse.h"
#include "util.h"
int parse_lines(char* source) {
  // Duplicates string (might not be necessary) (but strtok modifies input so may cause weird errors idk)
  char *parseable = strdup(source);
  // Parse

  char *token;

  const char *delim = "\n";

  int line_num = 1;

  token = strtok(parseable, delim);

  while (token != NULL) {    
    printf("DEBUG: Line no: %d\n", line_num);
    if (token[0] == '#') {
      // comment
      printf("DEBUG: Comment, skipping\n");
    } else {
      parse_line(token, line_num);
    }
    line_num++;
    token = strtok(NULL, delim);
  }

  // Succeeded! Return 0
  return 0;
}

int parse_line(char* line, int line_number) {
  // Kinda validates the line (add more checks!)
  // Any string containing only letters for opcode and on the right can be anything
  // Please add more checks and/or improve this 
  printf("DEBUG: Line %d, parsing\n", line_number);
  char *opcode;
  char *parameter;
  opcode = strtok(strdup(line), ":");
  parameter = strtok(NULL, ":");

  if (parameter == NULL || opcode == NULL) {
    fprintf(stderr, "Syntax error: Something is malformed on line %d.\n", line_number);
    return -1;
  }
  char *trimmedop = trim_leading_spaces(opcode);
  char *trimmedin = trim_leading_spaces(parameter);
  printf("Opcode: %s\n", trimmedop);
  printf("Input: %s\n", trimmedin); 


  free(trimmedop);
  free(trimmedin);
  return 0;
}
