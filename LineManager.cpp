// Name: ANTONIO BENNETT
// Seneca Student ID: 118914183
// Seneca email: ABENNETT13@MYSENECA.CA
// Date of completion: November 26, 2019 *Think I left this out in MS1*
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"	

LineManager::LineManager(const std::string link, std::vector<Task*> &vec, std::vector<CustomerOrder> &cus)
{
	size_t index = 0;
	Utilities temp;
	std::string record, token;
	bool more = true;
	m_cntCustomerOrder = cus.size();

	std::ifstream file(link);

	if (file)
	{
		while (!file.eof())
		{
			more = true;
			std::getline(file, record);
			while (more)
			{
				token = temp.extractToken(record, index, more);
				size_t i = 0;
				while (i < vec.size() && more)
				{
					if (token == vec[i]->getName())
					{
						while (more)
						{
							if (index != 0)
							{
								token = temp.extractToken(record, index, more);
								size_t j = 0;
								while (j < vec.size() && more)
								{
									if (token == vec[j]->getName())
									{
										vec[i]->setNextTask(*vec[j]);
										more = false;
									}
									j++;
								}
							}
							more = false;
						}
					}
					i++;
				}
			}
		}
	}
	for (size_t i = 0; i < cus.size(); i++)
	{
		ToBeFilled.push_front(std::move(cus[i]));
	}
	AssemblyLine = vec;
}
bool LineManager::run(std::ostream& os)
{
	CustomerOrder temp;

	if (!ToBeFilled.empty())
	{
		*AssemblyLine[4] += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}

	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), [&](Task* i) {
		i->runProcess(os);
		});

	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), [&](Task* i) {

		i->moveTask();

		if (i->getCompleted(temp))
			Completed.push_back(std::move(temp));

		
		});

	return (Completed.size() == m_cntCustomerOrder) ? true : false;

}
void LineManager::displayCompleted(std::ostream& os) const
{
	for (size_t i = 0; i < Completed.size(); i++)
		Completed[i].display(os);
}
void LineManager::validateTasks() const
{
	for (size_t i = 0; i < AssemblyLine.size(); i++)
		AssemblyLine[i]->validate(std::cout);
}