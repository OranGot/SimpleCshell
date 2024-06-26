#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "read_file.h"
#include "commands.h"
const char* background_color[] = {
    "BLKB", "\e[40m",
    "REDB", "\e[41m",
    "GRNB", "\e[42m",
    "YELB", "\e[43m",
    "BLUB", "\e[44m",
    "MAGB", "\e[45m",
    "CYNB", "\e[46m",
    "WHTB", "\e[47m",
    NULL    
};
const char* text_color[] = {
    "BLK","\e[0;30m",
    "RED", "\e[0;31m",
    "GRN", "\e[0;32m",
    "YEL", "\e[0;33m",
    "BLU", "\e[0;34m",
    "MAG", "\e[0;35m",
    "CYN", "\e[0;36m",
    "WHT", "\e[0;37m",
    NULL                
};
void echo(const char* printval);
void new(char* specifier);
void dump(char *specifier);
void md(char* specifier);
void funny();
void clr();
void change_text_color(const char* CLR);
void change_background_color(const char* CLR);
bool id_and_execute(char *commandbuffer, char mode){
    char* command = strtok(commandbuffer, " \n");
    char* specifier = strtok(NULL, " \n");
    char* flag = strtok(NULL, " \n");
    if(!strncmp(command, "cd", 3)){
        if(specifier){
        chdir(specifier);
        }

    }
    else if(!strncmp(command, "quit", 5)){
        return 1;
    }
    else if(!strncmp(command, "md", 3)){
        if(flag){
        if(!strncmp(flag, "<", 2)){
            char* filecontents = Convert_file_to_string(specifier);
            md(filecontents);
            free(filecontents);
        }
        }
        else if(specifier){
            md(specifier);
        }
    }
    else if(!strncmp(command, "funny", 5)){
        funny();
    }
    else if(!strncmp(command, "clr", 4)){
        if(flag){
            if(!strncmp(flag, "<", 2)){
                if(specifier){
                FILE* file = fopen(specifier, "w");
                fclose(file);
                }   

            }
        }
        else{
            clr();
        }

    }
    else if(!strncmp(command, "vanish", 7)){
        if(specifier){
        remove(specifier);
        }
    }
    else if(!strncmp(command, "new", 4)){
        if(specifier){
        new(specifier);
        }

    }
    else if(!strncmp(command, "dump", 5)){
        if(specifier){
        dump(specifier);
        }

    }
    else if(!strncmp(command, "cbc", 4)){
        if(specifier){
        change_background_color(specifier);
        }
    }
    else if(!strncmp(command, "ctc", 4)){
        if(specifier){
            change_text_color(specifier);
        }
    }
    else if(!strncmp(command, "echo", 5)){
        if(flag && specifier){
        if(!strncmp(flag, "<", 2)){
            char* filecontents = Convert_file_to_string(specifier);
            echo(filecontents);
            free(filecontents);
        }
        }
        else if(specifier){
        echo(specifier);
        }
    }
    else if(!strncmp(command, "sexe", 5)){
        if(specifier){
        Convert_to_instructions_and_execute(specifier);
        }
    }
    else if(!strncmp(command, "man", 4)){
        printf("sexe: execute script\n"
        "cd: change directory\n"
        "md: make new directory\n"
        "echo: print something(1 word support only)\n"
        "vanish: destroy something\n"
        "< flag to load from file\n"
        "dump: dump the whole file to terminal\n"
        "clr: clear, crossplatform\n"
        "quit: quit\n"
        "funny: funny\n"
        "cbc: change background color\n"
        "ctc: change text color\n"
        "man: print out all the commands"
);
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
void change_background_color(const char* CLR){
   for(int i = 0; background_color[i] != NULL; i+=2){
        if(!strncmp(background_color[i], CLR, 5)){
            printf("%s", background_color[i+1]);
            break;
        }
    }
}
void change_text_color(const char* CLR){
    for(int i = 0; text_color[i] != NULL; i+=2){
        if(!strncmp(text_color[i], CLR, 4)){
            printf("%s", text_color[i+1]);
            break;
        }
    }
}
void echo(const char* printval){
    printf("\n%s",printval);
}