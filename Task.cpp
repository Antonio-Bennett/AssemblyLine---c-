// Name: ANTONIO BENNETT
// Seneca Student ID: 118914183
// Seneca email: ABENNETT13@MYSENECA.CA
// Date of completion: November 26, 2019 *Think I left this out in MS1*
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Task.h"

Task::Task(const std::string& record) : Item(record)
{
	m_pNextTask = nullptr;
}
void Task::runProcess(std::ostream& os)
{
	if (!m_orders.empty())
	{
		while (!m_orders.back().getItemFillState(this->getName()))
		{
			m_orders.back().fillItem(*this, os);
		}
	}
}
bool Task::moveTask()
{
	if (!m_orders.empty())
		if (m_orders.back().getItemFillState(this->getName()))
		{
			if(m_pNextTask != nullptr)
			{
				*m_pNextTask += std::move(m_orders.back());
				m_orders.pop_back();
				return true;
			}
		}

	return false;
}
void Task::setNextTask(Task& next)
{
	m_pNextTask = &next;
}
bool Task::getCompleted(CustomerOrder& order)
{
	if (!this->m_orders.empty())
	{
		if(m_orders.back().getOrderFillState())
		{
			order = std::move(this->m_orders.back());
			this->m_orders.pop_back();
			return true;
		}
	}
	return false;
}

void Task::validate(std::ostream& val)
{
	if (m_pNextTask == nullptr)
		val << this->getName() << " --> END OF LINE" << std::endl;
	else
		val << this->getName() << " --> " << m_pNextTask->getName() << std::endl;
}
Task& Task::operator+=(CustomerOrder&& something)
{
	m_orders.push_front(std::move(something));
	return *this;
}