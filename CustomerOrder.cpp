// Name: ANTONIO BENNETT
// Seneca Student ID: 118914183
// Seneca email: ABENNETT13@MYSENECA.CA
// Date of completion: November 26, 2019 *Think I left this out in MS1*
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder()
{
	std::string m_name = "";
	std::string m_product = "";
	m_lstItem = nullptr;
}
CustomerOrder::CustomerOrder(std::string& record)
{
	size_t index = 0;
	size_t temp3 = 0;
	unsigned int temp4 = 0;
	bool x = true;
	Utilities temp;
	std::string temp2;

	m_name = temp.extractToken(record, index, x);
	

	m_product = temp.extractToken(record, index, x);
    
	temp3 = index;

	while (index != 0)
	{
		temp2 = temp.extractToken(record, index, x);
		++temp4;
	}
	x = true;
	index = temp3;
	m_cntItem = temp4;
	temp4 = 0;
	m_lstItem = new ItemInfo*[m_cntItem];
	
	while (temp4 < m_cntItem)
	{
		m_lstItem[temp4] = new ItemInfo(temp.extractToken(record, index, x));
		++temp4;
	}
	

	if (m_widthField < temp.getFieldWidth())
		m_widthField = temp.getFieldWidth();
}
CustomerOrder::CustomerOrder(CustomerOrder& copy)
{
	throw "It's wrong";
}
CustomerOrder::CustomerOrder(CustomerOrder&& move_copy) noexcept
{
	*this = std::move(move_copy);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& move_assign)
{
	if (this != &move_assign)
	{
		if (this->m_cntItem > 0)
		{
			for (size_t i = 0; i < this->m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete m_lstItem;
		}
		m_lstItem = move_assign.m_lstItem;
		m_name = move_assign.m_name;
		m_product = move_assign.m_product;
		m_cntItem = move_assign.m_cntItem;

		move_assign.m_lstItem = nullptr;
		move_assign.m_name = "";
		move_assign.m_product = "";
		move_assign.m_cntItem = 0;
	}

	return *this;
}
CustomerOrder::~CustomerOrder()
{
	for (size_t i = 0; i < this->m_cntItem; i++)
	{
		delete m_lstItem[i];
	}
	delete m_lstItem;
}
bool CustomerOrder::getItemFillState(std::string name) const
{
	for (size_t i = 0; i < this->m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == name)
			return m_lstItem[i]->m_fillState;
	}

	return true;
}
bool CustomerOrder::getOrderFillState() const
{
	bool all = true;
	for (size_t i = 0; i < this->m_cntItem; i++)
	{
		if (m_lstItem[i]->m_fillState == false)
			all = false;
	}
	return all;
}
void CustomerOrder::fillItem(Item& item, std::ostream& os)
{
	for (size_t i = 0; i < this->m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == item.getName())
		{
			if (item.getQuantity() > 0)
			{
				item.updateQuantity();
				m_lstItem[i]->m_fillState = true;
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			else
				os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;

		}
	}
}
void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++)
	{
		os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << std::left << std::setfill(' ') << "] " << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
	}
}