#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int exec(char **arguments, char *argv[], int count, char *line);
char *_getline();
char **tokenoide(char *line);
char _strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

#endif
