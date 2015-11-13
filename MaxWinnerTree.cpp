#include "MaxWinnerTree.h"
#include <tuple>
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

MaxWinnerTree::~MaxWinnerTree() {
   delete rootNode;
   rootNode = nullptr;
}

MaxWinnerTree::MaxWinnerTree(int bucketSize) : bucketSize(bucketSize), numLeaves(2) {

   rootNode = new MaxWinnerTree_Node(-1,-1,nullptr,nullptr,nullptr);

   MaxWinnerTree_Node* lc = new MaxWinnerTree_Node(bucketSize, 1, rootNode, nullptr, nullptr);
   MaxWinnerTree_Node* rc = new MaxWinnerTree_Node(bucketSize, 2, rootNode, nullptr, nullptr);

   rootNode->leftChild = lc;
   rootNode->rightChild = rc;

   lc->replay();
}

void MaxWinnerTree::doubleInSize() {
   vector<MaxWinnerTree_Node*> newLeaves;
   for (int i=0; i < numLeaves; i++) {
      newLeaves.push_back(new MaxWinnerTree_Node(bucketSize, numLeaves+i+1, nullptr, nullptr, nullptr));
   }

   vector<MaxWinnerTree_Node*> prevLevel = newLeaves;
   vector<MaxWinnerTree_Node*> nextLevel;
   while(prevLevel.size() != 1) {
      for (int j = 0; j < prevLevel.size(); j += 2) {
         nextLevel.push_back(new MaxWinnerTree_Node(-1, -1, nullptr, prevLevel.at(j), prevLevel.at(j+1)));
         prevLevel.at(j)->parent = prevLevel.at(j+1)->parent = nextLevel.back();
      }
      prevLevel = nextLevel;
      nextLevel = vector<MaxWinnerTree_Node*>();
   }

   MaxWinnerTree_Node *newRoot = new MaxWinnerTree_Node(-1, -1, nullptr, rootNode, prevLevel.at(0));
   prevLevel.at(0)->parent = newRoot;
   rootNode->parent = newRoot;
   rootNode = newRoot;

   // Replay matches
   
   for (int k = 0; k < numLeaves; k += 2) {
      newLeaves.at(k)->replay();
   }

   numLeaves *= 2;
   
}


MaxWinnerTree_Node* MaxWinnerTree::find(int key) {
   MaxWinnerTree_Node *cur = rootNode;

   while (cur->leftChild != nullptr || cur->rightChild != nullptr) {
      assert(cur->leftChild != nullptr && cur->rightChild != nullptr);

      if (cur->leftChild->key >= key) {
         cur = cur->leftChild;
      }
      else if (cur->rightChild->key >= key) {
         cur = cur->rightChild;
      }
      else {
         return nullptr;
      }
   }

   return cur;
}

void MaxWinnerTree::preorder() {
   cout << "PREORDER:" << endl;
   preorder_helper(rootNode);
   cout << endl << endl;
}

void MaxWinnerTree::preorder_helper(MaxWinnerTree_Node* it) {
   if (it == nullptr) return;
   cout << it->key << ", " << it->value << endl;
   preorder_helper(it->leftChild);
   preorder_helper(it->rightChild);
}
