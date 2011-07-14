 /*  Eric Soros
  *  CS 33001
  *  March 13, 2011
  *  prog2, part4
  */ 
#include "logentry.hpp"
#include "String.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
//IMPLEMENTATIONS FOR THE DATE CLASS
//Constructor for the Date Class
Date::Date(String t_day,String t_month, String t_year)
{
	day =  t_day;
	month = t_month;
	year = t_year;
}
//Test the Date constructors, pass in default constructor;
void Date_utest(const Date& test)
{
	assert(test.year.length() == 0 && test.month.length() == 0 && test.day.length() == 0);
	Date x(String("01"),String("Jan"),String("1992"));
	assert(x.year == "1992");
	assert(x.month == "Jan");
	assert(x.day == "01");
	std::cout << x << std::endl;
}
//print the current state of the Date
//month/day/year
std::ostream& operator<<(std::ostream& out, const Date& rhs)
{
	//f it is not blank, than print it out
	if (rhs.month.length() != 0)
	out << rhs.month<<"/"<<rhs.day<<"/"<<rhs.year;
	else out <<"This is a blank date";
	return out;
}
/////////////////////////////////////////////////////////////////////////////////

//IMPLEMENTAION FOR THE TIME CLASS
//Constructor for the time class
Time::Time(int t_hour, int t_minute, int t_second)
{
	hour = t_hour;
	minute = t_minute;
	second = t_second;
}
//Test the Time constructors, pass in default constructor
void Time_utest(const Time& test)
{
	assert(test.hour == 0 && test.minute == 0 && test.second == 0);
	Time x(12,01,01);
	assert(x.hour == 12 && x.minute == 01 && x.second == 01);
	std::cout << x << std::endl;
	std::cout << test << std::endl;
}
//print the current state of Time
//hour:minute:second
std::ostream& operator<<(std::ostream& out, const Time& rhs)
{
	//the variables are ints, and we need it to print 01:01:01.
	if (rhs.hour < 10) out <<"0";
	out << rhs.hour << ":";
	if (rhs.minute < 10) out <<"0";
	out << rhs.minute << ":";
	if (rhs.second < 10) out <<"0";
	out << rhs.second;
	
	return out;
}
/////////////////////////////////////////////////////////////////////////////////

//IMPLEMENTATION FOR THE LOGENTRY CLASS
int logEntry::getBytes() const
{
	return numBytes;
}
String logEntry::getHost() const
{
	return host;
}
//test constructors for the Date, time, and log classes
void Log_utest(const logEntry& test)
{
	assert(test.numBytes == 0);
	std::cout << test << std::endl;
}
//Pre: Takes a istream
//Post: returns a vector of logEntry files
// if strings.size() == 10, then a valid logentry is stored
std::vector<logEntry> parse(std::istream& in)
{
 	std::vector<logEntry> result;
 	while(!in.eof())
 	{
		String line;
		line.resize(512);
		getLine(in,line);
		logEntry entry(line);
		if (!in.eof())
		result.push_back(entry);
	}
	return result;
}
//Constructor for the log entry.
//Pass in line for further processing.
logEntry::logEntry(const String& line)
{
	std::vector<String> strings = line.split(' ');
	//for (int i = 0;i<strings.size();i++)
	//std::cout << strings[i] << std::endl;
	//if there are not 10 strings, return a blank (default) logEntry
	if (strings.size() != 10) 
    {
    	numBytes = 0;
    	return;
    }
    
    request = strings[6];
    host = strings[0];
    status = strings[8];
    //make sure we actually have any bytes to add
    if (strings[9] == "-") numBytes = 0;
    else numBytes = stringToInt(strings[9]);
    
    //Extraxt the day, month and year and send it to the Constructor
    String full_date = strings[3].substr(1,11);
    date = Date(full_date.substr(0,1),full_date.substr(3,5),full_date.substr(7,10));
    //Extract the time as a string, then convert to Int for constructor
    String full_time = strings[3].substr(13,20);    
    time = Time(stringToInt(full_time.substr(0,1)),stringToInt(full_time.substr(3,4)),stringToInt(full_time.substr(6,7 )));


}
//print the current state of the log entry
std::ostream& operator<<(std::ostream& out, const logEntry& rhs)
{
	out << rhs.host <<'\t'<<rhs.date<<' '<<rhs.time<< ' ';
	//formatting stuff
	out.width(75);
	out << std::left << rhs.request<< "\t" << rhs.status<<' '<<rhs.numBytes;
	return out;
}
//PRE: number is a numerical String
//POST: Returns an int representation of the String
int stringToInt(const String& number)
{
	int result = 0;
	int shift = 1;
	for (int i = number.length()-1;i >= 0; i--)
	{
		result += (number[i] - int('0'))*shift;
		//we need to shift the numbers over. same as 10^i
		shift = shift * 10;
	}
	return result;
}
//Pre: Takes a vector of logEntries.
//Post: returns the number of byes.
int byteCount(const std::vector<logEntry>& logs) 
{
	int result = 0;
	for (int i = 0; i < logs.size(); ++i)
	result  = result + logs[i].getBytes();
	return result;
}
//Outputs all of the logEntries
void outputAll(std::ostream& out, const std::vector<logEntry>& logs)
{
	for(int i = 0; i < logs.size(); ++i)
	out << logs[i] << std::endl;
}

void byHost(std::ostream& out, const std::vector<logEntry>& logs)
{
	for(int i = 0; i < logs.size(); ++i)
	out << logs[i].getHost() << std::endl;
}
