#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left, *right;
};

typedef struct tree node;

/* Insertion */
node *insert(node *p, int n)
{
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->data = n;
        p->left = NULL;
        p->right = NULL;
    }
    else if (n < p->data)
        p->left = insert(p->left, n);
    else
        p->right = insert(p->right, n);

    return p;
}

/* Deletion */
node *del(node *p, int n)
{
    node *temp, *ptr;

    if (p == NULL)
        return NULL;

    if (p->data == n)
    {
        if (p->left == NULL && p->right == NULL)
        {
            free(p);
            p = NULL;
        }
        else if (p->right == NULL)
        {
            temp = p->left;
            free(p);
            p = temp;
        }
        else if (p->left == NULL)
        {
            temp = p->right;
            free(p);
            p = temp;
        }
        else
        {
            temp = p->left;
            ptr = p->right;

            free(p);
            p = ptr;

            while (ptr->left != NULL)
                ptr = ptr->left;

            ptr->left = temp;
        }
    }
    else if (n < p->data)
        p->left = del(p->left, n);
    else
        p->right = del(p->right, n);

    return p;
}

/* Inorder Traversal */
void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

/* Preorder Traversal */
void preorder(node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

/* Postorder Traversal */
void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

/* Main Function */
int main()
{
    node *root = NULL;
    int ch, n;

    while (1)
    {
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Inorder");
        printf("\n4. Preorder");
        printf("\n5. Postorder");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &n);
                root = insert(root, n);
                break;

            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &n);
                root = del(root, n);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}
