//INDRA BHURTEL


#include "closet.h"
#include <gtkmm.h>

using namespace std;
using namespace Gtk;

int main(int argc, char *argv[]){
	Main kit(argc,argv);
	string name=Dialogs::enter_name("Enter your name: ","SHOPPING");
	string item_num=Dialogs::enter_num("Enter number of items: ","SHOPPING");
	int number=stoi(item_num.c_str());
	Closet::input(name,number);

	while(true)
	{
		Buy_checkBalance_exit::ask_action(name);
	}
	return 0;
}
