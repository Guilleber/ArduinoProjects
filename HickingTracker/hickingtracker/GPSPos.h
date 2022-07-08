#ifndef GPSPos_h
#define GPSPos_h


struct GPSPos {
	float longitude;
	float latitude;
	float altitude;
}

struct GPSTime {
	int hours;
	int minutes;
	int seconds;
}

struct GPSDate {
	int day;
	int month;
	int year;
}


#endif