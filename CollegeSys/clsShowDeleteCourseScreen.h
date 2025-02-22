#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsStudent.h"

using namespace std;

class clsShowDeleteCourseScreen : public clsScreen
{
private:
	static void _Delete()
	{
		cout << "\n\t Enter Course Name: ";
		string CourseName = clsInputValidate::ReadString();

		vector<string> vCourses = CurrentStudent.RegisteredCourses;
		vector<string> NewCourses;
		for (string& course : vCourses)
		{
			if (CourseName != course)
			{
				NewCourses.push_back(course);
			}
		}

		CurrentStudent.RegisteredCourses = NewCourses;
		CurrentStudent.DeleteCourse();

		bool DeleteStatus = CurrentStudent.Save();

		if (DeleteStatus) cout << "\n\t Course Deleted Successfully\n";
		else cout << "\n\t Course not Deleted Successfully\n";

	}
public:
	static void ShowDeleteCourseScreen()
	{
		_DrawScreenHeader("Delete Course");
		_Delete();
	}
};

