#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    // if (argc != 3) {
    //     printf("Usage: %s <>gaurav.txt><output file>\n", argv[0]);
    //     return 1;
    // }

    // Open input file
    FILE *fptr = fopen(argv[1], "r");
    fopen("C:\\Users\\Atul Parihar\\Desktop\\Gp code\\C Notes\\newprogram.txt","r");
    if (fptr == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Open output file
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL) {
        printf("Error opening output file\n");
        fclose(fptr);
        return 1;
    }

    // Define buffer and max buffer size
    char buffer[256];
    int max_size = sizeof(buffer);

    // Read from input file, replace macros, and write to output file
    while (fgets(buffer, max_size, fptr) != NULL) {
        // Check if line contains a macro definition
        if (strstr(buffer, "#define ") != NULL) {
            // Extract macro name and value
            char *macro_name = strtok(buffer, " \t");
            macro_name = strtok(NULL, " \t");
            char *macro_value = strtok(NULL, " \n");

            // Replace all occurrences of macro in input file with its value
            char temp[max_size];
            while (fgets(temp, max_size, fptr) != NULL) {
                char *occurrence = strstr(temp, macro_name);
                while (occurrence != NULL) {
                    strncpy(occurrence, macro_value, strlen(macro_value));
                    occurrence = strstr(temp, macro_name);
                }
                fprintf(outfile, "%s", temp);
            }
        } else {
            // Write line to output file if it is not a macro definition
            fprintf(outfile, "%s", buffer);
        }
    }

    // Close input and output files
    fclose(fptr);
    fclose(outfile);

    return 0;
}
