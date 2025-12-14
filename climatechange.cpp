#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>

using namespace std;

// Struct to hold typhoon data
struct Typhoon {
    string name;
    string arrival; // Format: military time_MM/DD
    string departure; // Format: military time_MM/DD
    string month;
    string interval;
    string stormCrossing;
    string timeOfLandfall;
    string developed;
    string pathType;
    string levels;
    int windSpeed;
    int casualties;
    double damages; // in Peso
    string placesAffected;
};

vector<Typhoon> loadTyphoons(int year);
vector<Typhoon> getTyphoonsForMonth(const vector<Typhoon>& typhoons, int month);
void displayTyphoons(const vector<Typhoon>& typhoons);
void displayResolutions(int year);
void searchTop3Strongest(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025);
void searchMostDamaging(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025);
void searchAlphabetical(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025);
void searchLongestStay(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025);
void searchLandfall(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025);

// Function to convert month name to int
int getMonthInt(const string& monthStr) {
    static const map<string, int> monthMap = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6},
        {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };
    auto it = monthMap.find(monthStr);
    return it != monthMap.end() ? it->second : 0;
}

// Function to parse month from arrival/departure date (MM/DD), with error handling
int getMonth(const string& date) {
    size_t pos = date.find('_');
    if (pos != string::npos) {
        string mmdd = date.substr(pos + 1);
        size_t slash = mmdd.find('/');
        if (slash != string::npos) {
            try {
                int month = stoi(mmdd.substr(0, slash));
                if (month >= 1 && month <= 12) return month;
            } catch (...) {
                return 0; // Invalid
            }
        }
    }
    return 0; // Invalid
}

