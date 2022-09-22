#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include<bits/stdc++.h>
#include <stdio.h>
#include <bitset>
using namespace std;

using std::string;
using std::vector;


class File_ {
private:
	uint32_t n;
public:
	File_(uint32_t input_n) {
		n = input_n;
	}

	void print_info() {
		std::cout << n << std::endl;
	}

    uint32_t euler_lopital(){
        uint32_t num1 = (exp(n)-1)/n;
        return num1;
    }

    uint32_t euler_cond(){
        uint32_t y = exp(n);
        if(y==1){
            uint32_t z = 1;
            return z;
        }
        else{
            uint32_t z = (y-1)/log(y);
            return z;
        }
    }

};

void readfile(vector<File_> &file_, string &filename) {
	std::ifstream infile(filename);
	if (infile.is_open()) {
		float n;
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
        cout << "The value "; 
		x.print_info();
        cout<< "The euler lopital value is : " << x.euler_lopital();
		cout << "\n";
        cout<< "The euler condition value is : " << x.euler_cond();
		cout << "\n\n";



	}

	return EXIT_SUCCESS;
}