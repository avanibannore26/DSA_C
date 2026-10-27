#include<stdio.h>

int main() {
	int ch, i, j, k, a[50], n, temp, min, pass, comp, sw;
		
	do {
		printf("\nMENU\n1.Bubble\n2.Selection\n3.Insertion\n4.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		
		pass = 0;
		comp = 0;
		sw = 0;
		
		switch(ch) {
			case 1:
				printf("\nEnter number of array elements: ");
				scanf("%d", &n);
				
				printf("\nEnter array elements: ");
				for(i = 0; i < n; i++)
					scanf("%d", &a[i]);
				
					for(i = 0; i < n - 1; i++) {
						pass++;
						printf("\nPass: %d\n", pass);
						
						for(j = 0; j < n - i - 1; j++) {
							comp++;
							
							if(a[j] > a[j + 1]) {
								temp = a[j];
								a[j] = a[j + 1];
								a[j + 1] = temp;
								sw++;
							}
						}
						
						for(k = 0; k < n; k++)
							printf("%d\t", a[k]);

						if(sw == 0)
							break;
						
						printf("\n");
					}
					
				printf("\nSorted array elements: ");
				for(i = 0; i < n; i++)
					printf("%d\t", a[i]);
					
				printf("\n\nPasses = %d\nComparisons = %d\nSwaps = %d\n", pass, comp, sw);
				
				break;
			
			case 2:
				printf("\nEnter number of array elements: ");
				scanf("%d", &n);
				
				printf("\nEnter array elements: ");
				for(i = 0; i < n; i++)
					scanf("%d", &a[i]);			
				
					for(i = 0; i < n - 1; i++) {
						pass++;
						min = i;
						
						for(j = i + 1; j < n; j++) {
							comp++;
							
							if(a[j] < a[min])
								min = j;
						}
						
						temp = a[i];
						a[i] = a[min];
						a[min] = temp;
						sw++;
						
						printf("\nPass: %d\n", pass);
						for(k = 0; k < n; k++)
							printf("%d\t", a[k]);
						
						printf("\n");
					}

				printf("\nSorted array elements: ");
				for(i = 0; i < n; i++)
					printf("%d\t", a[i]);

				printf("\n\nPasses = %d\nComparisons = %d\nSwaps = %d\n", pass, comp, sw);
				
				break;
			
			case 3:
				printf("\nEnter number of array elements: ");
				scanf("%d", &n);
				
				printf("\nEnter array elements: ");
				for(i = 0; i < n; i++)
					scanf("%d", &a[i]);			
				
					for(i = 1; i < n; i++) {
						pass++;
						temp = a[i];
						
						for(j = i - 1; j >= 0; j--) {
							comp++;
							
							if(temp < a[j]) {
								a[j + 1] = a[j];
								sw++;
							}
							else
								break;
						}
						
						a[j + 1] = temp;
						
						printf("\nPass: %d\n", pass);
						for(k = 0; k < n; k++)
							printf("%d\t", a[k]);
						
						printf("\n");
					}
					
				printf("\nSorted array elements: ");
				for(i = 0; i < n; i++)
					printf("%d\t", a[i]);

				printf("\n\nPasses = %d\nComparisons = %d\nSwaps = %d\n", pass, comp, sw);

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