// Function to load typhoons from hardcoded data
vector<Typhoon> loadTyphoons(int year) {
    vector<Typhoon> typhoons;
    if (year == 2024) {
        // Aghon
        Typhoon t1;
        t1.name = "Aghon";
        t1.arrival = "2000_05/23";
        t1.departure = "1200_05/29";
        t1.month = "May";
        t1.interval = "6";
        t1.stormCrossing = "Land";
        t1.timeOfLandfall = "5/24/2024 23:20:00";
        t1.developed = "WITHIN THE PAR";
        t1.pathType = "East to Northeast";
        t1.levels = "Tropical Depression";
        t1.windSpeed = 140;
        t1.casualties = 6;
        t1.damages = 1030000000.0;
        t1.placesAffected = "Region III | Aurora | Zambales | Pampanga | Bulacan | Nueva Ecija | Tarlac | Region V | Camarines Sur | Camarines Norte | Albay | Sorsogon | Masbate | Catanduanes | Region VI | Iloilo | Guimaras | Capiz | Aklan | Antique | Negros Occidental | Region VII | Cebu | Bohol | Negros Oriental | Siquijor | Region VIII | Northern Samar | Eastern Samar | Samar | Leyte | Southern Leyte | Biliran";
        typhoons.push_back(t1);

        // Butchoy
        Typhoon t2;
        t2.name = "Butchoy";
        t2.arrival = "0800_07/19";
        t2.departure = "0700_07/20";
        t2.month = "July";
        t2.interval = "1";
        t2.stormCrossing = "Land";
        t2.timeOfLandfall = "2024-07-18 10:00";
        t2.developed = "WITHIN THE PAR";
        t2.pathType = "Southwestward";
        t2.levels = "Tropical Depression";
        t2.windSpeed = 55;
        t2.casualties = 0;
        t2.damages = 0.0;
        t2.placesAffected = "Region III | Aurora | Zambales | Pampanga | Bulacan | Nueva Ecija | Tarlac | Region IV-A | Quezon | Rizal | Cavite | Laguna | Batangas | Region IV-B | Palawan | Occidental Mindoro | Oriental Mindoro | Romblon | Marinduque | Region V | Camarines Sur | Camarines Norte | Albay | Sorsogon | Masbate | Catanduanes | Region VI | Iloilo | Guimaras | Capiz | Aklan | Antique | Negros Occidental";
        typhoons.push_back(t2);

        // Carina
        Typhoon t3;
        t3.name = "Carina";
        t3.arrival = "2000_07/19";
        t3.departure = "0800_07/24";
        t3.month = "July";
        t3.interval = "5";
        t3.stormCrossing = "Water";
        t3.timeOfLandfall = "2024-07-19 4:00";
        t3.developed = "WITHIN THE PAR";
        t3.pathType = "Northwestard";
        t3.levels = "Super Typhoon";
        t3.windSpeed = 185;
        t3.casualties = 48;
        t3.damages = 10400000000.0;
        t3.placesAffected = "Region II | Isabela | Cagayan | Quirino | Nueva Vizcaya | Region III | Aurora | Zambales | Pampanga | Bulacan | Nueva Ecija | Tarlac | Region IV-A | Quezon | Rizal | Cavite | Laguna | Batangas | Region IV-B | Palawan | Occidental Mindoro | Oriental Mindoro | Romblon | Marinduque | Region V | Camarines Sur | Camarines Norte | Albay | Sorsogon | Masbate | Catanduanes | Region VI | Iloilo | Guimaras | Capiz | Aklan | Antique | Negros Occidental | Region VII | Cebu | Bohol | Negros Oriental | Siquijor | Region VIII | Northern Samar | Eastern Samar | Samar | Leyte | Southern Leyte | Biliran";
        typhoons.push_back(t3);

        // Dindo
        Typhoon t4;
        t4.name = "Dindo";
        t4.arrival = "0800_08/18";
        t4.departure = "0700_08/19";
        t4.month = "August";
        t4.interval = "1";
        t4.stormCrossing = "Water";
        t4.timeOfLandfall = "2024-08-18 2:00";
        t4.developed = "WITHIN THE PAR";
        t4.pathType = "Westward";
        t4.levels = "Tropical Storm";
        t4.windSpeed = 65;
        t4.casualties = 0;
        t4.damages = 0.0;
        t4.placesAffected = "Region V | Camarines Sur | Camarines Norte | Albay | Sorsogon | Masbate | Catanduanes | Region VI | Iloilo | Guimaras | Capiz | Aklan | Antique | Negros Occidental | Region VII | Cebu | Bohol | Negros Oriental | Siquijor";
        typhoons.push_back(t4);

        // Enteng
        Typhoon t5;
        t5.name = "Enteng";
        t5.arrival = "2300_09/01";
        t5.departure = "2000_09/04";
        t5.month = "September";
        t5.interval = "3";
        t5.stormCrossing = "Land";
        t5.timeOfLandfall = "2024-09-02 14:00";
        t5.developed = "OUTSIDE THE PAR";
        t5.pathType = "Northwestward";
        t5.levels = "Tropical Storm";
        t5.windSpeed = 88;
        t5.casualties = 21;
        t5.damages = 2600000000.0;
                t5.placesAffected = "Region III | Aurora | Zambales | Pampanga | Bulacan | Nueva Ecija | Tarlac | Region IV-A | Quezon | Rizal | Cavite | Laguna | Batangas | Region IV-B | Palawan | Occidental Mindoro | Oriental Mindoro | Romblon | Marinduque | Region V | Camarines Sur | Camarines Norte | Albay | Sorsogon | Masbate | Catanduanes | Region VI | Iloilo | Guimaras | Capiz | Aklan | Antique | Negros Occidental | Region VII | Cebu | Bohol | Negros Oriental | Siquijor | Region VIII | Northern Samar | Eastern Samar | Samar | Leyte | Southern Leyte | Biliran";
        typhoons.push_back(t5);

        // Ferdie
        Typhoon t6;
        t6.name = "Ferdie";
        t6.arrival = "1600_09/13";
        t6.departure = "0200_09/14";
        t6.month = "September";
        t6.interval = "1";
        t6.stormCrossing = "Water";
        t6.timeOfLandfall = "2024-09-13 10:00";
        t6.developed = "OUTSIDE THE PAR";
        t6.pathType = "Northwestward-Northward";
        t6.levels = "Tropical Storm";
        t6.windSpeed = 85;
        t6.casualties = 20;
        t6.damages = 1900000000.0;
        t6.placesAffected = "Region IV-B | Occidental Mindoro | Oriental Mindoro | Palawan | Romblon | Region V | Camarines Sur | Albay | Sorsogon | Masbate | Region VI | Negros Occidental | Antique | Capiz | Aklan | Iloilo | Guimaras | Region VII | Cebu | Bohol | Negros Oriental | Region IX | Zamboanga del Sur | Zamboanga del Norte | Zamboanga Sibugay | BARMM | Lanao del Sur | Maguindanao del Norte | Maguindanao del Sur | Region X | Misamis Oriental | Misamis Occidental | Lanao del Norte | Region XI | Davao del Sur | Davao del Norte";
        typhoons.push_back(t6);

        // Gener
        Typhoon t7;
        t7.name = "Gener";
        t7.arrival = "0800_09/16";
        t7.departure = "0200_09/18";
        t7.month = "September";
        t7.interval = "2";
        t7.stormCrossing = "Land";
        t7.timeOfLandfall = "2024-09-17 0:00";
        t7.developed = "WITHIN THE PAR";
        t7.pathType = "West-Northwestward";
        t7.levels = "Tropical Depresion";
        t7.windSpeed = 55;
        t7.casualties = 20;
        t7.damages = 1121000000.0;
        t7.placesAffected = "Region I | Ilocos Sur | Ilocos Norte | La Union | Pangasinan | Region II | Isabela | Cagayan | Quirino | Nueva Vizcaya | Region III | Zambales | Bataan | Tarlac | Nueva Ecija | Pampanga | Bulacan | Aurora | CAR | Ifugao | Mountain Province | Kalinga | Apayao | Benguet";
        typhoons.push_back(t7);

        // Helen
        Typhoon t8;
        t8.name = "Helen";
        t8.arrival = "1830_09/17";
        t8.departure = "1700_09/18";
        t8.month = "September";
        t8.interval = "1";
        t8.stormCrossing = "Water";
        t8.timeOfLandfall = "2024-09-17 18:30";
        t8.developed = "OUTSIDE THE PAR";
        t8.pathType = "West-Northwestward";
        t8.levels = "Tropical Storm";
        t8.windSpeed = 85;
        t8.casualties = 20;
        t8.damages = 1121000000.0;
        t8.placesAffected = "Region IV-A | Rizal | Quezon | Laguna | Cavite | Batangas | Region IV-B | Occidental Mindoro | Oriental Mindoro | Palawan | Romblon | Region V | Camarines Sur | Albay | Sorsogon | Masbate | Catanduanes | Region VI | Negros Occidental | Antique | Iloilo | Aklan | Capiz | Guimaras | Region VII | Cebu | Bohol | Negros Oriental | Siquijor | Region IX | Zamboanga del Sur | Zamboanga del Norte | Zamboanga Sibugay | BARMM | Lanao del Sur | Maguindanao del Norte | Maguindanao del Sur";
        typhoons.push_back(t8);

        // Igme
        Typhoon t9;
        t9.name = "Igme";
        t9.arrival = "0000_09/20";
        t9.departure = "0400_09/21";
        t9.month = "September";
        t9.interval = "1";
        t9.stormCrossing = "Water";
        t9.timeOfLandfall = "2024-09-20 5:00";
        t9.developed = "OUTSIDE THE PAR";
        t9.pathType = "West-Southwestward";
        t9.levels = "Tropical Depression";
        t9.windSpeed = 55;
        t9.casualties = 48;
        t9.damages = 4100000000.0;
        t9.placesAffected = "Region IV-A | Rizal | Quezon | Laguna | Cavite | Batangas | Region IV-B | Occidental Mindoro | Oriental Mindoro | Palawan | Romblon | Region V | Camarines Sur | Albay | Sorsogon | Masbate | Catanduanes | Region VI | Negros Occidental | Antique | Iloilo | Aklan | Capiz | Guimaras | Region VII | Cebu | Bohol | Negros Oriental | Siquijor | Region IX | Zamboanga del Sur | Zamboanga del Norte | Zamboanga Sibugay | BARMM | Lanao del Sur | Maguindanao del Norte | Maguindanao del Sur";
        typhoons.push_back(t9);

        // Julian
        Typhoon t10;
        t10.name = "Julian";
        t10.arrival = "0800_10/01";
        t10.departure = "0500_10/04";
        t10.month = "October";
        t10.interval = "3";
        t10.stormCrossing = "Water";
        t10.timeOfLandfall = "2024-10-24 12:30";
        t10.developed = "OUTSIDE THE PAR";
        t10.pathType = "West-Northwestward";
        t10.levels = "Super Typhoon";
        t10.windSpeed = 195;
        t10.casualties = 5;
        t10.damages = 1570000000.0;
        t10.placesAffected = "Region I | Ilocos Sur | Ilocos Norte | La Union | Pangasinan | Region II | Isabela | Cagayan | Quirino | Nueva Vizcaya | Region III | Zambales | Bataan | Tarlac | Nueva Ecija | Pampanga | Bulacan | Aurora | CAR | Ifugao | Mountain Province | Kalinga | Apayao | Benguet";
        typhoons.push_back(t10);

        // Kristine
        Typhoon t11;
        t11.name = "Kristine";
        t11.arrival = "0000_10/21";
        t11.departure = "0300_10/25";
        t11.month = "October";
        t11.interval = "4";
        t11.stormCrossing = "Land";
        t11.timeOfLandfall = "2024-10-26 19:30";
        t11.developed = "WITHIN THE PAR";
        t11.pathType = "West-Northwestward";
        t11.levels = "Severe Typhoon Storm";
        t11.windSpeed = 110;
        t11.casualties = 137;
        t11.damages = 7900000.0;
        t11.placesAffected = "Region V | Camarines Sur | Camarines Norte | Albay | Sorsogon | Masbate | Catanduanes | Region II | Cagayan | Isabela | Apayao | Kalinga | Region I | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Benguet | Ifugao | Mountain Province | Abra | Region III | Aurora | Zambales | Pampanga | Bulacan | Nueva Ecija | Tarlac | Region IV-A | Quezon | Rizal | Cavite | Laguna | Batangas | Region IV-B | Palawan | Occidental Mindoro | Oriental Mindoro | Romblon | Marinduque";
        typhoons.push_back(t11);

        // Leon
        Typhoon t12;
        t12.name = "Leon";
        t12.arrival = "1200_10/26";
        t12.departure = "0300_10/31";
        t12.month = "October";
        t12.interval = "5";
        t12.stormCrossing = "Water";
        t12.timeOfLandfall = "2024-11-06 22:00";
        t12.developed = "OUTSIDE THE PAR";
        t12.pathType = "West-Northwestward";
        t12.levels = "Super Typhoon";
        t12.windSpeed = 185;
        t12.casualties = 159;
        t12.damages = 996000000.0;
                t12.placesAffected = "Region I | Ilocos Sur | Ilocos Norte | La Union | Pangasinan | Region II | Isabela | Cagayan | Quirino | Nueva Vizcaya | Region III | Zambales | Bataan | Tarlac | Nueva Ecija | Pampanga | Bulacan | Aurora | CAR | Ifugao | Mountain Province | Kalinga | Apayao | Benguet | Region IV-A | Quezon | Rizal | Cavite | Laguna | Batangas | Region IV-B | Palawan | Occidental Mindoro | Oriental Mindoro | Romblon | Marinduque | Region IX | Zamboanga del Sur | Zamboanga del Norte | Zamboanga Sibugay | BARMM | Lanao";
        typhoons.push_back(t12);

        // Marce
        Typhoon t13;
        t13.name = "Marce";
        t13.arrival = "1800_11/04";
        t13.departure = "1600_11/08";
        t13.month = "November";
        t13.interval = "4";
        t13.stormCrossing = "Land";
        t13.timeOfLandfall = "2024-11-09 20:00";
        t13.developed = "WITHIN THE PAR";
        t13.pathType = "West - Northwestward";
        t13.levels = "Typhoon";
        t13.windSpeed = 120;
        t13.casualties = 20;
        t13.damages = 1900000000.0;
        t13.placesAffected = "Region II | Cagayan | Isabela | Quirino | Nueva Vizcaya | Region III | Aurora | Zambales | Pampanga | Bulacan | Nueva Ecija | Tarlac | Region IV-A | Quezon | Rizal | Cavite | Laguna | Batangas | Region IV-B | Palawan | Occidental Mindoro | Oriental Mindoro | Romblon | Marinduque | Region V | Camarines Sur | Camarines Norte | Albay | Sorsogon | Masbate | Catanduanes | Region VI | Iloilo | Guimaras | Capiz | Aklan | Antique | Negros Occidental | Region VII | Cebu | Bohol | Negros Oriental | Siquijor | Region VIII | Northern Samar | Eastern Samar | Samar | Leyte | Southern Leyte | Biliran";
        typhoons.push_back(t13);

        // Nika
        Typhoon t14;
        t14.name = "Nika";
        t14.arrival = "1800_11/08";
        t14.departure = "1400_11/12";
        t14.month = "November";
        t14.interval = "4";
        t14.stormCrossing = "Land";
        t14.timeOfLandfall = "2024-11-12 14:00";
        t14.developed = "WITHIN THE PAR";
        t14.pathType = "West - Northwestward";
        t14.levels = "Typhoon";
        t14.windSpeed = 130;
        t14.casualties = 20;
        t14.damages = 1121000000.0;
        t14.placesAffected = "Region II | Cagayan | Isabela | Apayao | Kalinga | Region I | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Benguet | Ifugao | Mountain Province | Region III | Aurora | Nueva Vizcaya | Quirino";
        typhoons.push_back(t14);

        // Ofel
        Typhoon t15;
        t15.name = "Ofel";
        t15.arrival = "1800_11/11";
        t15.departure = "1200_11/15";
        t15.month = "November";
        t15.interval = "4";
        t15.stormCrossing = "Land";
        t15.timeOfLandfall = "2024-11-17 16:00";
        t15.developed = "WITHIN THE PAR";
        t15.pathType = "Westward - Northwestward";
        t15.levels = "Super Typhoon";
        t15.windSpeed = 185;
        t15.casualties = 48;
        t15.damages = 10400000000.0;
        t15.placesAffected = "Region II | Cagayan | Isabela | Apayao | Kalinga | Region I | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Benguet | Ifugao | Mountain Province | Abra | Region III | Aurora | Nueva Vizcaya | Quirino";
        typhoons.push_back(t15);

        // Pepito Manaloto
        Typhoon t16;
        t16.name = "Pepito Manaloto";
        t16.arrival = "1200_11/16";
        t16.departure = "0800_11/18";
        t16.month = "November";
        t16.interval = "2";
        t16.stormCrossing = "Land";
        t16.timeOfLandfall = "None";
        t16.developed = "WITHIN THE PAR";
        t16.pathType = "West - Northwestward";
        t16.levels = "Typhoon";
        t16.windSpeed = 150;
        t16.casualties = 20;
        t16.damages = 1900000000.0;
        t16.placesAffected = "Region V | Catanduanes | Camarines Sur | Region III | Aurora | Isabela | Nueva Ecija | CAR | Benguet | Ifugao | Mountain Province";
        typhoons.push_back(t16);

        // Querubin
        Typhoon t17;
        t17.name = "Querubin";
        t17.arrival = "0000_12/24";
        t17.departure = "0000_12/25";
        t17.month = "December";
        t17.interval = "1";
        t17.stormCrossing = "Water";
        t17.timeOfLandfall = "None";
        t17.developed = "OUTSIDE THE PAR";
        t17.pathType = "East - Northwestward";
        t17.levels = "Tropical Depression";
        t17.windSpeed = 55;
        t17.casualties = 0;
        t17.damages = 0.0;
        t17.placesAffected = "Region V | Albay | Sorsogon | Camarines Sur | Region VIII | Leyte | Southern Leyte";
        typhoons.push_back(t17);
    } 
    else if (year == 2025) {
        // Auring
        Typhoon t1;
        t1.name = "Auring";
        t1.arrival = "1520_07/12";
        t1.departure = "0000_07/13";
        t1.month = "July";
        t1.interval = "1";
        t1.stormCrossing = "Water";
        t1.timeOfLandfall = "None";
        t1.developed = "Within the PAR";
        t1.pathType = "North-Northwest";
        t1.levels = "Tropical Depression";
        t1.windSpeed = 140;
        t1.casualties = 3;
                t1.damages = 50000.0;
        t1.placesAffected = "Region II | Cagayan Valley | Batanes | Babuyan Islands | CAR | Cordillera Administrative Region | Region I | Ilocos Region";
        typhoons.push_back(t1);

        // Bising
        Typhoon t2;
        t2.name = "Bising";
        t2.arrival = "1100_07/04";
        t2.departure = "0500_07/07";
        t2.month = "July";
        t2.interval = "3";
        t2.stormCrossing = "Water";
        t2.timeOfLandfall = "None";
        t2.developed = "Within the PAR";
        t2.pathType = "North-Northeastward";
        t2.levels = "Typhoon";
        t2.windSpeed = 140;
        t2.casualties = 3;
        t2.damages = 12400000.0;
        t2.placesAffected = "Region I | Ilocos Region | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Cordillera Administrative Region | Apayao | Kalinga | Mountain Province | Ifugao | Benguet | Region II | Cagayan Valley | Cagayan | Isabela | Nueva Vizcaya | Quirino | Region III | Central Luzon | Bataan | Zambales | Aurora | Northern Nueva Ecija";
        typhoons.push_back(t2);

        // Crisig
        Typhoon t3;
        t3.name = "Crisig";
        t3.arrival = "0800_07/16";
        t3.departure = "1100_07/19";
        t3.month = "July";
        t3.interval = "3";
        t3.stormCrossing = "Land";
        t3.timeOfLandfall = "2025-07-18 8:00";
        t3.developed = "Within the PAR";
        t3.pathType = "West-Northwestward";
        t3.levels = "Tropical Storm";
        t3.windSpeed = 110;
        t3.casualties = 40;
        t3.damages = 19660000000.0;
        t3.placesAffected = "Region II | Cagayan Valley | Cagayan | Isabela | Nueva Vizcaya | Quirino | Region I | Ilocos Region | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Cordillera Administrative Region | Apayao | Kalinga | Mountain Province | Ifugao | Benguet | Region III | Central Luzon | Aurora | Northern Nueva Ecija | Region V | Bicol Region | Camarines Norte | Region IV-A | CALABARZON | Northern Quezon | Polillo Islands | MIMAROPA | Mindoro | Marinduque | Romblon | Palawan | Occidental Mindoro | Oriental Mindoro | NCR | Metro Manila | Region VI | Western Visayas | Antique | Aklan | Iloilo";
        typhoons.push_back(t3);

        // Dante
        Typhoon t4;
        t4.name = "Dante";
        t4.arrival = "0500_07/22";
        t4.departure = "0300_07/24";
        t4.month = "July";
        t4.interval = "2";
        t4.stormCrossing = "Water";
        t4.timeOfLandfall = "None";
        t4.developed = "Within the PAR";
        t4.pathType = "West-Northwestward";
        t4.levels = "Tropical Depression";
        t4.windSpeed = 90;
        t4.casualties = 10;
        t4.damages = 196700000000.0;
        t4.placesAffected = "Region I | Ilocos Region | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Cordillera Administrative Region | Apayao | Kalinga | Mountain Province | Ifugao | Benguet | Region II | Cagayan Valley | Cagayan | Isabela | Nueva Vizcaya | Quirino | Region III | Central Luzon | Bataan | Zambales | Aurora | Northern Nueva Ecija | Region IV-A | CALABARZON | Northern Quezon | Polillo Islands | Region IV-B | MIMAROPA | Occidental Mindoro | Oriental Mindoro | Marinduque | Romblon | Palawan | Region V | Bicol Region | Albay | Camarines Norte | Camarines Sur | NCR | Metro Manila | Region VI | Western Visayas | Antique | Aklan | Iloilo | Region VII | Central Visayas | Cebu | Bohol | Region IX | Zamboanga Peninsula | Zamboanga del Norte | Zamboanga del Sur | BARMM | Basilan | Sulu | Tawi-Tawi | Region XIII / Caraga | Surigao del Norte | Surigao del Sur | Agusan del Norte";
        typhoons.push_back(t4);

        // Emong
        Typhoon t5;
        t5.name = "Emong";
        t5.arrival = "0300_07/23";
        t5.departure = "0500_07/26";
        t5.month = "July";
        t5.interval = "3";
        t5.stormCrossing = "Land";
        t5.timeOfLandfall = "2025-07-24 10:40";
        t5.developed = "Within the PAR";
        t5.pathType = "West-Southwestward";
        t5.levels = "Typhoon";
        t5.windSpeed = 120;
        t5.casualties = 40;
        t5.damages = 20000000000.0;
        t5.placesAffected = "Region I | Ilocos Region | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Cordillera Administrative Region | Apayao | Kalinga | Mountain Province | Ifugao | Benguet | Region II | Cagayan Valley | Cagayan | Isabela | Nueva Vizcaya | Quirino | Region III | Central Luzon | Bataan | Zambales | Aurora | Northern Nueva Ecija | Region IV-A | CALABARZON | Northern Quezon | Polillo Islands | Region IV-B | MIMAROPA | Occidental Mindoro | Oriental Mindoro | Marinduque | Romblon | Palawan | Region V | Bicol Region | Albay | Camarines Norte | Camarines Sur | NCR | Metro Manila | Region VI | Western Visayas | Antique | Aklan | Iloilo | Region VII | Central Visayas | Cebu | Bohol | Region IX | Zamboanga Peninsula | Zamboanga del Norte | Zamboanga del Sur | BARMM | Basilan | Sulu | Tawi-Tawi | Region XIII / Caraga | Surigao del Norte | Surigao del Sur | Agusan del Norte";
        typhoons.push_back(t5);

        // Fabian
        Typhoon t6;
        t6.name = "Fabian";
        t6.arrival = "1200_08/07";
        t6.departure = "1600_08/13";
        t6.month = "August";
        t6.interval = "1";
        t6.stormCrossing = "Water";
        t6.timeOfLandfall = "";
        t6.developed = "Within the PAR";
        t6.pathType = "West-Northwestward";
        t6.levels = "Tropical Depression";
        t6.windSpeed = 45;
        t6.casualties = 40;
        t6.damages = 20000000000.0;
                t6.placesAffected = "Region I | Ilocos Region | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Cordillera Administrative Region | Apayao | Kalinga | Mountain Province | Ifugao | Benguet | Region II | Cagayan Valley | Cagayan | Isabela | Nueva Vizcaya | Quirino | Region III | Central Luzon | Bataan | Zambales | Aurora | Northern Nueva Ecija | Region IV-A | CALABARZON | Northern Quezon | Polillo Islands | Region IV-B | MIMAROPA | Occidental Mindoro | Oriental Mindoro | Marinduque | Romblon | Palawan | Region V | Bicol Region | Albay | Camarines Norte | Camarines Sur | NCR | Metro Manila | Region VI | Western Visayas | Antique | Aklan | Iloilo | Region VII | Central Visayas | Cebu | Bohol | Region IX | Zamboanga Peninsula | Zamboanga del Norte | Zamboanga del Sur | BARMM | Basilan | Sulu | Tawi-Tawi | Region XIII / Caraga | Surigao del Norte | Surigao del Sur | Agusan del Norte";
        typhoons.push_back(t6);

        // Gorio
        Typhoon t7;
        t7.name = "Gorio";
        t7.arrival = "1120_08/10";
        t7.departure = "0200_08/19";
        t7.month = "August";
        t7.interval = "3";
        t7.stormCrossing = "Water";
        t7.timeOfLandfall = "None";
        t7.developed = "Outside the PAR";
        t7.pathType = "West to West-Northwest";
        t7.levels = "Typhoon";
        t7.windSpeed = 155;
        t7.casualties = 0;
        t7.damages = 45000.0;
        t7.placesAffected = "Region II | Cagayan Valley | Batanes | Babuyan Islands";
        typhoons.push_back(t7);

        // Huaning
        Typhoon t8;
        t8.name = "Huaning";
        t8.arrival = "0200_08/17";
        t8.departure = "0600_08/23";
        t8.month = "August";
        t8.interval = "2";
        t8.stormCrossing = "Water";
        t8.timeOfLandfall = "None";
        t8.developed = "Within the PAR";
        t8.pathType = "Northwest to Northeast";
        t8.levels = "Tropical Depression";
        t8.windSpeed = 70;
        t8.casualties = 0;
        t8.damages = 0.0;
        t8.placesAffected = "No significant areas affected (remained offshore)";
        typhoons.push_back(t8);

        // Isang
        Typhoon t9;
        t9.name = "Isang";
        t9.arrival = "1000_08/22";
        t9.departure = "1800_08/30";
        t9.month = "August";
        t9.interval = "1";
        t9.stormCrossing = "Land";
        t9.timeOfLandfall = "10:00_08/22";
        t9.developed = "Within the PAR";
        t9.pathType = "Northwest to West";
        t9.levels = "Tropical Storm";
        t9.windSpeed = 90;
        t9.casualties = 0;
        t9.damages = 0.0;
        t9.placesAffected = "Region II | Cagayan Valley | Cagayan | Isabela | Nueva Vizcaya | Quirino | Region I | Ilocos Region | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Cordillera Administrative Region | Apayao | Kalinga | Mountain Province | Ifugao | Benguet | Region III | Central Luzon | Aurora | Northern Nueva Ecija | Region V | Bicol Region | Camarines Norte | Region IV-A | CALABARZON | Northern Quezon | Polillo Islands | MIMAROPA | Mindoro | Marinduque | Romblon | Palawan | Occidental Mindoro | Oriental Mindoro | Marinduque | Romblon | NCR | Metro Manila | Region VI | Western Visayas | Antique | Aklan | Iloilo";
        typhoons.push_back(t9);

        // Jacinto
        Typhoon t10;
        t10.name = "Jacinto";
        t10.arrival = "0000_08/28";
        t10.departure = "0400_09/03";
        t10.month = "August";
        t10.interval = "2";
        t10.stormCrossing = "Water";
        t10.timeOfLandfall = "None";
        t10.developed = "WITHIN THE PAR";
        t10.pathType = "West to Northwest";
        t10.levels = "Tropical Depression";
        t10.windSpeed = 45;
        t10.casualties = 0;
        t10.damages = 710000.0;
              t10.placesAffected = "Region I | Ilocos Region | Ilocos Norte | Ilocos Sur | La Union | Pangasinan | CAR | Cordillera Administrative Region | Apayao | Kalinga | Mountain Province | Ifugao | Benguet | Region II | Cagayan Valley | Cagayan | Isabela | Nueva Vizcaya | Quirino | Region III | Central Luzon | Bataan | Zambales | Aurora | Northern Nueva Ecija | Region IV-A | CALABARZON | Northern Quezon | Polillo Islands | Region IV-B | MIMAROPA | Occidental Mindoro | Oriental Mindoro | Marinduque | Romblon | Palawan | Region V | Bicol Region | Albay | Camarines Norte | Camarines Sur | NCR | Metro Manila | Region VI | Western Visayas | Antique | Aklan | Iloilo | Region VII | Central Visayas | Cebu | Bohol | Region IX | Zamboanga Peninsula | Zamboanga del Norte | Zamboanga del Sur | BARMM | Basilan | Sulu | Tawi-Tawi | Region XIII / Caraga | Surigao del Norte | Surigao del Sur | Agusan del Norte";
        typhoons.push_back(t10);

        // Kiko
        Typhoon t11;
        t11.name = "Kiko";
        t11.arrival = "1200_09/02";
        t11.departure = "0000_09/06";
        t11.month = "September";
        t11.interval = "1";
        t11.stormCrossing = "Water";
        t11.timeOfLandfall = "None";
        t11.developed = "WITHIN THE PAR";
        t11.pathType = "East to Northeast";
        t11.levels = "Tropical Storm";
        t11.windSpeed = 85;
        t11.casualties = 0;
        t11.damages = 0.0;
        t11.placesAffected = "Region II | Cagayan Valley | Isabela | Nueva Vizcaya | Quirino | Region III | Central Luzon | Nueva Ecija | Pampanga | Region VI | Western Visayas | Antique | NCR | Metro Manila";
        typhoons.push_back(t11);

        // Lannie
        Typhoon t12;
        t12.name = "Lannie";
        t12.arrival = "1800_09/05";
        t12.departure = "2300_09/17";
        t12.month = "September";
        t12.interval = "1";
        t12.stormCrossing = "Water";
        t12.timeOfLandfall = "None";
        t12.developed = "WITHIN THE PAR";
        t12.pathType = "West to Northwestward";
        t12.levels = "Tropical Depression";
        t12.windSpeed = 55;
        t12.casualties = 0;
        t12.damages = 0.0;
        t12.placesAffected = "Region I | Ilocos Region | Sinait | Ilocos Sur | CAR | Cordillera Administrative Region | Region II | Cagayan Valley | Bayombong | Nueva Ecija | Region III | Zambales | NCR | Metro Manila | Region IV-A / IV-B | CALABARZON | MIMAROPA";
        typhoons.push_back(t12);

        // Mirasol
        Typhoon t13;
        t13.name = "Mirasol";
        t13.arrival = "0000_09/16";
        t13.departure = "0300_09/25";
        t13.month = "September";
        t13.interval = "1";
        t13.stormCrossing = "Land";
        t13.timeOfLandfall = "19:20_09/16";
        t13.developed = "WITHIN THE PAR";
        t13.pathType = "East to Northwest";
        t13.levels = "Tropical Depression";
        t13.windSpeed = 55;
        t13.casualties = 1;
        t13.damages = 0.0;
        t13.placesAffected = "Region I | Baler, Aurora | Casiguran, Aurora | Baguio City | Batac, Ilocos Norte | Region II | Bayombong, Nueva Vizcaya | Basco, Batanes | Calayan, Cagayan | Region III | Iba, Zambales | Region IV-A | Baybay City, Leyte | Infanta, Quezon | CAR | La Trinidad, Benguet | Region VIII | Eastern Visayas | Northern Samar | Eastern Samar";
        typhoons.push_back(t13);

        // Nando
        Typhoon t14;
        t14.name = "Nando";
        t14.arrival = "2000_09/18";
        t14.departure = "0000_09/24";
        t14.month = "September";
        t14.interval = "6";
        t14.stormCrossing = "Land";
        t14.timeOfLandfall = "2025-09-22 3:00";
        t14.developed = "WITHIN THE PAR";
        t14.pathType = "West-northwestward";
        t14.levels = "Super Typhoon";
        t14.windSpeed = 215;
        t14.casualties = 200;
        t14.damages = 0.0;
        t14.placesAffected = "Region I | Batanes (Basco, Sabtang, Itbayat) | Cagayan (Calayan, Aparri, Tuguegarao) | Ilocos Norte (Batac, Laoag) | Ilocos Sur (Vigan, Candon) | La Union (San Fernando) | Region II | Nueva Vizcaya (Bayombong) | Isabela (Ilagan, Santiago) | Quirino (Diffun) | CAR (Cordillera Administrative Region) | Benguet (La Trinidad, Baguio City) | Apayao (Kabugao) | Kalinga (Tabuk) | Region III | Zambales (Iba, Olongapo) | Bataan (Balanga) | Pampanga (San Fernando) | Tarlac (Tarlac City) | Region IV-A (CALABARZON) | Quezon (Infanta, Lucban) | Rizal (Tanay, Antipolo) | Laguna (San Pablo)";
        typhoons.push_back(t14);

        // Opong
        Typhoon t15;
        t15.name = "Opong";
        t15.arrival = "1600_09/23";
        t15.departure = "0000_09/27";
               t15.month = "September";
        t15.interval = "4";
        t15.stormCrossing = "Land";
        t15.timeOfLandfall = "2025-09-26 23:30";
        t15.developed = "WITHIN THE PAR";
        t15.pathType = "West to Northward";
        t15.levels = "Tropical Storm";
        t15.windSpeed = 120;
        t15.casualties = 19;
        t15.damages = 1000000000.0;
        t15.placesAffected = "Region V / Bicol / Eastern Visayas / MIMAROPA | Eastern Samar (San Policarpo, Arteche, Maslog, Oras, Sulat) | Northern Samar | Samar (Catbalogan City, other towns) | Biliran | Masbate (Masbate City, Aroroy, Mobo, Uson, Dimasalang, Cataingan, Pio V. Corpuz) | Romblon | Occidental Mindoro | Oriental Mindoro (Calapan City, Naujan, Bulalacao, Puerto Galera, Pinamalayan, San Teodoro, Roxas) | Southern Luzon / MIMAROPA coastal areas affected by enhanced southwest monsoon";
        typhoons.push_back(t15);

        // Paolo
        Typhoon t16;
        t16.name = "Paolo";
        t16.arrival = "1100_10/01";
        t16.departure = "0500_10/04";
        t16.month = "October";
        t16.interval = "4";
        t16.stormCrossing = "Land";
        t16.timeOfLandfall = "2025-10-03 10:00";
        t16.developed = "WITHIN THE PAR";
        t16.pathType = "West-northwestward";
        t16.levels = "Tropical Storm";
        t16.windSpeed = 135;
        t16.casualties = 1;
        t16.damages = 11000000.0;
        t16.placesAffected = "Region I | Ilocos Region | Northern Ilocos Norte | Region II | Cagayan Valley | Batanes | Babuyan Islands | Region V | Bicol Region | Bicol Region (General) | Region IV-A | CALABARZON | Quezon | Region VIII | Eastern Visayas | Northern Samar | Eastern Samar";
        typhoons.push_back(t16);

        // Quedan
        Typhoon t17;
        t17.name = "Quedan";
        t17.arrival = "1240_10/09";
        t17.departure = "0200_10/10";
        t17.month = "October";
        t17.interval = "1";
        t17.stormCrossing = "Water";
        t17.timeOfLandfall = "None";
        t17.developed = "Outside the PAR";
        t17.pathType = "northeastward";
        t17.levels = "Tropical Storm";
        t17.windSpeed = 70;
        t17.casualties = 0;
        t17.damages = 0.0;
        t17.placesAffected = "Region I | Ilocos Region | Northern Ilocos Norte | Region II | Cagayan Valley | Batanes | Babuyan Islands | Region V | Bicol Region | Bicol Region (General) | Region IV-A | CALABARZON | Quezon | Region VIII | Eastern Visayas | Northern Samar | Eastern Samar";
        typhoons.push_back(t17);

        // Ramil
        Typhoon t18;
        t18.name = "Ramil";
        t18.arrival = "1800_10/17";
        t18.departure = "0800_10/20";
        t18.month = "October";
        t18.interval = "3";
        t18.stormCrossing = "Land";
        t18.timeOfLandfall = "2025-10-18 - 14:00";
        t18.developed = "WITHIN THE PAR";
        t18.pathType = "West-northwestward";
        t18.levels = "Tropical Storm";
        t18.windSpeed = 65;
        t18.casualties = 7;
        t18.damages = 0.0;
        t18.placesAffected = "Region I | Ilocos Region | Ilocos Norte (Laoag, Batac, Pagudpud) | La Union (San Fernando, Bacnotan) | Pangasinan (Dagupan, Lingayen) | Region II | Cagayan Valley | Cagayan (Tuguegarao, Aparri) | Isabela (Ilagan, Santiago) | Nueva Vizcaya (Bayombong) | Quirino (Diffun) | Batanes (Basco) | Babuyan Islands (Calayan, Camiguin Norte) | Region IV-A | CALABARZON | Quezon (Polillo, Infanta, Lucban) | Rizal (Tanay, Antipolo) | Laguna (San Pablo, Calamba) | Region V | Bicol Region | Camarines Norte (Daet, Labo) | Camarines Sur (Naga, Pili) | Albay (Legazpi, Tabaco) | Sorsogon (Sorsogon City, Bulan) | Region VIII | Eastern Visayas | Northern Samar (Catarman, Laoang) | Eastern Samar (Borongan, San Policarpo)";
        typhoons.push_back(t18);

        // Salome
        Typhoon t19;
        t19.name = "Salome";
        t19.arrival = "0800_10/22";
        t19.departure = "1230_11/05";
        t19.month = "October";
        t19.interval = "1";
        t19.stormCrossing = "Water";
        t19.timeOfLandfall = "05:00_10/23";
        t19.developed = "WITHIN THE PAR";
        t19.pathType = "Northwestward";
        t19.levels = "Tropical Depression";
        t19.windSpeed = 55;
        t19.casualties = 0;
        t19.damages = 10000000.0;
        t19.placesAffected = "Region I | Ilocos Region | Northern Ilocos Norte | Region II | Cagayan Valley | Batanes | Babuyan Islands | Region V | Bicol Region | Bicol Region (General) | Region IV-A | CALABARZON | Quezon | Region VIII | Eastern Visayas | Northern Samar | Eastern Samar";
        typhoons.push_back(t19);

        // Tino
        Typhoon t20;
        t20.name = "Tino";
        t20.arrival = "0530_11/02";
        t20.departure = "0500_11/11";
        t20.month = "November";
        t20.interval = "3";
        t20.stormCrossing = "Land";
        t20.timeOfLandfall = "12:00_11/04";
        t20.developed = "OUTSIDE THE PAR";
        t20.pathType = "West-Northwestward";
        t20.levels = "Tropical Storm";
        t20.windSpeed = 85;
               t20.casualties = 253;
        t20.damages = 974000000.0;
        t20.placesAffected = "Region V | Bicol Region | Masbate | Sorsogon | Albay | Region VI | Western Visayas | Iloilo | Negros Occidental | Capiz | Antique | Guimaras | Region VII | Central Visayas | Cebu | Siquijor | Bohol | Region VIII | Eastern Visayas | Southern Leyte | Leyte | Eastern Samar | Northern Samar | Region IV-A | CALABARZON | Quezon | Marinduque | Region IV-B | MIMAROPA | Palawan | Occidental Mindoro | Romblon | Region XIII | Caraga | Dinagat Island | Surigao Del Norte";
        typhoons.push_back(t20);

        // Uwan
        Typhoon t21;
        t21.name = "Uwan";
        t21.arrival = "2200_11/07";
        t21.departure = "0200_11/27";
        t21.month = "November";
        t21.interval = "4";
        t21.stormCrossing = "Land";
        t21.timeOfLandfall = "21:10_11/09";
        t21.developed = "OUTSIDE THE PAR";
        t21.pathType = "Northeastward";
        t21.levels = "Super Typoon";
        t21.windSpeed = 185;
        t21.casualties = 33;
        t21.damages = 818740000.0;
        t21.placesAffected = "Region V | Bicol Region | Masbate | Sorsogon | Albay | Region VI | Western Visayas | Iloilo | Negros Occidental | Capiz | Antique | Guimaras | Region VII | Central Visayas | Cebu | Siquijor | Bohol | Region VIII | Eastern Visayas | Southern Leyte | Leyte | Eastern Samar | Northern Samar | Region IV-A | CALABARZON | Quezon | Marinduque | Region IV-B | MIMAROPA | Palawan | Occidental Mindoro | Romblon | Region XIII | Caraga | Dinagat Island | Surigao Del Norte";
        typhoons.push_back(t21);

        // Verbena
        Typhoon t22;
        t22.name = "Verbena";
        t22.arrival = "0200_11/24";
        t22.departure = "1100_12/09";
        t22.month = "November";
        t22.interval = "3";
        t22.stormCrossing = "Land";
        t22.timeOfLandfall = "2:40_11/25";
        t22.developed = "WITHIN THE PAR";
        t22.pathType = "West-Northwestward";
        t22.levels = "Tropical Depression";
        t22.windSpeed = 140;
        t22.casualties = 0;
        t22.damages = 0.0;
        t22.placesAffected = "Region IV-B | MIMAROPA | Palawan | Oriental Mindoro | Region VI | Western Visayas | Iloilo | Capiz | Negros Occidental | Region VIII | Eastern Visayas | Southern Leyte | Region X | Northern Mindanao | Lanao del Norte | Misamis Oriental | Camiguin | Region XIII | Caraga | Surigao del Sur | Butuan City | Dinagat Islands | Agusan del Norte";
        typhoons.push_back(t22);

        // Wilma
        Typhoon t23;
        t23.name = "Wilma";
        t23.arrival = "0600_12/05";
        t23.departure = "0800_12/07";
        t23.month = "December";
        t23.interval = "2";
        t23.stormCrossing = "Land";
        t23.timeOfLandfall = "2025-12-06 22:50";
        t23.developed = "WITHIN THE PAR";
        t23.pathType = "West-Southwestward";
        t23.levels = "Tropical Depression";
        t23.windSpeed = 55;
        t23.casualties = 0;
        t23.damages = 0.0;
        t23.placesAffected = "Region IV-A | Quezon | Rizal | Laguna | Batangas | Region IV-B | Oriental Mindoro | Occidental Mindoro | Palawan | Romblon | Region V | Sorsogon | Masbate | Region VI | Iloilo | Capiz | Antique | Region VII | Cebu | Bohol | Negros Oriental | Region VIII | Samar | Eastern Samar | Northern Samar | Leyte | Southern Leyte | Region XIII | Dinagat Islands | Agusan del Norte | Surigao del Norte";
        typhoons.push_back(t23);
    } 
    else {
        cout << "Error: Invalid year. Only 2024 or 2025 supported." << endl;
    }
    return typhoons;
}

