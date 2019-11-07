#ifndef SLLIST_HPP
#define SLLIST_HPP

class SLList {
public:
  SLList(int, SLList *);
    SLList * sublist(int start, int end);
    SLList * merge(SLList * b);
    SLList * mergesort();
    
    int counting = 0;
    
  static SLList * const NIL;
    int head;
    SLList * tail;
    
    SLList *rest();
  int first();
  void setFirst(int);
  void setRest(SLList *);

  int nth(unsigned int);
  SLList *nthRest(unsigned int);

  unsigned int length();
  SLList *remove(int i);
  SLList *reverse();
};

#endif
