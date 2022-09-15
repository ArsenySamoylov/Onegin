#ifndef LINE_FUNCTIONS
#define LINE_FUNCTIONS

#include "../headers/text_to_lines.h"

int putl( const struct line* l );

enum COMPARISON
    {
    FIRST_BIGGER = 1,
    SECOND_BIGGER = -1,
    SAME = 0,

    ERROR_NULL_LINE  = -2,
    WRONG_MODE = -3
    };
int scmp(const struct line* l1, const struct line* l2, char mode);

char* skip_unnecessary_smb(const char *s);

void swap_lines(line* l1, line* l2);

#endif
