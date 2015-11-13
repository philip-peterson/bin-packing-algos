#ifndef _H__BINARYTREE_NODE
#define _H__BINARYTREE_NODE

class BinaryTree_Node {
   public:

      int key;
      int value;
      BinaryTree_Node* parent;
      BinaryTree_Node* leftChild;
      BinaryTree_Node* rightChild;
      BinaryTree_Node* getIos();

      ~BinaryTree_Node();

      BinaryTree_Node(int key, int value, BinaryTree_Node* parent)
         : key(key),
           value(value),
           parent(parent),
           leftChild(nullptr),
           rightChild(nullptr)
           {
           }

      BinaryTree_Node(const BinaryTree_Node& other) = delete;

      int numChildren();
};

#endif
