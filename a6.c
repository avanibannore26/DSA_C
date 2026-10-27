#include <stdio.h>
#define MAX 5

struct stack {
    int stk[MAX], top;
} st;

int full() {
    return st.top == MAX - 1;
}

int empty() {
    return st.top == -1;
}

void push(int x) {
    if(full () == 1)
        printf("\nStack overflow!\n");

    else
        st.stk[++st.top] = x;
}

void pop() {
    if(empty() == 1)
        printf("\nEmpty stack!\n");
	
    else
        printf("\nPopped data: %d\n", st.stk[st.top--]);
}

void display() {
    int i;
	
    if(empty() == 1)
        printf("\nEmpty stack!\n");
	
    else {
		printf("\nStack contains: ");
		
        for(i = st.top; i >= 0; i--)
            printf("%d ", st.stk[i]);
        printf("\n");
    }
}

int main() {
    int ch, x;
    st.top = -1;

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
				printf("\nInvalid choice!\n");
				break;
        }
    } while(ch != 4);

    return 0;
}