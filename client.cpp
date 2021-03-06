#include "client.h"
#include "agency.h"
#include "customUtilities.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Client::Client()
{
	name = "John Doe";
	vat = 0;
	household = 1;
	address = Address();
	totalSpent = 0;
	travelPacks = {};
}

Client::Client(string name, unsigned vat, unsigned short household, Address address, vector<int> & travelPacks, unsigned totalSpent) {
	this->name = name;
	this->vat = vat;
	this->household = household;
	this->address = address;
	this->travelPacks = travelPacks;
	this->totalSpent = totalSpent;
}

#pragma region GETTERS

string Client::getName() const {
	return name;
}

unsigned Client::getVAT() const {
	return vat;
}

unsigned short Client::getHousehold() const {
	return household;
}

Address Client::getAddress() const {
	return address;
}

vector<int> Client::getTravelPacksList() const {
	return travelPacks;
}

size_t Client::getTravelPacksListSize() const
{
	return this->travelPacks.size();
}

int Client::getTravelPackAt(int index) const
{
	if (index < 0 || index >= (int) this->travelPacks.size())
		return 0;
	else
		return this->travelPacks.at(index);
}

unsigned Client::getTotalSpent() const {
	return totalSpent;
}

#pragma endregion

#pragma region SETTERS

bool Client::setName(string new_name) {
	if (new_name.empty()) return false;
	this->name = new_name;
	return true;
}

bool Client::setVAT(unsigned new_vat) {
		this->vat = new_vat;
		return true;
}

bool Client::setHousehold(unsigned short new_household) {
	if (new_household >= 1) {
		this->household = new_household;
		return true;
	}
	return false;
}

bool Client::setAddress(Address new_address) {
	this->address = new_address;
	return true;
}

bool Client::setTravelPacksList(vector<int> & new_travelPacks) {
	this->travelPacks = new_travelPacks;
	return true;
}

bool Client::setTotalSpent(unsigned new_totalSpent) {
	this->totalSpent = new_totalSpent;
	return true;
}

#pragma endregion

// OTHER PUBLIC METHODS

void Client::printSummary() const
{
	cout << left << setw(30) << this->name << right
		<< "    VAT: " << this->vat;
}

bool Client::hasBought(const int id) const
{
	for (size_t i = 0; i < this->travelPacks.size(); i++)
	{
		if (id == this->travelPacks.at(i))
			return true;
	}

	return false;
}

void Client::addPack(const int id, const int price, const int tickets)
{
	for (int i = 0; i < tickets; i++)
		this->travelPacks.push_back(id);

	this->totalSpent += price * tickets;
}

// OUTPUT STREAM OPERATOR OVERRIDES

ostream& operator<<(ostream& stream, const Client & client)
{
	stream << setw(CLIENT_OUTPUT_ALIGNMENT) << "Name: " << client.name << endl
		<< setw(CLIENT_OUTPUT_ALIGNMENT) << "VAT: " << client.vat << endl
		<< setw(CLIENT_OUTPUT_ALIGNMENT) << "Household: " << client.household << endl
		<< setw(CLIENT_OUTPUT_ALIGNMENT) << "Address: " << client.address << endl;

	if (client.travelPacks.empty())
		stream << setw(CLIENT_OUTPUT_ALIGNMENT) << "Packs: " << "No packs bought" << endl;
	else
	{
		stream << setw(CLIENT_OUTPUT_ALIGNMENT) << "Packs: " << client.travelPacks.front();

		for (size_t i = 1; i < client.travelPacks.size(); i++)
			stream << ", " << client.travelPacks.at(i);

		stream << endl;
	}

	stream << setw(CLIENT_OUTPUT_ALIGNMENT) << "Total spent: " << client.totalSpent;
	return stream;
}

ofstream& operator<< (ofstream & stream, const Client & client)
{
	stream << client.name << endl
		<< client.vat << endl
		<< client.household << endl
		<< client.address << endl;

	if (client.travelPacks.empty())
		stream << "-" << endl;
	else
	{
		stream << client.travelPacks.front();

		for (size_t i = 1; i < client.travelPacks.size(); i++)
			stream << " ; " << client.travelPacks.at(i);

		stream << endl;
	}

	stream << client.totalSpent;

	return stream;
}

// T1G02
// up201800170 Breno Accioly
// up201806516 Tiago Silva