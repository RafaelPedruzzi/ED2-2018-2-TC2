// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// worstFit.h: worst fit and decreasing worst fit definitions

#ifndef BESTFIT_H_

#define BESTFIT_H_

#define DISK 1000000

/**
 * Function that implements the best fit heuristic
 * 
 * input: array of integers and the it's lenght
 * output: number of disks needed
 * pre-condition: array not empty
 * post-condition: input array unchanged
*/
int bestFit(int *values, int nValues);

#endif
