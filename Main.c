#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#include "read_file.h"
#define MAX_COMMAND_LENGTH 256
#define MAX_PATH_LENGTH 128
int main(){
    char commandbuffer[MAX_COMMAND_LENGTH];
    printf("welcome to my shell\n");
    bool exit = false;
    Convert_to_instructions_and_execute("config.myshell");
    while(!exit){
    char pathbuffer[MAX_PATH_LENGTH];
    if (getcwd(pathbuffer, sizeof(pathbuffer)) != NULL) {
        printf("\n#%s: ", pathbuffer);
    } else {
        perror("getcwd() error");
    }
        fgets(commandbuffer, MAX_COMMAND_LENGTH, stdin);
        exit = id_and_execute(commandbuffer, '1');
    }


    return 0;
}