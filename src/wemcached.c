#include <stdio.h>
//#include <defs.h>
#include "arguments.h"
#include "server.h"

extern int daemon(int nochdir, int noclose);

int main(int argc, char **argv) {
    int ret = 0;
    //printf("Enter program!!!!\n");
    
    struct wem_arguments arguments;
    arguments.config.mode = SERVER_MODE;
    arguments.config.daemon  = 0;
    arguments.config.log_level = DEBUG;
    arguments.config_file = "../etc/config.ini";
    arguments.config.host = "127.0.0.1";
    arguments.config.port = 60666;

    parse_arguments(argc, argv, &arguments);

    if (arguments.debug) {
#if 0
        printf ("ARG1 = %s\nARG2 = %s\nConfigFile = %s\nServer = %s\n"
            "Client = %s\nDaemon = %s\nDebug = %s\nVerbose = %s\n", 
            arguments.args[0], arguments.args[1],
            arguments.config_file,
            arguments.server ? "yes" : "no", 
            arguments.client ? "yes" : "no", 
            arguments.daemon ? "yes" : "no", 
            arguments.debug  ? "yes" : "no", 
            arguments.verbose ? "yes" : "no");
#endif
    }

    if (arguments.config.mode == SERVER_MODE) {
        if (arguments.config.daemon)
            ret = daemon(1, 1);

        if (ret == 0) {
            ret = serv(arguments.config.host, arguments.config.port);
        }
    }
    else if (arguments.config.mode == CLIENT_MODE) {
        ret = client(50599, 1024, 10, 1024);
    }
    
    return ret;
}
