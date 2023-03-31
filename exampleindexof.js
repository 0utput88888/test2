// 配列に対してindexofを使う例
var fruits = ["apple", "banana", "orange", "grape"];
var index = fruits.indexOf("banana"); // indexは1になる
console.log(index); // 1を出力

var index2 = fruits.indexOf("melon"); // index2は-1になる
console.log(index2); // -1を出力

// 文字列に対してindexofを使う例
var message = "Hello, this is Bing.";
var index3 = message.indexOf("Bing"); // index3は13になる
console.log(index3); // 13を出力

var index4 = message.indexOf("Google"); // index4は-1になる
console.log(index4); // -1を出力