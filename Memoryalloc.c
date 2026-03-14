#include <stdio.h>
#include <limits.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], remaining[m];
    for (int i = 0; i < m; i++) remaining[i] = blockSize[i];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (remaining[j] >= processSize[i]) {
                allocation[i] = j;
                remaining[j] -= processSize[i]; // Subtract the size
                break;
            }
        }
    }
    printf("\nFirst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\tRemaining Space\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1, remaining[allocation[i]]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t-\n", i + 1, processSize[i]);
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], remaining[m];
    for (int i = 0; i < m; i++) remaining[i] = blockSize[i];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (remaining[j] >= processSize[i]) {
                if (bestIdx == -1 || remaining[j] < remaining[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            remaining[bestIdx] -= processSize[i];
        }
    }
    printf("\nBest Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\tRemaining Space\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1, remaining[allocation[i]]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t-\n", i + 1, processSize[i]);
    }
}

// Add worstFit and nextFit functions here similarly...

int main() {
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) scanf("%d", &blockSize[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) scanf("%d", &processSize[i]);

    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    // Call other functions...
    return 0;
}