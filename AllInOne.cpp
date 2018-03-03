#include "Header.h"

AllInOne::AllInOne(char* s1, int a, int b, char* s2, int c, bool b1, bool b2):
DesktopComputer(s1, a, b, s2, c)
{
	touchscreen = b1;
	ssd = b2;
}
//-------------------------------------------------------------------------------------------------
AllInOne::AllInOne(const AllInOne& obj):
DesktopComputer(obj)
{
	touchscreen = obj.touchscreen;
	ssd = obj.ssd;
}
//-------------------------------------------------------------------------------------------------
AllInOne::~AllInOne()
{
	//cout <<"Destructor of the class DesktopComputer"<< endl;		
}
//-------------------------------------------------------------------------------------------------
AllInOne& AllInOne::operator=(AllInOne& obj)
{
	if (this != &obj)
	{
		setModel(obj.getModel());
		setCost(obj.getCost());
		setDisplaySize(obj.getDisplaySize());
		setProcessor(obj.getProcessor());
		setUsbAmmount(obj.getUsbAmmount());
		touchscreen = obj.touchscreen;
		ssd = obj.ssd;
	}
	return *this;
}
//------------------------------------------------------------------------------------------------------
void AllInOne::setTouchscreen(bool b)
{
	touchscreen = b;
}
//------------------------------------------------------------------------------------------------------
void AllInOne::setSsd(bool b)
{
	ssd = b;
}
//-------------------------------------------------------------------------------------------------------
bool AllInOne::getTouchscreen()
{
	return touchscreen;
}
//-------------------------------------------------------------------------------------------------------
bool AllInOne::getSsd()
{
	return ssd;
}
//-------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, AllInOne& obj)
{
	out << dynamic_cast <DesktopComputer&> (obj);
	out <<"Touchscreen: ";
	if (obj.touchscreen) out <<"yes"<< endl;
	else out <<"no"<< endl;
	out <<"SSD: ";
	if (obj.ssd) out <<"yes"<< endl;
	else out <<"no"<< endl;

	return out;
}
//-------------------------------------------------------------------------------------------------------
istream& operator>>(istream& in, AllInOne& obj)
{
	in >> dynamic_cast<DesktopComputer&>(obj);

	int a;

	cout <<"\nDoes this model have touchscreen? (1 - Yes, 2 - No)";
	in >> a;
	if (--a) obj.touchscreen = false;
	else obj.touchscreen = true;

	cout <<"\nDoes this model have ssd? (1 - Yes, 2 - No)";
	in >> a;
	if (--a) obj.ssd = false;
	else obj.ssd = true;

	return in;
}