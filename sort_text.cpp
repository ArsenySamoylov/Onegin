#include <stdio.h>
//#include <locale.h>
//#include <windows.h>

#include "../headers/string_functions.h"

#include "../headers/sort_text.h"

#include "../headers/text_buffer.h"
#include "../headers/text_to_lines.h"

int main(char* test)
    {
    //setlocale(LC_ALL, "");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    //char test[] = "../text/test1.txt";

    char* buffer = get_text(test);

    struct text Hamlet = text_to_lines(buffer);

    printf("\n\nTEXT\n");

    for(int i = 0; i<Hamlet.num_of_lns;i++)
        {
        line l = (Hamlet.lines_array)[i];
        custom_puts(l.line);

        }
   // printf("%d", lines); */
    //sorting


    return 0;
    }

    /*int main()
    {

    FILE* f = fopen("../text/test1.txt", "r");
    char s[100];
    int n = fread(s,sizeof(char), 100, f);
    s[n] = '\0';
    if(f == NULL)
        printf("SUKA");
   // printf("%s\n%d",s, n);
    //printf("MGEMMEG");
    int lines = cnt_lines(s);
    printf("%d",lines);
    fclose(f);
    }     */


