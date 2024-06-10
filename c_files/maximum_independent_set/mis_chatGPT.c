#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Δομή δεδομένων για έναν κόμβο του δέντρου
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Συνάρτηση για να δημιουργήσουμε έναν νέο κόμβο
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Συνάρτηση για τον υπολογισμό του μέγιστου ανεξάρτητου συνόλου αν περιλαμβάνεται ο κόμβος v
int MIS_incl(Node* root, int* memo_incl, int* memo_excl);

// Συνάρτηση για τον υπολογισμό του μέγιστου ανεξάρτητου συνόλου αν δεν περιλαμβάνεται ο κόμβος v
int MIS_excl(Node* root, int* memo_incl, int* memo_excl);

// Συνάρτηση για τον υπολογισμό του μέγιστου ανεξάρτητου συνόλου
int MIS(Node* root, int* memo_incl, int* memo_excl) {
    if (root == NULL)
        return 0;

    // Αν έχει ήδη υπολογιστεί το αποτέλεσμα, επιστρέφουμε
    if (memo_incl[root->data] != -1 && memo_excl[root->data] != -1)
        return memo_incl[root->data] > memo_excl[root->data] ? memo_incl[root->data] : memo_excl[root->data];

    int incl = MIS_incl(root, memo_incl, memo_excl);
    int excl = MIS_excl(root, memo_incl, memo_excl);

    memo_incl[root->data] = incl;
    memo_excl[root->data] = excl;

    return incl > excl ? incl : excl;
}

// Συνάρτηση για τον υπολογισμό του μέγιστου ανεξάρτητου συνόλου αν περιλαμβάνεται ο κόμβος v
int MIS_incl(Node* root, int* memo_incl, int* memo_excl) {
    if (root == NULL)
        return 0;

    // Αν έχει ήδη υπολογιστεί το αποτέλεσμα, επιστρέφουμε
    if (memo_incl[root->data] != -1)
        return memo_incl[root->data];

    int incl = 1; // Περιλαμβάνουμε τον τρέχοντα κόμβο
    if (root->left != NULL)
        incl += MIS_excl(root->left, memo_incl, memo_excl);
    if (root->right != NULL)
        incl += MIS_excl(root->right, memo_incl, memo_excl);

    memo_incl[root->data] = incl;
    return incl;
}

// Συνάρτηση για τον υπολογισμό του μέγιστου ανεξάρτητου συνόλου αν δεν περιλαμβάνεται ο κόμβος v
int MIS_excl(Node* root, int* memo_incl, int* memo_excl) {
    if (root == NULL)
        return 0;

    // Αν έχει ήδη υπολογιστεί το αποτέλεσμα, επιστρέφουμε
    if (memo_excl[root->data] != -1)
        return memo_excl[root->data];

    int excl = 0; // Δεν περιλαμβάνουμε τον τρέχοντα κόμβο
    if (root->left != NULL)
        excl += MIS(root->left, memo_incl, memo_excl);
    if (root->right != NULL)
        excl += MIS(root->right, memo_incl, memo_excl);

    memo_excl[root->data] = excl;
    return excl;
}

// Συνάρτηση για την εκκίνηση της διαδικασίας του MIS
int getMaxIndependentSet(Node* root) {
    if (root == NULL)
        return 0;

    // Δημιουργία και αρχικοποίηση των πινάκων μνήμης
    int n = 1000; // Ας υποθέσουμε ότι τα δεδομένα των κόμβων είναι < 1000 για απλότητα
    int* memo_incl = (int*)malloc(n * sizeof(int));
    int* memo_excl = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        memo_incl[i] = -1;
        memo_excl[i] = -1;
    }

    int result = MIS(root, memo_incl, memo_excl);

    // Καθαρισμός μνήμης
    free(memo_incl);
    free(memo_excl);

    return result;
}

int main() {
    // Δημιουργία του δέντρου
    Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->right = newNode(60);
    root->right->left = newNode(70);
    root->right->left->left = newNode(80);
    root->right->left->left->left = newNode(90);
    root->right->left->left->right = newNode(100);

    int maxIS = getMaxIndependentSet(root);
    printf("Το μέγιστο ανεξάρτητο σύνολο έχει μέγεθος: %d\n", maxIS);

    return 0;
}
