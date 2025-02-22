#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include  "clsString.h"
using namespace std;

class clsCourse
{
private:
	string _CourseName;
	int _CourseHours;
	vector<string> _CoursePreq;

	static clsCourse _ConvertRecordLineToCourse(string Line)
	{
		vector<string> vData = clsString::Split(Line, "#//#");
		vector<string> preq = clsString::Split(vData[2], "-");
		return clsCourse(vData[0], stoi(vData[1]), preq);
	}
	

	static vector<clsCourse> _LoadAllCourses()
	{
		vector<clsCourse> vCourses;
		fstream MyFile;
		MyFile.open("Courses.txt", ios::in);
		string Line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCourse Course = _ConvertRecordLineToCourse(Line);
				vCourses.push_back(Course);
			}
		}
		MyFile.close();
		return vCourses;
	}


public:
	clsCourse(string CourseName, int CourseHours, vector<string> CoursePreq)
	{
		_CourseName = CourseName;
		_CourseHours = CourseHours;
		_CoursePreq = CoursePreq;
	}

	// Getters
	string getCourseName() 
	{
		return _CourseName; 
	}
	int getCourseHours()
	{
		return _CourseHours; 
	}
	vector<string> getCoursePreq()
	{ 
		return _CoursePreq; 
	}

	// Property declarations
	__declspec(property(get = getCourseName)) string CourseName;
	__declspec(property(get = getCourseHours)) int CourseHours;
	__declspec(property(get = getCoursePreq)) vector<string> CoursePreq;

	static vector<clsCourse> GetAllCourses()
	{
		return _LoadAllCourses();
	}

	static void AddCourse(string CourseName)
	{

	}
};

