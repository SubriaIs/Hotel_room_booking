#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include"Hotel.h"

using namespace std;



int main() {
	//variables
	int choice, reservationNo;
	string reserverName;
	Room allRoomList[300];
	stack<Reservation> reservations;
	// initial single and double room objects (0-149) for single, (150 - 299) for double
	for (int i = 0; i < 151; i++)
	{

		if (i > 59 && i < 80)
		{
			if ( i%2 == 0) // check 61 -80 even double
			{
				allRoomList[i].RoomID = (i + 1);
				//array 0 to 1
				allRoomList[i].RoomSize = "double";
				allRoomList[i].RoomPrice = 150;
				allRoomList[i].IsBookable = true;
				allRoomList[i].Description = "Room is suitable for 2 persons";
			}
			else
			{
				allRoomList[i].RoomID = (i + 1);
				//array 0 to 1
				allRoomList[i].RoomSize = "single";
				allRoomList[i].RoomPrice = 100;
				allRoomList[i].IsBookable = true;
				allRoomList[i].Description = "Room is suitable for 1 person";
			}
		}
		else
		{
			allRoomList[i].RoomID = (i + 1);
			//array 0 to 1
			allRoomList[i].RoomSize = "Single";
			allRoomList[i].RoomPrice = 100;
			allRoomList[i].IsBookable = true;
			allRoomList[i].Description = "Room is suitable for 1 person";
		}
	}
	for (int i = 150; i < 300; i++)
	{


		allRoomList[i].RoomID = (i + 1);
		//array 0 to 1
		allRoomList[i].RoomSize = "Double";
		allRoomList[i].RoomPrice = 150;
		allRoomList[i].IsBookable = true;
		allRoomList[i].Description = "Room is suitable for 2 persons";


	}
	//User interface
	cout << "---Welcome to Hotel Reservation System---" << endl;
	while (true)
	{
		cout << " Enter 1 for new Reservation, 2 for search by Reservation No, 3 for search by Reserver Name: ";
		cin >> choice;
		switch (choice) {
		case 1:
			userDisplay(allRoomList, reservations);
			break;
		case 2:
			cout << " Enter reservation No: ";
			cin >> reservationNo;
			searchReservationByNumber(reservationNo, reservations);
			break;
		case 3:
			cout << " Enter Reserver Name: ";
			cin.ignore(); // clear the buffer
			getline(cin, reserverName);
			searchReservationByName(reserverName, reservations);
			break;
		default:
			cout << "Looking for choice";
		}
	}
	return 0;
}
