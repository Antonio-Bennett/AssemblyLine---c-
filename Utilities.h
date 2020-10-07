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
#include <sstream>

class Utilities
{
	size_t m_wifthField = 1;
	static char m_delimiter;
public:
	void setFieldWidth(size_t w);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char d);
	const char getDelimiter() const;
};