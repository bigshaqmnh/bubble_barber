#include <iostream>
#include <cstring>

using namespace std;

class Exception
{
public:
	Exception(char* = "", int = 0);
	Exception(const Exception&);
	~Exception();

	void setMessage(char*);
	void setErrorCode(int);

	friend ostream& operator<<(ostream&, const Exception&);

private:
	char* message;
	int error_code;
};

class ExceptionInput:public Exception
{
public:
	ExceptionInput(char* = "", int = 0, char* = "");
	ExceptionInput(const ExceptionInput&);
	~ExceptionInput();

	void setErrorType(char*);

	ExceptionInput& fill(char*, int, char*);

	friend ostream& operator<<(ostream&, ExceptionInput&);

private:
	char* error_type;
};

void str_check(char*);