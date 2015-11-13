#include "BinaryTree.h"
#include <tuple>
#include <iostream>
#include <assert.h>
using namespace std;

BinaryTree::BinaryTree() {
   rootNode = nullptr;
}

BinaryTree::~BinaryTree() {
   while (rootNode != nullptr) {
      removeNode(rootNode);
   }
}

void BinaryTree::insert(int key, int value) {
   if (rootNode == nullptr) {
      rootNode = new BinaryTree_Node(key, value, nullptr);
      return;
   }

   BinaryTree_Node* cur = rootNode;
   BinaryTree_Node* parCur = nullptr;

   bool wasRight = true;

   while (cur != nullptr) {
      parCur = cur;
      if ( key <= cur->key ) {
         cur = cur->leftChild;
         wasRight = false;
      }
      else {
         cur = cur->rightChild;
         wasRight = true;
      }
   }

   BinaryTree_Node* newNode = new BinaryTree_Node(key, value, parCur);

   if (wasRight) {
      parCur->rightChild = newNode;
   }
   else {
      parCur->leftChild = newNode;
   }

}

std::tuple<int,int> BinaryTree::find(int key) {
   return findAndOptionallyRemove(key, false);
}

std::tuple<int,int> BinaryTree::remove(int key) {
   return findAndOptionallyRemove(key, true);
}

std::tuple<int,int> BinaryTree::findAndOptionallyRemove(int key, bool remove) {
   if (rootNode == nullptr) {
      return std::tuple<int,int>(-1, -1);
   }

   BinaryTree_Node* cur = rootNode;
   BinaryTree_Node* parCur = nullptr;

   // Keep a record of the node and parent
   // of the node with the smallest value
   int min_key = 0;
   bool min_key_initialized = false;
   BinaryTree_Node* min_cur = nullptr;
   BinaryTree_Node* min_parCur = nullptr;

   while (cur != nullptr) {
      ///
      if(cur->key >= key) {
         if (!min_key_initialized) {
            min_key = cur->key;
            min_key_initialized=true;
         }
         if (cur->key <= min_key) {
            if (cur->key < min_key) {
               min_cur = nullptr;
            }
            min_key = cur->key;
            if (min_cur == nullptr) {
               min_cur = cur;
               min_parCur = parCur;
            }
            else if (cur->value < min_cur->value) {
               min_cur = cur;
               min_parCur = parCur;
            }
         }
      }
      ///
      parCur = cur;
      if (key <= cur->key) {
         cur = cur->leftChild;
      }
      else  {
         cur = cur->rightChild;
      }
   }

   std::tuple<int,int> valToReturnIfNoErrors (-1, -1);

   cur = min_cur;
   parCur = min_parCur;

   if (cur != nullptr) {
      valToReturnIfNoErrors = std::tuple<int,int>( cur->key, cur->value );

      // only do the removal if we found a bucket...
      if (remove) {
         removeNode(cur);
      }
   }

   return valToReturnIfNoErrors;
}

void BinaryTree::removeNode(BinaryTree_Node* nodeToDelete) {
   int nc = nodeToDelete->numChildren();

   int relationToParent;
   BinaryTree_Node* parent = nodeToDelete->parent;
   if (parent == nullptr) {
      relationToParent = 0;
   }
   else {
      if (parent->leftChild == nodeToDelete) {
         relationToParent = -1;
      }
      else {
         assert(parent->rightChild == nodeToDelete);
         relationToParent = 1;
      }
   }

   if (nc == 0) {
      if (relationToParent == -1) {
         parent->leftChild = nullptr;
      }
      else if (relationToParent == 1) {
         parent->rightChild = nullptr;
      }
      else {
         rootNode = nullptr;
      }
   }

   if (nc == 1) {
      BinaryTree_Node* theChild = (nodeToDelete->rightChild != nullptr) ? nodeToDelete->rightChild : nodeToDelete->leftChild;

      theChild->parent = parent;

      if (relationToParent == -1) {
         parent->leftChild = theChild;
      }
      else if (relationToParent == 1) {
         parent->rightChild = theChild;
      }
      else {
         rootNode = theChild;
      }
   }

   if (nc == 2) {
      BinaryTree_Node* ios = nodeToDelete->getIos();
      nodeToDelete->key = ios->key;
      nodeToDelete->value = ios->value;
      removeNode(ios);
   }

   if (nc <= 1) {
      nodeToDelete->parent = nodeToDelete->leftChild = nodeToDelete->rightChild = nullptr;
   }

}