// Function to get typhoons for a specific month and year
vector<Typhoon> getTyphoonsForMonth(const vector<Typhoon>& typhoons, int month) {
    vector<Typhoon> result;
    for (const auto& t : typhoons) {
        if (getMonthInt(t.month) == month) {  // FIXED: was getMonth()
            result.push_back(t);
        }
    }
    return result;
}

// Function to display typhoon details
void displayTyphoons(const vector<Typhoon>& typhoons) {
    if (typhoons.empty()) {
        cout << "No typhoons recorded for this month." << endl;
        return;
    }
    for (const auto& t : typhoons) {
        cout << "Name: " << t.name << endl;
        cout << "Arrival (PAR): " << t.arrival << endl;
        cout << "Departure (PAR): " << t.departure << endl;
        cout << "Month: " << t.month << endl;
        cout << "Interval: " << t.interval << endl;
        cout << "Storm Crossing: " << t.stormCrossing << endl;
        cout << "Time of Landfall: " << t.timeOfLandfall << endl;
        cout << "Developed: " << t.developed << endl;
        cout << "Path Type: " << t.pathType << endl;
        cout << "Levels: " << t.levels << endl;
        cout << "Wind Speed: " << t.windSpeed << " km/h" << endl;
        cout << "Casualties: " << t.casualties << endl;
        cout << "Damages: " << fixed << setprecision(2) << t.damages << " Peso" << endl;
        cout << "Places Affected: " << t.placesAffected << endl;
        cout << "----------------------------------------" << endl;
    }
}
// Function to display resolutions/recommendations
void displayResolutions(int year) {
    cout << "-- Resolution(s) / Recommendation(s) for " << year << " --" << endl;
    if (year == 2024) {
        cout << "** Government **" << endl;
        cout << "- Increase funding for rapid evacuation systems due to high casualty rates." << endl;
        cout << "- Implement stricter zoning laws in coastal areas affected by multiple typhoons." << endl;
        cout << "- Enhance collaboration with local governments for real-time data sharing." << endl;
        cout << "- Invest in mental health support for disaster survivors." << endl;
        cout << "- Develop national typhoon preparedness campaigns targeting vulnerable populations." << endl;

        cout << "** Community **" << endl;
        cout << "- Organize local training sessions on first aid and emergency response." << endl;
        cout << "- Establish community watch groups for early typhoon warnings." << endl;
        cout << "- Promote household emergency kits with focus on food and water storage." << endl;
        cout << "- Foster neighborhood support networks for post-typhoon recovery." << endl;
        cout << "- Encourage sustainable farming practices to reduce environmental vulnerability." << endl;

        cout << "** Improvements **" << endl;
        cout << "- Upgrade weather radar systems for better storm tracking accuracy." << endl;
        cout << "- Integrate AI-driven prediction models for casualty minimization." << endl;
        cout << "- Improve data collection on human impacts for future planning." << endl;
        cout << "- Develop mobile apps for personalized evacuation alerts." << endl;
        cout << "- Enhance communication infrastructure to prevent information gaps." << endl;

        cout << "** Advance Preparedness **" << endl;
        cout << "- Conduct annual simulation drills in high-risk areas." << endl;
        cout << "- Stockpile medical supplies in advance of typhoon season." << endl;
        cout << "- Train volunteers in search and rescue operations." << endl;
        cout << "- Create digital maps for safe evacuation routes." << endl;
        cout << "- Implement early warning systems in schools and hospitals." << endl;
    } else if (year == 2025) {
        cout << "** Government **" << endl;
        cout << "- Allocate budgets for infrastructure repair following extensive damages." << endl;
        cout << "- Enforce building codes with typhoon-resistant materials." << endl;
        cout << "- Partner with international aid for long-term recovery." << endl;
        cout << "- Introduce tax incentives for disaster-resilient construction." << endl;
        cout << "- Establish a national fund for typhoon damage compensation." << endl;

        cout << "** Community **" << endl;
        cout << "- Build community shelters with improved durability." << endl;
        cout << "- Educate on insurance options for property protection." << endl;
        cout << "- Promote reforestation to mitigate future storm intensity." << endl;
        cout << "- Organize workshops on damage assessment and reporting." << endl;
        cout << "- Strengthen family emergency plans with focus on economic recovery." << endl;

        cout << "** Improvements **" << endl;
        cout << "- Invest in satellite technology for precise damage mapping." << endl;
        cout << "- Develop predictive analytics for economic impact reduction." << endl;
        cout << "- Upgrade communication networks for uninterrupted service." << endl;
        cout << "- Integrate drone technology for rapid post-storm surveys." << endl;
        cout << "- Enhance data analytics for trend analysis in typhoon patterns." << endl;

        cout << "** Advance Preparedness **" << endl;
        cout << "- Create regional stockpiles of construction materials." << endl;
        cout << "- Train engineers in quick infrastructure restoration." << endl;
        cout << "- Develop apps for real-time damage reporting." << endl;
        cout << "- Conduct vulnerability assessments annually." << endl;
        cout << "- Establish partnerships with NGOs for sustained support." << endl;
    } else {
        cout << "No specific resolutions available for this year." << endl;
    }
}

