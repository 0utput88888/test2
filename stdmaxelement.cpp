#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    // (1) ベクトルから最大値を見つける
    std::vector<int> v = {3, 1, 4, 5, 2};
    auto it = std::max_element(v.begin(), v.end());
    std::cout << "The maximum element is " << *it << "\n";

    // (2) 配列から最大値を見つける
    int a[] = {3, 1, 4, 5, 2};
    auto it2 = std::max_element(std::begin(a), std::end(a));
    std::cout << "The maximum element is " << *it2 << "\n";

    // (3) リストから最大値を見つける
    std::list<int> l = {3, 1, 4, 5, 2};
    auto it3 = std::max_element(l.begin(), l.end());
    std::cout << "The maximum element is " << *it3 << "\n";

    // (4) 比較関数を指定して最大値を見つける
    std::vector<std::string> s = {"apple", "banana", "orange", "pear"};
    auto it4 = std::max_element(s.begin(), s.end(), [](const std::string& a, const std::string& b){
        return a.size() < b.size();
    });
    std::cout << "The longest string is " << *it4 << "\n";
}