#include "Header.h"

Tablet::Tablet(char* s1, int a, int b, char* s2, bool b1):
PortableComputer(s1, a, b, s2)
{
	//cout <<"Constructor of class Tablet"<< endl;
	camera = b1;
}
//-----------------------------------------------------------------------------------
Tablet::~Tablet()
{
	//cout <<"Destructor of class Tablet"<< endl;
}
//--------------------------------------------------------------------------------------------
void Tablet::objectShow()
{
	cout <<"Model: "<< model << endl;
	cout <<"Price: "<< cost <<" $"<< endl;
	cout <<"Display size: "<< display_size <<" inch"<< endl;
	cout <<"Operating system: "<< os << endl;
	cout <<"Camera: ";
	if (camera) cout <<"yes"<< endl;
	else cout <<"no"<< endl;
}
//--------------------------------------------------------------------------------------------
Tablet& Tablet::operator=(const Tablet& obj)
{
	if (this != &obj)
	{
		strcpy(model, obj.model);
		cost = obj.cost;
		display_size = obj.display_size;
		strcpy(os, obj.os);
		camera = obj.camera;
	}
	return *this;
}
//-----------------------------------------------------------------------------------------------
void Tablet::setCamera(bool b)
{
	camera = b;
}
//---------------------------------------------------------------------------------------------
bool Tablet::getCamera()
{
	return camera;
}