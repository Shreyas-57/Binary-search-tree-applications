#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[15];
    struct contact *left;
    struct contact *right;
};

typedef struct contact NODE;

NODE* insert(NODE*, char[], char[]);
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);
NODE* delete_contact(NODE*, char[]);

NODE* insert(NODE* root, char name[], char phone[]) {
    NODE *newnode, *curr, *parent;

    newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return root;
    }

    strcpy(newnode->name, name);
    strcpy(newnode->phone, phone);
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        printf("Contact list initialized with first entry\n");
        return newnode;
    }

    curr = root;
    parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (strcmp(name, curr->name) < 0)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (strcmp(name, parent->name) < 0)
        parent->left = newnode;
    else
        parent->right = newnode;

    printf("Contact saved successfully\n");
    return root;
}

void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %-15s | Phone: %s\n", root->name, root->phone);
        inorder(root->right);
    }
}

void preorder(NODE* root) {
    if (root != NULL) {
        printf("%s ", root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->name);
    }
}

NODE* delete_contact(NODE* root, char name[]) {
    NODE *curr = root, *parent = NULL, *successor, *p;

    if (root == NULL) {
        printf("Contact list is empty\n");
        return root;
    }

    while (curr != NULL && strcmp(name, curr->name) != 0) {
        parent = curr;
        if (strcmp(name, curr->name) < 0)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL) {
        printf("Contact not found\n");
        return root;
    }

    if (curr->left == NULL)
        p = curr->right;
    else if (curr->right == NULL)
        p = curr->left;
    else {
        successor = curr->right;
        while (successor->left != NULL)
            successor = successor->left;

        successor->left = curr->left;
        p = curr->right;
    }

    if (parent == NULL) {
        free(curr);
        return p;
    }

    if (curr == parent->left)
        parent->left = p;
    else
        parent->right = p;

    free(curr);
    printf("Contact deleted\n");
    return root;
}

int main() {
    NODE *root = NULL;
    int choice;
    char name[50], phone[15];

    while (1) {
        printf("\n--- CONTACTS MENU ---\n");
        printf("1. Add Contact\n");
        printf("2. View All (A-Z)\n");
        printf("3. Structure (Preorder)\n");
        printf("4. Structure (Postorder)\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone: ");
                scanf("%s", phone);
                root = insert(root, name, phone);
                break;

            case 2:
                printf("\n--- All Contacts ---\n");
                inorder(root);
                break;

            case 3:
                preorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter Name to delete: ");
                scanf("%s", name);
                root = delete_contact(root, name);
                break;

            case 6:
                exit(0);
        }
    }
    return 0;
}
