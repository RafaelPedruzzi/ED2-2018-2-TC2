// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// bst.c: binary search tree implementation

#include <stdio.h>
#include <stdlib.h>

#include "../inc/bst.h"

// Function that initialize a new tree
Tree *bst_Init(void)
{
    return NULL;    // Tree pointer is initialized as null
}

// Funtion that destroys a given Tree
void bst_Destroy(Tree *root)
{
    if (root == NULL)   // Aborting the function if Tree is alredy null
    {
        return;
    }
    bst_Destroy(root->right);   // Destroing tree's rigth branch
    bst_Destroy(root->left);    // Destroing tree's left branch
    free(root);                 // Freeing the tree
}

// Function that insert a given value in a given Tree
Tree *bst_Insert(Tree *root, int value)
{
    if (root == NULL)                           // If tree is empty:
    {
        root = (Tree *)malloc(sizeof(Tree));    // Allocates a new Tree
        root->info = value;                     // Set new Tree's info
        root->left = root->right = NULL;        // Set branches as null
    }
    else if (value < root->info)                        // Else, if the value is smaller than root's info
        root->left = bst_Insert(root->left, value);     // It will be inserted in the left branch.
    else
        root->right = bst_Insert(root->right, value);   // Else, it will be inserted in the rigth branch
    return root;    // Returning root to update the tree's pointer
}

// Function that removes a Tree that contains a given value from a given root Tree
Tree *bst_Remove(Tree *root, int value)
{
    if (root == NULL)   // Aborting the function in case of the root is null.
        return NULL;
    if (value < root->info)                             // If value is smaller than root's info,
        root->left = bst_Remove(root->left, value);     // It will be removed from the root's left branch.
    else if (value > root->info)                        // Else, if it is bigger,
        root->right = bst_Remove(root->right, value);   // It will be removed from the root's right branch.
    else                                                // Else, root's info is equal to the value and the target to be removed.
    {
        if (root->left == NULL && root->right == NULL)  // If both branches are null,
        {
            free(root);                                 // Frees the root tree and
            root = NULL;                                // Set return value as null.
        }
        else if (root->left == NULL)    // Else, if only the left branch is null, the root will be freed and
        {
            Tree *t = root;             
            root = root->right;         // Return value will be seted as the root's right branch.
            free(t);
        }
        else if (root->right == NULL)   // Else, repeat the process returning the left branch.
        {
            Tree *t = root;
            root = root->left;
            free(t);
        }
        else                                            // Else, the root has both branches.
        {                                               // In this case, the biggest info of root's left tree will be exchanged for the root's info.
            Tree *f = root->left;
            while (f->right != NULL)                    // Finding biggest info in left tree.
            {
                f = f->right;
            }
            root->info = f->info;                       // Exchanging it for root.
            f->info = value;
            root->left = bst_Remove(root->left, value); // Removing, than, the value from the root's left branch.
        }
    }
    return root;    // Returning current satate of root to update the tree's pointer.
}

// Function that search a given value from a given Tree
Tree *bst_Search(Tree *root, int value)
{
    if (root == NULL)                           // If tree is empty returns null.
        return NULL;
    else if (root->info > value)                // Else, if the value is smaller than root's info,
        return bst_Search(root->left, value);   // Search it on the root's left branch.
    else if (root->info < value)                // Else, if the value is bigger than root's info,
        return bst_Search(root->right, value);  // Search it on the root's right branch.
    else                                        // Else, the value was found.
        return root;                            // Returning value's Tree.
}

void bst_Print(Tree *root)
{
    printf(" ( ");
    if (root != NULL)
    {
        bst_Print(root->left);
        printf("%d", root->info);
        bst_Print(root->right);
    }
    printf(" ) ");
}
