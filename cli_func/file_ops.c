#include "file_ops.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>     // library for directory handling
#include <unistd.h>     // library for chdir()
#include <errno.h>      // library for error numbers

// Function to list the contents of a directory
void list_directory(const char* path) { // dir pointer and entry
    DIR* dir;
    struct dirent* entry;

    if ((dir = opendir(path)) == NULL) { //if dir cant be opened
        perror("Failed to open directory");
        return;
    }

    printf("Directory contents of '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

// change the current working directory
int change_directory(const char* path) {
    if (chdir(path) != 0) {
        perror("Failed to change directory");
        return errno;
    }
    return 0; // Return 0 on success
}
