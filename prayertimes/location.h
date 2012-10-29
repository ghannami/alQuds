#ifndef LOCATION_H
#define LOCATION_H

class PrayerTimes;

class Location
{
public:
    Location();
    void readSettings();

private:
    PrayerTimes *mPrayerTimes;
};

#endif // LOCATION_H
