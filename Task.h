// Name: ANTONIO BENNETT
// Seneca Student ID: 118914183
// Seneca email: ABENNETT13@MYSENECA.CA
// Date of completion: November 26, 2019 *Think I left this out in MS1*
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

#include <iostream>
#include <deque>
#include <string>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item
{
	std::deque<CustomerOrder> m_orders;
	Task *m_pNextTask;
public:
	Task(const std::string& record);
	Task(Task& copy) = delete;
	Task& operator=(Task& copy_assign) = delete;
	void runProcess(std::ostream& os);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};
