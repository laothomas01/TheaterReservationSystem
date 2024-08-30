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
        std::vector<Seat> GetSeats() const;
};

#endif 