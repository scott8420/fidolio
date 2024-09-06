#include <project_box.hh>
#include <gdkmm.h>

// Resources
#include <folder.xpm>

ProjectBox::ProjectBox(void* data) : m_data(data) {

	this->set_ui();
}

void ProjectBox::set_data(void* value) {
	this->m_data = value;
}

void* ProjectBox::get_data() {
	return this->m_data;
}

void ProjectBox::set_ui() {
	this->set_orientation(Gtk::Orientation::HORIZONTAL);
	this->set_margin(0);

	// Make tab boxes
	auto proj_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto auth_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto targ_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto styl_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto keyb_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto pref_hbx = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

	// Make labels
	auto proj_lbl = Gtk::make_managed<Gtk::Label>("Project");
	auto auth_lbl = Gtk::make_managed<Gtk::Label>("Author");
	auto targ_lbl = Gtk::make_managed<Gtk::Label>("Target");
	auto styl_lbl = Gtk::make_managed<Gtk::Label>("Text Styles");
	auto keyb_lbl = Gtk::make_managed<Gtk::Label>("Keyboard Shortcuts");
	auto pref_lbl = Gtk::make_managed<Gtk::Label>("Preferences");

	proj_hbx->append(*proj_lbl);
	auth_hbx->append(*auth_lbl);
	targ_hbx->append(*targ_lbl); 
	styl_hbx->append(*styl_lbl); 
	keyb_hbx->append(*keyb_lbl);
	pref_hbx->append(*pref_lbl);

	// Make views for pages
	auto proj_viw = this->set_project_ui();
	auto auth_viw = this->set_author_ui();
	auto targ_viw = Gtk::make_managed<Gtk::Label>("Target View");
	auto styl_viw = Gtk::make_managed<Gtk::Label>("Styles View");
	auto keyb_viw = Gtk::make_managed<Gtk::Label>("Keyboard Shortcuts View");
	auto pref_viw = Gtk::make_managed<Gtk::Label>("Preferences View");

	// Add pages
	this->m_nb.append_page(*proj_viw, *proj_hbx);
	this->m_nb.append_page(*auth_viw, *auth_hbx);
	this->m_nb.append_page(*targ_viw, *targ_hbx);
	this->m_nb.append_page(*styl_viw, *styl_hbx);
	this->m_nb.append_page(*keyb_viw, *keyb_hbx);
	this->m_nb.append_page(*pref_viw, *pref_hbx);

    this->m_nb.set_expand(true);

	this->append(this->m_nb);
}

