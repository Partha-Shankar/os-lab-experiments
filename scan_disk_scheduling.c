#include <stdio.h>

int request[50];
int SIZE, pre, head;

int dist(int a, int b) {
    return (a > b) ? a - b : b - a;
}
#include <stdio.h>

int request[50];
int SIZE, pre, head, uptrack, downtrack;

struct max {
    int up, down;
} kate[50];

int dist(int a, int b) {
    return (a > b) ? a - b : b - a;
}

void sort(int n) {
    int i, j;

    // Bubble sort to arrange requests in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }

    // Categorize requests into downtrack and uptrack
    j = 0;
    i = 0;
    while (request[i] != head) {
        kate[j++].down = request[i++];
    }
    downtrack = j;

    i++;
    j = 0;
    while (i < n) {
        kate[j++].up = request[i++];
    }
    uptrack = j;
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
