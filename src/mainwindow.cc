#include <mainwindow.hh>
#include <utils.hh>
#include <globals.hh>

#include <gdkmm.h>

// Toolbar images in xpm format
#include <editor.xpm>
#include <project.xpm>
#include <outline.xpm>
#include <people.xpm>
#include <timeline.xpm>
#include <summary.xpm>
#include <world.xpm>
#include <compile.xpm>
#include <fidolio.xpm>
#include <fidolio_tall.xpm>

// Resources
#include <fidolio_menu.ui>

MainWindow::MainWindow() {
    WINDOW = this;

    // This just sets the title of our new window.
    this->set_title(Globals::get()->app_name());
    this->set_default_size(800, 500);
    
    this->set_headerbar();
    this->set_ui();
    this->set_action_groups();
}

void MainWindow::set_ui() {
    
    // Sets the margin around the box.
    this->m_bx.set_margin(0);
    this->m_bx.set_homogeneous(false);

    // About Dialog Setup
    this->m_about_dlg.set_transient_for(*this);
    this->m_about_dlg.set_hide_on_close();
    this->m_about_dlg.set_logo(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(fidolio_tall))); 
    this->m_about_dlg.set_program_name(Globals::get()->app_name() + " Writing Application");
    this->m_about_dlg.set_version(Globals::get()->app_version());
    this->m_about_dlg.set_copyright("Scott Combs");
    this->m_about_dlg.set_comments("An OpenSource Writing Application");
    this->m_about_dlg.set_license("LGPL");
    this->m_about_dlg.set_website("http://www.github.com/scott8420");
    this->m_about_dlg.set_website_label("github website");
    this->m_about_dlg.set_authors(Glib::OptionGroup::vecustrings{"Scott Combs"});

    // put the box into the main window.
    this->set_child(this->m_bx);

    this->m_nb.set_tab_pos(Gtk::PositionType::LEFT);

    auto proj_lbl = Gtk::make_managed<Gtk::Label>("Contents of Prroject");
    auto summ_lbl = Gtk::make_managed<Gtk::Label>("Contents of Summary");
    auto peop_lbl = Gtk::make_managed<Gtk::Label>("Contents of People");
    auto plot_lbl = Gtk::make_managed<Gtk::Label>("Contents of Timeline");
    auto worl_lbl = Gtk::make_managed<Gtk::Label>("Contents of Worlds");
    auto outl_lbl = Gtk::make_managed<Gtk::Label>("Contents of Outline");
    auto edit_lbl = Gtk::make_managed<Gtk::Label>("Contents of Editor");
    auto comp_lbl = Gtk::make_managed<Gtk::Label>("Contents of Compile");

    // Load a specific icon
    auto proj_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(project)));
    auto summ_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(summary)));
    auto peop_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(people)));
    auto time_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(timeline)));
    auto worl_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(world)));
    auto outl_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(outline)));
    auto edit_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(editor)));
    auto comp_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(compile)));
    
    auto proj_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto summ_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto peop_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto time_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto worl_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto outl_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto edit_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto comp_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    
    proj_hbx->append(*proj_img);
    proj_img->set_hexpand(true);
    proj_hbx->set_hexpand(true);
     
    summ_hbx->append(*summ_img);
    summ_img->set_hexpand(true);
    summ_hbx->set_hexpand(true);
     
    peop_hbx->append(*peop_img);
    peop_img->set_hexpand(true);
    peop_hbx->set_hexpand(true);
     
    time_hbx->append(*time_img);
    time_img->set_hexpand(true);
    time_hbx->set_hexpand(true);
     
    worl_hbx->append(*worl_img);
    worl_img->set_hexpand(true);
    worl_hbx->set_hexpand(true);
     
    outl_hbx->append(*outl_img);
    outl_img->set_hexpand(true);
    outl_hbx->set_hexpand(true);
     
    edit_hbx->append(*edit_img);
    edit_img->set_hexpand(true);
    edit_hbx->set_hexpand(true);

    comp_hbx->append(*comp_img);
    comp_img->set_hexpand(true);
    comp_hbx->set_hexpand(true);
     
    this->m_nb.append_page(*proj_lbl, *proj_hbx);
    this->m_nb.append_page(*summ_lbl, *summ_hbx);
    this->m_nb.append_page(*peop_lbl, *peop_hbx);
    this->m_nb.append_page(*plot_lbl, *time_hbx);
    this->m_nb.append_page(*worl_lbl, *worl_hbx);
    this->m_nb.append_page(*outl_lbl, *outl_hbx);
    this->m_nb.append_page(*edit_lbl, *edit_hbx);
    this->m_nb.append_page(*comp_lbl, *comp_hbx);

    this->m_nb.set_expand(true);

    this->m_bx.append(m_nb);
    this->m_bx.set_expand(true);
}

