#include <stdio.h>
#include <stdlib.h>

#include "text.h"
#include "sort.h"

void help();

int main(int argc, const char *argv[])
    {
    if (argc < 3)
        {
        help();

        return -1;
        }

    const char* text_direction = argv[1];
    const char* result_file_direction = argv[2];

    char* buffer = get_text(text_direction);

    struct text Hamlet = {NULL, NULL, 0};
    DIVIDE_IN_LNS(&Hamlet, buffer);

    //sorting from beggining of the line

    SORT(&Hamlet, STD_MODE);
    FPUT(&Hamlet, result_file_direction, SORTED);

    //sorting from end of the line

    SORT(&Hamlet, REVERSE_MODE);
    FPUT(&Hamlet, result_file_direction, SORTED);

    //put original

    FPUT(&Hamlet, result_file_direction, ORIGINAL);

    /*test

    //TEST PUTL
    char s[] ="HELLOW WORLF!\nMOSCOW CALL";
    line l = {s, 13};
    FILE* f = fopen("FPUTL.txt", "w");
    putl(&l);
    fputl(&l, f);
    */

    //free memory
    free((void*)Hamlet.buffer);
    free((void*)Hamlet.lines_array);
    return 0;
    }

 void help()
    {
    printf("\n\n"
           "************* whassup nigggas, MC Pushkin here*********************\n"
           "This function is designed to make a raping texts for babies\n"
           "So if you want to rap better (i.e. rapper) than Eminem, then run this programm!!!\n"
           "with 2 arguments: source for your rap text and name of file to rap to,\n"
           "where to save your new banger??? Aaaa???? Eeeee???? Uuuuu!!! Wha u r doin here??? Wassup niggas???!!!\n"
           "************     ROUND !!!!!!!!!!!!!!!!!! (3.14 -> 3) *****************\n\n");
    printf("Press any key to close programm\n");

    getchar();
    }


