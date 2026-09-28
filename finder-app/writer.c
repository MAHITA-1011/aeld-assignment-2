#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd;
    ssize_t nr;
    size_t len;

    openlog(NULL, 0, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <file> <string>", argv[0]);
        closelog();
        return 1;
    }

    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Failed to open file %s: %s",
               argv[1], strerror(errno));
        closelog();
        return 1;
    }

    len = strlen(argv[2]);
    nr = write(fd, argv[2], len);

    if (nr == -1) {
        syslog(LOG_ERR, "Failed to write to file %s: %s",
               argv[1], strerror(errno));
        close(fd);
        closelog();
        return 1;
    }

    if ((size_t)nr != len) {
        syslog(LOG_ERR, "Failed to write complete string to file %s",
               argv[1]);
        close(fd);
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

    if (close(fd) == -1) {
        syslog(LOG_ERR, "Failed to close file %s: %s",
               argv[1], strerror(errno));
        closelog();
        return 1;
    }

    closelog();
    return 0;
}
