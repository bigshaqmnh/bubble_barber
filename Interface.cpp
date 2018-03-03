#include "Header.h"

template< class T >
void Interface< T >::main_menu()
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		cout <<"1.Work with Desktop computers"<< endl;
		cout <<"2.Work with Portable computers"<< endl;
		cout <<"0.Exit"<< endl;

		cin >> choice;

		switch (choice)
		{
			case '1':
			{
				desktop_menu();
				break;
			}
			case '2':
			{
				portable_menu();
				break;
			}
			case '0': break;
			default:
			{
				cout <<"Wrong input! Try again."<< endl;
				flag1 = true;
			}
		}
	} while (choice != '0' || flag);
}
//-----------------------------------------------------------------------------------
template< class T >
void Interface< T >::desktop_menu()
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		cout <<"1.Work with All-in-one computers"<< endl;
		cout <<"0.Back to main menu"<< endl;

		cin >> choice;

		switch (choice)
		{
			case '1':
			{
				Interface< AllInOne > obj;
				obj.option();
				break;
			}
			case '0': break;
			default:
			{
				cout <<"Wrong input! Try again."<< endl;
				flag = true;
			}			
		}
	} while (choice != '0' || flag);

}
//-----------------------------------------------------------------------------------
template< class T >
void Interface< T >::portable_menu()
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		cout <<"1.Work with Notebooks"<< endl;
		cout <<"2.Work with Tablets"<< endl;
		cout <<"0.Back to main menu"<< endl;

		cin >> choice2;

		switch (choice2)
		{
			case '1':
			{
				Interface< Notebook > obj;
				obj.option();
				break;
			}
			case '2':
			{
				Interface< Tablet > obj;
				obj.option();
				break;
			}
			case '0': break;
			default:
			{
				cout <<"Wrong input! Try again."<< endl;
				flag = true;
			}
		}

	} while (choice != '0' || flag);
}
//-------------------------------------------------------------------------
template< class T >
void Interface< T >::option()
{
	Queue< T > queue;
	T obj;

	char choice;

	do
	{
		cout <<"\n1.Add object"<< endl;
		cout <<"2.Eject object"<< endl;
		cout <<"3.Show all objects"<< endl;
		cout <<"4.Search object by parameter"<< endl;
		cout <<"5.Sort objects by parameter"<< endl;
		cout <<"6.Delete object"<< endl;
		cout <<"0.Return to main menu"<< endl;

		cin >> choice;

		switch (choice)
		{
			case '1':
			{
				obj.fill();
				queue.enqueue(obj);
				break;
			}
			case '2':
			{
				cout <<"\nThe first object in the queue was: ";
				queue.dequeue(obj);
				cout << obj;
				break;
			}
			case '3':
			{
				cout <<"\nThe queue is: ";
				queue.printQueue();
				break;
			}
			case '4':
			{
				cout <<"\nEnter the element you want to find: ";
				cin >> value;
				queue.search(value);
				break;
			}
			case '5':
			{
				cout <<"\nSorted by ascending: "<< endl;
				queue.sort();
				queue.printQueue();
				break;
			}
			case '6':
			{
				cout <<"\nEnter the element you want to delete: ";
				cin >> value;
				queue.del_elem(value);
				cout <<"Element "<< value <<" was successfully deleted"<< endl;
				break;
			}
			case '0': break;
		}
	} while (choice != '0');
}