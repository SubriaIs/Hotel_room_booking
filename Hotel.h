#include<iostream>
#pragma once
// Room object
struct Room {
	int RoomID;
	std::string RoomSize;
	int RoomPrice;
	bool IsBookable;
	std::string Description;
};
// Reservation object
struct Reservation {
	int ReservationID;
	int InvoiceNumber;
	std::string ReserveName;
	Room ReservedRoom;
	int NoOfNights;
	double discount;
	double totalprice;
};
void searchReservationByNumber(int number, std::stack<Reservation> reservationList);
void searchReservationByName(std::string name, std::stack<Reservation> reservationList);
double getTotalBill(double RoomPrice, int NoOfNights);
int generateNumber(int max_num, int min_num);
std::string getReservationName();
void userDisplay(Room* roomList, std::stack<Reservation>& reservationList);
