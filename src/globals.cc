#include <globals.hh>

Globals::Globals() {

}

Globals::~Globals() {

}

Globals* Globals::get() {
	static Globals* instance = nullptr;
	
	if(instance == nullptr) {
		instance = new Globals();
	}

	return instance;
}

Glib::ustring& Globals::app_name() { 
	return this->m_app_name; 
}

Glib::ustring& Globals::app_version() { 
	return this->m_app_version; 
}