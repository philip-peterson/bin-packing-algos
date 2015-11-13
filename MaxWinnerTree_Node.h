#ifndef _H__WINNERTREE_NODE
#define _H__WINNERTREE_NODE

class MaxWinnerTree_Node {
   public:

      int key;
      int value;
      MaxWinnerTree_Node* parent;
      MaxWinnerTree_Node* leftChild;
      MaxWinnerTree_Node* rightChild;

      ~MaxWinnerTree_Node();

      MaxWinnerTree_Node(int key, int value, MaxWinnerTree_Node* parent)
         : key(key),
           value(value),
           parent(parent),
           leftChild(nullptr),
           rightChild(nullptr)
           {
           }

      MaxWinnerTree_Node(int key, int value, MaxWinnerTree_Node* parent, MaxWinnerTree_Node* leftChild, MaxWinnerTree_Node* rightChild)
         : key(key),
           value(value),
           parent(parent),
           leftChild(leftChild),
           rightChild(rightChild)
           {
           }

      void replay();

      MaxWinnerTree_Node(const MaxWinnerTree_Node& other) = delete;

};

#endif
