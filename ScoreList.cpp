//
//  ScoreList.cpp
//  CS32_HW1
//
//  Created by Andrew Perley on 1/22/17.
//  Copyright © 2017 Andrew Perley. All rights reserved.
//

#include "Sequence.h"
#include "ScoreList.h"
#include <limits>

ScoreList::ScoreList(){
    
}


bool ScoreList::add(unsigned long score){
    if(score <= 100){
        score_seq.insert(score);
        return true;
    }
    return false;
}

bool ScoreList::remove(unsigned long score){
    int pos = 0;
    pos = score_seq.find(score);
    
    if(score_seq.find(score)!=-1){
        score_seq.erase(pos);
        return true;
    }
    else
        return false;
}

int ScoreList::size() const{
    return score_seq.size();
}

unsigned long ScoreList::minimum() const{
    unsigned long min_val = 0;
    
    if( score_seq.size() == 0)
        return NO_SCORE;
  
    else{
        score_seq.get(0, min_val);
        return min_val;
    }
}

unsigned long ScoreList::maximum() const{
    unsigned long max_val = 0;
    
    if( score_seq.size() == 0)
        return NO_SCORE;
    
    else{
        score_seq.get(score_seq.size()-1, max_val);
        return max_val;
    }
}



