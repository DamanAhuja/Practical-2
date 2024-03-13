#include <iostream>
#include <vector>

std::vector<int> merge_ordered_arrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged_array;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged_array.push_back(arr1[i]);
            i++;
        } else {
            merged_array.push_back(arr2[j]);
            j++;
        }
    }

    // Add remaining elements from arr1
    while (i < arr1.size()) {
        merged_array.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements from arr2
    while (j < arr2.size()) {
        merged_array.push_back(arr2[j]);
        j++;
    }

    return merged_array;
}

int main() {
    std::vector<int> arr1 = {1, 3, 5, 7, 9};
    std::vector<int> arr2 = {2, 4, 6, 8, 10};

    std::vector<int> merged_array = merge_ordered_arrays(arr1, arr2);

    std::cout << "Merged Ordered Array: ";
    for (int num : merged_array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
