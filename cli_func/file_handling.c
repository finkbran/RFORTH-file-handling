#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

void copy_file(const char* src_path, const char* dest_path) {
    FILE *src, *dest; //pointer
    char buffer[1024]; //hold data
    size_t bytes; //hold from fread

    src = fopen(src_path, "rb"); //opens to read from source
    if (src == NULL) { //source doesnt exist
        perror("Error opening source file");
        return;
    }

    dest = fopen(dest_path, "wb"); //opens to write ti destination
    if (dest == NULL) { //destination doesnt exist
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest); //write from src ti buffer array
    }

    fclose(src);
    fclose(dest);
}

int move_file(const char* src_path, const char* dest_path) {
    //attempt to rename
    if (rename(src_path, dest_path) == 0) {
        return 0; 
    }

    //move across diff mounts, if rename fails
    copy_file(src_path, dest_path); 
    remove(src_path);  //delete source after success

    return 0; 
}


void delete_file(const char* filepath) {
    if (remove(filepath) != 0) {
        perror("Failed to delete file");
    }
}


void display_file_content(const char* filepath) { //display to terminal
    FILE *file;
    char ch;

    file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}
