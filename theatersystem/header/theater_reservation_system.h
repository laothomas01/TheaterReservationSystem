
#ifndef THTR_H
#define THTR_H


// #include <vector>
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
//         bool IsUsernameTaken(std::string new_username,std::string new_password);
        void AddOneDay(std::tm& tm);
        // void SortUserDatabase();
//         bool HasUsername(std::string username,std::string password);
//         bool IsValidShow(std::string date,std::string time);
        void InitialMenu(bool start);
        void SignUp();
        void SignIn();
        void ExitSystem(bool start);
        void ViewReservations();
        void CancelReservation(bool start);
        void CompleteTransaction();
        void TransactionMode(User *user);


    public:
        void LoadSystem(std::string filename = " ");
        void reserveSeat(const std::string &showDate, const std::string &showTime, std::string seatId);
        TheaterReservationSystem();
        ~TheaterReservationSystem();
        void ReserveSeats(User* user);
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






//         void AddUser(std::string username, std::string password); 
//         void AddShow(Show show); 
//         void DisplayShows() const;
//         void Start(bool start,std::string filename);
//         void SignUp(bool start);
//         void SignIn(bool start);
//         void TransactionMode(bool start, User user);
//         void ReservationSession(bool start,User& user);
//         void ViewReservations(bool start, User user) const; 
//         void CancelReservation(bool start,User user);
//         void UpdateShow(Show show);
//         std::vector<Show> GetShows() const;
//         std::vector<std::string> SingleDelimeterStringSplit(std::string word, char delimeter);

};
#endif

// // // //forward declaration

// // // class TheaterReservationSystem
// // // {
// // //     private:
// // //         std::vector<User> userDatabase_;
// // //     public:
// // //         std::vector<Show> showDatabase_; 

// // //         TheaterReservationSystem();
// // //         ~TheaterReservationSystem();
// // //         void AddUser(User user);
// // //         void AddShow(Show show);
// // //         // void addUser(User* user);
// // //         bool IsUsernameTaken(std::string new_username);
// // //         std::vector<Show> GetShowDatabase();
// // //         std::vector<User> GetUserDatabase();
// // //         Show GetShow(const std::string& date,const std::string& time);
// // //         // void UpdateShowSeat(std::vector<Seat>& seats)
        
// // //         // Show* GetShow(std::string date,std::string time);
// // //         // void UpdateShowSeats(std::string date,std::string time,std::vector<std::string> seatReservations);
// // //         // void UpdateShowSeats(Show show,std::vector<std::string> reservations);
// // #include <iomanip>
// // #include <ctime>
// // #include <sstream>

// // // class Show {
// // // public:
// // //     Show(std::string date, std::string time, std::vector<Seat> seats) : date(date), time(time), seats(seats) {}
// // //     std::string GetDateString() const { return date; }
// // //     std::string GetTimeString() const { return time; }
// // //     void UpdateSeatAvailability(const std::string& seatId, bool availability) {
// // //         for (Seat& seat : seats) {
// // //             if (seat.GetSeatId() == seatId) {
// // //                 seat.SetAvailability(availability);
// // //                 break;
// // //             }
// // //         }
// // //     }
// // //     void DisplaySeats() const {
// // //         for (const Seat& seat : seats) {
// // //             std::cout << seat.SeatToString();
// // //         }
// // //     }

// // // private:
// // //     std::string date;
// // //     std::string time;
// // //     std::vector<Seat> seats;
// // // };

// // // class TheaterReservationSystem {
// // // public:
// // //     TheaterReservationSystem(const std::vector<Show>& shows) : showDatabase(shows) {}
// // //     Show& GetShow(const std::string& date, const std::string& time) {
// // //         for (Show& show : showDatabase) {
// // //             if (show.GetDateString() == date && show.GetTimeString() == time) {
// // //                 return show;
// // //             }
// // //         }
// // //         throw std::runtime_error("Show not found");
// // //     }
// // //     void UpdateReservedSeats(const std::string& date, const std::string& time, const std::vector<std::string>& seatReservations) {
// // //         Show& show = GetShow(date, time);
// // //         for (const std::string& seatId : seatReservations) {
// // //             show.UpdateSeatAvailability(seatId, false);
// // //         }
// // //     }
// // //     void DisplayShows() const {
// // //         for (const Show& show : showDatabase) {
// // //             std::cout << "Show Date: " << show.GetDateString() << " Time: " << show.GetTimeString() << std::endl;
// // //             show.DisplaySeats();
// // //         }
// // //     }

// // // private:
// // //     std::vector<Show> showDatabase;
// // // };


// // class TheaterReservationSystem
// // {
// //     private:
// //         std::vector<User> userDatabase_;
// //         std::vector<Show> showDatabase_;
// //     public:
// //         TheaterReservationSystem();
// //         ~TheaterReservationSystem();
// //         void AddUser(User user);
// //         void AddShow(Show show);
// //         User GetUser(std::string username,std::string password);
// //         Show GetShow(std::string date,std::string time) const;
// //         void AddOneDay(std::tm& tm);
// //         void LoadSystem(std::string filename = " ");
// //         void Start(bool start);
// //         void InitialMenu(bool start);
// //         void SignUp(bool start);
// //         void SignIn(bool start);
// //         void TransactionMode(bool start, User user);
// //         void ReservationSession(bool start,User& user);
// //         void DisplayShows() const;
// //         void ViewReservations(bool start, User user) const; 
// //         void CancelReservation(bool start,User user);
// //         void UpdateShow(Show show);
        
        
// // };

// // #endif
