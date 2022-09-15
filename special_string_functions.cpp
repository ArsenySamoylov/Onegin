#include <stdio.h>
#include <stdlib.h>

// special for printing line strucute (for sort algorithm)
int custom_puts( const char *s )
    {
    int flag_error = EOF;
    int i = 0;

    while (s[i] != '\0' && s[i] != '\n')
        flag_error = putchar(s[i++]);

    flag_error = putchar('\n');

    return flag_error;
    }


int custom_strlen( const char *s )
    {
    int i = 0;

    while( s[i] != '\0' )
        i++;

    return i;
    }

char *custom_strcpy( char *destiny, const char *source)
    {
    int i = 0;

    while( source[i] != '\0' )
        destiny[i] = source[i++];

    destiny[i] = '\0';

    return destiny;
    }

