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
    
    void set_ui();
};

#endif

