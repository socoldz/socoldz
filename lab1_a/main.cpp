#include <iostream>
#include <string>
#include <vector>

enum class Type
{
    HUDOZH,
    TECH
};

class Books {
private:
    const std::string nazvanie;
    const std::string avtor;
    const Type tip;

public:
    Books(const std::string& betanazvanie, const std::string& betaavtor, const Type& betatip) :nazvanie(betanazvanie), avtor(betaavtor), tip(betatip) {};
    virtual  ~Books() {}
    Type getType() const {
        return tip;
    }
   
};

class Biblioteca {
private:
    std::vector<Books> Library;

public:
    void checkbooks(const std::string& nazvanie, const std::string& avtor, const Type& tip) {
        if (nazvanie != "" && avtor != "") {
            Books* kniga = new Books(nazvanie, avtor, tip);
            Library.push_back(*kniga);
        }
        else {
            std::cout << "Bro checkni nazvanie tam, avtora, hz y knizhki " << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    void podschetswitch() {
        int hud = 0;
        int tech = 0;
        for (const Books& book : Library) {
            switch (book.getType()) {
            case Type::HUDOZH:
                ++hud;
                break;
            case Type::TECH:
                ++tech;
            }
        }
        std::cout << "Podschet switchem:" << std::endl << "Hudozhestvennih knig: " << hud << std::endl << "Technicheskih knig: " << tech << std::endl << std::endl;
    }
    void podschetif() {
        int hud = 0;
        int tech = 0;
        for (const Books& book : Library) {
            if (book.getType() == Type::HUDOZH) {
                ++hud;
            }
            else {
                ++tech;
            }
        }
        std::cout << "Podschet ifom:" << std::endl << "Hudozhestvennih knig: " << hud << std::endl << "Technicheskih knig: " << tech << std::endl;
    }
};

int main()
{
    Biblioteca libr;
    libr.checkbooks("1", "7", Type::HUDOZH);
    libr.checkbooks("3", "4", Type::HUDOZH);
    libr.checkbooks("5", "6", Type::TECH);
    libr.checkbooks("7", "66", Type::TECH);
    libr.checkbooks("69", "1337", Type::TECH);

    libr.podschetswitch();
    libr.podschetif();
    return 0;
}
