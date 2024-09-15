#include <pomodoro_box.hh>
#include <globals.hh>
#include <utils.hh>

// Resources
#include <reset.xpm>

PomodoroBox::PomodoroBox(void* data) : m_data(data) {
	this->set_ui();
}

void PomodoroBox::set_data(void* value) {
	this->m_data = value;
}

void* PomodoroBox::get_data() {
	return this->m_data;
}

void PomodoroBox::set_ui() {
	this->set_orientation(Gtk::Orientation::VERTICAL);
	this->set_margin(MARGINS);
	this->set_size_request(500, -1);
	this->set_halign(Gtk::Align::CENTER);
	this->set_spacing(WIDGET_SPACING);

	// Make boxes
	auto hbx_1 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_2 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_3 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_4 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_5 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_6 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_7 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_8 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_9 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_10 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

	hbx_1->set_hexpand(true);
	hbx_2->set_hexpand(true);
	hbx_3->set_hexpand(true);
	hbx_4->set_hexpand(true);
	hbx_5->set_hexpand(true);
	hbx_6->set_hexpand(true);
	hbx_7->set_hexpand(true);
	hbx_8->set_hexpand(true);
	hbx_9->set_hexpand(true);
	hbx_10->set_hexpand(true);

	hbx_1->set_spacing(WIDGET_SPACING);
	hbx_2->set_spacing(WIDGET_SPACING);
	hbx_3->set_spacing(WIDGET_SPACING);
	hbx_4->set_spacing(WIDGET_SPACING);
	hbx_5->set_spacing(WIDGET_SPACING);
	hbx_6->set_spacing(WIDGET_SPACING);
	hbx_7->set_spacing(WIDGET_SPACING);
	hbx_8->set_spacing(WIDGET_SPACING);
	hbx_9->set_spacing(WIDGET_SPACING);
	hbx_10->set_spacing(WIDGET_SPACING);
	
	// Make Spacer Boxes
	auto sbx_5 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto sbx_6 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto sbx_7 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto sbx_8 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto sbx_9 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto sbx_10 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	
	sbx_5->set_hexpand(true);
	sbx_6->set_hexpand(true);
	sbx_7->set_hexpand(true);
	sbx_8->set_hexpand(true);
	sbx_9->set_hexpand(true);
	sbx_10->set_hexpand(true);

	// Make Scales
	auto sca_1 = Gtk::make_managed<Gtk::Scale>();
	auto sca_2 = Gtk::make_managed<Gtk::Scale>();
	auto sca_3 = Gtk::make_managed<Gtk::Scale>();
	auto sca_4 = Gtk::make_managed<Gtk::Scale>();

	auto lsc_1 = Gtk::make_managed<Gtk::Label>("1:00");
	auto lsc_2 = Gtk::make_managed<Gtk::Label>("1:00");
	auto lsc_3 = Gtk::make_managed<Gtk::Label>("1:00");
	auto lsc_4 = Gtk::make_managed<Gtk::Label>("1");
	
	sca_1->set_orientation(Gtk::Orientation::HORIZONTAL);
	sca_2->set_orientation(Gtk::Orientation::HORIZONTAL);
	sca_3->set_orientation(Gtk::Orientation::HORIZONTAL);
	sca_4->set_orientation(Gtk::Orientation::HORIZONTAL);
	
	sca_1->set_name("focus");
	sca_2->set_name("short_break");
	sca_3->set_name("long_break");
	sca_4->set_name("rounds");

	sca_1->set_range(1.0, 90.0);
	sca_2->set_range(1.0, 90.0);
	sca_3->set_range(1.0, 90.0);
	sca_4->set_range(1.0, 12.0);
	
	sca_1->set_show_fill_level(true);
	sca_2->set_show_fill_level(true);
	sca_3->set_show_fill_level(true);
	sca_4->set_show_fill_level(true);

	sca_1->set_digits(0);
	sca_2->set_digits(0);
	sca_3->set_digits(0);
	sca_4->set_digits(0);

	sca_1->set_hexpand(true);
	sca_2->set_hexpand(true);
	sca_3->set_hexpand(true);
	sca_4->set_hexpand(true);

	sca_1->set_increments(1, 10);
	sca_2->set_increments(1, 10);
	sca_3->set_increments(1, 10);
	sca_4->set_increments(1, 2);

	sca_1->signal_value_changed().connect(sigc::bind(sigc::mem_fun(*this, &PomodoroBox::on_scale_value_changed), sca_1, lsc_1));
	sca_2->signal_value_changed().connect(sigc::bind(sigc::mem_fun(*this, &PomodoroBox::on_scale_value_changed), sca_2, lsc_2));
	sca_3->signal_value_changed().connect(sigc::bind(sigc::mem_fun(*this, &PomodoroBox::on_scale_value_changed), sca_3, lsc_3));
	sca_4->signal_value_changed().connect(sigc::bind(sigc::mem_fun(*this, &PomodoroBox::on_scale_value_changed), sca_4, lsc_4));
	
	// Make labels
	auto lbl_1 = Gtk::make_managed<Gtk::Label>("Focus:");
	auto lbl_2 = Gtk::make_managed<Gtk::Label>("Short Break:");
	auto lbl_3 = Gtk::make_managed<Gtk::Label>("Long Break:");
	auto lbl_4 = Gtk::make_managed<Gtk::Label>("Rounds:");
	auto lbl_5 = Gtk::make_managed<Gtk::Label>("Always On Top:");
	auto lbl_6 = Gtk::make_managed<Gtk::Label>("Auto-start Focus Timer:");
	auto lbl_7 = Gtk::make_managed<Gtk::Label>("Auto-start Break Timer:");
	auto lbl_8 = Gtk::make_managed<Gtk::Label>("Tick Sounds:");
	auto lbl_9 = Gtk::make_managed<Gtk::Label>("Notifications:");
	auto lbl_10 = Gtk::make_managed<Gtk::Label>("Reset To Defaults:");
	
	// Make Color Buttons
	auto cbtn_1 = Gtk::make_managed<Gtk::ColorDialogButton>();
	auto cbtn_2 = Gtk::make_managed<Gtk::ColorDialogButton>();
	auto cbtn_3 = Gtk::make_managed<Gtk::ColorDialogButton>();

	cbtn_1->set_dialog(Gtk::ColorDialog::create());
	cbtn_2->set_dialog(Gtk::ColorDialog::create());
	cbtn_3->set_dialog(Gtk::ColorDialog::create());

	cbtn_1->set_rgba(RED);
	cbtn_2->set_rgba(GRN);
	cbtn_3->set_rgba(BLU);

	cbtn_1->set_name("focus");
	cbtn_2->set_name("short_break");
	cbtn_3->set_name("long_break");

	cbtn_1->set_size_request(30, 15);
	cbtn_2->set_size_request(30, 15);
	cbtn_3->set_size_request(30, 15);

	cbtn_1->set_valign(Gtk::Align::CENTER);
	cbtn_2->set_valign(Gtk::Align::CENTER);
	cbtn_3->set_valign(Gtk::Align::CENTER);
	
	// Make Switches
	auto swi_5 = Gtk::make_managed<Gtk::Switch>();
	auto swi_6 = Gtk::make_managed<Gtk::Switch>();
	auto swi_7 = Gtk::make_managed<Gtk::Switch>();
	auto swi_8 = Gtk::make_managed<Gtk::Switch>();
	auto swi_9 = Gtk::make_managed<Gtk::Switch>();
	
	swi_5->set_name("always_on_top");
	swi_6->set_name("auto-start_focus_timer");
	swi_7->set_name("auto-start_break_timer");
	swi_8->set_name("tick_sounds");
	swi_9->set_name("notifications");

	// Make Button(s)
	auto btn_10 = Gtk::make_managed<Gtk::Button>();
	auto img_10 = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Utils::image_from_xpm(reset)));
	btn_10->set_child(*img_10);
	btn_10->set_has_frame(false);

	// Connect Signal to Button
	this->m_scales = {sca_1, sca_2, sca_3, sca_4};
	this->m_buttons = {cbtn_1, cbtn_2, cbtn_3};
	this->m_switches = {swi_5, swi_6, swi_7, swi_8, swi_9};
	btn_10->signal_clicked().connect(sigc::mem_fun(*this, &PomodoroBox::on_reset_clicked));

	// Build Boxes
	hbx_1->append(*lbl_1);
	hbx_1->append(*sca_1);
	hbx_1->append(*lsc_1);
	hbx_1->append(*cbtn_1);

	hbx_2->append(*lbl_2);
	hbx_2->append(*sca_2);
	hbx_2->append(*lsc_2);
	hbx_2->append(*cbtn_2);

	hbx_3->append(*lbl_3);
	hbx_3->append(*sca_3);
	hbx_3->append(*lsc_3);
	hbx_3->append(*cbtn_3);

	hbx_4->append(*lbl_4);
	hbx_4->append(*sca_4);
	hbx_4->append(*lsc_4);

	hbx_5->append(*lbl_5);
	hbx_5->append(*sbx_5);
	hbx_5->append(*swi_5);

	hbx_6->append(*lbl_6);
	hbx_6->append(*sbx_6);
	hbx_6->append(*swi_6);

	hbx_7->append(*lbl_7);
	hbx_7->append(*sbx_7);
	hbx_7->append(*swi_7);

	hbx_8->append(*lbl_8);
	hbx_8->append(*sbx_8);
	hbx_8->append(*swi_8);

	hbx_9->append(*lbl_9);
	hbx_9->append(*sbx_9);
	hbx_9->append(*swi_9);

	hbx_10->append(*lbl_10);
	hbx_10->append(*sbx_10);
	hbx_10->append(*btn_10);

	// Append All boxes
	this->append(*hbx_1);
	this->append(*hbx_2);
	this->append(*hbx_3);
	this->append(*hbx_4);
	this->append(*hbx_5);
	this->append(*hbx_6);
	this->append(*hbx_7);
	this->append(*hbx_8);
	this->append(*hbx_9);
	this->append(*hbx_10);
	
}

