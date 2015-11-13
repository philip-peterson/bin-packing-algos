#ifndef _H__WINNERTREE
#define _H__WINNERTREE

#include "MaxWinnerTree_Node.h"
#include <tuple>

class MaxWinnerTree {
   private:
      int bucketSize;
      int numLeaves;

   public:
      MaxWinnerTree_Node* rootNode;

      MaxWinnerTree(int bucketSize);
      ~MaxWinnerTree();
      MaxWinnerTree(const MaxWinnerTree& other) = delete;

      void doubleInSize();
      MaxWinnerTree_Node* find(int key);

      void preorder();
      void preorder_helper(MaxWinnerTree_Node* node);
};

#endif
