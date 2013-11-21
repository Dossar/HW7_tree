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

void makeDecisionTree(Tree); // Creates Full Decision Tree with 8 leaves
void play(Tree); // Executes Decision Tree gameplay
void learn(Tree); // Optional

int main(int argc, char** argv) {

    Tree T = initBinaryTree(); // Initialize the binary tree.
    makeDecisionTree(T); // Create the Full Decision Tree with 8 leaves.
    play(T); // Play one round the yes-or-no game.

    return (EXIT_SUCCESS);
}

/* Creates a hardcoded binary tree with the base set of questions and answers.
   The user is also told here that he/she will be answering yes or no questions. */
void makeDecisionTree(Tree T) {

    /* Here we are adding the Questions and Answers.
     Yes will always go to the left node, No will always go to the right node.
     Start by making the root Node. */   
    BinaryNodePtr rootNode = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    rootNode->data.Question = "Do you want to eat fast food?";
    make_root(T, rootNode->data);

    /* QUESTIONS */
    
    // "Yes" to the root node. Node1 is the left node of the root.
    // Add "Do you want to eat fast food?"
    BinaryNodePtr Yes_Root_Node1 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Yes_Root_Node1->data.Question = "Are you willing to spend more than $30?";
    add(T->root, 0, Yes_Root_Node1);

    // "No" to the root node. Node2 is the right node of the root.
    // Add No to "Do you want to eat fast food?"
    BinaryNodePtr No_Root_Node2 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    No_Root_Node2->data.Question = "Do you like hamburgers?";
    add(T->root, 1, No_Root_Node2);

    // "Yes" to Node1, Node3 is the left node of Node1.
    // Add Yes to "Are you willing to spend more than $30?"
    BinaryNodePtr Yes_Node1_Node3 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Yes_Node1_Node3->data.Question = "More than $60?";
    add(Yes_Root_Node1, 0, Yes_Node1_Node3);

    // "Yes" to Node1, Node4 is the right node of Node1.
    // Add No to "Are you willing to spend more than $30?"
    BinaryNodePtr No_Node1_Node4 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    No_Node1_Node4->data.Question = "Do you like italian food?";
    add(Yes_Root_Node1, 1, No_Node1_Node4);

    // "Yes" to Node2 (root's right node), Node5 is left node of Node2.
    // Add Yes to "Do you like hamburgers?"
    BinaryNodePtr Yes_Node2_Node5 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Yes_Node2_Node5->data.Question = "Are you willing to eat <500 calories?";
    add(No_Root_Node2, 0, Yes_Node2_Node5);
    
    // "No" to Node2 (root's right node), Node6 is right node of Node2.
    // Add No to "Do you like hamburgers?"
    BinaryNodePtr No_Node2_Node6 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    No_Node2_Node6->data.Question = "Do you like tacos?";
    add(No_Root_Node2,1,No_Node2_Node6);    
    
    /*ANSWERS*/
    
    // Add Yes to Node3's question "More than $60?"
    BinaryNodePtr Answer1 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer1->data.Question = "Go to the Cheesecake Factory.";
    add(Yes_Node1_Node3,0,Answer1);
    
    // Add No to Node3's question "More than $60?"
    BinaryNodePtr Answer2 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer2->data.Question = "Go to Outback Steakhouse.";
    add(Yes_Node1_Node3,1,Answer2);
    
    // Add Yes to Node4's question "Do you like italian food?"
    BinaryNodePtr Answer3 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer3->data.Question = "Go to Olive Garden.";
    add(No_Node1_Node4,0,Answer3);
    
    // Add No to Node4's question "Do you like italian food?"
    BinaryNodePtr Answer4 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer4->data.Question = "Go to Applebees.";
    add(No_Node1_Node4,1,Answer4);
    
    // Add Yes to Node5's question "Are you willing to eat <500 calories?"
    BinaryNodePtr Answer5 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer5->data.Question = "Go to Five Guys.";
    add(Yes_Node2_Node5,0,Answer5);
    
    // Add No to Node5's question "Are you willing to eat <500 calories?"
    BinaryNodePtr Answer6 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer6->data.Question = "Go to Wendy's.";
    add(Yes_Node2_Node5,1,Answer6);
    
    // Add Yes to Node6's question "Do you like tacos?"
    BinaryNodePtr Answer7 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer7->data.Question = "Go to Taco Bell.";
    add(No_Node2_Node6,0,Answer7);
    
    // Add No to Node6's question "Do you like tacos?"
    BinaryNodePtr Answer8 = (BinaryNodePtr) malloc(sizeof (BinaryNode));
    Answer8->data.Question = "Go eat Chinese Food.";
    add(No_Node2_Node6,1,Answer8);
    
    /* FULL TREE BUILT WITH 8 LEAVES (ANSWERS) */
    printf("This program will help you decide where to eat based on yes-or-no questions.\n");

}

/* Simulates one round of the game. */
void play(Tree T) {

    // These three functions work.
    printf("Tree Height: %d\n", height(T->root));
    printf("Number of Nodes: %d\n", numNodes(T->root));
    printf("Number of Leaves: %d\n", numLeaves(T->root));

    // We start gameplay from the root. Set current pointer to root node.
    T->current = T->root;

    // Following line of code was for debugging.
    // printf("RETURN VALUE: %d\n", getData());

    // Loop until we encounter a leaf. If we are at a leaf, that means we arrived at an answer.
    // current keeps track of which node we are in the decision tree.
    while (!isLeaf(T->current)) { // Loop while our current position is not a leaf.
        printf("%s\n", T->current->data.Question); // Print the question to the user.
        // Get input from the user with getData function.
        if (getData()) {
            // If the user answered yes, move to the left node.
            T->current = T->current->left; // Move current to the left (yes) value
        } else {
            // If the user answered no, move to the right node.
            T->current = T->current->right; // Move current to the right (no) value
        }        
    }

    // Print the leaf's data (answer we arrived at).    
    printf("%s\n", T->current->data.Question);

}

/* This is optional. Creates an add node to tree to "learn" from the user. */
void learn(Tree T) {

}

