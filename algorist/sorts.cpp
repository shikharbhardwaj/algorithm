#include <algorithm>
void insertion_sort(int *x, int n) {
    for (int i = 1; i < n; i++) {
        int cur = x[i];
        int j = i - 1;
        while (x[j] > cur && j >= 0) {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = cur;
    }
}
void qsort1(int *x, int l, int u) {
    if (l >= u) {
        return;
    }
    int m = l;
    // Simple partitioning
    for (int i = l + 1; i <= u; i++) {
        if (x[i] < x[l]) {
            std::swap(x[++m], x[i]);
        }
    }
    std::swap(x[l], x[m]);
    qsort1(x, l, m - 1);
    qsort1(x, m + 1, u);
}
void qsort2(int *x, int l, int u) {
    if (l >= u) {
        return;
    }
    int t = x[l]; // Lowest element is the pivot
    int i = l, j = u + 1;
    do {
        do {
            i++;
        } while (i <= u && x[i] < t);
        do {
            j--;
        } while (x[j] > t);
        if (i > j) {
            break;
        }
        std::swap(x[i], x[j]);
    } while (true);
    std::swap(x[l], x[j]);
    qsort2(x, l, j - 1);
    qsort2(x, j + 1, u);
}
const int cutoff = 23;
void qsort3(int *x, int l, int u) {
    if (u - l + 1 <= cutoff) {
        insertion_sort(x + l, u - l + 1);
        return;
    }
    // int m = l;
    // for (int i = l + 1; i <= u; i++) {
    // if (x[i] < x[l]) {
    // std::swap(x[++m], x[i]);
    //}
    //}
    // std::swap(x[l], x[m]);
    int t = x[l]; // Lowest element is the pivot
    int i = l, j = u + 1;
    do {
        do {
            i++;
        } while (i <= u && x[i] < t);
        do {
            j--;
        } while (x[j] > t);
        if (i > j) {
            break;
        }
        std::swap(x[i], x[j]);
    } while (true);
    std::swap(x[l], x[j]);
    qsort3(x, l, j - 1);
    qsort3(x, j + 1, u);
}

std::random_device rd;
std::mt19937 eng(rd());
void qsort4(int *x, int l, int u) {
    if (u - l + 1 <= cutoff) {
        insertion_sort(x + l, u - l + 1);
        return;
    }
    std::uniform_int_distribution<int> dist(u, l);
    // Random pivot
    std::swap(x[l], x[dist(eng)]);
    int t = x[l];
    int i = l, j = u + 1;
    do {
        do {
            i++;
        } while (i <= u && x[i] < t);
        do {
            j--;
        } while (x[j] > t);
        if (i > j) {
            break;
        }
        std::swap(x[i], x[j]);
    } while (true);
    std::swap(x[l], x[j]);
    qsort3(x, l, j - 1);
    qsort3(x, j + 1, u);
}
