#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Car {
	string brand, model, body_style;
	int weight, max_speed;
	double price;

	bool is_valid_string(string* str, int size = 20) {
		bool is_valid = true;
		for (int i = 0; i < size; i++) {
			if ((*str)[i] < 65 || ((*str)[i] > 90 && (*str)[i] < 97) || (*str)[i] > 122 || (*str)[i] == 32) {
				return is_valid;
			}
		}
		return is_valid;
	}

	void title_case(string* str, int size) {
		char ch;
		if ((*str)[0] >= 97 && (*str)[0] <= 122) {
			ch = (*str)[0] - 32;
			(*str)[0] = ch;

		}
		for (int i = 1; i < size; i++) {
			if ((*str)[i] >= 65 && (*str)[i] <= 90) {
				ch = (*str)[i] + 32;
				(*str)[i] = ch;
			}
		}
	}
	void lower_case(string* str, int size) {
		for (int i = 0; i < size; i++) {
			if ((*str)[i] >= 65 && (*str)[i] <= 90) {
				(*str)[i] += 32;
			}
		}
	}

public:

	void set_brand(string brand) {
		int size = brand.size();
		if (size >= 3 && size <= 15 && is_valid_string(&brand, size)) {
			this->title_case(&brand, size);
			this->brand = brand;
		}
		else {
			cout << "Invalid brand name" << endl;
		}
	}
	void set_model(string model) {
		int size = model.size();
		if (size >= 3 && size <= 15) {
			this->model = model;
		}
		else {
			cout << "model name is too long" << endl;
		}
	}



	void set_body_style(string size, string type) {
		int size_size = size.size();
		int size_type = type.size();
		if (size_size >= 5 && size_size <= 10 && size_type >= 3 && size_type <= 5) {
			this->lower_case(&size, size_size);
			this->lower_case(&type, size_type);
			bool can_set_style = false;
			if (size == "subcompact" || size == "compact" || size == "midsize" || size == "large") {
				if (type == "car" || type == "suv") {
					can_set_style = true;
				}
			}
			else if (size == "smart" && type == "car") {
				can_set_style = true;
			}
			else if (size == "half-ton" && type == "truck") {
				can_set_style = true;
			}
			else {
				cout << "Invalid body style" << endl;
			}
			if (can_set_style) {
				if (type == "suv") {
					type = "SUV";
				}
				else {
					type[0] -= 32;
				}
				size[0] -= 32;
				this->body_style = size + " " + type;
			}
		}
		else {
			cout << "Invalid body style" << endl;
		}


	}

	void set_weight(int w) {
		if (w > 0) {
			this->weight = w;
		}
		else {
			cout << "Invalid weight" << endl;
		}
	}
	int get_weight() {
		return this->weight;
	}
	void set_max_speed(int m_s) {
		if (m_s >= 150 && m_s < +350) {
			this->max_speed = m_s;
		}
		else {
			cout << "Invalid maximum speed" << endl;
		}
	}
	void get_all_data() {
		cout << "Car model: " << this->brand << " " << this->model << endl;
		cout << "Size: " << this->body_style << endl;
		cout << "Weight: " << this->weight << endl;
	}

};

class Parking {
	Car car;
	int PSN;

public:

	int gen_rand(int start, int end) {
		return rand() % (end - start) + start;
	}

	int get_PCN() {
		int weight = this->car.get_weight();
		if (weight <= 2700) {
			return gen_rand(1, 100);
		}
		else if (weight > 2700 && weight <= 4500) {
			return gen_rand(101, 160);
		}
		else {
			return gen_rand(161, 200);
		}
	};

	void get_car_data() {
		car.get_all_data();
	}
	void set_car_brand(string brand) {
		car.set_brand(brand);
	}
	void set_car_body_style(string size, string type) {
		car.set_body_style(size, type);
	}
	void set_car_model(string model) {
		car.set_model(model);
	}
	void set_car_weigth(int w) {
		car.set_weight(w);
	}
};


int main() {
	srand(time(nullptr));
	string brand = "honda";
	string model = "CR-V";
	string body_size = "compact";
	string body_type = "suv";

	Parking park;
	park.set_car_brand(brand);
	park.set_car_body_style(body_size, body_type);
	park.set_car_model(model);
	park.set_car_weigth(1600);
	park.get_car_data();
	cout << "Your parking space number is " << park.get_PCN() << endl;
	return 0;
}