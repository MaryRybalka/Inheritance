#include <iostream>
#include <string>

using namespace std;

enum GENDER {
    F, M, U
};
enum SKILL {
    junior, middle, senior
};
enum STYLE {
    hiphop, classic
};

class Human {
    int age;
    GENDER gender;
    string sec_name;
    int height;
public:
    Human(int _age, GENDER _gender, const string &_name, int _height) {
        this->age = _age;
        this->gender = _gender;
        this->sec_name = _name;
        this->height = _height;
    }

    int getAge() const {
        return age;
    }

    void setAge(int _age) {
        this->age = _age;
    }

    string getGender() const {
        switch (gender){
            case 0: return "female";
            case 1: return "male";
            default: return "undecided";
        }
    }

    void setGender(GENDER _gender) {
        this->gender = _gender;
    }

    const string &getName() const {
        return sec_name;
    }

    void setName(const string &_name) {
        this->sec_name = _name;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int _height) {
        this->height = _height;
    }
};

class Student : public Human {
    string number_of_zach;
public:
    Student(const string &_number_of_zach, int _age, GENDER _gender, const string &_name, int _height) : Human(_age,
                                                                                                               _gender,
                                                                                                               _name,
                                                                                                               _height) {
        this->number_of_zach = _number_of_zach;
    }

    const string &getNumber_of_zach() const {
        return number_of_zach;
    }

    void setNumber_of_zach(const string &_number_of_zach) {
        this->number_of_zach = _number_of_zach;
    }
};

class Programmer : public Human {
    SKILL skill;
    bool glasses;
public:
    Programmer(SKILL _skill, bool _glasses, int _age, GENDER _gender, const string &_name, int height) : Human(_age,
                                                                                                               _gender,
                                                                                                               _name,
                                                                                                               height) {
        this->skill = _skill;
        this->glasses = _glasses;
    }

    string getSkill() const{
        switch (skill){
            case 0: return "junior";
            case 1: return "middle";
            default: return "senior";
        }
    }

    void setSkill(SKILL _skill) {
        this->skill = _skill;
    }

    bool getGlasses() const{
        return glasses;
    }

    void setGlasses(bool _glasses) {
        this->glasses = _glasses;
    }
};

class Dancer : public Student {
    STYLE style;
public:
    Dancer(STYLE _style, const string &_num_zach, int _age, GENDER _gender, const string &_name, int height) : Student(
            _num_zach, _age, _gender, _name, height) {
        this->style = _style;
    }

    string getStyle() const{
        switch (style){
            case 0: return "hip-hop";
            default: return "classic";
        }
    }

    void setStyle(STYLE _style) {
        this->style = _style;
    }
};

class MoaisStudent : public Programmer, public Dancer {
    bool scolarship;
    bool sleep;
public:
    MoaisStudent(bool _scolarship, bool _sleep, SKILL _skill, bool _glasses, STYLE _style, const string &_num_zach,
                 int _age, GENDER _gender, const string &_name, int _height) : Programmer(_skill, _glasses, _age,
                                                                                          _gender, _name, _height),
                                                                               Dancer(_style, _num_zach, _age, _gender,
                                                                                      _name, _height) {
        this->scolarship = _scolarship;
        this->sleep = _sleep;
    }
};

class Profeccor : public Student {
    string scienece;
public:
    Profeccor(const string &_science, const string &_number_of_zach, int _age, GENDER _gender, const string &_name,
              int _height) : Student(_number_of_zach, _age, _gender, _name, _height) {
        this->scienece = _science;
    }
};

int main() {
    Human vasya(24, GENDER::M, "petrov", 167);
    Student olya("345678907654", 20, GENDER::F, "petrova", 150);
    Programmer peter(junior, true, 22, M, "kostin", 189);
    Dancer veniamin(hiphop, "12341231", 10, U, "smith", 100);
    MoaisStudent oleg(true, false, middle, true, classic, "1760009", 24, F, "nesterov", 174);
    Profeccor katya("math", "1009827", 30, F, "volodartseva", 167);

    cout << "Human Vasya:" << endl;
    cout << vasya.getAge() << endl;
    cout << vasya.getGender() << endl;

    cout << "Student Olya:" << endl;
    cout << olya.getAge() << endl;
    cout << olya.getGender() << endl;
    cout << olya.getNumber_of_zach() << endl;

    cout << "Programmer Peter:" << endl;
    cout << peter.getGender() << endl;
    cout << peter.getSkill() << endl;
    peter.setHeight(100);//call Human class method and change Human class field "height" through Programmer class object

    cout << "MOAIS student Oleg:" << endl;
    cout << oleg.getStyle() << endl;//method of Dancer class
    cout << oleg.getGlasses() << endl;//method of Programmer class
    oleg.setStyle(hiphop);
    cout << oleg.getStyle() << endl;
    return 0;
}