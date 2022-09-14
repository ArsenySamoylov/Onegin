#ifndef STRING_FUNCTIONS
#define STRING_FUNCTIONS

int custom_puts(const char *s);

char *custom_strchr(char *s, const char c);

int   custom_strlen(const char *s);

char *custom_strcpy(char * destiny, const char *source);

char *custom_strcat(char *s, const char *c);

char *custom_strncat(char *s, const char *c, int n);

char *custom_fgets(char *s, int MAX_LEN, FILE *iop);

char *custom_strcmp(const char *s1, const char *s2);

int  custom_getline(char *s, int MAX_LEN);

#endif
