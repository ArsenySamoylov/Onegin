#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "text.h"

//add checking function
char* get_text(const char *file_direction)
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
        fclose(text);

        return NULL;
        }

    char* text_buffer = (char*)calloc(text_data.st_size + 1, sizeof(char));

    size_t number_of_ch = fread(text_buffer, sizeof(char), text_data.st_size, text);

    text_buffer = (char*)realloc(text_buffer, number_of_ch + 1);
    text_buffer[number_of_ch] = '\0';

    if ( feof(text) == 0 )
        {
        printf("Error occurred while reading file in path %s\n", file_direction);
        fclose(text);

        return NULL;
        }

    fclose(text);

    return text_buffer;
    }

int divide_text_in_lines(struct text* text, const char* buffer)
    {
    if (text   == NULL) return ERROR_TEXT;
    if (buffer == NULL) return EMPTY_BUFFER;

    int num_of_lns= cnt_lines(buffer);

    line* lines_array = (line*)calloc(num_of_lns + 1, sizeof(lines_array[0]));
    if (lines_array == NULL) return DYNAMIC_MEMORY_ERR;

    int current_line = 0;
    int symbl_in_line = 0;
    size_t i = 0;

    while( buffer[i] != '\0')
        {
        if (buffer[i] == '\n')
            {

            lines_array[current_line] = { (char*)(buffer + i - symbl_in_line), symbl_in_line};

            symbl_in_line = 0;
            current_line++;
            }

        if (buffer[i+1] == '\0')
            {
            lines_array[current_line] = { (char*)(buffer + i + 1 - symbl_in_line), symbl_in_line};

            symbl_in_line = 0;
            current_line++;
            }

        else
            symbl_in_line++;

        i++;

        }

    /*if (current_line < num_of_lns)
        {
        lines_array[current_line] = { (char*)(text+i-ch_cnt), ch_cnt};
        current_line++;
        }  */

    if (current_line != num_of_lns)
        return LINES_UNMATCHING;

    lines_array[num_of_lns] = { NULL, 0};

    *text = {buffer, lines_array, num_of_lns};
    return TXT_SUCCESS;
    }



int fput_txt(const struct text* t, const char* file_direction, const int mode)
    {
    if (t == NULL || t->buffer == NULL || t->lines_array == NULL)
        return ERROR_TEXT;

    if (file_direction == NULL)
        return EMPTY_DIRECTION;

    if (t->num_of_lns < 0)
        return NO_LINES;

    FILE* file = fopen(file_direction, "a");

    if (file == NULL)
        {
        return FILE_ERROR;
        }

    if (mode == ORIGINAL)
        {

        fputs("\n\n!!! ENGLISH LITERATURE  TEACHERS DON'T WORRY !!!!!!!!!!!!\n",   file);
        fputs(    "***************** ORIGINAL TEXT *************************\n\n", file);

        fputs(t->buffer, file);

        fputs("\n\n***************** END OF ORIGINAL ****************\n", file);
        fputs(    "***************** END OF ORIGINAL ****************\n", file);

        fclose(file);
        return ORIGINAL;
        }

    else if (mode == SORTED)
        {
        fputs("\n***************** SORTED   TEXT ******************\n",   file);
        fputs(  "***************** SORTED   TEXT ******************\n\n", file);

        line* arr      = t->lines_array;
        int num_of_lns = t->num_of_lns;

        for(int i = 0; i < num_of_lns; i++)
            {
            if ( (arr+i)->line[0] == '\n' )
                ;
            else
                fputl(arr+i, file);
            }
        fputs("\n\n**************** END OF SORTED ******************\n", file);
        fputs(    "**************** END OF SORTED ******************\n", file);

        fclose(file);
        return SORTED;
        }

    fclose(file);

    return UNEXPECTED_ERR;
    }

void txt_checker(int flag)
    {
    printf("txt_checker : ");

    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hconsole, (lt_red << 4) | white);
    switch(flag)
            {
             case TXT_SUCCESS:
                SetConsoleTextAttribute(hconsole, (lt_green << 4) | black);
                printf("Text successfully divided on lines\n");
                break;
             case ORIGINAL:
                SetConsoleTextAttribute(hconsole, (lt_green << 4) | lil);
                printf("Original text successfully was put in resulting file\n");
                break;
             case SORTED:
                SetConsoleTextAttribute(hconsole, (lt_green << 4) | blue);
                printf("Sorted text successfully was put in resulting file\n");
                break;
             case ERROR_TEXT:
                printf("Error within text strcuture\n");
                break;

             case EMPTY_DIRECTION:
                printf("Wrong direction for resulting file\n");
                break;

             case NO_LINES:
                printf("Resulting text has no lines\n");
                break;

            case FILE_ERROR:
                printf("Couldn't open resulting file");
                break;

             case EMPTY_BUFFER:
                printf("Error in buffer\n");
                break;

            case DYNAMIC_MEMORY_ERR:
                printf("Error occurred while allocating memory\n");
                break;

            case LINES_UNMATCHING:
                printf("Number of lines in buffer and in line array doesn't match\n");
                break;

            case UNEXPECTED_ERR:
            default:
                printf("Unexpected error occurred while writing in resulting file\n");
                break;
            }
        SetConsoleTextAttribute(hconsole, (black<<4) | std_cl);
    }

int cnt_lines(const char* text)
    {
    if (text == NULL)
        return -1;

    unsigned int num_of_lns = 0;

    long long i = 0;
    while (text[i] != '\0')
        {
        if (text[i] == '\n' || text[i+1] == '\0' )
            num_of_lns++;

        i++;
        }

    return num_of_lns;
    }
