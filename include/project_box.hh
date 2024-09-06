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
	Gtk::Entry* m_proj_title_ent;
	Gtk::Entry* m_proj_subtitle_ent;
	Gtk::Entry* m_proj_series_ent;
	Gtk::Entry* m_proj_volume_ent;
	Gtk::Entry* m_proj_license_ent;
	Gtk::Entry* m_proj_folder_ent;
	Gtk::Entry* m_auth_name_ent;
	Gtk::Entry* m_auth_email_ent;
	Gtk::TextView* m_auth_bio_tvw;

	Gtk::ComboBoxText* m_proj_genre_cbx;
	
	void set_ui();
	Gtk::Box* set_project_ui();
	Gtk::Box* set_author_ui();
	void on_folder_clicked();
	void on_folder_clicked_finish(const Glib::RefPtr<Gio::AsyncResult>&, const Glib::RefPtr<Gtk::FileDialog>&);

private:
	ProjectBox() = delete;
};

#endif