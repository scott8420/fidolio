#ifndef __WEEK_TOGGLEBUTTON_BOX__
#define __WEEK_TOGGLEBUTTON_BOX__

#include <gtkmm.h>
#include <bitset>

typedef enum DayOfWeekEnum {
	SUNDAY = 0,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
} DayOfWeek;

class WeekToggleButtonBox : public Gtk::Box {
public:
	WeekToggleButtonBox();

	bool get_bit(const DayOfWeek);
	void set_bit(const DayOfWeek, bool);
	void set_has_frame(bool);

	gulong get_value();
	Glib::ustring to_string();
	std::bitset<7> get_bitset();

protected:
	Gtk::ToggleButton m_sunday;
	Gtk::ToggleButton m_monday;
	Gtk::ToggleButton m_tuesday;
	Gtk::ToggleButton m_wednesday;
	Gtk::ToggleButton m_thursday;
	Gtk::ToggleButton m_friday;
	Gtk::ToggleButton m_saturday;
	
	void set_ui();
	void on_toggle_changed(const DayOfWeek);

private:
	std::bitset<7> m_bits;
};



#endif