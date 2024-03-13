#include <iostream>
#include <fstream>
#include <string>

class Student {
private:
    int rollNo;
    std::string name;
    std::string className;
    int year;
    int totalMarks;

public:
    Student() {}

    Student(int rollNo, const std::string& name, const std::string& className, int year, int totalMarks)
        : rollNo(rollNo), name(name), className(className), year(year), totalMarks(totalMarks) {}

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "Roll No: " << student.rollNo << std::endl;
        os << "Name: " << student.name << std::endl;
        os << "Class: " << student.className << std::endl;
        os << "Year: " << student.year << std::endl;
        os << "Total Marks: " << student.totalMarks << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Student& student) {
        is >> student.rollNo >> student.name >> student.className >> student.year >> student.totalMarks;
        return is;
    }
};

int main() {
    std::ofstream outFile("students.txt");
    if (!outFile) {
        std::cerr << "Error: Unable to create/open file." << std::endl;
        return 1;
    }

    // Store 5 objects of Student class in a file
    for (int i = 0; i < 5; ++i) {
        int rollNo, year, totalMarks;
        std::string name, className;

        std::cout << "Enter details for student " << i + 1 << ":" << std::endl;
        std::cout << "Roll No: ";
        std::cin >> rollNo;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Class: ";
        std::getline(std::cin, className);
        std::cout << "Year: ";
        std::cin >> year;
        std::cout << "Total Marks: ";
        std::cin >> totalMarks;

        Student student(rollNo, name, className, year, totalMarks);
        outFile << student;
    }
    outFile.close();

    std::ifstream inFile("students.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    // Retrieve records from the file and display them
    std::cout << "\nRecords from the file:" << std::endl;
    Student student;
    while (inFile >> student) {
        std::cout << student << std::endl;
    }
    inFile.close();

    return 0;
}
