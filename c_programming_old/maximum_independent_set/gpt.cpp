#include <iostream>
#include <vector>
#include <memory>

// Define the structure for tree node
class Node {
public:
    int data;
    int liss_size;
    Node* left;
    Node* right;
    std::vector<int> liss_nodes; // Vector to store LISS nodes

    Node(int data) : data(data), liss_size(0), left(nullptr), right(nullptr) {}
};

// Function to find the Largest Independent Set (LIS)
int LISS(Node* root) {
    if (!root)
        return 0;

    if (root->liss_size != 0)
        return root->liss_size;

    if (!root->left && !root->right) {
        root->liss_size = 1;
        root->liss_nodes.push_back(root->data);
        return root->liss_size;
    }

    // Calculate size excluding the current node
    int liss_excl = LISS(root->left) + LISS(root->right);

    // Calculate size including the current node
    int liss_incl = 1;
    std::vector<int> liss_incl_nodes = {root->data};
    if (root->left) {
        liss_incl += LISS(root->left->left) + LISS(root->left->right);
        liss_incl_nodes.insert(liss_incl_nodes.end(), root->left->liss_nodes.begin(), root->left->liss_nodes.end());
    }
    if (root->right) {
        liss_incl += LISS(root->right->left) + LISS(root->right->right);
        liss_incl_nodes.insert(liss_incl_nodes.end(), root->right->liss_nodes.begin(), root->right->liss_nodes.end());
    }

    // Select the maximum of two sizes and store the nodes for future use
    if (liss_incl > liss_excl) {
        root->liss_size = liss_incl;
        root->liss_nodes = liss_incl_nodes;
    } else {
        root->liss_size = liss_excl;
        if (root->left) {
            root->liss_nodes = root->left->liss_nodes;
        }
        if (root->right) {
            root->liss_nodes.insert(root->liss_nodes.end(), root->right->liss_nodes.begin(), root->right->liss_nodes.end());
        }
    }

    return root->liss_size;
}

// Utility function to print the LIS nodes
void printLISSNodes(const std::vector<int>& nodes) {
    for (int node : nodes) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Let's construct the binary tree shown in the example
    auto root = std::make_shared<Node>(10);
    root->left = std::make_shared<Node>(20);
    root->right = std::make_shared<Node>(30);
    root->left->left = std::make_shared<Node>(40);
    root->left->right = std::make_shared<Node>(50);
    root->right->right = std::make_shared<Node>(60);
    root->left->right->left = std::make_shared<Node>(70);
    root->left->right->right = std::make_shared<Node>(80);

    std::cout << "Size of the Largest Independent Set is " << LISS(root) << std::endl;
    std::cout << "Nodes in the Largest Independent Set are: ";
    printLISSNodes(root->liss_nodes);

    return 0;
}


