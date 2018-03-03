#include <iostream>
#include <cstring>
#include <fstream>
#include "Exception.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------
class CalculatingMachine
{
public:
	CalculatingMachine(char* = "", int = 0, int = 0);
	CalculatingMachine(const CalculatingMachine&);
	~CalculatingMachine();

	void setModel(char*);
	void setCost(int);
	void setDisplaySize(int);

	char* getModel();
	int getCost();
	int getDisplaySize();

	friend ostream& operator<<(ostream&, CalculatingMachine&);
	friend istream& operator>>(istream&, CalculatingMachine&);

private:
	int cost, display_size; // cpu_cores, ram, internal_storage;
	char model[50];
};
//-------------------------------------------------------------------------------------------------------
class DesktopComputer:public CalculatingMachine
{
public:
	DesktopComputer(char* = "", int = 0, int = 0, char* = "", int = 0);
	DesktopComputer(const DesktopComputer&);
	~DesktopComputer();

	void setProcessor(char*);
	void setUsbAmmount(int);

	char* getProcessor();
	int getUsbAmmount();

	friend ostream& operator<<(ostream&, DesktopComputer&);
	friend istream& operator>>(istream&, DesktopComputer&);

private:
	char processor[30];
	int usb_ammount;
};
//------------------------------------------------------------------------------------------------------
class PortableComputer:public CalculatingMachine
{
public:
	PortableComputer(char*, int, int, char* = "");
	~PortableComputer();

	void setOs(char*);
	char* getOs();

	friend ostream& operator<<(ostream&, PortableComputer&);
	friend istream& operator>>(istream&, PortableComputer&);

private:
	char os[20];
};
//------------------------------------------------------------------------------------------------------
class AllInOne:public DesktopComputer
{
public:
	AllInOne(char* = "", int = 0, int = 0, char* = "", int = 0, bool = false, bool = false);
	AllInOne(const AllInOne&);
	~AllInOne();

	void edit();
	AllInOne& operator=(AllInOne&);

	friend ostream& operator<<(ostream&, AllInOne&);
	friend istream& operator>>(istream&, AllInOne&);

	void setTouchscreen(bool);
	void setSsd(bool);

	bool getTouchscreen();
	bool getSsd();

private:
	bool touchscreen, ssd;
};
//-------------------------------------------------------------------------------------------------------
class Notebook:public PortableComputer
{
public:
	Notebook(char* = "", int = 0, int = 0, char* = "", bool = false);
	~Notebook();

	void objectShow();
	Notebook& operator=(const Notebook&);

	void setCdRom(bool);
	bool getCdRom();

private:
	bool cd_rom;
};
//-------------------------------------------------------------------------------------------------------
class Tablet:public PortableComputer
{
public:
	Tablet(char* = "", int = 0, int = 0, char* = "", bool = false);
	~Tablet();

	void objectShow();
	Tablet& operator=(const Tablet&);	

	void setCamera(bool);
	bool getCamera();

private:
	bool camera;
};
//------------------------------------------------------------------------------------------------
template< class T >
class Interface
{
public:
	Interface(){};
	~Interface(){};

	void main_menu();
	void desktop_menu();
	void portable_menu();
	void option();
};