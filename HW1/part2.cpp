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
	float n;
public:
	File_(float input_n) {
		n = input_n;
	}

	void print_info() {
		std::cout << n << std::endl;
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

float e=1e-8;
float sqrt_(int n_times,float x){
    if(n_times==0) 
    {
        return 1;
    }
    return 0.5*(sqrt_(n_times-1,x) + x/sqrt_(n_times-1,x));
}

float squared_(float x,int n_times)
{
    float result_ = sqrt_(n_times, x);
    if (fabs(result_*result_ - x) < e) 
    {
        return result_;
    }
    return squared_(x,n_times+1);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Please input the file name!" << std::endl;
	}
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

    vector<int> arr = {2,5,10,20,30,40,50};
	for (auto x : file_) {
        x.print_info();

	}

    for (auto it : arr){
        cout << sqrt_(it,100);
        cout << "\n\n";
    }

    for (auto it : arr){
        cout << sqrt_(it,100)*sqrt_(it,100);
        cout << "\n\n";
    }
	return EXIT_SUCCESS;
}


