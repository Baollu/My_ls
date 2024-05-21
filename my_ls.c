/*
** EPITECH PROJECT, 2023
** my
** File description:
** ls
*/

#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"

struct flag_s *flag_init(void)
{
    struct flag_s *flag;

    flag = malloc(sizeof(struct flag_s));
    flag->a = 0;
    flag->l = 0;
    flag->R = 0;
    flag->d = 0;
    flag->r = 0;
    flag->t = 0;
    return flag;
}

void have_flag(char c, struct flag_s *flag)
{
    char array[] = {'a', 'l', 'R', 'd', 'r', 't', '\0'};
    int *flag_array[] = {&flag->a, &flag->l, &flag->R,
        &flag->d, &flag->r, &flag->t};

    for (int j = 0; j < 7; j++){
        if (c == array[j])
            *flag_array[j] = 1;
    }
}

void loop_str(char *str, struct flag_s *flag)
{
    int j;

    for (j = 1; str[j] != '\0'; j++){
        have_flag(str[j], flag);
    }
}

int loop_ac(int argc, char **argv, struct flag_s *flag)
{
    int i;

    for (i = 0; i < argc; i++){
        if ( argv[i][0] == '-')
            loop_str(argv[i], flag);
    }
    return 0;
}

int main(int argc, char **argv)
{
    struct flag_s *flag = flag_init();

    loop_ac(argc, argv, flag);
    if (flag->a == 1){
        flag_a(argc, argv);
        return 0;
    }
    no_flag(argc, argv);
    return 0;
}