Gtk::Box* ProjectBox::set_project_ui() {
	// Configure parent box
	auto box_1 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL, 0);
	auto box_2 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL, 0);
	auto swn = Gtk::make_managed<Gtk::ScrolledWindow>();
	swn->set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  	swn->set_expand(true);

	box_1->append(*swn);
	box_1->set_homogeneous(false);
	box_1->set_size_request(650, 250);
	box_1->set_margin(50);
	box_1->set_valign(Gtk::Align::START);
	box_1->set_halign(Gtk::Align::CENTER);

	// Add widgets
	auto hbx_1 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_2 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_3 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_4 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_5 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_6 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_7 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

	auto lbl_1 = Gtk::make_managed<Gtk::Label>();
	auto lbl_2 = Gtk::make_managed<Gtk::Label>();
	auto lbl_3 = Gtk::make_managed<Gtk::Label>();
	auto lbl_4 = Gtk::make_managed<Gtk::Label>();
	auto lbl_5 = Gtk::make_managed<Gtk::Label>();
	auto lbl_6 = Gtk::make_managed<Gtk::Label>();

	this->m_proj_title_ent = Gtk::make_managed<Gtk::Entry>();
	this->m_proj_subtitle_ent = Gtk::make_managed<Gtk::Entry>();
	this->m_proj_series_ent = Gtk::make_managed<Gtk::Entry>();
	this->m_proj_volume_ent = Gtk::make_managed<Gtk::Entry>();
	this->m_proj_folder_ent = Gtk::make_managed<Gtk::Entry>();
	this->m_proj_license_ent = Gtk::make_managed<Gtk::Entry>();	

	this->m_proj_genre_cbx = Gtk::make_managed<Gtk::ComboBoxText>();
	//this->m_proj_genre_cbx->append("")
	auto btn_1 = Gtk::make_managed<Gtk::Button>();
	auto img_1 = Gtk::make_managed<Gtk::Image>(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(folder)));

	lbl_1->set_margin_bottom(2);
	lbl_1->set_xalign(1);
	lbl_1->set_size_request(100, -1);
	lbl_1->set_markup("<b>Title:  </b>");
	this->m_proj_title_ent->set_has_frame(false);
	this->m_proj_title_ent->set_max_length(256);
	this->m_proj_title_ent->set_placeholder_text("Title of project");
	this->m_proj_title_ent->set_size_request(500);
	hbx_1->append(*lbl_1);
	hbx_1->append(*this->m_proj_title_ent);	

	lbl_2->set_margin_bottom(2);
	lbl_2->set_xalign(1);
	lbl_2->set_size_request(100, -1);
	lbl_2->set_markup("<b>Subtitle:  </b>");
	this->m_proj_subtitle_ent->set_has_frame(false);
	this->m_proj_subtitle_ent->set_max_length(256);
	this->m_proj_subtitle_ent->set_placeholder_text("Subtitle of project");
	this->m_proj_subtitle_ent->set_size_request(500);
	hbx_2->append(*lbl_2);
	hbx_2->append(*this->m_proj_subtitle_ent);

	lbl_3->set_margin_bottom(2);
	lbl_3->set_xalign(1);
	lbl_3->set_size_request(100, -1);
	lbl_3->set_markup("<b>Series:  </b>");
	this->m_proj_series_ent->set_has_frame(false);
	this->m_proj_series_ent->set_max_length(256);
	this->m_proj_series_ent->set_placeholder_text("Series of project");
	this->m_proj_series_ent->set_size_request(500);
	hbx_3->append(*lbl_3);
	hbx_3->append(*this->m_proj_series_ent);

	lbl_4->set_margin_bottom(2);
	lbl_4->set_xalign(1);
	lbl_4->set_size_request(100, -1);
	lbl_4->set_markup("<b>Volume:  </b>");
	this->m_proj_volume_ent->set_has_frame(false);
	this->m_proj_volume_ent->set_max_length(256);
	this->m_proj_volume_ent->set_placeholder_text("Volume of project");
	this->m_proj_volume_ent->set_size_request(500);
	hbx_4->append(*lbl_4);
	hbx_4->append(*this->m_proj_volume_ent);

	lbl_5->set_margin_bottom(2);
	lbl_5->set_xalign(1);
	lbl_5->set_size_request(100, -1);
	lbl_5->set_markup("<b>License:  </b>");
	this->m_proj_license_ent->set_has_frame(false);
	this->m_proj_license_ent->set_max_length(256);
	this->m_proj_license_ent->set_placeholder_text("License of project");
	this->m_proj_license_ent->set_size_request(500);
	hbx_5->append(*lbl_5);
	hbx_5->append(*this->m_proj_license_ent);			

	auto sep_1 = Gtk::make_managed<Gtk::Separator>(Gtk::Orientation::HORIZONTAL);
	sep_1->set_margin_top(20);
	sep_1->set_margin_bottom(20);
	sep_1->set_hexpand(true);
	
	hbx_6->append(*sep_1);

	lbl_6->set_margin_bottom(2);
	lbl_6->set_xalign(1);
	lbl_6->set_size_request(100, -1);
	lbl_6->set_markup("<b>Folder:  </b>");
	this->m_proj_folder_ent->set_has_frame(false);
	this->m_proj_folder_ent->set_max_length(256);
	this->m_proj_folder_ent->set_placeholder_text("Folder location for project");
	this->m_proj_folder_ent->set_size_request(500);
	this->m_proj_folder_ent->set_editable(false);
	btn_1->set_child(*img_1);
	btn_1->set_has_frame(false);
	btn_1->signal_clicked().connect(sigc::mem_fun(*this, &ProjectBox::on_folder_clicked));
	btn_1->set_size_request(24, -1);
	btn_1->set_tooltip_text("Presents a dialog to choose a folder where \nthe project's data will be stored");
	hbx_7->append(*lbl_6);
	hbx_7->append(*this->m_proj_folder_ent);
	hbx_7->append(*btn_1);

	box_2->append(*hbx_1);
	box_2->append(*hbx_2);
	box_2->append(*hbx_3);
	box_2->append(*hbx_4);
	box_2->append(*hbx_5);
	box_2->append(*hbx_6);
	box_2->append(*hbx_7);

	swn->set_child(*box_2);

	return box_1;
}

