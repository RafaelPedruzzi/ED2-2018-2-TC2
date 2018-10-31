// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// bst.h: binary search tree definitions

/**
 * Struct that implements a tree
 * 
 * pi = tree's parent
 * value = tree's object (integer)
 * bf = balance factor
 * left = tree's left branch
 * right = tree's right branch
*/
typedef struct tree
{
    struct tree *pi;
    int value;
    int bf;
    struct tree *left;
    struct tree *right;
} Tree;

/**
 * Struct sentinel for the bst
 * 
 * root = tree's root
*/
typedef struct bst
{
    Tree *root;
} BST;

/**
 * Function that initialize a new tree
 * 
 * output: a new Tree pointer
 * post condition: tree is empty
*/
Tree *bst_Init(void);

/**
 * Funtion that destroys a given Tree
 * 
 * input: the tree that will be destroyed
 * post condition: Tree freed from the memory
*/
void bst_Destroy(Tree *root);

/**
 * Function that insert a given value in a given Tree
 * 
 * inputs: pointer to the tree and value to be inserted
 * output: the tree with the new value inserted
 * post condition: tree contains the value on a new leaf
*/
Tree *bst_Insert(Tree *root, int value);

/**
 * Function that removes a Tree that contains a given value from a given root Tree
 * 
 * inputs: root tree and the target tree
 * output: root tree without the target
 * pre condition: root contais the target
 * post condition: target removed from the root tree
*/
Tree *bst_Remove(Tree *root, int value);

/**
 * Function that search a given value from a given Tree
 * 
 * inputs: root tree and value
 * output: pointer to the Tree that contains the value
 * pre condition: root contais the value in at leas one of it's trees
 * post condition: Tree unchanged
*/
Tree *bst_Search(Tree *root, int value);

/**
 * Function that prints a given tree
 * 
 * input: Tree to be printed
 * post condition: Tree unchanged
*/
void bst_Print(Tree *root);
