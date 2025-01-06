#include <stdio.h>

int request[50];
int SIZE, pre, head;

int dist(int a, int b) {
    return (a > b) ? a - b : b - a;
}

int main() {
    int n, i;
    printf("ENTER THE DISK SIZE: ");
    scanf("%d", &SIZE);
    printf("ENTER THE NUMBER OF REQUESTS: ");
    scanf("%d", &n);
    printf("ENTER THE REQUEST SEQUENCE: ");
    for (i = 0; i < n; i++) 
        scanf("%d", &request[i]);

    printf("ENTER THE CURRENT HEAD: ");
    scanf("%d", &head);

    request[n] = head;          // Add the head position to the request list
    request[n + 1] = SIZE - 1;  // Add the maximum disk position
    request[n + 2] = 0;         // Add the minimum disk position

    printf("ENTER THE PREVIOUS REQUEST: ");
    scanf("%d", &pre);

    return 0;
}