Gtk::Box* ProjectBox::set_author_ui() {
	// Configure parent box
	auto box_1 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL, 0);
	auto box_2 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL, 0);
	auto swn = Gtk::make_managed<Gtk::ScrolledWindow>();
	swn->set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  	swn->set_expand(true);

	box_1->append(*swn);
	box_1->set_homogeneous(false);
	box_1->set_size_request(650, 250);
	box_1->set_margin(50);
	box_1->set_valign(Gtk::Align::START);
	box_1->set_halign(Gtk::Align::CENTER);

	// Add widgets
	auto hbx_1 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_2 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);
	auto hbx_3 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 0);

	auto lbl_1 = Gtk::make_managed<Gtk::Label>();
	auto lbl_2 = Gtk::make_managed<Gtk::Label>();
	auto lbl_3 = Gtk::make_managed<Gtk::Label>();

	this->m_auth_name_ent = Gtk::make_managed<Gtk::Entry>();
	this->m_auth_email_ent = Gtk::make_managed<Gtk::Entry>();
	this->m_auth_bio_tvw = Gtk::make_managed<Gtk::TextView>();

	lbl_1->set_margin_bottom(2);
	lbl_1->set_xalign(1);
	lbl_1->set_size_request(100, -1);
	lbl_1->set_markup("<b>Name:  </b>");
	this->m_auth_name_ent->set_has_frame(false);
	this->m_auth_name_ent->set_max_length(256);
	this->m_auth_name_ent->set_placeholder_text("Name of the author");
	this->m_auth_name_ent->set_size_request(500);
	hbx_1->append(*lbl_1);
	hbx_1->append(*this->m_auth_name_ent);	

	lbl_2->set_margin_bottom(2);
	lbl_2->set_xalign(1);
	lbl_2->set_size_request(100, -1);
	lbl_2->set_markup("<b>Email:  </b>");
	this->m_auth_email_ent->set_has_frame(false);
	this->m_auth_email_ent->set_max_length(256);
	this->m_auth_email_ent->set_placeholder_text("Email address of the author");
	this->m_auth_email_ent->set_size_request(500);
	hbx_2->append(*lbl_2);
	hbx_2->append(*this->m_auth_email_ent);

	lbl_3->set_margin_bottom(2);
	lbl_3->set_xalign(1);
	lbl_3->set_yalign(0);
	lbl_3->set_size_request(100, -1);
	lbl_3->set_markup("<b>Bio:  </b>");
	this->m_auth_bio_tvw->set_size_request(500, 200);
	this->m_auth_bio_tvw->set_expand(true);
	hbx_3->append(*lbl_3);
	hbx_3->append(*this->m_auth_bio_tvw);

	box_2->append(*hbx_1);
	box_2->append(*hbx_2);
	box_2->append(*hbx_3);

	swn->set_child(*box_2);

	return box_1;
}

void ProjectBox::on_folder_clicked() {
	auto dialog = Gtk::FileDialog::create();

	// Show the dialog and wait for a user response:
	dialog->select_folder(sigc::bind(sigc::mem_fun(*this, &ProjectBox::on_folder_clicked_finish), dialog));
}

void ProjectBox::on_folder_clicked_finish(const Glib::RefPtr<Gio::AsyncResult>& result, 
										 const Glib::RefPtr<Gtk::FileDialog>& dialog) {
  // Handle the response:
  try {
    auto folder = dialog->select_folder_finish(result);
    this->m_proj_folder_ent->set_text(folder->get_path());
  } catch (const Gtk::DialogError& err) {
    // Can be thrown by dialog->select_folder_finish(result).
    //std::cout << "No folder selected. " << err.what() << std::endl;
  } catch (const Glib::Error& err) {
    //std::cout << "Unexpected exception. " << err.what() << std::endl;
  }
}