#ifndef PRAYERTIMESADAPTER_H
#define PRAYERTIMESADAPTER_H
#include <QDate>
class PrayerTimes;

class PrayerTimesAdapter
{
public:
    explicit PrayerTimesAdapter();

private:
    PrayerTimes mPrayerTimes;
    QDate mCurrentDate;
    double mLatitude, mLongtitude;
};

#endif // PRAYERTIMESADAPTER_H
