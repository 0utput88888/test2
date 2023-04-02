#include <iterator> // std::distanceを使うために必要
#include <iostream>
#include <vector>
#include <list>

int main()
{
    // std::vectorに対してstd::distanceを使う例
    {
        std::vector<int> v = {3, 1, 4};
        std::size_t d = std::distance(v.begin(), v.end()); // vの要素数を求める
        std::cout << d << std::endl; // 3と出力される
    }

    // std::listに対してstd::distanceを使う例
    {
        std::list<int> ls = {3, 1, 4, 5, 2};
        std::size_t d = std::distance(ls.begin(), ls.end()); // lsの要素数を求める
        std::cout << d << std::endl; // 5と出力される
    }
}