#include <iostream>
#include <vector>
#include <string>
#include "Pethotel.h"
 
using namespace std;

void customerMenu(PetHotel*);
void employeeMenu(PetHotel*);


int main()
{
	PetHotel hotel("Pet Hotel", "Magic Street 123");
	int choice = -1;

	while (choice != 0)
	{
		cout << "-----PET HOTEL Main Menu-----\n";
		cout << "1. Employee Menu\n";
		cout << "2. Customer Menu\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			employeeMenu(&hotel);
		}
		else if (choice == 2)
		{
			customerMenu(&hotel);
		}
		else if (choice == 0)
		{
			cout << "Exiting system...\n";
		}
		else {
			cout << "Please Enter a valid number.\n";
		}


	}

	return 0;
}

void customerMenu(PetHotel* hotel) 
{
	int choice = -1;

	while (choice != 0)
	{
		cout << "-------CUSTOMER MENU-------\n";
		cout << "1. Make Reservation\n";
		cout << "2. Edit Reservation\n";
		cout << "3. Cancel Reservation\n";
		cout << "4. View Reservation\n";
		cout << "0. Back to Main Menu\n";
		cout << "Enter your choice: ";

		cin >> choice;
		switch (choice)
		{
		case 1: 
			cout << "[TODO] Make Reservation\n";
			break;
		case 2:
			cout << "[TODO] Edit Reservation\n";
			break;
		case 3:
			cout << "[TODO] Cancel Reservation\n";
			break;
		case 4:
			cout << "[TODO] View Reservation\n";
			break;
		case 0:
			return;
		default:
			cout << "Please enter a valid number!\n";
		}
	}

	

}



void employeeMenu(PetHotel* hotel)
{
	int choice = -1;

	while (choice != 0)
	{
		cout << "\n--- EMPLOYEE MENU ---\n";
		cout << "1. Add Kennel\n";
		cout << "2. Remove Kennel\n";
		cout << "3. Add Reservation\n";
		cout << "4. Edit Reservation\n";
		cout << "5. Delete Reservation\n";
		cout << "6. List All Animals\n";
		cout << "7. List Animals by Type\n";
		cout << "8. List Dogs by Size\n";
		cout << "9. List Animals by Care Schedule\n";
		cout << "10. List Kennels With Animals\n";
		cout << "11. Move Animal to Another Kennel\n";
		cout << "0. Back to Main Menu\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "[TODO] Add Kennel\n";
			break;
		case 2:
			cout << "[TODO] Remove Kennel\n";
			break;
		case 3:
			cout << "[TODO] Add Reservation\n";
			break;
		case 4:
			cout << "[TODO] Edit Reservation\n";
			break;
		case 5:
			cout << "[TODO] Delete Reservation\n";
			break;
		case 6:
			cout << "[TODO] List All Animals\n";
			break;
		case 7:
			cout << "[TODO] List Animals by Type\n";
			break;
		case 8:
			cout << "[TODO] List Dogs by Size\n";
			break;
		case 9:
			cout << "[TODO] List Animals by Care Schedule\n";
			break;
		case 10:
			cout << "[TODO] List Kennels With Animals\n";
			break;
		case 11:
			cout << "[TODO] Move Animal\n";
			break;
		case 0:
			return;
		default:
			cout << "Invalid choice.\n";
		}
	}

}