#include <iostream>
#include <map>
using namespace std ;
map < string  , int > Month ;
map < int , string > MonthInNumbers ;
void months (){
    Month["Jenuary"] = 1 ;
    Month["February"] = 2 ;
    Month["March"] = 3 ;
    Month["April"] = 4 ;
    Month["May"] = 5 ;
    Month["June"] = 6 ;
    Month["July"] = 7 ;
    Month["August"] = 8 ;
    Month["September"] = 9 ;
    Month["October"] = 10 ;
    Month["November"] = 11 ;
    Month["December"] = 12 ;
}
void NumberMonths (){
    MonthInNumbers[1] = "Jenuary" ;
    MonthInNumbers[2] = "February" ;
    MonthInNumbers[3] = "March" ;
    MonthInNumbers[4] = "April" ;
    MonthInNumbers[5] = "May" ;
    MonthInNumbers[6] = "June" ;
    MonthInNumbers[7] = "July" ;
    MonthInNumbers[8] = "August" ;
    MonthInNumbers[9] = "September" ;
    MonthInNumbers[10] = "October" ;
    MonthInNumbers[11] = "November" ;
    MonthInNumbers[12] = "December" ;
}
struct Date{
    int day ;
    string month ;
    int year ;
    Date(int d , string m , int y) : day(d) , month(m) , year(y){

    }
    string DayMonthYear(){
        string Day = to_string(day);
        string Year = to_string(year) ;
        string Date_in_words = Day + "-" + month + "-" + Year ;
        return Date_in_words ;
    }
    string MonthYear(){
        string Year = to_string(year) ;
        string Date_in_words = month + "-" + Year ;
        return Date_in_words ;
    }
    string DayMonth(){
        string Day = to_string(day);
        string Date_in_words = Day + "-" + month ;
        return Date_in_words ;
    }

    bool IsEqual(Date date){
        if(date.year == year and date.month == month and date.day == day)
            return true ;
        return false ;
    }
    bool IsAfter(Date date){
        if(date.year < year) return false ;
        if(date.year > year) return true ;
        if(Month[date.month] > Month[month]) return true ;
        if(date.day > day) return true ;
        return false ;
    }
    bool IsBefore(Date date){
        if(date.year > year) return false ;
        if(date.year < year) return true ;
        if(Month[date.month] < Month[month]) return true ;
        if(date.day < day) return true ;
        return false ;
    }
    void MinusYears(int num){
       year -= num ;
    }
    void MinusMonths( int num){
        int NumberMonth = Month[month] ;
        NumberMonth -= num ;
        month = MonthInNumbers[NumberMonth] ;
    }
    void MinusDays(int num){
       day -= num ;
    }
   void AddYears(int num){
        year += num ;
    }
   void AddMonths(int num){
        int NumberMonth = Month[month] ;
        NumberMonth += num ;
        month = MonthInNumbers[NumberMonth] ;
    }
    void AddDays(int num){
        day += num ;
    }
    int Length_Of_Month(string m){
        if(m == "January" || m == "March" || m == "May" || m == "July" || m == "August" || m == "October" || m == "December")
            return 31 ;
        if(m == "April" || m == "June" || m == "September" || m == "November") return 30 ;
        if(m == "February" and year % 4) return 28 ;
        if(m == "February" and year % 4 == 0)
            return 29 ;
    }
    void Count_Down(Date d){
        int Years = d.year - year , days;
        if(d.month == month) days = d.day - day ;
        else {
            days = Length_Of_Month(month) - day + d.day;
            int m = Month[month], mm = Month[d.month];
            m = max(0, mm - m - 1);
            days += m * 30;
        }
        int Months = days / 30 ;
        days %= 30 ;
        cout << Years << " Years , " << Months << " Months , " << days << " Days" << endl;
    }
    bool LeapYear(){
        if (year % 4 == 0)
            return true ;
        else
            return false ;
    }
    string ISHoliday() {
        if (day == 7 and month == "January") {
            return "YES , its Christmas Day";
        }
        if (day == 25 and month == "February") {
            return "YES , its Anniversary of January 25 Revolution and Police day";
        }
        if (day == 17 and month == "April") {
            return "YES , its Easter Day" ;
        }
        if(day == 25 and month == "April"){
            return "YES , its Sinai Liberation day" ;
        }
        if(day == 1 and month == "May"){
            return "YES , its labor day\n" ;
        }
        if(day == 30 and month == "June"){
            return "YES , its Anniversary of the June 30 Revolution" ;
        }
        if(day == 23 and month == "July"){
            return "YES , its Anniversary of the July 23 Revolution" ;
        }
        if(day == 6 and month == "October"){
            return "YES , The anniversary of the Sixth of October War" ;
        }
        return "NO\n" ;
    }
    void printDate(){
        cout << DayMonthYear() << endl ;
    }
};
int main() {
months() ;
NumberMonths() ;
Date d1(12 , "October" , 2004) ;
cout << d1.DayMonthYear() << endl << d1.DayMonth() << endl << d1.MonthYear() << endl;
Date d2(23 , "March" , 2003) ;
cout << d1.IsEqual(d2) << endl;
cout << d1.IsAfter(d2) << endl;
cout << d1.IsBefore(d2) << endl;
d1.MinusYears(1) ;
d1.MinusMonths(1) ;
d1.MinusDays(10) ;
d1.printDate() ;
d2.AddDays(5) ;
d2.AddMonths(2) ;
d2.AddYears(2) ;
d2.printDate() ;
cout << d1.Length_Of_Month(d1.month) << endl;
d1.Count_Down(d2) ;
Date d3(6 , "October" , 2020) ;
cout << d3.ISHoliday() << endl;
Date d4(10 , "May" , 2005) ;
cout << d4.ISHoliday() << endl;

    return 0;
}
