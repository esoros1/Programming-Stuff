//
//  stringGA.cpp
//  stringGA
//
//  Created by Eric Soros on 10/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#include "stringGA.h"

//used for sorting purposes
bool compare_to(chromosome lhs, chromosome rhs)
{
    return lhs.fitness <= rhs.fitness;
}

//make a random string of size n
std::string random_string(int n)
{
    std::string result(TARGET_LENGTH,' ');
    
    //I'm only going to use printable ASCII characters
    //which go from 32 to 126
    for(int i = 0; i < n; ++i)
    {
        char rand_char = (rand() % 94) + 32;
        result[i] = rand_char;
    }
    return result; 
}

//calculate the fitness of the string. Just subtract the value at 
//current position with the value of the target string. we want a 
//lower fitness
int calculate_fitness(const std::string& str)
{
    int result = 0;
    for(int i = 0; i < TARGET_LENGTH; ++i)
        result += abs(str[i] - TARGET[i]);
    
    return result;
}

//initialize the population to POPSIZE with random strings and 
//calculate their fitness. population must be empty!
void init_population(std::vector<chromosome>& population)
{
    for(int i = 0; i < popsize; ++i)
    {
        chromosome temp;
        temp.str = random_string(TARGET_LENGTH);
        temp.fitness = calculate_fitness(temp.str);
        
        population.push_back(temp);
    }
}

//print out the chromosome. Basically just for testing
void print_chromosome(const chromosome& c)
{
    std::cout << c.str << "----------------->" << c.fitness << std::endl;
}

//Crossover the two chromosomes at a random point on the strings
//Depends on the crossover rate. 
void crossover(chromosome& rhs, chromosome& lhs)
{
    int rand_num = (rand() % 99) + 1;
    
    //if we crossover depends on the crossover rate
    if(rand_num <= crossover_rate)
    {
        //pick a random place to switch the strings on
        int rand_index = rand() % (TARGET_LENGTH - 1);
        for(int i = rand_index; i < TARGET_LENGTH; ++i)
        {
            //swap the chars. 
            char temp = rhs.str[i];
            rhs.str[i] = lhs.str[i];
            lhs.str[i] = temp;
        }
        
    }
    
}

//mutation is hard, because we can't just flip the bits. Therefore,
//we will just assign a random string instead. This should happen
//a really smally amount of the time, like .01 percent
void mutation(chromosome& c)
{
    int rand_num = (rand() % 999) +1;
    
    if (rand_num <= mutation_rate)
        c.str = random_string(TARGET_LENGTH);
}

//make a new generation.
//First, we add the two best to the next generation. After that ,
//we go through and crossover and mutate until we have enough
//for a new population
//FOR THIS TO WORK, THE POPULATION MUST BE SORTED
void make_new_population(std::vector<chromosome>& old_generation)
{
    std::vector<chromosome> new_generation;
     
    //add the two best from the old generation to the new one
    new_generation.push_back(old_generation[0]);
    new_generation.push_back(old_generation[1]);
    
    //go through the rest, adding crossovers and mutations
    for(int i = 2; i < old_generation.size(); i+=2)
    {
        chromosome temp1 = old_generation[i];
        chromosome temp2 = old_generation[i+1];
        
        crossover(temp1, temp2);
        mutation(temp1);
        mutation(temp2);
        //calculate the fitness for the new strings. 
        temp1.fitness = calculate_fitness(temp1.str);
        temp2.fitness = calculate_fitness(temp2.str);
        
        new_generation.push_back(temp1);
        new_generation.push_back(temp2);
    }
    //swap old_generation and new_generation
    //the destructor will take care of deleting the old stuff
    swap(old_generation,new_generation);
    //sort for the next time we make a new generation.
    sort(old_generation.begin(), old_generation.end(), compare_to);

}

