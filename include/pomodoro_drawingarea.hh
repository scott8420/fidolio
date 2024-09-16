#ifndef __POMODORO_DRAWINGAREA__
#define __POMODORO_DRAWINGAREA__

#include <gtkmm.h>

class Ticker;

class PomodoroDrawingArea : public Gtk::DrawingArea {
public:
	PomodoroDrawingArea();

	void on_draw(const Cairo::RefPtr<Cairo::Context>&, int, int);
	void set_color(const Gdk::RGBA&);
	void set_phase(const Glib::ustring&);
	void set_round(guint8);
	void set_timeout(gint16);
	void set_tick(bool);
	void start();
	void start(const Gdk::RGBA&, const Glib::ustring&, gint8, gint16, bool);
	void stop();
	void reset();

protected:
	void set_timer();
	bool on_triggered();

private:
	Gdk::RGBA m_color;
	Glib::ustring m_phase;
	Glib::RefPtr<Ticker> m_ticker;
	guint8 m_round;
	bool m_tick;
};

#endif