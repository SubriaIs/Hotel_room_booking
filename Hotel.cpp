#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include"Hotel.h"
using namespace std;

void searchReservationByNumber(int number, stack<Reservation> reservationList) {
	Reservation reservationTemp;
	while (!reservationList.empty()) {
		reservationTemp = reservationList.top();
		if (reservationTemp.ReservationID == number) {
			//Print Invoice
			cout << "---Reservation Details---" << endl;
			cout << "Reservation ID : " << reservationTemp.ReservationID << endl;
			cout << "Invoice Number : " << reservationTemp.InvoiceNumber << endl;
			cout << "Reservation Name : " << reservationTemp.ReserveName << endl;
			cout << "Room No: " << reservationTemp.ReservedRoom.RoomID << endl;
			cout << "Room Size: " << reservationTemp.ReservedRoom.RoomSize << endl;
			cout << "Room Price : " << reservationTemp.ReservedRoom.RoomPrice << endl;
			cout << "Room Description : " << reservationTemp.ReservedRoom.Description << endl;
			cout << "Reservation NoOfNights : " << reservationTemp.NoOfNights << endl;
			cout << "Invoice Discount : " << reservationTemp.discount << endl;
			cout << "Invoice Total Price : " << reservationTemp.totalprice << endl;
			cout << endl;
			break;
		}
		reservationList.pop();
	}
}

void searchReservationByName(string name, stack<Reservation> reservationList) {
	Reservation reservationTemp;
	while (!reservationList.empty()) {
		reservationTemp = reservationList.top();
		if (reservationTemp.ReserveName == name) {
			//Print Invoice
			cout << "---Reservation Details---" << endl;
			cout << "Reservation ID : " << reservationTemp.ReservationID << endl;
			cout << "Invoice Number : " << reservationTemp.InvoiceNumber << endl;
			cout << "Reservation Name : " << reservationTemp.ReserveName << endl;
			cout << "Room No: " << reservationTemp.ReservedRoom.RoomID << endl;
			cout << "Room Size: " << reservationTemp.ReservedRoom.RoomSize << endl;
			cout << "Room Price : " << reservationTemp.ReservedRoom.RoomPrice << endl;
			cout << "Room Description : " << reservationTemp.ReservedRoom.Description << endl;
			cout << "Reservation NoOfNightd : " << reservationTemp.NoOfNights << endl;
			cout << "Invoice Discount : " << reservationTemp.discount << endl;
			cout << "Invoice Total Price : " << reservationTemp.totalprice << endl;
			cout << endl;
			break;
		}
		reservationList.pop();
	}
}
//Total Bill
double getTotalBill(double RoomPrice, int NoOfNights) {
	double discountPrice, totalAmount, discountAmount, amount;
	if (NoOfNights < 5) {
		discountPrice = 0;
	}
	else if (NoOfNights >= 5 && NoOfNights < 15) {
		discountPrice = 0.1;
	}
	else {
		discountPrice = 0.2;
	}
	totalAmount = RoomPrice * NoOfNights;
	discountAmount = totalAmount * discountPrice;
	amount = totalAmount - discountAmount;
	return amount;
}


//randomly create number
int generateNumber(int max_num, int min_num) {
	return (rand() % max_num) + min_num;
}
//Get reservation name
string getReservationName() {
	string reserverName;
	cout << "Enter Full Reserve name: ";
	cin.ignore(); //clear the buffer
	getline(cin, reserverName);
	return reserverName;
}
void userDisplay(Room* roomList, stack<Reservation>& reservationList) {
	int NumOfNights, roomNumber;
	bool isRoomFound = false;
	Room roomBook;
	Reservation reservation;
	//user inputs


	while (true) {
		cout << "Enter a room number you want " << endl;

		cin >> roomNumber;

		while (cin.fail()) {
			cin.clear(); // clear error flag
			cin.ignore(1000, '\n'); // discard invalid input
			cout << "Invalid input! That's not an integer. Try again: ";
			cin >> roomNumber;
		}

		if (roomNumber > 1 && roomNumber < 300)
		{
			break;
		}
		else {
			cout << "Please enter new room number under 300" << endl;
		}
	}
	cout << "How many nights ?" << endl;
	cin >> NumOfNights;
	if (roomList[roomNumber - 1].IsBookable == true)
	{
		roomBook = roomList[roomNumber - 1];
		roomBook.IsBookable = false;
		roomList[roomNumber - 1].IsBookable = false;
		isRoomFound = true;
	}

	if (!isRoomFound)
	{
		cout << "Sorry ! no room available." << endl;
	}
	else if (isRoomFound)
	{
		//Perform new reservation
		reservation.ReservationID = generateNumber(99999, 10000);
		reservation.InvoiceNumber = generateNumber(9999, 1000);
		reservation.ReserveName = getReservationName();
		reservation.ReservedRoom = roomBook;
		reservation.NoOfNights = NumOfNights;
		reservation.totalprice = getTotalBill(roomBook.RoomPrice, NumOfNights);
		reservation.discount = ((roomBook.RoomPrice * NumOfNights) - reservation.totalprice);
		reservationList.push(reservation);
		// store in reservation stack
		//Print Invoice
		cout << "---Reservation Details---" << endl;
		cout << "Reservation ID : " << reservation.ReservationID << endl;
		cout << "Invoice Number : " << reservation.InvoiceNumber << endl;
		cout << "Reservation Name : " << reservation.ReserveName << endl;
		cout << "Room No: " << roomBook.RoomID << endl;
		cout << "Room Size: " << roomBook.RoomSize << endl;
		cout << "Room Price : " << roomBook.RoomPrice << endl;
		cout << "Room Description : " << roomBook.Description << endl;
		cout << "Reservation NoOfNightd : " << NumOfNights << endl;
		cout << "Invoice Discount : " << reservation.discount << endl;
		cout << "Invoice Total Price : " << reservation.totalprice << endl;
		cout << endl;
	}
}