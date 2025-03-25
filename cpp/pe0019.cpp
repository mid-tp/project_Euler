#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;




int add_day_leap_year(int year){
    if ((year % 400) == 0){
        return 1;
    }

    if ((year % 4) == 0){
        //A leap year occurs on any year evenly divisible by 4, but not
        // on a century unless it is divisible by 400.
        if ((year % 100) == 0){
            // No leap years on centuries
            return 0;
        }
        // Otherwise, we have a leap year
        return 1;
    }
    // If the year is not divisible by 4 to begin with
    // We definitely don't have a leap year.
    return 0;
}

int main(){

    unordered_map<string, string> day_to_day = {
        {"Mon", "Tue"},
        {"Tue", "Wed"},
        {"Wed", "Thu"},
        {"Thu", "Fri"},
        {"Fri", "Sat"},
        {"Sat", "Sun"},
        {"Sun", "Mon"},
    };

    // Then, keep track of the sundays and the dates.

    unordered_map<string, string> month_to_month = {
        {"Jan", "Feb"},
        {"Feb", "Mar"},
        {"Mar", "Apr"},
        {"Apr", "May"},
        {"May", "Jun"},
        {"Jun", "Jul"},
        {"Jul", "Aug"},
        {"Aug", "Sep"},
        {"Sep", "Oct"},
        {"Oct", "Nov"},
        {"Nov", "Dec"},
        {"Dec", "Jan"},
    };

    unordered_map<string, u_int8_t> month_to_num_days = {
        {"Jan", 31},
        {"Feb", 28},
        {"Mar", 31},
        {"Apr", 30},
        {"May", 31},
        {"Jun", 30},
        {"Jul", 31},
        {"Aug", 31},
        {"Sep", 30},
        {"Oct", 31},
        {"Nov", 30},
        {"Dec", 31},
    };


    string cur_month = "Jan";
    string cur_day = "Mon";
    int day_of_month = 1;
    int cur_year = 1900;
    int sundays_count = 0;
    int leap_year_addition = add_day_leap_year(cur_year);
    int num_month_days;

    while (cur_year  < 2001){
        // Calculate the number of days this month has
        num_month_days = month_to_num_days[cur_month];
        if (cur_month == "Feb") num_month_days += leap_year_addition;

        // Check if we go to another month
        if (day_of_month > num_month_days){
            // In this case, we switch to the next month
            // Go to the next month and reset the day of the month.
            // If we switch from Dec to Jan, add 1 to the current year.    
            cur_month = month_to_month[cur_month];
            day_of_month = 1;

            // Check if the current month is Jan, which mean we made a full
            // year circle.
            if (cur_month == "Jan"){
                cur_year += 1;
                leap_year_addition = add_day_leap_year(cur_year);
            }
        }
        // Do some printing 
        cout << cur_year << " " << cur_month << " " << day_of_month << " is on a " << cur_day << endl;

        // Check if the Sunday is on the first of the month
        if ((day_of_month == 1) && cur_day == "Sun"){
            if (cur_year > 1900){
                sundays_count += 1;
            }
        }

        // Logic of updating days, months and years 
        day_of_month += 1;
        // Update the day
        cur_day = day_to_day[cur_day];
    }


    cout << endl;
    cout << "The number of Sundays on the first of the month are " << sundays_count << endl;
    cout << endl;
    return 0;
}