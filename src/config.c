#include <argp.h>
//#include <defs.h>
#include "arguments.h"

#include <stdio.h>

const char *argp_program_version     = "Wemcached -- 0.1";
const char *argp_program_bug_address = "<goby@foxmail.com>";
static char description[]            = "My Practise.";
static char args_doc[]               = "";
static struct argp_option options[]  = {
    { "server",  's', 0, 0, "Run with server mode. The default mode."},
    { "client",  'c', 0, 0, "Run with client mode."},
    { "daemon",  'd', 0, 0, "Run with daemon mode, only valid when program in server mode."},
    { "config",  'f', 0, 0, "Specify the configuration file. The default file is config.ini."}, 
    { "verbose", 'v', 0, 0, "Run with verbose mode."}, 
    { "debug",   'D', 0, 0, "Run in DEBUG mode."},
    { 0 }
};

/* Arguments for Wemcached */
/*struct wem_arguments
{
    char *args[2];
    int server, client, daemon, verbose, debug;
    char *config_file;
};
*/

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct wem_arguments *arguments = state->input;
    switch(key) {
        case 's':
            arguments->server = 1;
            arguments->client = 0;
            break;
        case 'c':
            arguments->client = 1;
            arguments->server = 0;
            break;
        case 'd':
            arguments->daemon = 1;
            break;
        case 'f':
            arguments->config_file = arg;
            break;
        case 'v':
            arguments->verbose = 1;
            break;
        case 'D':
            arguments->debug = 1;
            break;
       
        case ARGP_KEY_ARG:
            if (state->arg_num >= 2)
                argp_usage(state);
            
            arguments->args[state->arg_num] = arg;
            break;
        /*case ARGP_KEY_END:*/
            if (state->arg_num < 2)
                 argp_usage(state); 
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    return (0);
}

static struct argp argp = {options, parse_opt, args_doc, description};

int parse_arguments(int argc, char *argv[], struct wem_arguments *arguments) {
    argp_parse(&argp, argc, argv, 0, 0, arguments);

    return (1);
}

/* End of arguments parsing.*/
