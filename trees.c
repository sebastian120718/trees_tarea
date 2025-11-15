#include <stdio.h>
#include <stdlib.h>


struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

/* Crear un nuevo nodo */
struct Node* create_node(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Error: no hay memoria disponible.\n");
        exit(1);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Insertar un valor en el árbol */
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

/* Recorridos básicos */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

/* Liberar memoria */
void free_tree(struct Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}


int main() {
    struct Node* root = NULL;
    int value;

    printf("=== Árbol Binario de Búsqueda (BST) ===\n");
    printf("Ingrese valores para insertar en el árbol.\n");
    printf("Escriba -1 para terminar.\n\n");

    while (1) {
        printf("Ingrese un número: ");
        scanf("%d", &value);

        if (value == -1) {
            printf("Ingreso finalizado.\n");
            break;
        }

        root = insert(root, value);
    }

    printf("\n--- Recorridos del árbol ---\n");

    printf("Inorder (ascendente): ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    
    free_tree(root);

    return 0;
}
