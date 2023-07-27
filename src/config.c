#include <stdlib.h>
#include "config.h"

void save_option(int *options, char option) {
    switch (option) {
        case 'l':
            *options |= long_format;
            break;
            // support more options here
    }
}

Config *parse_args(char **args) {
    Config *config = calloc(1, sizeof(Config));
    char **directory_names = calloc(100, sizeof(char *));
    int *options = calloc(1, sizeof(int));
    for (int i = 0; args[i] != NULL; ++i) {
        char *current_arg = args[i];
        if (current_arg[0] == '-') {
            save_option(options, current_arg[1]);
        } else {
            int next_free_index = -1;
            for (int j = 0; next_free_index == -1; ++j) {
                if (!directory_names[j]) {
                    next_free_index = j;
                }
            }
            // consider handling errors if more than 100 directory names are supplied
            // next_free_index would be -1...
            directory_names[next_free_index] = current_arg;
        }
    }
    return config;
};