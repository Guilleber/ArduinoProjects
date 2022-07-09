#include "Utils.h"


int getLocalHour(int hour) {
  return (hour + LOCAL_TIME)%24;
}
