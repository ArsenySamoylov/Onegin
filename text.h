#ifndef TEXT_TO
#define TEXT_TO

#include <windows.h>
#include <sys/stat.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string>

#include "line_functions.h"

#define FPUT(text, result_file, mode)    txt_checker(fput_txt(text, result_file, mode));
#define GET_TEXT(text, buffer)           txt_checker(get_text_and_divide_on_lsn(&Hamlet, buffer));

struct text
    {
    const char* buffer;
    struct line *lines_array; //+ 1 - NULL line
    int num_of_lns;           //without null line
    };

struct line
    {
    char* line;
    int num_of_ch;
    };

enum get_text
    {
    FILE_NT_FND = -300,
    NULL_BUFFER,
    NULL_FDIRECTION,
    SIZE_ERR,
    READING_ERR,

    GET_TEXT_SUCS = 1,
    };
enum text_flags
    {
    TXT_SUCCESS = 0,
    };

enum text_sort
    {
    ORIGINAL = 1,
    SORTED   = 2,
    };

enum text_err
    {
    ERROR_TEXT         = -1,
    EMPTY_DIRECTION    = -2,
    NO_LINES           = -3,
    FILE_ERROR         = -4,
    UNEXPECTED_ERR     = -5,
    EMPTY_BUFFER       = -6,
    DYNAMIC_MEMORY_ERR = -7,
    LINES_UNMATCHING   = -8,
    WRONG_MODE_TXT     = -9,
    };

enum dead_inside
    {
    ALREADY_DEAD = -1,
    MUREDERED,
    };

#define __DNKFRLV_NOT_IMPLEMENTED__(...)

enum console_colors
    {
    black    = 0,
    blue     = 1,
    green    = 2,
    __DNKFRLV_NOT_IMPLEMENTED__ (3)
    red      = 4,
    lil      = 5,
    gray     = 8,
    lt_blue  = 9,
    lt_green = 10,
    std_cl   = 11,
    lt_red   = 12,
    white    = 15,

    };

int get_text_and_divide_on_lsn(struct text* text, const char* text_name);

int get_text(char** buffer, const char *file_direction);

int divide_text_in_lines(struct text* text);

int fput_txt(const struct text* t, const char* file_direction, const int mode);

int shut_down_system(struct text* dead_body);

void txt_checker(int flag);

int cnt_lines(const char* text, char end_of_line);

FILE* create_file(const char* name, int mode, int number);


#endif
