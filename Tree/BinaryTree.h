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
        BinaryNodePtr current;
    } BinaryTree, *Tree;

    /*PROTOTYPES*/
    bool hasLeft(BinaryNodePtr);
    bool hasRight(BinaryNodePtr);
    bool isLeaf(BinaryNodePtr);
    Tree initBinaryTree(void);
    void fill_root(Tree, BinaryNodePtr);
    void add(BinaryNodePtr, int, BinaryNodePtr);
    int height(BinaryNodePtr);
    int numNodes(BinaryNodePtr);
    int numLeaves(BinaryNodePtr);

    int getData();

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

    /*Add a leaf to the node given in the tree (No memory allocation)*/
    void add(BinaryNodePtr node, int l_or_r, BinaryNodePtr data) {
        // 1 = ADD TO RIGHT   0 = ADD TO LEFT
        if (node->left == NULL && l_or_r == 0) { // add right leaf            
            node->left = data; // add node to tree
        } else {
            if (node->right == NULL && l_or_r == 1) { // add left leaf               
                node->right = data; // add node to tree
            }
        }

    }

#define max(a,b) ((a)>(b)?(a):(b))

    /* Returns the hight of the tree */
    int height(BinaryNodePtr root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));

    }

    /*Returns the total number of nodes in the tree */
    int numNodes(BinaryNodePtr root) {
        if (root == NULL)return 0;
        return 1 + numNodes(root->left) + numNodes(root->right);

    }

    int numLeaves(BinaryNodePtr root) {
        if (root == NULL)return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        return numLeaves(root->left) + numLeaves(root->right);
    }

#define NAMESIZE 80

    /*Gets data from the user and returns a 1 or 0 depending on a yes no response*/
    int getData() {
        char *response = (char*) malloc(sizeof (char)*NAMESIZE); // allocate new memory        
        size_t responseSize = sizeof (response);
        int bytes_read = 1;       

        // IF STRING IS WRONG, LOOP UNTIL IT IS CORRECT        
        while (1) {
            

            // GET STRING
            printf("(y/n) -> ");
            bytes_read = getline(&response, &responseSize, stdin);
            if (bytes_read == -1) {
                // a stream issue has occured,
                printf("INPUT ERROR.\n");
                exit(1);
            } else {
                strtok(response, "\n"); // remove the endline token from the input string
            }

            if (strcmp(response, "y") == 0 || strcmp(response, "n") == 0 || strcmp(response, "yes") == 0 || strcmp(response, "no") == 0) {                
                break;                
            } else {
                *response = 0; // reset string
                continue;
            }           
        }

        // based on valid input return a value
        if (strcmp(response, "y") == 0 || strcmp(response, "yes") == 0) {
            *response = 0; // reset string           
            return 1;
        } else {
            *response = 0; // reset string            
            return 0;
        }

    }




#ifdef	__cplusplus
}
#endif

#endif	/* TREE_H */

