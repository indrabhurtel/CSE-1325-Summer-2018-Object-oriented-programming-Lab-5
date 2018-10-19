//INDRA BHURTEL


#ifndef _closet_h
#define _closet_h

#include <iostream>
#include <gtkmm.h>
#include <vector>
#include <string>

using namespace std;
using namespace Gtk;

class Testing{ //Testing class
public:
static void vectors();
};

class Buying_item{ // Buying_item class
public:
static void search_item(string text);
static void search_item();
};

class Check_balance{ // Check_balance class
public:
static void view_balance();
};

class Closet{ // Closet class
public:
static void add_items(int num);
static void input(string name, int num_item);
};

class Buy_checkBalance_exit{ // Buy_checkBalance_exit class
public:
static void ask_action(string name);
};

class Dialogs{ // Dialogs class
public:
	static string enter_name(string msg, string title);
	static string enter_num(string msg, string title);
};
#endif

