#include<iostream>
#include"BST.hpp"

//BST Implementation

// Check if the tree is empty

bool BST::empty() const {
    return root == nullptr;
}

// Insert a value into the BST

void BST::insert(const Employee& value) {
    insertAux(root, value);
}

void BST::insertAux(NodePtr& subtree, const Employee& employee) {
    if (subtree!=nullptr) {
        subtree = new Node(employee);
    }else if(subtree -> key == employee.age){
      subtree -> Employees.push_back(employee);
    }
    else if (employee.age < subtree->key) {
        insertAux(subtree->left, employee);
    } else if (employee.age > subtree->key) {
        insertAux(subtree->right, employee);
    }
}

// Search for a employee in the BST
bool BST::search(const Employee& employee) const {
    return searchAux(root, employee);
}

bool BST::searchAux(NodePtr subtree, const Employee& value) const {
    if (subtree== nullptr) {
        return false;
    }
    if (value.age == subtree->key) {
        return true;
    } else if (value.age < subtree->key) {
        return searchAux(subtree->left, value);
    } else {
        return searchAux(subtree->right, value);
    }
}

// Erase an employee from the BST
void BST::erase(const Employee& value) {
    root = eraseAux(root, value);
}

typename BST::NodePtr BST::eraseAux(NodePtr subtree, const Employee& employee) {
    if (!subtree) {
        return nullptr; // Tree is empty or node not found
    }
    int key = employee.age;
    if (key < subtree->key) {
        subtree->left = eraseAux(subtree->left, employee);
    } else if (key > subtree->key) {
        subtree->right = eraseAux(subtree->right,employee);
    } else {
        // Key matches: Remove the specific employee from the vector
        auto& employees = subtree->Employees;
        Employee emp;
        emp = employees.find(employee);

        if (it != employees.end()) {
            employees.erase(it); // Remove the employee
        }

        // If the Employees vector is empty, delete the node
        if (employees.empty()) {
            if (!subtree->left) {
                Node* temp = subtree->right;
                delete subtree;
                return temp;
            } else if (!subtree->right) {
                Node* temp = subtree->left;
                delete subtree;
                return temp;
            }

            // Node with two children: Find the inorder successor
            Node* temp = findMin(subtree->right);
            subtree->key = temp->key;
            subtree->Employees = temp->Employees;
            subtree->right = eraseAux(subtree->right, temp->key, Employee{}); // Remove the successor
            delete temp;
        }
    }

    return subtree;
}


typename BST::NodePtr BST::findMin(NodePtr subtree) const {
    while (subtree && subtree->left) {
        subtree = subtree->left;
    }
    return subtree;
}

typename BST::NodePtr BST::findMax(NodePtr subtree) const {
    while (subtree && subtree->left) {
        subtree = subtree->right;
    }
    return subtree;
}

// Inorder traversal
void BST::inorder(std::ostream& out) const {
    inorderAux(out, root);
}

void BST::inorderAux(std::ostream& out, NodePtr subtree) const {
    if (subtree) {
        inorderAux(out, subtree->left);
        out << subtree->key;

        inorderAux(out, subtree->right);
    }
}

// Preorder traversal
void BST::preorder(std::ostream& out) const {
    preorderAux(out, root);
}

void BST::preorderAux(std::ostream& out, NodePtr subtree) const {
    if (subtree) {
        out << subtree->key << " ";
        preorderAux(out, subtree->left);
        preorderAux(out, subtree->right);
    }
}

// Postorder traversal
void BST::postorder(std::ostream& out) const {
    postorderAux(out, root);
}

void BST::postorderAux(std::ostream& out, NodePtr subtree) const {
    if (subtree) {
        postorderAux(out, subtree->left);
        postorderAux(out, subtree->right);
        out << subtree->key << " ";
    }
}

// Get the minimum age in the BST
BST:: NodePtr BST::minValue() const {
    NodePtr temp = findMin(root);
    if (!temp) {
        throw std::runtime_error("Tree is empty");
    }
    return temp->data;
}

// Get the maximum age in the BST
BST:: NodePtr BST::maxValue() const {
    NodePtr temp = root;
    while (temp && temp->right) {
        temp = temp->right;
    }
    if (!temp) {
        throw std::runtime_error("Tree is empty");
    }
    return temp->data;
}
void BST::print(std::ostream& out) const {
  printAux(out, root);
}
void BST::printAux(std::ostream& out, NodePtr subtree) const {
  if (subtree) {
    printAux(out, subtree->left);
    out << subtree->key << " ";
    printAux(out, subtree->right);

  }
}




void BST:: insertEmployee(string name, int id, int age, float performanceScore,double salary) {
    this-> insert( Employee(name,id,age,performanceScore,salary));
}
void BST::deleteEmployee(int age) {
  NodePtr temp = search();
}
void BST :: displayEmployees() {

}

void BST :: operator<<(std::ostream& out) const {
  out << "Employees: \n";

}


