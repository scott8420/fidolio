#include <gdkmm.h>
#include <glib/guuid.h>
#include <globals.hh>
#include <sstream>
#include <iomanip>
#include <utils.hh>

// Resources
#include <defaultauthor.xpm>
#include <defaultcover.xpm>
#include <question.xpm>
#include <western.xpm>

Glib::ustring Utils::create_uuid() {
  return Glib::ustring(g_uuid_string_random());
}

void Utils::msg_box(Gtk::Window *parent, const Glib::ustring &message,
					const Glib::ustring &detail) {
  // Creates a referenced smartpointer which will destroy itself when done
  auto dlg = Gtk::AlertDialog::create();
  dlg->set_message(message);
  dlg->set_detail(detail);
  dlg->set_buttons({});
  dlg->set_default_button(-1);
  dlg->set_cancel_button(-1);
  dlg->show(*parent);
}

Glib::RefPtr<Gdk::Pixbuf> Utils::image_from_xpm(const char *const *data) {
  return Gdk::Pixbuf::create_from_xpm_data(data);
}

Glib::RefPtr<Gdk::Pixbuf> Utils::image_from_name(const Glib::ustring &name) {
  if (name.lowercase() == "western") {
	return Utils::image_from_xpm(western);
  } else if (name.lowercase() == "question") {
	return Utils::image_from_xpm(question);
  } else if (name.lowercase() == "defaultcover") {
	return Utils::image_from_xpm(defaultcover);
  } else if (name.lowercase() == "defaultauthor") {
	return Utils::image_from_xpm(defaultauthor);
  }

  return Utils::image_from_xpm(question);
}

Glib::RefPtr<Gdk::RGBA> Utils::hex_to_rgba(const Glib::ustring &hex) {
	// returns a gray color if it fails
	// Format is in "xRRGGBBAA"

	Glib::RefPtr<Gdk::RGBA> color(new Gdk::RGBA(0.5f, 0.5f, 0.5f, 1.0f));
	std::stringstream ss;
	int r, g, b, a;
	Glib::ustring type = hex.substr(0, 2).uppercase();

	if ((hex.length() != 10) || (type != "0X")) {
		return color;
	}
		
	ss << std::hex << hex.substr(2, 2);
	ss >> r;
	ss.clear();
	ss << std::hex << hex.substr(4, 2);
	ss >> g;
	ss.clear();
	ss << std::hex << hex.substr(6, 2);
	ss >> b;
	ss.clear();
	ss << std::hex << hex.substr(8, 2);
	ss >> a;

	color->set_red(gdouble(r) / 255.0f);   // Red component (0.0 to 1.0)
	color->set_green(gdouble(g) / 255.0f); // Green component (0.0 to 1.0)
	color->set_blue(gdouble(b) / 255.0f);  // Blue component (0.0 to 1.0)
	color->set_alpha(gdouble(a) / 255.0f); // Alpha component (0.0 to 1.0)

	return color;
}

const Glib::ustring Utils::rgba_to_hex(const Gdk::RGBA& color) {
	// Format is in "xRRGGBBAA"

	int r = int(color.get_red() * 255.0f);
	int g = int(color.get_green() * 255.0f);
	int b = int(color.get_blue() * 255.0f);
	int a = int(color.get_alpha() * 255.0f);

	std::stringstream ss;
	ss << "0x" << std::hex << std::setfill('0') << std::setw(2) << r;
	ss << std::hex << std::setfill('0') << std::setw(2) << g;
	ss << std::hex << std::setfill('0') << std::setw(2) << b;
	ss << std::hex << std::setfill('0') << std::setw(2) << a;

	return Glib::ustring(ss.str().c_str());
}

bool Utils::dark_mode_on() {
	auto settings = Gtk::Settings::get_default();
	auto theme_name = settings->property_gtk_theme_name().get_value();
    return theme_name.find("dark") != std::string::npos;
}
