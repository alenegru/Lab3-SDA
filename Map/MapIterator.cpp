#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d) {
    current = -1;
}


void MapIterator::first() {
    current = 0;
}


void MapIterator::next() {
    if (valid())
        current++;
    else
        throw exception{};
}


TElem MapIterator::getCurrent() {
    if (valid())
        return this->map.elems[this->current];
    else
        throw exception{};
}


bool MapIterator::valid() const {
    if (current > 0 && current <= map.size())
        return true;
    return false;
}
