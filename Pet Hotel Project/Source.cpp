#include <iostream>
#include <vector>
#include <string>
#include "Pethotel.h"
#include "Dog.h"
#include "Cat.h"
#include "Rodent.h"
#include "Reservation.h"
#include "Kennel.h"
 
using namespace std;
int nextReservationId = 1;

void customerMenu(PetHotel*);

//Employee Menu + Functions
void employeeMenu(PetHotel*);

void listReservations(PetHotel*);
void changeReservation(PetHotel*);
void removeReservation(PetHotel*);
void moveAnimal(PetHotel*);
void listAnimals(PetHotel*);
void listAllAnimals(PetHotel*);	
void listAnimalsByType(PetHotel*);
void listAnimalsBySize(PetHotel*);
void listAnimalByCare(PetHotel*);
void addKennel(PetHotel*);
void listKennels(PetHotel*);
void removeKennel(PetHotel*);



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
		cout << "0. Back to Main Menu\n";
		cout << "Enter your choice: ";

		cin >> choice;
		switch (choice)
		{
		case 1: 
		{
			int typeChoice;
			cout << "\nSelect pet type:\n";
			cout << "1. Dog\n";
			cout << "2. Cat\n";
			cout << "3. Rodent\n";
			cout << "Choice: ";
			cin >> typeChoice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			Animal* newAnimal = NULL;

			if (typeChoice == 1)
			{
				int id, weight;
				string name,line,kg, birthDate, breed, careSchedule;

				cout << "Enter dog ID: "; 
				getline(cin, line);
				id = stoi(line);
				cout << "Name: ";
				getline(cin, name);
				cout << "Birth date (YYYY-MM-DD): ";
				getline(cin, birthDate);
				cout << "Breed: "; 
				getline(cin, breed);
				cout << "Preffered Care schedule (e.g. 3 walks/day): "; 
				getline(cin, careSchedule);
				cout << "Weight (kg): ";
				getline(cin, kg);
				weight = stoi(kg);

				newAnimal = new Dog(id, name, breed, birthDate, careSchedule, weight);

			}
			if (typeChoice == 2)
			{
				int id, weight;
				string line, kg, name, birthDate, breed, careSchedule;

				cout << "Enter cat ID: ";
				getline(cin, line);
				id = stoi(line);
				cout << "Name: "; 
				getline(cin, name);
				cout << "Birth date (YYYY-MM-DD): "; 
				getline(cin, birthDate);
				cout << "Breed: "; 
				getline(cin, breed);
				cout << "Preffered Care schedule: "; 
				getline(cin, careSchedule);
				cout << "Weight (kg): "; 
				getline(cin, kg);
				weight = stoi(kg);

				newAnimal = new Cat(id, name, birthDate, breed, careSchedule, weight);
			}
			if (typeChoice == 3)
			{
				int id;
				string line, name, birthDate, breed, careSchedule, rodentType;

				cout << "Enter rodent ID: ";
				getline(cin, line);
				id = stoi(line);   // convert string -> int

				cout << "Name: ";
				getline(cin, name);

				cout << "Birth date (YYYY-MM-DD): ";
				getline(cin, birthDate);

				cout << "Breed: ";
				getline(cin, breed);

				cout << "Preferred Care schedule: ";
				getline(cin, careSchedule);

				cout << "Rodent type (mouse/rabbit/etc): ";
				getline(cin, rodentType);
				newAnimal = new Rodent(id, name, birthDate, breed, careSchedule, rodentType);
			}
			else if (typeChoice < 1 || typeChoice > 3)
			{
				cout << "Invalid type selected.\n";
				break;
			}

			if (newAnimal == NULL)
			{
				cout << "Error creating animal.\n";
				break;
			}

			// grouping preference
			char groupingInput;
			bool putTogether = false;

			// only small/medium cats/dogs can be grouped
			if (typeChoice == 1)
			{
				Dog* d = (Dog*)newAnimal;
				int w = d->getWeight();

				if (w < 25)
				{
					cout << "May this pet be placed together in a larger kennel? (y/n): ";
					cin >> groupingInput;
					putTogether = (groupingInput == 'y' || groupingInput == 'Y');
				}
			}
			else if(typeChoice == 2)
			{
				cout << "May this pet be placed together in a larger kennel? (y/n): ";
				cin >> groupingInput;
				putTogether = (groupingInput == 'y' || groupingInput == 'Y');
			}
			else //rodents are in their own kennels 
			{
				putTogether = false;
			}

			//Find available kennels for the new animal
			vector<Kennel*> options = hotel->findAvailableKennelsFor(newAnimal);

			if (options.empty())
			{
				cout << "No available kennels for this animal at the moment.\n";
				delete newAnimal;
				break;
			}

			vector<Kennel*> filtered;

			if (!putTogether)
			{
				//if grouping is not allowed, filter only empty kennels
				for (Kennel* k : options)
				{
					if(k->getCurrentCount() == 0)
						filtered.push_back(k);
				}
			}
			else
			{
				//if pets can be grouped, use all options
				filtered = options;
			}
			if (filtered.empty())
			{
				cout << "No suitable kennels available based on your grouping preference.\n";
				delete newAnimal;
				break;
			}

			//display available kennels
			cout << "\nAvailable Kennels:\n";
			for(Kennel* k : filtered)
			{
				cout << "Kennel ID: " << k->getId()
					<< " | Size: " << k->getSize()
					<< " | Type: " << k->getType()
					<< " | Current Occupancy: " << k->getCurrentCount()
					<< "\n";
			}

			// For simplicity, automatically assign the first available kennel
			Kennel* assignedKennel = filtered[0];
			cout << "Your pet has been assigned to Kennel ID: " << assignedKennel->getId() << "\n";

			// reservation dates

			string startDate, endDate;
			cout << "Enter reservation start date (YYYY-MM-DD): ";
			cin >> startDate;
			cout << "Enter reservation end date (YYYY-MM-DD): ";
			cin >> endDate;

			//animal list for reservations
			vector<Animal*> pets;
			pets.push_back(newAnimal);

			int resId = nextReservationId++;

			Reservation* res = new Reservation(resId, startDate, endDate, pets, putTogether);
			if (!res->isDurationValid())
			{
				cout << "Reservation must be between 2 and 28 days. \n";
				delete res;
				delete newAnimal;
				break;
			}
			assignedKennel->addAnimal(newAnimal);

			
			hotel->addAnimal(newAnimal);
			hotel->addReservation(res);

			cout << "Reservation created successfully! Your reservation ID is: " << resId << "\n";
		
			break;
		}
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
		cout << "1. Change Reservation\n";
		cout << "2. Remove Reservation\n";
		cout << "3. List Reservations\n";
		cout << "4. Move Animal\n";
		cout << "5. List Animals\n";
		cout << "6. Add Kennel\n";
		cout << "7. List Kennel\n";
		cout << "8. Remove Kennel\n";
		cout << "0. Back to Main Menu\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			changeReservation(hotel);
			break;
		case 2:
			removeReservation(hotel);
			break;
		case 3:
			listReservations(hotel);
			break;
		case 4:
			moveAnimal(hotel);
			break;
		case 5:
			listAnimals(hotel);
			break;
		case 6:
			addKennel(hotel);
			break;
		case 7:
			listKennels(hotel);
			break;
		case 8:
			removeKennel(hotel);
			break;
		case 0:
			return;
		default:
			cout << "Invalid choice.\n";
		}
	}

}

