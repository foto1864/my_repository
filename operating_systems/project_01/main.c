#include <stdio.h>
#include <stdlib.h>

// xrisimo gia na mi grafoume sinexeia char*
typedef char* string;

// kathe node tha periexei to onoma tou logariasmou san string kai enan pinaka me
// deiktes oi opoioi tha deixnoun se allous komvous
typedef struct Node {
    string account_name;
    struct Node** neighbours; // pinakas me deiktes stous allous komvous pou de jeroume posoi tha einai ejarxis
    int matrix_capacity; // deixnei posa stixia ehi o pinakas me tous deiktes
    int filled_nodes; // deixnei posa stixia ine katilimena
} Node;

Node* create_node(string name) {
    Node* new_node = malloc(sizeof(*new_node));
    new_node->account_name = name;

    // otan dimiourgeitai ena node desmevetai horos gia alla 2 geitonika, to 2 einai arbitrary mporoume meta na to afjisume
    new_node->neighbours = malloc(2*sizeof(Node*));
    for (int i = 0; i<2 ; i++) {
        new_node->neighbours[i] = malloc(sizeof(*new_node));
    }

    new_node->matrix_capacity = 2;  // capacity ine 2
    new_node->filled_nodes = 0;     // ine omos adia opote 0 filled

    return new_node;
}

void insert_node(Node* new_node, Node* old_node) {
    int capacity = old_node->matrix_capacity;
    int filled = old_node->filled_nodes;

    if (filled < capacity) {
        old_node->neighbours[filled] = new_node;
        old_node->filled_nodes++;
    }
    else if (filled == capacity) {
        printf("Sorry\n");
    }

    printf("Insertion Successful\n");
    return;
}

void print_node(Node* node) {
    printf("The name of the account is %s\n", node->account_name);
    printf("The nodes of this node that are filled are: %d\n", node->filled_nodes);
    return;
}

int main() {

    Node* fotinakis = create_node("Fotinakis 123");
    Node* kontopidis = create_node("Kontopidis 124");

    insert_node(kontopidis, fotinakis);
    print_node(fotinakis);
    print_node(kontopidis);

    return 0;
}