// Function for search: Top 3 Strongest Typhoons
void searchTop3Strongest(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025) {
    vector<Typhoon> all = typhoons2024;
    all.insert(all.end(), typhoons2025.begin(), typhoons2025.end());
    sort(all.begin(), all.end(), [](const Typhoon& a, const Typhoon& b) {
        return a.windSpeed > b.windSpeed;
    });

    cout << "-- Top 3 Strongest Typhoons from 2024 - 2025 --" << endl;
    for (int i = 0; i < min(3, (int)all.size()); ++i) {
        cout << (i + 1) << ". " << all[i].name << " - " << all[i].windSpeed << " km/h" << endl;
    }

    cout << "1. Comments" << endl;
    cout << "2. Menu" << endl;
    cout << "3. Back" << endl;
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (choice == 1) {
            cout << "-- Comments --" << endl;
            cout << "These top typhoons highlight the need for advanced wind-resistant infrastructure and early warning systems." << endl;
            cout << "1. Menu" << endl;
            cout << "2. Back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (choice == 1) break;
        } else if (choice == 2) {
            break;
        } else if (choice == 3) {
            // Stay in search
        } else {
            cout << "Invalid choice." << endl;
        }
    }
}

// Function for search: Most Damaging Typhoon
void searchMostDamaging(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025) {
    vector<Typhoon> all = typhoons2024;
    all.insert(all.end(), typhoons2025.begin(), typhoons2025.end());
    if (all.empty()) {
        cout << "No typhoon data available." << endl;
        return;
    }
    Typhoon most = *max_element(all.begin(), all.end(), [](const Typhoon& a, const Typhoon& b) {
        return a.damages < b.damages;
    });

    cout << "The " << most.name
         << " is considered the most damaging typhoon that entered the Philippines with "
         << fixed << setprecision(2) << most.damages << " pesos in cost of damage." << endl;

    cout << "1. Comments" << endl;
    cout << "2. Menu" << endl;
    cout << "3. Back" << endl;
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (choice == 1) {
            cout << "-- Comments --" << endl;
            cout << "This typhoon caused significant economic losses, highlighting the need for better infrastructure and financial preparedness." << endl;
            cout << "1. Menu" << endl;
            cout << "2. Back" << endl;
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (choice == 1) break;
        } else if (choice == 2) {
            break;
        } else if (choice == 3) {
            // Stay in search
        } else {
            cout << "Invalid choice." << endl;
        }
    }
}

