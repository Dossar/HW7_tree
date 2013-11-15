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
   void add(Tree, BinaryNodePtr, int);

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

   /*Fill the root value with the values given*/
   void fill_root(Tree T, BinaryNodePtr node) {

   }

   /*Add a leaf to a give position in the tree*/
   void add(Tree T, BinaryNodePtr node, int left_or_right) {

   }



#ifdef	__cplusplus
}
#endif

#endif	/* TREE_H */

