#include <stdio.h>

struct poly {
    int coeff, expo;
};

int main() {
    struct poly p1[20], p2[20], p3[40], temp;
    int n, m, i, j, k;

    printf("\nEnter number of terms in first polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &p1[i].coeff, &p1[i].expo);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &p2[i].coeff, &p2[i].expo);
    }

    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(p1[i].expo < p1[j].expo) {
                temp = p1[i];
                p1[i] = p1[j];
                p1[j] = temp;
            }

    for(i = 0; i < m - 1; i++)
        for(j = i + 1; j < m; j++)
            if(p2[i].expo < p2[j].expo) {
                temp = p2[i];
                p2[i] = p2[j];
                p2[j] = temp;
            }

    i = j = k = 0;

    while(i < n && j < m) {
        if(p1[i].expo == p2[j].expo) {
            p3[k] = p1[i];
            p3[k].coeff += p2[j].coeff;
			
            i++;
            j++;
            k++;
        }
		
        else if(p1[i].expo > p2[j].expo)
            p3[k++] = p1[i++];
        
		else
            p3[k++] = p2[j++];
    }

    while(i < n)
        p3[k++] = p1[i++];

    while(j < m)
        p3[k++] = p2[j++];

    printf("\nFirst Polynomial: ");
    for(i = 0; i < n; i++)
        printf("%dx^%d ", p1[i].coeff, p1[i].expo);

    printf("\nSecond Polynomial: ");
    for(i = 0; i < m; i++)
        printf("%dx^%d ", p2[i].coeff, p2[i].expo);

    printf("\nResultant Polynomial: ");
    for(i = 0; i < k; i++)
        if(p3[i].coeff != 0)
            printf("%dx^%d ", p3[i].coeff, p3[i].expo);

    return 0;
}