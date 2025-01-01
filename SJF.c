#include <stdio.h>

int main() {
    int n, i, j, temp, bt[10], wt[10], tt[10];
    float avg_wt = 0, avg_tt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tt[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    avg_wt /= n;
    avg_tt /= n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
    }

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tt);
}
