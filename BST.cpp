#include<iostream>
#include"BST.hpp"

//BST Implementation

// Check if the tree is empty
template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

// Insert a value into the BST
template <typename T>
void BST<T>::insert(const T& value) {
    insertAux(root, value);
}

template <typename T>
void BST<T>::insertAux(NodePtr& subtree, const T& value) {
    if (!subtree) {
        subtree = new Node(value);
    } else if (value < subtree->data) {
        insertAux(subtree->left, value);
    } else if (value > subtree->data) {
        insertAux(subtree->right, value);
    }
}

// Search for a value in the BST
template <typename T>
bool BST<T>::search(const T& value) const {
    return searchAux(root, value);
}

template <typename T>
bool BST<T>::searchAux(NodePtr subtree, const T& value) const {
    if (!subtree) {
        return false;
    }
    if (value == subtree->data) {
        return true;
    } else if (value < subtree->data) {
        return searchAux(subtree->left, value);
    } else {
        return searchAux(subtree->right, value);
    }
}

// Erase a value from the BST
template <typename T>
void BST<T>::erase(const T& value) {
    root = eraseAux(root, value);
}

template <typename T>
typename BST<T>::NodePtr BST<T>::eraseAux(NodePtr subtree, const T& value) {
    if (!subtree) {
        return nullptr;
    }

    if (value < subtree->data) {
        subtree->left = eraseAux(subtree->left, value);
    } else if (value > subtree->data) {
        subtree->right = eraseAux(subtree->right, value);
    } else {
        // Node with only one child or no child
        if (!subtree->left) {
            NodePtr temp = subtree->right;
            delete subtree;
            return temp;
        } else if (!subtree->right) {
            NodePtr temp = subtree->left;
            delete subtree;
            return temp;
        }

        // Node with two children: Get the inorder successor
        NodePtr temp = findMin(subtree->right);
        subtree->data = temp->data;
        subtree->right = eraseAux(subtree->right, temp->data);
    }
    return subtree;
}

template <typename T>
typename BST<T>::NodePtr BST<T>::findMin(NodePtr subtree) const {
    while (subtree && subtree->left) {
        subtree = subtree->left;
    }
    return subtree;
}
template <typename T>
typename BST<T>::NodePtr BST<T>::findMax(NodePtr subtree) const {
    while (subtree && subtree->left) {
        subtree = subtree->right;
    }
    return subtree;
}

// Inorder traversal
template <typename T>
void BST<T>::inorder(std::ostream& out) const {
    inorderAux(out, root);
}

template <typename T>
void BST<T>::inorderAux(std::ostream& out, NodePtr subtree) const {
    if (subtree) {
        inorderAux(out, subtree->left);
        out << "Age: " << subtree->data.age
            << ", Name: " << subtree->data.name
            << ", Income: " << subtree->data.income
            << ", Performance: " << subtree->data.performanceScore << "\n";
        inorderAux(out, subtree->right);
    }
}

// Preorder traversal
template <typename T>
void BST<T>::preorder(std::ostream& out) const {
    preorderAux(out, root);
}

template <typename T>
void BST<T>::preorderAux(std::ostream& out, NodePtr subtree) const {
    if (subtree) {
        out << subtree->data << " ";
        preorderAux(out, subtree->left);
        preorderAux(out, subtree->right);
    }
}

// Postorder traversal
template <typename T>
void BST<T>::postorder(std::ostream& out) const {
    postorderAux(out, root);
}

template <typename T>
void BST<T>::postorderAux(std::ostream& out, NodePtr subtree) const {
    if (subtree) {
        postorderAux(out, subtree->left);
        postorderAux(out, subtree->right);
        out << subtree->data << " ";
    }
}

// Get the minimum value in the BST
template <typename T>
T BST<T>::minValue() const {
    NodePtr temp = findMin(root);
    if (!temp) {
        throw std::runtime_error("Tree is empty");
    }
    return temp->data;
}

// Get the maximum value in the BST
template <typename T>
T BST<T>::maxValue() const {
    NodePtr temp = root;
    while (temp && temp->right) {
        temp = temp->right;
    }
    if (!temp) {
        throw std::runtime_error("Tree is empty");
    }
    return temp->data;
}
template <typename T>
void BST<T>::print(std::ostream& out) const {
  printAux(out, root);
}
