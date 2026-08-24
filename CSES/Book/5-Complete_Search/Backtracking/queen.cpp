
int count = 0;

const int n = 4;

int column[n] = {0};
int diag1[2 * n - 1] = {0};
int diag2[2 * n - 1] = {0};

void search(int y) {
    if (y == n) {
        count++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x + y] || diag2[x - y + n - 1])
            continue;
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}