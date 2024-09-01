#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();

protected:
    // Signals
    void on_btn1_clicked(const Glib::ustring& data);

    // Widgets
    Gtk::Box m_box1;
    Gtk::Button m_btn1;
    Gtk::Notebook m_nb;
    Gtk::Label m_one;
    Gtk::Label m_two;
    Gtk::Label m_three;

private:
    void setUI();
};

#endif

