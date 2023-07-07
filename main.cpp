#include <iostream>
#include <string>
using namespace std;
#include "LINKED_LIST.h"
#include "ADMIN.h"
#include "FILES.h"
int main()
{
	patient data;
	short int number;
	int a[6]={0};
	from_file(&data, a);
	string time[6] = { "from 2 to 2:30 pm ","from 2:30 to 3 pm " ,"from 3 to 3:30 pm " ,"from 3:30 to 4 pm " ,"from 4 to 4:30 pm " ,"from 4:30 to 5 pm " };
	cout << "Hello to our clinic managment system " << endl;
	cout << "plz choose : " << endl;
	cout << "1- admin " << endl;
	cout << "2- user " << endl;
	cin >> number;
	system("cls");
	if (number == 1)
	{
		int numofpass = 3;
		while (numofpass --)
		{
			cout << "Enter Password : ";
			cin >> number;
			if (number == 1234)
			{
				numofpass = 0;
				system("cls");
				number = 1;
				while (number == 1)
				{
					cout << " What do you want to do ? plz choose " << endl;
					cout << "1- add new patient record. " << endl;
					cout << "2- edit patient record. " << endl;
					cout << "3- reserve a slot with the dr . " << endl;
					cout << "4- cancel reservatation . " << endl;
					cin >> number;
					system("cls");
					int id;
					string name, gender;
					short unsigned int age;
					node* tempr = NULL;
					switch (number)
					{
					case 1: 
							cout << "Enter informatation abot new patient : " << endl;
							cout << "id : ";
							cin >> id;
							cout << endl;
							cout << "Name : ";
							cin >> name;
							cout << endl;
							cout << "gender : ";
							cin >> gender;
							cout << endl;
							cout << "age : ";
							cin >> age;
							cout << endl;
							data.create_new_node(id, name, gender, age);
						break;
					case 2:
						cout << "enter the id of the patient : " << endl;
						cin >> id;
						system("cls");
						tempr = data.search(id);
						if (tempr != NULL)
						{
							cout << "what do u want to edit ? plzz choose " << endl;
							cout << "1- edit name ." << endl;
							cout << "2- edit gender ." << endl;
							cout << "3- edit age ." << endl;
							cin >> number;
							system("cls");
							string new_name;
							string new_gender;
							int new_age;
							switch (number)
							{
							case 1:
								
								cout << "enter the new name : " << endl;
								cin >> new_name;
								edit_name(tempr, new_name);
							    break;
							case 2:
								
								cout << "enter the new gender : " << endl;
								cin >> new_gender;
								edit_gender(tempr, new_gender);
								break;
							case 3:
								
								cout << "enter the new age : " << endl;
								cin >> new_age;
								edit_age(tempr, new_age);
								break;

							}
							system("cls");
							cout << "Done successfully..." << endl;
						}
						else
						{
							cout << "incorrect id" << endl;
						}
						system("pause");
						break;
					case 3:
						cout << "The available slots : plz choose slot " << endl;
						for (int i = 0; i < 6; i++)
						{
							if (a[i] == 0)
							{
								cout << i + 1 << "- " << time[i] << endl;
							}
						}
						cin >> number;
						cout << "write the id of the patient : ";
						cin >> id;
						if (data.search(id)!=NULL)
						{
							a[number-1] = id;
						}
						break;
					case 4:
						cout << "write the id of the patient that you want to cancel his  reservation : ";
						cin >> id;
						for (int i = 0; i < 6; i++)
						{
							if (a[i] == id)
							{
								a[i] = 0;
								break;
							}
						}
						cout << "Done successfully ";
						
						break;
					}
					system("cls");
					cout << "Do you want to exit or continue ? plz choose " << endl;
					cout << "1- continue ." << endl;
					cout << "2- exit ." << endl;
					cin >> number;
					system("cls");
					if (number == 2)
					{
						to_file(data.top(), a);
					}
				}
			}
			else
			{
				system("cls");
					cout << " wrong password " << endl;
					cout << "You have " << numofpass << " more trails " << endl;
					if (numofpass == 0)
					{
						cout << "The system closed " << endl;
						return 0;
					}
			}
		}
		
	}
	else
	{
		number = 1;
		while (number == 1)
		{
			cout << "what do you want ? plz choose " << endl;
			cout << "1- view patient record . " << endl;
			cout << "2- view patients reservatation ." << endl;
			cin >> number;
			system("cls");
			if (number == 1)
			{
				int id;
				cout << "Enter the paitent id : ";
				cin >> id;
				node* tempb = NULL;
				tempb = data.search(id);
				system("cls");
				if (tempb != NULL)
				{
					cout << "The patient name : " << tempb->name << endl;
					cout << "The patient gender : " << tempb->gender << endl;
					cout << "The patient age : " << tempb->age << endl;
				}
				else
				{
					cout << "incorrect id";
				}
			}
			else
			{
				for (int i = 0; i < 6; i++)
				{
					if (a[i] != 0)
					{
						cout << "The id of patient is " << a[i] << " and the time of his slot " << time[i] << endl;
					}
				}
			}
			system("pause");
			system("cls");
			cout << "Do you want to exit or continue ? plz choose " << endl;
			cout << "1- continue ." << endl;
			cout << "2- exit ." << endl;
			cin >> number;
			system("cls");
			if (number == 2)
			{
				to_file(data.top(), a);
			}
		}
	}
}