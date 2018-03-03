#include "Exception.h"

Exception::Exception(char* s, int a)
{
	message = new char[strlen(s) + 1];
	strcpy(message, s);
	error_code = a;
}
//-----------------------------------------------------------------------------
Exception::Exception(const Exception& obj)
{
	message = new char[strlen(obj.message) + 1];
	strcpy(message, obj.message);
	error_code = obj.error_code;
}
//-----------------------------------------------------------------------------
Exception::~Exception()
{
	delete[] message;
}
//-----------------------------------------------------------------------------
void Exception::setMessage(char* s)
{
	message = new char[strlen(s) + 1];
	strcpy(message, s);
}
//-----------------------------------------------------------------------------
void Exception::setErrorCode(int a)
{
	error_code = a;
}
//-----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Exception& obj)
{
	out << obj.message <<" "<< obj.error_code <<": ";
	return out;
}