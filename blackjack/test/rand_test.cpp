#include<cstdlib>
#include<ctime>
#include<iostream>


using namespace std;

int main()
{
    int a, b; // randon numbers
    srand(time(NULL));
    a = rand() % 10;
    b = rand() % 10;

    cout << "a = " << a 
        << "\nb = " << b << endl;
}