#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsStudentLoginScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsMainScreen : clsScreen
{
private:
    enum enLogin    
    {
        eStudentLogin = 1,
        eProfLogin = 2
    };
    static void _StudentLoginScreen()
    {
        clsStudentLoginScreen::ShowStudentLoginScreen();
    }
    static int _ReadMainMenuOption()
    {
        cout << "\n\tEnter Your Choice: ";
        int Option = clsInputValidate::ReadIntNumber();
        return Option;
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainScreen();
    }

    static void _PreformMainMenuOption(enLogin Login)
    {
        switch (Login)
        {
            case enLogin::eStudentLogin:
                system("cls");
                _StudentLoginScreen();
                _GoBackToMainMenue();
                break;
        }
    }
public:
	static void ShowMainScreen()
	{
        system("cls");
        _DrawScreenHeader("Main Screen");

        cout << setw(37) << left << "" << "\t[1] Login as Student.\n";
        cout << setw(37) << left << "" << "\t[2] Login as Prof.\n";
        _PreformMainMenuOption((enLogin)_ReadMainMenuOption());
	}
};

