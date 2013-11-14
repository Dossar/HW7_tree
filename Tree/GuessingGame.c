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

// Whatever data is being stored in the nodes in this tree.
#define MAXSIZE 200  

typedef struct {
    char Question[MAXSIZE];
    char Answer[MAXSIZE];
} NodeData;

#include "BinaryTree.h"

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

