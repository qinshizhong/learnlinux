#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    close(STDOUT_FILENO);
    open("bar", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    printf("This statement goes to bar; standard output redirected\n");
}
