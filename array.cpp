// ヘッダーファイルをインクルードする
#include <iostream>
#include <array>

// 線形探索の関数
int linear_search(std::array<int, 10>& array, int target) {
    // 配列の要素を先頭から順に調べる
    for (int i = 0; i < array.size(); i++) {
        // 目的の値が見つかったらそのインデックスを返す
        if (array[i] == target) {
            return i;
        }
    }
    // 目的の値が見つからなかったら-1を返す
    return -1;
}

// メイン関数を定義する
int main()
{
    // 配列を宣言する
    std::array<int, 10> array = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    // 目的の値を入力する
    int target;
    std::cin >> target;
    // 線形探索を実行する
    int index = linear_search(array, target);
    // 結果を出力する
    if (index != -1) {
        std::cout << "Found at index " << index << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }
    // プログラムを終了する
    return 0;
}