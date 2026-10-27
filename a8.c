#include <stdio.h>
#define MAX 5

struct queue {
    int q[MAX], front, rear;
} q1;

int full() {
    return q1.rear == MAX-1;
}

int empty() {
    return q1.front == q1.rear+1;
}

void add(int x) {
    if(full() == 1)
        printf("\nQueue is full!\n");
	
    else {
        q1.q[++q1.rear] = x;
        printf("\nAdded data: %d\n", x);
    }
}

void delete() {
    if(empty() == 1)
        printf("\nEmpty queue!\n");
	
    else
        printf("\nDeleted data: %d\n", q1.q[q1.front++]);
}

void display() {
    int i;
	
    if(empty() == 1)
        printf("\nEmpty queue!\n");
	
    else {
        printf("\nQueue contains: ");
		
        for(i = q1.front; i <= q1.rear; i++)
            printf("%d ", q1.q[i]);
        printf("\n");
    }
}

int main() {
    int ch, x;
    q1.front = 0;
    q1.rear = -1;

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