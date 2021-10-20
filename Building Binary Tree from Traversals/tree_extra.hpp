//  Name: Andrei Modiga
//  Assignment number: 3
//  Assignment: Binary space partitioning trees
//  Date last modified: October 19, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

//  tree_extra.hpp

// Draws the binary tree rooted at t.  
// Parameter link is a symbol to print in front of the node to
// which t points indicating the direction of the branch leading 
// to the node.
// Parameter depth is proportional to depth of the node to which p
// points.
#include <iostream>
// #include "tree.hpp"


template <typename T>
static void draw(TreeNode<T> *t, char link, int depth) {
    if (t != nullptr) {
        //Print right tree
        draw(t->right, '/', depth + 1);
        //node
        for (int i = 0; i < depth; i++)
            std::cout << "   ";

        std::cout << link << '[' << t->data << ']' << '\n';
        //Print left tree
        draw(t->left, '\\', depth + 1);
    }
    // std::cout << "TODO: Implement draw function\n";
}


// Frees up the space held by the nodes in a binary tree 
// rooted at t.
template <typename T>
void dispose(TreeNode<T> *t) {
    if (t == nullptr) {
        return;
    }
    //Delete right
    dispose(t->right);
    //Delete left
    dispose(t->left);
    //Delete node
    delete(t);
    //Set t
    t = nullptr;
}


// Builds a binary tree from preorder and inorder traversals.
// Parameter pre_begin is an iterator to the beginning of the
// preorder traveral sequence.
// Parameter pre_end is an iterator to the end of the preorder 
// traveral sequence.
// Parameter in_begin is an iterator to the beginning of the
// inorder traveral sequence.
// Parameter in_end is an iterator to the end of the inorder
// traveral sequence.
// Returns a pointer to the root of the newly created binary tree.
    template <typename T>
static TreeNode<T>* build_tree(typename std::vector<T>::const_iterator pre_begin,
        typename std::vector<T>::const_iterator pre_end,
        typename std::vector<T>::const_iterator in_begin,
        typename std::vector<T>::const_iterator in_end) {

        typename std::vector<T>::const_iterator pre_index_iter = pre_begin + (find(in_begin, in_end, *pre_begin) - in_begin);
        typename std::vector<T>::const_iterator in_index_iter = find(in_begin, in_end, *pre_begin);
        
        std::vector<T> left_pre(next(pre_begin), next(pre_index_iter));
        std::vector<T> right_pre(next(pre_index_iter), pre_end);
        std::vector<T> left_in(in_begin, in_index_iter);
        std::vector<T> right_in(next(in_index_iter), in_end);
        // Check if at end to return nullprt, if not builds subtree
        TreeNode<T>* root = new TreeNode(*pre_begin,
            (begin(left_pre) == end(left_pre)) ? nullptr : (build_tree<T>(begin(left_pre), end(left_pre), begin(left_in), end(left_in))),
           (begin(right_pre) == end(right_pre)) ? nullptr : (build_tree<T>(begin(right_pre), end(right_pre), begin(right_in), end(right_in))));

        return root;
}

