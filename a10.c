#include <stdio.h>
#include <stdlib.h>

typedef struct bstree {
    int data;
    struct bstree *lchild, *rchild;
} node;

node *getnode() {
    node *p = (node *)malloc(sizeof(node));

    printf("\nEnter data: ");
    scanf("%d", &p->data);
    p->lchild = p->rchild = NULL;
    return p;
}

node *createbstree(node *root) {
    node *p, *curr;
    char ch;

    do {
        p = getnode();

        if(root == NULL)
            root = p;
        else {
            curr = root;

            while(1) {
                if(p->data < curr->data) {
                    if(curr->lchild == NULL) {
                        curr->lchild = p;
                        break;
                    }
                    curr = curr->lchild;
                }
                else if(p->data > curr->data) {
                    if(curr->rchild == NULL) {
                        curr->rchild = p;
                        break;
                    }
                    curr = curr->rchild;
                }
                else {
                    printf("\nDuplicate data!\n");
                    free(p);
                    break;
                }
            }
        }

        printf("\nAdd more nodes? (y/n): ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');

    return root;
}

void inorder(node *p) {
    if(p != NULL) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void preorder(node *p) {
    if(p != NULL) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(node *p) {
    if(p != NULL) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

node *search(node *p, int x) {
    if(p == NULL || p->data == x)
        return p;

    if(x < p->data)
        return search(p->lchild, x);

    return search(p->rchild, x);
}

int main() {
    node *root = NULL, *temp;
    int ch, x;

    printf("\nCreate the BST\n");
    root = createbstree(root);

    do {
        printf("\nMENU\n1.Inorder\n2.Preorder\n3.Postorder\n4.Search\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nInorder: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("\nPreorder: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nEnter data to search: ");
                scanf("%d", &x);
                temp = search(root, x);

                if(temp == NULL)
                    printf("\nNode not found!\n");
                else
                    printf("\nNode %d found!\n", temp->data);
                break;

			case 5:
				printf("Exiting...\n");
				break;
			
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(ch != 5);

    return 0;
}