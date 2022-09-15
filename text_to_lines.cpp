#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../headers/text_to_lines.h"
#include "../headers/line_functions.h"

struct text text_to_lines(const char* text)
    {
    assert(text != NULL);

    int num_of_lns= cnt_lines(text);
    /*
    printf("Number of lines: %d\n", num_of_lns);
    */
    line* lines_array = (line*)calloc(num_of_lns + 1, sizeof(lines_array[0]));

    int current_line = 0;
    int ch_cnt = 0;
    size_t i = 0;
    while( text[i] != '\0')
        {
        if (text[i] == '\n')
            {
            /*all symbols and theit adresses
            printf("\ti=%d, ch_cht=%d, i-chd=%d\n\t",i, ch_cnt, i-ch_cnt);
            end */

            //line l { (char*)(text+i-ch_cnt), ch_cnt } ;
            //lines_array[current_line] = l;
            lines_array[current_line] = { (char*)(text+i-ch_cnt), ch_cnt};

            ch_cnt = 0;
            current_line++;
            }
        else
            ch_cnt++;
        /*print all symbols and their adrese's
         if(text[i] == '\n')
                printf("s[%d] = '\\n', adress: %p\n",i, text+i);
            else
                printf("s[%d] = %c, adress: %p\n",i, text[i], text+i);
        */
        i++;


        }

    if (current_line < num_of_lns)
        {
        //line l { (char*)(text+i-ch_cnt), ch_cnt};
        lines_array[current_line] = { (char*)(text+i-ch_cnt), ch_cnt};
       // printf("SYMBOLS: %d", ch_cnt);
        current_line++;
        }
    if (current_line != num_of_lns)
        {
        printf("Number of lines doesn't match!\n");

        exit(1);
        }

    lines_array[num_of_lns] = { NULL, 0};

    /*PRINT RESULTING ARRAY
    printf("NUMBER OF LINES: %d\n", num_of_lns);
    for(int i = 0; i<num_of_lns+1; i++)
        {
        line line = lines_array[i];

        if (line.line == NULL && line.num_of_ch == 0)
            printf("Line %d is NULL and symbols %d\n",i+1, line.num_of_ch);
        else
            {
            printf("Line %d, symbols %d, point to %p\n",i+1,line.num_of_ch, line.line );
            putl(&line);
            //printf("\n");
            }
        }
      */

    struct text temp {(char*)text, lines_array, num_of_lns};
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
