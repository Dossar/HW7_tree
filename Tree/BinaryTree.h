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


    // This is for an individual node, containing node data and pointer to left and right children.

    typedef struct treenode {
        NodeData data;
        struct treenode *left, *right;
    } TreeNode, *TreeNodePtr;

    // This structure is the root node, the very top level.

    typedef struct {
        TreeNodePtr root;
        TreeNodePtr current;
    } BinaryTree;

    /*PROTOTYPES*/
//    hasLeft(BinaryNode *node);
//    hasRight(BinaryNode *node);
//    isLeaf(BinaryNode *node);
//    initBinaryTree(), (initializes Binary Tree);
//    fill_root(BinaryTree* T, BinaryTreeData data);
//    add(BinaryTree* T, BinaryNode *node, int left_or_right, BinaryTreeData data);
//
//    /*FUNCTIONS*/
//
//    hasLeft(BinaryNode *node) {
//
//    }
//
//    hasRight(BinaryNode *node) {
//
//    }
//
//    isLeaf(BinaryNode *node) {
//
//    }
//
//    initBinaryTree(), (initializes Binary Tree) {
//
//    }
//
//    fill_root(BinaryTree* T, BinaryTreeData data) {
//
//    }
//
//    add(BinaryTree* T, BinaryNode *node, int left_or_right, BinaryTreeData data) {
//
//    }



#ifdef	__cplusplus
}
#endif

#endif	/* TREE_H */

