#include <utils.hh>
#include <glib/guuid.h>
#include <gdkmm.h>
#include <globals.hh>

#include <sstream>

// Resources

#include <western.xpm>
#include <question.xpm>
#include <defaultcover.xpm>
#include <defaultauthor.xpm>

Glib::ustring Utils::create_uuid() {
	return Glib::ustring(g_uuid_string_random());
}

void Utils::msg_box(Gtk::Window* parent, const Glib::ustring& message, const Glib::ustring& detail) {
	// Creates a referenced smartpointer which will destroy itself when done
	auto dlg = Gtk::AlertDialog::create();
    dlg->set_message(message);
    dlg->set_detail(detail);
    dlg->set_buttons({});
    dlg->set_default_button(-1);
    dlg->set_cancel_button(-1);
    dlg->show(*parent);
}

Glib::RefPtr<Gdk::Pixbuf> Utils::image_from_xpm(const char *const * data) {
    return Gdk::Pixbuf::create_from_xpm_data(data);
}

Glib::RefPtr<Gdk::Pixbuf> Utils::image_from_name(const Glib::ustring& name) {
    if(name.lowercase() == "western") {
       return Utils::image_from_xpm(western);
    } else if(name.lowercase() == "question") {
        return Utils::image_from_xpm(question);
    } else if(name.lowercase() == "defaultcover") {
        return Utils::image_from_xpm(defaultcover);
    } else if(name.lowercase() == "defaultauthor") {
        return Utils::image_from_xpm(defaultauthor);
    }
    
    return Utils::image_from_xpm(question);
}

Glib::RefPtr<Gdk::RGBA> Utils::hex_to_rgba(const Glib::ustring& str) {
    // returns a gray color if it fails
    // Format is in "xRRGGBBAA"

    Glib::RefPtr<Gdk::RGBA> color(new Gdk::RGBA(0.5f, 0.5f, 0.5f, 1.0f));
    std::stringstream ss;
    int r, g, b, a;

    if (str.length() != 9 || str[0] != 'x')
        return color;

    ss << std::hex << str.substr(1, 2).c_str();
    ss >> r;
    ss.clear();
    ss << std::hex << str.substr(3, 2).c_str();
    ss >> g;
    ss.clear();
    ss << std::hex << str.substr(5, 2).c_str();
    ss >> b;
    ss.clear();
    ss << std::hex << str.substr(7, 2).c_str();
    ss >> a;

    color->set_red(gdouble(r)/255.0f);   // Red component (0.0 to 1.0)
    color->set_green(gdouble(g)/255.0f); // Green component (0.0 to 1.0)
    color->set_blue(gdouble(b)/255.0f);  // Blue component (0.0 to 1.0)
    color->set_alpha(gdouble(a)/255.0f); // Alpha component (0.0 to 1.0)

    return color;
}