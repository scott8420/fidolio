#include <mainwindow.hh>
#include <utils.hh>
#include <globals.hh>
#include <project_box.hh>

#include <gdkmm.h>

// Toolbar images in xpm format
#include <editor.xpm>
#include <home.xpm>
#include <outline.xpm>
#include <character.xpm>
#include <timeline.xpm>
#include <summary.xpm>
#include <world.xpm>
#include <compile.xpm>
#include <fidolio.xpm>
#include <fidolio_tall.xpm>
#include <trash.xpm>
#include <explore.xpm>
#include <open-menu.xpm>
#include <pomodoro.xpm>

// Resources
#include <fidolio_menu.ui>
#include <explore_menu.ui>
#include <open-menu_menu.ui>
#include <pomodoro.ui>

MainWindow::MainWindow() :
    m_project_pnd(Gtk::Orientation::HORIZONTAL) {

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
    auto peop_lbl = Gtk::make_managed<Gtk::Label>("Contents of Character");
    auto plot_lbl = Gtk::make_managed<Gtk::Label>("Contents of Timeline");
    auto worl_lbl = Gtk::make_managed<Gtk::Label>("Contents of Worlds");
    auto outl_lbl = Gtk::make_managed<Gtk::Label>("Contents of Outline");
    auto edit_lbl = Gtk::make_managed<Gtk::Label>("Contents of Editor");
    auto comp_lbl = Gtk::make_managed<Gtk::Label>("Contents of Compile");
    auto tras_lbl = Gtk::make_managed<Gtk::Label>("Contents of Trash");

    auto pro1_lbl = Gtk::make_managed<Gtk::Label>("Contents of Project A");
    auto pro2_lbl = Gtk::make_managed<Gtk::Label>("Contents of Project B");

    this->m_project_pnd.set_expand(true);
    this->m_project_pnd.set_margin(0);
    this->m_project_pnd.set_wide_handle(true);
    this->m_project_pnd.set_start_child(*pro1_lbl);
    this->m_project_pnd.set_end_child(*pro2_lbl);

    // Load a specific icon
    auto proj_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(home)));
    auto summ_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(summary)));
    auto char_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(character)));
    auto time_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(timeline)));
    auto worl_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(world)));
    auto outl_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(outline)));
    auto edit_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(editor)));
    auto comp_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(compile)));
    auto tras_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(trash)));
    
    auto proj_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto summ_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto char_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto worl_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto time_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto outl_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto edit_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto comp_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
    auto tras_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

    proj_hbx->append(*proj_img);
    proj_img->set_hexpand(true);
    proj_hbx->set_hexpand(true);
     
    summ_hbx->append(*summ_img);
    summ_img->set_hexpand(true);
    summ_hbx->set_hexpand(true);
     
    char_hbx->append(*char_img);
    char_img->set_hexpand(true);
    char_hbx->set_hexpand(true);

    worl_hbx->append(*worl_img);
    worl_img->set_hexpand(true);
    worl_hbx->set_hexpand(true);
     
    time_hbx->append(*time_img);
    time_img->set_hexpand(true);
    time_hbx->set_hexpand(true);
     
    outl_hbx->append(*outl_img);
    outl_img->set_hexpand(true);
    outl_hbx->set_hexpand(true);
     
    edit_hbx->append(*edit_img);
    edit_img->set_hexpand(true);
    edit_hbx->set_hexpand(true);

    comp_hbx->append(*comp_img);
    comp_img->set_hexpand(true);
    comp_hbx->set_hexpand(true);
     
    tras_hbx->append(*tras_img);
    tras_img->set_hexpand(true);
    tras_hbx->set_hexpand(true);
    
    this->m_pb = Gtk::make_managed<ProjectBox>(nullptr);
    this->m_pb->set_expand(true);
    
    // Formated example VIEW, LABEL
    this->m_nb.append_page(*this->m_pb, *proj_hbx);
    this->m_nb.append_page(*summ_lbl, *summ_hbx);
    this->m_nb.append_page(*peop_lbl, *char_hbx);
    this->m_nb.append_page(*worl_lbl, *worl_hbx);
    this->m_nb.append_page(*plot_lbl, *time_hbx);
    this->m_nb.append_page(*outl_lbl, *outl_hbx);
    this->m_nb.append_page(*edit_lbl, *edit_hbx);
    this->m_nb.append_page(*comp_lbl, *comp_hbx);
    this->m_nb.append_page(*tras_lbl, *tras_hbx);

    this->m_nb.set_expand(true);

    this->m_bx.append(m_nb);
    this->m_bx.set_expand(true);
}

