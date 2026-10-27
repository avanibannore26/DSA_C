#include<stdio.h>

int main() {
    int i, j, ch, n, a[50], key, mid, min, max, temp, pos, cmp;

    printf("\nEnter number of array elements: ");
    scanf("%d", &n);

    printf("\nEnter array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter number to be searched: ");
    scanf("%d", &key);

    do {
        printf("\nMENU\n1.Linear\n2.Binary\n3.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        cmp = 0;

        switch(ch) {
            case 1:
                for(i = 0; i < n; i++) {
                    cmp++;

                    if(a[i] == key)
                        break;
                }

                if(i < n) {
                    printf("\n%d found at position %d", key, i + 1);
                    printf("\nNumber of comparisons: %d\n", cmp);
                }
				
                else {
                    printf("\n%d not found", key);
                    printf("\nNumber of comparisons: %d\n", cmp);
                }

                break;

            case 2:
                for(i = 0; i < n - 1; i++) {
                    for(j = 0; j < n - i - 1; j++) {
                        if(a[j] > a[j + 1]) {
                            temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }

                min = 0;
                max = n - 1;
                pos = -1;

                while(min <= max) {
                    mid = (min + max) / 2;
                    cmp++;

                    if(a[mid] == key) {
                        pos = mid;
                        break;
                    }
					
                    else if(key < a[mid])
                        max = mid - 1;
					
                    else
                        min = mid + 1;
                }

                if(pos != -1) {
                    printf("\n%d found at position %d", key, pos + 1);
                    printf("\nNumber of comparisons: %d\n", cmp);
                }
                
				else {
                    printf("\n%d not found", key);
                    printf("\nNumber of comparisons: %d\n", cmp);
                }

                break;
				
			case 3:
				printf("Exiting...\n");
				break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(ch != 3);

    return 0;
}