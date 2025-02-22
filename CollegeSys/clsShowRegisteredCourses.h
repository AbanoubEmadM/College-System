#pragma once
#include <iostream>
#include "CurrentStudent.h"
#include "clsScreen.h"
#include "clsShowAllCoursesScreen.h"

using namespace std;

class clsShowRegisteredCourses : public clsScreen
{
private:
	static void _GetRegisteredCourses()
	{
		vector<string> RegisteredCourses = CurrentStudent.GetRegisteredCourses();

		for (string& course : RegisteredCourses)
		{
			cout << "| " << setw(25) << left << course << "\t\n";
		}
	}
public:
	static void ShowRegisteredCoursesScreen()
	{
		_DrawScreenHeader("Registered Courses");
		cout << "\n";
		cout << "------------------------------------------\n";
		cout << "| " << setw(25) << left << "Course Name"
			<< "\n";
		cout << "------------------------------------------\n";

		_GetRegisteredCourses();
	}
};