void listReservations(PetHotel* hotel)
{
	vector<Reservation*> reservations = hotel->getReservations();
	if (reservations.empty())
	{
		cout << "No reservations found.\n";
		return;
	}
	cout << "\n--- Current Reservations ---\n";
	for (Reservation* r : reservations)
	{
		cout << "Reservation ID: " << r->getId()
			<< " | Start: " << r->getStartDate()
			<< " | End: " << r->getEndDate()
			<< " | Number of Animals: " << r->getAnimals().size()
			<< "\n";
	}
}

void changeReservation(PetHotel* hotel)
{
	listReservations(hotel);

	int resId;
	cout << "Enter Reservation ID to change: ";
	cin >> resId;
	
	Reservation* r = hotel->findReservationById(resId);
	
	if (r == NULL)
	{
		cout << "Reservation not found.\n";
		return;
	}

	int choice = -1;
	while (choice != 0)
	{
		cout << "\n--- EDIT RESERVATION ---\n";
		cout << "1. Change Start Date\n";
		cout << "2. Change End Date\n";
		cout << "3. Change Grouping\n";
		cout << "0. Back to Employee Menu\n";
		cout << "Enter choice: ";
		cin >> choice;


		if (choice == 1)
		{
			string start;
			cout << "Enter new start date (YYYY-MM-DD): ";
			cin >> start;
			r->setStartDate(start);

			if (!r->isDurationValid())
			{
				cout << "Invalid duration. \n";
			}
		}
		else if (choice == 2)
		{
			string end;
			cout << "Enter new end date (YYYY-MM-DD): ";
			cin >> end;
			r->setEndDate(end);

			if (!r->isDurationValid())
			{
				cout << "Invalid duration. \n";
			}
		}
		else if (choice == 3)
		{
			char c;
			cout << "Allow grouping in kennels? (y/n): ";
			cin >> c;

			bool putTogether = (c == 'y' || c == 'Y');
			r->setPutTogether(putTogether);

			cout << "Grouping preference updated.\n";

		}
	}
}

