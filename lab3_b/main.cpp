#include <iostream> 
#include <vector> 

class Detal {
protected:
    Detal() {}
public:
    virtual ~Detal() {}
    template<typename T>
    friend void addvec(std::vector<Detal*>& vec);
};

class Sborka : public Detal {
protected:
    Sborka() = default;
public:
    virtual ~Sborka() {}
    template<typename T>
    friend void addvec(std::vector<Detal*>& vec);
};

template<typename T>
void addvec(std::vector<Detal*>& vec) {
    vec.push_back(new T());
}

int main() {
    std::vector<Detal*> Shron;
    addvec<Detal>(Shron);
    addvec<Sborka>(Shron);
    addvec<Sborka>(Shron);
    addvec<Sborka>(Shron);

    for (auto a : Shron) {
        delete a;
    }
    Shron.clear();

    return 0;
}
