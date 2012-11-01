#include "prayertimesadapter.h"
#include "prayertimes.hpp"

PrayerTimesAdapter::PrayerTimesAdapter()
{
    mPrayerTimes = new PrayerTimes();
    double times[7];
    mPrayerTimes->get_prayer_times(2012,10,30,Settings::instance()->latitude(),
                                   Settings::instance()->longitude(),1 ,times);
    qDebug();
    qDebug()<<"settings: Fajr\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[0]));
    qDebug()<<"settings: Shuruk\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[1]));
    qDebug()<<"settings: Duhr\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[2]));
    qDebug()<<"settings: Asr\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[3]));
    qDebug()<<"settings: Maghrib\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[4]));
    qDebug()<<"settings: Ishaa\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[6]));

}

