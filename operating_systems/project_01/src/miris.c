#include "general.h"
#include "display_menu.h"
#include "hash_map.h"

// Structure representing an edge (transaction)
typedef struct Edge {
    char* dest;  // Destination node (account)
    double amount;  // Transaction amount
    char* date;  // Date of the transaction
    struct Edge* next;  // Pointer to the next edge in the adjacency list
} Edge;

// Structure representing a node (user/account)
typedef struct Node {
    char* name;  // User ID (account)
    Edge* adjList;  // Adjacency list (list of outgoing transactions)
    struct Node* next;  // Pointer to the next node in the hash table
} Node;

// Hash table for storing nodes (for O(1) access)
Node* hashTable[HASH_SIZE];

// Function to create a new node (account)
Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = strdup(name);
    newNode->adjList = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new edge (transaction)
Edge* createEdge(char* dest, double amount, char* date) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = strdup(dest);
    newEdge->amount = amount;
    newEdge->date = strdup(date);
    newEdge->next = NULL;
    return newEdge;
}

// Function to insert a node (account) into the hash table
void insertNode(char* name) {
    unsigned int index = hash(name);
    Node* newNode = createNode(name);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Function to find a node in the hash table by name (ID)
Node* findNode(char* name) {
    unsigned int index = hash(name);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to insert an edge (transaction) between two nodes
void insertEdge(char* src, char* dest, double amount, char* date) {
    Node* srcNode = findNode(src);
    if (!srcNode) {
        insertNode(src);
        srcNode = findNode(src);
    }

    Node* destNode = findNode(dest);
    if (!destNode) {
        insertNode(dest);
        destNode = findNode(dest);
    }

    Edge* newEdge = createEdge(dest, amount, date);
    newEdge->next = srcNode->adjList;
    srcNode->adjList = newEdge;
}

// Function to delete an edge (transaction) between two nodes
void deleteEdge(char* src, char* dest) {
    Node* srcNode = findNode(src);
    if (!srcNode) {
        printf("Source node not found.\n");
        return;
    }

    Edge* prev = NULL;
    Edge* curr = srcNode->adjList;
    while (curr != NULL && strcmp(curr->dest, dest) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Edge not found.\n");
        return;
    }

    if (prev == NULL) {
        srcNode->adjList = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr->dest);
    free(curr->date);
    free(curr);
    printf("Edge deleted.\n");
}

// Function to delete a node (account) and all its outgoing edges
void deleteNode(char* name) {
    unsigned int index = hash(name);
    Node* prev = NULL;
    Node* curr = hashTable[index];
    
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (prev == NULL) {
        hashTable[index] = curr->next;
    } else {
        prev->next = curr->next;
    }

    // Free all edges (transactions)
    Edge* edge = curr->adjList;
    while (edge != NULL) {
        Edge* temp = edge;
        edge = edge->next;
        free(temp->dest);
        free(temp->date);
        free(temp);
    }

    free(curr->name);
    free(curr);
    printf("Node and all edges deleted.\n");
}

// Function to print all the outgoing transactions of a node
void findOutgoingTransactions(char* name) {
    Node* node = findNode(name);
    if (!node) {
        printf("Node not found.\n");
        return;
    }

    Edge* edge = node->adjList;
    printf("Outgoing transactions for %s:\n", name);
    while (edge != NULL) {
        printf("To: %s, Amount: %.2f, Date: %s\n", edge->dest, edge->amount, edge->date);
        edge = edge->next;
    }
}

// Function to print all the incoming transactions to a node
void findIncomingTransactions(char* name) {
    printf("Incoming transactions for %s:\n", name);
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* node = hashTable[i];
        while (node != NULL) {
            Edge* edge = node->adjList;
            while (edge != NULL) {
                if (strcmp(edge->dest, name) == 0) {
                    printf("From: %s, Amount: %.2f, Date: %s\n", node->name, edge->amount, edge->date);
                }
                edge = edge->next;
            }
            node = node->next;
        }
    }
}

// Function to free all memory used by the graph
void freeGraph() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* node = hashTable[i];
        while (node != NULL) {
            Node* tempNode = node;
            node = node->next;

            // Free all edges
            Edge* edge = tempNode->adjList;
            while (edge != NULL) {
                Edge* tempEdge = edge;
                edge = edge->next;
                free(tempEdge->dest);
                free(tempEdge->date);
                free(tempEdge);
            }

            free(tempNode->name);
            free(tempNode);
        }
    }
}

// Main function with a menu-driven interface
int main() {
    int choice;
    char src[100], dest[100], date[20];
    double amount;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", src);
                insertNode(src);
                printf("Node %s inserted.\n", src);
                break;
            case 2:
                printf("Enter source node: ");
                scanf("%s", src);
                printf("Enter destination node: ");
                scanf("%s", dest);
                printf("Enter transaction amount: ");
                scanf("%lf", &amount);
                printf("Enter transaction date (YYYY-MM-DD): ");
                scanf("%s", date);
                insertEdge(src, dest, amount, date);
                printf("Edge from %s to %s inserted.\n", src, dest);
                break;
            case 3:
                printf("Enter node name to delete: ");
                scanf("%s", src);
                deleteNode(src);
                break;
            case 4:
                printf("Enter source node: ");
                scanf("%s", src);
                printf("Enter destination node: ");
                scanf("%s", dest);
                deleteEdge(src, dest);
                break;
            case 5:
                printf("Enter node name to view outgoing transactions: ");
                scanf("%s", src);
                findOutgoingTransactions(src);
                break;
            case 6:
                printf("Enter node name to view incoming transactions: ");
                scanf("%s", src);
                findIncomingTransactions(src);
                break;
            case 7:
                printf("Exiting...\n");
                freeGraph();
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}
