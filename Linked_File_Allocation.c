#include<stdio.h>
#include<stdlib.h>

void main() {
    int f[50], p, i, st, len, j, c, k, a;
    for (i = 0; i < 50; i++) 
        f[i] = 0;

    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);
    printf("Enter blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a < 0 || a >= 50) {
            printf("Error: Block number %d is out of range. Try again.\n", a);
            i--; 
        } else {
            f[a] = 1;
        }
    }

x:
    printf("Enter index starting block and length: ");
    scanf("%d%d", &st, &len);
    if (st < 0 || st >= 50 || len <= 0) {
        printf("Error: Invalid starting block or length. Try again.\n");
        goto x;
    }

    k = len;
    if (f[st] == 0) {
        for (j = st; j < (st + k); j++) {
            if (j >= 50) {
                printf("Error: Block number %d is out of range.\n", j);
                break;
            }
            if (f[j] == 0) {
                f[j] = 1;
                printf("%d------->%d\n", j, f[j]);
            } else {
                printf("%d Block is already allocated\n", j);
                k++;
            }
        }
    } else {
        printf("%d starting block is already allocated\n", st);
    }

    printf("Do you want to enter more file(Yes - 1/No - 0): ");
    scanf("%d", &c);

    if (c == 1)
        goto x;
    else
        exit(0);
}
