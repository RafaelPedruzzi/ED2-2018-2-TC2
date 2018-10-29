#include <stdio.h>
#include "../inc/bst.h"

int main(void)
{
    Tree *t = bst_Init();

    t = bst_Insert(t, 5);
    t = bst_Insert(t, 2);
    t = bst_Insert(t, 3);
    t = bst_Insert(t, 4);
    t = bst_Insert(t, 1);
    t = bst_Insert(t, 6);
    t = bst_Insert(t, 7);

    bst_Remove(t, 6);

    bst_Print(t);

    bst_Destroy(t);

    return 0;
}