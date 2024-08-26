#include "show.h"

Show::Show(std::tm time, std::tm date) : time_(time), date_(date) {}
Show::~Show() {}

std::string Show::ToString()
{
    std::string dateTime = GetDateString() + " | " + GetTimeString();
    return dateTime;
}

void Show::AddSeat(Seat seat)
{
    seats_.push_back(seat);
}

// std::vector<Seat> Show::GetSeats() const
// {
//     return seats_;
// }

// bool Show::IsValidSeat(std::string seatId)
// {
//     for(Seat seat : seats_)
//     {
//         if(seat.GetSeatId() == seatId)
//         {
//             return true;
//         }
//     }
//     return false;
// }

void Show::DisplaySeats()
{
    for (Seat &seat : seats_)
    {
        std::cout << seat.ToString() << std::endl;
    }
}

bool Show::HasSeat(std::string seatId)
{
    for (Seat seat : seats_)
    {
        if (seat.GetSeatId() == seatId)
        {
            return true;
        }
    }
    return false;
}
Seat *Show::findSeat(std::string seatId)
{
    for (Seat &seat : seats_)
    {
        if (seat.GetSeatId() == seatId)
        {
            return &seat;
        }
    }
    return nullptr;
}

void Show::RemoveSeat(std::string seatId)
{
    std::vector<Seat>::iterator iter = seats_.begin();
    while (iter != seats_.end())
    {
        if (iter->GetSeatId() == seatId)
        {
            iter->UpdateAvailability(true);
            seats_.erase(iter);
            break;
        }
        else
        {
            ++iter;
        }
    }
    // Seat s = std::find(seats_.begin(),seats_.end(),)
}
// void Show::UpdateSeatAvailability(std::string seatId,bool available)
// {
//     for(Seat& seat : seats_)
//     {
//         if(seat.GetSeatId() == seatId)
//         {
//             seat.UpdateAvailability(available);
//             break;
//         }
//     }
// }

std::tm Show::GetTime()
{
    return time_;
}
std::tm Show::GetDate()
{
    return date_;
}

// // void Show:: UpdateSeatAvailability(std::string seatId,bool availability)
// // {
// //     for(Seat& seat : seats_)
// //     {
// //         if(seat.GetSeatId() == seatId)
// //         {
// //             seat.SetAvailability(availability);
// //         }
// //     }
// // }

std::string Show::GetDateString() const
{
    std::ostringstream oss;
    oss << std::put_time(&date_, "%Y-%m-%d");
    return oss.str();
}
std::string Show::GetTimeString() const
{
    std::ostringstream oss;
    oss << std::put_time(&time_, "%H:%M");
    return oss.str();
}

void Show::UpdateSeatAvailability(bool available, const std::string &seatId)
{
    Seat *seat = findSeat(seatId);
    if (seat)
    {
        seat->UpdateAvailability(available);
    }
    // for(auto& seat : seats_)
    // {
    //     Seat* seat_ptr = findSeat(seatId);
    //     if(seat_ptr)
    //     {
    //         seat_ptr->UpdateAvailability(available);
    //         return;
    //     }
    // }
}

// // Seat Show::GetSeat(std::string seatId) const
// // {
// //     Seat s("",0,false);
// //     for(Seat seat : seats_)
// //     {
// //         if(seat.GetSeatId() == seatId)
// //         {
// //             s = seat;
// //             return s;
// //         }
// //     }
// //     return s;
// // }
// std::string Show::ShowToString()
// {
//     return "Date: " + GetDateString() + " Time: " + GetTimeString();
// }

// // std::vector<Seat> Show:: GetSeats()
// // {
// //     return seats_;
// // }

// // void Show::removeallseats()
// // {
// //     seats_.clear();
// // }
