
#include "sort.h"

int sort(struct text* text_to_sort, int mode)
    {
    if (text_to_sort->lines_array == NULL || text_to_sort->num_of_lns == 0)  return EMPTY_TEXT;
    if (mode != STD_MODE && mode != REVERSE_MODE && mode != BUFFER_MODE)     return WRONG_MODE;

    //return sorting_buble(text_to_sort->lines_array, text_to_sort->num_of_lns, mode);
    line* l_array  = (text_to_sort->lines_array);
    ssize_t number = (text_to_sort)->num_of_lns ;

    if (mode == STD_MODE)
        qsort(l_array, number, sizeof(line), standard_line_comparartor);

    if (mode == REVERSE_MODE)
        qsort(l_array, number, sizeof(line), reverse_line_comparator);

    return  QUICK_SORT;
    }


int sorting_buble(struct line* array, const int num_of_lns, const int mode)
    {
    if (array == NULL || num_of_lns == 0)                                     return EMPTY_TEXT;
    if (mode != STD_MODE && mode != REVERSE_MODE && mode != BUFFER_MODE)      return WRONG_SORTING_MODE;

    for(int x = 0; x < num_of_lns; x++)
        {
        line* max = (line*)(array + x);

        for(int y = x; y < num_of_lns; y++)
            {
            if (scmp(array + y, max, mode) == FIRST_BIGGER)
                swap_lines(array + x, array + y);
            }
        }

    return SORT_SUCCESS;
    }

void sort_checker(int flag)
    {
    printf("sort_checker: ");

    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hconsole, (lt_red << 4) | white);

    switch(flag)
        {
        case QUICK_SORT:
            SetConsoleTextAttribute(hconsole, (lt_blue << 4) | black);
            printf("Quick sort activated\n");
            break;

        case SORT_SUCCESS:
            SetConsoleTextAttribute(hconsole, (lt_green << 4) | black);
            printf("Text was successfully sorted\n");
            break;

        case EMPTY_TEXT:
            printf("Text is empty!\n");
            break;

        case WRONG_SORTING_MODE:
            printf("Wrong sorting mode\n");
            break;

        default:
            printf("Unexpected sorting error\n");
        }

    SetConsoleTextAttribute(hconsole, (black<<4) | std_cl);
    }
