#include <iostream> 
#include <vector> 
#include <iterator> 
#include <optional>

std::optional<int> binarySearch(std::vector<int>& arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2; auto it = std::next(arr.begin(), mid);

        if (*it == x)
            return mid;

        if (*it > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return std::nullopt;
}

int main() {
    std::vector<int> arr = { 2, 5, 7, 10, 15, 20 }; 
    int n = std::distance(arr.begin(), arr.end());

    auto result = binarySearch(arr, 0, n - 1, 10);

    if (!result)
        std::cout << "Element is not present in array";
    else
        std::cout << "Element is present at index " << *result;

    return 0;
}