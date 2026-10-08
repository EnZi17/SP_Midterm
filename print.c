#include "ls.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_file_info(const char *path, const char *name, const struct stat *st, int long_format) {
    if (long_format) {
        struct passwd *pwd = getpwuid(st->st_uid);
        struct group *grp = getgrgid(st->st_gid);
        char time_buf[256];
        struct tm *tm_info = localtime(&st->st_mtime);
        strftime(time_buf, sizeof(time_buf), "%b %d %H:%M", tm_info);
        
        printf("%c%c%c%c%c%c%c%c%c%c %lu %s %s %5ld %s %s\n",
            S_ISDIR(st->st_mode) ? 'd' : '-',
            (st->st_mode & S_IRUSR) ? 'r' : '-',
            (st->st_mode & S_IWUSR) ? 'w' : '-',
            (st->st_mode & S_IXUSR) ? 'x' : '-',
            (st->st_mode & S_IRGRP) ? 'r' : '-',
            (st->st_mode & S_IWGRP) ? 'w' : '-',
            (st->st_mode & S_IXGRP) ? 'x' : '-',
            (st->st_mode & S_IROTH) ? 'r' : '-',
            (st->st_mode & S_IWOTH) ? 'w' : '-',
            (st->st_mode & S_IXOTH) ? 'x' : '-',
            (unsigned long)st->st_nlink,
            pwd ? pwd->pw_name : "unknown",
            grp ? grp->gr_name : "unknown",
            (long)st->st_size,
            time_buf,
            name);
    } else {
        printf("%s  ", name);
    }
}
