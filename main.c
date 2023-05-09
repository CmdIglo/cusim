#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//used for sleep() function Linux Users use: <unistd.h>
//#include <windows.h>

//own functions for CPU logic
#include "lib/functions.c"

/*
    incProgramCounter()
    decProgramCounter()
    getProgramCounter()
    dualMux()
    quadMux()
*/

//returns irload bit
int irload(int phase) {

    /**
     * TODO: binary exclusive or, or smth in that direction
    */
    if(phase == 0) {
        return 1;
    } else {
        return 0;
    }

}

//template code snippet
int main(int argc, char** argv) {

    //instruction register load bit
    //false, only true, if in phase 0 (IF&DE)
    int _irload = 0;

    //the cpu command
    //has to be 16 wide, because it can either be a command for the 8- or the 16-Bit cpu
    char command[16];

    /**
     * Bit 0 = LSB, Bit 8/16 = MSB
    */
    //binary operation at bit 6&7 of instruction (16-Bit: 14&15)
    char op1[2];
    //binary operation at bit 4&5 of instruction (16-Bit: 12&13)
    char op2[2];
    //target register at bit 2&3 of instruction (16-Bit: 10&11)
    char rd[2];
    //source register at bit 0&1 of instruction (16-Bit: 8&9)
    char rs[2];
    //immediate byte of 16-Bit instruction, bit 0-7 of instruction
    char immed[8];

    //get user input; 8-Bit cpu command
    printf("Type in a 8Bit cpu command: \n");
    scanf("%s", command);
    printf("%s\n", command);

    //TODO: errors, check string concat
    op1[0] = command[0];
    op1[1] = command[1];

    op2[0] = command[2];
    op2[1] = command[3];

    rd[0] = command[4];
    rd[1] = command[5];

    rs[0] = command[6];
    rs[1] = command[7];

    for(int i = 0; i<8; i++) {
        immed[i] = command[8+i];
    }

    printf("------\n");
    printf("op1: %s\n", op1);
    printf("op2: %s\n", op2);
    printf("data registry: %s\n", rd);
    printf("source registry: %s\n", rs);
    printf("immediate value (16-Bit): %s\n", immed);
    printf("------\n");

    //sets if the cpu is running
    bool running = true;
    //phase of the cpu workflow
    int phase = 0;

    //while loop = CPU frequency
    /**
     * TODO: Switch statements can be rewritten with functions, like irload()
    */
    while(running) {
        printf("%d\n", irload(phase));
        //check which CPU Phase we are in
        switch(phase) {
            //fetch
            case 0:
                //set irload to true
                _irload++;
                phase++;
                //increment the pc
                incProgramCounter();
                break;
            //decode
            case 1:
                //checks if a 16-Bit command has been passed by the user
                if(length(command) == 16) {
                    incProgramCounter(); //increment the pc by 1
                }
                _irload--;
                phase++;
                break;
            //fetch
            case 2:
                phase++;
                break;
            //execute
            case 3:
                phase = 0;
                return 0;
                break;
        }

        //CPU frequency is 10Hz
        //sleep(0.1);
    }

    return 0;
}