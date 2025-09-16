#include <stdio.h>
#include <string.h>

int main() {
    char data[100];  // buffer to hold input

    printf("Hello World\n");
    printf("Input: ");

    // fgets is safer than gets, reads up to 99 chars + '\0'
    if (fgets(data, sizeof(data), stdin) != NULL) {
        // remove newline character if present
        data[strcspn(data, "\n")] = '\0';
        printf("Output: %s\n\n", data);
    }

    return 0;
}
