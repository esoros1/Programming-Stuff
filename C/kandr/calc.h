#ifndef CALC_H
#define CALC_H

//functions that are used in the calculator program
double atof(char []);
int atoi(char []);
int getline(char [],int);

//stuff for the stack
void push(double);
double pop();

//get next operator
#define NUMBER '0'
double getNextOperator(char []);

#endif
