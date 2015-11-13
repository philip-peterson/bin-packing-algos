#include "BinPacking.h"
#include <queue>

#include <iostream>
using namespace std;

int main(int argc, char** argv) {

   while (true) {

                char c;
                cout << "Please choose the algorithm for test: 1. Firstfit; 2. Bestfit; 3. Quit?";
                cout << flush;
                cin >> c;

                if (c != '1' && c != '2') {
                   return 0;
                }
                
                std::queue<int> elemSizes;
                int numElems;
                int binCapacity;

                cout << "Enter number of objects and bin capacity for " << (c == '1' ? "First" : "Best") << " Fit" << endl;
                cout << endl;
                cout << "Enter number of objects and bin capacity" << endl;

                cin >> numElems;
                cin >> binCapacity;
                cout << endl;

                for (int i = 1; i <= numElems; i++) {
                   cout << "Enter space requirement of object " << i << endl;
                   int theSize;
                   cin >> theSize;
                   elemSizes.push(theSize);
                }

                cout << endl;
                cout << endl;

      BinPacking bp;

      if ( c == '2' ) {
         bp.bestFit(binCapacity, elemSizes);
      }
      else {

       bp.firstFit(binCapacity, elemSizes);
      }
   }
   return 0;
}
