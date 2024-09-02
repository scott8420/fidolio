#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();

protected:
    // Signals

    // Widgets
    Gtk::Box m_box1;
    Gtk::Notebook m_nb;

    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_navigate;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_file;

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


    void set_ui();
    void set_action_groups();
    void set_action_group_file();
    void set_action_group_navigate();
};

#endif

