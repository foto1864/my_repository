#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree node
struct node {
    int data;
    int liss_size;
    struct node *left, *right;
    int *liss_nodes; // Array to store LISS nodes
    int liss_nodes_count;
};

// Utility function to create a new tree node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->liss_size = 0;
    temp->liss_nodes = NULL;
    temp->liss_nodes_count = 0;
    return temp;
}

// Utility function to copy LISS nodes
void copyLISSNodes(int *dest, int *src, int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = src[i];
    }
}

// Utility function to append node to LISS nodes array
int* appendLISSNode(int *nodes, int count, int data) {
    int *new_nodes = (int*)malloc((count + 1) * sizeof(int));
    for (int i = 0; i < count; i++) {
        new_nodes[i] = nodes[i];
    }
    new_nodes[count] = data;
    free(nodes);
    return new_nodes;
}

// Function to find the Largest Independent Set (LIS)
int LISS(struct node *root) {
    if (root == NULL)
        return 0;

    if (root->liss_size != 0)
        return root->liss_size;

    if (root->left == NULL && root->right == NULL) {
        root->liss_size = 1;
        root->liss_nodes = appendLISSNode(NULL, 0, root->data);
        root->liss_nodes_count = 1;
        return root->liss_size;
    }

    // Calculate size excluding the current node
    int liss_excl = LISS(root->left) + LISS(root->right);

    // Calculate size including the current node
    int liss_incl = 1;
    int *liss_incl_nodes = appendLISSNode(NULL, 0, root->data);
    int liss_incl_count = 1;
    if (root->left) {
        liss_incl += LISS(root->left->left) + LISS(root->left->right);
        liss_incl_nodes = (int*)realloc(liss_incl_nodes, (liss_incl_count + root->left->liss_nodes_count) * sizeof(int));
        copyLISSNodes(liss_incl_nodes + liss_incl_count, root->left->liss_nodes, root->left->liss_nodes_count);
        liss_incl_count += root->left->liss_nodes_count;
    }
    if (root->right) {
        liss_incl += LISS(root->right->left) + LISS(root->right->right);
        liss_incl_nodes = (int*)realloc(liss_incl_nodes, (liss_incl_count + root->right->liss_nodes_count) * sizeof(int));
        copyLISSNodes(liss_incl_nodes + liss_incl_count, root->right->liss_nodes, root->right->liss_nodes_count);
        liss_incl_count += root->right->liss_nodes_count;
    }

    // Select the maximum of two sizes and store the nodes for future use
    if (liss_incl > liss_excl) {
        root->liss_size = liss_incl;
        root->liss_nodes = liss_incl_nodes;
        root->liss_nodes_count = liss_incl_count;
    } else {
        root->liss_size = liss_excl;
        root->liss_nodes = (int*)malloc((root->left ? root->left->liss_nodes_count : 0) + (root->right ? root->right->liss_nodes_count : 0) * sizeof(int));
        root->liss_nodes_count = 0;
        if (root->left) {
            copyLISSNodes(root->liss_nodes, root->left->liss_nodes, root->left->liss_nodes_count);
            root->liss_nodes_count += root->left->liss_nodes_count;
        }
        if (root->right) {
            copyLISSNodes(root->liss_nodes + root->liss_nodes_count, root->right->liss_nodes, root->right->liss_nodes_count);
            root->liss_nodes_count += root->right->liss_nodes_count;
        }
        free(liss_incl_nodes); // Free the included nodes list
    }

    return root->liss_size;
}

// Utility function to print the LIS nodes
void printLISSNodes(struct node* root) {
    if (root == NULL) return;
    for (int i = 0; i < root->liss_nodes_count; i++) {
        printf("%d ", root->liss_nodes[i]);
    }
    printf("\n");
}

int main() {
    // Let's construct the binary tree shown in the example
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    printf("Size of the Largest Independent Set is %d\n", LISS(root));
    printf("Nodes in the Largest Independent Set are: ");
    printLISSNodes(root);

    return 0;
}
