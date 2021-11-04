//  Name: Andrei Modiga
//  Assignment number: 1 
//  Assignment: Vectors
//  File name: vectorsutil.cpp
//  Date last modified: September 6, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

#ifndef VECTORUTILS_H_INCLUDED_
#define VECTORUTILS_H_INCLUDED_

#include "vectorsutil.h"
#include <iostream>
#include <vector>

//------------------------------------------------
//  Returns the maximum value in vector v.
//  The result is undefined if v is empty.
int maximum(const std::vector<int>& v){

        int max = v[0];
        for(int i = 0; i < v.size(); i++)
        {
            if (v[i] > max) {
                max = v[i];
            }
        }
        return max;

}



//------------------------------------------------
//  Returns the position of the value seek
//  within vector v. 
//  Returns -1 (never a valid position in a
//  C++ vector) if seek is not an element of v.
int find(const std::vector<int>& v, int seek){

        for(int i = 0; i < v.size(); i++)
        {
            if (v[i] == seek){
                return i;
            }   
        }
    return -1;


}



//------------------------------------------------
//  Returns the number of times the value seek
//  appears within vector v. 
//  Returns 0 if seek is not an element of v
int count(const std::vector<int>& v, int seek){

    int timeSeek = 0; 
    for(int i = 0; i < v.size(); i++)
    {
        if (v[i] == seek) {
            timeSeek++;
        }
    }
    return timeSeek;
    
}



//------------------------------------------------
//  Returns true if vectors v1 and v2 contain 
//  exactly the same elements, regardless of their
//  order; otherwise, the function returns false. 
bool equivalent(const std::vector<int>& v1, const std::vector<int>& v2){

    for (int i = 0; i < v1.size(); i++) {
        if (find(v2, v1[i]) == -1) {
            return false;
        }

        if (count(v1, v1[i]) != count(v2, v1[i])) {
            return false;
        }
    }
    
    return true;

}

//------------------------------------------------
//  Physically rearranges the elements of v
//  so they appear in order from lowest value
//  to highest value.
void sort(std::vector<int>& v){

    int i, j, temp;
    int n = v.size() - 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}


//------------------------------------------------
//  Removes the first occurrence of element
//  del from vector v.  (The first occurrence
//  has the lowest index.)
//  The vector is unaffected if del is not a
//  element of v.
//  The function returns true if a element is
//  removed; otherwise, it returns false if
//  del does not appear in v.
bool remove_first(std::vector<int>& v, int del){

    
    int n = 0;
    for(int i = 0; i < v.size() - 1; i++) {

        if(v[i] == del){
           while (n + i < v.size()) {
                int temp = v[n + i];
                v[n + i] = v[n + i + 1];
                v[n + i + 1] = temp;
                n += 1;
           }

           v.pop_back();
           return true;    
        }
    }
    return false;

}

#endif 