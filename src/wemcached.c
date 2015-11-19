#include <stdio.h>
//#include <defs.h>
#include "arguments.h"
#include "server.h"

extern int daemon(int nochdir, int noclose);

int main(int argc, char **argv) {
    int ret = 0;
    printf("Enter program!!!!\n");
    
    struct wem_arguments arguments;
    arguments.server  = 1;
    arguments.daemon  = 0;
    arguments.client  = 0;
    arguments.verbose = 0;
    arguments.debug   = 0;
    arguments.config_file = "config.ini";

    parse_arguments(argc, argv, &arguments);

    if (arguments.debug) {
        printf ("ARG1 = %s\nARG2 = %s\nConfigFile = %s\nServer = %s\n"
            "Client = %s\nDaemon = %s\nDebug = %s\nVerbose = %s\n", 
            arguments.args[0], arguments.args[1],
            arguments.config_file,
            arguments.server ? "yes" : "no", 
            arguments.client ? "yes" : "no", 
            arguments.daemon ? "yes" : "no", 
            arguments.debug  ? "yes" : "no", 
            arguments.verbose ? "yes" : "no");
    }

    if (arguments.server) {
        if (arguments.daemon)
            ret = daemon(1, 1);

        if (ret == 0) {
            ret = serv(0, 0);
        }
    }
    else if (arguments.client) {
        ret = client(50599, 1024, 10, 1024);
    }
    
    return ret;
}
