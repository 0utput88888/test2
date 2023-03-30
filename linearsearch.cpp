// ヘッダーファイルをインクルードする
#include <iostream>
using namespace std;

// 線形探索の関数
int linear_search(int array[], int size, int target) {
  // 配列の要素を先頭から順に調べる
  for (int i = 0; i < size; i++) {
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
  // 配列のサイズを入力する
  int size = 0;
  cin >> size;
  // 配列を宣言する
  int array[size];
  // 配列の要素を入力する
  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
  // 目的の値を入力する
  int target;
  cin >> target;
  // 線形探索を実行する
  int index = linear_search(array, size, target);
  // 結果を出力する
  if (index != -1) {
    cout << "Found at index " << index << endl;
  } else {
    cout << "Not found" << endl;
  }
  // プログラムを終了する
  return 0;
}