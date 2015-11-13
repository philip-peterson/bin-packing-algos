#include "BinaryTree_Node.h"
#include <iostream>

BinaryTree_Node::~BinaryTree_Node() {
   if ( leftChild != nullptr || rightChild != nullptr || parent != nullptr ) {
      std::cerr << "Cannot delete BST node because it has non-null pointers." << std::endl;
   }
}

int BinaryTree_Node::numChildren() {
   if (leftChild == nullptr && rightChild == nullptr) {
      return 0;
   }
   if (leftChild != nullptr && rightChild != nullptr) {
      return 2;
   }
   return 1;
}

// Returns in-order successor
BinaryTree_Node* BinaryTree_Node::getIos() {
   if (rightChild == nullptr) {
      return nullptr;
   }
   BinaryTree_Node* cur = rightChild;
   while (cur->leftChild != nullptr) {
      cur = cur->leftChild;
   }
   return cur;
}
