#ifndef SEAT_H
#define SEAT_H
#include <string>
#include <iostream>

class Seat 
{
    private:
        double price_;
        bool available_;
        std::string seatId_;
    public:
        Seat(std::string seatId,double price,bool available);
        ~Seat();
        void UpdateAvailability(bool isAvailable);
        std::string ToString();
        void Reserve();
        void CancelReservation();

        bool IsAvailabile() const;
        std::string GetSeatId() const;
        double GetPrice() const;
    
};
#endif




