#include "BinPacking.h"
#include "BinaryTree.h"
#include "MaxWinnerTree.h"
#include <queue>
#include <iostream>
#include <assert.h>


using namespace std;

void BinPacking::firstFit(int bucketSize, std::queue<int> sizes) const {
   MaxWinnerTree wt (bucketSize);

   int whichObj = 1;
   while (!sizes.empty()) {
      int size = sizes.front();
      MaxWinnerTree_Node* e = wt.find(size);
      if (e == nullptr) {
         wt.doubleInSize();
      }
      else {
         cout << "Pack object " << whichObj << " in bin " << e->value << endl;
         e->key -= size;
         assert(e->key >= 0);
         e->replay();
         sizes.pop();
         whichObj++;
      }
   }
}
   
void BinPacking::bestFit(int bucketSize, std::queue<int> sizes) const {
   BinaryTree bt;

   int numBuckets = 1;
   bt.insert(bucketSize, numBuckets);
   
   int curObj = 1;

   while (sizes.size() > 0) {
      int sizeOfCur = sizes.front();

      std::tuple<int,int> kvpair = bt.remove(sizeOfCur);
      int k = std::get<0>(kvpair);
      int v = std::get<1>(kvpair);

      if (v == -1) {
         numBuckets += 1;
         bt.insert(bucketSize, numBuckets);
      }
      else {
         cout << "Pack object " << curObj << " in bin " << v << endl;
         sizes.pop();
         if (k-sizeOfCur > 0) {
            bt.insert(k-sizeOfCur, v);
         }
         curObj += 1;
      }
   }
   
}
