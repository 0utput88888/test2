#include <iostream>
#include <array>
#include <algorithm>
#include <random>

int main() {
    // array<int, 10>型の変数arrを宣言し、1から10で初期化する
    std::array<int, 10> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 乱数発生器を作成
    std::random_device rd;
    std::mt19937 g(rd());

    // 昇順になっている個数の最大値を記録する変数max_countを宣言し、0に初期化する
    int max_count = 0;

    // 昇順になっている個数が最大だったときの配列を記録する変数max_arrを宣言する
    std::array<int, 10> max_arr;

    // for文で1万回試す
    for (int trial = 0; trial < 1000000; trial++) {
        // shuffle関数でarrの要素をランダムに並べ替える
        std::shuffle(arr.begin(), arr.end(), g);

        // 昇順になっている個数をカウントする変数countを宣言し、0に初期化する
        int count = 0;

        // for文でarrの要素をチェックする
        for (int i = 0; i < arr.size() - 1; i++) {
            // arr[i] < arr[i+1]なら昇順と判断し、countをインクリメントする
            if (arr[i] < arr[i + 1]) {
                count++;
            }
        }

        // countがmax_countより大きければ、max_countとmax_arrを更新する
        if (count > max_count) {
            max_count = count;
            max_arr = arr;
        }
    }

    // 昇順になっている個数の最大値とそのときの配列を表示する
    std::cout << "昇順になっている個数の最大値: " << max_count << "\n";

    std::cout << "そのときの配列: ";
    for (int x : max_arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}