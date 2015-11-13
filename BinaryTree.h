#ifndef _H__BINARYTREE
#define _H__BINARYTREE

#include "BinaryTree_Node.h"
#include <tuple>

class BinaryTree {
   private:
      std::tuple<int,int> findAndOptionallyRemove(int key, bool remove);
      void removeNode(BinaryTree_Node*);

   public:
      BinaryTree_Node* rootNode;

      BinaryTree();
      ~BinaryTree();
      BinaryTree(const BinaryTree& other) : rootNode(other.rootNode) {}

      void insert(int key, int value);
      std::tuple<int,int> find(int key);
      std::tuple<int,int> remove(int key);



};

#endif
