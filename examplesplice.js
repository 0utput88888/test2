// 配列から要素を削除する例
var animals = ["dog", "cat", "bird", "fish"];
var removed = animals.splice(1, 2); // 1番目の要素から2つの要素を削除する
console.log(animals); // ["dog", "fish"]を出力
console.log(removed); // ["cat", "bird"]を出力

// 配列に要素を追加する例
var fruits = ["apple", "banana", "orange"];
var inserted = fruits.splice(2, 0, "grape", "melon"); // 2番目の要素の前に"grape"と"melon"を追加する
console.log(fruits); // ["apple", "banana", "grape", "melon", "orange"]を出力
console.log(inserted); // []を出力