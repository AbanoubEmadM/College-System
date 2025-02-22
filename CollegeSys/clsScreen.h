#pragma once
#include <iostream>
#include "CurrentStudent.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t  " << Title;
        if (!CurrentStudent.IsEmpty())
            cout << "\n\n\t\t\t\t\t\t  Hello " << CurrentStudent.Name << " - " << CurrentStudent.ID;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
    }

};