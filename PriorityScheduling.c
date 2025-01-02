#include <stdio.h>

int main() {
    int i, j, pno[10], prior[10], bt[10], n, wt[10], tt[10], w1 = 0, t1 = 0, s;
    float aw, at;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter burst time and priority for process %d: ", i + 1);
        scanf("%d %d", &bt[i], &prior[i]);
        pno[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (prior[i] > prior[j]) {
                s = prior[i]; prior[i] = prior[j]; prior[j] = s;
                s = bt[i]; bt[i] = bt[j]; bt[j] = s;
                s = pno[i]; pno[i] = pno[j]; pno[j] = s;
            }
        }
    }
    wt[0] = 0;
    tt[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tt[i] = wt[i] + bt[i];
        w1 += wt[i];
        t1 += tt[i];
    }
    aw = (float)w1 / n;
    at = (float)t1 / n;
    printf("Job\tBT\tWT\tTAT\tPriority\n");
    for (i = 0; i < n; i++) printf("%d\t%d\t%d\t%d\t%d\n", pno[i], bt[i], wt[i], tt[i], prior[i]);
    printf("Average WT = %.2f, Average TAT = %.2f\n", aw, at);
    return 0;
}
