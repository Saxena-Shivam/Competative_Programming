#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class binary
{
    string s;

public:
    void read()
    {
        cout << "Enter a binary number: ";
        cin >> s;
    }

    void chk_bin()
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) != '0' && s.at(i) != '1')
            {
                cout << "\nIncorrect binary number format... program will quit";
                exit(0);
            }
        }
    }

    void ones()
    {
        chk_bin();
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '0')
                s.at(i) = '1';
            else
                s.at(i) = '0';
        }
    }

    void displayones()
    {
        ones();
        cout << "\nThe 1's complement of the binary number is: " << s;
    }
};

int main()
{
    binary b;
    b.read();
    b.displayones();
    return 0;
}
