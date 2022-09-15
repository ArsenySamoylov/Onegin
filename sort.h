#ifndef SORT_ZAEBET
#define SORT_ZAEBET

#include "../headers/line_functions.h"
#include "../headers/text_to_lines.h"
enum status
    {
    EMPTY_TEXT = 0,
    WRONG_MODE = -1,

    SUCCESS = 1
    };

int sort(const struct *text text_to_sort, char* mode);
int sorting_buble(struct lines* array,int num_of_lns, char mode);

#endif
