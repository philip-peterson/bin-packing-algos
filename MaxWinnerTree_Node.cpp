#include "MaxWinnerTree_Node.h"
#include <iostream>
#include <assert.h>
using namespace std;

MaxWinnerTree_Node::~MaxWinnerTree_Node() {
   if ( leftChild != nullptr ) {
      delete leftChild;
   }
   if ( rightChild != nullptr ) {
      delete rightChild;
   }
   if (parent != nullptr) {
      if (parent->leftChild == this) {
         parent->leftChild = nullptr;
      }
      else {
         parent->rightChild = nullptr;
      }
   }
}

void MaxWinnerTree_Node::replay() {
   if (parent == nullptr) {
      return;
   }

   if (parent->leftChild->key >= parent->rightChild->key) {
      parent->key = parent->leftChild->key;
      parent->value = parent->leftChild->value;
   }
   else {
      parent->key = parent->rightChild->key;
      parent->value = parent->rightChild->value;
   }

   parent->replay();
   
}
