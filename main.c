#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//used for sleep() function Linux Users use: <unistd.h>
//#include <windows.h>

//own functions for CPU logic
#include "lib/functions.c"
//arithmetics logic unit
#include "lib/alu.c"

/*
    incProgramCounter()
    decProgramCounter()
    getProgramCounter()
    dualMux()
    quadMux()
*/

/**
 * TODO: CPU has to read from memory.txt
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

    //aluop
    op2[0] = command[2];
    op2[1] = command[3];

    //data registry
    rd[0] = command[4];
    rd[1] = command[5];

    //source registry
    rs[0] = command[6];
    rs[1] = command[7];

    //immediate Byte
    for(int i = 0; i<8; i++) {
        immed[i] = command[8+i];
    }

    printf("------\n");
    /*
    //check if the values are stored properly
    printf("%d", op1[0] & 1);
    printf("%d\n", op1[1] & 1);
    printf("%d", op2[0] & 1);
    printf("%d\n", op2[1] & 1);
    printf("%d", rd[0] & 1);
    printf("%d\n", rd[1] & 1);
    printf("%d", rs[0] & 1);
    printf("%d\n", rs[1] & 1);
    printf("%d\n", immed[0] & 1);
    */
    printf("op1: \n");
    printf("%d", op1[0] & 1);
    printf("%d\n", op1[1] & 1);
    printf("op2: \n");
    printf("%d", op2[0] & 1);
    printf("%d\n", op2[1] & 1);
    printf("data registry: \n");
    printf("%d", rd[0] & 1);
    printf("%d\n", rd[1] & 1);
    printf("source registry: \n");
    printf("%d", rs[0] & 1);
    printf("%d\n", rs[1] & 1);
    printf("------\n");

    //sets if the cpu is running
    //TODO: currently false, because logic in while loop not complete
    bool running = false;
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
                if(strlen(command) == 16) {
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

    //test part of script
    printf("\nTESTS: \n");
    setProgramCounter(0);
    for(int i = 0; i < 10; i++) {
        printf("%d ", getProgramCounter());
        incProgramCounter();
        if(i == 9) {
            printf("\n");
        }
    }

    return 0;
}