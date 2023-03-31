#include <iostream> // 入出力を扱うライブラリ
#include <cstdlib> // 乱数を扱うライブラリ
#include <ctime> // 時刻を扱うライブラリ
#include <algorithm>

// 配列の要素を入れ替える関数
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 配列の最初・中央・最後の要素の中央値を返す関数
int median_of_three(int a[], int low, int high) {
    int mid = (low + high) / 2; // 中央のインデックス
    // 最初・中央・最後の要素を昇順に並べる
    if (a[low] > a[mid]) swap(a[low], a[mid]);
    if (a[mid] > a[high]) swap(a[mid], a[high]);
    if (a[low] > a[mid]) swap(a[low], a[mid]);
    // 中央の要素を返す
    return a[mid];
}

// 配列をpivotを基準に分割する関数
int partition(int a[], int low, int high) {
    // pivotをmedian-of-three法で選ぶ
    int pivot = median_of_three(a, low, high);
    // lowとhighの間でpivotより小さい要素と大きい要素を入れ替える
    while (low <= high) {
        // pivotより小さい要素を左から探す
        while (a[low] < pivot) low++;
        // pivotより大きい要素を右から探す
        while (a[high] > pivot) high--;
        // 見つかったら入れ替える
        if (low <= high) {
            swap(a[low], a[high]);
            low++;
            high--;
        }
    }
    // 分割点のインデックスを返す
    return low;
}

// クイックソートの関数
void quicksort(int a[], int low, int high) {
    // 範囲が1以上ならソートする
    if (low < high) {
        // 配列を分割する
        int index = partition(a, low, high);
        // 左側の部分配列をソートする
        quicksort(a, low, index - 1);
        // 右側の部分配列をソートする
        quicksort(a, index, high);
    }
}

int main() {
    // 乱数の種を現在時刻で初期化する
    srand(time(NULL));
    // 要素数10の整数型の配列を宣言する
    int a[10];
    // 配列の各要素に0から99までのランダムな値を代入する
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }

    quicksort(a, 0, 9);

    if (std::is_sorted(a, a + 10)) {
        // 配列の要素をすべて表示する
        for (int i = 0; i < 10; i++) {
            std::cout << a[i] << " "; // 配列のi番目の要素と空白を出力する
        }
        std::cout << std::endl; // 改行を出力する
    }
}