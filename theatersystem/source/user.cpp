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

// double User::CalculateReservationTotalPrice()
// {
//     double total(0.0);

//     return total;
// }

// std::string User::UserToString()
// {
//     return "Username: "  + username_ + "Password: " + password_;
// }

// void User:: AddReservation(Show show)
// {
//     reservations_.push_back(show);
// }

// void User:: AddReservation(std::tm date, std::tm time,std::string seatId,std::vector<Show>& showDatabase)
// {
//     Show reservation(time,date);
//     bool addedSeat(false);
//     for(Show& show : showDatabase)
//     {
//         if(reservation.GetDateString() == show.GetDateString() && reservation.GetTimeString() == show.GetTimeString())
//         {
//             for(Seat seat : show.GetSeats())
//             {
//                 if(seat.GetSeatId() == seatId)
//                 {
//                     std::cout << "Found seat: " << seatId << std::endl;
//                     show.UpdateSeatAvailability(seatId,false);
//                     // reservation.AddSeat(seat);

//                     break;
//                 }
//             }
//             break;
//         }
// }
//     // AddReservation(reservation);
//     // if(addedSeat)
//     // {
//     //     for(Show& show : showDatabase)
//     //     {
//     //         if(show.GetDateString() == reservation.GetDateString() && show.GetTimeString() == reservation.GetTimeString())
//     //         {
//     //             show.UpdateSeatAvailability(seatId,false);
//     //             break;
//     //         }
//     //     }
//     // }

// }

// void User::RemoveReservation(std::string showDate, std::string showTime, std::string seatId,std::vector<Show>& showDatabase)
// {
//     bool removedSeat(false);
//     for(Show& show : showDatabase)
//     {
//         if(show.GetDateString() == showDate && show.GetTimeString() == showTime)
//         {
//             // show.UpdateSeatAvailability(seatId,true);
//             for(Seat seat: show.GetSeats())
//             {
//                 if(seat.GetSeatId() == seatId)
//                 {
//                     std::cout << "Found seat: " << seatId << std::endl;
//                     show.UpdateSeatAvailability(seatId,true);
//                     break;
//                 }
//             }
//             // show.RemoveSeat(seatId,removedSeat);
//             break;
//         }
//     }
//     // if(removedSeat)
//     // {
//     //     for(Show& show : showDatabase)
//     //     {
//     //         if(show.GetDateString() == showDate && show.GetTimeString() == showTime)
//     //     {
//     //         show.UpdateSeatAvailability(seatId,true);
//     //         break;
//     //     }
//     //     }
//     // }

// }
// void User::DisplayReservations() const
// {
//     if(!reservations_.empty())
//     {
//         for(Show show : reservations_)
//         {
//             std::cout << show.ToString() << std::endl;
//             show.DisplaySeats();
//         }
//     }
//     else
//     {
//         std::cout << "No reservations" << std::endl;
//     }
// }
// void User::SortReservations() const
// {

// }

// // std::string User::GetUsername() const
// // {
// //     return username_;
// // }
// // std::string User::GetPassword() const
// // {
// //     return password_;
// // }

// // std::string User::UserToString()
// // {
// //     return "Username: " + username_ + " Password: " + password_;
// // }
// // void User::AddReservation(Show reservation)
// // {
// //     reservations_.push_back(reservation);
// // }

// // std::vector<Show> User::GetReservations() const
// // {
// //     return reservations_;
// // }

// // Show User::GetReservation(std::string date,std::string time) const
// // {
// //     Show tmp;
// //     for(Show reservation: reservations_)
// //     {
// //         if(reservation.GetDateString() == date && reservation.GetTimeString() == time)
// //         {
// //             tmp = reservation;
// //             return tmp;
// //         }
// //     }
// //     return tmp;
// // }
// // void User::DisplayReservation(std::string date, std::string time) const
// // {
// //     for(Show reservation : reservations_)
// //     {
// //         if(reservation.GetDateString() == date && reservation.GetTimeString() == time)
// //         {
// //             for(Seat seat : reservation.GetSeats())
// //             {
// //                 std::cout << seat.GetSeatId() << std::endl;
// //             }
// //         }
// //     }
// // }
// // void User::RemoveReservations(Show& show, std::string seatId)
// // {
// //     show.UpdateSeatAvailability(seatId,true);
// // }
// // // void User::RemoveReservations(Show show, std::string seatId)
// // //         {

// // //             for(Show& show: ref)
// // //             {

// // //                 if(show.GetDateString() == showDate && show.GetTimeString() == showTime)
// // //                 {
// // //                     std::cout << "Before;" << std::endl;
// // //                     for(Seat s : show.GetSeats())
// // //                     {
// // //                         std::cout << s.SeatToString() << std::endl;
// // //                     }

// // //                     show.removeallseats();
// // //                     reservations_= ref;

