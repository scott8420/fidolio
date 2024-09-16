#ifndef __TICKER_HH__
#define __TICKER_HH__

#include <gtkmm.h>
#include <glibmm.h>

class Ticker {
public: 
	Ticker(gint32 interval, gint32 duration) 
		: interval(interval), duration(duration), counter(duration) {
	}

	Ticker() 
		: interval(0), duration(0), counter(0) {
	}

	void stop() {
		this->connection.disconnect();
	}

	void reset() {
		this->connection.disconnect();
		this->counter = this->duration;
	}

	void set_interval(gint32 value) {
		this->interval = value;

		if (this->connection.connected()) {
			this->stop();
		}
	}

	void set_duration(gint32 value) {
		this->duration = value;
		this->counter = value;
		if (this->connection.connected()) {
			this->stop();
		}
	}
	
	gint32 counter;
	gint32 interval;
	sigc::connection connection;
	
protected:
	gint32 duration;
};

#endif