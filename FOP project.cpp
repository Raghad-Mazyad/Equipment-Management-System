#include<iostream>
#include<string>
#include <fstream>
using namespace std;

#define equipment_count 100
#define laboratory_counter 100
struct Equipment //initialization the variable
{
	string equipment_number;
	string equipment_name;
	int assignmentNum;
} equipment_list[equipment_count];

struct Laboratory //initialization the variable
{
	string laboratory_number;
	string laboratory_name;
	int assignmentNum;
}laboratory_list[laboratory_counter];

int menu(int user) // function that the user will see it and choise one of them 
{
	cout<< "\n-----------------------------\n";
	cout << "1- Adding a new equipment\n";
	cout<< "2- Adding a new laboratory\n";
	cout << "3- Edit an equipment\n";
	cout << "4- Edit an laboratory\n";
	cout << "5- search for an equipment\n";
	cout << "6- search for an laboratory\n";
	cout << "7- show all the equipment\n";
	cout << "8- show all the laboratorys\n";
	cout<< "9- Delete an equipment\n";
	cout<< "10- Delete an laboratorys\n";
	cout << "11- Assign equipment to a laboratory\n";
	cout << "12- Check assignment \n";
	cout << "13- Quit\n";
	cout<< "-----------------------------\n";
	cout << " Enter your choise: ";
	cin >> user;
	return user;
}

void Add_Equipment(int count) // this function is used to add a new equipment 
	{
	    Equipment equipment;
		cout<< "- Enter equipment details -\n";
		cout<< " Enter equipment name: ";
		cin>>equipment.equipment_name;
		cout<< " Enter equipment number: ";
		cin>>equipment.equipment_number;
		
		equipment_list[count] = equipment;
		
		ofstream file;
		file.open("equi.txt");
		for(int i = 0; i < count; i++)
			{
				file << equipment_list[i].equipment_name << "-" << equipment_list[i].equipment_number << endl;
			}
		file.close();
		
	}
	
void Add_Laboratory(int counter)// this function is used to add a new Laboratory
	{
		Laboratory laboratory;
		cout<< "- Enter Laboratory details -\n";
		cout<< " Enter Laboratory name: ";
		cin>>laboratory.laboratory_name;
		cout<< " Enter Laboratory number: ";
		cin>>laboratory.laboratory_number;
		
		laboratory_list[counter] = laboratory;
		
		ofstream file;
		file.open("lab.txt");
		for(int i = 0; i < counter; i++)
			{
				file << laboratory_list[i].laboratory_name << "-" << laboratory_list[i].laboratory_number;
			}
		file.close();
	}
	
void Show_Equipment (int itemCount) // make the user see all equipment in a program
	{
		cout << "\n-----------Equipment List-----------\n";
		for(int ctr = 0; ctr < itemCount; ctr++) 
			{
			cout<< "\n-----------Equipment "<< ctr+1 << " Details-----------\n";	
			cout<< "Equipment name: " << equipment_list[ctr].equipment_name;
			cout<< "\nEquipment number: " << equipment_list[ctr].equipment_number;
			} 
	}

void Show_Laboratory(int itemCount) // make the user see all equipment in a Laboratory
	{
		cout << "\n-----------Laboratory List-----------\n";
		for(int ctr = 0; ctr < itemCount; ctr++) 
			{
				cout<< "\n----------- Laboratory "<< ctr+1 << " Details-----------\n";	
				cout<< " Laboratory name: " << laboratory_list[ctr].laboratory_name;
				cout<< "\n Laboratory number: " << laboratory_list[ctr].laboratory_number;
			} 
	}

void Search_Equipment(string number , int index) // make the user found the equipment easly be using this function 
	{
		for(int ctr = 0 ; ctr < index ; ctr++)
			{
				if (equipment_list[ctr].equipment_number.compare(number)==0)
				{
					cout<< "Equipment name: " << equipment_list[ctr].equipment_name;
			        cout<< "\nEquipment number: " << equipment_list[ctr].equipment_number;
			        return;
			
				}
			}
		cout<< "\n Equipment is not found \n";
	}
void Search_Laboratory(string num , int counter)// make the user found the Laboratory easly be using this function 
{
	for(int ctr = 0 ; ctr < counter ; ctr++)
	{
		if (laboratory_list[ctr].laboratory_number.compare(num)==0)
		{
			cout<< " Laboratory name: " << laboratory_list[ctr].laboratory_name;
	        cout<< "\n Laboratory number: " << laboratory_list[ctr].laboratory_number;
	        return;
		}
		
	}
	cout<< "\n Laboratory is not found \n";
}

void assign(int index, int counter) // connect a equipment to Laboratory
	{
		string equipNum, labNum;
		cout << "Enter the number of the equipment: ";
		cin >> equipNum;
		cout << "Enter the number of the lab: ";
		cin >> labNum;
		
		
		for(int ctr = 0 ; ctr < index ; ctr++)
			{
				if (equipment_list[ctr].equipment_number.compare(equipNum)==0)
				{
					for(int ctr2 = 0 ; ctr2 < counter ; ctr2++)
					{
						if (laboratory_list[ctr2].laboratory_number.compare(labNum)==0)
						{
							cout << "Enter the assignment number: ";
							cin >> laboratory_list[ctr2].assignmentNum;
							laboratory_list[ctr2].assignmentNum = equipment_list[ctr].assignmentNum;
							return;
						}
					}
				}
		
			}
		cout << "Either lab or equipment is not found.";
	}
