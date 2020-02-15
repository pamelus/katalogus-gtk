#ifndef DATA_HPP
#define DATA_HPP

#include <ustring.h>

class Data {
	protected:
		Glib::ustring name;
		Glib::ustring more;
	public:
		Data();
		Data(Glib::ustring iName, Glib::ustring iMore);
		virtual ~Data();
		
};

#endif
