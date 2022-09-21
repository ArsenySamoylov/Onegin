#ifndef LINE_FUNCTIONS
#define LINE_FUNCTIONS

    #include <assert.h>

    #include "text.h"
    #include "sort.h"

    int putl( const struct line* l );

    int fputl( const struct line* l, FILE *out );

    enum COMPARISON
        {
        FIRST_BIGGER  = 1,
        SECOND_BIGGER = -1,
        SAME          = 0,

        ERROR_NULL_LINE  = -2,
        WRONG_MODE       = -3
        };

    int scmp(const struct line* l1, const struct line* l2, const int mode);

    char* skip_unnecessary_smb(const char *s);

    void swap_lines(line* l1, line* l2);

    int standard_line_comparartor( const void* ln1, const void* ln2 );

    int reverse_line_comparator  ( const void* ln1, const void* ln2 );

#endif
