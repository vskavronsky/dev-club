#include <iostream>

class Human {
    protected:
        const char* name;
        int age;
    
    public:
        Human() {
            std::cout << "Human constructor" << std::endl;
        }

        ~Human() {
            std::cout << "Human destructor" << std::endl;
        }
};

class Student : public Human {
    protected:
        double grade;

    public:
        //friend void initialize(Student* student);
        
        Student() : Human() {
            std::cout << "Student constructor" << std::endl;
        }
        
        ~Student() {
            std::cout << "Student destructor" << std::endl;
        }

        const char* getName() {
            return this->name;
        }

        int getAge() {
            return this->age;
        }
        
        double getGrade() {
            return this->grade;
        }

        void setGrade(double value) {
            if ( value > 0 && value <= 5.0 ) {
                this->grade = value;
            }
        }
};

class Course {
    public:
        Course() {
            std::cout << "Course constructor" << std::endl;
        }
        
        ~Course() {
            std::cout << "Course destructor" << std::endl;
        }
};

class Teacher : public Human {
    protected:
        Course* course;

    public:
        Teacher() : Human() {
            std::cout << "Teacher constructor" << std::endl;
            this->course = new Course;
        }

        ~Teacher() {
            delete course;
            std::cout << "Teacher destructor" << std::endl;
        }
};

class TutorPair {
    protected:
        Student* student;
        Teacher* teacher;
        int noMeetings;

    public:
        TutorPair() {
            std::cout << "TutorPair constructor" << std::endl;
            this->student = new Student;
            this->teacher = new Teacher;
        }

        ~TutorPair() {
            delete teacher;
            delete student;
            std::cout << "TutorPair destructor" << std::endl;
        }
};

//void initialize(Student* student) {
//    student->name = "Sasha";
//    student->age = 20;
//    student->grade = 4.5;
//}

int main() {
    std::cout << "Creating obj TutorPair" << std::endl;
    TutorPair* tp = new TutorPair;

    delete tp;

    return 0;
}
