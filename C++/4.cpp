#include <iostream>
#include <cstring>
#include <cctype>

// Function to show address of each character in string
void show_address(const char* str) {
    std::cout << "Address of each character in the string:" << std::endl;
    for (int i = 0; str[i] != '\0'; ++i) {
        std::cout << "Character: " << str[i] << ", Address: " << static_cast<const void*>(&str[i]) << std::endl;
    }
}

// Function to concatenate two strings
void concatenate_strings(char* str1, const char* str2) {
    strcat(str1, str2);
}

// Function to compare two strings
int compare_strings(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

// Function to calculate length of the string using pointers
int calculate_length(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

// Function to convert all lowercase characters to uppercase
void convert_to_uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (std::islower(str[i])) {
            str[i] = std::toupper(str[i]);
        }
    }
}

// Function to reverse the string
void reverse_string(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; ++i) {
        std::swap(str[i], str[length - i - 1]);
    }
}

// Function to insert a string in another string at a user-specified position
void insert_string(char* str, const char* substr, int pos) {
    int len = strlen(str);
    int sub_len = strlen(substr);
    if (pos < 0 || pos > len) {
        std::cout << "Invalid position." << std::endl;
        return;
    }
    for (int i = len - 1; i >= pos; --i) {
        str[i + sub_len] = str[i];
    }
    for (int i = 0; i < sub_len; ++i) {
        str[pos + i] = substr[i];
    }
}

int main() {
    char str1[100], str2[100], substr[100];
    int choice, pos;

    std::cout << "Enter the first string: ";
    std::cin.getline(str1, 100);

    while (true) {
        std::cout << "\nString Manipulation Menu:" << std::endl;
        std::cout << "1. Show address of each character in string" << std::endl;
        std::cout << "2. Concatenate two strings" << std::endl;
        std::cout << "3. Compare two strings" << std::endl;
        std::cout << "4. Calculate length of the string" << std::endl;
        std::cout << "5. Convert all lowercase characters to uppercase" << std::endl;
        std::cout << "6. Reverse the string" << std::endl;
        std::cout << "7. Insert a string in another string at a user specified position" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                show_address(str1);
                break;
            case 2:
                std::cout << "Enter the second string to concatenate: ";
                std::cin.ignore();
                std::cin.getline(str2, 100);
                concatenate_strings(str1, str2);
                std::cout << "Concatenated string: " << str1 << std::endl;
                break;
            case 3:
                std::cout << "Enter the second string to compare: ";
                std::cin.ignore();
                std::cin.getline(str2, 100);
                if (compare_strings(str1, str2) == 0) {
                    std::cout << "Strings are equal." << std::endl;
                } else {
                    std::cout << "Strings are not equal." << std::endl;
                }
                break;
            case 4:
                std::cout << "Length of the string: " << calculate_length(str1) << std::endl;
                break;
            case 5:
                convert_to_uppercase(str1);
                std::cout << "String converted to uppercase: " << str1 << std::endl;
                break;
            case 6:
                reverse_string(str1);
                std::cout << "Reversed string: " << str1 << std::endl;
                break;
            case 7:
                std::cout << "Enter the string to insert: ";
                std::cin.ignore();
                std::cin.getline(substr, 100);
                std::cout << "Enter the position to insert: ";
                std::cin >> pos;
                insert_string(str1, substr, pos);
                std::cout << "Modified string: " << str1 << std::endl;
                break;
            case 8:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 8." << std::endl;
        }
    }

    return 0;
}
