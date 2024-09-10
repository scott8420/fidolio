#include <target_progress_box.hh>
#include <cctype>
#include <string>
#include <utils.hh>
#include <globals.hh>

// Resources
#include <target_progress_count_menu.ui>
#include <reset.xpm>

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
	
	auto hbx_1 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	hbx_1->set_spacing(WIDGET_SPACING);
	
	// Make labels
	auto lbl_1 = Gtk::make_managed<Gtk::Label>();
	lbl_1->set_markup("<b>Project Target:</b>");
	lbl_1->set_xalign(1);

	this->m_target_count_ent.set_placeholder_text("Enter only number values");
	this->m_target_count_ent.signal_changed().connect(sigc::mem_fun(*this, &TargetProgressBox::on_target_count_entry_changed));
	this->m_target_count_ent.set_hexpand(true);
	//this->m_builder = Gtk::Builder::create_from_string(ui_menu_count);
    const std::vector<Glib::ustring> strings_1{ "Characters", "Words", "Pages" };
	const std::vector<Glib::ustring> strings_2{ "Characters", "Words", "Pages" };
	this->m_target_string_list = Gtk::StringList::create(strings_1);
	this->m_session_string_list = Gtk::StringList::create(strings_2);
    this->m_target_count_ddn.set_model(this->m_target_string_list);
	this->m_target_count_ddn.set_selected(1);
	
	// Connect signal handler:
  	this->m_target_count_ddn.property_selected().signal_changed().connect(sigc::mem_fun(*this, &TargetProgressBox::on_target_count_dropdown_changed));
	
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
	//this->m_target_count_lbl.set_halign(Gtk::Align::CENTER);
	hbx_2->append(this->m_target_count_lbl);
	this->m_target_sep.set_orientation(Gtk::Orientation::HORIZONTAL);
	this->m_target_sep.set_size_request(-1, 5);
	this->m_target_sep.set_margin_top(MARGINS);
	this->m_target_sep.set_margin_bottom(MARGINS);
	this->m_target_sep.set_hexpand(true);

	auto hbx_8 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_9 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_10 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

	this->m_target_deadline_cbx.set_label("Deadline: ");
	hbx_8->append(this->m_target_deadline_cbx);
	hbx_8->append(this->m_target_deadline_dpk);
	hbx_9->set_hexpand(true);
	this->m_target_notifications_cbx.set_label("Show Notifications");
	this->m_target_notifications_cbx.set_halign(Gtk::Align::END);
	hbx_10->append(*hbx_8);
	hbx_10->append(*hbx_9);
	hbx_10->append(this->m_target_notifications_cbx);

	auto hbx_3 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_4 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_5 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	
	auto lbl_3 = Gtk::make_managed<Gtk::Label>();
	lbl_3->set_markup("<b>Session Target:</b>");
	lbl_3->set_xalign(0);

	this->m_session_count_ent.signal_changed().connect(sigc::mem_fun(*this, &TargetProgressBox::on_session_count_entry_changed));
    this->m_session_count_ddn.set_model(this->m_session_string_list);
	this->m_session_count_ddn.set_selected(1);
	this->m_session_count_ddn.property_selected().signal_changed().connect(sigc::mem_fun(*this, &TargetProgressBox::on_session_count_dropdown_changed));
	this->m_session_count_ent.set_placeholder_text("Enter only number values");
	this->m_session_count_ent.set_hexpand(true);

	this->m_session_btn.set_label("Reset");
	auto reset_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Utils::image_from_xpm(reset)));
	this->m_session_btn.set_child(*reset_img);
	this->m_session_btn.set_has_frame(false);
	this->m_session_btn.signal_clicked().connect(sigc::mem_fun(*this, &TargetProgressBox::on_session_btn_clicked));
	
	hbx_3->set_spacing(WIDGET_SPACING);
	hbx_5->set_halign(Gtk::Align::END);
	hbx_5->append(this->m_session_btn);
	hbx_5->append(this->m_session_count_ddn);
	
	auto hbx_6 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	hbx_6->set_spacing(WIDGET_SPACING);
	hbx_6->set_margin_top(WIDGET_SPACING);
	hbx_6->set_margin_bottom(WIDGET_SPACING);
	this->m_session_pgr.set_orientation(Gtk::Orientation::HORIZONTAL);
	this->m_session_pgr.set_fraction(0.5f);
	this->m_session_pgr.set_show_text(true);
	this->m_session_pgr.set_hexpand(true);
	hbx_6->append(this->m_session_pgr);
	hbx_6->append(this->m_session_count_lbl);

	hbx_3->append(*lbl_3);
	hbx_3->append(this->m_session_count_ent);
	hbx_3->append(*hbx_5);
	hbx_3->set_hexpand(true);

	this->append(*hbx_1);
	this->append(*hbx_2);
	this->append(*hbx_10);
	this->append(this->m_target_sep);
	this->append(*hbx_3);
	this->append(*hbx_6);

	this->on_target_count_dropdown_changed();
	this->on_session_count_dropdown_changed();
}

void TargetProgressBox::on_session_btn_clicked() {
	Utils::msg_box(WINDOW, "Button Clicked", "Session Reset Button Clicked");
}

void TargetProgressBox::on_target_count_entry_changed() {
	this->on_target_count_dropdown_changed();
}

void TargetProgressBox::on_target_count_dropdown_changed() {
	auto count = this->m_target_count_ent.get_text();
	if (count == "") {
		count = "0";
	}
	auto selected = this->m_target_count_ddn.get_selected();
	auto type = this->m_target_string_list->get_string(selected);
	this->m_target_count_lbl.set_text("0 of " + count + " " + type);
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

void TargetProgressBox::on_session_count_dropdown_changed() {
	auto count = this->m_session_count_ent.get_text();
	if (count == "") {
		count = "0";
	}
	auto selected = this->m_session_count_ddn.get_selected();
	auto type = this->m_session_string_list->get_string(selected);
	this->m_session_count_lbl.set_text("0 of " + count + " " + type);

}
	
void TargetProgressBox::on_session_count_entry_changed(){
	this->on_session_count_dropdown_changed();
}