void removeReservation(PetHotel* hotel)
{
	listReservations(hotel);
	int id;
	cout << "Enter Reservation ID to remove: ";
	cin >> id;
	
	Reservation* r = hotel->findReservationById(id);
	
	if (r == NULL)
	{
		cout << "Reservation not found.\n";
		return;
	}
	//remove animals from kennels
	for (Animal* a : r->getAnimals())
	{
		for (Kennel* k : hotel->getKennels())
		{
			k->removeAnimal(a);
		}
	}

	bool success = hotel->removeReservation(r);
	if (success)
	{
		delete r;
		cout << "Reservation removed successfully.\n";
	}
	else
	{
		cout << "Error removing reservation.\n";
		return;
	}
}

void moveAnimal(PetHotel* hotel)
{
	vector<Animal*> animals = hotel->getAnimals();

	if (animals.empty())
	{
		cout << "No animals found.\n";
		return;
	}

	cout << "\n--- Animals ---\n";
	for (int i = 0; i < animals.size(); i++)
	{
		cout << i << ". " << animals[i]->getName()
			<< " ( " << animals[i]->getType() << ")\n";
	}

	int index;
	cout << "Enter Animal ID to move: ";
	cin >> index;
	
	if (index < 0 || index >= animals.size())
	{
		cout << "Invalid Animal ID.\n";
		return;
	}
	Animal* a = animals[index];

	vector<Kennel*> options = hotel->findAvailableKennelsFor(a);

	if (options.empty())
	{
		cout << "No available kennels for this animal at the moment.\n";
		return;
	}

	cout << "\n--- AVAILABLE KENNELS ---\n";
	for (int i = 0; i < options.size(); i++)
	{
		cout << i << ". Kennel ID " << options[i]->getId()
			<< " | Size " << options[i]->getSize()
			<< "\n";
	}

	int kennelIndex;
	cout << "Enter Kennel ID to move the animal to: ";
	cin >> kennelIndex;

	if (kennelIndex < 0 || kennelIndex >= options.size())
	{
		cout << "Invalid Kennel ID.\n";
		return;
	}
	
	//Remove animal from old kennel
	for (Kennel* k : hotel->getKennels())
	{
		k->removeAnimal(a);
	}

	options[kennelIndex]->addAnimal(a);

	cout << "Animal moved successfully to Kennel ID: " << options[kennelIndex]->getId() << "\n";

}

void listAnimals(PetHotel* hotel)
{
	int choice;

	cout << "\n--- LIST OF ANIMALS ---\n";
	cout << "1. List All Animals\n";
	cout << "2. List Animals by Type\n";
	cout << "3. List Animals by Size\n";
	cout << "4. List Animals by Care Schedule\n";
	cout << "0. Back to Employee Menu\n";
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		listAllAnimals(hotel);
		break;
	case 2:
		listAnimalsByType(hotel);
		break;
	case 3:
		listAnimalsBySize(hotel);
		break;
	case 4:
		listAnimalByCare(hotel);
		break;
	case 0:
		return;
	default:
		cout << "Invalid choice.\n";
		break;

	}

}

void listAllAnimals(PetHotel* hotel)
{
	vector<Animal*> animals = hotel->getAnimals();
	if (animals.empty())
	{
		cout << "No animals found.\n";
		return;
	}
	cout << "\n--- Current Animals ---\n";
	for (Animal* a : animals)
	{
		cout << "Animal ID: " << a->getId()
			<< " | Name: " << a->getName()
			<< " | Type: " << a->getType()
			<< " | Breed: " << a->getBreed()
			<< "\n";
	}
}

void listAnimalsByType(PetHotel* hotel)
{
	vector<Animal*> animals = hotel->getAnimals();
	if (animals.empty())
	{
		cout << "No animals found.\n";
		return;
	}

	int choice;
	cout << "\n--- FILTER BY TYPE ---\n";
	cout << "1. Dog\n";
	cout << "2. Cat\n";
	cout << "3. Rodent (rabbit, mouse, etc.)\n";
	cout << "Enter choice: ";
	cin >> choice;

	string type;

	if (choice == 1) type = "Dog";
	else if (choice == 2) type = "Cat";
	else if (choice == 3) type = "Rodent";
	else
	{
		cout << "Invalid choice.\n";
		return;
	}

	cout << "\n --- ANIMALS OF TYPE: " << type << " ---\n";

	for (Animal* a : hotel->getAnimals())
	{
		if (a->getType() == type)
		{
			cout << "Animal ID: " << a->getId()
			<< " | Name: " << a->getName()
			<< " | Breed: " << a->getBreed()
			<< "\n";
		}
		if (type == "Rodent")
		{
			Rodent* r = (Rodent*)a;
			cout << " | Species: " << r->getRodentType();
		}
		else
		{
			cout << "No animals of type " << type << " found.\n";
		}
	}

}

