#include <mainwindow.hh>
#include <utils.hh>

MainWindow::MainWindow() {
    this->setUI();
}

void MainWindow::setUI() {
    // This just sets the title of our new window.
    this->set_title("Msg Box");

    this->set_default_size(400, 200);

    // Sets the margin around the box.
    this->m_box1.set_margin(0);
    this->m_box1.set_homogeneous(false);

    // put the box into the main window.
    this->set_child(this->m_box1);

    this->m_nb.set_tab_pos(Gtk::PositionType::LEFT);
    m_one.set_text("Contents of Tab One");
    m_two.set_text("Contents of Tab Two");
    m_three.set_text("Contents of Tab Three");

    //gtk_notebook_append_page(notebook, tab1, gtk_vbox_new());

    // Load a specific icon
   
    // auto m_i1 = Gtk::make_managed<Gtk::Image>("../rsc/go-home-symbolic.svg");
    // auto m_i2 = Gtk::make_managed<Gtk::Image>("../rsc/open-menu-symbolic.svg");
    // Gtk::Button m_b1;
    // Gtk::Button::gtk_button_set_image(m_b1, m_i1)

    // m_nb.append_page()
    m_nb.append_page(m_one, "One");
    m_nb.append_page(m_two, "Two");
    m_nb.append_page(m_three, "Three");
    m_nb.set_expand(true);

    this->m_box1.append(m_nb);
    this->m_box1.set_expand(true);

    Utils::msg_box(this, "A Message", "Details");

    // Add the button
    // this->m_btn1.set_label("Click Me");
    // this->m_btn1.set_size_request(90,24);
    // this->m_btn1.set_margin(20);
    // this->m_btn1.signal_clicked().connect(sigc::bind(
    //             sigc::mem_fun(*this, &MainWindow::on_btn1_clicked), "Button 1"));
    // this->m_box1.append(m_btn1);
    // this->m_btn1.set_expand(false);
}

void MainWindow::on_btn1_clicked(const Glib::ustring& data) {
    auto dlg = Gtk::AlertDialog::create();
    dlg->set_message(data + " was clicked");
    dlg->set_detail("That was easy");
    dlg->set_buttons({});
    dlg->set_default_button(-1);
    dlg->set_cancel_button(-1);
    dlg->show(*this);
}

