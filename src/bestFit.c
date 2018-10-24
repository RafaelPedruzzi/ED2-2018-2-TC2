// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// bestFit.c: best fit and decreasing best fit implementations

#include <stdio.h>
#include <stdlib.h>
#include "../inc/bst.h"

#include "../inc/bestFit.h"

// Function that implements the best fit heuristic
int bestFit(int *values, int nValues)
{
    Tree *bst = bst_Init();
    Tree *possibleDisk;
    Tree *target;
    int value, sum, nDisks=0;

    //bst_Insert(bst, values[0]);

    for (int i = 0; i < nValues; i++)
    {
        value = values[i];
        possibleDisk = NULL;
        target = bst;

        while (target != NULL)
        {
            sum = target->info + value;
            if (sum == DISK)
            {
                possibleDisk = target;
                break;
            }
            else
            {
                if(sum > DISK)
                {
                    target = target->left;
                }
                else
                {
                    possibleDisk = target;
                    target = target->right;
                }
            }
        }

        if(possibleDisk == NULL)
        {
            bst = bst_Insert(bst, value);
            nDisks++;
            //bst_Print(bst);
            //printf("\n");
        }
        else
        {
            value += possibleDisk->info;
            bst = bst_Remove(bst, possibleDisk);
            bst_Insert(bst, value);
            //bst_Print(bst);
            //printf("\n");
        }
    }

    bst_Destroy(bst);

    return nDisks;
}
