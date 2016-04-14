#include <dirent.h>
#include <stdio.h>

void quit(char *p_msg, int exit_status) {
    perror(p_msg);
    exit(exit_status);
}

int main(int argc, char **argv) {
    DIR *dir = NULL;
    struct dirent *direntry = NULL;

    if ((dir = opendir(argv[1])) == NULL)
       quit("opendir", 1);  

    while ((direntry = readdir(dir)) != NULL) 
        printf("%10d %s\n", direntry->d_ino, direntry->d_name);

    closedir(dir);
    exit(0);
}
