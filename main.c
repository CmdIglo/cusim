#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//used for sleep() function; Linux Users use: <unistd.h>
#include <windows.h>

//template code snippet
int main(int argc, char** argv) {

    //the cpu command
    //has to be 16 wide, because it can either be a command for the 8- or the 16-Bit cpu
    char command[16];

    //get user input; 8-Bit cpu command
    printf("Type in a 8Bit cpu command: \n");
    scanf("%s", command);
    printf("%s\n", command);

    //sets if the cpu is running
    bool running = true;
    //phase of the cpu workflow
    int phase = 0;

    //while loop = CPU frequency
    while(running) {
        //check which CPU Phase we are in
        switch(phase) {
            //fetch
            case 0:
                phase++;
                break;
            //decode
            case 1:
                phase++;
                break;
            //fetch
            case 2:
                phase++;
                break;
            //execute
            case 3:
                phase = 0;
                break;
        }

        //CPU frequency is 10Hz
        sleep(0.1);
    }

    return 0;
}