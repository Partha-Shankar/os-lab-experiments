#include<stdio.h>

int i, j, nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
int recent[10], lrucal[50], count = 0;

int lruvictim() 
{ 
    return 0;
}

void main() 
{ 
        printf("\n\t\t\t LRU PAGE REPLACEMENT ALGORITHM");
    printf("\n Enter no.of Frames.. ."); 
    scanf("%d", &nof); 
    printf(" Enter no.of reference string.."); 
    scanf("%d", &nor); 
    printf("\n Enter reference string.."); 
    for (i = 0; i < nor; i++) 
        scanf("%d", &ref[i]); 

    for (i = 1; i <= nof; i++) 
    { 
        frm[i] = -1; 
        lrucal[i] = 0; 
    } 
    for (i = 0; i < 10; i++) 
        recent[i] = 0;

    return 0; 
}
