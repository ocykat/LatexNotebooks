#pragma once

namespace insertion_sort {
    template <typename T>
    void sort(T a[], int begin, int end) {
        for (int i = begin + 1; i < end; i++) {
            int x = a[i];
            int j;
            for (j = i - 1; j > -1 && a[j] > x; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = x;
        }
    }
};
