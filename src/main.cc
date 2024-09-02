#include <mainwindow.hh>
#include <globals.hh>

int main(int argc, char* argv[]) {
    Globals::get()->m_app = Gtk::Application::create("org.gtkmm.examples.base");
    return Globals::get()->m_app->make_window_and_run<MainWindow>(argc, argv);
}

