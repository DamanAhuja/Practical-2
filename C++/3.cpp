#include <iostream>
#include <map>
#include <cctype>
 
std::map<char, int> count_alphabets(const std::string& text) {
    std::map<char, int> counts;
    for (char c : text) {
        if (std::isalpha(c)) {
            char lowercase_c = std::tolower(c);
            counts[lowercase_c]++;
        }
    }
    return counts;
}

void print_table(const std::map<char, int>& counts) {
    std::cout << "Alphabet   Count" << std::endl;
    std::cout << "----------------" << std::endl;
    for (const auto& pair : counts) {
        std::cout << pair.first << "          " << pair.second << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <text>" << std::endl;
        return 1;
    }

    std::string text;
    for (int i = 1; i < argc; ++i) {
        text += argv[i];
        if (i != argc - 1) {
            text += " ";
        }
    }

    std::map<char, int> counts = count_alphabets(text);
    print_table(counts);

    return 0;
}
