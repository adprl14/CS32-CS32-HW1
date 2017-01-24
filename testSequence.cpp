
//  testSequence.cpp
//  CS32_HW1
//
//  Created by Andrew Perley on 1/23/17.
//  Copyright © 2017 Andrew Perley. All rights reserved.
//


#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Sequence s;
    unsigned long value=0;
    assert(s.empty());
    assert(s.size()==0);
    assert(s.remove(0)==0);
    assert(!s.erase(0));
    assert(!s.get(0, value));
    assert(!s.set(0, value));
    assert(s.find(0)==-1);
    
    s.insert(0, 1);
    assert(s.size()==1);
    assert(s.get(0, value));
    assert(value == 1);
    assert(s.set(0, 0));
    assert(s.find(0)==0);
    assert(s.remove(0)==1);
    assert(s.empty());
    
    Sequence s2;
    for(int i = 0; i<200; i++){
        s2.insert(0);
    }
    assert(s2.insert(0, 1) == false);
    assert(s2.insert(1) == -1);
    assert(!s2.set(-1, 1));
    assert(!s2.get(-1, value));
    assert(s2.remove(0)==200);
    assert(s2.empty());
    
    Sequence s_a;
    s_a.insert(0, 1);
    s_a.insert(0, 2);
    Sequence s_b;
    s_b.insert(0, 5);
    s_a.swap(s_b);
    assert(s_a.size() == 1  &&  s_a.find(5) == 0  &&  s_b.size() == 2  &&
           s_b.find(1) == 1  &&  s_b.find(2) == 0);

    
    
   
    cout << "Passed all the tests" << endl;
}


