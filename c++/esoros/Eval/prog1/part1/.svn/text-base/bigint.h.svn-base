 #ifndef BIGINT_H_
 #define BIGINT_H_
 #include <fstream>
 
 /*  Eric Soros
  *  CS 33001
  *  January 23, 2011
  *  Prog1, part1
  */ 
  // This is the implementation for the bigint ADT. 
  const int maxSize = 300; //The maximum number of digits for the BigInt.
  
  class bigint
  {
	public:
		bigint();
		bigint(const char data []);
		bigint(int num);
		void print(std::ostream & out); //prints the bigint out. 80 digits per line. 
    private:
		char digits[maxSize]; //Array to hold the bigint. 
  };
  #endif