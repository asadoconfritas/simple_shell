#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/* str functions */
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/* shell */
int main(int argc, char **argv);
int firststep(int *mode, char **inp, char ***tokens);
void execute(char **tokens);
char **parse(char *inp, char *del);

#endif
