#ifndef SHOW_H
#define SHOW_H

#include <ctime>
#include <vector>
#include "seat.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <iostream>
#include <iomanip>

// class Show
// {
//     private:
//         std::tm time_;
//         std::tm date_;
//         std::vector<Seat> seats_;
//     public:
//         Show(std::tm time,std::tm date);
//         Show();
//         ~Show();
//         void AddSeat(Seat seat);
//         Seat GetSeat(std::string seatId) const;
//         void test(int);
//         std::string GetDateString();
//         std::string GetTimeString();
//         std::tm GetTime() const;
//         std::tm GetDate() const;
//         void UpdateSeatAvailability(std::string seatId,bool availability);
//         std::string ShowToString();
//         void DisplayAvailableSeats() const;
//         void DisplayAllSeats() const;
//         std::vector<Seat> GetSeats();
//         void removeallseats();


// };

class Show
{
    private:
        std::tm time_;
        std::tm date_;
        std::vector<Seat> seats_;

    public:
        Show(std::tm time,std::tm date);
        ~Show();
        void AddSeat(Seat s);
        void RemoveSeat(std::string seatId);
        std::string ToString();
        std::string GetDateString() const;
        std::string GetTimeString() const;
        std::tm GetDate();
        std::tm GetTime();
        void DisplaySeats();
        bool HasSeat(std::string seatId);
        Seat* findSeat(std::string seatId);
        void UpdateSeatAvailability(bool available, const std::string& seatId);
        // void UpdateSeatAvailability(std::string seatId,bool available);
        // void UpdateSeatPrice(std::string seatId,double price);
        // bool IsValidSeat(std::string seatId);

    
};
// // #include <vector> 
// // #include <iostream>
// // #include <iomanip>
// // #include "seat.h"
// // #include <ctime>
// // #include <unordered_set>

// // class Show
// // {
// //     private:
// //         std::tm time_;
// //         std::tm date_; 
// //         std::vector<Seat> seats_;
// //     public:
// //         Show(std::tm time,std::tm date);
// //         ~Show();
// //         void AddSeat(Seat s);
// //         Seat GetSeat(std::string seatId);
// //         void UpdateSeat(const Seat& updatedSeat);
// //         void UpdateSeats(const std::unordered_set<std::string> reservedSeatIds,bool availability);
// //         std::tm GetTime();
// //         std::tm GetDate();
// //         std::string GetDateString();
// //         std::string GetTimeString();
// //         std::string ShowToString();
// //         void DisplaySeats();
// //         std::vector<Seat> GetSeats();
// //         std::string FormatDate(const std::tm& tm);
// //         std::string FormatTime(const std::tm& tm);
        
// // };
// // // #include <string>
// // // #include <vector>
// // // #include <iostream>
// // // #include "seat.h"

// // // //forward declaration 

// // // class Show
// // // {
// // //     private:
// // //         std::string date_;
// // //         std::string time_;
// // //         // std::vector<Seat*> seats_; 
// // //     public:
// // //         // Show(std::string date, std::string time);

// // //         ~Show();
// // //         void addSeat(std::string seatId,double price,bool availability);
// // //         // std::vector<Seat*> getSeats();
// // //         Seat* getSeat(std::string seatId);
// // //         std::string getDate();
// // //         std::string getTime();
// // //         std::string showToString();
// // //         bool displaySeats();
        

// // // };

#endif 