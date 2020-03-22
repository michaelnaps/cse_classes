// File: bin_tree.cpp
// Created by: Michael Napoli
// Created on: 3/11/2020
// Last modified on: 3/18/2020

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

int main() {
   // the binary trees in instruction examples
   TreeNode *root, *root2;
   int nodedatas[] = {1,2,3,4,5,6,7,8,1,-1,-1,-1,-1,1,-1};
   int nodedatas2[] = {1,2,3,4,5,-1,7,8,1,-1,-1,-1,-1,1,-1};
   root = insertNodes(nodedatas, root, 0, 15);
   root2 = insertNodes(nodedatas2, root2, 0, 15);

   assert(size(root) == 10);
   assert(size(root->left) == 5);
   assert(count(root, 1) == 3);
   assert(count(root, 9) == 0);
   assert(height(root) == 3);
   assert(height(root->left->right) == 0);
   // assert(hasPathSum(root,10) == true);
   // assert(hasPathSum(root,1) == false);
   assert(isBalanced(root) == true);
   assert(isBalanced(root2) == false);
   assert(isSameTree(root, root2) == false);
   assert(isSameTree(root->left, root2->left) == true);

   cout << "Congratulation!" << endl;

   clean_tree(root);
   clean_tree(root2);

   return 0;
}

// A helper function to build the test cases. You do not need to modify it.
TreeNode* insertNodes(int nodeValues[], TreeNode* root, int i, int n) {
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

// function: size()
// Function that returns the total number of nodes within a given binary tree.
// input: initialized 'TreeNode' pointer variable
// output: node count - integer
int size(TreeNode* root) {
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

// function: count()
// Function that counts the number of nodes that contain a given target value.
// input: 'root' - initialized 'TreeNode' pointer variable
//    'target' - target value to be found within the binary tree
// output: number of 'target' values within tree
int count(TreeNode* root, int target) {
   int num(0);  // variable for number of 'target' values within 'root'

   // if the current branch contains the target value, iterate 'num'
   if (root->data == target) {
      ++num;
   }

   // if the following left and right branches are not empty, check
   if (root->left != NULL) {
      num += count(root->left, target);
   }
   if (root->right != NULL) {
      num += count(root->right, target);
   }

   // return final 'num' value
   return num;
}

// function: height()
// function that counts and returns the maximum height of a given binary tree.
// This height is the number of nodes between the 'root' and the leafs
// intput: 'root' - initialized 'TreeNode' variable
// output: maximum height of the tree (integer)
int height(TreeNode* root) {
   int left_num(0), right_num(0);  // variables for count of left and right side

   // stopping case 1 - given root is NULL
   if (root == NULL) {
      return -1;
   }

   // stopping case 2 - given root variable is a leaf
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
bool isSameTree(TreeNode* root1, TreeNode* root2) {
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

// not completed for full credit
bool hasPathSum(TreeNode* root, int target) {
   return false;
}

// function: isBalanced()
// Function that compares two sides of a given root node to see if they
// are balanced. For a binary tree to be balanced, the height of the opposite sides of each
// node must differ by no more than 1.
// input: initialized binary tree pointer variable
// output: boolean value
bool isBalanced(TreeNode* root) {
   int left_height(0), right_height(0);  // variables for height of left an right branches

   // stopping case - node is empty
   if (root == NULL) {
      return true;  // empty nodes are always balanced (no branches on either side)
   }
   else {
      // get maximum heights for left and right branches
      left_height = height(root->left);
      right_height = height(root->right);

      // check if balanced (use absolute value)
      if (abs(left_height - right_height) <= 1) {
         // check next branches
         return (isBalanced(root->left) && isBalanced(root->right));
      }
      else {
         return false;
      }
   }
}

// function: clean_tree()
// Function that deallocates the memory for a given binary tree
// intput: initialized binary tree pointer variable
// output: nothing
void clean_tree(TreeNode* root) {

   // stopping case - current root is empty
   if (root != NULL) {
      // clean both sides of the remaining tree
      clean_tree(root->left);
      clean_tree(root->right);

      // deallocate memory from current root
      delete root;
   }

   // return nothing
   return;
}
