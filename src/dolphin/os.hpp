#pragma once

#include "globalDefs.hpp"
#include "types.hpp"

ASMDefined u64 gettime(); // ogc function

struct OSCalendarTime
{
    int sec;    ///< seconds after the minute [0, 61]
    int min;    ///< minutes after the hour [0, 59]
    int hour;   ///< hours since midnight [0, 23]
    int mday;   ///< day of the month [1, 31]
    int mon;    ///< month since January [0, 11]
    int year;   ///< years since 0000
    int wday;   ///< days since Sunday [0, 6]
    int yday;   ///< days since January 1 [0, 365]

    int msec;   ///< milliseconds after the second [0,999]
    int usec;   ///< microseconds after the millisecond [0,999]
};

ASMDefined void __OSTicksToCalendarTime(u64 ticks, OSCalendarTime *td);