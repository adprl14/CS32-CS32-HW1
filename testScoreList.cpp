//
//  testScoreList.cpp
//  CS32_HW1
//
//  Created by Andrew Perley on 1/22/17.
//  Copyright © 2017 Andrew Perley. All rights reserved.


#include "ScoreList.h"
#include "Sequence.h"
#include <limits>
#include <iostream>
#include <cassert>
using namespace std;

void test_Score(){
    ScoreList scores;
    //testing constructor
    assert(scores.size()==0);
    assert(scores.minimum()==NO_SCORE);
    assert(scores.maximum()==NO_SCORE);
    
    //testing add
    assert(scores.add(1)==true);
    assert(scores.size()==1);
    assert(scores.minimum()==1);
    assert(scores.maximum()==1);
    
    
    assert(scores.add(-1) == false);
    assert(scores.size()==1);
    assert(scores.add(101) == false);
    assert(scores.size()==1);
    
    assert(scores.add(0)==true);
    assert(scores.size()==2);
    assert(scores.minimum()==0);
    assert(scores.maximum()==1);
    
    assert(scores.add(100)==true);
    assert(scores.size()==3);
    assert(scores.minimum()==0);
    assert(scores.maximum()==100);
    
    
    assert(scores.add(100)==true);
    assert(scores.size()==4);
    assert(scores.minimum()==0);
    assert(scores.maximum()==100);
    
    //testing remove
    assert(!scores.remove(-1));
    assert(!scores.remove(101));
    assert(scores.size()==4);
    
    assert(scores.remove(100));
    assert(scores.size()==3);
    assert(scores.minimum()==0);
    assert(scores.maximum()==100);
    
    assert(scores.remove(0));
    assert(scores.size()==2);
    assert(scores.minimum()==1);
    assert(scores.maximum()==100);
    
    assert(scores.remove(1));
    assert(scores.size()==1);
    assert(scores.minimum()==100);
    assert(scores.maximum()==100);
    
    assert(!scores.remove(1));
    
    
    cout<<"all tests passed"<<endl;
}

//int main(){
//    test_Score();
//}
//
//
//
