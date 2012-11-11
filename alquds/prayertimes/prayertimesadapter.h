#ifndef PRAYERTIMESADAPTER_H
#define PRAYERTIMESADAPTER_H
#include <QDate>
#include "prayertimes.hpp"
#include <QMap>

class PrayerTimesAdapter : public QObject
{
    Q_OBJECT

public:
    explicit PrayerTimesAdapter(double xLatitude, double xLongitude, double xTimezone);
    QTime *getPrayerTimes();

public slots:
    void updatePrayerTimes();
    void setLocation(double xLatitude, double xLongitude);
    void setTimezone(double xTimezone);
    void setCalculationMethod(PrayerTimes::CalculationMethod xCalc_method);
    void setAsrMethod(PrayerTimes::JuristicMethod xAsr_juristic);
    void setAdjustingMethod(PrayerTimes::AdjustingMethod xAdjust_high_lats);
    void setDhuhrMinutes(double xDhuhr_minutes);

private:
    QDate mCurrentDate;
    QTime *mPrayerTimes;
    double mLatitude, mLongitude, mTimezone;
    PrayerTimes::CalculationMethod mCalc_method;		// caculation method
    PrayerTimes::JuristicMethod mAsr_juristic;		// Juristic method for Asr
    PrayerTimes::AdjustingMethod mAdjust_high_lats;	// adjusting method for higher latitudes
    double mDhuhr_minutes;                          // minutes after mid-day for Dhuhr
};

#endif // PRAYERTIMESADAPTER_H
