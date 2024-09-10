#ifndef __TARGET_BOX__
#define __TARGET_BOX__

#include <gtkmm.h>

class TargetBox : public Gtk::Box {
public:
	TargetBox(void*);

	void set_data(void*);
	void* get_data();

protected:
	void* m_data;
	Gtk::Notebook m_nb;
	
	void set_ui();

private:
	TargetBox() = delete;
};

#endif
