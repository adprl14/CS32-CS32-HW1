//
//  newSequence.cpp
//  CS32_HW1
//
//  Created by Andrew Perley on 1/23/17.
//  Copyright © 2017 Andrew Perley. All rights reserved.
//

#include "newSequence.h"
#include <iostream>

Sequence::Sequence(unsigned long n){
    
    
    seq_items = new ItemType[n];
    seq_size = 0;
    max_items = n;
}

Sequence::Sequence(Sequence const &old){
    max_items = old.max_items;
    seq_items = new ItemType[max_items];
    seq_size=old.seq_size;
    
    for (int i = 0; i<max_items; i++){
        seq_items[i] = old.seq_items[i];
    }
}


Sequence::~Sequence(){
    delete [] seq_items;
    seq_items = nullptr;
}

bool Sequence::empty() const{
    bool result = false;
    
    if (seq_size == 0)
        result = true;
    
    return result;
}

int Sequence::size() const{
    return seq_size;
}

bool Sequence::insert(int pos, const ItemType& value){
    bool result = false;
    if(seq_size<max_items){
        if (pos >= 0 && pos <= seq_size)
        {
            if (seq_size>0) {
                ItemType temp = seq_items[seq_size-1];
                for ( int i = seq_size-1; i> pos; i--)
                {
                    seq_items[i] =  seq_items[i-1];
                }
                seq_items[seq_size] = temp;
            }
            
            seq_items[pos] = value;
            seq_size++;
            result = true;
        }
    }
    return result;
}

int Sequence::insert(const ItemType &value){
    int p = 0;
    
    for (int i = 0; i < seq_size; i++){
        if (value <= seq_items[i]){
            
            bool result1 = insert(i, value);
            if (result1 == true){
                p=i;
                return p;
            }
            else
                return -1;
        }
    }
    
    p = seq_size;
    bool result2 = insert(p, value);
    if( result2 == true)
        return p;
    
    return -1;
}

bool Sequence::erase(int pos){
    if (pos>= 0 && pos<seq_size)
    {
        for(int i = pos; i<seq_size-1; i++)
        {
            seq_items[i] = seq_items[i+1];
        }
        seq_size--;
        return true;
    }
    
    return false;
}

int Sequence::remove(const ItemType& value){
    int num_removed = 0;
    
    for (int i = 0; i<seq_size;i++){
        if (seq_items[i]==value){
            erase(i);
            num_removed++;
            i--;
        }
    }
    return num_removed;
}

bool Sequence::get(int pos, ItemType& value) const{
    
    
    if ( pos>=0 && pos<seq_size){
        value = seq_items[pos];
        return true;
    }
    
    else
        return false;
}

bool Sequence::set(int pos, const ItemType& value){
    if ( pos>=0 && pos<seq_size){
        seq_items[pos] = value;
        return true;
    }
    
    return false;
}

int Sequence::find(const ItemType& value) const{
    int p = -1;
    
    for (int i = 0; i< seq_size; i++){
        if(value == seq_items[i]){
            p = i;
            return p;
        }
    }
    
    return p;
}

void Sequence::swap(Sequence& other){
    int other_size = other.size();
    unsigned long other_max = other.max_items;
    int m_size = seq_size;
    unsigned long m_max = max_items;
    ItemType* m_seq = seq_items;
    ItemType* other_seq = other.seq_items;
    
    seq_items = other_seq;
    other.seq_items=m_seq;
    
    seq_size=other_size;
    other.seq_size = m_size;
    max_items = other_max;
    other.max_items=m_max;
}









