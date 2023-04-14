#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class car {
public:
	std::string model;
	car() {}
	virtual ~car() { std::cout << "Model' tachki: " << model << std::endl << std::endl; }
};
class Mercedes : public car {
public:
	Mercedes(std::string model) {
		this->model = model;
	}
	~Mercedes() {std::cout << "Brand: Mercedes" << std::endl;}
};
class Toyota : public car {	
public:
	Toyota(std::string model) {
		this->model = model;
	}
	~Toyota() { std::cout << "Brand: Toyota" << std::endl; }
};
class BMW : public car {
public:
	BMW(std::string model) {
		this->model = model;
	}
	~BMW() {std::cout << "Brand: BMW" << std::endl;}
};

car* brand_class(std::string brand, std::string model) {
	car* result = new Mercedes(model);
	if (brand == "Mercedes")
	{
		result = new Mercedes(model);
	}
	else if (brand == "Toyota") {
		result = new Toyota(model);
	}
	else if (brand == "BMW") {
		result = new BMW(model);
	}
	return result;
}

int main() {
	std::vector <car*> cars;
	std::ifstream fin;
	fin.open("C:\\chzh.txt");
	if (fin.is_open()) {
		std::string line;
		while (getline(fin, line)) {
			std::string brand, model;
			brand = line.substr(0, line.find(" "));
			model = line.substr(line.find(" ") + 1);
			if (brand == "Mercedes") {
				cars.push_back(new Mercedes(model));
			}
			else if (brand == "BMW") {
				cars.push_back(new BMW(model));
			}
			else if (brand == "Toyota") {
				cars.push_back(new Toyota(model));
			}
		}
		fin.close();
	}
	else {
		std::cout<< "Unable to open file"<< std::endl;
		return 0;
	}
	for (int i = 0; i < cars.size(); i++)
	{
		delete cars[i];
	}
}
