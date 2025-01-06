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

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }

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

void scan(int n) {
    int i, seekcount = 0;
    printf("SEEK SEQUENCE = ");
    sort(n);

    if (pre < head) {
        for (i = 0; i < uptrack; i++) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].up);
            head = kate[i].up;
        }
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].down);
            head = kate[i].down;
        }
    } else {
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].down);
            head = kate[i].down;
        }
        for (i = 0; i < uptrack; i++) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].up);
            head = kate[i].up;
        }
    }
    printf("\nTOTAL DISTANCE: %d\n", seekcount);
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
    request[n] = head;
    request[n + 1] = SIZE - 1;
    request[n + 2] = 0;

    printf("ENTER THE PREVIOUS REQUEST: ");
    scanf("%d", &pre);
    scan(n + 3);
}
