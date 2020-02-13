#include <cstdlib>
#include <climits>

#include "SLList.hpp"
#include "math.h"

using namespace std;

SLList * const SLList::NIL = new SLList(0, NULL);

SLList::SLList(int i, SLList * n) {
    head = i;
    tail = n;
}

int SLList::first() {
    return head;
}

SLList *SLList::rest() {
  return tail;
}

void SLList::setFirst(int i) {
    head = i;
}

void SLList::setRest(SLList *n) {
    tail = n;
}

int SLList::nth(unsigned int i) {
    if (i == 0) {
        return head;
    } else if (tail == NIL) {
        return 0-1;
    } else {
        return tail -> nth(i-1);
    }
}

SLList *SLList::nthRest(unsigned int i) {
    if (i == 0) {
        return this;
    } else {
        return tail -> nthRest(i-1);
    }
}

unsigned int SLList::length() {
    if (this == NIL) {
        return 0;
    } else {
        return 1 + rest() -> length();
    }
}

SLList *SLList::remove(int i) {
    if (rest() == NULL) {
        return NIL;
    } else if (i == head) {
        return rest() -> remove(i);
    } else {
        return new SLList(first(), rest() -> remove(i));
    }
}

SLList *SLList::reverse() {
  return NULL;
}

SLList * SLList::sublist(int start, int end) {
    if (start == end) {
        return NIL;
    } else {
        return new SLList(nth(start), sublist(start + 1, end));
    }
}

SLList * SLList::merge(SLList * b) {
    if (this == NIL) {
        return b;
    } else if (b == NIL) {
        return this;
    } else if (first() <= b -> first()) {
        return new SLList(first(), rest() -> merge(b));
    } else {
        return new SLList(b -> first(), b -> rest() -> merge(this));
    }
}

SLList * SLList::mergesort() {
    int kL = length();
    if (kL <= 1) {
        return this;
    } else {
        int middle = floorf(kL/2);
        SLList * left = sublist(0, middle) -> mergesort();
        SLList * right = sublist(middle, kL) -> mergesort();
        return left -> merge(right);
    }
}
