#include <stdio.h>
#include <string.h>
#include "file_ops.h"

void list_directory(const char* path);
int change_directory(const char* path);

int run_interactive_mode() {
    printf("Enter 'exit' to quit.\n");
    char command[256], path[1024];

    while (1) {
        if (scanf("%255s %1023s", command, path) != 2) {
            printf("Error reading input. Please try again.\n"); //not working properly
            continue; // skip further processing and prompt again
        }

        if (strcmp(command, "exit") == 0) break;
        else if (strcmp(command, "ls") == 0) list_directory(path);
        else if (strcmp(command, "cd") == 0) change_directory(path);
        else if (strcmp(command, "lsrec") == 0) list_directory_recursive(path, 0); //accepts
    }
}

int main() {
    run_interactive_mode();  // this is the cli entry function
    return 0;
}


