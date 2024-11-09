#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *get_string(const char *prompt) 
{
    size_t size = 64;
    size_t length = 0;
    char *buffer = malloc(size);

    if (buffer == NULL) {
        perror("Unable to allocate memory");
        return NULL;
    }

    printf("%s", prompt);

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Check if buffer needs to be resized
        if (length + 1 >= size) {
            size *= 2;  // Double the size
            char *new_buffer = realloc(buffer, size);
            
            if (new_buffer == NULL) {
                free(buffer);  // Free the original buffer if realloc fails
                perror("Unable to reallocate memory");
                return NULL;
            }

            buffer = new_buffer;  // Only assign to buffer if realloc succeeds
        }

        buffer[length++] = ch;  // Add the character to the buffer
    }

    buffer[length] = '\0';  // Null-terminate the string
    return buffer;
}