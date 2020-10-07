// Name: ANTONIO BENNETT
// Seneca Student ID: 118914183
// Seneca email: ABENNETT13@MYSENECA.CA
// Date of completion: November 26, 2019 *Think I left this out in MS1*
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

char Utilities::m_delimiter = ',';

void Utilities::setFieldWidth(size_t w)
{
	m_wifthField = w;
}
size_t Utilities::getFieldWidth() const
{
	return m_wifthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string temp;

	if (str.at(next_pos) == m_delimiter)
		throw "No token between delimeters";

	size_t delim = str.find_first_of(m_delimiter, next_pos);
	temp = str.substr(next_pos, (delim - next_pos));

	if (!temp.empty())
	{
		next_pos = delim + 1;
		more = true;
		if (m_wifthField < temp.length())
			m_wifthField = temp.length();
		return temp;
	}

	return temp;
}
void Utilities::setDelimiter(const char d)
{
	m_delimiter = d;
}
const char Utilities::getDelimiter() const
{
	return m_delimiter;
}