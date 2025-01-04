#include<stdio.h>

int main() 
{
    int i, j, n, a[50], frame[10], no, k, avail, count = 0; 

    // Input Handling
    printf("\n ENTER THE NUMBER OF PAGES:\n"); 
    scanf("%d", &n); 
    printf("\n ENTER THE PAGE NUMBER :\n"); 
    for (i = 1; i <= n; i++) 
        scanf("%d", &a[i]); 
    printf("\n ENTER THE NUMBER OF FRAMES :"); 
    scanf("%d", &no); 

    
    for (i = 0; i < no; i++) 
        frame[i] = -1;

    return 0;
}
