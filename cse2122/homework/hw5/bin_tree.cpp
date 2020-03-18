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

bool isLeaf(TreeNode* root);
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

   assert(size(root) == 10);
   assert(size(root->left) == 5);
   assert(count(root,1) == 3);
   assert(count(root,9) == 0);
   assert(height(root) == 3);
   assert(height(root->left->right) == 0);
   // assert(hasPathSum(root,10) == true);
   // assert(hasPathSum(root,1) == false);
   // assert(isBalanced(root) == true);
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

// function: isLeaf()
// function that returns whether or not a give branch is empty
// intput: a single binary tree variable
// output: boolean value
bool isLeaf(TreeNode* root) {
   return (root->left == NULL && root->right == NULL);
}

int size(TreeNode* root){
   int num(0);  // variable for the number of branches in a given tree

   // stopping case - reach end of branches, i.e. given root is empty
   if (isLeaf(root)) {
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
   int num(0);  // variable for number of 'target' values within 'root'

   // if the current branch contains the target value, iterate 'num'
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
   int left_num(0), right_num(0);  // variables for count of left and right side

   // stopping case - given root is empty
   if (isLeaf(root)) {
      return 0;
   }

   // check if left branch is empty
   if (root->left != NULL) {
      // if not, add its height to total count
      left_num += height(root->left);
   }

   // check if right branch is empty
   if (root->right != NULL) {
      // if not, add its height to total count
      right_num += height(root->right);
   }

   // iterate and return maximum height
   if (left_num > right_num) {
      return ++left_num;
   }
   else {
      return ++right_num;
   }
}

// function: isSameTree()
// Function that checks whether or not two given binary trees are equal
// intput: two 'TreeNode' varaibles - 'root1', 'root2'
// output: boolean value
bool isSameTree(TreeNode* root1, TreeNode* root2){
   // stopping case - reached leaf node of one/both of roots
   if (root1 == NULL && root2 == NULL) {
      return true;  // return true if trees end at same place
   }
   else if (root1 == NULL || root2 == NULL) {
      return false;  // one tree ends before the other
   }
   // otherwise, check if data values are equal
   else {
      // if root data values are equal
      if (root1->data == root2->data) {
         // check if next is equal and return
         return (isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right));
      }
      // otherwise, return false
      else {
         return false;
      }
   }
}


bool hasPathSum(TreeNode* root, int target){
   return false;
}


bool isBalanced(TreeNode* root){
   return false;
}

// function: clean_tree()
// Function that deallocates the memory for a given binary tree
// intput: initialized binary tree variable
// output: nothing
void clean_tree(TreeNode* root) {

   // stopping case - current root is not empty
   if (root != NULL) {
      clean_tree(root->left);
      clean_tree(root->right);
      delete root;
   }

   // return nothing
   return;
}
