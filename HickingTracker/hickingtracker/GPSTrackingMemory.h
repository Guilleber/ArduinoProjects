#ifndef GPSTrackingMemory_h
#define GPSTrackingMemory_h

#include "Arduino.h"
#include <SPI.h>
#include <SD.h>


void format_timestamp(char timestamp[], int year, int month, int day, int hour, int minute);


class GPSTrackingMemory {
public:
	explicit GPSTrackingMemory(char name[]);
	//void seek(int line);
	//void add(GPSPos new_pos);
	//GPSPos getNext();
private:
  char name[21] = "";
	//File path_file;
	//int nb_pos;
};


#endif
