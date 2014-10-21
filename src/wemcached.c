#include <stdio.h>
#include <defs.h>
#include <server.h>

extern int daemon(int nochdir, int noclose);

int main(int argc, char **argv) {
    int ret;
    printf("Enter program!!!!\n");

    ret = daemon(1, 1);

    if (ret == 0) {
        ret = serv(0, 0);
    }
    
    return ret;
}
