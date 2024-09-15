#include <author_box.hh>

// Resources
AuthorBox::AuthorBox(void* data) : m_data(data) {

	this->set_ui();
}

void AuthorBox::set_data(void* value) {
	this->m_data = value;
}

void* AuthorBox::get_data() {
	return this->m_data;
}

void AuthorBox::set_ui() {
	this->set_orientation(Gtk::Orientation::HORIZONTAL);
	this->set_margin(0);

	// Make tab boxes
	auto name_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto emai_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto biog_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	
	// Make labels
	auto name_lbl = Gtk::make_managed<Gtk::Label>("Name: ");
	auto emai_lbl = Gtk::make_managed<Gtk::Label>("Author: ");
	auto biog_lbl = Gtk::make_managed<Gtk::Label>("Bio: ");

}