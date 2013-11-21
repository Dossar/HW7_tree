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
    rootNode->data.Question = "Do you want to eat fast food?";
    make_root(T, rootNode->data); // add root node

    // yes to root (Node1)
    BinaryNodePtr Yes_Root_Node1 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Yes_Root_Node1->data.Question = "Are you willing to spend more than $30?"; // add question
    add(T->root, 1, Yes_Root_Node1); // add yes to root question

    // no to root (Node2)
    BinaryNodePtr No_Root_Node2 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    No_Root_Node2->data.Question = "Do you like hamburgers?";
    add(T->root, 0, No_Root_Node2); // add no to root question

    // yes to Node1 (Node3)
    BinaryNodePtr Yes_Node1_Node3 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Yes_Node1_Node3->data.Question = "More than $60?";
    add(Yes_Root_Node1, 0, Yes_Node1_Node3);

    // no to Node1 (Node4)
    BinaryNodePtr No_Node1_Node4 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    No_Node1_Node4->data.Question = "Do you like italian food?";
    add(Yes_Root_Node1, 1, No_Node1_Node4);

    // yes to Node2 (Node5)
    BinaryNodePtr Yes_Node2_Node5 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Yes_Node2_Node5->data.Question = "Are you willing to eat <500 calories?";
    add(No_Root_Node2, 0, Yes_Node2_Node5);
    
    // no to Node2 (Node6)
    BinaryNodePtr No_Node2_Node6 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    No_Node2_Node6->data.Question = "Do you like tacos?";
    add(No_Root_Node2,1,No_Node2_Node6);
    
    
    /*ANSWERS*/
    
    // yes to Node3
    BinaryNodePtr Answer1 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer1->data.Question = "Cheesecake Factory";
    add(Yes_Node1_Node3,0,Answer1);
    
    // no to Node3
    BinaryNodePtr Answer2 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer2->data.Question = "Outback Steakhouse";
    add(Yes_Node1_Node3,1,Answer2);
    
    // yes to Node4
    BinaryNodePtr Answer3 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer3->data.Question = "Olive Garden";
    add(No_Node1_Node4,0,Answer3);
    
    // no to Node4
    BinaryNodePtr Answer4 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer4->data.Question = "Applebees";
    add(No_Node1_Node4,1,Answer4);
    
    // yes to Node5
    BinaryNodePtr Answer5 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer5->data.Question = "Five Guys Burgers";
    add(Yes_Node2_Node5,0,Answer5);
    
    // no to Node5
    BinaryNodePtr Answer6 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer6->data.Question = "Wendys";
    add(Yes_Node2_Node5,1,Answer6);
    
    // yes to Node6
    BinaryNodePtr Answer7 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer7->data.Question = "Taco Bell";
    add(No_Node2_Node6,0,Answer7);
    
    // no to Node6
    BinaryNodePtr Answer8 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer8->data.Question = "Eat Chinese Food";
    add(No_Node2_Node6,1,Answer8);

}

/* Simulates one round of the game */
void play(Tree T) {

    printf("Tree height: %d\n", height(T->root));
    printf("Nodes: %d\n", numNodes(T->root));
    printf("Leaves: %d\n", numLeaves(T->root));

    // start gameplay from the top of the tree so
    T->current = T->root;

    //printf("RETURN VALUE: %d\n", getData());

    //loop until we encounter a leaf
    while (!isLeaf(T->current)) { // loop while our current position is not a leaf.
        printf("%s\n", T->current->data.Question); // print the question
        if (getData()) {
            // if answered yes
            T->current = T->current->left; // move current to the left or yes value
        } else {
            // if answered no
            T->current = T->current->right; // move current
        }        
    }


    // print the leaf question data (the answer)    
    printf("%s\n", T->current->data.Question);


}

/* This is optional. Creates an add node to tree to "learn" from the user. */
void learn(Tree T) {

}

