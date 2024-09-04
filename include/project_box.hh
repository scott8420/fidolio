#ifndef __PROJECT_BOX__
#define __PROJECT_BOX__

#include <gtkmm.h>

class ProjectBox : public Gtk::Box {
public:
	ProjectBox(void*);

	void set_data(void*);
	void* get_data();

protected:
	void* m_data;
	Gtk::Notebook m_nb;
	void set_ui();

private:
	ProjectBox() = delete;
};

#endif