// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// bst.c: binary search tree implementation

#include <stdio.h>
#include <stdlib.h>

#include "../inc/bst.h"

Tree *bst_Init(void)
{
    return NULL;
}

void bst_Destroy(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    bst_Destroy(root->right);
    bst_Destroy(root->left);
    free(root);
}

Tree *bst_Insert(Tree *root, int value)
{
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->info = value;
        root->left = root->right = NULL;
    }
    else if (value < root->info)
        root->left = bst_Insert(root->left, value);
    else
        root->right = bst_Insert(root->right, value);
    return root;
}

Tree *bst_Remove(Tree *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (root->info > value)
        root->left = bst_Remove(root->left, value);
    else if (root->info < value)
        root->right = bst_Remove(root->right, value);
    else
    {
        /* achou o nó a remover */
        /* nó sem filhos */
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        /* nó só tem filho à direita */
        else if (root->left == NULL)
        {
            Tree *t = root;
            root = root->right;
            free(t);
        }
        /* só tem filho à esquerda */
        else if (root->right == NULL)
        {
            Tree *t = root;
            root = root->left;
            free(t);
        }
        /* nó tem os dois filhos */
        else
        {
            Tree *f = root->left;
            while (f->right != NULL)
            {
                f = f->right;
            }
            root->info = f->info;
            /* troca as informações */
            f->info = value;
            root->left = bst_Remove(root->left, value);
        }
    }
    return root;
}

Tree *bst_Search(Tree *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (root->info > value)
        return bst_Search(root->left, value);
    else if (root->info < value)
        return bst_Search(root->right, value);
    else
        return root;
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
