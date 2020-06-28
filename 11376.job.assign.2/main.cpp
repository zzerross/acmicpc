/**
 * @ref https://www.acmicpc.net/problem/11375
 */
#include <stdio.h>

#define S 1001

int E, J, job[S][S], jobs[S], visited[S], assigned[S];

int assign(int e) {
    if (visited[e])
        return 0;

    visited[e] = 1;

    for (int i = 0; i < jobs[e]; i++) {
        int j = job[e][i];

        if (assigned[j] < 0 || assign(assigned[j]))
            return 0 <= (assigned[j] = e);
    }

    return 0;
}

int main() {
    scanf("%d %d", &E, &J);

    for (int e = 0; e < E; e++) {
        scanf("%d", &jobs[e]);

        for (int i = 0; i < jobs[e]; i++)
            scanf("%d", &job[e][i]);
    }

    for (int j = 1; j <= J; j++)
        assigned[j] = -1;

    int r = 0;

    for (int e = 0; e < E; e++) {
        for (int m = 0; m < 2; m++) {
            for (int i = 0; i < E; i++)
                visited[i] = 0;

            if (assign(e))
                r++;
        }
    }

    printf("%d\n", r);

    return 0;
}
