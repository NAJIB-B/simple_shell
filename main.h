#ifndef MAIN_H
#define MAIN_H

char *_strdup(const char *str);
char **get_user_input();
char *_getenv(const char *name);
int _strlen(char *str);
char *string_joiner(char *str1, char *str2);
char *find_path(char *command);
char *get_last_part(char *str);

#endif
