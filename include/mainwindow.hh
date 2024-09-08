#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <gtkmm.h>


enum {
    HOME = 0,
    SUMMARY,
    CHARACTER,
    WORLD,
    TIMELINE,
    OUTLINE,
    EDITOR,
    COMPILE,
    TRASH
};

enum {
    HOME_PROJECT = 0,
    HOME_AUTHOR,
    HOME_TARGET,
    HOME_TEXT_STYLES,
    HOME_KEYBOARD_SHORTCUTS,
    HOME_PREFERENCES
};

class ProjectBox;

class MainWindow : public Gtk::Window {
public:
    MainWindow();

protected:

    // Widgets
    Gtk::Box m_bx;
    Gtk::Notebook m_nb;
    Gtk::HeaderBar m_hbr;
    Gtk::MenuButton m_fidolio_mbtn;
    Gtk::MenuButton m_explore_mbtn;
    Gtk::MenuButton m_open_menu_mbtn;
    Gtk::AboutDialog m_about_dlg;
    Gtk::Paned m_project_pnd;
    ProjectBox* m_pb;

    Glib::RefPtr<Gio::Menu> m_fidolio_menu;
    Glib::RefPtr<Gio::Menu> m_explore_menu;
    Glib::RefPtr<Gio::Menu> m_open_menu_menu;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_fidolio;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_navigate;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_file;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group_explore;
    Glib::RefPtr<Gtk::Builder> m_builder;
 
    // ACTIONS
    void on_action_home();
    void on_action_home_project();
    void on_action_home_author();
    void on_action_home_target();
    void on_action_home_text_styles();
    void on_action_home_keyboard_shortcuts();
    void on_action_home_preferences();
    void on_action_summary();
    void on_action_character();
    void on_action_timeline();
    void on_action_world();
    void on_action_outline();
    void on_action_editor();
    void on_action_compile();
    void on_action_trash();
    void on_action_quit();
    void on_action_about();

    void set_ui();
    void set_headerbar();
    void set_action_groups();
    void set_action_group_file();
    void set_action_group_navigate();
    void set_action_group_fidolio();
    void set_action_group_explore();
};

#endif

