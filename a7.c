#include <stdio.h>
#include <stdlib.h>

struct stack {
    int num;
    struct stack *next;
} *top, *p;

int isempty() {
    if(top == NULL)
        return 1;
	
    else
        return 0;
}

void push(int x) {
    p = (struct stack *)malloc(sizeof(struct stack));
    p->num = x;
    p->next = top;
    top = p;
}

void pop() {
    if(isempty() == 1)
        printf("\nEmpty stack!");
	
    else {
        p = top;
        printf("\nPopped data: %d", p->num);
        top = top->next;
        free(p);
    }
}

void display() {
    if(isempty() == 1)
        printf("\nEmpty stack!");
	
    else {
        p = top;
        printf("\nStack contains: ");
		
        while(p != NULL) {
            printf("%d ", p->num);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, x;
    top = NULL;

    do {
        printf("\nMENU\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter data to be pushed: ");
                scanf("%d", &x);
                push(x);
                display();
                break;
			
            case 2:
                pop();
                display();
                break;
			
            case 3:
                display();
                break;

			case 4:
				printf("Exiting...\n");
				break;
			
            default:
                printf("\nInvalid choice!");
                break;
        }
    } while(ch != 4);

    return 0;
}