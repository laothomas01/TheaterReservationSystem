
#ifndef USER_H
#define USER_H
#include <string>
#include "show.h"
#include <algorithm>
#include <map>
class User
{
    private:
        std::string username_;
        std::string password_;
        std::map<std::string,Show> reservations;

        // std::vector<Show> reservations_;
        std::vector<Show> SortReservations();

        static bool CompareShows(Show& a,Show& b)
        {
            std::tm date1 = a.GetDate();
            std::tm date2 = b.GetDate();

            std::time_t dateA = std::mktime(const_cast<std::tm*>(&date1));
            std::time_t dateB = std::mktime(const_cast<std::tm*>(&date2));

            if(dateA != dateB)
            {
                return dateA < dateB;
            }


            std::tm time1 = a.GetTime();
            std::tm time2 = b.GetTime();
            //if dates are equal, compare times 

                // If dates are equal, compare times
            std::time_t timeA = std::mktime(const_cast<std::tm*>(&time1));
            std::time_t timeB = std::mktime(const_cast<std::tm*>(&time2));

            return timeA < timeB;

        }
        unsigned int GetReservationSize() const;

    public:
        User(std::string username,std::string password);
        ~User();
        std::string GetUsername() const;
        std::string GetPassword() const;
        std::string ToString() const;
        void SetPassword(const std::string password);
        void AddReservation(Show show);
        void CancelReservation(std::string date, std::string time, std::string seatId);
        Show* FindReservation(std::string date, std::string time);
        // void CancelReservation(Show* reservation,Seat* seat);
        // double CalculateReservationTotalPrice();
        std::map<std::string,Show> GetReservations() const;



        // std::string GetUsername() const;
        // std::string GetPassword() const; 
        // std::string UserToString();
        // std::vector<Show> GetReservations() const;
        // void AddReservation(Show show);
        // void AddReservation(std::tm date,std::tm time,std::string seatId);
        // void AddReservation(std::tm date, std::tm time,std::string seatId,std::vector<Show>& showDatabase);
        // void RemoveReservation(std::string showDate, std::string showTime,std::string seatId,std::vector<Show>& showDatabase);
        void DisplayReservations();
};
#endif
// #include <string> 
// #include "show.h"
// #include <map>
// #include <iostream>
// #include <algorithm>
// // //forward declaration 

// class User 
// {
//     private:
//         std::string username_;
//         std::string password_;
//         // std::unordered_map<std::string,Show> reservations_;
//         std::vector<Show> reservations_;
//     public:
//         User(std::string username, std::string password);
//         User();
//         ~User();
//         std::string GetUsername() const;
//         std::string GetPassword() const; 
//         std::string UserToString();
//         void AddReservation(Show show);
//         // Show GetReservation(std::string date) const;
        
//         std::vector<Show> GetReservations() const;
//         Show GetReservation(std::string date,std::string time) const;
//         void DisplayReservation(std::string date,std::string time) const;
//         // void RemoveReservation(std::string seatId,Show& show,Show& newShow);
//         void UpdateReservations(Show reservations);
//         // void RemoveReservation(std::string seatId,Show show,);
//         // void RemoveReservation(std::string seatID);
//         // void RemoveReservations(std::string showDate, std::string showTime, std::string seatId);
//         void RemoveReservations(Show& show, std::string seatId);
//         void clearallreserves();


// };  

// #endif // USER_H