void MainWindow::set_headerbar() {
    //open-menu-symbolic
    this->m_fidolio_mbtn.set_label("");
    auto fidolio_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Utils::image_from_xpm(fidolio))); //  Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(fidolio)));
    this->m_fidolio_mbtn.set_child(*fidolio_img);
    this->m_fidolio_mbtn.set_has_frame(false);
    this->m_builder = Gtk::Builder::create_from_string(ui_menu_fidolio);
    this->m_fidolio_menu = this->m_builder->get_object<Gio::Menu>("fidolio-menu-popup");
    this->m_fidolio_mbtn.set_menu_model(this->m_fidolio_menu);
    this->m_hbr.pack_start(this->m_fidolio_mbtn);


    this->m_open_menu_mbtn.set_label("Open");
    //auto open_menu_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Utils::image_from_xpm(open_menu)));
    this->m_open_menu_mbtn.set_icon_name("open-menu-symbolic");
    //this->m_open_menu_mbtn.set_child(*open_menu_img);
    this->m_open_menu_mbtn.set_has_frame(false);
    this->m_builder->add_from_string(ui_menu_open_menu);
    this->m_open_menu_menu = this->m_builder->get_object<Gio::Menu>("open-menu-popup");
    this->m_open_menu_mbtn.set_menu_model(this->m_open_menu_menu);
    this->m_hbr.pack_end(this->m_open_menu_mbtn);

    this->m_explore_mbtn.set_label("Explorer");
    auto explore_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Utils::image_from_xpm(explore)));
    //this->m_explore_mbtn.set_child(*explore_img);
    this->m_explore_mbtn.set_icon_name("explore2-symbolic");
    this->m_explore_mbtn.set_has_frame(false);
    this->m_explore_mbtn.set_always_show_arrow(true);
    this->m_explore_mbtn.set_tooltip_text("Navigator menu to directly set viewport");
    this->m_builder->add_from_string(ui_menu_explore);
    this->m_explore_menu = this->m_builder->get_object<Gio::Menu>("explore-menu-popup");
    this->m_explore_mbtn.set_menu_model(this->m_explore_menu);
    this->m_hbr.pack_end(this->m_explore_mbtn); 

    this->m_pomodoro_menu_mbtn.set_label("");
    auto pomodoro_img = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Utils::image_from_xpm(pomodoro))); //  Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(fidolio)));
    this->m_pomodoro_menu_mbtn.set_child(*pomodoro_img);
    this->m_pomodoro_menu_mbtn.set_has_frame(false);
    this->m_builder->add_from_string(ui_menu_pomodoro);
    this->m_pomodoro_menu = this->m_builder->get_object<Gio::Menu>("pomodoro-menu-popup");
    this->m_pomodoro_menu_mbtn.set_menu_model(this->m_pomodoro_menu);
    this->m_hbr.pack_end(this->m_pomodoro_menu_mbtn);

    this->set_titlebar(this->m_hbr);
}

void MainWindow::set_action_groups() {
    this->set_action_group_file();
    this->set_action_group_navigate();
    this->set_action_group_fidolio();
    this->set_action_group_explore();
}

void MainWindow::set_action_group_fidolio() {

    //Create the Action Group
    this->m_action_group_fidolio = Gio::SimpleActionGroup::create();

    //Connect Signals
    this->m_action_group_fidolio->add_action("quit", sigc::mem_fun(*this, &MainWindow::on_action_quit));
    this->m_action_group_fidolio->add_action("about", sigc::mem_fun(*this, &MainWindow::on_action_about));
    
    //Add to Window's Actions
    this->insert_action_group("fidolio_actions", this->m_action_group_fidolio);

    // Set Acceleration Keys
    if( APP != nullptr) {
        APP->set_accel_for_action("fidolio_actions.quit", "<Primary>q");
        APP->set_accel_for_action("fidolio_actions.about", "<Primary>0");
    }
}

