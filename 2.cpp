#include <iostream>
#include <exception>
using namespace std;
struct MyException : public exception {
    const char * what () const throw () {
        return "C++ Exception";
    }
};
int main()
{
    char op;
    float num1, num2;
    cout << "Enter your operation + or - or * or /:\n";
    cin >> op;
    cout << "Enter first numbers:\n";
    cin >> num1;
    try {
        if (cin.fail()) throw MyException();
    }catch(MyException& e) {
        cout << "Enter  a  number,  not  a symbol\n" << endl;
        cout << e.what() << endl;
        return 0;
    }
    cout << "Enter second numbers:\n";
    cin >> num2;
    try {
        if (cin.fail()) throw MyException();
    }catch(MyException& e) {
        cout << "Enter  a  number,  not  a symbol\n" << endl;
        cout << e.what() << endl;
        return 0;
    }
    switch(op)
    {
        case '+':
            cout << num1+num2;
            break;
        case '-':
            cout << num1-num2;
            break;
        case '*':
            cout << num1*num2;
            break;
        case '/':
            if (num2!=0){
                cout << num1/num2;
            }
            try {
                if (num2 == 0) throw MyException();
            }catch(MyException& e) {
                cout << "Don't divide by zero\n" << endl;
                cout << e.what() << endl;
            }
            break;
        default:
            cout << "Operation not find";
            break;
    }
    return 0;
}
