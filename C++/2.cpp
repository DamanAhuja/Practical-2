#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> remove_duplicates(std::vector<int>& arr) {
    std::unordered_set<int> unique_elements;
    std::vector<int> result;

    for (int num : arr) {
        if (unique_elements.find(num) == unique_elements.end()) {
            result.push_back(num);
            unique_elements.insert(num);
        }
    }

    return result;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 3, 2, 1};
    std::vector<int> unique_arr = remove_duplicates(arr);

    std::cout << "Array after removing duplicates: ";
    for (int num : unique_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
