#include<iostream>
using namespace std;

void arr_print(int* arr, int n)
{
    for(int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
}

void gen_recur(int x, int* arr, int sum,int index)
{
   if (sum == x)
   {
      arr_print(arr, index);
      return;
   }

   int num = 1;
   while (num <= x - sum && (index == 0 ||num <= arr[index - 1]))
   {
       arr[index] = num;
       gen_recur(x, arr, sum + num,index + 1);
       num++;
   }
}
void gen(int x)
{ 
    int arr[x];
    gen_recur(x, arr, 0, 0);
}
 
int main(int argc, char *argv[])
{
    int x;
    cout << "Number : ";
    cin >> x;

    gen(x);
    return 0;
}