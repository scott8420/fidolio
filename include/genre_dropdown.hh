#ifndef __GENRE_DROPDOWN__
#define __GENRE_DROPDOWN__

#include <gtkmm.h>

class GenreDropDown : public Gtk::DropDown {
public:
	GenreDropDown();

protected:
	void on_setup_selected_item(const Glib::RefPtr<Gtk::ListItem>& list_item);
	void on_bind_selected_item(const Glib::RefPtr<Gtk::ListItem>& list_item);
	void on_setup_list_item(const Glib::RefPtr<Gtk::ListItem>& list_item);
	void on_bind_list_item(const Glib::RefPtr<Gtk::ListItem>& list_item);
	void on_unbind_list_item(const Glib::RefPtr<Gtk::ListItem>& list_item);
	void on_selected_item_changed(const Glib::RefPtr<Gtk::ListItem>& list_item);
	void on_dropdown_changed();
	
	void create_model();
	void liststore_add_item(const Glib::ustring&, const Glib::ustring&, const Glib::ustring&);

	// A Gio::ListStore item.
	class ModelColumns : public Glib::Object {
	public:
		Glib::ustring m_title;
		Glib::ustring m_image;
		Glib::ustring m_description;

		static Glib::RefPtr<ModelColumns> create(const Glib::ustring& title,
			const Glib::ustring& image, const Glib::ustring& description) {
			return Glib::make_refptr_for_instance<ModelColumns>( new ModelColumns(title, image, description));
		}

		// static Glib::RefPtr<ModelColumns> create(const Glib::ustring& title,
		// 	const Glib::ustring& icon, const Glib::ustring& description) {
		// 	return Glib::make_refptr_for_instance<ModelColumns>( new ModelColumns(title, icon, description));
		// }
	protected:
		ModelColumns(const Glib::ustring& title, const Glib::ustring& image, const Glib::ustring& description)
    		: m_title(title), m_image(image), m_description(description) {
		}

	}; // ModelColumns

	Glib::RefPtr<Gio::ListStore<ModelColumns>> m_ListStore;
private:
	
};

#endif