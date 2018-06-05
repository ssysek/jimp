//
// Created by syskmaci on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H
#include <cstddef>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>

namespace tree {

    template<class T>
    class Tree {
    public:
        T value;

        std::unique_ptr <Tree<T>> left;
        std::unique_ptr <Tree<T>> right;
        int size;
        int depth;

        Tree();

        Tree(T value);

        ~Tree() {};

        auto Root() {
            return this;
        }

        T Value() {
            return value;
        }

        int Size() {
            return size;
        }

        int Depth();

        //bool operator<(const Tree &other) const;

        void Insert(T value);

        bool Find(T value);
    };

    template<class T>
    Tree<T>::Tree() {
        depth = 0;
        size = 0;
        left = nullptr;
        right = nullptr;
    }

    template<class T>
    Tree<T>::Tree(T value) {
        depth = 1;
        size = 1;
        this->value = value;
        left = nullptr;
        right = nullptr;

    }

    template<class T>
    void Tree<T>::Insert(T val) {
        if (val < value) {
            if (left != nullptr) left->Insert(val);
            else {
                std::unique_ptr <Tree<T>> new_node = std::make_unique<Tree<T>>(val);
//                new_node->value = val;
//                new_node->left = nullptr;
//                new_node->right = nullptr;
//                this->left = std::move(new_node);
            }
        } else {
            if (right != nullptr) right->Insert(val);
            else {
                std::unique_ptr <Tree<T>> new_node = std::make_unique<Tree<T>>(val);
//                new_node->value = val;
//                new_node->left = nullptr;
//                new_node->right = nullptr;
//                this->right = std::move(new_node);
            }
        }
        size++;
    }
    template<class T>
    bool Tree<T>::Find(T val) {
        if(val==value){
            return true;
        }
        else if(val<value){
            if (left == nullptr){
                return false;
            }
            else{
                return left->Find(val);
            }
        }
        else{
            if (right == nullptr){
                return false;
            }
            else{
                return right->Find(val);
            }
        }
    }

    template<class T>
    int Tree<T>::Depth() {
        if (this) {
            return 1 + std::max(this->left->Depth(), this->right->Depth());
        } else {
            return 0;
        }
    }

}

#endif //JIMP_EXERCISES_TREE_H
