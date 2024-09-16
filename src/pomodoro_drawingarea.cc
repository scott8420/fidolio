#include <pomodoro_drawingarea.hh>
#include <cairomm/context.h>
#include <utils.hh>
#include <ticker.hh>

#include <iostream>

PomodoroDrawingArea::PomodoroDrawingArea() 
	: m_color(RED), m_round(1), m_phase("Focus"), m_tick(false) {
	this->set_timer();
}

void PomodoroDrawingArea::set_timer() {
	this->m_ticker = Glib::RefPtr<Ticker>(new Ticker());
}

void PomodoroDrawingArea::set_color(const Gdk::RGBA& value) {
	this->m_color = value;
}

void PomodoroDrawingArea::set_timeout(gint16 value) {
	this->m_ticker->set_duration(value);
}

void PomodoroDrawingArea::set_round(guint8 value) {
	this->m_round = value;
}

void PomodoroDrawingArea::set_phase(const Glib::ustring& value) {
	this->m_phase = value;
}

void PomodoroDrawingArea::set_tick(bool value) {
	this->m_tick = value;
}

void PomodoroDrawingArea::start(const Gdk::RGBA& color, const Glib::ustring& phase, gint8 round, gint16 timeout, bool tick) {
	this->set_color(color);
	this->set_phase(phase);
	this->set_round(round);
	this->set_timeout(timeout);
	this->set_tick(tick);
	this->start();
}

void PomodoroDrawingArea::start() {
	if (!this->m_ticker->connection.connected()) {
		this->m_ticker->connection = Glib::signal_timeout().connect(sigc::mem_fun(*this, &PomodoroDrawingArea::on_triggered), this->m_ticker->interval);
	}
}

void PomodoroDrawingArea::stop() {
	this->m_ticker->stop();
}

void PomodoroDrawingArea::reset() {
	this->m_ticker->reset();
}

bool PomodoroDrawingArea::on_triggered() {
	if (this->m_ticker->counter > 0) {
		// Redraw the clock
		this->queue_draw();
		//std::cout << "Timeout triggered: " << this->m_ticker->counter-- << std::endl;
		return true;
	}
	return false;
}

void PomodoroDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
	// Set the origin (x, y) and radius values
	int x = width / 2; // Adjust the x-coordinate as needed
	int y = height / 2; // Adjust the y-coordinate as needed
	int smaller = (width >= height) ? height : width; 
	double radius = double(smaller) / 2.0f; // Adjust the radius as needed

	// Move to the origin
	cr->move_to(x, y);

	// Draw the circle
	cr->arc(x, y, radius, 0, 360 * (M_PI / 180)); // Draw a full circle

	// Stroke the circle (optional)
	cr->set_line_width(2); // Adjust the line width as needed
	cr->stroke();
}
