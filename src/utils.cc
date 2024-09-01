#include <utils.hh>
#include <glib/guuid.h>

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