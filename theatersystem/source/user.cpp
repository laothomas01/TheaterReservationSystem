#include "user.h"

User::User(std::string username, std::string password) : username_(username), password_(password)
{
}

User::~User()
{
}

std::string User::GetUsername() const
{
    return username_;
}

std::string User::GetPassword() const
{
    return password_;
}

std::string User::ToString() const
{
    return username_ + "|" + password_;
}
void User::SetPassword(const std::string password)
{
    password_ = password;
    std::cout << "Done setting password" << std::endl;
}

void User::AddReservation(Show show)
{
    std::string dateTime = show.GetDateString() + show.GetTimeString();
    reservations.insert({dateTime, show});
}

void User::DisplayReservations()
{
    std::vector<Show> sortedReservations = SortReservations();
    for (Show show : sortedReservations)
    {
        std::cout << show.ToString() << std::endl;
        show.DisplaySeats();
    }
}

std::vector<Show> User::SortReservations()
{
    std::vector<Show> sortedReservations;
    if (!reservations.empty())
    {
        std::map<std::string, Show>::iterator iter = reservations.begin();
        while (iter != reservations.end())
        {
            sortedReservations.push_back(iter->second);
            ++iter;
        }
    }

    std::sort(sortedReservations.begin(), sortedReservations.end(), CompareShows);

    return sortedReservations;
}

Show *User::FindReservation(std::string date, std::string time)
{
    std::map<std::string, Show>::iterator iter = reservations.begin();
    while (iter != reservations.end())
    {
        if (iter->second.GetDateString() == date && iter->second.GetTimeString() == time)
        {
            return &iter->second;
        }
        ++iter;
    }
    return nullptr;
}
void User::CancelReservation(std::string date, std::string time, std::string seatId)
{
    Show *reservation = FindReservation(date, time);
    reservation->RemoveSeat(seatId);
}

unsigned int User::GetReservationSize() const
{
    return reservations.size();
}
std::map<std::string,Show> User::GetReservations() const 
{
    return reservations;
}
