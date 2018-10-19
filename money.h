//INDRA BHURTEL
//1001542825

#ifndef _MONEY_H
#define _MONEY_H

#include <vector>
#include <iostream>
#include <gtkmm.h>
#include <string>

using namespace std;

class Dialogs
{
public:
	static int message(string msg, string title);

	static string input(string msg, string title);
};

#endif
