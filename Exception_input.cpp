#include "Exception.h"

ExceptionInput::ExceptionInput(char* s1, int a, char* s2):
Exception(s1, a)
{
	error_type = new char[strlen(s2) + 1];
	strcpy(error_type, s2);
}
//-----------------------------------------------------------------------------
ExceptionInput::ExceptionInput(const ExceptionInput& obj):
Exception(obj)
{
	error_type = new char[strlen(obj.error_type) + 1];
	strcpy(error_type, obj.error_type);
}
//-----------------------------------------------------------------------------
ExceptionInput::~ExceptionInput()
{
	delete[] error_type;
}
//-----------------------------------------------------------------------------
void ExceptionInput::setErrorType(char* s)
{
	error_type = new char[strlen(s) + 1];
	strcpy(error_type, s);
}
//-----------------------------------------------------------------------------
ostream& operator<<(ostream& out, ExceptionInput& obj)
{
	out << dynamic_cast<Exception&>(obj);
	out << obj.error_type << endl;
	return out;
}
//-----------------------------------------------------------------------------
ExceptionInput& ExceptionInput::fill(char* s1, int a, char* s2)
{
	setMessage(s1);
	setErrorCode(a);
	setErrorType(s2);

	return *this;
}
//-----------------------------------------------------------------------------
void str_check(char* temp)
{
	bool flag;
	ExceptionInput input_error;

	do
	{
		try
		{
			flag = false;

			if(temp[0] < 'A' || temp[0] > 'Z')
				throw input_error.fill("Error", 11, "Wrong input! The first letter must be zagl.");
			
			for (int i = 0; temp[i]; ++i)
				{
					/*if (temp[i] == ' ')
					{
						input_error.fill("Error", 16, "Wrong input! Don't use spaces.");
						throw input_error;
					} */
					if (temp[i] < 'A' || temp[i] > 'Z' && temp[i] < 'a' || temp[i] > 'z')
					{
						input_error.fill("Error", 13, "Wrong input! Don't use digits. Write in English language.");
						throw input_error;
					}
				}
		}
		catch(ExceptionInput)
		{
			flag = true;
			cout << input_error;
		}
		if (flag)
		{
			cout <<"Repeat your input..."<< endl;
			cin.getline(temp, 50);
		}
	} while(flag);
}