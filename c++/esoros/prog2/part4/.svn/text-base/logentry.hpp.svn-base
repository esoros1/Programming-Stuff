 /*  Eric Soros
  *  CS 33001
  *  March 13, 2011
  *  prog2, part4
  */ 
#ifndef INCLUDE_LOGENTRY_HPP_
#define INCLUDE_LOGENTRY_HPP_

#include <vector>
#include <fstream>
#include <iostream>
#include "String.hpp" 

class Date { 
  public:
            Date() {};
        	//Day, Month, Year
        	Date(String,String,String);
		    //test the date constructors, pass in default constructor
		    friend void Date_utest(const Date&);
		    //print the date month/day/year
		    friend std::ostream& operator<<(std::ostream&, const Date&);
  private:
    String  day, month, year;
};

class Time {
  public:
            Time(): hour(0),minute(0),second(0) {};
			//hour,minute,second
			Time(int, int, int);
			//test the time constructor, pass in deafult constructor
			friend void Time_utest(const Time&);
			//print the time: hour::minute::second
			friend std::ostream& operator<<(std::ostream&, const Time&);
  private:
    int	    hour, minute, second;
};


class logEntry {
  public:
            logEntry(): numBytes(0) {}; 
            //pass in the line to do further processing with. 
            logEntry(const String&);
			
			int getBytes() const;
			String getHost() const;
			
    		//test the logentry constructors
    		friend void Log_utest(const logEntry&);
  			friend std::ostream& operator<< (std::ostream&, const logEntry&);
  private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int	    numBytes;
};


//
// Free functions
//

std::vector<logEntry>  parse      (std::istream&);
int                    byteCount  (const std::vector<logEntry>&);
void                   outputAll  (std::ostream&, const std::vector<logEntry>&);
void                   byHost     (std::ostream&, const std::vector<logEntry>&); 
int                    stringToInt(const String&);//Turns string into int


#endif
