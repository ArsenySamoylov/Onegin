#include <stdio.h>

#include "text.h"
#include "sort.h"

// "Sortityu_Zaebal!.exe" "../text/Hamlet.txt" "../result/PUSHKIN_LOX.txt"
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
    txt_checker(divide_text_in_lines(&Hamlet, buffer));

    //sorting from beggining of the line

    SORT(&Hamlet, STD_MODE);

    // sort_checker(sort(&Hamlet, "b"));
    FPUT(&Hamlet, result_file_direction, ORIGINAL);

    //sorting from end of the line

    SORT(&Hamlet, REVERSE_MODE);
    FPUT(&Hamlet, result_file_direction, SORTED);

    //put original

    FPUT(&Hamlet, result_file_direction, ORIGINAL);

    return 0;
    }

 void help()
    {
    printf("\n\n************* whassup nigggas, mc Pushkin here*********************\n"
           "This function is designed to make a raping texts for babies\n"
           "So if you want to rap better than Eminem, then run this programm\n"
           "with 2 arguments: source for your rap text and name of file,\n"
           "where to save your new banger\n"
           "************     ROUND !!!!!!!!!!!!!!!!!!  **************************\n\n");
    printf("Press any key to close programm\n");

    getchar();
    }


