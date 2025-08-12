#include <sys/stat.h>
#include <stdint.h>

// Redirecione printf para sua UART
extern int __io_putchar(int ch);

int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        __io_putchar(ptr[i]);
    }
    return len;
}

int _close(int file) { return -1; }
int _fstat(int file, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _isatty(int file) { return 1; }
int _lseek(int file, int ptr, int dir) { return 0; }
int _read(int file, char *ptr, int len) { return 0; }
caddr_t _sbrk(int incr) { return (caddr_t)-1; }
void _exit(int status) { while (1); }
int _kill(int pid, int sig) { return -1; }
int _getpid(void) { return 1; }