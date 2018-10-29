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
    Tree *bst = bst_Init();                             // Initializing a binary search tree that represents the disks and keep the disk's occupied space.
    Tree *possibleDisk;                                 // Auxiliar pointer used to keep the last checked disk were the current analized value may fit.
    Tree *target;                                       // Auxiliar pointer used to go through the tree.
    int value, sum, nDisks = 0;                         // Auxiliar values that keep the current value being analyzed, the sum of this value with the value of the current tree being analyzed and the number of disks in use, respectively.

    for (int i = 0; i < nValues; i++)                   // Loop that insert each value in it best place in the tree.
    {
        value = values[i];                              // Getting the next value of the entry.
        possibleDisk = NULL;                            // Starting possibleDisk as null.
        target = bst;                                   // Starting target as the bst.

        while (target != NULL)                          // Loop that search the best tree to fit the value.
        {
            sum = target->value + value;                // Initializing sum as value plus target's value
            if (sum == DISK)                            // If sum is equals to the disk's limit then the value fits perfectly in the current tree ant there is no need of continue searching.
            {
                possibleDisk = target;                  // possibleDisk will be seted as current tree.
                break;                                  // And the loop will be interrupted.
            }
            if (sum > DISK)                             // Else, if sum is bigger than disk's limit, the search continues in the root's left branch.
            {
                target = target->left;                  // Updating target to the root's left branch.
            }
            else                                        // Else, sum is lesser than the limit and there may be a tree that it fits better. Thus the search continue in the root's rigth branch and this tree is saved in possibleDisk.
            {
                possibleDisk = target;                  // Setting possibleDisk as current tree.
                target = target->right;                 // Updating target to the root's right branch.
            }
        }

        if (possibleDisk == NULL)                       // After the loop, if possibleDisk is null then no possible fit was found and a new disk must be created.
        {
            bst = bst_Insert(bst, value);               // Inserting value in the bst as a new disk.
            nDisks++;                                   // Increasing number of disks.
        }
        else                                            // Else, the value will be added to the founded disk.
        {
            value += possibleDisk->value;               // Adding the disk's value to variable value.
            bst = bst_Remove(bst, possibleDisk->value); // Removing disk from the bst.
            bst = bst_Insert(bst, value);               // Inserting new disk with the sum of the values.
        }
    }

    bst_Destroy(bst);                                   // Destroing bst.

    return nDisks;                                      // Returning number of disks needed.
}
