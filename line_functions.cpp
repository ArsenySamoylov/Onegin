#include <stdio.h>
#include <stdlib.h>
#include <cctype>

#include "line_functions.h"

int putl( const struct line* ln )
    {
    const char* str   = ln->line;
    int num_of_ch     = ln->num_of_ch;

    int put_symb = (int)fwrite(str, sizeof(str[0]), num_of_ch + 1, stdin);

    if (put_symb != num_of_ch + 1)
        return EOF;

    return put_symb;
    }

int fputl( const struct line* ln, FILE *out )
    {
    if (out == NULL) return -1;

    if (out == NULL) return -1;

    const char* str = ln->line;
    int num_of_ch   = ln->num_of_ch;

    int put_symb = (int)fwrite(str, sizeof(str[0]), num_of_ch + 1, out);

    if (put_symb != num_of_ch + 1)
        return EOF;

    return put_symb;
    }

int scmp(const struct line* ln1, const struct line* ln2, const int mode)
    {
    if (ln1 == NULL || ln2 == NULL) return ERROR_NULL_LINE;

    if (mode == STD_MODE)
        {
        char* s1 = skip_unnecessary_smb(ln1->line);
        char* s2 = skip_unnecessary_smb(ln2->line);

        assert (s1 != NULL && s2 != NULL);

        if (*s1 == '\n' || *s2 == '\n')
            return (*s2 == '\n') ? FIRST_BIGGER : SECOND_BIGGER;

        while ( ( *s1 != '\n' && *s1 != '\0') && (*s2 != '\n' && *s2 != '\0') )
            {
            int compare = tolower(*s1) - tolower(*s2);

            if (compare != 0)
                return compare;

            if (compare != 0)
                return (compare < 0) ? FIRST_BIGGER : SECOND_BIGGER;

            s1++;
            s2++;
            }

        int len1 = ln1->num_of_ch;
        int len2 = ln2->num_of_ch;

        if (len1 != len2)
            return (len1 - len2 > 0) ? FIRST_BIGGER:SECOND_BIGGER;

        return SAME;
        }
        
    //doesn't work all that good =(( (add skipping of unnecessary smbl)
    if (mode == REVERSE_MODE)
        {
        char* s1 = ln1->line;
        int len1 = ln1->num_of_ch - 1;

        char* s2 = ln2->line;
        int len2 = ln2->num_of_ch - 1;

        assert(s1 != NULL && s2 != NULL);

        while( len1 >= 0 && len2 >= 0)
            {
            int compare = tolower(*(s1+len1)) - tolower(*(s2+len2));

            if (compare != 0)
                return (compare < 0) ? FIRST_BIGGER: SECOND_BIGGER;

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
    //int i = 0;

    while (*s != '\n' && *s != '\0' && isalpha(*s) == 0)
      //  i++;
            s++;

    return (char*)(s);
    }

void swap_lines(line* l1, line* l2)
    {
    line temp = *l1;
    *l1 = *l2;
    *l2 = temp;
    }

int standard_line_comparartor( const void* ln1, const void* ln2 )
    {
    assert(ln1 != NULL && ln2 !=NULL);

    char* s1 = skip_unnecessary_smb( ((line*)ln1) -> line );
    char* s2 = skip_unnecessary_smb( ((line*)ln2) -> line );

    assert(s1 != NULL && s2 !=NULL);

    if (*s1 == '\n' || *s2 == '\n')
        return (*s2 == '\n') ? FIRST_BIGGER:SECOND_BIGGER;

    while ( (*s1 != '\n' && *s1 != '\0') && (*s2 != '\n' && *s2 != '\0') )
        {
        int compare = tolower(*s1) - tolower(*s2);

        if (compare != 0)
                return (compare > 0) ? FIRST_BIGGER: SECOND_BIGGER;

        s1++;
        s2++;
        }

    int len1 = ((line*)ln1) -> num_of_ch;
    int len2 = ((line*)ln2) -> num_of_ch;

    if (len1 != len2)
        return (len1 - len2 >  0) ? FIRST_BIGGER:SECOND_BIGGER;

    return SAME;
    }
//doesn't work all that good =(( (add skipping of unnecessary smbl)
int reverse_line_comparator( const void* ln1, const void* ln2 )
    {
    assert(ln1 != NULL && ln2 != NULL);

    char* s1 = ((line*)ln1) -> line;
    int len1 = ((line*)ln1) -> num_of_ch - 1;

    char* s2 = ((line*)ln2) -> line;
    int len2 = ((line*)ln2) -> num_of_ch - 1;

    assert(s1 != NULL && s2 !=NULL);

    while( len1 >= 0 && len2 >= 0)
        {
        int compare = tolower(s1[len1]) - tolower(s2[len2]);

        if (compare != 0)
            return (compare > 0) ? FIRST_BIGGER: SECOND_BIGGER;

        len1--;
        len2--;
        }
    if (len1 != len2)
        return (len1 > len2) ? FIRST_BIGGER:SECOND_BIGGER;

    return SAME;

    }


