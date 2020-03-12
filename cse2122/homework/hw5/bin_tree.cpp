// File: bin_tree.cpp
// Created by: Michael Napoli
// Created on: 3/11/2020
// Last modified on:

/*
   Purpose:
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
/* your code here */




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
   assert(hasPathSum(root,10) == true);
   assert(hasPathSum(root,1) == false);
   assert(isBalanced(root) == true);
   assert(isSameTree(root,root2) == false);
   assert(isSameTree(root->left,root2->left) == true);

   cout << "Congratulation!" << endl;
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

int size(TreeNode* root){
   int num(0);  // variable for the number of branches in a given tree

   // stopping case - both of the following leafs are empty
   if (root->left == NULL && root->right == NULL) {
      return 1;
   }
   // otherwise check the following branches
   else {
      if (root->left != NULL) {
         num += size(root->left);
      }
      if (root->right != NULL) {
         num += size(root->right);
      }
   }

   // return the number of branches in tree
   return num;
}


int count(TreeNode* root, int target){
   int num(0);  // variable for number of 'target' values within the given tree

   // if the current branch equals the target value, iterate 'num'
   if (root->data == target) {
      num = num + 1;
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
   /* your code here */
}


bool isSameTree(TreeNode* root1, TreeNode* root2){
   // stopping case - both the follwing branches are empty
   return (root1->left == NULL && root1->right == NULL && root2->left == NULL && root2->right == NULL);

   // if the trees are not empty, continue checking their branches
   return (isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right));
}


bool hasPathSum(TreeNode* root, int target){
   /* your code here */
}


bool isBalanced(TreeNode* root){
   /* your code here */
}
