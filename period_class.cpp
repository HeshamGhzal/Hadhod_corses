#pragma once
#include"clsDate.h"
class clsperiod
{
private:
	clsdate _start_periode;
	clsdate _end_period;
public:

	clsperiod(clsdate start, clsdate end)
	{
		_start_periode = start;
		_end_period = end;
	}

	static bool Is_periode_overlap(clsperiod periode1, clsperiod periode2)
	{
		if (clsdate::compare_two_dates(periode1._start_periode, periode2._end_period) == 1 ||
			clsdate::compare_two_dates(periode2._start_periode, periode1._end_period) == 1)
			return false;

		return true;
	}
	bool Is_periode_overlap(clsperiod periode2)
	{
		return Is_periode_overlap(*this, periode2);
	}

	static int period_length_in_days(clsperiod periode, bool includ_end_day)
	{
		return clsdate::diffrance_between_two_dates(periode._start_periode, periode._end_period, includ_end_day);
	}
	int period_length_in_days(bool includ_end_day)
	{
		return period_length_in_days(*this, includ_end_day);
	}

	static bool Is_date_within_period(clsdate date, clsperiod periode)
	{
		return  !(clsdate::compare_two_dates(date, periode._start_periode) == -1 ||
			clsdate::compare_two_dates(date, periode._end_period) == 1);
	}
	bool Is_date_within_period(clsdate date)
	{
		return Is_date_within_period(date, *this);
	}

	static int count_overlab_days_between_two_periods(clsperiod periode1, clsperiod periode2)
	{
		int over_lab_days = 0;
		if (!Is_periode_overlap(periode1, periode2))
			return 0;

		if (clsdate::Is_Date1_Befor_Date2(periode2._start_periode, periode1._start_periode))
			swap(periode1, periode2);

		while (clsdate::Is_Date1_Befor_Date2(periode1._start_periode, periode1._end_period))
		{
			if (Is_date_within_period(periode1._start_periode, periode2))
			{
				over_lab_days++;
			}
			periode1._start_periode = clsdate::Increas_date_by_one(periode1._start_periode);
		}

		return over_lab_days;
	}
	int count_overlab_days_between_two_periods(clsperiod periode2)
	{
		return count_overlab_days_between_two_periods(*this, periode2);
	}
};

