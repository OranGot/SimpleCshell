#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include <stdbool.h>
#define LINE_BUFFER_SIZE 1024
static void remove_comments(char* linebuffer){
    bool iscomment = 0;
for(int i = 0; i<LINE_BUFFER_SIZE; i++){
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
int Convert_to_instructions_and_execute(char* filename){
    char linebuffer[LINE_BUFFER_SIZE];
    FILE* file = fopen(filename, "r");
    if(!file){
        printf("error");
        return 1;
    }
    while(fgets(linebuffer, LINE_BUFFER_SIZE, file)){
        remove_comments(linebuffer);
        id_and_execute(linebuffer, '2');
    }

    fclose(file);
    return 0;
}
char* Convert_file_to_string(char* filename){
    FILE* file = fopen(filename, "r");
    if(!file){
        printf("error");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    unsigned long filesize = ftell(file);
    if (filesize == -1L) {
        perror("ftell");
        fclose(file);
        return NULL;
}
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