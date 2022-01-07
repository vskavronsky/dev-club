#include <iostream>
#include <string>

class Advisor {};

class Student {
    protected:
        std::string m_name;
        double m_gradePointAverage;
        int m_semesterHours;
    
    public:
        Student(const char* name = "no name")
            : m_name(name), m_gradePointAverage(0.0), m_semesterHours(0)
        {
            std::cout << "Construct student " << m_name << std::endl;
        }

        ~Student() {
            std::cout << "Destruct student " << m_name << std::endl;
        }

        void addCourse(int hours, double grade) {
            std::cout << "Add course for " << m_name << std::endl;
            m_gradePointAverage = m_semesterHours * m_gradePointAverage + grade;
            m_semesterHours += hours;
            m_gradePointAverage = m_gradePointAverage / m_semesterHours;
        }

        int getSemesterHours() const {
            return m_semesterHours;
        }

        double getGradePointAverage() const {
            return m_gradePointAverage;
        }
};

class GraduateStudent : public Student {
    protected:
        Advisor m_advisor;
        double m_qualifierGrade;

    public:
        GraduateStudent(const char* name, const Advisor& advisor, double qualifierGrade = 0.0)
            : Student(name), m_advisor(advisor), m_qualifierGrade(qualifierGrade)
        {
            std::cout << "Construct graduate student " << m_name << std::endl;
        }

        ~GraduateStudent() {
            std::cout << "Destruct graduate student " << m_name << std::endl;
        }

        double getQualifierGrade() const {
            return m_qualifierGrade;
        }
};

int main() {
    Advisor adv;

    Student nick("Nick Thomas");
    GraduateStudent matt("Matt Madox", adv, 1.5);

    nick.addCourse(30, 3.7);
    matt.addCourse(40, 4.2);
    std::cout << "Matts grade: " << matt.getQualifierGrade() << std::endl;

    return 0;
}
