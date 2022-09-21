#include "text.h"

//add checking for get text return status
int get_text_and_divide_on_lsn(struct text* text, const char* text_name)
    {
    if (text_name == NULL)    return EMPTY_DIRECTION;
    if (text == NULL)         return EMPTY_TEXT;

    char* full_direction = (char*)calloc(strlen(text_name) + 100, sizeof(full_direction[0]));
    snprintf(full_direction,20, "text/%s", text_name);

    get_text((char**)&(text->buffer), full_direction);

    return divide_text_in_lines(text);
    }

int get_text(char** buffer, const char *file_direction)
    {
    if (buffer == NULL)          return NULL_BUFFER;
    if (file_direction == NULL ) return NULL_FDIRECTION;

    
    FILE *text = fopen(file_direction, "r");
    if (text == NULL)
        {
        fclose(text);
        return FILE_NT_FND;
        }

    struct stat text_data;
    stat(file_direction, &text_data);

    if (text_data.st_size < 1)
        {
        fclose(text);

        return SIZE_ERR;
        }

    char* text_buffer = (char*) calloc (text_data.st_size + 1, sizeof (char));

    size_t number_of_ch = fread (text_buffer, sizeof(char), text_data.st_size, text);

    text_buffer = (char*)realloc(text_buffer, number_of_ch + 1);
    text_buffer[number_of_ch] = '\0';

    if ( feof(text) == 0 )
        {
        fclose(text);
        return READING_ERR;
        }

    fclose(text);
    
    *buffer = text_buffer;

    return GET_TEXT_SUCS;
    }

int divide_text_in_lines(struct text* text)
    {
    if (text   == NULL) return ERROR_TEXT;

    char* buffer = (char*)text->buffer;
    if (buffer == NULL) return EMPTY_BUFFER;

    int num_of_lns= cnt_lines(buffer, '\n');

    line* lines_array = (line*)calloc(num_of_lns + 1, sizeof(lines_array[0]));
    if (lines_array == NULL) return DYNAMIC_MEMORY_ERR;

    int current_line = 0;
    int symbl_in_line = 0;
    size_t i = 0;

    while (buffer[i] != '\0')
        {
        if (buffer[i] == '\n')
            {

            lines_array[current_line] = { (char*)(buffer + i - symbl_in_line), symbl_in_line};
            
            symbl_in_line = 0;
            current_line++;
            }

        else if (buffer[i+1] == '\0')
            {
            lines_array[current_line] = { (char*)(buffer + i + 1 - symbl_in_line), symbl_in_line};

            current_line++;
            symbl_in_line = 0;
            }

        else
            symbl_in_line++;

        i++;

        }

    if (current_line != num_of_lns)
        return LINES_UNMATCHING;

    lines_array[num_of_lns] = { NULL, 0};

    text->lines_array = lines_array;
    text->num_of_lns  = num_of_lns;

    return TXT_SUCCESS;
    }




int fput_txt(const struct text* t, const char* file_direction, const int mode)
    {
    if (t == NULL || t->buffer == NULL || t->lines_array == NULL) return ERROR_TEXT;
    if (file_direction == NULL)                                   return EMPTY_DIRECTION;
    if (mode != ORIGINAL && mode != SORTED)                       return WRONG_MODE_TXT;
    if (t->num_of_lns < 0)                                        return NO_LINES;

    static int number_of_using_this_function = 0;


    //FILE* file = fopen(file_direction, "a");
    FILE* file = create_file(file_direction, mode, ++number_of_using_this_function);

    if (file == NULL)  return FILE_ERROR;

    if (mode == ORIGINAL)
        {
        fputs("!!! ENGLISH LITERATURE  TEACHERS DON'T WORRY !!!!!!!!!!!!\n",   file);
        fputs(    "***************** ORIGINAL TEXT *************************\n\n", file);

        fputs(t->buffer, file);

        fputs("\n\n***************** END OF ORIGINAL ****************\n", file);
        fputs(    "***************** END OF ORIGINAL ****************\n", file);

        fclose(file);
        return ORIGINAL;
        }

    else if (mode == SORTED)
        {
        fputs("***************** SORTED   TEXT ******************\n",   file);
        fputs(  "***************** SORTED   TEXT ******************\n\n", file);

        line* arr      = t->lines_array;
        int num_of_lns = t->num_of_lns;

        for(int i = 0; i < num_of_lns; i++)
            {
            if ( (arr+i)->line[0] == '\n' || (arr+i)->line[0] == '=' )
                ;
            else
                fputl(arr+i, file);
            }
        fputs("\n\n**************** END OF SORTED ******************\n", file);
        fputs(    "**************** END OF SORTED ******************\n", file);

        fclose(file);
        return SORTED;
        }

    fclose(file);

    return UNEXPECTED_ERR;
    }

