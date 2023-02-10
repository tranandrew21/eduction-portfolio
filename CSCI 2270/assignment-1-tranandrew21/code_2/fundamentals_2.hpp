#ifndef READFILE2_H__
#define READFILE2_H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct emissionInfo { 
    string countryName; 
    double emission_in_2015;
    double emission_in_2016; 
    double emission_in_2017;
    double emission_in_2018;
    double emission_in_2019;
    double average; 
};

// TODO add detailed explanation on what the function should do
// This function will initiate a local struct and store various types of information within it, the average of all emissions from 2015 - 2019 will also be calculated and stored in the struct
void insertEmissionInfo(emissionInfo co2_emissions[], string countryName, double emission_in_2015, double emission_in_2016, double emission_in_2017, double emission_in_2018, double emission_in_2019, int length); 

string calcEmissionZone(double average);


#endif // READFILE2_H__