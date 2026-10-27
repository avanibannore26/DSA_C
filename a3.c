#include <stdio.h>
#include <string.h>

struct student {
    int roll, SS, DE, DSA, total;
    char name[20];
    float avg;
} s[50], temp;

void display(int n) {
    int i;

    printf("\nRoll\tName\tSS\tDE\tDSA\tTotal\tAverage");
    for(i = 0; i < n; i++)
        printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%.2f", s[i].roll, s[i].name, s[i].SS, s[i].DE, s[i].DSA, s[i].total, s[i].avg);
		
	printf("\n");
}

void calculate(int i) {
    s[i].total = s[i].SS + s[i].DE + s[i].DSA;
    s[i].avg = s[i].total / 3.0;
}

int main() {
    int i, j, n, ch, field, roll, found;
    char name[20];

    printf("\nEnter number of students: ");
    scanf("%d", &n);

    printf("\nEnter the student information:\n");
    for(i = 0; i < n; i++) {
        printf("\nEnter roll number and name: ");
        scanf("%d%s", &s[i].roll, s[i].name);

        printf("Enter marks in SS, DE and DSA: ");
        scanf("%d%d%d", &s[i].SS, &s[i].DE, &s[i].DSA);

        calculate(i);
    }

    do {
        printf("\nMENU\n1.Display\n2.Modify\n3.Append\n4.Search\n5.Sort\n6.Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                display(n);
                break;

            case 2:
                printf("\nEnter roll number to modify: ");
                scanf("%d", &roll);
                found = 0;

                for(i = 0; i < n; i++) {
                    if(s[i].roll == roll) {
                        found = 1;

                        printf("\n1.Roll 2.Name 3.SS 4.DE 5.DSA\n");
                        printf("\nEnter the field to be modified: ");
                        scanf("%d", &field);
					
						printf("\nEnter the modified value: ");

                        switch(field) {
                            case 1: scanf("%d", &s[i].roll); break;
                            case 2: scanf("%s", s[i].name); break;
                            case 3: scanf("%d", &s[i].SS); break;
                            case 4: scanf("%d", &s[i].DE); break;
                            case 5: scanf("%d", &s[i].DSA); break;
                            default: printf("Invalid field"); break;
                        }

                        calculate(i);
                        display(n);
                        break;
                    }
                }

                if(!found)
                    printf("\nStudent not found");

                break;

            case 3:
                if(n >= 50) {
                    printf("\nDatabase full");
                    break;
                }

                printf("\nEnter roll number and name: ");
                scanf("%d%s", &s[n].roll, s[n].name);

                printf("\nEnter marks in SS, DE and DSA: ");
                scanf("%d%d%d", &s[n].SS, &s[n].DE, &s[n].DSA);

                calculate(n);
                n++;
                display(n);
				
                break;

            case 4:
                printf("\nEnter student name to search: ");
                scanf("%s", name);
                found = 0;

                for(i = 0; i < n; i++) {
                    if(strcmp(name, s[i].name) == 0) {
                        printf("\nStudent found:");
                        printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%.2f",
                        s[i].roll, s[i].name, s[i].SS, s[i].DE, s[i].DSA, s[i].total, s[i].avg);

                        found = 1;
                        break;
                    }
                }

                if(!found)
                    printf("\nStudent not found");
				
				printf("\n");

                break;

            case 5:
                for(i = 0; i < n - 1; i++) {
                    for(j = 0; j < n - i - 1; j++) {
                        if(s[j].roll > s[j + 1].roll) {
                            temp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = temp;
                        }
                    }
                }

                display(n);
                break;

			case 6:
				printf("Exiting...\n");
				break;

            default:
                printf("\nInvalid choice!\n");
				break;
        }
    } while(ch != 6);

    return 0;
}