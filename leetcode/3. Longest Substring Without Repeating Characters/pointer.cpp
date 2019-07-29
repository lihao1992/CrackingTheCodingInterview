#include <iostream>

using namespace std;

int main(){

    int a = 1;
    int *p = &a;
    int **ptr = &p;

    
    cout << "a is" << a << endl;
    cout << "*p is" << *p << endl;
    cout << "&a is " << &a << endl;
    cout << "&p is" << &p << endl;
    cout << "*&p is" << *&p << endl;
    cout << "p is " << p << endl;


    return 0;

}