/* 
 * File:   main.c
 * Author: mike
 *
 * Created on November 13, 2013, 10:29 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
define BinaryTreeData as a string (array of chars)
include BinaryTree.h
define functions: makeDecisionTree, play, learn - optional
main should do the following:
create variable decisionTree of type BinaryTree //use initBinaryTree
call makeDecisionTree(BinaryTree* T) // fill decisionTree with questions (nodes) and answers (leaves), calling functions fill_root and add 
call play(BinaryTree* T) – simulating 1 round of the game, introducing variable currentNode and calling isLeaf(currentNode)
allow us to play as many rounds as the user wants – optional
call learn(BinaryTree* T) -  change a leaf with incorrect answer to a question node with children:  correct and incorrect answer – optional 
 */


#include <stdbool.h>

// Whatever data is being stored in the nodes in this tree.
#define MAXSIZE 200  

typedef struct {
    char *Question;
    bool Answer;
} NodeData;

#include "BinaryTree.h"

void makeDecisionTree(Tree);
void play(Tree);
void learn(Tree);

int main(int argc, char** argv) {

    Tree T = initBinaryTree();
    makeDecisionTree(T);
    play(T);



    return (EXIT_SUCCESS);
}

/* Creates a hardcoded binary tree with the base set of questions and answers. */
void makeDecisionTree(Tree T) {

    /* Add questions in some logical order */
    // add the root question
    BinaryNodePtr rootNode = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    rootNode->data.Question = "Are you happy?";

    // yes to root
    BinaryNodePtr LRoot_Node1 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    LRoot_Node1->data.Question = "Keep doing whatever you're doing.";

    // no to root
    BinaryNodePtr RRoot_Node2 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    RRoot_Node2->data.Question = "Do you want to be happy?";

    // yes to Node2
    BinaryNodePtr LNode2_Node3 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    LNode2_Node3->data.Question = "Change something.";

    // no to Node2
    BinaryNodePtr RNode2_Node4 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    RNode2_Node4->data.Question = "Keep doing whatever you're doing.";

    /* Construct tree */
    make_root(T, rootNode->data); // add root node
    add(T->root, 0, LRoot_Node1); // add yes to root question
    add(T->root, 1, RRoot_Node2); // add no to root question
    add(RRoot_Node2, 0, LNode2_Node3); // add yes to Node2 question
    add(RRoot_Node2, 1, RNode2_Node4); // add no to Node2 question

}

/* Simulates one round of the game */
void play(Tree T) {

    printf("Tree height: %d\n", height(T->root));
    printf("Nodes: %d\n", numNodes(T->root));
    printf("Leaves: %d\n", numLeaves(T->root));

    // start gameplay from the top of the tree so
    T->current = T->root;

    printf("RETURN VALUE: %d\n", getData());

    // loop until we encounter a leaf
    //    while (!isLeaf(T->current)) {
    //        printf("%s\n", T->current->data.Question); // print the question
    //        if (getData()) {
    //
    //            // stuff
    //
    //        }
    //    }

}

/* This is optional. Creates an add node to tree to "learn" from the user. */
void learn(Tree T) {

}

