#ifndef MODELS_HPP
#define MODELS_HPP

#include <gtkmm.h>

class ListModel : public Gtk::TreeModel::ColumnRecord {
	public:
		ListModel();
		~ListModel();
		
		Gtk::TreeModelColumn<Glib::ustring> name;
		Gtk::TreeModelColumn<Glib::ustring> medium;
		Gtk::TreeModelColumn<Glib::ustring> genre;
};

#endif
