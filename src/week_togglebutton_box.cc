#include <week_togglebutton_box.hh>
#include <cstddef>

WeekToggleButtonBox::WeekToggleButtonBox() {
	this->set_ui();
}

bool WeekToggleButtonBox::get_bit(const DayOfWeek day) {
	return this->m_bits[std::size_t(day)];
}

void WeekToggleButtonBox::set_bit(const DayOfWeek day, bool value) {
	this->m_bits.set(std::size_t(day), value);
}

gulong WeekToggleButtonBox::get_value() {
	return gulong(this->m_bits.to_ulong());
}

std::bitset<7> WeekToggleButtonBox::get_bitset() {
	return this->m_bits;
}

void WeekToggleButtonBox::set_ui() {
	this->set_orientation(Gtk::Orientation::HORIZONTAL);
	this->set_spacing(0);

	this->m_sunday.set_label("Sun");
	this->m_monday.set_label("Mon");
	this->m_tuesday.set_label("Tue");
	this->m_wednesday.set_label("Wed");
	this->m_thursday.set_label("Thu");
	this->m_friday.set_label("Fri");
	this->m_saturday.set_label("Sat");

	this->m_sunday.set_has_frame(true);
	this->m_monday.set_has_frame(true);
	this->m_tuesday.set_has_frame(true);
	this->m_wednesday.set_has_frame(true);
	this->m_thursday.set_has_frame(true);
	this->m_friday.set_has_frame(true);
	this->m_saturday.set_has_frame(true);

	this->m_sunday.signal_toggled().connect(sigc::bind(sigc::mem_fun(*this, &WeekToggleButtonBox::on_toggle_changed), DayOfWeek::SUNDAY));
	this->m_monday.signal_toggled().connect(sigc::bind(sigc::mem_fun(*this, &WeekToggleButtonBox::on_toggle_changed), DayOfWeek::MONDAY));
	this->m_tuesday.signal_toggled().connect(sigc::bind(sigc::mem_fun(*this, &WeekToggleButtonBox::on_toggle_changed), DayOfWeek::TUESDAY));
	this->m_wednesday.signal_toggled().connect(sigc::bind(sigc::mem_fun(*this, &WeekToggleButtonBox::on_toggle_changed), DayOfWeek::WEDNESDAY));
	this->m_thursday.signal_toggled().connect(sigc::bind(sigc::mem_fun(*this, &WeekToggleButtonBox::on_toggle_changed), DayOfWeek::THURSDAY));
	this->m_friday.signal_toggled().connect(sigc::bind(sigc::mem_fun(*this, &WeekToggleButtonBox::on_toggle_changed), DayOfWeek::FRIDAY));
	this->m_saturday.signal_toggled().connect(sigc::bind(sigc::mem_fun(*this, &WeekToggleButtonBox::on_toggle_changed), DayOfWeek::SATURDAY));
	
	this->append(this->m_sunday);
	this->append(this->m_monday);
	this->append(this->m_tuesday);
	this->append(this->m_wednesday);
	this->append(this->m_thursday);
	this->append(this->m_friday);
	this->append(this->m_saturday);
	
}

void WeekToggleButtonBox::on_toggle_changed(const DayOfWeek day) {
	Gtk::ToggleButton* btn;

	switch(day) {
		case DayOfWeek::SUNDAY: {
			btn = &this->m_sunday;
			break;
		}
		case DayOfWeek::MONDAY: {
			btn = &this->m_monday;
			break;
		}
		case DayOfWeek::TUESDAY: {
			btn = &this->m_tuesday;
			break;
		}
		case DayOfWeek::WEDNESDAY: {
			btn = &this->m_wednesday;
			break;
		}
		case DayOfWeek::THURSDAY: {
			btn = &this->m_thursday;
			break;
		}
		case DayOfWeek::FRIDAY: {
			btn = &this->m_friday;
			break;
		}
		case DayOfWeek::SATURDAY: {
			btn = &this->m_saturday;
			break;
		}
		default: {
			return;
		}
	}

	this->set_bit(day, btn->get_active());
}

void WeekToggleButtonBox::set_has_frame(bool value) {
	this->m_sunday.set_has_frame(value);
	this->m_monday.set_has_frame(value);
	this->m_tuesday.set_has_frame(value);
	this->m_wednesday.set_has_frame(value);
	this->m_thursday.set_has_frame(value);
	this->m_friday.set_has_frame(value);
	this->m_saturday.set_has_frame(value);
}

Glib::ustring WeekToggleButtonBox::to_string() {
	return Glib::ustring(this->m_bits.to_string().c_str());
}