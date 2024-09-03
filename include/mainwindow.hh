#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <gtkmm.h>

enum {
    PROJECT = 0,
    SUMMARY,
    PEOPLE,
    TIMELINE,
    WORLD,
    OUTLINE,
    EDITOR,
    COMPILE
};

class MainWindow : public Gtk::Window {
public:
    MainWindow();

protected:

    // Widgets
    Gtk::Box m_bx;
    Gtk::Notebook m_nb;
    Gtk::HeaderBar m_hbr;
    Gtk::MenuButton m_fidolio_mbtn;
    Gtk::AboutDialog m_about_dlg;

    Glib::RefPtr<Gio::Menu> m_fidolio_menu;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_fidolio;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_navigate;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_file;
    Glib::RefPtr<Gtk::Builder> m_builder;
 
    // ACTIONS
    void on_action_project();
    void on_action_summary();
    void on_action_people();
    void on_action_timeline();
    void on_action_world();
    void on_action_outline();
    void on_action_editor();
    void on_action_compile();
    void on_action_quit();
    void on_action_about();

    void set_ui();
    void set_headerbar();
    void set_action_groups();
    void set_action_group_file();
    void set_action_group_navigate();
    void set_action_group_fidolio();
};

#endif

