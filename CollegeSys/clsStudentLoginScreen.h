#pragma once
#include <iostream> 
#include "clsInputValidate.h"
#include "clsStudent.h"
#include "clsStudentMainScreen.h"
#include "clsScreen.h"

using namespace std;

class clsStudentLoginScreen : clsScreen
{
private:
	static void _Login()
	{
		cout << "\n\tEnter Your ID: ";
		string ID = clsInputValidate::ReadString();

		cout << "\n\tEnter Your Password: ";
		string Password = clsInputValidate::ReadString();

		clsStudent Student = clsStudent::Find(ID, Password);

		while (Student.IsEmpty())
		{
			cout << "\n\tWrong ID or Password, Try again!\n";

			cout << "\n\tEnter Your ID: ";
			ID = clsInputValidate::ReadString();

			cout << "\n\tEnter Your Password: ";
			Password = clsInputValidate::ReadString();
			Student = clsStudent::Find(ID, Password);
		}

		CurrentStudent = Student;

	}
public:
	static void ShowStudentLoginScreen()
	{
		_DrawScreenHeader("Student Login");
		_Login();
		system("cls");
		clsStudentMainScreen::ShowStudentMainScreen();

	}
};

