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
	const Glib::ustring& get_phase();
	void set_round(guint8);
	guint8 get_round();
	void set_interval(gint32);
	void set_duration(gint32);
	void set_tick(bool);
	void set_draw_time(bool);
	void set_draw_phase(bool);
	void set_draw_round(bool);
	void start();
	void start(const Gdk::RGBA& color, const Glib::ustring& phase, 
				guint8 round, gint32 interval, gint32 duration, 
				gint32 counter, bool ticks = false, bool draw_time = false, 
				bool draw_round = false, bool draw_phase = false);
	void pause();
	void reset();
	gint32 get_counter();
protected:
	void set_timer();
	bool on_triggered();
	float get_degree();

private:
	Gdk::RGBA m_color;
	Glib::ustring m_phase;
	Glib::RefPtr<Ticker> m_ticker;
	guint8 m_round;
	bool m_tick;
	bool m_draw_time;
	bool m_draw_phase;
	bool m_draw_round;
};

#endif