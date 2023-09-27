#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 128
#define MAX_NUM_TOKENS 128

typedef struct {
  char* name;
  char* value;
} Macro;

int main(int argc, char** argv) {
  // Check for correct number of arguments
  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  // Open the input file
  char* input_file_name = argv[1];
  FILE* input_file = fopen(input_file_name, "r");
  if (input_file == NULL) {
    printf("Error opening input file '%s'\n", input_file_name);
    return 1;
  }

  // Create an array to store the macro definitions
  Macro macros[MAX_NUM_TOKENS];
  int num_macros = 0;

  // Read each line of the input file
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
    // Check if the line is a macro definition
    if (strncmp(line, "#define", 7) == 0) {
      // Extract the macro name and value from the line
      char* token;
      char* tokens[MAX_NUM_TOKENS];
      int num_tokens = 0;
      token = strtok(line, " \t");
      while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " \t");
      }
      if (num_tokens >= 3) {
        // Store the macro definition in the array
        macros[num_macros].name = strdup(tokens[1]);
        macros[num_macros].value = strdup(tokens[2]);
        num_macros++;
      }
    } else {
      // Replace occurrences of the macros with their values
      int i;
      for (i = 0; i < num_macros; i++) {
        Macro macro = macros[i];
        char* name = macro.name;
        char* value = macro.value;
        char* p = strstr(line, name);
        while (p != NULL) {
          // Replace the macro with its value
          int name_len = strlen(name);
          int value_len = strlen(value);
          memmove(p + value_len, p + name_len, strlen(p + name_len) + 1);
          memcpy(p, value, value_len);
          p = strstr(line, name);
        }
      }

      // Print the modified line
      printf("%s", line);
    }
  }

  // Close the input file
  fclose(input_file
