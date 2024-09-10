#include <date_picker.hh>
#include <utils.hh>
#include <down-symbolic.xpm>


DatePicker::DatePicker() {
	this->m_label.set_text("Select Date");
	this->set_ui();
}

DatePicker::DatePicker(const Glib::ustring& label) {
	this->m_label.set_text(label);
	this->set_ui();
}

void DatePicker::set_ui() {
	this->m_image = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Utils::image_from_xpm(down_symbolic)));
	this->m_button.signal_clicked().connect(sigc::mem_fun(*this, &DatePicker::on_button_clicked));
	this->m_button.set_child(*this->m_image);
	this->m_button.set_has_frame(false);
	
	// Create a calendar widget
	this->m_calendar.signal_day_selected().connect(sigc::mem_fun(*this, &DatePicker::on_day_selected));

	this->set_orientation(Gtk::Orientation::HORIZONTAL);

	this->m_popover.set_parent(this->m_button);
	this->m_popover.set_child(this->m_calendar);
	
	this->append(this->m_label);
	this->append(this->m_button);

}

Glib::DateTime DatePicker::get_date() {
	return this->m_datetime;
}

void DatePicker::set_date(const Glib::DateTime& datetime) {
	this->m_calendar.select_day(datetime);
	this->m_datetime = datetime;
	this->on_day_selected();
}

void DatePicker::on_button_clicked() {
	this->m_popover.popup();
}

void DatePicker::on_day_selected() {
	// Handle date selection
	this->m_datetime = this->m_calendar.get_date();
	std::string selected_date = this->m_datetime.format("%Y-%m-%d");
	this->m_label.set_text(selected_date);
	this->m_popover.popdown(); 
}