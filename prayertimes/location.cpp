#include "location.h"
#include "prayertimes.hpp"
#include <QSettings>
#include <QDebug>

Location::Location()
{
    QSettings settings("Ghannami","AlQuds");
//    settings.setValue("location/city","Koblenz");
//    settings.setValue("location/latitude",50.3551);
//    settings.setValue("location/longitude",7.592136);

    mPrayerTimes = new PrayerTimes(PrayerTimes::Egypt);
    double times[6];
    mPrayerTimes->get_prayer_times(2012,10,22,settings.value("latitude").toDouble(),
                                   settings.value("longitude").toDouble(),2, times);

    qDebug()<<"settings: Fajr\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[0]));
    qDebug()<<"settings: Duhr\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[2]));
    qDebug()<<"settings: Asr\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[3]));
    qDebug()<<"settings: Maghrib\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[4]));
    qDebug()<<"settings: Ishaa\t"<<QString::fromStdString(PrayerTimes::float_time_to_time24(times[5]));
}
