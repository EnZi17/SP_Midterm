#include "ls.h"

void do_ls(const char *dir_name, int show_hidden, int long_format) {
    DIR *dir_ptr;
    struct dirent *direntp;
    struct stat info;
    char path[1024];
    
    if ((dir_ptr = opendir(dir_name)) == NULL) {
        fprintf(stderr, "ls: cannot open %s\n", dir_name);
        return;
    }
    
    while ((direntp = readdir(dir_ptr)) != NULL) {
        if (!show_hidden && direntp->d_name[0] == '.') {
            continue;
        }
        snprintf(path, sizeof(path), "%s/%s", dir_name, direntp->d_name);
        if (stat(path, &info) == -1) {
            perror("stat");
        } else {
            print_file_info(path, direntp->d_name, &info, long_format);
        }
    }
    closedir(dir_ptr);
    if (!long_format) printf("\n");
}
