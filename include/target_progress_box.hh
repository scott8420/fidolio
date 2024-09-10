#ifndef __TARGET_PROGRESS_BOX__
#define __TARGET_PROGRESS_BOX__

#include <gtkmm.h>

class TargetProgressBox : public Gtk::Box {
public:
	TargetProgressBox(void*);

	void set_data(void*);
	void* get_data();

protected:
	void* m_data;
	
	Gtk::Entry m_target_count_ent;
	Gtk::ProgressBar m_target_count_pbr;
	Gtk::DropDown m_target_count_ddn;
	Gtk::Entry m_auth_email_ent;
	Glib::RefPtr<Gtk::StringList> m_string_list;
	Gtk::TextView* m_auth_bio_tvw;
	Glib::RefPtr<Gtk::Builder> m_builder;
	Gtk::ProgressBar m_target_pgr;
	
	void set_ui();

protected:
	void on_count_dropdown_changed();

private:
	TargetProgressBox() = delete;

	void validate_text();
};

#endif
