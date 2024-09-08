#include <utils.hh>
#include <glib/guuid.h>
#include <gdkmm.h>
#include <globals.hh>

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