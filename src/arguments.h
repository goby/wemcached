#ifndef __WEMCACHED_ARGUMENTS_H__
#define __WEMCACHED_ARGUMENTS_H__

#include <argp.h>

enum e_run_mode
{
    UNSET_MODE = 0,
    SERVER_MODE,
    CLIENT_MODE
};

enum e_log_level
{
    UNSET_LEVEL = 0,
    DEBUG,
    VERBOSE,
    INFO,
    WARNING,
    ERROR
};

/* the main config of wemcached.*/
struct wem_config
{
    int mode;
    int daemon;
    int port;
    int timeout;
    int tcp_keepalived;
    int log_level;
    int max_clients;
    char *log_file;
    char *host;
    char *pidfile;
};


/* Arguments for Wemcached */
struct wem_arguments
{
    char *args[2];
    char *config_file;
    int debug;
    struct wem_config config;
};

int parse_arguments(int argc, char *argv[], struct wem_arguments *arguments);

#endif
