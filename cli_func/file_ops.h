#ifndef FILE_OPS_H
#define FILE_OPS_H

// Function to list the contents of a directory
void list_directory(const char* path);

// Function to change the current working directory
int change_directory(const char* path);

void list_directory_recursive(const char* base_path, int indent_level);

#endif // FILE_OPS_H
