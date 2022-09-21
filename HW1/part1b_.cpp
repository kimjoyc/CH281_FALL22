
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
	int n;
public:
	File_(int input_n) {
		n = input_n;
	}

	void print_info() {
		std::cout << n << std::endl;
	}

    float euler_pro(){
        float num1 = pow(log(1+1/n),n);
        return num1;
    }
};

void readfile(vector<File_> &file_, string &filename) {
	std::ifstream infile(filename);
	if (infile.is_open()) {
		int n;
		while (infile >> n) {

			File_ new_file_(n);
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
		x.print_info();
        cout << "\n\n";
        int y= x.euler_pro();
        cout << setprecision(8);
        cout << y;
        cout << "\n\n";

	}

	return EXIT_SUCCESS;
}