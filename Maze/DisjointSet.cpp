// Name: Andrei Modiga
// Assignment number: 5
// Assignment: Maze
// Date last modified: November 3, 2021
// Honor statement: I have neither given nor received any unauthorized help on this assignment. 


#include "DisjointSet.h"
#include <vector>


// Construct size sets, each in its own equivalent class
DisjointSet::DisjointSet(int size) : number_of_sets(size), set(size) {
    for (int i = 0; i < size; i++)
        Make_Set(i);
}

// Find the equivalence class of n.
// Uses path compression to reduce the search path
// of all the elements on the path from n to its
// representative element.
int DisjointSet::Find(int i) {
    if (set[i] != i)
        set[i] = Find(set[i]);
    return set[i];
}

// Merge the two equivalence classes s1 and s2.
// No optimization performed during the union.
int DisjointSet::Union(int s1, int s2) {
    int p1 = Find(s1),
        p2 = Find(s2);
    set[p1] = p2;
    number_of_sets--;
    return 1;
}

// Number of equivalence classes (sets)
int DisjointSet::Cardinality() const {
    // Replace with your code
    return number_of_sets;
}

// Makes a set in its own equivalence class
void DisjointSet::Make_Set(int i) {
    // Add your code
    set[i] = i;
}

// Unmerge all elements into separate sets.
// Each element will be a singleton in its 
// own equivalence class.
void DisjointSet::Split() {
    // Add your code
    for (int i = 0; i < (int)set.size(); i++)
        set[i] = i;
    number_of_sets = (int)set.size();
}
