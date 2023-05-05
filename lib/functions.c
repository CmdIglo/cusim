/**
 * The functionality of the CPU components
*/

#include <stdlib.h>

//Quadruple MUX; i.e. Multiplexer with 4 inputs
//phase: which phase the cu is in (0: Fetch&Decode, 1:Fetch, 2:Execute)
int quadMux(int phase, int one, int two, int three, int four) {

    //mux logic here
    switch(phase) {
        case 0:
            return one;
            break;
        case 1:
            return two;
            break;
        case 10:
            return three;
            break;
        case 11:
            return four;
            break;
    }

}

//dual MUX; i.e. Multiplexer with two inputs
int dualMux(int pcsel, int one, int two) {

    //mux logic here
    if(pcsel == 0) {
        return one;
    } else if(pcsel > 0) {
        return two;
    }

}