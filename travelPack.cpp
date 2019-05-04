#include "travelPack.h"

#include <iostream>
#include <iomanip>

using namespace std;

TravelPack::TravelPack()
{
	id = 0;
	destinations = {};
	departureDate = Date();
	returnDate = Date();
	price = 0;
	maxBookings = 0;
	currentBookings = 0;
}

#pragma region GETTERS

int TravelPack::getId() const
{
	return this->id;
}

std::vector<std::string> TravelPack::getDestinations() const
{
	return this->destinations;
}

Date TravelPack::getDeparture() const
{
	return this->departureDate;
}

Date TravelPack::getReturn() const
{
	return this->returnDate;
}

int TravelPack::getPrice() const
{
	return this->price;
}

int TravelPack::getMaxBookings() const
{
	return this->maxBookings;
}

int TravelPack::getCurrentBookings() const
{
	return this->currentBookings;
}

#pragma endregion

#pragma region SETTERS

bool TravelPack::setDestinations(const std::vector<std::string>& destinations)
{
	if (destinations.empty())
		return false;

	this->destinations = vector<string>(destinations);
	return true;;
}

bool TravelPack::setDeparture(const Date departureDate)
{
	if (departureDate > this->returnDate)
		return false;

	this->departureDate = departureDate;
	return true;
}

bool TravelPack::setReturn(const Date returnDate)
{
	if (returnDate < this->departureDate)
		return false;

	this->returnDate = returnDate;
	return true;
}

bool TravelPack::setPrice(const int price)
{
	if (price < 0)
		return false;

	this->price = price;
	return true;
}

bool TravelPack::setMaxBookings(const int maxBookings)
{
	if (maxBookings <= 0 || maxBookings < this->currentBookings)
		return false;

	this->maxBookings = maxBookings;
	return true;
}

bool TravelPack::setCurrentBookings(int currentBookings)
{
	if (currentBookings < 0 || currentBookings > this->maxBookings)
		return false;

	this->currentBookings = currentBookings;
	return true;
}

#pragma endregion

void TravelPack::printSummary()
{
	cout << "Main destination: " << this->destinations.front() << endl;
	cout << "       Departure: " << this->departureDate << endl;
	cout << "          Return: " << this->returnDate << endl;
	cout << "           Price: " << this->price << endl;
	cout << "Avaiable tickets: " << (this->maxBookings - this->currentBookings) << endl;
}

std::ostream& operator<<(std::ostream& stream, const TravelPack& pack)
{
	stream << setw(PACK_OUTPUT_ALIGNMENT) << "Id: " << pack.id << endl;

	stream << setw(PACK_OUTPUT_ALIGNMENT) << "Destinations: " << pack.destinations.front();
	if (pack.destinations.size() != 1)
	{
		stream << " - ";

		for (size_t i = 1; i < pack.destinations.size() - 1; i++)
		{
			stream << pack.destinations.at(i) << ", ";
		}

		stream << pack.destinations.back();
	}
	stream << endl;

	stream << setw(PACK_OUTPUT_ALIGNMENT) << "Departure: " << pack.departureDate << endl;
	stream << setw(PACK_OUTPUT_ALIGNMENT) << "Fim: " << pack.returnDate << endl;

	stream << setw(PACK_OUTPUT_ALIGNMENT) << "Price: " << pack.price << endl;
	stream << setw(PACK_OUTPUT_ALIGNMENT) << "Max Bookings: " << pack.maxBookings << endl;
	stream << setw(PACK_OUTPUT_ALIGNMENT) << "Current Bookings: " << pack.currentBookings << endl;

	return stream;
}

std::ofstream& operator<<(std::ofstream& stream, const TravelPack& pack)
{
	stream << pack.id << endl;

	stream << pack.destinations.front();
	if (pack.destinations.size() != 1)
	{
		stream << " - ";

		for (size_t i = 1; i < pack.destinations.size() - 1; i++)
		{
			stream << pack.destinations.at(i) << ", ";
		}

		stream << pack.destinations.back();
	}
	stream << endl;

	stream << pack.departureDate << endl;
	stream << pack.returnDate << endl;
	stream << pack.price << endl;
	stream << pack.maxBookings << endl;
	stream << pack.currentBookings << endl;
	return stream;
}
