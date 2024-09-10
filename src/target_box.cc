#include <target_box.hh>
#include <target_progress_box.hh>

// Resources

TargetBox::TargetBox(void* data) : m_data(data) {
	this->set_ui();
}

void TargetBox::set_data(void* value) {
	this->m_data = value;
}

void* TargetBox::get_data() {
	return this->m_data;
}

void TargetBox::set_ui() {
	this->set_orientation(Gtk::Orientation::HORIZONTAL);
	this->set_margin_top(20);
	this->set_margin_bottom(20);
	this->m_nb.set_halign(Gtk::Align::CENTER);
	this->m_nb.set_size_request(900, -1);
	this->m_nb.set_tab_pos(Gtk::PositionType::LEFT);

	// Make tab boxes
	auto hbx_1 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_2 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_3 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_4 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

	// Make labels
	auto lbl_1 = Gtk::make_managed<Gtk::Label>("Progress");
	auto lbl_2 = Gtk::make_managed<Gtk::Label>("History");
	auto lbl_3 = Gtk::make_managed<Gtk::Label>("Statistics");
	auto lbl_4 = Gtk::make_managed<Gtk::Label>("Settings");

	hbx_1->append(*lbl_1);
	hbx_2->append(*lbl_2);
	hbx_3->append(*lbl_3); 
	hbx_4->append(*lbl_4);

	// Make views for pages
	auto viw_1 = Gtk::make_managed<TargetProgressBox>(nullptr);
	auto viw_2 = Gtk::make_managed<Gtk::Label>("History View");
	auto viw_3 = Gtk::make_managed<Gtk::Label>("Statistics View");
	auto viw_4 = Gtk::make_managed<Gtk::Label>("Settings View");

	// Add pages
	this->m_nb.append_page(*viw_1, *hbx_1);
	this->m_nb.append_page(*viw_2, *hbx_2);
	this->m_nb.append_page(*viw_3, *hbx_3);
	this->m_nb.append_page(*viw_4, *hbx_4);

    this->m_nb.set_expand(true);

	this->append(this->m_nb);
}