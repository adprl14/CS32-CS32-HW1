//
//  Sequence.cpp
//  CS32_HW1
//
//  Created by Andrew Perley on 1/22/17.
//  Copyright © 2017 Andrew Perley. All rights reserved.
//

#include "Sequence.h"


Sequence::Sequence(){
    seq_size = 0;
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
    if(seq_size<DEFAULT_MAX_ITEMS){
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
    ItemType other_temp;
    ItemType m_Temp;
    int other_size = other.size();
    int m_size = seq_size;
    int max_size;
   
    if (seq_size >= other.size())
    {
        max_size=seq_size;
    }
    else
        max_size=other.size();
    
    for (int i = 0; i<max_size; i++){
        other_temp=other.seq_items[i];
        m_Temp=seq_items[i];
        other.seq_items[i]=m_Temp;
        seq_items[i]=other_temp;
    }
    
    seq_size=other_size;
    other.seq_size = m_size;
}









