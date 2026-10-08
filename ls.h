#ifndef LS_H
#define LS_H
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_ls(const char *dir, int show_hidden, int long_format);
void print_file_info(const char *path, const char *name, const struct stat *st, int long_format);
#endif