int shut_down_system(struct text* dead_body)
    {
    if (dead_body == NULL)  return ALREADY_DEAD;

    free((void*)(dead_body->buffer));
    free((void*)(dead_body->lines_array));

    dead_body->buffer      = NULL;
    dead_body->lines_array = NULL;

    return MUREDERED;
    }

void txt_checker(int flag)
    {
    printf("txt_checker : ");

    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hconsole, (lt_red << 4) | white);
    switch(flag)
            {
             case TXT_SUCCESS:
                SetConsoleTextAttribute(hconsole, (lt_green << 4) | black);
                printf("Text successfully divided on lines\n");
                break;

             case ORIGINAL:
                SetConsoleTextAttribute(hconsole, (lt_green << 4) | lil);
                printf("Original text successfully was put in resulting file\n");
                break;

             case SORTED:
                SetConsoleTextAttribute(hconsole, (lt_green << 4) | blue);
                printf("Sorted text successfully was put in resulting file\n");
                break;

             case ERROR_TEXT:
                printf("Error within text strcuture\n");
                break;

             case EMPTY_DIRECTION:
                printf("Wrong direction for resulting file\n");
                break;

             case NO_LINES:
                printf("Resulting text has no lines\n");
                break;

            case FILE_ERROR:
                printf("Couldn't open resulting file");
                break;

             case EMPTY_BUFFER:
                printf("Error in buffer\n");
                break;

            case DYNAMIC_MEMORY_ERR:
                printf("Error occurred while allocating memory\n");
                break;

            case LINES_UNMATCHING:
                printf("Number of lines in buffer and in line array doesn't match\n");
                break;

            case WRONG_MODE_TXT:
                printf("Wrong mode\n");
                break;

            case UNEXPECTED_ERR:
            default:
                printf("Unexpected error occurred while writing in resulting file\n");
                break;
            }
        SetConsoleTextAttribute(hconsole, (black<<4) | std_cl);
    }

int cnt_lines(const char* text, char end_of_line)
    {
    if (text == NULL)
        return -1;

    unsigned int num_of_lns = 0;

    long long i = 0;
    while (text[i] != '\0')
        {
        if (text[i] == end_of_line || text[i+1] == '\0' )
            num_of_lns++;

        i++;
        }

    return num_of_lns;
    }

FILE* create_file(const char* name, int mode, int number)
    {
    if (name == NULL)                            return NULL;
    if (mode != ORIGINAL && mode != SORTED)      return NULL;

    if (number < 0 || number >= 10)
      {
      printf("UNDER DEVELOPMENT!!!!!!!!!!!!\n");
      return NULL;
      }

    int len_of_file_name = strlen(name); 

    const char prefix[] = "result/ORGNL_%s";
    int max_length = len_of_file_name + sizeof(prefix) + 32;

    char* new_name = (char*)calloc(max_length, sizeof(new_name[0]));
   
    if (mode == ORIGINAL)
        snprintf(new_name, max_length, "result/ORGNL_%s",  name);

    if (mode == SORTED)
        snprintf(new_name, max_length, "result/SRTD_%d%s", number, name);

    FILE* file = fopen(new_name, "w");
    return file;
    }
