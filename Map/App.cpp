#include "ExtendedTest.h"
#include "ShortTest.h"

#include "Map.h"
#include <assert.h>

#include <iostream>
using namespace std;


int main() {
	testAll();
	testAllExtended();
//    Map m;
//    for (int i = -100; i <= 100; i = i + 2) {
//        m.add(i, i);
//    }
//    for (int i = 0; i <= 100; i++){
//        cout << "First:" << m.elems[i].first << "Second: " << m.elems[i].second << '\n';
//    }
//    for (int i = 100; i > -100; i--) {
//        cout <<"First: " << m.elems[i].first << "Second: " << m.elems[i].second;
//        if (i % 2 == 0) {
//            assert(m.remove(i) == i);
//
//        } else {
//            assert(m.remove(i) == NULL_TVALUE);
//
//        }
//    }
	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


