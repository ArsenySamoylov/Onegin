#ifndef SORT_ZAEBET
#define SORT_ZAEBET

#include "line_functions.h"
#include "text.h"   // + colors

#define SORT(text, mode)    sort_checker(sort(text, mode));

enum sort_mode
    {
    BUFFER_MODE   = 0,
    STD_MODE      = 1,
    REVERSE_MODE  = -1,
    };

enum flag_sort
    {
    EMPTY_TEXT         = 0,
    WRONG_SORTING_MODE = -1,

    SORT_SUCCESS  = 1,
    };

int sort(struct text* text_to_sort, int mode);

int sorting_buble(struct line* array, const int num_of_lns, const int mode);

void sort_checker(int flag);

#endif
