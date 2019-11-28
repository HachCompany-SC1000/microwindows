#ifndef TS_DEVICE
#define TS_DEVICE "SC1000"

#define TS_DEVICE_FILE "/dev/ts"

struct ts_event {
	short pressure;
	short x;
	short y;
  	short millisecs;
};

#endif
