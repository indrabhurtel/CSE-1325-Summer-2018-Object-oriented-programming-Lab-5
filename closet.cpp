//INDRA BHURTEL

#include "closet.h"
#include <iostream>
#include <gtkmm.h>
#include <vector>
#include <string>

using namespace std;
using namespace Gtk;

vector <string> items;
vector <float> item_price;
float price;
float money_made=0.00;

static void vectors(){
		for(int i=0;i<(int)items.size();i++)
            {cout<<items[i]<<endl;
			cout<<item_price[i]<<endl;}}

void Buying_item::search_item(string text) { //function to buy items
		Dialog *dialog=new Dialog();
		dialog->set_title("Closet");
		string space="";

   	 for(int i=0;i<(int)items.size();i++){
			if(items[i]==text){
				space="check";

				string text_sell="We have ";
				text_sell.append(text);
				text_sell.append("(s) for $");
				text_sell.append(to_string(item_price[i]));
				text_sell.append(". Would you like to buy it?");

				Label *labell=new Label(text_sell);
				dialog->get_content_area()->pack_start(*labell);
				labell->show();

                dialog->add_button("Yes",1);
				dialog->add_button("No",2);
				dialog->add_button("Cancel",0);

				int result=dialog->run();
				dialog->close();
                delete labell;

                if(result==1){
                money_made+=item_price[i];}
				break;}}

            if(space==""){
			Label *labelll=new Label("I'm sorry, we don't have that.");
			dialog->get_content_area()->pack_start(*labelll);
			labelll->show();

			dialog->add_button("Confirm",0);
            dialog->run();
            dialog->close();

			while(Main::events_pending()){
				Main::iteration();}
                delete labelll;}
                space="";
                delete dialog;}

void Buying_item::search_item() { // function for searching an item
		Dialog *dialog=new Dialog();
		dialog->set_title("Business");

		Label *label=new Label("What are you looking for?");
		dialog->get_content_area()->pack_start(*label);
		label->show();

		dialog->add_button("Cancel",0);
		dialog->add_button("OK",1);

		Entry *entry=new Entry();
		entry->set_text("");
		entry->set_max_length(60);
		entry->show();
		dialog->get_vbox()->pack_start(*entry);

		int result=dialog->run();
		string text=entry->get_text();

		dialog->close();

		while(Main::events_pending()){
        Main::iteration();}
        delete dialog;
		delete label;
		delete entry;

		if(result==1){
			Buying_item::search_item(text);}} // searching for the item

void Check_balance::view_balance(){ // function for checking balance
      		 Dialog *dialog=new Dialog();
		dialog->set_title("Shopping Time: Total");
		string text_income=to_string(money_made);
		string dollar_sign="$";

		string show_income = dollar_sign.append(text_income);
		Label *label=new Label("Your total is: ");
		dialog->get_content_area()->pack_start(*label);
		label->show();
		Label *label_income=new Label(show_income);
		dialog->get_content_area()->pack_start(*label_income);
		label_income->show();
		dialog->add_button("OK",1);
		dialog->run();
		dialog->close();
		while(Main::events_pending()){
		Main::iteration();}
        delete dialog;
		delete label;
		delete label_income;}

			void Closet::add_items(int num){ // function to save item
                                for(int i=0; i<num;i++){

								Entry *EntryFirst=new Entry();
								Entry *EntrySecond=new Entry();
								EntryFirst->set_text("");
								EntrySecond->set_text("");
								EntryFirst->set_max_length(50);
								EntrySecond->set_max_length(50);
								Dialog* dialog=new Dialog();
								dialog->set_title("Item for sale");

								Label *labelFirst=new Label("Enter name of an item: ");
								dialog->get_content_area()->pack_start(*labelFirst);
								labelFirst->show();
								EntryFirst->show();
								dialog->get_vbox()->pack_start(*EntryFirst);

								Label *labelSecond=new Label("Enter price of an item: ");
								dialog->get_content_area()->pack_start(*labelSecond);
								labelSecond->show();

								dialog->add_button("Cancel",0);
								dialog->add_button("OK",1);
								EntrySecond->show();
								dialog->get_vbox()->pack_start(*EntrySecond);

                                int result=dialog->run();
								string text_item=EntryFirst->get_text();
								string text_price=EntrySecond->get_text();

								dialog->close();

								while(Main::events_pending()){
									Main::iteration();}

								delete dialog;
								delete labelFirst;
								delete labelSecond;
								delete EntryFirst;
								delete EntrySecond;

								if(result==1){
									items.push_back(text_item);
                                    price=strtof((text_price).c_str(),0);
									item_price.push_back(price);}else
                                    exit(0);}
						}

			void Closet::input(string name, int num_item){
							MessageDialog *dialog=new MessageDialog(" Shopping Time");
							string sentence=name;
                            sentence.append(" has ");
							sentence.append(to_string(num_item));
							sentence.append(" items.");
							dialog->set_secondary_text(sentence);
                            dialog->add_button("Entering  Shopping",1);
                            int result=dialog->run();
                            dialog->close();
                            while(Main::events_pending()){
                            Main::iteration();}
                            delete dialog;

							if(result==1){
                            add_items(num_item);}else
                            exit(0);}

			void Buy_checkBalance_exit::ask_action(string name){
							Dialog *dialog=new Dialog();
							dialog->set_title("Choose from the buttons below");


							Label *label_one=new Label(name);
							Label *label_two=new Label("  Welcome to Shopping place");

                            dialog->get_content_area()->pack_start(*label_one);
							dialog->get_content_area()->pack_start(*label_two);

                            label_one->show();
							label_two->show();

							dialog->add_button("Buy",1);
							dialog->add_button("Check balance",2);
							dialog->add_button("Exit",0);

							int result=dialog->run();
                            dialog->close();

							while(Main::events_pending()){
                            Main::iteration();}
                            delete dialog;
                            delete label_one;
							delete label_two;

						if(result==1){
                        Buying_item::search_item();}
                        else if(result==2){
						Check_balance::view_balance();}else
                        exit(0);}

			string Dialogs::enter_name(string msg, string title){
							Dialog *dialog=new Dialog();
							dialog->set_title(title);

							Label *label=new Label(msg);
							dialog->get_content_area()->pack_start(*label);
							label->show();

							dialog->add_button("Cancel",0);
							dialog->add_button("OK",1);

						Entry *entry=new Entry();
						entry->set_text("");
						entry->set_max_length(60);
						entry->show();
						dialog->get_vbox()->pack_start(*entry);

						int result=dialog->run();
						string text=entry->get_text();
                        dialog->close();

						while(Main::events_pending()){
                        Main::iteration();}
                        delete dialog;
						delete label;
						delete entry;

						if(result==1){
							return text;}else
							return "CANCEL";}

			string Dialogs::enter_num(string msg, string title)
					{
						Dialog *num_dialog=new Dialog();
						num_dialog->set_title(title);

						Label *num_label=new Label(msg);
						num_dialog->get_content_area()->pack_start(*num_label);
						num_label->show();

						num_dialog->add_button("Cancel",0);
						num_dialog->add_button("OK",1);

						Entry *entry=new Entry();
						entry->set_text("");
						entry->set_max_length(60);
						entry->show();
						num_dialog->get_vbox()->pack_start(*entry);

						int result=num_dialog->run();
						string number=entry->get_text();
                        num_dialog->close();

						while(Main::events_pending()){
                        Main::iteration();}

						delete num_dialog;
						delete num_label;
						delete entry;
                        if(result==1){
							return number;} else
							return "CANCEL";}

