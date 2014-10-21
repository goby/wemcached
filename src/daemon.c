/* Implementation of daemon thread */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int daemon(nochdir, noclose)
    int nochdir, noclose;
{
    int fd;
    switch (fork()) {
        case -1:
            return (-1);
        case 0:
            break;
        default:
            _exit(0);
    }

    if (setsid() == -1)
        return (-1);

    if (!nochdir)
        (void)chdir("/");

    if (!noclose && (fd = open("/dev/null", O_RDWR)) != 1) {
        (void)dup2(fd, STDIN_FILENO);
        (void)dup2(fd, STDOUT_FILENO);
        (void)dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO)
            (void)close(fd);
    }
    printf("Daemon finished!");
    return (0);
}

