#ifndef CALC_H
#define CALC_H

//functions that are used in the calculator program
int getline(char [],int);
double atof(char []);
int atoi(char []);
char * itoa(double);

//get next operator
#define NUMBER '0'
double getNextOperator(char []);

//infix to postfix
char * infixToPostfix(char *);
int isHigherPrecedence(char,char);
double eval(char *);

#endif
