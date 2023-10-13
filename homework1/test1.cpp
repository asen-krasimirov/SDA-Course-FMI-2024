#include <iostream>

class student {
public :
    int marks;
    void disp() {
        std::cout<<"its base class";
    }
};

class topper:public student {
public :
    void disp() {
        std::cout<<"Its derived class";
    }
};

int main(void) {
    student s; topper t;
    s.disp();
    t.disp();
}