// // //                      std::cout << "after" << std::endl;
// // //                     for(Seat s : show.GetSeats())
// // //                     {
// // //                         std::cout << s.SeatToString() << std::endl;
// // //                     }
// // //                     break;
// // //                 }
// // //             }

// // //             for(Show& show : reservations_)
// // //             {
// // //                 if(show.GetDateString() == showDate && show.GetTimeString() == showTime)
// // //                 {
// // //                     std::vector<Seat>::iterator it;
// // //                     it = show.GetSeats().begin();
// // //                     Seat seat = show.GetSeat(seatId);
// // //                     std::vector<Seat>::iterator it = std::find(show.GetSeats().begin(),show.GetSeats().end(),seat);
// // //                     if(it != show.GetSeats().end())
// // //                     {
// // //                         show.GetSeats().erase(it);

// // //                     }

// // //                 }
// // //             }

// // //             DisplayReservation(showDate,showTime);

// // //         }

// // // void User::RemoveReservation(std::string seatId)
// // // {

// // //     // {
// // //     //     if(s.GetSeatId() == seatId)
// // //     //     {

// // //     //     }
// // //     // }
// // // }
// // // void User::RemoveReservation(std::string seatId, Show reservation, Show& newShow)
// // // {
// // //     auto it = reservation.GetSeats().begin();
// // //     Seat& seat = reservation.GetSeat(seatId); // Fetch the seat once

// // //     while (it != reservation.GetSeats().end())
// // //     {
// // //         if (it->GetSeatId() == seat.GetSeatId())
// // //         {
// // //             seat.SetAvailability(true); // Set the seat's availability
// // //             newShow = reservation;      // Update the newShow with the current reservation state
// // //             it = reservation.GetSeats().erase(it); // Erase the seat and get the new iterator position

// // //             If only one seat should be removed, you can break here
// // //             break;
// // //         }
// // //         else
// // //         {
// // //             ++it; // Only increment the iterator if no element was erased
// // //         }
// // //     }

// // //     UpdateReservations(reservation); // Update reservations after modifying
// // // }

// // // void User::RemoveReservation(std::string seatId,Show reservation,Show& newShow)
// // // {
// // //     std::vector<Seat>::iterator it = reservation.GetSeats().begin();

// // //     for(it; it != reservation.GetSeats().end(); ++it)
// // //     {
// // //         if(it->GetSeatId() == reservation.GetSeat(seatId).GetSeatId())
// // //         {
// // //             reservation.GetSeat(seatId).SetAvailability(true);
// // //             newShow = reservation;
// // //             reservation.GetSeats().erase(it);
// // //         }
// // //     }

// // //     UpdateReservations(reservation);

// // // }

// // void User::UpdateReservations(Show input)
// // {
// //     for(Show& show : reservations_)
// //     {
// //         if(show.GetDateString() == input.GetDateString() && show.GetTimeString() == input.GetTimeString())
// //         {
// //             show.UpdateSeatAvailability("eb100",true);
// //             break;
// //         }
// //     }
// // }
// // void User::clearallreserves()
// // {
// //     reservations_.clear();
// // }

// // // User:: GetReservation(std::string date) const
// // // {
// // //     dummy value in case no reservation is found
// // //     Show reservation;
// // //     for(Show reservation_ : reservations_)
// // //     {
// // //         if(reservation_.GetDateString() == date)
// // //         {
// // //             return reservation_;
// // //         }
// // //     }
// // //     std::cout << "Cannot find reservation!" << std::endl;
// // //     return reservation;
// // // }

// // // std::vector<Show> User:: GetReservations() const
// // // {
// // //     return reservations_;
// // // }
// // //need to sort based on date then time
// // // void User::ViewReservations() const
// // // {
// // //     std::cout << "Viewing reservations" << std::endl;
// // //     for(Show reservation : reservations_)
// // //     {
// // //         std::cout << reservation.ShowToString() << std::endl;
// // //          for(Seat seat : reservation.GetSeats())
// // //          {
// // //             std::cout << seat.SeatToString() << std::endl;
// // //          }
// // //     }

// // // }

// // // std::string User::GetPassword() const
// // // {
// // //     return password_;
// // // }

// // // void User::AddReservation(Show show)
// // // {
// // //     reservations_.push_back(show);
// // // }
// // // void User::ViewReservations() const
// // // {
// // //     for(Show show: reservations_)
// // //     {
// // //         std::cout << show.ShowToString() << std::endl;
// // //         show.DisplaySeats();
// // //     }
// // // }

// // // // bool User::addReservation(const std::string date,const std::string time)
// // // // {
// // // //     const std::string datetime = date + " " + time;

// // // // }

// // // // std::vector<Show*> User::getReservations() const
// // // // {
// // // //     return reservations_;
// // // // }

// // // // bool User::addReservation(Show* new_reservation)
// // // // {
// // // //     reservations_.push_back(new_reservation);
// // // // }
