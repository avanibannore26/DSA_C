#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

void display(struct node *curr) {
    if(curr == NULL)
        printf("\nEMPTY LIST!");
	
    else {
		printf("\nSingly linked list contains: ");
		
        while(curr != NULL) {
            printf("%d\t", curr->num);
            curr = curr->next;
        }
    }
	
    printf("\n");
}

void disp_rev(struct node *curr) {
	if(curr != NULL) {
        disp_rev(curr->next);
        printf("%d\t", curr->num);
    }
}

int main() {
    struct node *head = NULL, *curr, *p, *prev, *next;
    int choice, pos, data, found;
    char ch;

    do {
        p = (struct node *)malloc(sizeof(struct node));

        if(p == NULL)
            return 1;

        printf("\nEnter data: ");
        scanf("%d", &p->num);
        p->next = NULL;

        if(head == NULL)
            head = p;
        
		else {
            curr = head;
            while(curr->next != NULL)
                curr = curr->next;

            curr->next = p;
        }

        printf("\nNew node? (y/n): ");
        scanf(" %c", &ch);

    } 
	
	while(ch == 'y' || ch == 'Y');

    do {
        printf("\nMENU\n1.Display\n2.Insert\n3.Delete\n4.Search\n5.Reverse display\n6.Revert SLL\n7.Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display(head);
                break;

            case 2:
                printf("\nInsert at: 1.Beginning  2.End  3.After a value \n");
				printf("\nEnter choice: ");
                scanf("%d", &pos);

                p = (struct node *)malloc(sizeof(struct node));
                if(p == NULL)
                    return 1;

                printf("\nEnter data: ");
                scanf("%d", &p->num);

                if(pos == 1) {
                    p->next = head;
                    head = p;
                }
				
                else if(pos == 2) {
                    p->next = NULL;

                    if(head == NULL)
                        head = p;
					
                    else {
                        curr = head;
                        while(curr->next != NULL)
                            curr = curr->next;

                        curr->next = p;
                    }
                }
				
                else if(pos == 3) {
                    printf("\nInsert after which value? ");
                    scanf("%d", &data);

                    curr = head;
                    while(curr != NULL && curr->num != data)
                        curr = curr->next;

                    if(curr == NULL) {
                        printf("\nData not found!");
                        free(p);
                        break;
                    }

                    p->next = curr->next;
                    curr->next = p;
                }
				
                else {
                    printf("\nInvalid choice!");
                    free(p);
                    break;
                }

                display(head);
				
                break;

            case 3:
                printf("\nDelete: 1.Beginning  2.End  3.By value \n");
				printf("\nEnter choice: ");
                scanf("%d", &pos);

                if(head == NULL) {
                    printf("\nEMPTY LIST!");
                    break;
                }

                if(pos == 1) {
                    p = head;
                    head = head->next;
                    free(p);
                }
				
                else if(pos == 2) {
                    if(head->next == NULL) {
                        free(head);
                        head = NULL;
                    }
					
                    else {
                        curr = head;
                        while(curr->next->next != NULL)
                            curr = curr->next;

                        p = curr->next;
                        curr->next = NULL;
                        free(p);
                    }
                }
				
                else if(pos == 3) {
                    printf("\nEnter data to delete: ");
                    scanf("%d", &data);

                    if(head->num == data) {
                        p = head;
                        head = head->next;
                        free(p);
                    }
					
					else {
                        curr = head;
                        while(curr->next != NULL &&
                              curr->next->num != data)
                            curr = curr->next;

                        if(curr->next == NULL) {
                            printf("\nData not found!");
                            break;
                        }

                        p = curr->next;
                        curr->next = p->next;
                        free(p);
                    }
                }
				
                else {
                    printf("\nInvalid choice!");
                    break;
                }

                display(head);
                break;

            case 4:
                printf("\nEnter data to search: ");
                scanf("%d", &data);

                curr = head;
                pos = 1;
                found = 0;

                while(curr != NULL) {
                    if(curr->num == data) {
                        printf("\nFound at position %d\n", pos);
                        found = 1;
                        break;
                    }

                    curr = curr->next;
                    pos++;
                }

                if(!found)
                    printf("\nData not found!\n");

                break;
				

            case 5:
                if(head == NULL)
                    printf("\nEMPTY LIST!");
                
				else {
					printf("\nReversed singly linked list contains: ");
					
                    disp_rev(head);
                    printf("\n");
                }
				
                break;

            case 6:
                prev = NULL;
                curr = head;

                while(curr != NULL) {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }

                head = prev;
                display(head);
                break;

			case 7:
				printf("Exiting...\n");
				break;


            default:
                printf("\nInvalid choice!\n");
				break;
        }

    } while(choice != 7);

    return 0;
}