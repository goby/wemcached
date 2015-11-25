#ifndef __WEMCACHED_COMMON_H__
#define __WEMCACHED_COMMON_H__

#define MAX_CMD_LENGTH 8
#define MAX_ARG_LENGTH 4

enum {
    ARG_TYPE_STRING,
    ARG_TYPE_NUMERIC
};

enum {
    CMD_QUIT,
    CMD_GET,
    CMD_SET,
    CMD_LIST,
    CMD_MONITOR,

    CMD_MAX = 0xFFF
};


struct argument {
    int type;
    int required;
};

struct command {
    int cmd;
    int argument_len;
    char name[MAX_CMD_LENGTH];
    struct argument args[MAX_ARG_LENGTH];
};

#endif
