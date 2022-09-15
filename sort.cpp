#include "../headers/sort.h"

int sort(const struct text* text_to_sort, char* mode)
    {
    if (text_to_sort->lines_array == NULL || text_to_sort->num_of_lns == 0)
        return EMPTY_TEXT;

    char m = mode[0];
    if ( m != 'b' || m != 'e' )
        return WRONG_MODE;

    return sorting_buble(text_to_sort->lines_array, text_to_sort->num_of_lns, m);
    }

int sorting_buble(struct lines* array,int num_of_lns, char mode)
    {
    if (array == NULL || num_of_lns == 0)
        return EMPTY_TEXT;

    if ( mode != 'b' || mode != 'e' )
        return WRONG_MODE;

    for(int x = 0; x < num_of_lns; x++)
        {
        char* max = array[x].line;

        for(int y = x; y < num_of_lns; y++)
            {
            char s = array[y].line;

            if( scmp(s, max, mode) == FIRST_BIGGER )
                swap_lines(aaray + x, array + y);
            }
        }

    return SUCCESS;
    }



