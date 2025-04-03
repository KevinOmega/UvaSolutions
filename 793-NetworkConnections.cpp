#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class DisjointSet {
public:
    int represents[2000];

    DisjointSet(int n) {
        fill(represents, represents + n, -1);
    }

    int FindParent(int c1) {
        if (represents[c1] < 0) {
            return c1;
        }
        return represents[c1] = FindParent(represents[c1]); // Path compression
    }

    void Union(int c1, int c2) {
        int p1 = FindParent(c1);
        int p2 = FindParent(c2);

        if (p1 != p2) {
            if (abs(represents[p1]) >= abs(represents[p2])) { // Union by size
                represents[p1] += represents[p2];
                represents[p2] = p1;
            } else {
                represents[p2] += represents[p1];
                represents[p1] = p2;
            }
        }
    }

    bool SameParent(int c1, int c2) {
        return FindParent(c1) == FindParent(c2);
    }
};

int main() {
    int tc, nc, c1, c2;
    char inst;
    int sa, ua, ntc = 0;

    scanf("%d", &tc);
    getchar(); // Consume newline after number of test cases

    while (ntc < tc) {
        scanf("%d", &nc);
        getchar(); // Consume newline

        sa = 0, ua = 0;
        DisjointSet computers(nc);

        char line[50]; // To read the entire line
        while (fgets(line, sizeof(line), stdin) && line[0] != '\n') {
            sscanf(line, " %c %d %d", &inst, &c1, &c2);
            c1--; c2--; // Convert to zero-based index

            if (inst == 'c') {
                computers.Union(c1, c2);
            } else if (inst == 'q') {
                if (computers.SameParent(c1, c2)) {
                    sa++;
                } else {
                    ua++;
                }
            }
        }

        if (ntc > 0) {
            printf("\n");
        }
        printf("%d,%d\n", sa, ua);
        ntc++;
    }

    return 0;
}
