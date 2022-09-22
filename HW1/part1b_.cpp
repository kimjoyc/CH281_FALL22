
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<cmath>
#include <iomanip> 

using std::string;
using std::vector;

using namespace std;

class File_ {
private:
	uint32_t n; 
	uint32_t n2;
public:
	File_(uint32_t input_n, uint32_t input_n2) {
		n = input_n;
		n2 = input_n2;
	}

	void print_info() {
		std::cout << n << std::endl;
	}

    uint32_t n_goes_inf(){
        uint32_t num1 = pow(log(1+1/n),n);
        return num1;
    }
	uint32_t x_goes_0(){
        uint32_t num1 = log(1+n2);
        return num1;
    }
};

void readfile(vector<File_> &file_, string &filename) {
	std::ifstream infile(filename);
	if (infile.is_open()) {
		int n;
		float n2;
		while (infile >> n >> n2) {

			File_ new_file_(n,n2);
			file_.push_back(new_file_);
		}
		infile.close();
	} else {
		throw std::invalid_argument("Can't open file to read.");
	}
}

int main(int argc, char* argv[]) {

	vector<File_> file_;
	string filename = argv[1];
	try {
		readfile(file_, filename);
	}
	catch (std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		std::cout << "Something wrong happened!" << std::endl;
		return EXIT_FAILURE;
	}

	for (auto x : file_) {
		cout << "The value is : ";
		x.print_info();
        cout << "The limit as x goes to 0 : " << x.x_goes_0();
		cout << "\n";
		cout << "The limit as n goes to inf : " << x.n_goes_inf();
        cout << "\n\n";

	}

	return EXIT_SUCCESS;
}