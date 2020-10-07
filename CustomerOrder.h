// Name: ANTONIO BENNETT
// Seneca Student ID: 118914183
// Seneca email: ABENNETT13@MYSENECA.CA
// Date of completion: November 19, 2019 *Think I left this out in MS1*
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

#include <iostream>
#include <string>
#include "Item.h"
#include <utility>

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder 
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem = 0;
	ItemInfo** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(std::string& record);
	CustomerOrder(CustomerOrder& copy);
	CustomerOrder& operator=(CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&& move_copy) noexcept;
	CustomerOrder& operator=(CustomerOrder&& move_assign);
	~CustomerOrder();
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream& os);
	void display(std::ostream& os) const;
};
