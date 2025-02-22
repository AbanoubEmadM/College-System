#pragma once
#include <iostream>
#include "CurrentStudent.h"
#include "clsScreen.h"
#include "clsShowAllCoursesScreen.h"
#include "clsShowRegisteredCourses.h"
#include "clsShowRegisterNewCourseScreen.h"
#include "clsShowDeleteCourseScreen.h"

using namespace std;

class clsStudentMainScreen : clsScreen
{
private:
    enum enStudentOptions { eAllCourses = 1 ,eRegisterCourse = 2, eShowRegisteredCourse = 3, eDeleteCourse = 4};

    static int _ReadMainMenuOption()
    {
        cout << "Enter Your Choice: ";
        int Option = clsInputValidate::ReadIntNumber();
        return Option;
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        system("cls");
        ShowStudentMainScreen();
    }
    static void _ShowAllCourses()
    {
        clsShowAllCoursesScreen::ShowAllCourses();
    }
    static void _RegisterNewCourse()
    {
        clsShowRegisterNewCourseScreen::ShowRegisterNewCourseScreen();
    }
    static void _ShowMyCourses()
    {
        clsShowRegisteredCourses::ShowRegisteredCoursesScreen();
    }
    static void _DeleteCourse()
    {
        clsShowDeleteCourseScreen::ShowDeleteCourseScreen();
    }
    static void _PreformMainMenuOption(enStudentOptions StudentOption)
    {
        switch (StudentOption)
        {
        case enStudentOptions::eAllCourses:
            system("cls");
            _ShowAllCourses();
            _GoBackToMainMenue();
            break;
        case enStudentOptions::eRegisterCourse:
            system("cls");
            _RegisterNewCourse();
            _GoBackToMainMenue();
            break;
        case enStudentOptions::eShowRegisteredCourse:
            system("cls");
            _ShowMyCourses();
            _GoBackToMainMenue();
            break;
        case enStudentOptions::eDeleteCourse:
            system("cls");
            _DeleteCourse();
            _GoBackToMainMenue();
            break;

        }

    }

public:
	static void ShowStudentMainScreen() 
	{
		_DrawScreenHeader("Student Main Menu");
		cout << setw(37) << left << "" << "\t[1] Show All Courses.\n";
        cout << setw(37) << left << "" << "\t[2] Register New Course.\n";
		cout << setw(37) << left << "" << "\t[3] Show Registered Courses.\n";
        cout << setw(37) << left << "" << "\t[4] Delete Course.\n";
        _PreformMainMenuOption((enStudentOptions)_ReadMainMenuOption());

	}
};

