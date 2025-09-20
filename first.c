#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 250
#define DELIM " \t\n"

int main() {
    char input[BUFFER_SIZE];
    char *token;
    char **tokens = NULL;
    int token_count = 0;

    // Prompt user
    printf("Enter Strings: ");
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Tokenize input
    token = strtok(input, DELIM);
    while (token != NULL) {
        // Allocate space for new token pointer
        tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
        if (tokens == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }

        // Allocate space for the token string and copy it
        tokens[token_count] = malloc(strlen(token) + 1);
        if (tokens[token_count] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }
        strcpy(tokens[token_count], token);

        token_count++;
        token = strtok(NULL, " ");
    }

    // Add NULL terminator to the array
    tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    tokens[token_count] = NULL;

    // Print tokens in a separate loop
    for (int i = 0; i < token_count; i++) {
        printf("Token[%d] = %s\n", i, tokens[i]);
    }

    // Free memory
    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}


    // char data[100];  // buffer to hold input

    // printf("Hello World\n");
    // printf("Input: ");

    // // fgets is safer than gets, reads up to 99 chars + '\0'
    // if (fgets(data, sizeof(data), stdin) != NULL) {
    //     // remove newline character if present
    //     data[strcspn(data, "\n")] = '\0';
    //     printf("Output: %s\n\n", data);
    // }

    // return 0;

