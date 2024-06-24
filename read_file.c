#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include <stdbool.h>
static void remove_comments(char* linebuffer){
    bool iscomment = 0;
for(int i = 0; i<1024; i++){
    if(!iscomment){
        if(linebuffer[i] == ';'){
            iscomment = true;
        }
    }
    else{
        linebuffer[i] = ' ';
    }

}
}
void Convert_to_instructions_and_execute(char* filename){
    char linebuffer[1024];
    FILE* file = fopen(filename, "r");
    if(!file){
        printf("error");
    }
    while(fgets(linebuffer, 1024, file)){
        remove_comments(linebuffer);
        id_and_execute(linebuffer, '2');
    }


    fclose(file);
}
char* Convert_file_to_string(char* filename){
    FILE* file = fopen(filename, "r");
    if(!file){
        printf("error");
    }
    fseek(file, 0, SEEK_END);
    unsigned long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *content = malloc(filesize + 1);
    if (content == NULL) {
        perror("malloc");
        fclose(file);
        return NULL;
    }
    fread(content, 1, filesize, file);
    content[filesize] = '\0';
    fclose(file);
    return content;    
}