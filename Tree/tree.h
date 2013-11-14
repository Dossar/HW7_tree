/* 
 * File:   tree.h
 * Author: mike
 *
 * Created on November 13, 2013, 10:29 AM
 */

#ifndef TREE_H
#define	TREE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h> 
#include <string.h>
    
#define MaxSize 100
    
    // Whatever data is being stored in the nodes in this tree.
    typedef struct {
        char QuestionAnswer[MaxSize];
    } NodeData;
    
    // This is for an individual node, containing node data and pointer to left and right children.
    typedef struct treenode {
        NodeData data;
        struct treenode *left, *right;
    } TreeNode, *TreeNodePtr;
    
    // This structure is the root node, the very top level.
    typedef struct {
        TreeNodePtr root;
    } BinaryTree;
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* TREE_H */

