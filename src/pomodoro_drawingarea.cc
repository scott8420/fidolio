#include <pomodoro_drawingarea.hh>
#include <cairomm/context.h>
#include <utils.hh>
#include <ticker.hh>

#include <iostream>

#define DEGR(value)  value * (M_PI / 180.0f)
#define ZERO DEGR(-90.0f)
#define FONTSIZE 14
#define MINS 60
#define SECS 60

PomodoroDrawingArea::PomodoroDrawingArea() 
	: m_color(RED), m_round(1), m_phase("Focus"), 
	  m_tick(false), m_draw_time(false), 
	  m_draw_phase(false), m_draw_round(false) {

	this->set_timer();
	this->set_draw_func(sigc::mem_fun(*this, &PomodoroDrawingArea::on_draw));
	this->set_size_request(85, 101);
	this->set_margin(0);
}

void PomodoroDrawingArea::set_timer() {
	this->m_ticker = Glib::RefPtr<Ticker>(new Ticker());
}

void PomodoroDrawingArea::set_color(const Gdk::RGBA& value) {
	this->m_color = value;
}

void PomodoroDrawingArea::set_round(guint8 value) {
	this->m_round = value;
}

guint8 PomodoroDrawingArea::get_round() {
	return this->m_round;
}

void PomodoroDrawingArea::set_phase(const Glib::ustring& value) {
	this->m_phase = value;
}

const Glib::ustring& PomodoroDrawingArea::get_phase() {
	return this->m_phase;
}

void PomodoroDrawingArea::set_tick(bool value) {
	this->m_tick = value;
}

void PomodoroDrawingArea::start(const Gdk::RGBA& color, const Glib::ustring& phase, 
								guint8 round, gint32 interval, gint32 duration, 
								gint32 counter, bool ticks, bool draw_time, 
								bool draw_round, bool draw_phase) {
	this->set_color(color);
	this->set_phase(phase);
	this->set_round(round);
	this->m_ticker->set_interval(interval);
	this->m_ticker->set_duration(duration);
	this->m_ticker->set_counter(counter);
	this->set_tick(ticks);
	this->set_draw_phase(draw_phase);
	this->set_draw_round(draw_round);
	this->set_draw_time(draw_time);
	this->start();
}

void PomodoroDrawingArea::start() {
	if (!this->m_ticker->connection.connected()) {
		this->m_ticker->connection = Glib::signal_timeout().connect(sigc::mem_fun(*this, &PomodoroDrawingArea::on_triggered), this->m_ticker->interval);
	}
}

void PomodoroDrawingArea::pause() {
	this->m_ticker->pause();
}

void PomodoroDrawingArea::reset() {
	this->m_ticker->reset();
	this->queue_draw();
}

bool PomodoroDrawingArea::on_triggered() {
	if (this->m_ticker->get_counter() > 0) {
		// Redraw the clock
		this->queue_draw();
		this->m_ticker->set_counter(this->get_counter() - 1);

		return true;
	}

	return false;
}

void PomodoroDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
	
	// Set the origin (x, y) and radius values
	int x = width / 2; // Adjust the x-coordinate as needed
	int y = height / 2; // Adjust the y-coordinate as needed
	int smaller = (width >= height) ? height : width; 
	double radius = double(smaller - 10) / 2.0f; // Adjust the radius as needed

	// Draw full Circle
	if (Utils::dark_mode_on()) {
		cr->set_source_rgba(0.35f, 0.35f, 0.35f, 1.0f);
	} else {
		cr->set_source_rgba(0.0f, 0.0f, 0.0f, 0.25f);
	}

	cr->arc(x, y, radius, ZERO, DEGR(360.0f));
	cr->set_line_width(1);
	cr->stroke();

	// Draw the time circle
	if (this->get_degree() > 0) {
		cr->set_source_rgba(this->m_color.get_red(), this->m_color.get_green(), this->m_color.get_blue(), this->m_color.get_alpha());
		cr->arc(x, y, radius, ZERO, DEGR(this->get_degree()) + ZERO);
		cr->set_line_width(10);
		cr->set_line_cap(Cairo::Context::LineCap::ROUND);
		cr->stroke();
	}

	if (this->m_draw_time) {
		double counter = double(this->m_ticker->get_counter());
		double interval = double(this->m_ticker->interval);
		double seconds = (counter / (1000.0f / interval)) + 1.0;
		int hours = int(seconds) / (MINS * SECS);
		int mins = int(seconds) / SECS;
		double secs = seconds - double(hours * (MINS * SECS)) - double(mins * SECS);
		auto dt = Glib::DateTime::create_local(2024,1,1,hours,mins,secs);
		auto time = dt.format("%H:%M:%S");
		cr->set_font_size(FONTSIZE);
		
		Cairo::TextExtents te;
		cr->get_text_extents(time, te);
		cr->move_to(x-(te.width/2), y+(te.height/2));
		cr->show_text(time);
	}

	if (this->m_draw_phase) {
		cr->set_font_size(FONTSIZE);
		Cairo::TextExtents te;
		cr->get_text_extents(this->get_phase(), te);

		cr->move_to(x-(te.width/2), y+(te.height*2));
		cr->show_text(this->get_phase());
	}

	if (this->m_draw_round) {
		cr->set_font_size(FONTSIZE);
		Glib::ustring rnd = Glib::ustring::sprintf("R:%d", this->get_round());
		Cairo::TextExtents te;
		cr->get_text_extents(rnd, te);

		cr->move_to(x-(te.width/2)-2, y-te.height);
		cr->show_text(rnd);
	}
}

float PomodoroDrawingArea::get_degree() {
	float percent = this->m_ticker->get_percentage();
	return 360.0f * percent;
}

gint32 PomodoroDrawingArea::get_counter() {
	return this->m_ticker->get_counter();
}

void PomodoroDrawingArea::set_draw_time(bool value) {
	this->m_draw_time = value;
}

void PomodoroDrawingArea::set_draw_phase(bool value) {
	this->m_draw_phase = value;
}

void PomodoroDrawingArea::set_draw_round(bool value) {
	this->m_draw_round = value;
}