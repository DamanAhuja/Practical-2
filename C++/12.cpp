#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
  
void removeWhitespaces(std::string& str) {
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        removeWhitespaces(line);
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Contents copied to output.txt after removing whitespaces." << std::endl;
    return 0;
}