// Function for search: List all names alphabetically
void searchAlphabetical(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025) {
    vector<Typhoon> all = typhoons2024;
    all.insert(all.end(), typhoons2025.begin(), typhoons2025.end());
    sort(all.begin(), all.end(), [](const Typhoon& a, const Typhoon& b) {
        return a.name < b.name;
    });

    cout << "-- List of Typhoons from 2024 - 2025 (A-Z) --" << endl;
    for (const auto& t : all) {
        cout << t.name << endl;
    }

    cout << "1. Comments" << endl;
    cout << "2. Menu" << endl;
    cout << "3. Back" << endl;

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (choice == 1) {
            cout << "-- Comments --" << endl;
            cout << "Listing typhoons alphabetically aids in systematic tracking and historical analysis." << endl;
            cout << "1. Menu" << endl;
            cout << "2. Back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (choice == 1) break;
        } else if (choice == 2) {
            break;
        } else if (choice == 3) {
            // Stay in search
        } else {
            cout << "Invalid choice." << endl;
        }
    }
}

// Function for search: Longest Stay
void searchLongestStay(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025) {
    vector<Typhoon> all = typhoons2024;
    all.insert(all.end(), typhoons2025.begin(), typhoons2025.end());
    if (all.empty()) {
        cout << "No typhoon data available." << endl;
        return;
    }
    Typhoon longest = *max_element(all.begin(), all.end(), [](const Typhoon& a, const Typhoon& b) {
        try {
            return stoi(a.interval) < stoi(b.interval);
        } catch (...) {
            return false;
        }
    });

    cout << "The " << longest.name << " had the longest stay with " << longest.interval << " days." << endl;
    cout << "1. Comments" << endl;
    cout << "2. Menu" << endl;
    cout << "3. Back" << endl;

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (choice == 1) {
            cout << "-- Comments --" << endl;
            cout << "Extended stays increase exposure time, necessitating prolonged preparedness measures." << endl;
            cout << "1. Menu" << endl;
            cout << "2. Back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (choice == 1) break;
        } else if (choice == 2) {
            break;
        } else if (choice == 3) {
            // Stay in search
        } else {
            cout << "Invalid choice." << endl;
        }
    }
}

