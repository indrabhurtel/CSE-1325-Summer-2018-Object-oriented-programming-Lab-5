//INDRA BHURTEL

#include "money.h"
#include <vector>
#include <string>


class Money_Converter{ // MoneyConverter class

    public:
        vector <string> money;
        vector <double> money_value;

        Money_Converter(string location){
            if (location == "North" || location == "East") {
                money.push_back("Pound");
                money.push_back("Peso");
                money.push_back("Yen");
                money.push_back("Rupees");

                money_value.push_back(1.31);
                money_value.push_back(0.054);
                money_value.push_back(0.0089);
                money_value.push_back(0.015);
            }
            else {
                money.push_back("Dinar");
                money.push_back("Sol");
                money.push_back("Euro");
                money.push_back("Loti");

                money_value.push_back(0.00084);
                money_value.push_back(0.31);
                money_value.push_back(1.17);
                money_value.push_back(0.076);

            }
            }
};

        double moneyMade = 0;

class Currency_exchange_office { // MoneyExchangeOffice class

    public:
        string office_Name; // Name of an office
        string manager_Name;  // Name of an office manager
        string Loc;

        Currency_exchange_office(string location){
            Loc = location;
            if (location == "North" || location == "East"){
                office_Name = "ABC Conversions";
                manager_Name = " Armin";
            }
            else {
                office_Name = "DEF Conversions";
                manager_Name = "Jep";

            }
            print();
        }

        void print(){
            double input;
            Money_Converter currencyyy(Loc);
            double money;
            string moneyy;

            Dialogs::message("Welcome to " + office_Name + "\nPlease contact manager"  + manager_Name +" if you have any complaints. ","");
            moneyy = Dialogs::input("What currency are you looking to convert to dollars? ","");
            input = stod(Dialogs::input("How much are you looking to convert to dollars",""),nullptr);


            for (int i = 0; i < currencyyy.money.size(); i++){
                if (currencyyy.money[i] == moneyy) {
                    money = input * currencyyy.money_value[i];
                    moneyMade+=money;
                    Dialogs::message("Here is your money in dollars: $" + to_string(money),"");
                    break;
                }
                else {
                    if (i == currencyyy.money.size() -1 ){
                    Dialogs::message("We don't convert the " + moneyy + "currency here. Sorry!!!","");

                    } else
                        continue;
                }
            }
        }
};

int main(int argc, char *argv[]){
        Gtk::Main kit(argc,argv);

    string input;

    while (true ) {

    input = Dialogs::input("Where are you in the airport? ","");
    if (input == "exit"){
        Dialogs::message("Total currency exchanged to dollars: $" + to_string(moneyMade),""); // print total dollars dispensed by both exchanges
        Dialogs::message("Thank you for using currency exchange machine :) :) "," Exiting.... ");

        break;
    }

    Currency_exchange_office direct(input);

    }

    return 0;
}
