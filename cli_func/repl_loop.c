#include <stdio.h>
#include <string.h>
#include "file_ops.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void list_directory(const char* path);
int change_directory(const char* path);
void list_directory_recursive(const char* path, int indent_level);
void copy_file(const char* src, const char* dest);
int move_file(const char* src, const char* dest);
void delete_file(const char* filepath);
void display_file_content(const char* filepath);

int run_interactive_mode() {
    char *input, *line;
    char command[256], path1[1024], path2[1024];

    while (1) {
        line = readline("DEMO> ");  //prompt
        if (!line) break;  // Exit on Ctrl-D

        
        if (*line) add_history(line); //add nonempty line allowing user to navigate via arrow keys

        
        input = strdup(line);  
        free(line);  

        int count = sscanf(input, "%255s %1023s %1023s", command, path1, path2); //stores commands from user
        free(input);  

        if (strcmp(command, "exit") == 0) break;
        else if (strcmp(command, "ls") == 0 && count == 2) {
            list_directory(path1);
        }
        else if (strcmp(command, "cd") == 0 && count == 2) {
            change_directory(path1);
        }
        else if (strcmp(command, "tree") == 0 && count == 2) {
            list_directory_recursive(path1, 0);
        }
        else if (strcmp(command, "cp") == 0 && count == 3) {
            copy_file(path1, path2);
        }
        else if (strcmp(command, "mv") == 0 && count == 3) {
            move_file(path1, path2);
        }
        else if (strcmp(command, "rm") == 0 && count == 2) {
            delete_file(path1);
        }
        else if (strcmp(command, "cat") == 0 && count == 2) {
            display_file_content(path1);
        }
        else {
            printf("Invalid command or arguments. Please try again.\n");
        }
    }
    return 0;
}

int main() {
    run_interactive_mode();  //this is the cli entry function
    return 0;
}