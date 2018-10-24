// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// bst.h: binary search tree definitions

/**
 * Struct that implements a tree
 * 
 * info = tree's object
 * left = tree's left branch
 * right = tree's right branch
*/
typedef struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
} Tree;

/**
 * Function that initialize a new tree
 * 
 * output: a new Tree pointer
 * post-condition: tree is empty
*/
Tree *bst_Init(void);

/**
 * Funtion that destroys a given Tree
 * 
 * input: the tree that will be destroyed
 * post-condition: Tree freed from the memory
*/
void bst_Destroy(Tree *root);

/**
 * Function that insert a given value in a given Tree
 * 
 * inputs: pointer to the tree and value to be inserted
 * output: the tree with the new value inserted
 * post-condition: tree contains the value on a new leaf
*/
Tree *bst_Insert(Tree *root, int value);

/**
 * Function that removes a given Tree from a given root Tree
 * 
 * inputs: root tree and the target tree
 * output: root tree without the target
 * pre-condition: root contais the target
 * post-condition: target removed from the root tree
*/
Tree *bst_Remove(Tree *root, Tree *target);

/**
 * Function that search a given value from a given root Tree
 * 
 * inputs: root tree and value
 * output: pointer to the Tree that contains the value
 * pre-condition: root contais the value in at leas one of it's trees
 * post-condition: Tree unchanged
*/
Tree *bst_Search(Tree *root, int value);

void bst_Print(Tree *root);
