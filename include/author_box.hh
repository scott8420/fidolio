#ifndef __AUTHOR_BOX__
#define __AUTHOR_BOX__

#include <gtkmm.h>

class AuthorBox : public Gtk::Box {
public:
	AuthorBox(void*);

	void set_data(void*);
	void* get_data();

protected:
	void* m_data;
	
	Gtk::Entry* m_auth_name_ent;
	Gtk::Entry* m_auth_email_ent;
	Gtk::TextView* m_auth_bio_tvw;
	
	void set_ui();

private:
	AuthorBox() = delete;
};

#endif
