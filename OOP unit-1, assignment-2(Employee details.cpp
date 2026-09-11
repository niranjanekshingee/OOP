#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int idno;
    string mob;

public:
    void input()
    {
        cout << "\n----- Enter Employee Details -----\n";

        cout << "Enter Name           : ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter ID Number      : ";
        cin >> idno;

        cout << "Enter Mobile Number  : ";
        cin >> mob;
    }

    void display()
    {
        cout << "\n----- Employee Details -----\n";
        cout << "Name          : " << name << endl;
        cout << "ID Number     : " << idno << endl;
        cout << "Mobile Number : " << mob << endl;
    }
};

int main()
{
    Employee e1;

    e1.input();
    e1.display();

    return 0;
}
