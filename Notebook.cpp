#include "Header.h"

Notebook::Notebook(char* s1, int a, int b, char* s2, bool b1):
PortableComputer(s1, a, b, s2)
{
	//cout <<"Constructor of class Notebook"<< endl;
	cd_rom = b1;
}
//--------------------------------------------------------------------------------------------
Notebook::~Notebook()
{
	//cout <<"Destructor of class Notebook"<< endl;
}
//--------------------------------------------------------------------------------------------
void Notebook::objectShow()
{
	cout <<"Model: "<< getModel() << endl;
	cout <<"Price: "<< getCost() <<" $"<< endl;
	cout <<"Display size: "<< display_size <<" inch"<< endl;
	cout <<"Operating system: "<< os << endl;
	cout <<"CD_ROM: ";
	if (cd_rom) cout <<"yes"<< endl;
	else cout <<"no"<< endl;
}
//--------------------------------------------------------------------------------------------
Notebook& Notebook::operator=(const Notebook& obj)
{
	if (this != &obj)
	{
		strcpy(model, obj.model);
		cost = obj.cost;
		display_size = obj.display_size;
		strcpy(os, obj.os);
		cd_rom = obj.cd_rom;
	}
	return *this;
}
//-----------------------------------------------------------------------------------------------
void Notebook::setCdRom(bool b)
{
	cd_rom = b;
}
//---------------------------------------------------------------------------------------------
bool Notebook::getCdRom()
{
	return cd_rom;
}