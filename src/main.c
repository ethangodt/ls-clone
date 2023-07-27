#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    dir = opendir(".");
    if (!dir) {
        printf("Error opening directory.\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        stat(entry->d_name, &fileStat);
        if (S_ISREG(fileStat.st_mode)) {
            printf("%s %lld B\n", entry->d_name, fileStat.st_size);
        }
    }

    closedir(dir);
    return 0;
}
