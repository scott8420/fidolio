#include <project_box.hh>

ProjectBox::ProjectBox(void* data) : m_data(data) {

	this->set_ui();
}

void ProjectBox::set_data(void* value) {
	this->m_data = value;
}

void* ProjectBox::get_data() {
	return this->m_data;
}

void ProjectBox::set_ui() {
	this->set_orientation(Gtk::Orientation::HORIZONTAL);
	this->set_margin(0);

	// Make tab boxes
	auto proj_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto auth_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto targ_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto styl_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto keyb_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto pref_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

	// Make labels
	auto proj_lbl = Gtk::make_managed<Gtk::Label>("Project");
	auto auth_lbl = Gtk::make_managed<Gtk::Label>("Author");
	auto targ_lbl = Gtk::make_managed<Gtk::Label>("Target");
	auto styl_lbl = Gtk::make_managed<Gtk::Label>("Text Styles");
	auto keyb_lbl = Gtk::make_managed<Gtk::Label>("Keyboard Shortcuts");
	auto pref_lbl = Gtk::make_managed<Gtk::Label>("Preferences");

	// Append labels to boxes
	proj_hbx->append(*proj_lbl);
	auth_hbx->append(*auth_lbl);
	targ_hbx->append(*targ_lbl); 
	styl_hbx->append(*styl_lbl); 
	keyb_hbx->append(*keyb_lbl);
	pref_hbx->append(*pref_lbl);

	// Make views for pages
	auto proj_viw = Gtk::make_managed<Gtk::Label>("Project View");
	auto auth_viw = Gtk::make_managed<Gtk::Label>("Author View");
	auto targ_viw = Gtk::make_managed<Gtk::Label>("Target View");
	auto styl_viw = Gtk::make_managed<Gtk::Label>("Styles View");
	auto keyb_viw = Gtk::make_managed<Gtk::Label>("Keyboard Shortcuts View");
	auto pref_viw = Gtk::make_managed<Gtk::Label>("Preferences View");

	// Add pages
	this->m_nb.append_page(*proj_viw, *proj_hbx);
	this->m_nb.append_page(*auth_viw, *auth_hbx);
	this->m_nb.append_page(*targ_viw, *targ_hbx);
	this->m_nb.append_page(*styl_viw, *styl_hbx);
	this->m_nb.append_page(*keyb_viw, *keyb_hbx);
	this->m_nb.append_page(*pref_viw, *pref_hbx);

    this->m_nb.set_expand(true);

	this->append(this->m_nb);
}
