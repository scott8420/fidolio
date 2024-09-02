#include <mainwindow.hh>
#include <utils.hh>
#include <iostream>

int main(int argc, char* argv[]) {

    //std::cout << Utils::create_uuid() << std::endl;

    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("org.gtkmm.examples.base");
    
    return app->make_window_and_run<MainWindow>(argc, argv);
}

