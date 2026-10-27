#include <stdio.h>
#define MAX 10

typedef struct queue {
    int front, rear;
    int data[MAX];
} queue;

int G[MAX][MAX], n, visited[MAX];

int empty(queue *q) {
    return q->front > q->rear;
}

void enqueue(queue *q, int x) {
    q->data[++q->rear] = x;
}

int dequeue(queue *q) {
    return q->data[q->front++];
}

void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for(i = 0; i < n; i++) {
        if(!visited[i] && G[v][i] == 1)
            DFS(i);
    }
}

void BFS(int v) {
    int i;
    queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, v);
    visited[v] = 1;

    while(!empty(&q)) {
        v = dequeue(&q);
        printf("%d ", v);

        for(i = 0; i < n; i++) {
            if(!visited[i] && G[v][i] == 1) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, v, ch, nedges;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            G[i][j] = 0;

    printf("\nEnter number of edges: ");
    scanf("%d", &nedges);

    for(i = 0; i < nedges; i++) {
        printf("\nEnter start and end vertices: ");
        scanf("%d%d", &v, &j);
        G[v][j] = G[j][v] = 1;
    }

    do {
        printf("\nMENU\n1.DFS\n2.BFS\n3.Display matrix\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter starting vertex: ");
                scanf("%d", &v);

                for(i = 0; i < n; i++)
                    visited[i] = 0;

                printf("\nDFS Traversal: ");
                DFS(v);
                printf("\n");
                break;

            case 2:
                printf("\nEnter starting vertex: ");
                scanf("%d", &v);
				
				for(i = 0; i < n; i++)
                    visited[i] = 0;
				
                printf("\nBFS Traversal: ");
                BFS(v);
				printf("\n");
                break;

            case 3:
                printf("\nAdjacency Matrix:\n");

                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++)
                        printf("%d\t", G[i][j]);
                    printf("\n");
                }
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