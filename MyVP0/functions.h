

#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
void input(istream& in,T &num, T min, T max,string caption)
{
    bool goodInput{false};
    while (!goodInput)
    {

        std::cout << caption << endl;
        in >> num;
        std::system("cls");
    if (cin.fail())
    {
        cin.clear();

        cin.ignore(32767,'\n');

        cout << "it must be a number" << endl;
//        cin.ignore(32767,'\n');
    }
    else if (num<min||num>max)
    {
        cout << "Number must be more than " << min << " and less than " << max << endl;
    }
    else
    {
        goodInput = true;
    }
    };
//    if (in.fail())
//    {
//        in.ignore(32767,'\n');
//    };
    in.ignore(32767,'\n');
}
