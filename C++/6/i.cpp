#include <iostream>
#include <vector>

int binary_search_recursive(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Element found
    } else if (arr[mid] > target) {
        return binary_search_recursive(arr, target, left, mid - 1); // Search in the left half
    } else {
        return binary_search_recursive(arr, target, mid + 1, right); // Search in the right half
    }
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target;

    std::cout << "Enter the element to search: ";
    std::cin >> target;

    int index = binary_search_recursive(arr, target, 0, arr.size() - 1);
    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
