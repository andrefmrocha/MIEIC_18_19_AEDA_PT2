//
// Created by andrefmrocha on 12/24/18.
//

#ifndef AEDA_PROJECT_SUPPORTERS_H
#define AEDA_PROJECT_SUPPORTERS_H

#include <string>
#include <set>
#include <iostream>
#include "Repair.h"

class Supporter {
private:
    std::string name;
    std::string gender;
    std::set<Repair> repairDates;
    unsigned daysUntilAvailable;
    unsigned ID;
    static unsigned currentID;

public:

    Supporter(){};

    Supporter(const std::string &name, const std::string &gender);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getGender() const;

    void setGender(const std::string &gender);

    unsigned int getDaysUntilAvailable() const;

    unsigned numRepairs()const;

    std::set<Repair> &getRepairDates() ;

    bool checkAvailability(Date date);

    void scheduleRepair(Date date, Date currentDate, unsigned courtID);

    friend bool operator<(const Supporter sp1, const Supporter sp2);

    unsigned int getID() const;

    friend std::ostream &operator<<(std::ostream& out, const Supporter & sp);

    void storeInfo(std::ofstream &outfile, int indentation);

    void indent(std::ofstream &outfile, int indentation);

    void readInfo(std::ifstream &infile);

    Supporter operator--();

};


#endif //AEDA_PROJECT_SUPPORTERS_H