// Function for search: Sort by Landfall
void searchLandfall(const vector<Typhoon>& typhoons2024, const vector<Typhoon>& typhoons2025) {
    vector<Typhoon> all = typhoons2024;
    all.insert(all.end(), typhoons2025.begin(), typhoons2025.end());

    vector<Typhoon> landfall;
    for (const auto& t : all) {
        if (t.stormCrossing == "Land") {
            landfall.push_back(t);
        }
    }

    cout << "-- Typhoons that made Landfall --" << endl;
    for (const auto& t : landfall) {
        cout << t.name << endl;
    }

    cout << "1. Comments" << endl;
    cout << "2. Menu" << endl;
    cout << "3. Back" << endl;
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (choice == 1) {
            cout << "-- Comments --" << endl;
            cout << "Landfall typhoons pose direct threats, requiring focused coastal defense strategies." << endl;
            cout << "1. Menu" << endl;
            cout << "2. Back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (choice == 1) break;
        } else if (choice == 2) {
            break;
        } else if (choice == 3) {
            // Stay in search
        } else {
            cout << "Invalid choice." << endl;
        }
    }
}

int main() {
    vector<Typhoon> typhoons2024 = loadTyphoons(2024);
    vector<Typhoon> typhoons2025 = loadTyphoons(2025);

    int choice;
    bool running = true;

    while (running) {
        cout << "\nWelcome to ClimaScope\n" << endl << endl;
        cout << " Homepage " << endl;
        cout << "1. Swipe Up" << endl;
        cout << "2. Search" << endl;
        cout << "3. Menu" << endl;
        cout << "4. Exit the Execution" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: { // Swipe Up -> Year
                bool inYear = true;
                while (inYear) {
                    cout << "----------------------------------------" << endl;
                    cout << "– Year –" << endl;
                    cout << "1. 2024" << endl;
                    cout << "2. 2025" << endl;
                    cout << "3. Menu" << endl;
                    cout << "4. Back" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number." << endl;
                        continue;
                    }
                    switch (choice) {
                        case 1: { // 2024
                            bool inMonths2024 = true;
                            while (inMonths2024) {
                                cout << "----------------------------------------" << endl;
                                cout << "– Months that has typhoon(s) for 2024 –" << endl;
                                cout << "1. May" << endl;
                                cout << "2. July" << endl;
                                cout << "3. August" << endl;
                                cout << "4. September" << endl;
                                cout << "5. October" << endl;
                                cout << "6. November" << endl;
                                cout << "7. December" << endl;
                                cout << "8. Back" << endl;
                                cout << "9. Menu" << endl;
                                cout << "Enter your choice: ";
                                cin >> choice;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input. Please enter a number." << endl;
                                    continue;
                                }
                                if (choice >= 1 && choice <= 7) {
                                    int month = (choice == 1) ? 5 :
                                                (choice == 2) ? 7 :
                                                (choice == 3) ? 8 :
                                                (choice == 4) ? 9 :
                                                (choice == 5) ? 10 :
                                                (choice == 6) ? 11 : 12;

                                    vector<Typhoon> monthTyphoons = getTyphoonsForMonth(typhoons2024, month);
                                    cout << "----------------------------------------" << endl;
                                    cout << "– Typhoon(s) for the month of "
                                         << ((choice == 1) ? "May" :
                                             (choice == 2) ? "July" :
                                             (choice == 3) ? "August" :
                                             (choice == 4) ? "September" :
                                             (choice == 5) ? "October" :
                                             (choice == 6) ? "November" : "December")
                                         << " 2024 –" << endl;
                                    displayTyphoons(monthTyphoons);
                                    cout << "1. Resolution(s) / Recommendation(s) for 2024" << endl;
                                    cout << "2. Menu" << endl;
                                    cout << "3. Back" << endl;
                                    cout << "Enter your choice: ";
                                    cin >> choice;
                                    if (cin.fail()) {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cout << "Invalid input. Please enter a number." << endl;
                                        continue;
                                    }
                                    switch (choice) {
                                        case 1:
                                            displayResolutions(2024);
                                            cout << "1. Menu" << endl;
                                            cout << "2. Back" << endl;
                                            cin >> choice;
                                            if (cin.fail()) {
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                continue;
                                            }
                                            if (choice == 1) inMonths2024 = false;
                                            break;
                                        case 2:
                                            inMonths2024 = false;
                                            break;
                                        case 3:
                                            break; // Back to months
                                        default:
                                            cout << "Invalid choice." << endl;
                                    }
                                } else if (choice == 8) {
                                    inMonths2024 = false;
                                } else if (choice == 9) {
                                    inMonths2024 = false;
                                    inYear = false;
                                } else {
                                    cout << "Invalid choice." << endl;
                                }
                            }
                            break;
                        }
                        case 2: { // 2025
                            bool inMonths2025 = true;
                            while (inMonths2025) {
                                cout << "----------------------------------------" << endl;
                                cout << "– Months that has typhoon(s) for 2025 –" << endl;
                                cout << "1. July" << endl;
                                cout << "2. August" << endl;
                                cout << "3. September" << endl;
                                cout << "4. October" << endl;
                                cout << "5. November" << endl;
                                cout << "6. December" << endl;
                                cout << "7. Back" << endl;
                                cout << "8. Menu" << endl;
                                cout << "Enter your choice: ";
                                cin >> choice;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input. Please enter a number." << endl;
                                    continue;
                                }
                                if (choice >= 1 && choice <= 6) {
                                    int month = (choice == 1) ? 7 :
                                                (choice == 2) ? 8 :
                                                (choice == 3) ? 9 :
                                                (choice == 4) ? 10 :
                                                (choice == 5) ? 11 : 12;

                                    vector<Typhoon> monthTyphoons = getTyphoonsForMonth(typhoons2025, month);
                                    cout << "----------------------------------------" << endl;
                                    cout << "– Typhoon(s) for the month of "
                                         << ((choice == 1) ? "July" :
                                             (choice == 2) ? "August" :
                                             (choice == 3) ? "September" :
                                             (choice == 4) ? "October" :
                                             (choice == 5) ? "November" : "December")
                                         << " 2025 –" << endl;
                                    displayTyphoons(monthTyphoons);
                                    cout << "1. Resolution(s) / Recommendation(s) for 2025" << endl;
                                    cout << "2. Menu" << endl;
                                    cout << "3. Back" << endl;
                                    cout << "Enter your choice: ";
                                    cin >> choice;
                                    if (cin.fail()) {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cout << "Invalid input. Please enter a number." << endl;
                                        continue;
                                    }
                                    switch (choice) {
                                        case 1:
                                            displayResolutions(2025);
                                            cout << "1. Menu" << endl;
                                            cout << "2. Back" << endl;
                                            cin >> choice;
                                            if (cin.fail()) {
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                continue;
                                            }
                                            if (choice == 1) inMonths2025 = false;
                                            break;
                                        case 2:
                                            inMonths2025 = false;
                                            break;
                                        case 3:
                                            break; // Back to months
                                        default:
                                            cout << "Invalid choice." << endl;
                                    }
                                } else if (choice == 7) {
                                    inMonths2025 = false;
                                } else if (choice == 8) {
                                    inMonths2025 = false;
                                    inYear = false;
                                } else {
                                    cout << "Invalid choice." << endl;
                                }
                            }
                            break;
                        }
                        case 3: // Menu
                            inYear = false;
                            break;
                        case 4: // Back
                            inYear = false;
                            break;
                        default:
                            cout << "Invalid choice." << endl;
                    }
                }
                break;
            }
            case 2: { // Search
                bool inSearch = true;
                while (inSearch) {
                    cout << "----------------------------------------" << endl;
                    cout << "– Searching –" << endl;
                    cout << "1. Top 3 Strongest Typhoons from 2024 - 2025 (Based on their Wind Speed)" << endl;
                    cout << "2. Most Damaging Typhoon (Based on the cost in Peso)" << endl;
                    cout << "3. List all names of Typhoons from 2024 - 2025 by Alphabetical Order (A-Z)" << endl;
                    cout << "4. Longest Stay in Land (Arrival to Departure)" << endl;
                    cout << "5. Sort all typhoons that made Landfall (Based on Storm Crossing)" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number." << endl;
                        continue;
                    }
                    switch (choice) {
                        case 1:
                            searchTop3Strongest(typhoons2024, typhoons2025);
                            break;
                        case 2:
                            searchMostDamaging(typhoons2024, typhoons2025);
                            break;
                        case 3:
                            searchAlphabetical(typhoons2024, typhoons2025);
                            break;
                        case 4:
                            searchLongestStay(typhoons2024, typhoons2025);
                            break;
                        case 5:
                            searchLandfall(typhoons2024, typhoons2025);
                            break;
                        default:
                            cout << "Invalid choice." << endl;
                    }
                    cout << "1. Menu" << endl;
                    cout << "2. Back" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number." << endl;
                        continue;
                    }
                    if (choice == 1) inSearch = false;
                    // If 2, stay in search
                }
                break;
            }
            case 3: { // Menu
                bool inMenu = true;
                while (inMenu) {
                    cout << "----------------------------------------" << endl;
                    cout << "– Menu –" << endl;
                    cout << "1. Home" << endl;
                    cout << "2. Contact" << endl;
                    cout << "3. Setting" << endl;
                    cout << "4. About" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number." << endl;
                        continue;
                    }
                    switch (choice) {
                        case 1: // Home
                            inMenu = false;
                            break;
                        case 2: { // Contact
                            bool inContact = true;
                            while (inContact) {
                                cout << "----------------------------------------" << endl;
                                cout << "– Contact Us –" << endl;
                                cout << "1. Location" << endl;
                                cout << "2. Email" << endl;
                                cout << "3. Tel No." << endl;
                                cout << "– Follow Us –" << endl;
                                cout << "4. Facebook" << endl;
                                cout << "5. X (Twitter)" << endl;
                                cout << "6. Instagram" << endl;
                                cout << "Enter your choice: ";
                                cin >> choice;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input. Please enter a number." << endl;
                                    continue;
                                }
                                switch (choice) {
                                    case 1:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Location –" << endl;
                                        cout << "629 J. Nepomuceno Street, Quiapo, Manila, Philippines 1001" << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inContact = false;
                                        break;
                                    case 2:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Email –" << endl;
                                        cout << "info@climascopo.ph" << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inContact = false;
                                        break;
                                    case 3:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Tel No. –" << endl;
                                        cout << "+63 2 123 4567" << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inContact = false;
                                        break;
                                    case 4:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Facebook –" << endl;
                                        cout << "Link: www.Facebook.com/clima-scope/jfdihiefuh483nUT7GAYUYgubed/source=?/k" << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inContact = false;
                                        break;
                                    case 5:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– X (Twitter) –" << endl;
                                        cout << "Link: www.twitter.com/climascopo" << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inContact = false;
                                        break;
                                    case 6:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Instagram –" << endl;
                                        cout << "Link: www.instagram.com/climascopo" << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inContact = false;
                                        break;
                                    default:
                                        cout << "Invalid choice." << endl;
                                }
                            }
                            break;
                        }
                        case 3: { // Setting
                            bool inSetting = true;
                            while (inSetting) {
                                cout << "----------------------------------------" << endl;
                                cout << "– Settings –" << endl;
                                cout << "1. Preference" << endl;
                                cout << "2. Notifications" << endl;
                                cout << "3. Legal & Policies" << endl;
                                cout << "4. Help" << endl;
                                cout << "5. Report Technical Problem" << endl;
                                cout << "6. Rate Us" << endl;
                                cout << "7. Menu" << endl;
                                cout << "Enter your Choice: ";
                                cin >> choice;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input. Please enter a number." << endl;
                                    continue;
                                }
                                switch (choice) {
                                    case 1: { // Preference
                                        bool inPreference = true;
                                        while (inPreference) {
                                            cout << "----------------------------------------" << endl;
                                            cout << "– Preference –" << endl;
                                            cout << "1. Dark Mode" << endl;
                                            cout << "2. Default" << endl;
                                            cout << "3. Menu" << endl;
                                            cout << "4. Back" << endl;
                                            cout << "Enter your choice: ";
                                            cin >> choice;
                                            if (cin.fail()) {
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                cout << "Invalid input. Please enter a number." << endl;
                                                continue;
                                            }
                                            switch (choice) {
                                                case 1:
                                                    cout << "----------------------------------------" << endl;
                                                    cout << "– Dark Mode has been applied –" << endl;
                                                    cout << "1. Menu" << endl;
                                                    cout << "2. Back" << endl;
                                                    cin >> choice;
                                                    if (cin.fail()) {
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        continue;
                                                    }
                                                    if (choice == 1) inPreference = false;
                                                    break;
                                                case 2:
                                                    cout << "----------------------------------------" << endl;
                                                    cout << "– Default Mode has been applied –" << endl;
                                                    cout << "1. Menu" << endl;
                                                    cout << "2. Back" << endl;
                                                    cin >> choice;
                                                    if (cin.fail()) {
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        continue;
                                                    }
                                                    if (choice == 1) inPreference = false;
                                                    break;
                                                case 3:
                                                    inPreference = false;
                                                    break;
                                                case 4:
                                                    inPreference = false;
                                                    break;
                                                default:
                                                    cout << "Invalid choice." << endl;
                                            }
                                        }
                                        break;
                                    }
                                    case 2:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Notifications –" << endl;
                                        cout << "Notifications settings here." << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inSetting = false;
                                        break;
                                    case 3:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Legal & Policies –" << endl;
                                        cout << "Privacy Policy and Terms of Service text here." << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inSetting = false;
                                        break;
                                    case 4:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Help –" << endl;
                                        cout << "Help information here." << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inSetting = false;
                                        break;
                                    case 5:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Report Technical Problem –" << endl;
                                        cout << "Report form here." << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inSetting = false;
                                        break;
                                    case 6:
                                        cout << "----------------------------------------" << endl;
                                        cout << "– Rate Us –" << endl;
                                        cout << "Rating system here." << endl;
                                        cout << "1. Menu" << endl;
                                        cout << "2. Back" << endl;
                                        cin >> choice;
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            continue;
                                        }
                                        if (choice == 1) inSetting = false;
                                        break;
                                    case 7:
                                        inSetting = false;
                                        break;
                                    default:
                                        cout << "Invalid choice." << endl;
                                }
                            }
                            break;
                        }
                        case 4: { // About
                            cout << "----------------------------------------" << endl;
                            cout << "– About –" << endl;
                            cout << "\"ClimaScope: Tracking, Impact, and Climate Solutions for Philippine Typhoons.\"" << endl;
                            cout << "\"ClimaScope is a comprehensive platform that tracks typhoons in the Philippines, analyzes their impact, and provides climate-smart solutions to support preparedness and resilience.\"" << endl;
                            cout << "– Privacy policy –" << endl;
                            cout << "– Terms of Service –" << endl;
                            cout << "1. Back" << endl;
                            cout << "2. Menu" << endl;
                            cin >> choice;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter a number." << endl;
                                continue;
                            }
                            if (choice == 2) inMenu = false;
                            break;
                        }
                        default:
                            cout << "Invalid choice." << endl;
                    }
                }
                break;
            }
            case 4: // Exit
                running = false;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}


