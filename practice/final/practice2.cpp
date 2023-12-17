#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    static int totalStudents;
    // Declare a parameterized constructor that initializes the name and age of the student.
    Student(string incoming_name, int incoming_age);
   
    // Also, implement a default constructor that sets default values for name and age.
    Student(){
        name = "None";
        age = 0;
        }
    // Declare a method "display" that prints the name and age of the student.
    void display();

    // Declare a static method "getTotalStudents" that returns the total number of students.
    int getTotalStudents(){
        return totalStudents;
        }
    
private:
    // Declare private data members for the name and age of the student.
    string name;
    int age;
};

// Implement the constructors, methods, and static members of the Student class.
Student::Student(string incoming_name, int incoming_age){
    name = incoming_name;
    age = incoming_age;
    totalStudents = totalStudents+1;
}

void Student::display(){
    cout << name << "'s age is: " << age << endl;
}

int Student::totalStudents = 0;

int main() {
    // Create an array of Student objects with a size of 3.
    Student students[3];

    // Initialize the array with the following data:
    // 1. name: "John", age: 20
    // 2. name: "Jane", age: 21
    // 3. name: "Joe", age: 22
    students[0] = Student("John", 20);
    students[1] = Student("Jane", 21);
    students[2] = Student("Joe", 22);

    students[0].display();
    students[1].display();
    students[2].display();

    cout << "Total number of students: " << students[0].getTotalStudents() << endl;
    
    return 0;
}
