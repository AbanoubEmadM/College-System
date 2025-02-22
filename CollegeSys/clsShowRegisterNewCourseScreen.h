#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudent.h"

using namespace std;

class clsShowRegisterNewCourseScreen : public clsScreen
{
private:
	static void _AddNewCourse()
	{
		cout << "\n\t Enter Course Name: ";

		string CourseName = clsInputValidate::ReadString();
		vector<string> vCourses = CurrentStudent.RegisteredCourses;

		vCourses.push_back(CourseName);

		CurrentStudent.RegisteredCourses = vCourses;

		CurrentStudent.AddCourse();

		bool AddStatus = CurrentStudent.Save();

		if (AddStatus) cout << "\n\t Course Add Successfully\n";
		else cout << "\n\t Course not Add Successfully\n";

	}

public:
	static void ShowRegisterNewCourseScreen()
	{
		_DrawScreenHeader("Register New Course");
		_AddNewCourse();
	}
};

