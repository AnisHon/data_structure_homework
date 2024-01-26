//
// Created by Anis Han on 2024/1/24.
//

#ifndef CPPPROJECT01_SORT_ALGORITHM_H
#define CPPPROJECT01_SORT_ALGORITHM_H

#include <algorithm>

namespace sort {

    template <typename T>
    auto bubble_sort(T t[], int n) -> void {
        if (n <= 1) {
            return;
        }
        for (int i = n - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (t[j] > t[j + 1]) {
                    std::swap(t[j], t[j + 1]);
                }
            }
        }
    }

    template<typename T>
    auto selection_sort(T t[], int n) -> void {
        if (n <= 1) {
            return;
        }

        int min = 0;
        for (int i = 0; i < n - 1; ++i) {
            min = i;
            for (int j = i + 1; j < n; ++j) {
                if (t[min] > t[j]) {
                    min = j;
                }
            }
            std::swap(t[i], t[min]);
        }
    }

    template <typename T>
    auto insert_sort(T t[], int n) -> void {
        if (n <= 1) {
            return;
        }
        T temp;
        for (int i = 1; i < n; ++i) {
            temp = t[i];
            int j;
            for (j = i; j > 0; --j) {
                if (t[j - 1] > temp) {
                    t[j] = t[j - 1];
                } else {
                    break;
                }
            }
            t[j] = temp;
        }
    }

    template <typename T>
    auto shell_sort(T t[], int n) -> void {
        if (n <= 1) {
            return;
        }
        int h = 1;
        while (h < n / 2) {
            h = 2 * h + 1;
        }

        T temp;
        while (h /= 2) {
            for (int i = h; i < n; ++i) {
                temp = t[i];
                int j;
                for (j = i; j > 0; j -= h) {
                    if (t[j - h] > temp) {
                        t[j] = t[j - h];
                    } else {
                        break;
                    }
                }
                t[j] = temp;
            }
        }
    }

    template <typename T>
    static auto merge(T t[], T temp[], int beg, int mid, int end) -> void {
        int b1 = beg;
        int b2 = mid + 1;
        int i = beg;
        while (b1 <= mid && b2 <= end) {
            temp[i++] = t[b1] < t[b2] ? t[b1++] : t[b2++];
        }

        while (b1 <= mid) {
            temp[i++] = t[b1++];
        }

        while (b2 <= end) {
            temp[i++] = t[b2++];
        }

        for (int j = beg; j <= end; ++j) {
            t[j] = temp[j];
        }
    }

    template <typename T>
    static auto merge_sort_(T t[], T temp[], int beg, int end) -> void {
        if (beg >= end) return;
        if (t == nullptr || temp == nullptr) return;
        int mid = (beg + end) / 2;
        merge_sort_(t, temp, beg, mid);
        merge_sort_(t, temp, mid + 1, end);

        merge(t, temp, beg, mid, end);

    }

    template <typename T>
    auto merge_sort(T t[], int n) -> void {
        if (n <= 1) return;
        T *temp = new T[n];
        merge_sort_(t, temp, 0, n - 1);
        delete[] temp;

    }

    template <typename T>
    static auto quick_sort_(T t[], int beg, int end) -> void {
        if (beg >= end) return;

        int b1 = beg;
        int e1 = end;
        T key = t[(beg + end) / 2];

        while (beg < end) {

            while (t[beg] < key) {
                ++beg;
            };

            while (t[end] > key) {
                --end;
            };

            if (beg <= end) {
                std::swap(t[beg++], t[end--]);
            }
        }

        quick_sort_(t, b1, end);
        quick_sort_(t, beg, e1);
    }

    template <typename T>
    auto quick_sort(T t[], int n) -> void {
        if (n <= 1) return;
        quick_sort_(t, 0, n - 1);
    }






} // sort

#endif //CPPPROJECT01_SORT_ALGORITHM_H
