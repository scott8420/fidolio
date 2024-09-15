#ifndef __GLOBALS__
#define __GLOBALS__

#include <gtkmm.h>

class Globals {
private:
    Globals(); 
	virtual ~Globals();
	
public:
	Globals(const Globals&) = delete;

    static Globals* get();
	
	Glib::RefPtr<Gtk::Application> m_app = nullptr;
	Gtk::Window* m_window = nullptr;
	Glib::ustring& app_name();
	Glib::ustring& app_version();
	
private:
	Glib::ustring m_app_name = "Fidolio";
	Glib::ustring m_app_version = "1.0.0";
};

#define WINDOW Globals::get()->m_window
#define APP Globals::get()->m_app
#define MARGINS 50
#define WIDGET_SPACING 10

#endif