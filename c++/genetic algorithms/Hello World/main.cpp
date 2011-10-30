//
//  main.cpp
//  stringGA
//
//  Created by Eric Soros on 10/25/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#define POPSIZE 100

#include <iostream>
#include <string> 
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include "stringGA.h"

using std::string;

int main (int argc, const char * argv[])
{

    srand(unsigned(time(NULL)));

    std::vector<chromosome> population;
    init_population(population);
    
    //sort for the initial make_new_population
    sort(population.begin(),population.end(),compare_to);
    
    bool found = false; 
    int i = 0;
    while (!found)
    {
        make_new_population(population);
        std::cout << "Best of Generation " << i++ << "\n";
        print_chromosome(population[0]);
        
        found = population[0].str == TARGET;
    }
    
    
    return 0;
}


