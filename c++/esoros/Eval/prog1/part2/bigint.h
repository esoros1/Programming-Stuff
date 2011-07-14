 #ifndef BIGINT_H_
 #define BIGINT_H_
 #include <fstream>
 
 /*  Eric Soros
  *  CS 33001
  *  January 30, 2011
  *  Prog1, part2
  */ 
  // This is the implementation for the bigint ADT. 
  //The bigint is an array, witih the numbers stored backwords. The terminating digit is -1.
  const int maxSize = 250; //The maximum number of digits for the BigInt.
  
  class bigint
  {
	public:
		bigint();
		bigint(const char num []);
		bigint(int num);
		void print(std::ostream & out); //prints the bigint out. 80 digits per line. 
		friend void u_test(bigint); //test the constructor. Pass in default constructor. 
		int length(); //returns the number of digits.
	private:
		int digits[maxSize+1]; //Array to hold the bigint. plus 1 for maxSize chars + a terminating digit.
  };
  #endif