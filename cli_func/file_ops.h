#ifndef FILE_OPS_H
#define FILE_OPS_H

// Function to list the contents of a directory
void list_directory(const char* path);

// Function to change the current working directory
int change_directory(const char* path);

void list_directory_recursive(const char* base_path, int indent_level);

void copy_file(const char* src_path, const char* dest_path);

int move_file(const char* src_path, const char* dest_path);

void delete_file(const char* filepath);

void display_file_content(const char* filepath);

#endif // FILE_OPS_H
