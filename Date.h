class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day1, int month1, int year1);
	int getDay() const {
		return day;
	}

	void setDay(int day) {
		this->day = day;
	}

	int getmonth() const {
		return month;
	}

	void setmonth(int month) {
		this->month = month;
	}

	int getYear() const {
		return year;
	}

	void setYear(int year) {
		this->year = year;
	}
};
Date::Date() {
	setDay(0);
	setmonth(0);
	setYear(0);
}
Date::Date(int day1, int month1, int year1) {
	day = day1;
	month = month1;
	year = year1;
}