void PomodoroBox::on_scale_value_changed(Gtk::Scale* scale, Gtk::Label* label) {
	int value = (int) scale->get_value();

	if(scale->get_name() == "rounds") {
		label->set_text(Glib::ustring::sprintf("%d", value));
	} else {
		label->set_text(Glib::ustring::sprintf("%d:00", value));
	}
}

void PomodoroBox::on_reset_clicked() {
	for (Gtk::Scale* sca : this->m_scales) {
		if (sca->get_name() == "focus") {
			sca->set_value(20);
		} else if (sca->get_name() == "short_break") {
			sca->set_value(5);
		} else if (sca->get_name() == "long_break") {
			sca->set_value(30);
		} else if (sca->get_name() == "rounds") {
			sca->set_value(3);
		} 
	}

	for (Gtk::ColorDialogButton* btn : this->m_buttons) {
		if (btn->get_name() == "focus") {
			btn->set_rgba(RED);
		} else if (btn->get_name() == "short_break") {
			btn->set_rgba(GRN);
		} else if (btn->get_name() == "long_break") {
			btn->set_rgba(BLU);
		}
	}

	for(Gtk::Switch* swi : this->m_switches) {
		if (swi->get_name() == "always_on_top") {
			swi->set_active(true);
		} else if (swi->get_name() == "auto-start_focus_timer") {
			swi->set_active(false);
		} else if (swi->get_name() == "auto-start_break_timer") {
			swi->set_active(false);
		} else if (swi->get_name() == "tick_sounds") {
			swi->set_active(false);
		} else if (swi->get_name() == "notifications") {
			swi->set_active(true);
		}
	}
}