void MainWindow::set_action_group_explore() {
    //Create the Action Group
    this->m_action_group_explore = Gio::SimpleActionGroup::create();

    //Connect Signals
    this->m_action_group_explore->add_action("home_project", sigc::mem_fun(*this, &MainWindow::on_action_home_project));
    this->m_action_group_explore->add_action("home_author", sigc::mem_fun(*this, &MainWindow::on_action_home_author));
    this->m_action_group_explore->add_action("home_target", sigc::mem_fun(*this, &MainWindow::on_action_home_target));
    this->m_action_group_explore->add_action("home_text_styles", sigc::mem_fun(*this, &MainWindow::on_action_home_text_styles));
    this->m_action_group_explore->add_action("home_keyboard_shortcuts", sigc::mem_fun(*this, &MainWindow::on_action_home_keyboard_shortcuts));
    this->m_action_group_explore->add_action("home_preferences", sigc::mem_fun(*this, &MainWindow::on_action_home_preferences));
    this->m_action_group_explore->add_action("home_pomodoro", sigc::mem_fun(*this, &MainWindow::on_action_home_pomodoro));
    
    this->m_action_group_explore->add_action("home_summary", sigc::mem_fun(*this, &MainWindow::on_action_summary));
    this->m_action_group_explore->add_action("home_character", sigc::mem_fun(*this, &MainWindow::on_action_character));
    this->m_action_group_explore->add_action("home_timeline", sigc::mem_fun(*this, &MainWindow::on_action_timeline));
    this->m_action_group_explore->add_action("home_world", sigc::mem_fun(*this, &MainWindow::on_action_world));
    this->m_action_group_explore->add_action("home_outline", sigc::mem_fun(*this, &MainWindow::on_action_outline));
    this->m_action_group_explore->add_action("home_editor", sigc::mem_fun(*this, &MainWindow::on_action_editor));
    this->m_action_group_explore->add_action("home_compile", sigc::mem_fun(*this, &MainWindow::on_action_compile));
    this->m_action_group_explore->add_action("home_trash", sigc::mem_fun(*this, &MainWindow::on_action_trash));
    
    //Add to Window's Actions
    this->insert_action_group("explore_actions", this->m_action_group_explore);

    // Set Acceleration Keys
    if( APP != nullptr) {
        APP->set_accel_for_action("explore_actions.home_project", "<Alt>1");
        APP->set_accel_for_action("explore_actions.home_author", "<Alt>2");
        APP->set_accel_for_action("explore_actions.home_target", "<Alt>3");
        APP->set_accel_for_action("explore_actions.home_text_styles", "<Alt>4");
        APP->set_accel_for_action("explore_actions.home_keyboard_shortcuts", "<Alt>5");
        APP->set_accel_for_action("explore_actions.home_preferences", "<Alt>6");
        APP->set_accel_for_action("explore_actions.home_pomodoro", "<Alt>7");
        
        APP->set_accel_for_action("explore_actions.home_summary", "<Ctrl>2");
        APP->set_accel_for_action("explore_actions.home_character", "<Ctrl>3");
        APP->set_accel_for_action("explore_actions.home_world", "<Ctrl>4");
        APP->set_accel_for_action("explore_actions.home_timeline", "<Ctrl>5");
        APP->set_accel_for_action("explore_actions.home_outline", "<Ctrl>6");
        APP->set_accel_for_action("explore_actions.home_editor", "<Ctrl>7");
        APP->set_accel_for_action("explore_actions.home_compile", "<Ctrl>8");
        APP->set_accel_for_action("explore_actions.home_trash", "<Ctrl>9");
    }
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
        APP->set_accel_for_action("file_actions.quit", "<Ctrl>q");
        APP->set_accel_for_action("file_actions.about", "<Ctrl>0");
    }
}

