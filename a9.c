#include <stdio.h>
#include <stdlib.h>

struct queue {
    int num;
    struct queue *next;
} *front, *rear, *p;

int empty() {
    return front == NULL;
}

void add(int x) {
    p = (struct queue *)malloc(sizeof(struct queue));
    p->num = x;
    p->next = NULL;
	
    if(rear == NULL) {
        front = rear = p;
    }
	
    else {
        rear->next = p;
        rear = p;
    }
	
    printf("\nAdded data: %d\n", x);
}

void delete() {
    if(empty() == 1)
        printf("\nEmpty queue!\n");
	
    else {
        p = front;
        printf("\nDeleted data: %d\n", p->num);
        front = front->next;
        free(p);
		
        if(front == NULL)
            rear = NULL;
    }
}

void display() {
    if(empty() == 1)
        printf("\nEmpty queue!\n");
	
    else {
        p = front;
        printf("\nQueue contains: ");
		
        while(p != NULL) {
            printf("%d ", p->num);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, x;
    front = rear = NULL;

    do {
        printf("\nMENU\n1.Add\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter data to be added: ");
                scanf("%d", &x);
                add(x);
                display();
                break;
			
            case 2:
                delete();
                display();
                break;
			
            case 3:
                display();
                break;
			
			case 4:
				printf("Exiting...\n");
				break;
			
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(ch != 4);

    return 0;
}