#include <stdio.h>
#include <stdlib.h>
#include <cctype>

#include "line_functions.h"

int putl( const struct line* l )
    {

    const char* s = l->line;

    int flag_error = EOF;
    int i = 0;

    while (s[i] != '\0' && s[i] != '\n')
        flag_error = putchar(s[i++]);

    flag_error = putchar('\n');

    return flag_error;
    }

int fputl( const struct line* l, FILE *out )
    {
    if (out == NULL)
        return -1;

    const char* s = l->line;

    int flag_error = EOF;
    int i = 0;

    while (s[i] != '\0' && s[i] != '\n')
        flag_error = fputc(s[i++], out);

    flag_error = fputc('\n', out);

    return flag_error;
    }

int scmp(const struct line* l1, const struct line* l2, const int mode)
    {
    if (l1 == NULL || l2 == NULL)
        return ERROR_NULL_LINE;

    if (mode == STD_MODE)
        {
        char* s1 = skip_unnecessary_smb(l1->line);
        char* s2 = skip_unnecessary_smb(l2->line);

        if (s1[0] == '\n' || s2[0] == '\n')
            return (s2[0] == '\n') ? FIRST_BIGGER:SECOND_BIGGER;
        int i = 0;
        while ( (s1[i] != '\n' && s1[i] != '\0') && (s2[i] != '\n' && s2[i] != '\0') )
            {
            if (tolower(s1[i]) - tolower(s2[i]) != 0)
                return (tolower(s1[i]) - tolower(s2[i]) < 0) ? FIRST_BIGGER:SECOND_BIGGER;
            i++;
            }
        int len1 = l1->num_of_ch;
        int len2 = l2->num_of_ch;

        if (len1 != len2)
            return (len1 - len2 > 0) ? FIRST_BIGGER:SECOND_BIGGER;

        return SAME;
        }

    if (mode == REVERSE_MODE)
        {
        char* s1 = l1->line;
        int len1 = l1->num_of_ch - 1;

        char* s2 = l2->line;
        int len2 = l2->num_of_ch - 1;

        while( len1 >= 0 && len2 >= 0)
            {
            if (tolower(s1[len1]) != tolower(s2[len2]))
                return (tolower(s1[len1]) - tolower(s2[len2]) < 0) ? FIRST_BIGGER: SECOND_BIGGER;

            len1--;
            len2--;
            }
        if (len1 != len2)
            return (len1 > len2) ? FIRST_BIGGER:SECOND_BIGGER;

        return SAME;
        }


    return WRONG_MODE;
    }

char* skip_unnecessary_smb(const char *s)
    {
    int i = 0;

    while (s[i] != '\n' && s[i] != '\0' && isalpha(s[i]) == 0)
        i++;

    return (char*)(s+i);
    }

void swap_lines(line* l1, line* l2)
    {
    line temp = *l1;
    *l1 = *l2;
    *l2 = temp;
    }


/*
int main()
    {
    line l1 = {"!#5969Addnngn", 10}, l2 = {"aajfjsj",10};


    printf("%d\n",scmp(&l1,&l2, 'b'));

   // printf("%p l1\n%p l2\n",&l1, &l2);

    swap_lines(&l1, &l2);

    putl(&l1);
    putl(&l2);
    return 0;
    }
 */
