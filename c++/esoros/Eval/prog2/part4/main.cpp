 /*  Eric Soros
  *  CS 33001
  *  March 13, 2011
  *  prog2, part4
  */ 
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "String.hpp"
#include "logentry.hpp"
////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    std::vector<String> opt(3);     // options
    opt[0] = "all";
    opt[1] = "bytes";
    opt[2] = "host";

    if (argc == 2) {
        std::cerr << "usage: " << argv[0] << " filename [";
        for (int i = 0; i < int(opt.size()) - 1; ++i)
            std::cerr << opt[i] << " | ";
	 std::cerr << opt[opt.size() - 1] << " ]\n";
	 exit(1);
    }

    if (argc < 2) {
        std::cerr << "Error: command line file name required, exiting."
        << std::endl;
        exit(1);
    }
    
    std::ifstream in(argv[1]);
    std::vector<logEntry> logEntries = parse(in);
    in.close();

    String option(argv[2]);

    if (option == opt[0]) {              //First option
        outputAll(std::cout, logEntries);
    }
    else if (option == opt[1]) {        //Second option
        std::cout << "Total number of bytes sent: " 
                  << byteCount(logEntries) << std::endl;
    }
    else if (option == opt[2]) {        //Thrid option
        byHost(std::cout, logEntries);
    }
    else    {                           //Error, bad option
        std::cerr << "Unrecognized option: " << option << std::endl;
        std::cerr << "Options: ";
        for (int i = 0; i < int(opt.size()) - 1; ++i)
            std::cerr << opt[i] << ", ";
        std::cerr << opt[opt.size() - 1] << std::endl;
    }
    return 0;
}


