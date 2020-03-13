// File: bin_tree.cpp
// Created by: Michael Napoli
// Created on: 3/11/2020
// Last modified on:

/*
   Purpose: Program to test the 'TreeNode' structure along with
      its helper functions. This data structure is meant to be used
      with binary tree based data sets.
*/

#include <iostream>
#include <cstddef>
#include <cassert>

using namespace std;

struct TreeNode{
   int data;
   TreeNode *left;
   TreeNode *right;
};

// Function declarations
int size(TreeNode* root);
int count(TreeNode* root, int target);
int height(TreeNode* root);
bool isSameTree(TreeNode* root1, TreeNode* root2);
bool hasPathSum(TreeNode* root, int target);
bool isBalanced(TreeNode* root);

// feel free to define your own helper functions

bool isEmpty(TreeNode* root);
void clean_tree(TreeNode* root);




// A helper function to build a tree, you do not need to modify it
// Inputs:
//    nodeValues, a list of all node values from top to bottom, left to right. If no node at one place, use -1 as the placeholder
//    root, a pointer to the root node
//    i, set it to 0 when calling this function from outside
//    n, size of the 'nodeValues' array
// Postcondition: a tree is built with the second input argument as its root pointer
TreeNode* insertNodes(int nodeValues[], TreeNode* root, int i, int n);

int main(){
   // the binary trees in instruction examples
   TreeNode *root, *root2;
   int nodedatas[] = {1,2,3,4,5,6,7,8,1,-1,-1,-1,-1,-1,1};
   int nodedatas2[] = {1,2,3,4,5,6,7,8,1,-1,-1,-1,-1,1,-1};
   root = insertNodes(nodedatas, root, 0, 15);
   root2 = insertNodes(nodedatas2, root2, 0, 15);

   cout << height(root) << endl;

   assert(size(root) == 10);
   assert(size(root->left) == 5);
   assert(count(root,1) == 3);
   assert(count(root,9) == 0);
   assert(height(root) == 3);
   assert(height(root->left->right) == 0);
   assert(hasPathSum(root,10) == true);
   assert(hasPathSum(root,1) == false);
   assert(isBalanced(root) == true);
   assert(isSameTree(root,root2) == false);
   assert(isSameTree(root->left,root2->left) == true);

   cout << "Congratulation!" << endl;

   clean_tree(root);
   clean_tree(root2);

   return 0;
}

// A helper function to build the test cases. You do not need to modify it.
TreeNode* insertNodes(int nodeValues[], TreeNode* root, int i, int n){
   if(i<n && nodeValues[i]!=-1){
      root = new TreeNode;
      root->data = nodeValues[i];
      root->left = insertNodes(nodeValues, root->left, 2*i+1, n);
      root->right = insertNodes(nodeValues, root->right, 2*i+2, n);
   }
   else{
      root = NULL;
   }
   return root;
}

// function: isEmpty()
// function that returns whether or not a give branch is empty
// intput: a single binary tree variable
// output: boolean value
bool isEmpty(TreeNode* root) {
   return (root->left == NULL && root->right == NULL);
}

int size(TreeNode* root){
   int num(0);  // variable for the number of branches in a given tree

   // stopping case - reach end of branches, i.e. given root is empty
   if (isEmpty(root)) {
      return 1;
   }
   // otherwise, check the following branches
   else {
      if (root->left != NULL) {
         num += size(root->left);
      }
      if (root->right != NULL) {
         num += size(root->right);
      }
   }

   // iterate count and return
   return ++num;
}


int count(TreeNode* root, int target){
   int num(0);  // variable for number of 'target' values within the given tree

   // if the current branch equals the target value, iterate 'num'
   if (root->data == target) {
      ++num;
   }

   // if the following left branch is not empty, check
   if (root->left != NULL) {
      num += count(root->left, target);
   }
   // if the following right branch is not empty, check
   if (root->right != NULL) {
      num += count(root->right, target);
   }

   // return final 'num' value
   return num;
}


int height(TreeNode* root){
   int num(0);  // variable for number of branch nodes

   // stopping case - reach the end of the leafs of the initially given root
   if (isEmpty(root)) {
      return 1;
   }

   if (height(root->left) > height(root->right)) {
      num += height(root->left);
      return ++num;
   }
   else {
      num += height(root->right);
      return ++num;
   }
}

// function: isSameTree()
// Function that checks whether or not two given binary trees are equal
// intput: two 'TreeNode' varaibles - 'root1', 'root2'
// output: boolean value
bool isSameTree(TreeNode* root1, TreeNode* root2){
   // stopping case - one/both of the given roots are empty
   // must check both of the given roots
   if (isEmpty(root1)) {
      if (isEmpty(root2)) {
         return (root1->data == root2->data);
      }
      else {
         return false;
      }
   }
   else if (isEmpty(root2)) {
      return false;
   }

   // for the case where the branches are not empty
   // check if their data values are equal
   if (root1->data == root2->data) {
      // if so, check if left side is equal
      if (!isSameTree(root1->left, root2->left)) {
         return false;
      }
      // check if right side is equal
      else if (!isSameTree(root1->right, root2->right)) {
         return false;
      }
      // if all are equal, return true
      else {
         return true;
      }
   }
   // otherwise, return false
   else {
      return false;
   }
}


bool hasPathSum(TreeNode* root, int target){
   /* your code here */
}


bool isBalanced(TreeNode* root){
   /* your code here */
}

// function: clean_tree()
// Function that deallocates the memory for a given initialized binary tree
// intput: initialized binary tree variable
// output: nothing
void clean_tree(TreeNode* root) {
   TreeNode* current = root;  // variable for the current root location

   // stopping case - if the next branches are empty, deallocate current
   if (current->left == NULL && current->right == NULL) {
      delete current;
   }
   else {
      // check left branch and deallocate
      if (current->left != NULL) {
         clean_tree(current->left);
      }
      // check right branch and deallocate
      if (current->right != NULL) {
         clean_tree(current->right);
      }

      // deallocate memory from current location
      delete current;
   }

   // return nothing
   return;
}
