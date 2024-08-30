
#ifndef THTR_H
#define THTR_H


#include <iostream>
#include "show.h"
#include "user.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string> 

class TheaterReservationSystem 
{
    private:
        std::vector<User> userDatabase_;
        std::vector<Show> showDatabase_; 
        void AddOneDay(std::tm& tm);
        void InitialMenu(bool start);
        void SignUp();
        void SignIn();
        void ExitSystem(bool start);
        void ViewReservations();
        void CompleteTransaction();
        void TransactionMode(User *user);


    public:
        void LoadSystem(std::string filename = " ");
        void reserveSeat(const std::string &showDate, const std::string &showTime, std::string seatId);
        TheaterReservationSystem();
        ~TheaterReservationSystem();
        void ReserveSeats(User* user);
        void CancelReservation(User* user);
        void AddShow(Show show);
        
        void AddUser(User user);
        void DisplayShows() const;
        void DisplayUsers() const;
        void DisplayShowSeats(const std::string &showDate,const std::string &showTime);
        //we will implement binary search another time 
        bool HasUser(std::string username);
        void UpdateSeatAvailability(bool available,Seat seat);
        void UpdateSeatAvailability(bool available, const std::string &showDate, const std::string &showTime, const std::string &seatId);
        void UpdateSeatAvailability(Show* show, bool avail,std::string seatId);
        void Start(bool start);
        //return a reference???? pointer???? 
        User* FindUserLogin(const std::string& username,const std::string& password);
        Show* findShow(const std::string& date, const std::string& time);
        void UpdatePassword(std::string username,std::string password);
        void ViewReservations(User* user);
        void Out(User* user);

};
#endif

