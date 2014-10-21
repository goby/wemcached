#ifndef __WEMCACHED_ARGUMENTS_H__
#define __WEMCACHED_ARGUMENTS_H__

#include <argp.h>

/* Arguments for Wemcached */
struct wem_arguments
{
    char *args[2];
    int server, client, daemon, verbose, debug;
    char *config_file;
};

int parse_arguments(int argc, char *argv[], struct wem_arguments *arguments);

#endif
