/*************************/
/* InOut class as View   */
/*                       */
/*  Author: Holger Haupt */
/*    30.11.2022         */
/*                       */
/*************************/


#pragma once
#include <string>
#include <iostream>


class InOut
{
public:
	void print(const std::string& output);
	std::string scan();
	InOut(InOut&) = delete;
	InOut& operator=(InOut&) = delete;
	static InOut& getInstance();
private:
	InOut();
};

