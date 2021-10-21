#ifndef BinarySearchTree_H
#define BinarySearchTree_H
#include "player.h"
struct Node
{
    int value;
    Node* left;
    Node* right;
};
class BinarySearchTree
{
private:
    Node* root;
    int size;
    void desorder(Node* n); //function to arrange scores in descending order
public:
    BinarySearchTree(); //constructor to intialize the root and the size to zero 
    void insert(int data); //function to insert the scores in the tree
    void printdes(); //function to print the scored in descending order
    void read(); // function to read from file 
};
#endif