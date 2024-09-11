#ifndef __TARGET_PROGRESS_BOX__
#define __TARGET_PROGRESS_BOX__

#include <gtkmm.h>
#include <date_picker.hh>
#include <week_togglebutton_box.hh>

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
	Glib::RefPtr<Gtk::StringList> m_target_string_list;
	Glib::RefPtr<Gtk::StringList> m_session_string_list;
	Gtk::TextView* m_auth_bio_tvw;
	Glib::RefPtr<Gtk::Builder> m_builder;
	Gtk::ProgressBar m_target_pgr;
	Gtk::Label m_target_count_lbl;
	Gtk::Separator m_target_sep;
	Gtk::Entry m_session_count_ent;
	Gtk::DropDown m_session_count_ddn;
	Gtk::ProgressBar m_session_pgr;
	Gtk::Button m_session_btn;
	Gtk::Label m_session_count_lbl;
	Gtk::CheckButton m_target_deadline_cbx;
	Gtk::CheckButton m_target_notifications_cbx;
	Gtk::CheckButton m_session_writing_days_cbx;
	Gtk::CheckButton m_session_notifications_cbx;

	DatePicker m_target_deadline_dpk;
	WeekToggleButtonBox m_wtb;
	
	void set_ui();

protected:
	void on_target_count_entry_changed();
	void on_target_count_dropdown_changed();
	void on_session_btn_clicked();
	void on_session_count_dropdown_changed();
	void on_session_count_entry_changed();
	
private:
	TargetProgressBox() = delete;

	void validate_text();
};

#endif
