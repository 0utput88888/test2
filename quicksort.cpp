#include <iostream>
#include <vector>
#include <algorithm> // std::swap, std::make_heap, std::sort_heap
#include <cmath>   // std::log

using namespace std;

// 挿入ソート（小さい配列向け最適化）
template <typename T>
void insertionSort(vector<T>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        T key = arr.at(i);
        int j = i - 1;
        while (j >= left && arr.at(j) > key) {
            arr.at(j + 1) = arr.at(j);
            --j;
        }
        arr.at(j + 1) = key;
    }
}

// 3つの要素の中央値を返すヘルパー関数
template <typename T>
T median(T a, T b, T c) {
    if ((a <= b && b <= c) || (c <= b && b <= a)) return b;
    if ((b <= a && a <= c) || (c <= a && a <= b)) return a;
    return c;
}

// パーティション（ピボットを中央値に）
template <typename T>
int partition(vector<T>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    T pivot = median(arr.at(left), arr.at(mid), arr.at(right));
    int i = left;
    int j = right;

    while (true) {
        while (arr.at(i) < pivot) ++i;
        while (arr.at(j) > pivot) --j;
        if (i >= j) return j;
        swap(arr.at(i), arr.at(j));
        ++i;
        --j;
    }
}

// 高速クイックソート
const int INSERTION_SORT_THRESHOLD = 16; // 挿入ソートへの切り替え閾値

template <typename T>
void quickSort(vector<T>& arr, int left, int right, int depthLimit) {
    while (right - left > INSERTION_SORT_THRESHOLD) {
        if (depthLimit == 0) {
            make_heap(arr.begin() + left, arr.begin() + right + 1);
            sort_heap(arr.begin() + left, arr.begin() + right + 1);
            return;
        }
        --depthLimit;

        int pivotIndex = partition(arr, left, right);
        if (pivotIndex - left < right - pivotIndex) {
            quickSort(arr, left, pivotIndex, depthLimit);
            left = pivotIndex + 1;
        } else {
            quickSort(arr, pivotIndex + 1, right, depthLimit);
            right = pivotIndex;
        }
    }
    insertionSort(arr, left, right);
}

// ソート関数（エントリポイント）
template <typename T>
void sortArray(vector<T>& arr) {
    if (arr.empty()) return;
    int depthLimit = 2 * log2(arr.size()); // log を log2 に修正
    quickSort(arr, 0, arr.size() - 1, depthLimit);
}

// メイン関数
template <typename T>
void printArray(const vector<T>& arr) {
    for (const auto& num : arr) cout << num << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {34, 7, 23, 32, 5, 62, 32, 78, 4, 1, 90};
    sortArray(arr);
    printArray(arr);
    return 0;
}