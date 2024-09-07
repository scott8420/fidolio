#ifndef __UTILS__
#define __UTILS__

#include <gtkmm.h>
#include <glibmm.h>

class Utils {
public:
	static Glib::ustring create_uuid();
	static void msg_box(Gtk::Window*, const Glib::ustring&, const Glib::ustring&);
	static Glib::RefPtr<Gdk::Pixbuf> image_from_name(const Glib::ustring&);
	static Glib::RefPtr<Gdk::Pixbuf> image_from_xpm(const char *const *);
protected:
	Utils(){}
};

#endif
