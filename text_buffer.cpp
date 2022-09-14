#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>

#include "../headers/text_buffer.h"

char* get_text(char *file_direction)
    {
    FILE *text = fopen(file_direction, "r");

    if (text == NULL)
        {
        printf("File with text wasn't found in %s", file_direction);

        fclose(text);
        return NULL;
        }

    struct stat text_data;
    stat(file_direction, &text_data);

    if (text_data.st_size < 1)
        {
        printf("File %s is empty\n", file_direction);
        return NULL;
        }

    char* text_buffer = (char*)calloc(text_data.st_size + 1, sizeof(char));

    size_t number_of_ch = fread(text_buffer, sizeof(char), text_data.st_size, text);

    text_buffer = (char*)realloc(text_buffer, number_of_ch + 1);
    text_buffer[number_of_ch] = '\0';

    //printf("%c", text_buffer[text_data.st_size]);
    if ( feof(text) == 0 )
        {
        printf("Error occurred while reading file in path %s\n", file_direction);
        return NULL;
        }

    return text_buffer;
    }
