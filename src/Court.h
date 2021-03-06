/*
 * Court.h
 *
 *  Created on: Oct 21, 2018
 *      Author: andrefmrocha
 */

#ifndef SRC_COURT_H_
#define SRC_COURT_H_

#include "Calendar.h"
#include "Person.h"
#include "Reservation.h"
#include <iostream>
#include <string>
#include <fstream>

/**
 * The information of each Court
 */

class Court {
public:
	/**
	 * @brief Class Constructor
	 */
	Court();

	/**
	 * @brief Class Constructor
	 * @param year - year of the company
	 */
	Court(int year);

	/**
	 * @brief Reservation of a class
	 * @param month - month of the class
	 * @param day - day of the class
	 * @param startingHour - starting hour of the class
	 * @param user - user of the class
	 * @param teacher - teacher that gives the class
	 * @return if the reservation was successfull
	 */
	bool reserveClass(int month, int day, double startingHour, User &user, Teacher &teacher);
	/**
	 * @brief Reservation of a free
	 * @param month - month of the free
	 * @param day - day of the free
	 * @param startingHour - starting hour of the free
	 * @param user - user of the free
	 * @param duration - duration of the free
	 * @return if the reservation was successfull
	 */
	bool reserveFree(int month, int day, double startingHour, int duration, User& user);

	/**
	 *
	 * @brief Store in the information of the Court to a file
	 * @param outfile - the file to write information
	 * @param indent - current indentation
	 */
	void storeInfo(std::ofstream &outfile, int indentation);


	/**
	 * @brief Indenting the file
	 * @param outfile - the file to write information
	 * @param indent - current indentation
	 */
	void indent(std::ofstream&outfile, int identation);

	/**
	 *
	 * @brief Reading the information of a Date from a file
	 * @param infile - file to read the information from
	 */
	void readInfo(std::ifstream &infile);

	/**
	 * @brief Getter of the Maximum of Users
	 * @return the maximum of Users
	 */
	int getMaxUsers()const;

    /**
     * @brief Check if the Court is already reserved at the given time
     * @param month - month of the reservation
     * @param day - day of the reservation
     * @param startingHour - starting Hour of the reservation
     * @param duration - duration of the reservation
     */
	void occupied(int month, int day, double startingHour, int duration);

	/**
	 * @brief Checks if the court is occupied at a given time
	 * @param month - the month of the reservation
	 * @param day - the day of the reservation
	 * @param startingHour - the starting hour of the reservation
	 * @param duration - the duration of reservation
	 * @return - if it is occupied
	 */
	bool isOccupied(int month, int day, double startingHour, int duration);

	/**
	 * @brief Unschedule a given reservation
	 * @param month - the month of the reservation
	 * @param day - the day of the reservation
	 * @param startingHour - the starting hour of the reservation
	 * @param duration - the duration of the reservation
	 */
	void unsetReservation(int month, int day, double startingHour, unsigned int duration);

	/**
	 * @brief The number of hours left at a given time at a court
	 * @param month - the month of the day to be checked
	 * @param day - the day itself
	 */
	void hoursleft(int month, int day);
private:

	/**
	 * @brief Reserve the time in the Court
	 * @param month - month of the reservation
	 * @param day - day of the reservation
	 * @param startingHour - starting Hour of the reservation
	 * @param duration - duration of the reservation
	 */
	void reserveCourt(int month, int day, double startingHour, int duration);
	Year currentYear; /**< The year the company is in **/
	int maxUsers; /**< The maximum of users that can be in the court */
};


/**
 * When court is already reserved
 */
class CourtReserved{
private:
	double startingHour;
	int month;
	int day;

public:
	CourtReserved(int month, int day, double StartingHour);
	std::string what() const;
};

class NoCourtfound{
	double startingHour;
	int month;
	int day;

public:
	NoCourtfound(int month, int day, double StartingHour):month(month), day(day), startingHour(startingHour) {}
	std::string what() const;
};

#endif /* SRC_COURT_H_ */
