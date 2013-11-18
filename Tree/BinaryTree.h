/* 
 * File:   tree.h
 * Author: mike
 *
 * Created on November 13, 2013, 10:29 AM
 */

/*
structure BinaryNode with fields: BinaryTreeData data, BinaryNode *left, BinaryNode *right;  
structure BinaryTree with fields: BinaryNode *root, BinaryNode *current_node; 
FUNCTIONS
hasLeft(BinaryNode *node), 
hasRight(BinaryNode *node), 
isLeaf(BinaryNode *node),
initBinaryTree(), (initializes Binary Tree)
fill_root(BinaryTree* T, BinaryTreeData data)
add(BinaryTree* T, BinaryNode *node, int left_or_right, BinaryTreeData data) 
 */

#ifndef TREE_H
#define	TREE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>


    // This is for an individual node, containing node data and pointer to left and right children.

    typedef struct node {
        NodeData data;
        struct node *left, *right;
    } BinaryNode, *BinaryNodePtr;

    // This structure is the root node, the very top level.

    typedef struct tree {
        BinaryNodePtr root;
        BinaryNodePtr current; // creates 
    } BinaryTree, *Tree;

    /*PROTOTYPES*/
    bool hasLeft(BinaryNodePtr);
    bool hasRight(BinaryNodePtr);
    bool isLeaf(BinaryNodePtr);
    Tree initBinaryTree(void);
    void fill_root(Tree, BinaryNodePtr);
    void add(Tree, BinaryNodePtr, int);
    int height(Tree T);
    int numNodes(Tree T);
    int numLeaves(Tree T);

    /*FUNCTIONS*/

    /*Initalizes a new binary tree*/
    Tree initBinaryTree() {
        Tree T = (Tree) malloc(sizeof (BinaryTree)); // allocate new space in memory for Tree
        T->root = NULL;
        T->current = NULL;
        return T;
    }

    /*Return true/false if the node at the address has a left value*/
    bool hasLeft(BinaryNodePtr node) {
        if (node->left == NULL) {
            return false;
        } else {
            return true;
        }
    }

    /*Return true/false if the node at the address has a right value*/
    bool hasRight(BinaryNodePtr node) {
        if (node->right == NULL) {
            return false;
        } else {
            return true;
        }
    }

    /*Return true/false if the node at the address is an outer leaf*/
    bool isLeaf(BinaryNodePtr node) {
        if (!hasRight(node)&&!hasLeft(node)) {
            return true; // if node has no valid pointers to new values it is considered a leaf
        } else {
            return false; // if current node has more right or left values
        }
    }

    /* sets the root value at the top of the tree. only if root is null */
    void make_root(Tree T, NodeData data) {
        if (T->root == NULL) {
            BinaryNodePtr node = (BinaryNodePtr) malloc(sizeof (BinaryNode)); // allocate new space for root node
            node->data = data;
            T->root = node;
        } else {
            printf("\nroot exists already.");
            exit(0); // exit program
        }
    }

    /*Add a leaf to the node given in the tree*/
    void add(Tree T, BinaryNodePtr node, int l_or_r, NodeData data) {

        if (node->left == NULL && l_or_r == 1) { // add right leaf
            BinaryNodePtr addNode = (BinaryNodePtr) malloc(sizeof (BinaryNode)); // allocate new space for new leaf
            addNode->data = data; // add data to new node
            node->left = addNode; // add node to tree
        } else {
            if (node->right == NULL && l_or_r == 0) { // add left leaf
                BinaryNodePtr addNode = (BinaryNodePtr) malloc(sizeof (BinaryNode)); // allocate new space for new leaf
                addNode ->data = data; // add data to node
                node->right = addNode; // add node to tree
            }
        }

    }

#define max(a,b) ((a)>(b)?(a):(b))

    /* Returns the hight of the tree */
    int height(Tree T) {
        if (T->current == NULL) return 0;
        return 1 + max(height(T->root->left) + height(T->root->right));

    }

    /*Returns the total number of nodes in the tree */
    int numNodes(Tree T) {
        if (T->current == NULL)return 0;
        return 1 + numNodes(T->root->left) + numNodes(T->root->right);

    }

    int numLeaves(Tree T) {
        if (T->current == NULL)return 0;
        if (T->root->left == NULL && T->root->right == NULL) return 1;
        return numLeaves(T->root->left)+(T->root->right);
    }



#ifdef	__cplusplus
}
#endif

#endif	/* TREE_H */

