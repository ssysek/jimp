//
// Created by syskmaci on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H


template <class T>
bool Tree<T>::operator<(const Tree &other) const {
    return this->value < other.value;
}



template<class T>
Tree<T>::Tree() {
    depth= 0;
    size = 0;
    left = nullptr;
    right = nullptr;
}

template<class T>
void Tree<T>::Insert(T val) {
    if (val < value) {
        if (left != nullptr) left->Insert(val);
        else {
            std::unique_ptr<Tree<T>> new_node = std::make_unique<Tree<T>>();
            new_node->value = val;
            new_node->left = nullptr;
            new_node->right = nullptr;
            this->left = std::move(new_node);
        }
    }
    else {
        if ( right != nullptr) right->Insert(val);
        else {
            std::unique_ptr<Tree<T>> new_node = std::make_unique<Tree<T>>();
            new_node->value = val;
            new_node->left = nullptr;
            new_node->right = nullptr;
            this->right = std::move(new_node);
        }
    }
    size++;
}


#endif //JIMP_EXERCISES_TREE_H
