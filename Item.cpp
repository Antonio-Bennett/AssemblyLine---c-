// Name: ANTONIO BENNETT
// Seneca Student ID: 118914183
// Seneca email: ABENNETT13@MYSENECA.CA
// Date of completion: November 26, 2019 *Think I left this out in MS1*
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Item.h"

size_t Item::m_widthField = 0;

Item::Item(const std::string& record)
{
	size_t index = 0;
	bool x = true;
	Utilities temp;


	m_name = temp.extractToken(record, index, x);
	if (m_widthField < m_name.length())
		m_widthField = m_name.length();

	m_serialNumber = std::stoi(temp.extractToken(record, index, x));
	m_quantity = std::stoi(temp.extractToken(record, index, x));
	m_description = temp.extractToken(record, index, x);
}
const std::string& Item::getName() const
{
	return m_name;
}
const unsigned int Item::getSerialNumber()
{
	return m_serialNumber++;
}
const unsigned int Item::getQuantity()
{
	return m_quantity;
}
void Item::updateQuantity()
{
	if (m_quantity > 0)
		--m_quantity;
}
void Item::display(std::ostream& os, bool full) const
{
	if (full)
		os << std::setw(m_widthField) << std::left << m_name << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << std::left << std::setfill(' ') << "] Quantity: " << std::setw(m_widthField) << m_quantity << " Description: " << m_description << std::endl;
	else
		os << std::setw(m_widthField) << std::left << m_name << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << std::left << std::setfill(' ') << "]" << std::endl;

}