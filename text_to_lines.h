#ifndef TEXT_TO_LINES
#define TEXT_TO_LINES

struct text
    {
    struct line *lines_array;
    int num_of_lns;
    };


struct line
    {
    char* line;
    int num_of_ch;
    };

struct text text_to_lines(const char* text);

int cnt_lines(const char* text);
#endif
