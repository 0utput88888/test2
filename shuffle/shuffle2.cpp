#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    // vector<int>型の変数vを宣言
    std::vector<int> v;

    // vに1から10までの値を入れる
    for (int i = 1; i <=7; i++) {
        v.push_back(i);
    }

    // 乱数発生器を作成
    std::random_device rd;
    std::mt19937 g(rd());

    // shuffle回数をカウントする変数countを宣言し、0に初期化する
    int count = 0;

    // do-while文でshuffleを繰り返す
    do {
        // shuffle関数でvの要素をランダムに並べ替える
        std::shuffle(v.begin(), v.end(), g);

        // shuffle回数をインクリメントする
        count++;

        // vの要素を出力する
        for (int x : v) {
            std::cout << x << " ";
        }
        std::cout << "\n";

    } while (!std::is_sorted(v.begin(), v.end())); // vが昇順にソートされていない間は繰り返す

    // shuffle回数を表示する
    std::cout << "shuffle回数: " << count << "\n";

    return 0;
}
