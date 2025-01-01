#include <stdio.h>

int main() {
    int n, tq, i, bt[10], wt[10], tt[10], rem_bt[10], t = 0, count = 0;
    float avg_wt = 0, avg_tt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > tq) {
                    t += tq;
                    rem_bt[i] -= tq;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
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
