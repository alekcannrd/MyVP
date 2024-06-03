

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

        try
        {
            std::cout << caption << endl;
            in >> num;
            std::system("cls");

            if (cin.fail())
            {
                throw 1;
            }
            else if (num<min||num>max)
            {
                throw 2;
            }

            else
            {
                goodInput = true;
            }
        }
        catch (int id)
        {
            if (id == 1)
            {
                cin.clear();

                cin.ignore(32767,'\n');

                cout << "it must be a number" << endl;
            }
            else if (id == 2)
            {
                cout << "Number must be more than " << min << " and less than " << max << endl;
            }

        }
    };
//    if (in.fail())
//    {
//        in.ignore(32767,'\n');
//    };
    in.ignore(32767,'\n');
}
