//
//  stringGA.h
//  stringGA
//
//  Created by Eric Soros on 10/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef stringGA_stringGA_h
#define stringGA_stringGA_h

#include <string>
#include <vector>

//constants used by the program
const std::string TARGET("Hello, World!");
const int TARGET_LENGTH = (int) TARGET.size();
const int popsize = 100;
const int crossover_rate = 70;
const int mutation_rate = 1;
//basically a wrapper class. Holds a string and it's fitness
typedef struct chromosome
{
    std::string str; 
    int fitness; 
} chromosome;

//functions that the program uses
std::string random_string(int);
int calculate_fitness(const std::string&);
void init_population(std::vector<chromosome>&);
void print_chromosome(const chromosome&);
void crossover(chromosome&, chromosome&);
void mutation(chromosome&);
void make_new_population(std::vector<chromosome>&);
bool compare_to(chromosome, chromosome);
#endif
