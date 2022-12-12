
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Grades{
    string subjects[3] = {"SJL", "ANJ", "MAT"};
    map<string, vector<int>> grades;
public:
    Grades(){
        for (string subject_: subjects ){
            grades[subject_] = {};
        }
    }

    void add_grade(string subject_, int grade){
        grades[subject_].push_back(grade);
    }

    void remove_grade(string subject, int grade){
        for(int i = 0; i<=grades.size()-1; i++){
            if (grades[subject][i] == grade){
                grades[subject].erase(grades[subject].begin()+i);
                break;
            }
        }
    }

    void show_grades(string subject){
        for (int grade : grades[subject]){
            cout << grade<< "|";
        }
    }

    float get_average(string subject){
        float a;
        float count = 0.0;
        float sum = 0.0;
        for (float grade : grades[subject]){
            sum += grade;
            count += 1.0;
        }
        a = sum / count;
        return a;
    }
};

class Student{
    string name;
    string class_;
public:
    Grades grades;
    Student(string name_, string class_p){
        name = name_;
        class_ = class_p;
    }

    string get_name(){
        return name;
    }

    string get_class(){
        return class_;
    }
    void set_name(string name_){
        name = name_;
    }
    void show_name(){
        cout << name;
    }

};

class Menu{
    vector<Student> students;
public:

    void add_student(){
        cout << "ADD STUDENT"<< endl;
        cout << "Name:";
        string name;
        cin >> name;
        cout << "Class:";
        string class_;
        cin >> class_;
        Student s(name, class_);
        students.push_back(s);
    }

    void student_menu(Student s){
        while(true) {
            cout << endl<< s.get_name() << " MENU" << endl;
            cout << "1) Add grade" << endl;
            cout << "2) Remove grade" << endl;
            cout << "3) Show grades" << endl;
            cout << "4) Average" << endl;
            cout << "0) Exit" << endl;
            int a;
            cout << "Choose action:";
            cin >> a;
            if (a == 1) {
                cout << "Subject:";
                string su;
                cin >> su;
                cout << "Grade:";
                int g;
                cin >> g;
                s.grades.add_grade(su, g);
            } else if (a == 2) {
                cout << "Subject:";
                string su;
                cin >> su;
                cout << "Grade:";
                int g;
                cin >> g;
                s.grades.remove_grade(su, g);
            } else if (a == 3) {
                cout << "Subject:";
                string su;
                cin >> su;
                s.grades.show_grades(su);
            } else if (a == 4) {
                cout << "Subject:";
                string su;
                cin >> su;
                cout << s.grades.get_average(su) << endl;
            } else if (a == 0) {
                break;
            }
        }
    }

    Student choose_student(){
        cout << "CHOOSE STUDENT"<<endl;
        for(int i=0; i<=students.size()-1; i++){
            cout << i<<") "<<students[i].get_name() << " " << students[i].get_class() << endl;
        }
        int a;
        cout << "Choose student:";
        cin >> a;
        return students[a];
    }

    int menu(){
        while(1) {
            cout << "MENU" << endl;
            cout << "1) Add student" << endl;
            cout << "2) Manage student" << endl;
            cout << "Pick action:";
            int a;
            cin >> a;
            if (a == 1) {
                add_student();
            } else if (a == 2) {
                if (students.size() != 0) {
                    student_menu(choose_student());
                } else {
                    cout << "NO STUDENT";
                }
            } else{
                return 0;
            }
        }
    }


};


int main(){
    Menu m;
    m.menu();



    return 1;
}