//
// Created by Sysek on 2018-06-04.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>

namespace tree {

    template <class T>
    class TreeIterator {
    public:
        TreeIterator(){};
        TreeIterator(Tree<T> * root_);
        Tree<T> *root;

        virtual void BuildVector(Tree<T> *node)=0;
        const void PushBack(const T new_value){
            iterated.emplace_back(new_value);
        }

        void operator++();
        T operator*();
        bool operator!=(const TreeIterator &other)const;


        int iter;
        std::vector<T> iterated;

    };

    template <class T>
    TreeIterator<T>::TreeIterator(Tree<T> *root_) {
        root = root_;
        iter = 0;
    }

    template <class T>
    void TreeIterator<T>::operator++() {
        iter++;
    }

    template <class T>
    T TreeIterator<T>::operator*() {
        return iterated[iter];
    }

    template <class T>
    bool TreeIterator<T>::operator!=(const TreeIterator &other) const {
        return this->iter != other.iter;
    }


    template <class T>
    class InOrderTreeIterator : public TreeIterator<T> {
    public:
        InOrderTreeIterator(){};
        InOrderTreeIterator(Tree<T> * ptr);
        void BuildVector(Tree<T> *node);
    };

    template <class T>
    InOrderTreeIterator<T>::InOrderTreeIterator(Tree<T> *ptr) : TreeIterator<T>(ptr){
        BuildVector(ptr);
    }

    template <class T>
    void InOrderTreeIterator<T>::BuildVector(Tree<T> *node) {
        if (node->left) BuildVector(node->left.get());
        this->PushBack(node->value);
        if (node->right) BuildVector(node->right.get());
    }


    template <class T>
    class InOrderTreeView {
    public:
        InOrderTreeView(){};
        InOrderTreeView(Tree<T> * root);
        InOrderTreeIterator<T> begin();
        InOrderTreeIterator<T> end();
        InOrderTreeIterator<T> tree_iterator;
    };

    template <class T>
    InOrderTreeView<T>::InOrderTreeView(Tree<T> *root) : tree_iterator(root)  {
    }

    template <class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::begin() {
        tree_iterator.iter = 0;
        return tree_iterator;
    }

    template <class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::end() {
        tree_iterator.iter = int(tree_iterator.iterated.size());
        return tree_iterator;
    }

    template <class T>
    InOrderTreeView<T> InOrder(Tree<T> *root){
        return InOrderTreeView<T>(root);
    }


    //same as above...

    template <class T>
    class PostOrderTreeIterator : public TreeIterator<T> {
    public:
        PostOrderTreeIterator(){};
        PostOrderTreeIterator(Tree<T> * ptr);
        void BuildVector(Tree<T> *node);
    };

    template <class T>
    PostOrderTreeIterator<T>::PostOrderTreeIterator(Tree<T> *ptr) : TreeIterator<T>(ptr){
        BuildVector(ptr);
    }

    template <class T>
    void PostOrderTreeIterator<T>::BuildVector(Tree<T> *node) {
        if (node->left) BuildVector(node->left.get());
        if (node->right) BuildVector(node->right.get());
        this->PushBack(node->value);
    }


    template <class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView(){};
        PostOrderTreeView(Tree<T> * root);
        PostOrderTreeIterator<T> begin();
        PostOrderTreeIterator<T> end();
        PostOrderTreeIterator<T> tree_iterator;
    };

    template <class T>
    PostOrderTreeView<T>::PostOrderTreeView(Tree<T> *root) : tree_iterator(root)  {
    }

    template <class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::begin() {
        tree_iterator.iter = 0;
        return tree_iterator;
    }

    template <class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::end() {
        tree_iterator.iter = int(tree_iterator.iterated.size());
        return tree_iterator;
    }

    template <class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *root){
        return PostOrderTreeView<T>(root);
    }


}

#endif //JIMP_EXERCISES_TREEITERATORS_H


#endif //JIMP_EXERCISES_TREEITERATORS_H
