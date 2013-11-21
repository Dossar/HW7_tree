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


    /* This structure is for an individual node
       containing node data and pointers to left and right children. */
    typedef struct node {
        NodeData data;
        struct node *left, *right;
    } BinaryNode, *BinaryNodePtr;

    /* This structure contains a pointer to the root node and the current node.
       The root node is the very top level, current keeps track of the node we are at in the tree. */
    typedef struct tree {
        BinaryNodePtr root;
        BinaryNodePtr current;
    } BinaryTree, *Tree;

    /* FUNCTION PROTOTYPES */
    bool hasLeft(BinaryNodePtr); // Checks if the node has a left child.
    bool hasRight(BinaryNodePtr); // Checks if the node has a right child.
    bool isLeaf(BinaryNodePtr); // Checks if the node is a leaf (has no children)
    Tree initBinaryTree(void); // Initializes the tree.
    void make_root(Tree, NodeData); // Makes the root of the tree.
    void add(BinaryNodePtr, int, BinaryNodePtr); // Adds a node to the tree.
    int height(BinaryNodePtr); // Calculates height of the tree.
    int numNodes(BinaryNodePtr); // Calculates number of nodes in tree.
    int numLeaves(BinaryNodePtr); // Calculates number of leaves in tree (leaves have no children)
    int getData();

    /* FUNCTIONS */

    /* Initalizes a new binary tree. */
    Tree initBinaryTree() {
        Tree T = (Tree) malloc(sizeof (BinaryTree)); // Allocate new space in memory for Tree
        T->root = NULL; // We initialize root to NULL first. We use another function to make the root.
        T->current = NULL;
        return T;
    }

    /* Return true or false if the node at the address has a left value. */
    bool hasLeft(BinaryNodePtr node) {
        if (node->left == NULL) {
            return false; // NULL means the node doesn't have a left child.
        } else {
            return true; // Otherwise, the node has a left child.
        }
    }

    /* Return true or false if the node at the address has a right value. */
    bool hasRight(BinaryNodePtr node) {
        if (node->right == NULL) {
            return false; // NULL means the node doesn't have a right child.
        } else {
            return true; // Otherwise, the node has a right child.
        }
    }

    /* Return true or false if the node at the address has no left or right nodes. */
    bool isLeaf(BinaryNodePtr node) {
        if (!hasRight(node)&&!hasLeft(node)) {
            return true; // If the node has no right or left children, it is a leaf.
        } else {
            return false; // Otherwise, it has at least one child and is not a leaf.
        }
    }

    /* Sets the root value at the top of the tree, only if root is null. */
    void make_root(Tree T, NodeData data) {
        if (T->root == NULL) {
            // If root is null, allocate new space for root node.
            BinaryNodePtr node = (BinaryNodePtr) malloc(sizeof (BinaryNode));
            node->data = data;
            T->root = node;
        } else {
            // If the root is not null, that means the root already exists.
            // printf("\nRoot exists already.");
            exit(0); // exit program
        }
    }

    /* Add a leaf to the node given in the tree (No memory allocation) */
    void add(BinaryNodePtr node, int l_or_r, BinaryNodePtr data) {
        // 1 = ADD TO RIGHT   0 = ADD TO LEFT
        if (node->left == NULL && l_or_r == 0) { // Add Left Leaf           
            node->left = data; // Add Left Node to the tree
        } else {
            if (node->right == NULL && l_or_r == 1) { // Add Right Leaf               
                node->right = data; // Add Right Node to the tree
            }
        }

    }

#define max(a,b) ((a)>(b)?(a):(b))

    /* Calculates and returns the height of the tree recursively. */
    int height(BinaryNodePtr root) {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));

    }

    /*Returns the total number of nodes in the tree */
    int numNodes(BinaryNodePtr root) {
        if (root == NULL)
            return 0;
        return 1 + numNodes(root->left) + numNodes(root->right);

    }

    int numLeaves(BinaryNodePtr root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1; // This is the case where the tree only has the root.
        return numLeaves(root->left) + numLeaves(root->right);
    }

#define NAMESIZE 80

    /* Gets data from the user and returns a 1 or 0 depending on a yes no response. */
    int getData() {
        char *response = (char*) malloc(sizeof (char)*NAMESIZE); // Allocate new memory for user input, maximum 80        
        size_t responseSize = sizeof (response);
        int bytes_read = 1;       

        // IF STRING IS WRONG, LOOP UNTIL IT IS CORRECT        
        while (1) {
            

            // GET STRING
            printf("(y/n) -> ");
            bytes_read = getline(&response, &responseSize, stdin);
            if (bytes_read == -1) {
                // A stream issue has occurred.
                printf("INPUT ERROR.\n");
                exit(1);
            } else {
                strtok(response, "\n"); // Remove the newline token from the input string.
            }
            
            if (strcmp(response, "y") == 0 || strcmp(response, "n") == 0 || strcmp(response, "yes") == 0 || strcmp(response, "no") == 0) {                
                break; // This case means that the user has correctly inputted a valid answer.                
            } else {
                *response = 0; // Reset string
                continue;
            }           
        }

        // Based on valid input, return a value.
        if (strcmp(response, "y") == 0 || strcmp(response, "yes") == 0) {
            *response = 0; // Reset string           
            return 1; // Returning 1 means the user answered yes.
        } else {
            *response = 0; // Reset string            
            return 0; // Returning 0 means the user answered no.
        }

    }




#ifdef	__cplusplus
}
#endif

#endif	/* TREE_H */