void listAnimalsBySize(PetHotel* hotel)
{
	int choice;
	cout << "\n--- FILTER DOGS BY SIZE ---\n";
	cout << "1. Small (<10kg)\n";
	cout << "2. Medium (10-25kg)\n";
	cout << "3. Large (>25kg)\n";
	cout << "Enter choice: ";
	cin >> choice;

	cout << "\n --- DOGS OF SELECTED SIZE ---\n";

	for (Animal* a : hotel->getAnimals())
	{
		if (a->getType() != "Dog")
			continue;

		Dog* d = dynamic_cast<Dog*>(a);
		int weight = d->getWeight();

		if (choice == 1 && weight < 10)
		{
			cout << "Animal ID: " << a->getId()
				<< " | Name: " << a->getName()
				<< " | Breed: " << a->getBreed()
				<< " | Weight: " << weight << "kg"
				<< "\n";
		}
		else if (choice == 2 && weight >= 10 && weight <= 25)
		{
			cout << "Animal ID: " << a->getId()
				<< " | Name: " << a->getName()
				<< " | Breed: " << a->getBreed()
				<< " | Weight: " << weight << "kg"
				<< "\n";
		}
		else if (choice == 3 && weight > 25)
		{
			cout << "Animal ID: " << a->getId()
				<< " | Name: " << a->getName()
				<< " | Breed: " << a->getBreed()
				<< " | Weight: " << weight << "kg"
				<< "\n";
		}
	}

}

void listAnimalByCare(PetHotel* hotel)
{
	string care;
	cout << "Enter care schedule to filter by: ";
	cin.ignore();
	getline(cin, care);

	cout << "\n --- ANIMALS WITH CARE SCHEDULE: " << care << " ---\n";

	for (Animal* a : hotel->getAnimals())
	{
		if (a->getCareSchedule() == care)
		{
			cout << "Animal ID: " << a->getId()
				<< " | Name: " << a->getName()
				<< " | Type: " << a->getType()
				<< " | Breed: " << a->getBreed()
				<< "\n";
		}
	}
}

void addKennel(PetHotel* hotel)
{
	//int id, std::string size, std::string type, int capacity
	int id, capacity;
	string size, type;
	cout << "\n--- ADD KENNEL ---\n";
	cout << "Enter Kennel ID: ";
	cin >> id;
	cout << "Enter Kennel Size (small/medium/large/rodent): ";
	cin >> size;
	cout << "Enter Kennel Type(Dog, Cat, Rodent): ";
	cin >> type;
	if (size != "small" && size != "medium" && size != "large" && size != "rodent")
	{
		cout << "Invalid size.\n";
		return;
	}
	cout << "Enter Kennel Capacity: ";
	cin >> capacity;
	Kennel* kennel = new Kennel(id, size, type, capacity);

	hotel->getKennels().push_back(kennel); //Pushing the new kennel to a "copy" of the vector kennels
	hotel->setKennels(hotel->getKennels()); //Assigning the modified copy back to the pet hotel

	cout << "Kennel added successfully.\n";

}

void listKennels(PetHotel* hotel)
{
	vector<Kennel*> kennels = hotel->getKennels();
	if (kennels.empty())
	{
		cout << "No kennels found.\n";
		return;
	}
	cout << "\n--- Current Kennels ---\n";
	for (Kennel* k : kennels)
	{
		cout << "Kennel ID: " << k->getId()
			<< " | Size: " << k->getSize()
			<< " | Type: " << k->getType()
			<< " | Capacity: " << k->getCapacity()
			<< " | Current Occupancy: " << k->getCurrentCount()
			<< "\n";
	}
}

void removeKennel(PetHotel* hotel)
{
	listKennels(hotel);
	int id;
	
	cout << "Enter Kennel ID to remove: ";
	cin >> id;
	
	vector<Kennel*> kennels = hotel->getKennels();
	
	for (int i = 0; i < kennels.size(); i++)
	{
		if (kennels[i]->getId() == id)
		{
			if (!kennels[i]->isEmpty())
			{
				cout << "Cannot remove a kennel that is not empty.\n";
				return;
			}
			
			delete kennels[i];
			
			kennels.erase(kennels.begin() + i);
			hotel->setKennels(kennels);
			
			cout << "Kennel removed successfully.\n";
			return;
		}
	}
	cout << "Kennel not found.\n";
}