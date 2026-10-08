#include "ls.h"

int main(int argc, char *argv[]) {
    int opt;
    int show_hidden = 0;
    int long_format = 0;
    
    // Simplistic option parsing for demonstration
    while ((opt = getopt(argc, argv, "AacdFfhiklnqRrSstuw")) != -1) {
        switch (opt) {
            case 'a': show_hidden = 1; break;
            case 'l': long_format = 1; break;
        }
    }
    
    if (optind == argc) {
        do_ls(".", show_hidden, long_format);
    } else {
        while (optind < argc) {
            do_ls(argv[optind], show_hidden, long_format);
            optind++;
        }
    }
    return 0;
}
