#include "Map.h"
#include "MapIterator.h"
#include <iostream>
using namespace std;

Map::Map() {
    capacity = 5;
    elems = new TElem[capacity];
    next = new int[capacity];
    head = -1;
    //next[0] = -1;
    firstEmpty = 0;
}

Map::~Map() {
    delete[] elems;
    delete[] next;
}

TValue Map::add(TKey c, TValue v) {
    TElem elem(c, v);
    int option = 1;

    if (head != -1) {
        //verificare daca exista sau nu deja
        int current = head;
        while (current != -1) {
            if (elems[current].first == c) {
                option = 2;
                int old_value = elems[current].second;
                elems[current].second = v;
                return old_value;
            }
            current = next[current];
        }
    }
    
    if (option == 1) {
        //adaugare
        if (firstEmpty < nr_elems) {
            elems[firstEmpty] = elem;

            int position = 0;
            while (next[position] != -1)
                position++;

            next[firstEmpty] = -1;
            next[position] = firstEmpty;
        }
        else if (nr_elems == 0) {
            head = 0;
            elems[firstEmpty] = elem;
            next[firstEmpty] = -1;
            nr_elems++;
            firstEmpty = nr_elems;
        } else {
            elems[nr_elems] = elem;
            next[firstEmpty] = -1;
            next[firstEmpty - 1] = nr_elems;
            nr_elems++;
            firstEmpty = nr_elems;
        }
        counter++;
    }
    //resize
    if (nr_elems == capacity) {
        capacity = capacity * 2;

        TElem* temp = new TElem[capacity];
        int* temp2 = new int[capacity];

        for (int p = 0; p < nr_elems; p++) {
            temp[p] = elems[p];
            temp2[p] = next[p];
        }

        delete[] elems;
        delete[] next;

        elems = temp;
        next = temp2;
    }
    
    return NULL_TVALUE;
}

TValue Map::search(TKey c) const{
    int current = head;
    
    while (current != -1 && elems[current].first != c) {
        current = next[current];
    }
    if (current != -1)
        return elems[current].second;
	return NULL_TVALUE;
}

TValue Map::remove(TKey c){
    int current = head;
    int prev = -1;

    while (current != -1 && elems[current].first != c) {
        prev = current;
        current = next[current];
    }
    if (current != -1) {
        int value = elems[current].second;
        if (current == head) {
            head = next[head];
        } else {
            elems[current].first = 0;
            elems[current].second = 0;
            next[prev] = next[current];
        }
        //next[current] = firstEmpty;
        firstEmpty = current;
        counter--;
        
        cout << "START\n";
        for (int i = 0; i < capacity; i++) {
            cout << elems[i].first << " " << elems[i].second << " NEXT: " << next[i] << '\n';
        }
        
        cout << "FE: " << firstEmpty << '\n';
        cout << "END\n\n";
        
        return value;
    }
    return NULL_TVALUE;
}

int Map::size() const {
//    int current = head;
//    int counter = 0;
//    while (current != -1) {
//        current = next[current];
//        counter++;
//    }
    return counter;
}

bool Map::isEmpty() const {
    if (head == -1) {
        return true;
    }
	return false;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}

Map Map::give_new_map(Map map, int a, int b) {
    Map new_map;
    for (int i = 0; i < map.size(); i++) {
        if (a <= map.elems[i].first <= b) {
            new_map.add(map.elems[i].first, map.elems[i].second);
        }
    }
    return new_map;
}
