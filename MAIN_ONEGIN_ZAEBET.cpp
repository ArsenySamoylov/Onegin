#include <stdio.h>

#include "../headers/line_functions.h"

#include "../headers/sort_text.h"

#include "../headers/text_buffer.h"
#include "../headers/text_to_lines.h"
//#include "../headers/sort.h"

int main()
    {

    char test[] = "../text/test1.txt";

    char* buffer = get_text(test);

    struct text Hamlet = text_to_lines(buffer);

   //
   printf("main{}\n");
    for(int i = 0; i<Hamlet.num_of_lns;i++)
        {
        line l = (Hamlet.lines_array)[i];
        putl(&l);

        }
   //

    printf("%d", Hamlet.num_of_lns);
    //sorting



    return 0;
    }




