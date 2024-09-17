#ifndef __TICKER_HH__
#define __TICKER_HH__

#include <gtkmm.h>
#include <glibmm.h>

class Ticker {
public: 
	Ticker(gint32 interval, gint32 duration, gint32 counter) 
		: interval(interval), duration(duration), counter(counter) {
	}

	Ticker() 
		: interval(0), duration(0), counter(0) {
	}

	void pause() {
		this->connection.disconnect();
	}

	void reset() {
		this->connection.disconnect();
		this->counter = this->duration;
	}

	void set_interval(gint32 value) {
		this->interval = value;

		if (this->connection.connected()) {
			this->pause();
		}
	}

	void set_duration(gint32 value) {
		this->duration = value;
		this->counter = value;
		if (this->connection.connected()) {
			this->pause();
		}
	}

	gint32 get_duration() {
		return this->duration;
	}

	void set_counter(gint32 value) {
		this->counter = value;
	}

	gint32 get_counter() {
		return this->counter;
	}

	float get_percentage() {
		if (this->counter < 1) {
			return 0;
		}

		return float(this->counter) / float(this->duration);
	}
	
	gint32 interval;
	sigc::connection connection;
	
protected:
	gint32 counter;
	gint32 duration;
};

#endif