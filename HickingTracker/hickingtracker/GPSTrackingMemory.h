#ifndef GPSTrackingMemory_h
#define GPSTrackingMemory_h

#include "Arduino.h"
#include <SPI.h>
#include <SD.h>

#include "GPSPos.h"


class GPSTrackingMemory {
public:
	explicit GPSTrackingMemory(String name);
	void seek(int line);
	void add(GPSPos new_pos);
	GPSPos getNext();
	~GPSTrackingMemory();
private:
	File path_file;
	int nb_pos;
};


#endif