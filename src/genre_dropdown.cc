#include <genre_dropdown.hh>
#include <utils.hh>
#include <iostream>

GenreDropDown::GenreDropDown() : Gtk::DropDown() {
	// Factory for presenting the selected item.
	auto factory = Gtk::SignalListItemFactory::create();
	factory->signal_setup().connect(
	sigc::mem_fun(*this, &GenreDropDown::on_setup_selected_item));
	factory->signal_bind().connect(sigc::mem_fun(*this, &GenreDropDown::on_bind_selected_item));
	this->set_factory(factory);

	// Factory for presenting the items in the dropdown list.
	factory = Gtk::SignalListItemFactory::create();
	factory->signal_setup().connect(sigc::mem_fun(*this, &GenreDropDown::on_setup_list_item));
	factory->signal_bind().connect(sigc::mem_fun(*this, &GenreDropDown::on_bind_list_item));
	this->set_list_factory(factory);

	// Create the model and fill it.
	this->create_model();
	this->set_model(m_ListStore);
	this->set_selected(0);

	// // Show a search entry.
	// this->set_enable_search(true);

	// // Closure procedure with lamda
	// Glib::RefPtr<GenreDropDown::ModelColumns> expression = Gtk::ClosureExpression<GenreDropDown::ModelColumns>::create(
	// 	[](const Glib::RefPtr<Glib::ObjectBase>& item)->Glib::RefPtr<GenreDropDown::ModelColumns> {
	// 		// An item is a ModelColumns
	// 	const Glib::RefPtr<GenreDrop Down::ModelColumns> mc = std::dynamic_pointer_cast<GenreDropDown::ModelColumns>(item);
	// 	return mc;
	// });

	// this->set_expression(expression);

	// Connect signal handler:
	this->property_selected().signal_changed().connect(sigc::mem_fun(*this, &GenreDropDown::on_dropdown_changed));
}

void GenreDropDown::create_model() {
	m_ListStore = Gio::ListStore<ModelColumns>::create();
	
	liststore_add_item("Action/Adventure", "icon", "Fast-paced stories with thrilling plots, \noften featuring heroes and villains, and emphasizing \nphysical action and suspense");
	liststore_add_item("Biography", "icon", "Non-fiction accounts of real people\'s lives, \nwritten by someone other than the subject");
	liststore_add_item("Comedy", "icon", "Humorous fiction, often lighthearted and entertaining, \nintended to amuse and sometimes provoke laughter");
	liststore_add_item("Crime/Detective", "icon", "Mystery fiction focusing on solving crimes, \noften featuring detectives and investigations");
	liststore_add_item("Dystopian", "icon", "Fiction set in a hypothetical future society that \nhas been devastated or degraded, often exploring themes \nof government control and social upheaval");
	liststore_add_item("Epic Fantasy", "icon", "Long, grandiose stories with elaborate world-building, \ncomplex plots, and heroic quests");
	liststore_add_item("Fantasy", "icon", "Fiction that involves magical or supernatural elements, \noften set in imaginary worlds");
	liststore_add_item("Graphic Novel", "icon", "Highly illustrated stories, often using comic panels \nand speech bubbles, which can cover various genres");
	liststore_add_item("Historical Fiction", "icon", "Fiction set in a specific historical time \nperiod, often incorporating real events and figures");
	liststore_add_item("Horror", "icon", "Fiction that aims to evoke fear, anxiety, and unease, \noften featuring supernatural or terrifying elements");
	liststore_add_item("Literary Fiction", "icon", "Serious, character-driven fiction that explores \nthemes and emotions, often focusing on the human condition");
	liststore_add_item("Memoir", "icon", "Non-fiction accounts of the author\'s own life, often \nfocusing on a specific period or theme");
	liststore_add_item("Mystery", "icon", "Fiction that involves solving a puzzle or uncovering a \nhidden truth, often featuring detectives and investigations");
	liststore_add_item("New Adult", "icon", "Fiction focused on the challenges and experiences of \nyoung adults transitioning to adulthood");
	liststore_add_item("Paranormal Romance", "icon", "Fiction that combines elements of romance and \nfantasy, often featuring supernatural or paranormal elements");
	liststore_add_item("Police Procedural", "icon", "Crime fiction that focuses on the investigative \nprocedures and protocols of law enforcement");
	liststore_add_item("Regency Romance", "icon", "Fiction set during the Regency Era in England (1795-1837), \noften focusing on societal norms and romantic relationships");
	liststore_add_item("Romance", "icon", "Fiction that focuses on the emotional journey and relationship \nbetween characters, often with a happy ending");
	liststore_add_item("Science Fiction", "icon", "Speculative fiction that explores the consequences of \nscientific or technological advancements, often set in the future");
	liststore_add_item("Thriller", "icon", "Fiction that aims to evoke tension and suspense, often featuring \nfast-paced plots and high stakes");
	liststore_add_item("Western", "western", "Fiction that aims to evoke tension and suspense, often featuring \nfast-paced plots and high stakes");
	liststore_add_item("Young Adult (YA)", "icon", "Fiction focused on the challenges and experiences of teenagers, \noften exploring themes of identity and coming-of-age");
}

