#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    // vector<int>型の変数vを宣言
    std::vector<int> v;

    // vに1から10までの値を入れる
    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
    }

    // 乱数発生器を作成
    std::random_device rd;
    std::mt19937 g(rd());

    // shuffle関数でvの要素をランダムに並べ替える
    std::shuffle(v.begin(), v.end(), g);

    // vの要素を出力する
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}