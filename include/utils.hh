#ifndef __UTILS__
#define __UTILS__

#include <gtkmm.h>

class Utils {
public:
	static Glib::ustring create_uuid();
	static void msg_box(Gtk::Window*, const Glib::ustring&, const Glib::ustring&);
	static Glib::RefPtr<Gdk::Pixbuf> image_from_name(const Glib::ustring&);
	static Glib::RefPtr<Gdk::Pixbuf> image_from_xpm(const char *const *);
	static Glib::RefPtr<Gdk::RGBA> hex_to_rgba(const Glib::ustring&);
	static const Glib::ustring rgba_to_hex(const Gdk::RGBA&);
	static bool dark_mode_on();
protected:
	Utils(){}
};

#define RED *(Utils::hex_to_rgba("0XE9175BFF"))
#define GRN *(Utils::hex_to_rgba("0X32A4CCFF"))
#define BLU *(Utils::hex_to_rgba("0X2D7DFFFF"))

#endif
