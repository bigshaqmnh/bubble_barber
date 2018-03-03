#include "Header.h"

DesktopComputer::DesktopComputer(char* s1, int a, int b, char* s2, int c):
CalculatingMachine(s1, a, b)
{
	strcpy(processor, s2);
	usb_ammount = c;
}
//--------------------------------------------------------------------------------------------
DesktopComputer::DesktopComputer(const DesktopComputer& obj):
CalculatingMachine(obj)
{
	strcpy(processor, obj.processor);
	usb_ammount = obj.usb_ammount;
}
//--------------------------------------------------------------------------------------------
DesktopComputer::~DesktopComputer()
{
	//cout <<"Destructor of the class DesktopComputer"<< endl;	
}
//---------------------------------------------------------------------------------------------
void DesktopComputer::setProcessor(char* s)
{
	strcpy(processor, s);
}
//--------------------------------------------------------------------------------------------
void DesktopComputer::setUsbAmmount(int a)
{
	usb_ammount = a;
}
//--------------------------------------------------------------------------------------------
char* DesktopComputer::getProcessor()
{
	return processor;
}
//--------------------------------------------------------------------------------------------
int DesktopComputer::getUsbAmmount()
{
	return usb_ammount;
}
//--------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, DesktopComputer& obj)
{
	out << dynamic_cast <CalculatingMachine&> (obj);
	out <<"Processor model: "<< obj.processor << endl;
	out <<"Ammount of USB: "<< obj.usb_ammount << endl;

	return out;
}
//--------------------------------------------------------------------------------------------
istream& operator>>(istream& in, DesktopComputer& obj)
{
	in >> dynamic_cast<CalculatingMachine&>(obj);

	cout <<"\nEnter processor model: ";
	in.ignore();
	in.getline(obj.processor, 30);
	str_check(obj.processor);

	cout <<"\nEnter ammount of usb ports: ";
	in >> obj.usb_ammount;

	return in;
}