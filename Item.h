// Name: ANTONIO BENNETT
// Seneca Student ID: 118914183
// Seneca email: ABENNETT13@MYSENECA.CA
// Date of completion: November 26, 2019 *Think I left this out in MS1*
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"

class Item
{
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;
	static size_t m_widthField;
public:

	Item(const std::string& record);
	const std::string& getName() const;
	//isnt size_t same as unsigned int 
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

