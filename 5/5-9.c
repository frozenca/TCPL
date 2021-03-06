static const char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day) {
    int leap = year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
    if (month < 1 || month > 12) {
        return -1;
    }
    if (day < 1 || day > daytab[leap][month]) {
        return -1;
    }
    char* p = daytab[leap];
    while (--month) {
        day += *++p;
    }
    return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int* pmonth, int* pday) {
    int leap = year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
    char* p = daytab[leap];
    while (yearday > *++p) {
        yearday -= *p;
    }
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}

int main() {

}
