#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "CurrentStudent.h"

using namespace std;
class clsStudent : public clsPerson
{
private:
	string _GPA;
	string _ID;
	string _Password;
	int _CurrentLevel;
	int _Permissions;
	vector<string> _RegisteredCourses;

	enum enMode {Empty = 0, Update = 1, Add = 2};

	enum Prerequisite {
		ALL = -1,
		INTRO_TO_PROGRAMMING    = 1,
		DISCRETE_MATH           = 2,
		MATH1                   = 4,
		DATA_STRUCTURES         = 8,
		MATHEMATICS_FOR_CS      = 16,
		MATH2                   = 32,
		COMPUTER_ARCHITECTURE   = 64,
		MATH3                   = 128,
		LOGIC_DESIGN            = 256,
		MATH4                   = 512,
		PROBABILITY_STATISTICS  = 1024,
		ALGORITHMS              = 2048,
		OPERATING_SYSTEMS       = 4096,
		COMPUTER_NETWORKS       = 8192,
		CYBER_SECURITY          = 16384,
		ARTIFICIAL_INTELLIGENCE = 32768,
		STATISTICS              = 65536,
		MICROPROCESSORS         = 131072,
		EMBEDDED_SYSTEMS        = 262144
};

	enMode _Mode;

	static clsStudent _ConvertRecordLineToStudent(string Line)
	{
		vector<string> vData = clsString::Split(Line, "#//#");
		vector<string> RegisteredCourses = clsString::Split(vData[8], "-");
		return clsStudent
		(enMode::Update ,vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stod(vData[6]), (Prerequisite)16384, RegisteredCourses);
	}

	string _ConvertStudentToRecordLine(clsStudent Student)
	{
		string Data;
		Data = Student.Name + "#//#";
		Data += Student.Email + "#//#";
		Data += Student.Password + "#//#";
		Data += Student.PhoneNumber + "#//#";
		Data += Student.ID + "#//#";
		Data += Student.GPA + "#//#";
		Data += to_string(Student.CurrentLevel) + "#//#";
		Data += to_string(Student.Permissions) + "#//#";
	
		for (string& course : Student.RegisteredCourses)
		{
			Data += course + "-";
		}
		
		return Data.substr(0, Data.length() - 1);
	}

	static clsStudent _EmptyStudent()
	{
		return clsStudent(enMode::Empty, "", "", "", "", "", "", 0, 0, {});
	}
	static vector<clsStudent> _LoadAllStudents()
	{
		vector<clsStudent> vStudents;
		fstream MyFile;
		MyFile.open("Students.txt", ios::in);
		string Line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsStudent Student = _ConvertRecordLineToStudent(Line);
				vStudents.push_back(Student);
			}
		}
		MyFile.close();
		return vStudents;
	}
	void _SaveUsersDataToFile(vector <clsStudent> vStudents)
	{

		fstream MyFile;
		MyFile.open("Students.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsStudent Student : vStudents)
			{
				DataLine = _ConvertStudentToRecordLine(Student);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsStudent> vStudents = _LoadAllStudents();
		for (clsStudent& Student : vStudents)
		{
			if (Student.ID == ID)
			{
				Student = *this;

				break;
			}
		}

		_SaveUsersDataToFile(vStudents);

	}

public:
	clsStudent(enMode Mode , string Name, string Email, string Password, string PhoneNumber, string ID, string GPA, int CurrentLevel, int Permission, vector<string> RegisteredCourses)
		: clsPerson(Name, Email, PhoneNumber)
	{
		_Mode = Mode;
		_GPA = GPA;
		_Password = Password;
		_ID = ID;
		_CurrentLevel = CurrentLevel;
		_Permissions = Permission;
		_RegisteredCourses = RegisteredCourses;
	}
	
	string GetGPA()
	{
		return _GPA;
	}

	void SetGPA(string gpa)
	{
		_GPA = gpa;
	}

	__declspec(property(get = GetGPA, put = SetGPA)) string GPA;

	string GetID()
	{
		return _ID;
	}

	void SetID(string id)
	{
		_ID = id;
	}

	__declspec(property(get = GetID, put = SetID)) string ID;

	int GetCurrentLevel()
	{
		return _CurrentLevel;
	}

	void SetCurrentLevel(int lvl)
	{
		_CurrentLevel = lvl;
	}

	__declspec(property(get = GetCurrentLevel, put = SetCurrentLevel)) int CurrentLevel;

	int GetPermissions()
	{
		return _Permissions;
	}

	void SetPermissions(int permissions)
	{
		_Permissions = permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	string GetPassword()
	{
		return _Password;
	}

	void setPassword(string password)
	{
		_Password = password;
	}

	__declspec(property(get = GetPassword, put = setPassword)) string Password;

	vector<string> GetRegisteredCourses()
	{
		return _RegisteredCourses;
	}

	void SetRegisteredCourses(vector<string> RegisteredCourses)
	{
		_RegisteredCourses = RegisteredCourses;
	}

	__declspec(property(get = GetRegisteredCourses, put = SetRegisteredCourses)) vector<string> RegisteredCourses;

	bool IsEmpty()
	{
		return _Mode == enMode::Empty;
	}

	static clsStudent Find(string id)
	{
		fstream MyFile;
		MyFile.open("Students.txt", ios::in); // read
		string Line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsStudent Student = _ConvertRecordLineToStudent(Line);
				if (Student.ID == id)
				{
					MyFile.close();
					return Student;
				}
			}
		}
		MyFile.close();
		return _EmptyStudent();
	}

	static clsStudent Find(string id, string password)
	{
		fstream MyFile;
		MyFile.open("Students.txt", ios::in); // read
		string Line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsStudent Student = _ConvertRecordLineToStudent(Line);
				if (Student.ID == id && Student.Password == password)
				{
					MyFile.close();
					return Student;
				}
			}
		}
		MyFile.close();
		return _EmptyStudent();
	}

	static enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	 bool Save()
	{

		switch (_Mode)
		{
		case enMode::Empty:
		{
			if (IsEmpty())
			{
				return false;
			}
		}

		case enMode::Update:
		{
			_Update();
			return true;
		}
		}

	}
	 void AddCourse()
	 {
		 _Mode = enMode::Update;
	 }

	 void DeleteCourse()
	 {
		 _Mode = enMode::Update;
		 Save();
	 }

};

