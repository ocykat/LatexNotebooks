#pragma once

#include "../../util/util.h"

namespace quick_sort {
    template <typename T>
    int partition(T a[], int begin, int end) {
        T pivot_key = a[end - 1];
        int pivot = begin;

        for (int i = begin; i < end - 1; i++) {
            if (a[i] < pivot_key) {
                util::swap(a[i], a[pivot]);
                pivot++;
            }
        }

        util::swap(a[pivot], a[end - 1]);

        return pivot;
    }

    template <typename T>
    void sort(T a[], int begin, int end) {
        if (begin < end - 1) {
            int pivot = partition(a, begin, end);
            sort(a, begin, pivot);
            sort(a, pivot, end);
        }
    }
};
