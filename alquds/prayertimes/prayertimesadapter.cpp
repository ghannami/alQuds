#include "prayertimesadapter.h"
#include "prayertimes.hpp"

PrayerTimesAdapter::PrayerTimesAdapter(double xLatitude, double xLongitude, double xTimezone)
    :mLatitude(xLatitude), mLongitude(xLongitude), mTimezone(xTimezone)
{
    mCurrentDate = QDate::currentDate();
    mPrayerTimes = new QTime[PrayerTimes::TimesCount];

    mCalc_method = PrayerTimes::Makkah;
    mAsr_juristic = PrayerTimes::Shafii;
    mAdjust_high_lats = PrayerTimes::MidNight;
    mDhuhr_minutes = 0;
}

QTime *PrayerTimesAdapter::getPrayerTimes()
{
    if(mCurrentDate != QDate::currentDate())
        updatePrayerTimes();
    return mPrayerTimes;
}

void PrayerTimesAdapter::updatePrayerTimes()
{
    mCurrentDate = QDate::currentDate();
    PrayerTimes tPrayerTimes;

    tPrayerTimes.set_calc_method(mCalc_method);
    tPrayerTimes.set_asr_method(mAsr_juristic);
    tPrayerTimes.set_dhuhr_minutes(mDhuhr_minutes);
    tPrayerTimes.set_high_lats_adjust_method(mAdjust_high_lats);

    double times[PrayerTimes::TimesCount];
    tPrayerTimes.get_prayer_times(mCurrentDate.year(), mCurrentDate.month(), mCurrentDate.day(), mLatitude,
                                   mLongitude, mTimezone ,times);
    for(int i=0; i < PrayerTimes::TimesCount; i++)
    {
        int tHours, tMinutes;
        PrayerTimes::get_float_time_parts(times[i], tHours, tMinutes);
        mPrayerTimes[i] = QTime(tHours, tMinutes);
    }
}

void PrayerTimesAdapter::setLocation(double xLatitude, double xLongitude)
{
    mLatitude   = xLatitude;
    mLongitude  = xLongitude;
    updatePrayerTimes();
}

void PrayerTimesAdapter::setTimezone(double xTimezone)
{
    mTimezone = xTimezone;
    updatePrayerTimes();
}

void PrayerTimesAdapter::setCalculationMethod(PrayerTimes::CalculationMethod xCalc_method)
{
    mCalc_method = xCalc_method;
    updatePrayerTimes();
}

void PrayerTimesAdapter::setAdjustingMethod(PrayerTimes::AdjustingMethod xAdjust_high_lats)
{
    mAdjust_high_lats = xAdjust_high_lats;
    updatePrayerTimes();
}

void PrayerTimesAdapter::setDhuhrMinutes(double xDhuhr_minutes)
{
    mDhuhr_minutes = xDhuhr_minutes;
    updatePrayerTimes();
}

void PrayerTimesAdapter::setAsrMethod(PrayerTimes::JuristicMethod xAsr_juristic)
{
    mAsr_juristic = xAsr_juristic;
    updatePrayerTimes();
}
