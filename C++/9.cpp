#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& name) : name(name) {}

    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
    }
};

class Student : public Person {
private:
    std::string course;
    int marks;
    int year;

public:
    Student(const std::string& name, const std::string& course, int marks, int year)
        : Person(name), course(course), marks(marks), year(year) {}

    void display() const override {
        std::cout << "Student Details:" << std::endl;
        Person::display();
        std::cout << "Course: " << course << std::endl;
        std::cout << "Marks: " << marks << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

class Employee : public Person {
private:
    std::string department;
    double salary;

public:
    Employee(const std::string& name, const std::string& department, double salary)
        : Person(name), department(department), salary(salary) {}

    void display() const override {
        std::cout << "Employee Details:" << std::endl;
        Person::display();
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
    }
};

int main() {
    Person* p1 = new Person("John Doe");
    Person* p2 = new Student("Alice Smith", "Computer Science", 85, 2023);
    Person* p3 = new Employee("Bob Johnson", "Engineering", 60000);

    p1->display();
    std::cout << std::endl;
    p2->display();
    std::cout << std::endl;
    p3->display();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
