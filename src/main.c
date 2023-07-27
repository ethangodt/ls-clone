#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "config.h"

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char *default_dir_name = ".";
    char *dir_name = argc > 1 ? argv[1] : default_dir_name;
    Config *config = parse_args(argv);

    dir = opendir(dir_name);

    if (!dir) {
        printf("Error opening directory.\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        stat(entry->d_name, &fileStat);
        printf("%s %lld B\n", entry->d_name, fileStat.st_size);
    }

    closedir(dir);
    return 0;
}