void GenreDropDown::liststore_add_item(const Glib::ustring& title,
	const Glib::ustring& image, const Glib::ustring& description) {
		
		m_ListStore->append(ModelColumns::create(title, image, description));
}

void GenreDropDown::on_setup_selected_item(const Glib::RefPtr<Gtk::ListItem>& list_item) {
  auto box = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 10);
  box->append(*Gtk::make_managed<Gtk::Image>());
  box->append(*Gtk::make_managed<Gtk::Label>());
  list_item->set_child(*box);
}

void GenreDropDown::on_bind_selected_item(const Glib::RefPtr<Gtk::ListItem>& list_item) {
  auto col = std::dynamic_pointer_cast<ModelColumns>(list_item->get_item());
  if (!col) return;
  
  auto box = dynamic_cast<Gtk::Box*>(list_item->get_child());
  if (!box) return;
  
  auto image = dynamic_cast<Gtk::Image*>(box->get_first_child());
  if (!image) return;
  //image->set_from_icon_name(col->m_image);
  image->set(Utils::image_from_name(col->m_image));
  
  auto label = dynamic_cast<Gtk::Label*>(image->get_next_sibling());
  if (!label) return;
  label->set_text(col->m_title);
}

void GenreDropDown::on_setup_list_item(const Glib::RefPtr<Gtk::ListItem>& list_item) {
	auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 10);
	auto vbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL, 2);

	hbox->append(*Gtk::make_managed<Gtk::Image>());
	hbox->append(*vbox);
	auto title = Gtk::make_managed<Gtk::Label>();
	title->set_xalign(0.0);
	vbox->append(*title);
	auto description = Gtk::make_managed<Gtk::Label>();
	description->set_xalign(0.0);
	description->add_css_class("dim-label");
	vbox->append(*description);
	auto checkmark = Gtk::make_managed<Gtk::Image>();
	checkmark->set_from_icon_name("object-select-symbolic");
	checkmark->set_visible(false);
	hbox->append(*checkmark);

	list_item->set_child(*hbox);
}

void GenreDropDown::on_bind_list_item(const Glib::RefPtr<Gtk::ListItem>& list_item) {
	auto col = std::dynamic_pointer_cast<ModelColumns>(list_item->get_item());
	if (!col) return;
 
	auto hbox = dynamic_cast<Gtk::Box*>(list_item->get_child());
	if (!hbox) return;
  
	auto image = dynamic_cast<Gtk::Image*>(hbox->get_first_child());
	if (!image) return;
	image->set(Utils::image_from_name(col->m_image));
	//image->set_from_icon_name(col->m_image);

	auto vbox = dynamic_cast<Gtk::Box*>(image->get_next_sibling());
	if (!vbox) return;

	auto title = dynamic_cast<Gtk::Label*>(vbox->get_first_child());
	if (!title) return;
	title->set_text(col->m_title);
	
	auto description = dynamic_cast<Gtk::Label*>(title->get_next_sibling());
	if (!description) return;
	description->set_text(col->m_description);

	auto connection = this->property_selected_item().signal_changed().connect(
		sigc::bind(sigc::mem_fun(*this, &GenreDropDown::on_selected_item_changed),
		list_item));

	list_item->set_data("connection", new sigc::connection(connection),
		Glib::destroy_notify_delete<sigc::connection>);
	
	on_selected_item_changed(list_item);
}

void GenreDropDown::on_unbind_list_item(const Glib::RefPtr<Gtk::ListItem>& list_item) {
	if (auto connection = static_cast<sigc::connection*>(list_item->get_data("connection"))) {
		connection->disconnect();
		list_item->set_data("connection", nullptr);
	}
}

void GenreDropDown::on_selected_item_changed(const Glib::RefPtr<Gtk::ListItem>& list_item){
	auto hbox = dynamic_cast<Gtk::Box*>(list_item->get_child());
	if (!hbox) return;
	
	auto checkmark = dynamic_cast<Gtk::Image*>(hbox->get_last_child());
	if (!checkmark) return;
	
	checkmark->set_visible(this->get_selected_item() == list_item->get_item());
}

void GenreDropDown::on_dropdown_changed() {
  const auto selected = this->get_selected();
  std::cout << "DropDown changed: Row=" << selected
    << ", Title=" << m_ListStore->get_item(selected)->m_title << std::endl;
}