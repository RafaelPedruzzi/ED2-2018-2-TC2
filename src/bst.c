// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// bst.c: binary search tree implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../inc/bst.h"

bool changeHigth;   // Auxiliar variable used for auto-balance the tree

// Function that initialize a new tree.
Tree *bst_Init(void)
{
    return NULL;    // Tree's pointer is initialized as null.
}

// Funtion that destroys a given Tree.
void bst_Destroy(Tree *root)
{
    if (root == NULL)           // Aborting the function if Tree is already null.
    {
        return;
    }
    bst_Destroy(root->right);   // Destroing tree's rigth branch.
    bst_Destroy(root->left);    // Destroing tree's left branch.
    free(root);                 // Freeing the tree.
}

// Function that insert a given value in a given Tree.
Tree *bst_Insert(Tree *root, int value)
{
    if (root == NULL)                                   // If tree is empty:
    {
        root = (Tree *)malloc(sizeof(Tree));            // Allocates a new Tree.
        root->value = value;                            // Set new Tree's value.
        root->left = root->right = NULL;                // Set branches as null.
        root->amount = 1;                               // Set initial amount as 1.
        root->bf = 0;                                   // Set initial balance factor as 0
    }
    else if (value == root->value)                      // Else, if root's value and value are equals, root's amount is incremented
        root->amount++;
    else if (value < root->value)                       // Else, if the value is smaller than root's value.
        root->left = bst_Insert(root->left, value);     // It will be inserted in the left branch.
    else
        root->right = bst_Insert(root->right, value);   // Else, it will be inserted in the rigth branch.
    return root;                                        // Returning root to update the tree's pointer.
}

// Function that removes a Tree that contains a given value from a given root Tree
Tree *bst_Remove(Tree *root, int value)
{
    if (root == NULL)                                   // Aborting the function in case of the root is null.
        return NULL;
    if (value < root->value)                            // If value is smaller than root's value:
        root->left = bst_Remove(root->left, value);     // It will be removed from the root's left branch.
    else if (value > root->value)                       // Else, if it is bigger:
        root->right = bst_Remove(root->right, value);   // It will be removed from the root's right branch.
    else                                                // Else, root's value is equal to the value and the target to be removed.
    {
        if (root->amount > 1)                           // If amount is bigger than one it is decremented
        {
            root->amount--;
        }
        else if (root->left == NULL && root->right == NULL)  // Else, if both branches are null:
        {
            free(root);                                 // Frees the root tree.
            root = NULL;                                // Set return value as null.
        }
        else if (root->left == NULL)                    // Else, if only the left branch is null, the root will be freed and
        {
            Tree *t = root;             
            root = root->right;                         // Return value will be seted as the root's right branch.
            free(t);
        }
        else if (root->right == NULL)                   // Else, repeat the process returning the left branch.
        {
            Tree *t = root;
            root = root->left;
            free(t);
        }
        else                                            // Else, the root has both branches.
        {                                               // In this case, the biggest value of root's left tree will be exchanged for the root's value.
            Tree *f = root->left;
            while (f->right != NULL)                    // Finding biggest value in left tree.
            {
                f = f->right;
            }
            root->value = f->value;                     // Exchanging it for root.
            root->amount = f->amount;
            f->value = value;
            f->amount = 1;
            root->left = bst_Remove(root->left, value); // Removing, than, the value from the root's left branch.
        }
    }
    return root;                                        // Returning current satate of root to update the tree's pointer.
}

// Function that search a given value from a given Tree.
Tree *bst_Search(Tree *root, int value)
{
    if (root == NULL)                           // If tree is empty returns null.
        return NULL;
    if (value < root->value)                    // Else, if the value is smaller than root's value:
        return bst_Search(root->left, value);   // Search it on the root's left branch.
    if (value > root->value)                    // Else, if the value is bigger than root's value:
        return bst_Search(root->right, value);  // Search it on the root's right branch.
    return root;                                // Else, the correct value was found. Returning value's Tree.
}

// Function that prints a given tree
void bst_Print(Tree *root)
{
    printf(" [");                       // Printing '['.
    if (root != NULL)                   // Printing tree if it is not null.
    {
        printf(" %dx%d ", root->value, root->amount);    // Printing root's value.
        bst_Print(root->left);          // Printing root's left branch.
        bst_Print(root->right);         // Printing root's right branch.
    }
    printf("] ");                       // Printing ']'.
}
