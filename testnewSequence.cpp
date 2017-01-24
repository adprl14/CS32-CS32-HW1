//
//  testnewSequence.cpp
//  CS32_HW1
//
//  Created by Andrew Perley on 1/23/17.
//  Copyright © 2017 Andrew Perley. All rights reserved.
//


#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test_newSeq1(){
    Sequence a(1000);   // a can hold at most 1000 items
    Sequence b(5);      // b can hold at most 5 items
    Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
    ItemType v = 5;
    
    // No failures inserting 5 items into b
    for (int k = 0; k < 5; k++){
        assert(b.insert(k, v));
    }
    
    // Failure if we try to insert a sixth item into b
    assert(!b.insert(5, v));
    
    // When two Sequences' contents are swapped, their capacities are
    // swapped as well:
    a.swap(b);
    assert(!a.insert(5, v));
    for (int k = 0; k < 1000; k++)
        assert(b.insert(k, v));
        
        cout<< "Yay!!! :D "<<endl;
}

void test_newSeq2(){
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
    
    
    cout << "Passed all tests... Yay!!!" << endl;
}


int main()
{
    
    test_newSeq1();
    test_newSeq2();


  
}

