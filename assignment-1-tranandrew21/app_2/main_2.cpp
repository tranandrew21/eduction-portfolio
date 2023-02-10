#include <iostream>
#include <fstream>
#include "../code_2/fundamentals_2.hpp"
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream fin;
    fin.open(argv[1]);
    ofstream fout;
    fout.open(argv[2]);

    double lowerBound = stod(argv[3]);
    double upperBound = stod(argv[4]);
    
    emissionInfo co2_emissions[500];
    int index = 0;

    string line;
    string word;

    string countryName;
    double in2015, in2016, in2017, in2018, in2019;
    
    if (fin.is_open()) {
        while(getline(fin, line)) {
            stringstream ss(line);
            for(int i = 0; i < 6; i++) {
                getline(ss, word, ',');
                if (i == 0) {
                    countryName = word;
                }
                else if (i == 1) {
                    in2015 = stod(word);
                }
                else if (i == 2) {
                    in2016 = stod(word);
                }
                else if (i == 3) {
                    in2017 = stod(word);
                }
                else if (i == 4) {
                    in2018 = stod(word);
                }
                else if (i == 5) {
                    in2019 = stod(word);
                }
            }
            insertEmissionInfo(co2_emissions, countryName, in2015, in2016, in2017, in2018, in2019, index);
            index++;
        }
        
    }
    if (fout.is_open()) {
        for(int i = 0; i < index; i++) {
            string emissionZone = calcEmissionZone(co2_emissions[i].average);
            if (co2_emissions[i].average >= lowerBound && co2_emissions[i].average <= upperBound) {
                fout << co2_emissions[i].countryName << "," << co2_emissions[i].average << "," << emissionZone << "\n";
                cout << co2_emissions[i].countryName << "," << co2_emissions[i].average << "," << emissionZone << "\n";
            }
        }
    }
    
    fin.close();
    fout.close();
}