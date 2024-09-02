#include <mainwindow.hh>
#include <utils.hh>
#include <gdkmm.h>

// Toolbar images in xpm format
#include <editor.xpm>
#include <home.xpm>
#include <outline.xpm>
#include <people.xpm>
#include <plotline.xpm>
#include <summary.xpm>
#include <world.xpm>

MainWindow::MainWindow() {
    this->set_ui();
}

void MainWindow::set_ui() {
    // This just sets the title of our new window.
    this->set_title("Fidolio");

    this->set_default_size(400, 200);

    // Sets the margin around the box.
    this->m_box1.set_margin(0);
    this->m_box1.set_homogeneous(false);

    // put the box into the main window.
    this->set_child(this->m_box1);

    this->m_nb.set_tab_pos(Gtk::PositionType::LEFT);

    auto home_lbl = Gtk::make_managed<Gtk::Label>("Contents of Home");
    auto summ_lbl = Gtk::make_managed<Gtk::Label>("Contents of Summary");
    auto peop_lbl = Gtk::make_managed<Gtk::Label>("Contents of People");
    auto plot_lbl = Gtk::make_managed<Gtk::Label>("Contents of Plotline");
    auto worl_lbl = Gtk::make_managed<Gtk::Label>("Contents of Worlds");
    auto outl_lbl = Gtk::make_managed<Gtk::Label>("Contents of Outline");
    auto edit_lbl = Gtk::make_managed<Gtk::Label>("Contents of Editor");

    // Load a specific icon
    auto home_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(home)));
    auto summ_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(summary)));
    auto peop_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(people)));
    auto plot_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(plotline)));
    auto worl_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(world)));
    auto outl_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(outline)));
    auto edit_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(editor)));
    
    auto home_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto summ_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto peop_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto plot_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto worl_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto outl_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto edit_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    
    home_hbx->append(*home_img);
    home_img->set_hexpand(true);
    home_hbx->set_hexpand(true);
     
    summ_hbx->append(*summ_img);
    summ_img->set_hexpand(true);
    summ_hbx->set_hexpand(true);
     
    peop_hbx->append(*peop_img);
    peop_img->set_hexpand(true);
    peop_hbx->set_hexpand(true);
     
    plot_hbx->append(*plot_img);
    plot_img->set_hexpand(true);
    plot_hbx->set_hexpand(true);
     
    worl_hbx->append(*worl_img);
    worl_img->set_hexpand(true);
    worl_hbx->set_hexpand(true);
     
    outl_hbx->append(*outl_img);
    outl_img->set_hexpand(true);
    outl_hbx->set_hexpand(true);
     
    edit_hbx->append(*edit_img);
    edit_img->set_hexpand(true);
    edit_hbx->set_hexpand(true);
     
    m_nb.append_page(*home_lbl, *home_hbx);
    m_nb.append_page(*summ_lbl, *summ_hbx);
    m_nb.append_page(*peop_lbl, *peop_hbx);
    m_nb.append_page(*plot_lbl, *plot_hbx);
    m_nb.append_page(*worl_lbl, *worl_hbx);
    m_nb.append_page(*outl_lbl, *outl_hbx);
    m_nb.append_page(*edit_lbl, *edit_hbx);
    
    m_nb.set_expand(true);

    this->m_box1.append(m_nb);
    this->m_box1.set_expand(true);
}
