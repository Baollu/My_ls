/*
** EPITECH PROJECT, 2023
** flag
** File description:
** flag
*/

#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include "my.h"

int no_option(int argc, char **argv)
{
    struct dirent *repository;
    DIR *rep = opendir(argv[1]);

    if (rep == NULL)
        return 84;
    repository = readdir(rep);
    while (repository != NULL){
        if (repository->d_name[0] != '.' )
            mini_printf("%s ", repository->d_name);
        repository = readdir(rep);
    }
    closedir(rep);
    return 0;
}

int no_flag(int argc, char **argv)
{
    struct dirent *repository;
    DIR *rep = opendir(argv[1]);

    if (rep == NULL)
        return 84;
    repository = readdir(rep);
    while (repository != NULL){
        if (repository->d_name[0] != '.' )
            mini_printf("%s ", repository->d_name);
        repository = readdir(rep);
    }
    closedir(rep);
    return 0;
}

int flag_a(int argc, char **argv)
{
    struct dirent *repository;
    DIR *rep = opendir(argv[1]);

    if (rep == NULL)
        return 84;
    repository = readdir(rep);
    while (repository != NULL){
        mini_printf("%s ", repository->d_name);
        repository = readdir(rep);
    }
    closedir(rep);
    return 0;
}
