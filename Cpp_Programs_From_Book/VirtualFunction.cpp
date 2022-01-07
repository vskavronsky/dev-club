#include <iostream>
#include <memory>

class Student {
    public:
        //void calcTuition()
        virtual void calcTuition()
        {
            std::cout << "Function: Student::calcTuition" << std::endl;
        }

        virtual ~Student() {}
};

class GraduateStudent : public Student {
    public:
        //void calcTuition()
        virtual void calcTuition() override
        {
            std::cout << "Function: GraduateStudent::calcTuition" << std::endl;
        }

        virtual ~GraduateStudent() {}
};

void foo(Student& student) {
    student.calcTuition();
}

int main() {
    std::unique_ptr<Student> bob(new Student);
    foo(*bob);

    std::unique_ptr<GraduateStudent> chuck(new GraduateStudent);
    foo(*chuck);

    return 0;
}
