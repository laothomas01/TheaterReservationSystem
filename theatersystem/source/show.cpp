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
}

std::vector<Seat> Show::GetSeats() const
{
    return seats_;
}

std::tm Show::GetTime()
{
    return time_;
}
std::tm Show::GetDate()
{
    return date_;
}

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
}
