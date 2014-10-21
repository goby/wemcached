#include <stdio.h>
#include "include/defs.h"

extern int daemon(int nochdir, int noclose);

int main(int argc, char** argv) {
    printf("Enter program!!!!\n");

    return daemon(1, 1);
}
