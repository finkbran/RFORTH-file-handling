#include <stdio.h>   
#include <string.h>   
#include <dirent.h>   
#include <sys/stat.h> 
#include <unistd.h>   
//function to access a directory and its subcontents
void list_directory_recursive(const char* base_path, int indent_level) {
    DIR* dir;
    struct dirent* entry;
    char path[1024];

    if (!(dir = opendir(base_path)))
        return;

    while ((entry = readdir(dir)) != NULL) { //loop through each entry in directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue; //check if directory is current/parent directory if it is skip and proceed
        
        snprintf(path, sizeof(path), "%s/%s", base_path, entry->d_name);
        printf("%*s[%s]\n", indent_level * 2, "", entry->d_name);

        struct stat path_stat;
        stat(path, &path_stat);
        if (S_ISDIR(path_stat.st_mode)) { //check if entry is a directory
            list_directory_recursive(path, indent_level + 1); //if it is call func recursively starting from this file
        }
    }
    closedir(dir);
}

