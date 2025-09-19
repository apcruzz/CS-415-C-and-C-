#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BUFFER 250   // max size of input line

int main() {
    char buffer[MAX_BUFFER];    // input buffer
    char *token;                // temporary token pointer
    char **tokens = NULL;       // dynamic array of strings (on heap)
    int num_tokens = 0;         // keep track of how many tokens we have

    // Step 1: Read input from user
    printf("Enter String: ");
    if (fgets(buffer, MAX_BUFFER, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = '\0';

    // Step 2: Tokenize input using strtok
    token = strtok(buffer, " ");  // first token split by whitespace
    while (token != NULL) {
        // Step 3: Allocate space for new token in heap
        tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
        if (tokens == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Copy token string to heap
        tokens[num_tokens] = malloc(strlen(token) + 1);
        if (tokens[num_tokens] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        strcpy(tokens[num_tokens], token);

        num_tokens++; // increase token count

        token = strtok(NULL, " "); // get next token
    }

    // Step 4: Put NULL at the end of array
    tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
    tokens[num_tokens] = NULL;

    // Step 5: Print tokens in a separate loop
    for (int i = 0; i < num_tokens; i++) {
        printf("Token[%d] = %s\n", i, tokens[i]);
    }

    // Step 6: Free memory
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);  // free each string
    }
    free(tokens);  // free array of pointers

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

