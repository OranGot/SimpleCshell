#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "read_file.h"
void echo(const char* printval);
void new(char* specifier);
void dump(char *specifier);
void md(char* specifier);
void funny();
void clr();
void change_text_color();
void change_background_color();
bool id_and_execute(char *commandbuffer, char mode){
    char* command = strtok(commandbuffer, " \n");
    char* specifier = strtok(NULL, " \n");
    char* flag = strtok(NULL, " \n");
    if(!strncmp(command, "cd", 3)){
        chdir(specifier);
    }
    else if(!strncmp(command, "quit", 5)){
        return 1;
    }
    else if(!strncmp(command, "md", 3)){
        if(!strncmp(flag, "<", 2)){
            char* filecontents = Convert_file_to_string(specifier);
            md(filecontents);
            free(filecontents);
        }
        else{
            md(specifier);
        }
    }
    else if(!strncmp(command, "funny", 5)){
        funny();
    }
    else if(!strncmp(command, "clr", 4)){
        if(!strncmp(flag, "<", 2)){
            FILE* file = fopen(specifier, "w");
            fclose(file);
        }
        else{
            clr();
        }

    }
    else if(!strncmp(command, "vanish", 7)){
        remove(specifier);
    }
    else if(!strncmp(command, "new", 4)){
        new(specifier);
    }
    else if(!strncmp(command, "dump", 5)){
        dump(specifier);
    }
    else if(!strncmp(command, "cbc", 4)){
        change_background_color();
    }
    else if(!strncmp(command, "echo", 5)){
        if(!strncmp(flag, "<", 2)){
            char* filecontents = Convert_file_to_string(specifier);
            echo(filecontents);
            free(filecontents);
        }
        else{
        echo(specifier);
        }
    }
    else if(!strncmp(command, "sexe", 5)){
        Convert_to_instructions_and_execute(specifier);
    }
    else{
        if(mode == '1'){
            printf("\ninvalid command!");
        }
    }
    return 0;
}
void funny(){
    printf("\nthere is nothing here");
}
void clr(){
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}
void dump(char *specifier){
        char linebuffer[1024];
        FILE *file = fopen(specifier, "r");
        while(fgets(linebuffer, 1024, file)){
            printf("%s", linebuffer);
        }
        fclose(file);
}
void new(char* specifier){
    FILE *file = fopen(specifier, "w");
    fclose(file);
}
void md(char* specifier){
    if(mkdir(specifier, 0755)){
        if(errno == EEXIST){
            printf("\ndirectory already exists");
        }
        else{
            printf("\nFAILED");
        }
    }
}
void change_background_color(){

}
void change_text_color(){

}
void echo(const char* printval){
    printf("\n%s", printval);
}


