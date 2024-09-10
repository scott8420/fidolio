#include <target_progress_box.hh>
#include <cctype>
#include <string>
#include <utils.hh>
#include <globals.hh>

// Resources
#include <target_progress_count_menu.ui>

TargetProgressBox::TargetProgressBox(void* data) : m_data(data) {

	this->set_ui();
}

void TargetProgressBox::set_data(void* value) {
	this->m_data = value;
}

void* TargetProgressBox::get_data() {
	return this->m_data;
}

void TargetProgressBox::set_ui() {
	this->set_orientation(Gtk::Orientation::VERTICAL);
	this->set_margin(MARGINS);
	
	// Make tab boxes
	auto hbx_1 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	hbx_1->set_spacing(WIDGET_SPACING);
	
	// Make labels
	auto lbl_1 = Gtk::make_managed<Gtk::Label>();
	lbl_1->set_markup("<b>Project Target:</b>");
	lbl_1->set_xalign(1);
	// auto emai_lbl = Gtk::make_managed<Gtk::Label>("Author");
	// auto biog_lbl = Gtk::make_managed<Gtk::Label>("Target");

	this->m_target_count_ent.set_placeholder_text("Enter only number values");
	//this->m_target_count_ent.signal_changed().connect(sigc::mem_fun(*this, &TargetProgressBox::validate_text));
	this->m_target_count_ent.set_hexpand(true);
	this->m_builder = Gtk::Builder::create_from_string(ui_menu_count);
    const std::vector<Glib::ustring> strings{ "Characters", "Words", "Pages" };
	this->m_string_list = Gtk::StringList::create(strings);
    this->m_target_count_ddn.set_model(this->m_string_list);
	this->m_target_count_ddn.set_selected(1);
	
	// Connect signal handler:
  	this->m_target_count_ddn.property_selected().signal_changed().connect(sigc::mem_fun(*this, &TargetProgressBox::on_count_dropdown_changed));
	
	hbx_1->append(*lbl_1);
	hbx_1->append(this->m_target_count_ent);
	hbx_1->append(this->m_target_count_ddn);
	hbx_1->set_valign(Gtk::Align::START);
	hbx_1->set_hexpand(true);
	hbx_1->set_vexpand(false);

	auto hbx_2 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	hbx_2->set_spacing(WIDGET_SPACING);
	hbx_2->set_margin_top(WIDGET_SPACING);
	hbx_2->set_margin_bottom(WIDGET_SPACING);
	this->m_target_pgr.set_orientation(Gtk::Orientation::HORIZONTAL);
	this->m_target_pgr.set_fraction(0.5f);
	this->m_target_pgr.set_show_text(true);
	this->m_target_pgr.set_hexpand(true);
	hbx_2->append(this->m_target_pgr);

	this->append(*hbx_1);
	this->append(*hbx_2);

}

void TargetProgressBox::on_count_dropdown_changed() {
	auto selected = this->m_target_count_ddn.get_selected();
	Utils::msg_box(WINDOW, "DropDown Changed", this->m_string_list->get_string(selected));
}

void TargetProgressBox::validate_text() {
	g_signal_stop_emission_by_name(G_OBJECT(&this->m_target_count_ent), "insert-text");

	// Get the text from the entry
    std::string text = this->m_target_count_ent.get_text();

    // Check if the text is a number and within the valid range
    try {
        long value = std::stol(text); // Convert text to long
        if (value < 1 || value > 1000000) {
			// Show message
			Utils::msg_box(Globals::get()->m_window, "Invalid Number Input", "Number must be between 1 and 1000000");
			this->m_target_count_ent.set_text("");
		} else {
			this->m_target_count_ent.set_text(text);
		}

    } catch (const std::invalid_argument&) {
        Utils::msg_box(Globals::get()->m_window, "Invalid Number Input", "Number \"" + text + " is invalid");
		this->m_target_count_ent.set_text("");
		return;
	} catch (const std::out_of_range&) {
        Utils::msg_box(Globals::get()->m_window, "Invalid Number Input", "Number \"" + text + " is invalid");
		this->m_target_count_ent.set_text("");
		return;
	}

	// Stop the signal emission
    //g_signal_stop_emission_by_name(G_OBJECT(&this->m_target_count_ent), "insert-text");
}