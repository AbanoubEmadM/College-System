#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
private:
	string _Name;
	string _PhoneNumber;
	string _Email;

public:
	clsPerson(string Name, string Email, string PhoneNumber)
	{
		_Name = Name;
		_PhoneNumber = PhoneNumber;
		_Email = Email;
	}

	string GetName()
	{
		return _Name;
	}
	void SetName(string name)
	{
		_Name = name;
	}
	__declspec(property(get = GetName, put = SetName)) string Name;

	string GetEmail()
	{
		return _Email;
	}
	void SetEmail(string email)
	{
		_Email = email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	string GetPhoneNumber()
	{
		return _PhoneNumber;
	}
	void SetPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}
	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string PhoneNumber;

};