void MainWindow::set_action_group_navigate() {
 
    // Create the Action Group
    this->m_action_group_navigate = Gio::SimpleActionGroup::create();

	// Connect Signals
	this->m_action_group_navigate->add_action("home", sigc::mem_fun(*this, &MainWindow::on_action_home));
    this->m_action_group_navigate->add_action("summary", sigc::mem_fun(*this, &MainWindow::on_action_summary));
    this->m_action_group_navigate->add_action("character", sigc::mem_fun(*this, &MainWindow::on_action_character));
    this->m_action_group_navigate->add_action("world", sigc::mem_fun(*this, &MainWindow::on_action_world));
    this->m_action_group_navigate->add_action("timeline", sigc::mem_fun(*this, &MainWindow::on_action_timeline));
    this->m_action_group_navigate->add_action("outline", sigc::mem_fun(*this, &MainWindow::on_action_outline));
    this->m_action_group_navigate->add_action("editor", sigc::mem_fun(*this, &MainWindow::on_action_editor));
    this->m_action_group_navigate->add_action("compile", sigc::mem_fun(*this, &MainWindow::on_action_compile));
    this->m_action_group_navigate->add_action("trash", sigc::mem_fun(*this, &MainWindow::on_action_trash));
    
    // Add to Window's Actions
	this->insert_action_group("navigate_actions", this->m_action_group_navigate);

	// Set Acceleration Keys
	if( APP != nullptr) {
		APP->set_accel_for_action("navigate_actions.home", "<Ctrl>1");
		APP->set_accel_for_action("navigate_actions.summary", "<Ctrl>2");
        APP->set_accel_for_action("navigate_actions.character", "<Ctrl>3");
        APP->set_accel_for_action("navigate_actions.world", "<Ctrl>4");
        APP->set_accel_for_action("navigate_actions.timeline", "<Ctrl>5");
        APP->set_accel_for_action("navigate_actions.outline", "<Ctrl>6");
        APP->set_accel_for_action("navigate_actions.editor", "<Ctrl>7");
        APP->set_accel_for_action("navigate_actions.compile", "<Ctrl>8");
        APP->set_accel_for_action("navigate_actions.trash", "<Ctrl>9");
	}
}

void MainWindow::on_action_quit() {
    APP->quit();
}

void MainWindow::on_action_about() {
    this->m_about_dlg.set_visible(true);
    this->m_about_dlg.present();
}

void MainWindow::on_action_home() {
    this->m_nb.set_current_page(HOME);
}

void MainWindow::on_action_home_project() {
    this->m_nb.set_current_page(HOME);
    this->m_pb->set_page(HOME_PROJECT);
}

void MainWindow::on_action_home_author() {
    this->m_nb.set_current_page(HOME);
    this->m_pb->set_page(HOME_AUTHOR);
}

void MainWindow::on_action_home_target() {
    this->m_nb.set_current_page(HOME);
    this->m_pb->set_page(HOME_TARGET);
}

void MainWindow::on_action_home_text_styles() {
    this->m_nb.set_current_page(HOME);
    this->m_pb->set_page(HOME_TEXT_STYLES);
}

void MainWindow::on_action_home_keyboard_shortcuts() {
    this->m_nb.set_current_page(HOME);
    this->m_pb->set_page(HOME_KEYBOARD_SHORTCUTS);
}

void MainWindow::on_action_home_preferences() {
    this->m_nb.set_current_page(HOME);
    this->m_pb->set_page(HOME_PREFERENCES);
}

void MainWindow::on_action_home_pomodoro() {
    this->m_nb.set_current_page(HOME);
    this->m_pb->set_page(HOME_POMODORO);
}

void MainWindow::on_action_summary() {
    this->m_nb.set_current_page(SUMMARY);
}

void MainWindow::on_action_character() {
    this->m_nb.set_current_page(CHARACTER);
}

void MainWindow::on_action_world() {
    this->m_nb.set_current_page(WORLD);
}

void MainWindow::on_action_timeline() {
    this->m_nb.set_current_page(TIMELINE);
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

void MainWindow::on_action_trash() {
    this->m_nb.set_current_page(TRASH);
}
