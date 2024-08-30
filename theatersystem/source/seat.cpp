
#include "seat.h"


Seat::Seat(std::string seatId, double price,bool available)
:
seatId_(seatId),
price_(price),
available_(available)
{
    
}

Seat:: ~Seat()
{
    
}
void Seat::Reserve()
{
    available_ = false;
}
void Seat::CancelReservation()
{
    available_ = true;
}

void Seat::UpdateAvailability(bool available)
{
    available_ = available;
}

std::string Seat::ToString()
{
    return "SeatId: " + seatId_ + " | Price: " + std::to_string(price_) + " | Available: " + std::to_string(available_) + " |\n";
}

double Seat::GetPrice() const
{
    return price_;
}

std::string Seat::GetSeatId() const
{
    return seatId_;
}
bool Seat::IsAvailabile() const 
{
    return available_;
}

