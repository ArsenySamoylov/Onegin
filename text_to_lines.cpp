#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../headers/text_to_lines.h"

struct text text_to_lines(const char* text)
    {
    assert(text != NULL);

    int num_of_lns= cnt_lines(text);
    //
    printf("Number of lines: %d\n", num_of_lns);
    //
    line* lines_array = (line*)calloc(num_of_lns + 1, sizeof(lines_array[0]));

    int current_line = 0;

    for(size_t i = 0, ch_cnt = 0; text[i] != '\0'; i++, ch_cnt++)
        {
        if (text[i] == '\n')
            {
            line l { (char*)(text+i-ch_cnt), ch_cnt } ;
            //(lines_array[current_line]).line     = (char*)(text+i-ch_cnt)
            //(lines_array[current_line]).num_of_ch = ch_cnt;
            lines_array[current_line] = l;

            ch_cnt = 0;
            current_line++;
            }

        }

    lines_array[num_of_lns] = { NULL, 0};
  /*  lines_array[0] = (line*)text;
    line++;

    size_t i = 0, ch_cnt = 0;

    while (text[i] != '\0')
        {
        ch_cnt++;
        if (text[i] == '\n')
            {
            lines_array[line]= (line*)(text + i + 1);
            line++;
            }
        //
        if(text[i] == '\n')
            printf("buffer[%d] = '\\n', %-p\n", i, &text[i]);
        else printf("buffer[%d] = %c, %-p\n", i,text[i], &text[i]);
        //
        i++;

        }
    //
    for(int i = 0; i<num_of_lns; i++)
        printf("%p pointer to line %d\n", lines_array[i], i+1);
    //
    lines_array[line] = NULL;
    printf("LINE IS: %d\n", line);   */

    struct text temp {lines_array, num_of_lns};
    return temp;
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
