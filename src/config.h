#ifndef LS_CLONE_CONFIG_H
#define LS_CLONE_CONFIG_H

typedef struct {
    int options;
    char **directory_names;
} Config;

Config *parse_args(char **args);

typedef enum {
    long_format = 1 << 0,
    dir_dot = 1 << 0,
} options_mask;

void save_option(int *options, char option);

#endif //LS_CLONE_CONFIG_H
