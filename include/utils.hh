#ifndef __UTILS__
#define __UTILS__

#include <gtkmm.h>
#include <glibmm.h>

class Utils {
public:
	static Glib::ustring create_uuid();
	static void msg_box(Gtk::Window*, const Glib::ustring&, const Glib::ustring&);
protected:
	Utils(){}
};



#endif
