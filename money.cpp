//INDRA BHURTEL

#include "money.h"

using namespace std;
using namespace Gtk;


	 int Dialogs::message(string msg, string title)
	{
		MessageDialog *dialog = new MessageDialog(title);
		dialog->set_secondary_text(msg, true);

		dialog->add_button("Cancel", 0);

		int result = dialog->run();

		dialog->close();
		while(Gtk::Main::events_pending())
			Gtk::Main::iteration();

		delete dialog;

		if (result == 0)
			return 0;
		else
			return 1;
}

	 string Dialogs::input(string msg, string title){
		Gtk::Dialog *dialog = new Gtk::Dialog();
		dialog->set_title(title);

		Gtk::Label *label = new Gtk::Label(msg);
		dialog->get_content_area()->pack_start(*label);
		label->show();

		dialog->add_button("Cancel", 0);
		dialog->add_button("OK", 1);

		Gtk::Entry *entry = new Gtk::Entry();
		entry->set_text("");
		entry->set_max_length(60);
		entry->show();
		dialog->get_vbox()->pack_start(*entry);

		int result = dialog->run();
		std::string text = entry->get_text();

		dialog->close();
		while(Gtk::Main::events_pending())
			Gtk::Main::iteration();

		delete dialog;
		delete label;
		delete entry;

		if(result == 1)
			return text;
		else
			return "CANCEL";
	}
