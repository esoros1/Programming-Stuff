 #ifndef BIGINT_H_
 #define BIGINT_H_
 #include <fstream>
 
 /*  Eric Soros
  *  CS 33001
  *  February 13, 2011
  *  Prog1, part4
  */ 
  // This is the implementation for the bigint ADT. 
  //The bigint is an array, witih the numbers stored backwards. The terminating digit is -1.
  const int maxSize =1000; //The maximum number of digits for the BigInt.
  
  class bigint
  {
	public:
		bigint();
		bigint(const char num []);
		bigint(int num); 
		friend std::istream& operator>> (std::istream&, bigint &);
		friend std::ostream& operator<< (std::ostream&, const bigint&);
		friend bigint operator+ (int, const bigint &);
		bigint shift_left (int) const;//multiples bigint by 10^n
		friend void u_test(bigint); //test the constructor. Pass in default constructor. 
		int operator[] (int) const; //accesor
		bigint operator+ (const bigint &) const; //adds twwo bigints. 
		bigint operator+ (int) const;//adds a bigint and a digit 0-9.
		bigint operator* (int) const; //scalar multiplication
		bigint operator* (const bigint &) const; //multiply 2 bigints
		int num_trail_zeroes() const; //finds number of trialing zeroes.
		int length() const; //returns the number of digits.
	private:
		int digits[maxSize+1]; //Array to hold the bigint. plus 1 for maxSize chars + a terminating digit.
  };
	bigint operator* (int, const bigint &);
	bigint factorial (int);
  #endif
