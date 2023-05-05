#include <stdio.h>
#include <stdlib.h>

//template code snippet
int main(int argc, char** argv) {

    //the cpu command
    char command[8];

    //get user input; 8-Bit cpu command
    printf("Type in a 8Bit cpu command: \n");
    scanf("%s", command);
    printf("%s\n", command);

    return 0;
}