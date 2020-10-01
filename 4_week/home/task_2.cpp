//  Created by Дарья Землянская on 27.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
struct Lesson;

struct Student{
    Lesson * les;
    
    Student(): lessons{}, name("None") {
    }
    ~Student(){
    }
    
    Student(const std::string& n, const std::vector <Lesson*>& s): lessons(s), name(n)
    {
    }
    
    std::string name;
    std::vector <Lesson*> lessons;
    
};


struct Lesson{
    Student * st;
    
    Lesson(): students{}, title("None") {
    }
    ~Lesson(){
    }
    
    Lesson(const std::vector <Student*>& s, const std::string& t): students(s), title(t)
    {
    }
    
    std::string title;
    std::vector <Student*> students;

};


void add(Student& a, Lesson& b){
    b.students.push_back(&a);
    a.lessons.push_back(&b);
}

void Print_v(const struct Lesson& v){
    std::cout << v.title << ":" << std::endl;
    for (auto i: v.students){
        std::cout << i->name << " ";
    }
    std::cout << std::endl;
}

void Print_v(const struct Student& v){
    std::cout << v.name << ":" << std::endl;
    for (auto i: v.lessons){
        std::cout << i->title << " ";
    }
    std::cout << std::endl;
}



int main() {
    Student one, two, three;
    Student *pt1 = &one;
    Student *pt2 = &two;
    Student *pt3 = &three;
    
    Lesson l1, l2, l3;
    Lesson *les1 = &l1;
    Lesson *les2 = &l2;
    Lesson *les3 = &l3;
    
    pt1 -> name = "Masha";
    pt2 -> name = "Ivan";
    pt3 -> name = "Petya";
    
    les1 -> title = "Math";
    les2 -> title = "English";
    les3 -> title = "Code";
    
    std::vector <Student> stud = {*pt1, *pt2, *pt3};
    std::vector <Lesson> les = {*les1, *les2, *les3};

    
    add(*pt1, *les3);
    add(*pt3, *les3);
    add(*pt3, *les2);
    
    Print_v(*les3);
    Print_v(*pt1);
    Print_v(*pt3);
      
    return 0;
}
