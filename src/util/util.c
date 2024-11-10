#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *get_string(const char *prompt) {
    size_t buffer_size = 32;
    size_t length = 0;
    char *input = malloc(buffer_size * sizeof(char));

    if (input == NULL) return NULL;

    printf("%s", prompt);

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length + 1 >= buffer_size) {
            buffer_size *= 2;
            input = realloc(input, buffer_size);
            if (input == NULL) return NULL;
        }
        input[length++] = ch;
    }

    input[length] = '\0';
    return input;
}
