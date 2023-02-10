#include "fundamentals_2.hpp"

string calcEmissionZone(double avg) {
    // TODO
    string emissionZone = "";
    if (avg >= 10.0) {
        emissionZone = "RED";
        //cout << "RED" << endl;
    } 
    else if (avg >= 5.0 && avg < 10.0) {
        emissionZone = "ORANGE";
        //cout << "ORANGE" << endl;
    }
    else if (avg < 5.0 && avg >= 2.5) {
        emissionZone = "YELLOW";
        //cout << "YELLOW" << endl;
    }
    else if (avg < 2.5) {
        emissionZone = "GREEN";
        //cout << "GREEN" << endl;
    }
    return emissionZone;
}

void insertEmissionInfo(emissionInfo co2_emissions[], string countryName, double emission_in_2015, double emission_in_2016, double emission_in_2017, double emission_in_2018, double emission_in_2019, int index) {
    // TODO
    co2_emissions[index].countryName = countryName;
    co2_emissions[index].emission_in_2015 = emission_in_2015;
    co2_emissions[index].emission_in_2016 = emission_in_2016;
    co2_emissions[index].emission_in_2017 = emission_in_2017;
    co2_emissions[index].emission_in_2018 = emission_in_2018;
    co2_emissions[index].emission_in_2019 = emission_in_2019;
    co2_emissions[index].average = (emission_in_2015 + emission_in_2016 + emission_in_2017 + emission_in_2018 + emission_in_2019) / 5 ;
    return;
}