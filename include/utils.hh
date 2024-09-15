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
	static Glib::RefPtr<Gdk::RGBA> hex_to_rgba(const Glib::ustring&);
protected:
	Utils(){}
};

#define RED *(Utils::hex_to_rgba("xcc3299ff"))
#define GRN *(Utils::hex_to_rgba("x63cc32ff"))
#define BLU *(Utils::hex_to_rgba("x32a4ccff"))

#endif
