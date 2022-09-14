#include <stdio.h>
#include <stdlib.h>

// extra changes for sort algorithm
int custom_puts( const char *s )
    {
    int flag_error = EOF;
    int i = 0;

    while (s[i] != '\0' && s[i] != '\n')
        flag_error = putchar(s[i++]);

    flag_error = putchar('\n');

    return flag_error;
    }

char *custom_strchr( char* s, const char c )
    {
    int  i = 0;
    while( s[i] != '\0' )
        {
        if( s[i] == c )
           return (s + i);
        i++;
        }

    return NULL;
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

char *custom_strcat( char *s, const char *c )
    {
    int len = custom_strlen(s);
    int i = 0;

    while( c[i] != '\0' )
        s[len+i] = c[i++];

    return s;
    }

char *custom_strncat( char *s, const char *c, int n)
    {
    int len = custom_strlen(s);
    int i = 0;

    while( (n--) > 0 && c[i] != '\0')
        s[len+i] = c[i++];

    return s;
    }

char *custom_fgets( char *s, int MAX_LEN, FILE *iop)
    {
    int i = 0, c = 0;

    while( --MAX_LEN > 0 && c != EOF && c != '\n' )
        {
        c = fgetc(iop);

        if ( c != EOF )
            s[i++] = c;
        }

    if( MAX_LEN == 0 )
        return NULL;

    s[i] = '\0';

    return s;
    }

int custom_strcmp( const char *s1, const char *s2 )
    {
    int cmp_len = custom_strlen(s1) - custom_strlen(s2);

    if( cmp_len != 0 )
        return cmp_len;

    for(int i = 0; i < cmp_len; i++)
        {
        if( (s1[i] - s2[i]) != 0 )
            return (s1[i] - s2[i]);
        }

    return 0;
    }

char *custom_strdup( const char *s )
    {
    char *dup = (char*)calloc(custom_strlen(s) + 1, sizeof(char));

    custom_strcpy(dup, s);

    return dup;

    }
ssize_t custom_getline( char **s, ssize_t *n, FILE *stream )
    {
     *n = 0;

     unsigned buffer_size = 101;
     *s = (char*)calloc(buffer_size, sizeof(char));

     int c = 0;
     while( c != '\n' )
        {
        c = getc(stream);

        if ( c == EOF )
            {
            (*s)[(*n)] = '\0';
            *s = (char*)realloc( *s, (*n / buffer_size + 1) * 100 * sizeof(char) );

            return EOF;
            }

        (*s)[(*n)] = c;
        (*n)++;

        if( *n == buffer_size )
           *s = (char*)realloc( *s, (*n / buffer_size + 1) * 100 * sizeof(char) );

        }

        (*s)[(*n)] = '\0';

        *s = (char*)realloc(*s, *n);

        return *n;
    }
