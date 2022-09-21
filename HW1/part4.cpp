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
 
void bin_conv(int l, int m)
{

    int k;
    for (k = m - 1; k >= 0; k--) {
 
        if ((l>> k) & 1)
            cout << "1";
        else
            cout << "0";
    }
}
 
typedef union {
    float f;
    struct
    {

        unsigned int mantissa : 52;
        unsigned int exponent : 11;
        unsigned int sign : 1;
 
    } raw;
} float_;

void conv_IEEE_64bit(float_ int2bconv)
{

 
    cout << int2bconv.raw.sign << " - ";
    bin_conv(int2bconv.raw.exponent, 11);
    cout << " - ";
    bin_conv(int2bconv.raw.mantissa, 52);
    cout << "\n";
}
 
int main()
{
    float_ int2bconv;
    int2bconv.f = 10;
    cout << int2bconv.f << " is : " << endl;
    conv_IEEE_64bit(int2bconv);
    return 0;
}
 