void MainWindow::set_headerbar() {
    this->m_fidolio_mbtn.set_label("");
    auto fidolio_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(fidolio)));
    this->m_fidolio_mbtn.set_child(*fidolio_img);
    this->m_fidolio_mbtn.set_has_frame(false);
    this->m_builder = Gtk::Builder::create_from_string(ui_menu_fidolio);
    this->m_fidolio_menu = this->m_builder->get_object<Gio::Menu>("fidolio-menu-popup");
    this->m_fidolio_mbtn.set_menu_model(this->m_fidolio_menu);
    this->m_hbr.pack_start(this->m_fidolio_mbtn);
    this->set_titlebar(this->m_hbr);
}

void MainWindow::set_action_groups() {
    this->set_action_group_file();
    this->set_action_group_navigate();
    this->set_action_group_fidolio();
}

void MainWindow::set_action_group_fidolio() {

    //Create the Action Group
    this->m_action_group_fidolio = Gio::SimpleActionGroup::create();

    //Connect Signals
    this->m_action_group_fidolio->add_action("quit", sigc::mem_fun(*this, &MainWindow::on_action_quit));
    this->m_action_group_fidolio->add_action("about", sigc::mem_fun(*this, &MainWindow::on_action_about));
    
    //Add to Window's Actions
    this->insert_action_group("fidolio_actions", this->m_action_group_fidolio);
}

void MainWindow::set_action_group_file() {
  
    // Create the Action Group
    this->m_action_group_file = Gio::SimpleActionGroup::create();

    // Connect Signals
    this->m_action_group_file->add_action("quit", sigc::mem_fun(*this, &MainWindow::on_action_quit));
    this->m_action_group_file->add_action("about", sigc::mem_fun(*this, &MainWindow::on_action_about));

    // Add to Window's Actions
    this->insert_action_group("file_actions", this->m_action_group_file);

    // Set Acceleration Keys
    if( APP != nullptr) {
        APP->set_accel_for_action("file_actions.quit", "<Primary>q");
        APP->set_accel_for_action("file_actions.about", "<Primary>0");
    }
}

void MainWindow::set_action_group_navigate() {
 
    // Create the Action Group
    this->m_action_group_navigate = Gio::SimpleActionGroup::create();

	// Connect Signals
	this->m_action_group_navigate->add_action("project", sigc::mem_fun(*this, &MainWindow::on_action_project));
    this->m_action_group_navigate->add_action("summary", sigc::mem_fun(*this, &MainWindow::on_action_summary));
    this->m_action_group_navigate->add_action("people", sigc::mem_fun(*this, &MainWindow::on_action_people));
    this->m_action_group_navigate->add_action("timeline", sigc::mem_fun(*this, &MainWindow::on_action_timeline));
    this->m_action_group_navigate->add_action("world", sigc::mem_fun(*this, &MainWindow::on_action_world));
    this->m_action_group_navigate->add_action("outline", sigc::mem_fun(*this, &MainWindow::on_action_outline));
    this->m_action_group_navigate->add_action("editor", sigc::mem_fun(*this, &MainWindow::on_action_editor));
    this->m_action_group_navigate->add_action("compile", sigc::mem_fun(*this, &MainWindow::on_action_compile));
    
    // Add to Window's Actions
	this->insert_action_group("navigate_actions", this->m_action_group_navigate);

	// Set Acceleration Keys
	if( APP != nullptr) {
		APP->set_accel_for_action("navigate_actions.project", "<Primary>1");
		APP->set_accel_for_action("navigate_actions.summary", "<Primary>2");
        APP->set_accel_for_action("navigate_actions.people", "<Primary>3");
        APP->set_accel_for_action("navigate_actions.timeline", "<Primary>4");
        APP->set_accel_for_action("navigate_actions.world", "<Primary>5");
        APP->set_accel_for_action("navigate_actions.outline", "<Primary>6");
        APP->set_accel_for_action("navigate_actions.editor", "<Primary>7");
        APP->set_accel_for_action("navigate_actions.compile", "<Primary>8");
	}
}

void MainWindow::on_action_quit() {
    APP->quit();
}

void MainWindow::on_action_about() {
    this->m_about_dlg.set_visible(true);
    this->m_about_dlg.present();
}

void MainWindow::on_action_project() {
    this->m_nb.set_current_page(PROJECT);
}

void MainWindow::on_action_summary() {
    this->m_nb.set_current_page(SUMMARY);
}

void MainWindow::on_action_people() {
    this->m_nb.set_current_page(PEOPLE);
}

void MainWindow::on_action_timeline() {
    this->m_nb.set_current_page(TIMELINE);
}

void MainWindow::on_action_world() {
    this->m_nb.set_current_page(WORLD);
}

void MainWindow::on_action_outline() {
    this->m_nb.set_current_page(OUTLINE);
}

void MainWindow::on_action_editor() {
    this->m_nb.set_current_page(EDITOR);
}

void MainWindow::on_action_compile() {
    this->m_nb.set_current_page(COMPILE);
}
