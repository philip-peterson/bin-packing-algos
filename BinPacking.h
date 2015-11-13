#ifndef _H__BINPACKING
#define _H__BINPACKING

#include <queue>

class BinPacking {
   public:
      BinPacking() {}
      ~BinPacking() {}
      BinPacking(const BinPacking& other) = delete;
      void firstFit (int bucketSize, std::queue<int> sizes) const;
      void bestFit  (int bucketSize, std::queue<int> sizes) const;
};

#endif