void checkAssignment(int index, int counter) // make the program check if the assign found or not , then print the assign if it is find.
	{
		string labNum;
		cout << "Enter the number of the lab: ";
		cin >> labNum;
		
		
		for(int ctr = 0 ; ctr < counter ; ctr++)
		{
			if (laboratory_list[ctr].laboratory_number.compare(labNum)==0)
			{
				cout << "\n-----------Equipment List-----------\n";
				for(int ctr2 = 0; ctr2 < index; ctr2++) 
				{
					if(laboratory_list[ctr].assignmentNum == equipment_list[ctr2].assignmentNum)
					{	
						cout<< "\nLaboratory: " << laboratory_list[ctr].laboratory_name << ", Number: " << laboratory_list[ctr].laboratory_number << "\nequipment(s) list: " << endl;	
						cout<< "Equipment name: " << equipment_list[ctr2].equipment_name;
						cout<< "\nEquipment number: " << equipment_list[ctr2].equipment_number;
					}
				} 
			}
			
		}
	}

void Edit_Equipment(string numb , int index) // update any equipment detils from the user 
{
	int equNumber = -1;
	string new_name = "0";
	string new_number = "0";
	for (int ctr = 0 ; ctr < index ; ctr++)
		{
			if (equipment_list[ctr].equipment_number.compare(numb)==0)
			{
				equNumber = ctr;
				break;
			}
		}
	if (equNumber != -1)
		{
			cout << " Enter new name of the equipment: ";
			cin >> new_name;
			equipment_list[equNumber].equipment_name = new_name;
			cout << " Enter new number of the equipment: ";
			cin >> new_number;
			equipment_list[equNumber].equipment_number = new_number;
			Show_Equipment(index);
		}
	else
	cout << "Equipment not found! \n";
}

void Edit_Laboratory(string numbb , int counter)// update any Laboratory detils from the user 
{
	int LabNumber = -1;
	string new_Name = "0";
	string new_Number = "0";
	for (int ctr = 0 ; ctr < counter ; ctr++)
	{
		if (laboratory_list[ctr].laboratory_number.compare(numbb)==0)
		{
			LabNumber = ctr;
			break;
		}
	}
	if (LabNumber != -1)
	{
		cout << " Enter new name of the laboratory: ";
		cin >> new_Name;
		laboratory_list[LabNumber].laboratory_name = new_Name;
		cout << " Enter new number of the laboratory: ";
		cin >> new_Number;
		laboratory_list[LabNumber].laboratory_number = new_Number;
		Show_Laboratory(counter);
	}
	else
	cout << "laboratory not found! \n";
}
void Delete_Equipment(string elment , int index) // help the user to delet Equipment
{
	int equElment = -1;
	for (int ctr = 0 ; ctr < index ; ctr++)
	{
		if (equipment_list[ctr].equipment_number.compare(elment)==0)
		{
			equElment = ctr;
			break;
		}
	}
	if (equElment != -1)
	{
		equipment_list[equElment].equipment_name.clear();
		equipment_list[equElment].equipment_number.clear();
		Show_Equipment(index);
	}
	else
	cout << "Equipment not found! \n";
}
void Delete_Laboratory(string Elment , int counter) // help the user to delet Laboratory
{
	int LabElment = -1;
	for (int ctr = 0 ; ctr < counter ; ctr++)
	{
		if (laboratory_list[ctr].laboratory_number.compare(Elment)==0)
		{
			LabElment = ctr;
			break;
		}
	}
	if (LabElment != -1)
	{
		laboratory_list[LabElment].laboratory_name.clear();
		laboratory_list[LabElment].laboratory_number.clear();
		Show_Laboratory(counter);
	}
	else
	cout << "laboratory not found! \n";
}
int main() // the main function of program 
{
	int user , counter = 0 , index = 0 , itemCount;
	string number , num , numb , numbb , elment , Elment;
	do
	{
	
		user = menu(user);
	switch(user)
		{
			case 1:
				Add_Equipment(index);
				index++;
				break;
			case 2:
				Add_Laboratory(counter);
				counter++;
				break;
			case 3:
				cout << "Enter the number of the equipment: ";
				cin>> numb;
				Edit_Equipment(numb , index);
				break;
			case 4:
				cout << "Enter the number of the laboratory: ";
				cin>> numbb;
				Edit_Laboratory(numbb , counter);
				break;
			case 5:
				cout << "Enter the number of the equipment: ";
				cin>> number;
				Search_Equipment(number , index);
				break;
			case 6:
				cout << "Enter the number of the Laboratory: ";
				cin>> num;
				Search_Laboratory(num , counter);
				break;
			case 7:
				Show_Equipment(index);
				break;
			case 8:
				Show_Laboratory(counter);
				break;
			case 9:
				cout << "Enter the number of the equipment: ";
				cin>> elment;
				Delete_Equipment(elment ,index);
				break;
			case 10:
				cout << "Enter the number of the Laboratory: ";
				cin>> Elment;
				Delete_Laboratory(Elment , counter);
				break;	
			case 11:
				assign(index, counter);
				break;
			case 12:
				checkAssignment(index, counter);
				break;
			case 13:
				cout<< "\nProgram Terminated";
				break;
			default:
				cout<< "Input error, try again\n";
		}
	}while(user != 13);
	return 0;
}

