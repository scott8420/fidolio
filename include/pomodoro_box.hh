#ifndef __POMODORO_BOX__
#define __POMODORO_BOX__

#include <gtkmm.h>
#include <array>

class PomodoroBox : public Gtk::Box {
public:
	PomodoroBox(void*);

	void set_data(void*);
	void* get_data();

protected:
	void* m_data;
	
	void set_ui();
	void on_scale_value_changed(Gtk::Scale*, Gtk::Label*);
	void on_reset_clicked();

private:
	PomodoroBox() = delete;

	std::array<Gtk::Scale*, 4> m_scales;
	std::array<Gtk::ColorDialogButton*, 3> m_buttons;
	std::array<Gtk::Switch*, 5> m_switches;
};

#endif
