#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Class1 {
public:
    virtual void inf() {
        cout << "Class1" << endl;
    }
    virtual Class1* clone() {
        return new Class1(*this);
    }
    virtual ~Class1() {}
};

class Class2 : public Class1 {
public:
    virtual void inf() {
        cout << "Class2" << endl;
    }
    virtual Class2* clone() {
        return new Class2(*this);
    }
    virtual ~Class2() {}
};

void my_copy(Class1* obj, vector<Class1*>& vec) {
    Class1* copy = obj->clone();
    vec.push_back(copy);
}

int main() {
    Class1 obj1;
    Class2 obj2;

    vector<Class1*> vec;

    my_copy(&obj1, vec);
    my_copy(&obj2, vec);

    for (vector<Class1*>::iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << typeid(**i).name() << endl;
        delete* i;
    }

    return 0;
}
