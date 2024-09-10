#ifndef __DATE_PICKER__
#define __DATE_PICKER__

#include <gtkmm.h>

class DatePicker : public Gtk::Box {
public:
    DatePicker(); 
    DatePicker(const Glib::ustring&);

	Glib::DateTime get_date();
    void set_date(const Glib::DateTime&);

protected:
    void on_button_clicked();
    void on_day_selected();
    void set_ui();

private:
    Gtk::Button m_button;
    Gtk::Label m_label;
    Gtk::Popover m_popover;
    Gtk::Calendar m_calendar;
    Gtk::Image* m_image;
	Glib::DateTime m_datetime;
};

#endif