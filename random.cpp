#include <iostream> // 入出力を扱うライブラリ
#include <cstdlib> // 乱数を扱うライブラリ
#include <ctime> // 時刻を扱うライブラリ

int main() {
    // 乱数の種を現在時刻で初期化する
    srand(time(NULL));
    // 要素数10の整数型の配列を宣言する
    int a[10];
    // 配列の各要素に0から99までのランダムな値を代入する
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }
    // 配列の要素をすべて表示する
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " "; // 配列のi番目の要素と空白を出力する
    }
    std::cout << std::endl; // 改行を出力する
}