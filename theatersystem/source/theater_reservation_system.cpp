

// std::vector<std::string> TheaterReservationSystem::SingleDelimeterStringSplit(std::string str, char delimeter)
// {
//     std::vector<std::string> tokens;
//     std::string token;
//     std::stringstream ss(str);
//     while(std::getline(ss,token,delimeter))
//     {
//         tokens.push_back(token);
//     }
//     return tokens;
// }

// void TheaterReservationSystem:: AddUser(std::string username, std::string password)
// {
//     if(IsUsernameTaken(username,password))
//     {
//         std::cout << "Username is already taken" << std::endl;
//     }
//     else
//     {
//         std::cout << "Successfully created account" << std::endl;
//         User user(username,password);
//         userDatabase_.push_back(user);
//     }
// }

// bool TheaterReservationSystem:: IsUsernameTaken(std::string username, std::string password)
// {
//     for(User user : userDatabase_)
//     {
//         if(user.GetUsername() == username && user.GetPassword() == password)
//         {
//             return true;
//         }
//     }
//     return false;
// }

/*
features:
[] sign up
[] sign in
[] exit system
[] transaction mode
    [] reservation session
    [] view entire reservations
    [] cancel reservation
    [] out
        [] display receipt for the transaction
        [] handle group discounts
    [] load data from .txt file
 */
#include "theater_reservation_system.h"

TheaterReservationSystem ::TheaterReservationSystem()
{
}
TheaterReservationSystem ::~TheaterReservationSystem()
{
}

void TheaterReservationSystem::LoadSystem(std::string filename)
{
    std::cout << "Load System...." << std::endl;

    std::ifstream myfile;
    myfile.open(filename);
    std::string mystring;
    std::string myline;

    if (myfile.is_open())
    {
        while (myfile)
        {
            std::getline(myfile, myline);
            std::cout << myline << '\n';
        }
    }
    else
    {
        // File doesnt' exist
        // load all initial data
        std::tm start_date = {};
        std::tm end_date = {};
        std::tm six_thirty_schedule = {};
        std::tm eight_thirty_schedule = {};
        start_date.tm_year = 2020 - 1900; // tm_year is years since 1990
        start_date.tm_mon = 12 - 1;
        start_date.tm_mday = 23;

        six_thirty_schedule.tm_hour = 6;
        six_thirty_schedule.tm_min = 30;

        end_date.tm_year = 2021 - 1900;
        end_date.tm_mon = 1 - 1;
        end_date.tm_mday = 2;

        eight_thirty_schedule.tm_hour = 8;
        eight_thirty_schedule.tm_min = 30;

        std::string seatFloors[] = {"m", "sb", "wb", "eb"};
        std::tm current_date = start_date;

        while (std::mktime(&current_date) <= std::mktime(&end_date))
        {
            Show show(six_thirty_schedule, current_date);

            for (std::string floor : seatFloors)
            {
                if (floor == "m")
                {
                    for (int i = 1; i < 151; i++)
                    {
                        if (i > 100 && i < 151)
                        {
                            // std::cout << current_date.tm_mday << std::endl;
                            if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                            {
                                Seat seat(floor + std::to_string(i), 20.00, true);
                                show.AddSeat(seat);
                            }
                            else
                            {
                                Seat seat(floor + std::to_string(i), 45.00, true);
                                show.AddSeat(seat);
                            }
                        }
                        else
                        {
                            if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                            {
                                Seat seat(floor + std::to_string(i), 20.00, true);
                                show.AddSeat(seat);
                            }
                            else
                            {
                                Seat seat(floor + std::to_string(i), 35.00, true);
                                show.AddSeat(seat);
                            }
                        }
                    }
                }
                else if (floor == "sb")
                {
                    for (int i = 1; i < 51; i++)
                    {
                        if (i > 25 && i < 51)
                        {
                            if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                            {
                                Seat seat(floor + std::to_string(i), 20.00, true);
                                show.AddSeat(seat);
                            }
                            else
                            {
                                Seat seat(floor + std::to_string(i), 55.00, true);
                                show.AddSeat(seat);
                            }
                        }
                        else
                        {

                            if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                            {
                                Seat seat(floor + std::to_string(i), 20.00, true);
                                show.AddSeat(seat);
                            }
                            else
                            {
                                Seat seat(floor + std::to_string(i), 50.00, true);
                                show.AddSeat(seat);
                            }
                        }
                    }
                }
                else if (floor == "wb")
                {
                    for (int i = 1; i < 101; i++)
                    {
                        if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                        {
                            Seat seat(floor + std::to_string(i), 20.00, true);
                            show.AddSeat(seat);
                        }
                        else
                        {
                            Seat seat(floor + std::to_string(i), 40.00, true);
                            show.AddSeat(seat);
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < 101; i++)
                    {
                        if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                        {
                            Seat seat(floor + std::to_string(i), 20.00, true);
                            show.AddSeat(seat);
                        }
                        else
                        {
                            Seat seat(floor + std::to_string(i), 40.00, true);
                            show.AddSeat(seat);
                        }
                    }
                }
            }
            AddShow(show);
            AddOneDay(current_date);
        }
        current_date = start_date;
        while (std::mktime(&current_date) <= std::mktime(&end_date))
        {
            Show show(eight_thirty_schedule, current_date);
            for (std::string floor : seatFloors)
            {
                if (floor == "m")
                {
                    for (int i = 1; i < 151; i++)
                    {
                        if (i > 100 && i < 151)
                        {
                            if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                            {
                                Seat seat(floor + std::to_string(i), 20.00, true);
                                show.AddSeat(seat);
                            }
                            else
                            {
                                Seat seat(floor + std::to_string(i), 45.00, true);
                                show.AddSeat(seat);
                            }
                        }
                        else
                        {
                            if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                            {
                                Seat seat(floor + std::to_string(i), 20.00, true);
                                show.AddSeat(seat);
                            }
                            else
                            {
                                Seat seat(floor + std::to_string(i), 35.00, true);
                                show.AddSeat(seat);
                            }
                        }
                    }
                }
                else if (floor == "sb")
                {
                    for (int i = 1; i < 51; i++)
                    {
                        if (i > 25 && i < 51)
                        {
                            if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                            {
                                Seat seat(floor + std::to_string(i), 20.00, true);
                                show.AddSeat(seat);
                            }
                            else
                            {
                                Seat seat(floor + std::to_string(i), 55.00, true);
                                show.AddSeat(seat);
                            }
                        }
                        else
                        {

                            if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                            {
                                Seat seat(floor + std::to_string(i), 20.00, true);
                                show.AddSeat(seat);
                            }
                            else
                            {
                                Seat seat(floor + std::to_string(i), 50.00, true);
                                show.AddSeat(seat);
                            }
                        }
                    }
                }
                else if (floor == "wb")
                {
                    for (int i = 1; i < 101; i++)
                    {
                        if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                        {
                            Seat seat(floor + std::to_string(i), 20.00, true);
                            show.AddSeat(seat);
                        }
                        else
                        {
                            Seat seat(floor + std::to_string(i), 40.00, true);
                            show.AddSeat(seat);
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < 101; i++)
                    {
                        if (current_date.tm_mon == 11 && (current_date.tm_mday == 26 || current_date.tm_mday == 27))
                        {
                            Seat seat(floor + std::to_string(i), 20.00, true);
                            show.AddSeat(seat);
                        }
                        else
                        {
                            Seat seat(floor + std::to_string(i), 40.00, true);
                            show.AddSeat(seat);
                        }
                    }
                }
            }

            AddShow(show);
            AddOneDay(current_date);
        }
    }

    std::cout << "Done loading system" << std::endl;
}

void TheaterReservationSystem::AddOneDay(std::tm &tm)
{
    const time_t ONE_DAY = 24 * 60 * 60; // seconds in a day
    std::time_t date_time = std::mktime(&tm);
    date_time += ONE_DAY;
    tm = *std::localtime(&date_time);
}

void TheaterReservationSystem::AddShow(Show show)
{
    showDatabase_.push_back(show);
}

void TheaterReservationSystem::AddUser(User user)
{
    userDatabase_.push_back(user);
}
void TheaterReservationSystem::DisplayShows() const
{
    for (Show show : showDatabase_)
    {
        std::cout << show.ToString() << std::endl;
    }
}

void TheaterReservationSystem::DisplayUsers() const
{
    for (User user : userDatabase_)
    {
        std::cout << user.ToString() << std::endl;
    }
}
bool TheaterReservationSystem::HasUser(std::string username)
{
    for (User user : userDatabase_)
    {
        if (user.GetUsername() == username)
        {
            return true;
        }
    }
    return false;
}

void TheaterReservationSystem::DisplayShowSeats(const std::string &showDate, const std::string &showTime)
{
    Show *show = findShow(showDate, showTime);
    show->DisplaySeats();
}

User *TheaterReservationSystem::FindUserLogin(const std::string &username, const std::string &password)
{
    for (auto &user : userDatabase_)
    {
        if (user.GetUsername() == username && user.GetPassword() == password)
        {
            std::cout << "Found user" << std::endl;
            return &user;
        }
    }
    std::cout << "Login Invalid" << std::endl;
    return nullptr;
}

Show *TheaterReservationSystem::findShow(const std::string &showDate, const std::string &showTime)
{
    for (auto &show : showDatabase_)
    {
        if (show.GetDateString() == showDate && show.GetTimeString() == showTime)
        {
            return &show;
        }
    }
    return nullptr; // Show not found
}

// Function to reserve a seat
void TheaterReservationSystem::reserveSeat(const std::string &showDate, const std::string &showTime, std::string seatId)
{
    Show *show = findShow(showDate, showTime);
    if (show)
    {
        Seat *seat = show->findSeat(seatId);
        if (seat)
        {
            seat->Reserve();
        }
        else
        {
            std::cout << "Seat not found!" << std::endl;
        }
    }
    else
    {
        std::cout << "Show not found!" << std::endl;
    }
}

void TheaterReservationSystem::UpdateSeatAvailability(Show *show, bool avail, std::string seatId)
{
    show->UpdateSeatAvailability(avail, seatId);
}

void TheaterReservationSystem::UpdateSeatAvailability(bool available, const std::string &showDate, const std::string &showTime, const std::string &seatId)
{
    Show *show = findShow(showDate, showTime);
    if (show)
    {
        show->UpdateSeatAvailability(available, seatId);
    }
}

void TheaterReservationSystem::Start(bool start)
{
    LoadSystem("");
    User user("a", "b");
    AddUser(user);
    User *login = FindUserLogin("a", "b");
    ReserveSeats(login);
    login->DisplayReservations();
}
void TheaterReservationSystem::InitialMenu(bool start)
{
    while (start)
    {
        std::cout << "Sign [U]p E[X]it Sign [I]n" << std::endl;
        char choice(' ');
        std::cin >> choice;
        choice = (std::toupper(choice));
        switch (choice)
        {
        case 'U':
            SignUp();
            break;
        case 'I':
            break;
        case 'X':
            break;
        }
    }
}
void TheaterReservationSystem::SignUp()
{
    while (true)
    {
        std::string username("");
        std::string password("");
        std::cout << "Enter a username: (or press Q to quit)" << std::endl;
        std::cin >> username;
        if (username == "Q" || username == "q")
        {
            break;
        }
        std::cout << "Enter a password: (or press Q to quit)" << std::endl;
        std::cin >> password;
        if (password == "Q" || username == "q")
        {
            break;
        }
        if (HasUser(username))
        {
            std::cout << "Username is already taken" << std::endl;
        }
        else
        {
            User user(username, password);
            AddUser(user);
            std::cout << "User has been successfully created" << std::endl;
        }
    }
}
void TheaterReservationSystem::SignIn()
{
    while (true)
    {
        std::string username("");
        std::string password("");
        std::cout << "Enter a username: (or press Q to quit)" << std::endl;
        std::cin >> username;

        if (username == "Q" || username == "q")
        {
            break;
        }
        std::cout << "Enter a password: (or press Q to quit)" << std::endl;
        std::cin >> password;
        if (password == "Q" || username == "q")
        {
            break;
        }
        if (HasUser(username))
        {
            User *login = FindUserLogin(username, password);
            ReserveSeats(login);
            // when user finishes reservation session, break out of sign in page
            break;
        }
        else
        {
            std::cout << "Invalid Login" << std::endl;
        }
    }
}
void TheaterReservationSystem::TransactionMode(User *user)
{
    while (true)
    {
        std::cout << "[R]eserve    [V]iew    [C]ancel    [O]ut" << std::endl;
        char choice(' ');
        std::cin >> choice;
        choice = (std::toupper(choice));
        switch (choice)
        {
        case 'R':
            ReserveSeats(user);
            break;
        case 'V':
            break;
        case 'C':
            break;
        case 'O':
            break;
        }
    }
}
void TheaterReservationSystem::ViewReservations(User *user)
{
    user->DisplayReservations();
}
void TheaterReservationSystem::ReserveSeats(User *user)
{

    // std::map<std::string, std::vector<std::string>> reservations;

    // // this entire session is 1 transaction session
    // // this means all seats are currently available until end of reservation session and end of transaction session
    // // lets do 2 reservation sessions

    std::cout << "Reservation Session 1" << std::endl;
    DisplayShows();
    std::string date("");
    std::string time("");

    std::map<std::string, std::vector<std::string>> reservations;
    while (true)
    {
        std::cout << "Enter a date: " << std::endl;
        std::cin >> date;
        std::cout << "Enter a time: " << std::endl;
        std::cin >> time;
        Show *show = findShow(date, time);
        std::vector<std::string> selectedSeats;

        if (show)
        {
            show->DisplaySeats();
            bool selectingSeats(true);
            bool done(false);

            while (selectingSeats)
            {
                std::cout << "Enter a seat to reserve: ( Enter Q to finish) " << std::endl;

                std::string seatId("");
                std::cin >> seatId;
                if (seatId == "Q" || seatId == "q")
                {
                    if (!selectedSeats.empty())
                    {
                        std::string dateTime = date + " " + time;
                        reservations[dateTime].insert(reservations[dateTime].end(), selectedSeats.begin(), selectedSeats.end());
                    }

                    break;
                }

                Seat *seat = show->findSeat(seatId);
                if (seat)
                {
                    if (seat->IsAvailabile())
                    {
                        if (std::find(selectedSeats.begin(), selectedSeats.end(), seatId) != selectedSeats.end())
                        {
                            std::cout << "You already selected this seat" << std::endl;
                        }
                        else
                        {
                            selectedSeats.push_back(seatId);
                        }
                    }
                    else
                    {
                        std::cout << "Seat unavailable" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Cannot find seat" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Cannot find show" << std::endl;
        }

        std::cout << "Do you want to make another reservation? (Y/N)" << std::endl;
        char choice(' ');
        std::cin >> choice;
        choice = (std::toupper(choice));
        if (choice == 'N')
        {
            for (const auto &entry : reservations)
            {
                const std::string &datetime = entry.first;
                const std::vector<std::string> &seats = entry.second;
                std::size_t spacePos = datetime.find(' ');
                if (spacePos != std::string::npos)
                {
                    // Extract date and time
                    std::string dateString = datetime.substr(0, spacePos);
                    std::string timeString = datetime.substr(spacePos + 1);
                    // Output the reserved seats
                    std::cout << dateString << std::endl;
                    std::cout << timeString << std::endl;
                    Show *currentShow = findShow(dateString, timeString);

                    std::tm tm_date = {};
                    std::istringstream ss(dateString);
                    ss >> std::get_time(&tm_date, "%Y-%m-%d");
                    if (ss.fail())
                    {
                        std::cerr << "Failed to parse date!" << std::endl;
                        break;
                    }
                    // Convert the parsed date to a time_t value
                    std::time_t date = std::mktime(&tm_date);
                    std::cout << "Checking year" << std::endl;
                    std::cout << tm_date.tm_year + 1900 << std::endl;

                    std::tm tm_time = {};
                    std::istringstream ss2(timeString);
                    ss2 >> std::get_time(&tm_time, "%H:%M");
                    if (ss2.fail())
                    {
                        std::cerr << "Failed to parse time!" << std::endl;
                        break;
                    }
                    std::time_t time = std::mktime(&tm_time);
                    Show reservation(tm_time, tm_date);
                    for (std::string seatId : seats)
                    {
                        reserveSeat(dateString, timeString, seatId);
                        Seat *seat = currentShow->findSeat(seatId);
                        if (seat)
                        {
                            reservation.AddSeat(*seat);
                        }
                    }
                    user->AddReservation(reservation);
                }
            }
            break;
        }
    }
    // std::string date("2020-12-23");
    // std::string time("06:30");

    // // UpdateSeatAvailability(false,"eb100");
    // Show *show = findShow(date, time);
    // if (show)
    // {
    //     std::vector<std::string> selectedSeats;
    //     Seat *seat1 = show->findSeat("eb100");
    //     Seat *seat2 = show->findSeat("eb98");
    //     Seat *seat3 = show->findSeat("eb98");
    //     // UpdateSeatAvailability(false,seat1->GetSeatId());

    //     selectedSeats.push_back(seat2->GetSeatId());
    //     selectedSeats.push_back(seat3->GetSeatId());

    //     // if(!seat1->IsAvailabile())
    //     // {
    //     //     std::cout << "Not Available" << std::endl;
    //     // }
    //     // else
    //     // {
    //     //     selectedSeats.push_back()
    //     // }

    //     // test already selecting seat
    //     if (std::find(selectedSeats.begin(), selectedSeats.end(), "eb100") != selectedSeats.end())
    //     {
    //         std::cout << "You already selected this seat" << std::endl;
    //     }
    //     // Done reserving seats
    //     if (!selectedSeats.empty())
    //     {
    //         std::string datetime = date + " " + time;
    //         reservations[datetime].insert(reservations[datetime].end(), selectedSeats.begin(), selectedSeats.end());
    //     }

    //     for (const auto &entry : reservations)
    //     {
    //         const std::vector<std::string> &seats = entry.second;
    //         for (std::string id : seats)
    //         {
    //             std::cout << id << std::endl;
    //         }
    //     }
    //     // are you done making reservations?

    //     // no. let's do one more.
    // }
    // date = "2020-12-24";
    // time = "08:30";
    // show = findShow(date, time);

    // //                 {
    //                     break;
    //                 }
    //                 else
    //                 {
    //                     std::cout << "Invalid Input" << std::endl;
    //                 }
    //             }
    //         }
    //     }
    //     else
    //     {
    //         std::cout << "Invalid show" << std::endl;
    //     }

    //     std::cout << "Do you want to make another reservation? [Y/N]" << std::endl;
    //     char choice(' ');
    //     std::cin >> choice;
    //     choice = (std::toupper(choice));

    //     if (choice == 'N')
    //     {
    //         for (const auto &entry : reservations)
    //         {
    //             const std::string &datetime = entry.first;
    //             const std::vector<std::string> &seats = entry.second;
    //             // Find the space position in the datetime string
    //             std::size_t spacePos = datetime.find(' ');
    //             if (spacePos != std::string::npos)
    //             {
    //                 // Extract date and time
    //                 std::string date = datetime.substr(0, spacePos);
    //                 std::string time = datetime.substr(spacePos + 1);
    //                 // Output the reserved seats
    //                 std::cout << date << std::endl;
    //                 std::cout << time << std::endl;
    //                 Show *tmp = findShow(date, time);
    //                 Show reservation(tmp->GetTime(), tmp->GetDate());
    //                 for (std::string seatId : seats)
    //                 {
    //                     Seat* seat = tmp->findSeat(seatId);
    //                     UpdateSeatAvailability(false,seat->GetSeatId());
    //                     // reservation.AddSeat(*seat);
    //                     // std::cout << seat->ToString() << std::endl;
    //                 }
    //                 // user->AddReservation(reservation);
    //             }
    //         }
    //         break;
    //     }

    // }
}

// void TheaterReservationSystem::UpdatePassword(std::string username, std::string password)
// {
// }
// void TheaterReservationSystem::DisplayShows() const
// {
//     for(Show show : showDatabase_)
//     {
//         std::cout << show.ShowToString() << std::endl;
//     }
// }

// void TheaterReservationSystem:: Start(bool start,std::string filename)
// {
//     LoadSystem(filename);
//     while(start)
//     {
//         std::cout << "Sign[U]p Sign[I]n E[X]it" << std::endl;
//         char choice{' '};
//         std::cin >> choice;
//         choice = (std::toupper(choice));
//         switch(choice)
//         {
//             case 'U':
//                 std::cout << "SignUp" << std::endl;
//                 SignUp(true);
//                 break;
//             case 'I':
//                 std::cout << "SignIn" << std::endl;
//                 SignIn(true);
//                 break;
//             case 'X':
//                 std::cout << "Exit" << std::endl;
//                 break;
//             default:
//                 std::cout << "Invalid Input" << std::endl;
//         }
//     }
// }

// void TheaterReservationSystem:: SignUp(bool start)
// {
//     while(start)
//     {
//         std::string username{""};
//         std::string password{""};
//         std::cout << "Enter a username: (or press Q to quit)" << std::endl;
//         std::cin >> username;
//         if(username == "q" || username == "Q")
//         {
//             break;
//         }
//         std::cout << "Enter a password: (or press Q to quit)" << std::endl;
//         std::cin >> password;

//         if(password == "q" || password == "Q")
//         {
//             break;
//         }

//         if(HasUsername(username,password))
//         {
//             std::cout << "Username already taken!" << std::endl;
//         }
//         else
//         {
//             AddUser(username,password);
//         }
//     }
// }
// void TheaterReservationSystem::SignIn(bool start)
// {
//     while(start)
//     {
//         std::string username{""};
//         std::string password{""};
//         std::cout << "Enter a username: (or press Q to quit)" << std::endl;
//         std::cin >> username;
//         if(username == "q" || username == "Q")
//         {
//             break;
//         }
//         std::cout << "Enter a password: (or press Q to quit)" << std::endl;
//         std::cin >> password;

//         if(password == "q" || password == "Q")
//         {
//             break;
//         }

//         if(HasUsername(username,password))
//         {
//             std::vector<User>::iterator userIter = userDatabase_.begin();
//             while(userIter != userDatabase_.end())
//             {
//                 if(userIter->GetUsername() == username && userIter->GetPassword() == password)
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     ++userIter;
//                 }
//             }
//             std::cout << userIter->UserToString() << std::endl;
//             TransactionMode(start,*userIter);
//         }
//         else
//         {
//             std::cout << "Invalid Login" << std::endl;
//         }

//     }
// }
// void TheaterReservationSystem::TransactionMode(bool start, User user)
// {
//      while(start)
//     {
//         std::cout << "[R]eserve    [V]iew    [C]ancel    [O]ut" << std::endl;
//         char choice{' '};
//         std::cin >> choice;
//         choice = (std::toupper(choice));
//         switch(choice)
//         {
//             case 'R':
//                 std::cout << "Reserve" << std::endl;
//                 ReservationSession(true,user);
//                 break;
//             case 'V':
//                 std::cout << "View" << std::endl;
//                 ViewReservations(true,user);
//                 break;
//             case 'C':
//                 std::cout << "Cancel" << std::endl;
//                 CancelReservation(true,user);
//                 break;
//             case 'O':
//                 std::cout << "Out" << std::endl;
//                 break;
//             default:
//                 std::cout << "Invalid Input" << std::endl;
//                 break;
//         }
//     }
// }
// std::vector<Show> TheaterReservationSystem::GetShows() const
// {
//     return showDatabase_;
// }
// void TheaterReservationSystem::ReservationSession(bool start,User& user)
// {
//     // std::unordered_map<std::string,std::vector<std::string>>reservations;

//     //going to read show date data mapped to vector of reserved seats

//     //will iterate through data and populate user's reservations

//     std::unordered_map<std::string,std::vector<std::string>> reservationString;
//     std::vector<std::string> chosenSeats;

//     while(start)
//     {
//         std::string dateString("");
//         std::string timeString("");
//         DisplayShows();
//         std::cout << "Enter a date" << std::endl;
//         std::cin >> dateString;
//         std::cout << "Enter a time" << std::endl;
//         std::cin >> timeString;

//         if(IsValidShow(dateString,timeString))
//         {
//             Show currentShow;
//             for(Show show : showDatabase_)
//             {
//                 if(show.GetDateString() == dateString && show.GetTimeString() == timeString)
//                 {
//                     currentShow = show;
//                     break;
//                 }
//             }
//             currentShow.DisplaySeats();
//             bool selectingSeats(false);

//             //we are selecting seats

//             // //if seat can be found in data base, insert date time : vector<string> to map of seat reservations
//             while(selectingSeats)
//             {
//                 std::cout << "Enter a seatId: (or press Q to quit) " << std::endl;
//                 std::string seatId("");
//                 std::cin >> seatId;
//                 if(seatId == "Q" || seatId == "q")
//                 {
//                     break;
//                 }
//                 else if(currentShow.IsValidSeat(seatId))
//                 {
//                     if(currentShow.GetSeat(seatId).IsAvailabile())
//                     {
//                         bool alreadySelectedSeat(false);
//                         for(std::string id: chosenSeats)
//                         {
//                             if(id == seatId)
//                             {
//                                 alreadySelectedSeat = true;
//                                 break;
//                             }

//                         }
//                         if(alreadySelectedSeat)
//                         {
//                             std::cout << "Already selected seat";
//                         }
//                         else
//                         {
//                             chosenSeats.push_back(seatId);
//                         }
//                         // std::string dateTime = dateString + "|" + timeString;

//                         // std::unordered_map<std::string,std::vector<std::string>>::iterator itr = reservationString.find(dateTime);
//                         // if(itr == reservationString.end())
//                         // {
//                         //     std::vector<std::string> emptyVector;
//                         //     reservationString.insert({dateTime,emptyVector});

//                         // }
//                         // else
//                         // {

//                         // }

//                         // selectedSeats.push_back(seatId);
//                     }
//                     else
//                     {
//                         std::cout << "Seat unavailable." << std::endl;
//                     }

//                     std::cout << "Done selecting seats(Y/N)?" << std::endl;
//                     char choice{' '};
//                     std::cin >> choice;
//                     choice = (std::toupper(choice));
//                     bool selectingChoice(true);
//                     while(selectingChoice)
//                     {
//                         if(choice == 'Y')
//                         {

//                         }
//                         else if(choice =='N')
//                         {

//                         }
//                         else
//                         {
//                             std::cout << "Invalid Input" << std::endl;
//                         }
//                     }
//                 // while(s                  char choice{' '};
//                     std::cin >> choice;
//                     choice = (std::toupper(choice));
//                     bool selectingChoice(true);electingChoice)
//                 // {
//                 //     if(choice == 'Y')
//                 //     {
//                 //         selectingSeats = false;
//                 //         std::cout << "Done reserving for show:\nDate: " << dateString<<"\nTime: " << timeString << std::endl;
//                 //         std::string dateTimeString = dateString + "|" + timeString;
//                 //         std::vector<std::string> emptyVector;
//                 //         reservationString.insert({dateTimeString,emptyVector});
//                 //         std::unordered_map<std::string,std::vector<std::string>>::iterator itr = reservationString.find(dateTimeString);
//                 //         if(itr == reservationString.end())
//                 //         {

//                 //         }

//                 //         break;
//                 //     }
//                 //     else if(choice == 'N')
//                 //     {
//                 //         selectingChoice = false;
//                 //     }
//                 //     else
//                 //     {
//                 //         std::cout << "Invalid choice" << std::endl;
//                 //     }
//                 // }
//                 }
//                 else
//                 {
//                     std::cout << "Cannot find seat" << std::endl;
//                 }

//             }

//         }
//         else
//         {
//             std::cout << "Cannot find show" << std::endl;
//         }

//         std::cout << "Are you done making reservations? [Y/N]" << std::endl;
//         char choice{' '};
//         std::cin >> choice;
//         choice = (std::toupper(choice));
//         bool selectingChoice(true);
//         while(selectingChoice)
//         {
//             if(choice == 'Y')
//         {
//             selectingChoice = false;
//             start = false;
//         }
//         else if(choice == 'N')
//         {
//             selectingChoice = false;

//         }
//         else
//         {
//             std::cout << "Invalid choice" << std::endl;
//         }
//         }

//         // if(IsValidShow(dateString,timeString))
//         // {
//         //     std::cout << "Found Valid Show" << std::endl;

//         //     Show currentShow;
//         //     for(Show show : GetShows())
//         //     {
//         //         if(show.GetDateString() == dateString && show.GetTimeString() == timeString)
//         //         {
//         //             currentShow = show;
//         //             break;
//         //         }
//         //     }
//         //     bool selectingSeats(true);
//         //     while(selectingSeats)
//         //     {
//         //         currentShow.DisplaySeats();
//         //         std::cout << "Select a seat: (or press Q to quit) " << std::endl;
//         //         std::string seatId("");
//         //         std::cin >> seatId;
//         //         if(seatId == "Q" || seatId == "q")
//         //         {
//         //             break;
//         //         }

//         //         for(Seat s : currentShow.GetSeats())
//         //         {
//         //             if(s.GetSeatId() == seatId)
//         //             {
//         //                 if(s.IsAvailabile())
//         //                 {
//         //                     seatReservations.push_back(seatId);
//         //                 }
//         //                 else
//         //                 {
//         //                     std::cout << "Seat unavailable" << std::endl;
//         //                 }
//         //             }
//         //                 break;
//         //         }
//         //     }

//         //     std::cout << currentShow.GetDateString();
//         //     std::cout << currentShow.GetTimeString();
//         // }
//         // else
//         // {
//         //     std::cout << "Cannot find show" << std::endl;
//         // }
//     }
// /*

// reservatons:
// date | time : reservations { a,b,c,....n }

// loop:
//     enter date
//     enter time
//     if date == q or Q:
//         if

// */
//     // while(start)
//     // {
//     //     DisplayShows();

//     //     std::string date("");
//     //     std::string time("");
//     //     std::vector<std::string> selectedSeats;

//     //     std::cout << "Enter a show date:(Enter Q to quit) " << std::endl;
//     //     std::cin >> date;
//     //     if(time == "Q" || time == "q")
//     //     {
//     //         std::cout << "Goodbye" << std::endl;
//     //         if(!reservations.empty())
//     //         {
//     //             std::unordered_map<std::string,std::vector<std::string>>::iterator datetimeIter = reservations.begin();
//     //             while(datetimeIter != reservations.end())
//     //             {
//     //                 std::string dateTime = datetimeIter->first;
//     //                 std::vector<std::string> splitDateTime = SingleDelimeterStringSplit(dateTime,'|');
//     //                 std::cout << splitDateTime.size();

//     //             }
//     //         }
//     //         break;
//     //     }

//     //     std::cout << "Enter a show time:(Enter Q to quit) " << std::endl;
//     //     std::cin >> time;

//     //     if(time == "Q" || time == "q")
//     //     {
//     //         std::cout << "Goodbye" << std::endl;
//     //         if(!reservations.empty())
//     //         {
//     //             std::unordered_map<std::string,std::vector<std::string>>::iterator datetimeIter = reservations.begin();
//     //             while(datetimeIter != reservations.end())
//     //             {
//     //                 std::string dateTime = datetimeIter->first;
//     //                 std::vector<std::string> splitDateTime = SingleDelimeterStringSplit(dateTime,'|');
//     //                 std::cout << splitDateTime.size();

//     //             }
//     //         }
//     //         break;
//     //     }

//     //     std::vector<Show>::iterator showIter = showDatabase_.begin();
//     //     if(IsValidShow(date,time))
//     //     {
//     //         while(showIter != showDatabase_.end())
//     //         {
//     //             if(showIter->GetDateString() == date && showIter->GetTimeString() == time)
//     //             {
//     //                 break;
//     //             }
//     //             else
//     //             {
//     //                 ++showIter;
//     //             }
//     //         }
//     //         bool selectingSeats(true);
//     //         while(selectingSeats)
//     //         {
//     //             showIter->DisplaySeats();
//     //             std::cout << "Enter a seatId: " << std::endl;
//     //             std::string seatId("");
//     //             std::cin >> seatId;
//     //             if(showIter->IsValidSeat(seatId))
//     //             {
//     //                 for(Seat s : showIter->GetSeats())
//     //                 {
//     //                     if(s.GetSeatId() == seatId)
//     //                     {

//     //                     }
//     //                 }
//     //             }

//     //         }
//     //     }

//         // if(IsValidShow(date,time))
//         // {
//         //     while(showIter != showDatabase_.end())
//         //     {
//         //         if(showIter->GetDateString() == date && showIter->GetTimeString() == time)
//         //         {
//         //             break;
//         //         }
//         //         else
//         //         {
//         //             ++showIter;
//         //         }
//         //     }

//         //     showIter->DisplaySeats();
//         //     bool selectingSeats(true);
//         //     while(selectingSeats)
//         //     {
//         //         std::cout << "Enter a seat Id: (Enter Q to quit) " << std::endl;
//         //         std::string seatId("");
//         //         std::cin >> seatId;
//         //         if(seatId == "Q" || seatId == "q")
//         //         {
//         //             std::cout << "Done selecting" << std::endl;
//         //             break;
//         //         }
//         //         bool seatTaken(false);
//         //         for(std::string selection : reservations)
//         //         {
//         //             if(selection == seatId)
//         //             {
//         //                 std::cout << "Seat has already been selected!" << std::endl;
//         //                 seatTaken = true;
//         //                 break;
//         //             }
//         //         }
//         //         if(!seatTaken)
//         //         {
//         //             reservations.push_back(seatId);
//         //         }

//         //     }
//         // }
//         // else
//         // {
//         //     std::cout << "Cannot find show" << std::endl;
//         // }

//         // bool selectingSeats{true};
//         // std::vector<std::string> reservedSeatIds;

//         // while(selectingSeats)
//         // {
//         //     std::cout << "Select a seat: " << std::endl;
//         //     std::string seatId{""};
//         //     std::cin >> seatId;
//         //     if(show.GetSeat(seatId).GetAvailability() == false)
//         //     {
//         //         std::cout << "Seat is unavailable" << std::endl;
//         //     }
//         //     else
//         //     {
//         //         reservedSeatIds.push_back(seatId);
//         //     }
//         //     char choice{' '};
//         //     bool continuing{true};
//         //     std::cout << "Continue? [Y/N]" << std::endl;
//         //     std::cin >> choice;
//         //     choice = (std::toupper(choice));
//         //     while(continuing)
//         //     {
//         //         if(choice == 'N')
//         //         {
//         //             continuing = false;
//         //             selectingSeats = false;
//         //             for(std::string seatId : reservedSeatIds)
//         //             {
//         //                 show.UpdateSeatAvailability(seatId,false);
//         //                 reservation.AddSeat(show.GetSeat(seatId));
//         //             }
//         //             UpdateShow(show);
//         //         }
//         //         else if(choice == 'Y')
//         //         {
//         //             continuing = false;
//         //         }
//         //         else
//         //         {
//         //             std::cout << "Invalid Input" << std::endl;
//         //         }
//         //     }

//         // }
//         // user.AddReservation(reservation);
//     // }
// }
// void TheaterReservationSystem::ViewReservations(bool start, User user) const
// {

// }
// void TheaterReservationSystem::CancelReservation(bool start,User user)
// {

// }
// void TheaterReservationSystem::UpdateShow(Show show)
// {

// }
// bool TheaterReservationSystem:: HasUsername(std::string username,std::string password)
// {
//     for(User user : userDatabase_)
//     {
//         if(user.GetUsername() == username && user.GetPassword() == password)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// bool TheaterReservationSystem:: IsValidShow(std::string showDate, std::string showTime)
// {
//     for(Show show : showDatabase_)
//     {
//         if(show.GetDateString() == showDate && show.GetTimeString() == showTime)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// // void TheaterReservationSystem:: SignUp(bool start)
// // {
// //     while(start)
// //     {
// //         std::string username{""};

// //         std::string password{""};
// //         std::cout << "Enter a username: " << std::endl;
// //         std::cin >> username;
// //         std::cout << "Enter a password: " << std::endl;
// //         std::cin >> password;
// //         bool usernameTaken{false};
// //         for(User user: userDatabase_)
// //         {
// //             if(user.GetUsername() == username)
// //             {
// //                 usernameTaken = true;
// //                 break;
// //             }
// //         }
// //         if(!usernameTaken)
// //         {
// //             User user (username,password);
// //             userDatabase_.push_back(user);
// //             start = false;
// //             std::cout << "Finished signing up" << std::endl;
// //         }
// //     }
// // }
// // void TheaterReservationSystem::SignIn(bool start)
// // {
// //     while(start)
// //     {
// //         std::cout << "Enter a username: " << std::endl;
// //         std::string username{""};
// //         std::cin >> username;
// //         std::cout << "Enter a password: " << std::endl;
// //         std::string password{""};
// //         std::cin >> password;
// //         bool successfulLogin{false};
// //         for(User user : userDatabase_)
// //         {
// //             if(user.GetUsername() == username && user.GetPassword() == password)
// //             {
// //                 successfulLogin = true;
// //                 break;
// //             }
// //         }
// //         if(successfulLogin)
// //         {
// //             User user = GetUser(username,password);
// //             TransactionMode(start,user);
// //             start = false;
// //         }
// //         else
// //         {
// //             std::cout << "Invalid Login!" << std::endl;
// //         }

// //         // if(hasUsername)
// //         // {

// //         //     bool hasPassword{false};
// //         //     for(User user : userDatabase_)
// //         //     {
// //         //         if(user.GetPassword() == password)
// //         //         {
// //         //             hasPassword = true;
// //         //             break;
// //         //         }
// //         //     }

// //         //     if(hasPassword)
// //         //     {
// //         //         std::cout << "Successful Login" << std::endl;
// //         //         //Login
// //         //         User user = GetUser(username,password);
// //         //         TransactionMode(true,user);

// //         //     }
// //         //     else
// //         //     {
// //         //         std::cout << "Invalid password" << std::endl;
// //         //     }

// //     }
// // }

// // void TheaterReservationSystem:: TransactionMode(bool start, User user)
// // {
// //     while(start)
// //     {
// //         std::cout << "[R]eserve    [V]iew    [C]ancel    [O]ut" << std::endl;
// //         char choice{' '};
// //         std::cin >> choice;
// //         choice = (std::toupper(choice));
// //         switch(choice)
// //         {
// //             case 'R':
// //                 std::cout << "Reserve" << std::endl;
// //                 ReservationSession(true,user);
// //                 break;
// //             case 'V':
// //                 std::cout << "View" << std::endl;
// //                 ViewReservations(true,user);
// //                 break;
// //             case 'C':
// //                 std::cout << "Cancel" << std::endl;
// //                 CancelReservation(true,user);
// //                 break;
// //             case 'O':
// //                 std::cout << "Out" << std::endl;
// //                 break;
// //             default:
// //                 std::cout << "Invalid Input" << std::endl;
// //                 break;
// //         }
// //     }
// // }
// // void TheaterReservationSystem:: ReservationSession(bool start, User& user)
// // {
// //     while(start)
// //     {
// //         DisplayShows();
// //         std::cout << "Select a show time: " << std::endl;
// //         bool selectingShow{true};

// //         std::string date{""};
// //         std::string time{""};
// //         std::cout << "Enter a date: [Q to quit]" << std::endl;
// //         std::cin >> date;
// //         if(date == "Q" || date == "q")
// //         {
// //             std::cout << "exiting reservation" << std::endl;
// //             break;
// //         }
// //         std::cout << "Enter a time: [Q to quit]" << std::endl;
// //         std::cin >> time;
// //         if(time == "Q" || time == "q")
// //         {
// //             std::cout << "exiting reservation" << std::endl;
// //             break;
// //         }

// //         Show show = GetShow(date,time);
// //         Show reservation(show.GetTime(),show.GetDate());

// //         show.DisplayAllSeats();

// //         bool selectingSeats{true};
// //         std::vector<std::string> reservedSeatIds;

// //         while(selectingSeats)
// //         {
// //             std::cout << "Select a seat: " << std::endl;
// //             std::string seatId{""};
// //             std::cin >> seatId;
// //             if(show.GetSeat(seatId).GetAvailability() == false)
// //             {
// //                 std::cout << "Seat is unavailable" << std::endl;
// //             }
// //             else
// //             {
// //                 reservedSeatIds.push_back(seatId);
// //             }
// //             char choice{' '};
// //             bool continuing{true};
// //             std::cout << "Continue? [Y/N]" << std::endl;
// //             std::cin >> choice;
// //             choice = (std::toupper(choice));
// //             while(continuing)
// //             {
// //                 if(choice == 'N')
// //                 {
// //                     continuing = false;
// //                     selectingSeats = false;
// //                     for(std::string seatId : reservedSeatIds)
// //                     {
// //                         show.UpdateSeatAvailability(seatId,false);
// //                         reservation.AddSeat(show.GetSeat(seatId));
// //                     }
// //                     UpdateShow(show);
// //                 }
// //                 else if(choice == 'Y')
// //                 {
// //                     continuing = false;
// //                 }
// //                 else
// //                 {
// //                     std::cout << "Invalid Input" << std::endl;
// //                 }
// //             }

// //         }
// //         user.AddReservation(reservation);
// //     }
// // }

// // void TheaterReservationSystem:: DisplayShows() const
// // {
// //     std::cout << std::endl;
// //     for(Show show : showDatabase_)
// //     {
// //         std::cout << show.ShowToString() << std::endl;
// //     }
// // }

// // Show TheaterReservationSystem:: GetShow(std::string date,std::string time) const
// // {
// //     Show showVar;
// //     for(Show show: showDatabase_)
// //     {
// //         if(show.GetDateString() == date && show.GetTimeString() == time)
// //         {
// //             showVar = show;
// //             return showVar;
// //         }
// //     }
// //     std::cout << "Cannot find show!" << std::endl;
// //     return showVar;
// // }

// // void TheaterReservationSystem::UpdateShow(Show input)
// // {
// //     for(Show& show : showDatabase_)
// //     {
// //         if(show.GetDateString() == input.GetDateString() && show.GetTimeString() == input.GetTimeString())
// //         {
// //             show = input;
// //             break;
// //         }
// //     }
// // }
// // void TheaterReservationSystem::ViewReservations(bool start, User user) const
// // {
// //     while(start)
// //     {
// //         std::cout << "[A] View Reservations\n[B] View Reservation\n[Q] Quit" << std::endl;
// //         char choice{' '};
// //         std::cin >> choice;
// //         choice = (std::toupper(choice));
// //         if(choice == 'A')
// //         {
// //             std::vector<Show> reservations = user.GetReservations();
// //             std::cout << "Reservations: " << std::endl;
// //             for(Show reservation : reservations)
// //             {
// //                 std::cout << reservation.ShowToString() << std::endl;
// //                 for(Seat seat : reservation.GetSeats())
// //                 {
// //                     std::cout << seat.SeatToString() << std::endl;
// //                 }
// //             }
// //         }
// //         else if(choice == 'B')
// //         {
// //             std::string date{""};
// //             std::cout << "Enter a date: " << std::endl;
// //             std::cin >> date;
// //             std::vector<Show> reservations = user.GetReservations();
// //             std::cout << "Reservations: " << std::endl;
// //             for(Show reservation : reservations)
// //             {
// //                 if(reservation.GetDateString() == date)
// //                 {
// //                     std::cout << reservation.ShowToString() << std::endl;
// //                     for(Seat seat : reservation.GetSeats())
// //                     {
// //                         std::cout << seat.SeatToString() << std::endl;
// //                     }
// //                 }
// //             }
// //         }
// //         else if(choice == 'Q')
// //         {
// //             break;
// //         }
// //         else
// //         {
// //             std::cout << "Invalid Input" << std::endl;
// //         }
// //     }
// // }
// // void TheaterReservationSystem:: CancelReservation(bool start,User user)
// // {
// //     std::string date{""};
// //     std::string time{""};

// //     std::cout << "Enter a date: " << std::endl;
// //     std::cin >> date;
// //     std::cout << "Enter a time: " << std::endl;
// //     std::cin >> time;
// //     user.DisplayReservation(date,time);
// //     Show show = user.GetReservation(date,time);
// //     bool selectingSeats{true};
// //     std::vector<std::string> cancelReservedSeatIds;

// //     while(selectingSeats)
// //     {
// //         std::cout << "Select a seat: " << std::endl;
// //         std::string seatId{""};
// //         std::cin >> seatId;
// //         bool foundSeat{false};
// //         for(Seat seat : show.GetSeats())
// //         {
// //             if(seatId == seat.GetSeatId())
// //             {
// //                 foundSeat = true;
// //                 break;
// //             }
// //         }
// //         if(foundSeat)
// //         {
// //             cancelReservedSeatIds.push_back(seatId);
// //         }
// //         else
// //         {
// //             std::cout << "Seat noasdsadt found" << std::endl;
// //         }

// //         // for(Show show : )
// //         // {
// //         //     for(Seat seat : show.GetSeats())
// //         //     {
// //         //         if(seatId == seat.GetSeatId())
// //         //         {
// //         //             foundSeat = true;
// //         //             break;
// //         //         }
// //         //     }
// //         // }

// //         char choice{' '};
// //         bool continuing{true};

// //         while(continuing)
// //         {
// //             std::cout << "Continue? [Y/N]" << std::endl;
// //             std::cin >> choice;
// //             choice = (std::toupper(choice));
// //             if(choice == 'N')
// //             {
// //                 continuing = false;
// //                 selectingSeats = false;
// //                 user.clearallreserves();
// //                 std::cout << user.GetReservations().size() << std::endl;

// //                 // for(std::string seatId : cancelReservedSeatIds)
// //                 // {
// //                 //     user.RemoveReservations(date,time,seatId);
// //                 // }
// //                 // for(std::string seatid : cancelReservedSeatIds)
// //                 // {
// //                 //     // user.RemoveReservation(seatId);
// //                 // }

// //                 //update show's seat availability

// //                 // Show updatedShow;
// //                 // if(reservedSeatIds.empty())
// //                 // {
// //                 //     std::cout << "No reserved seats" << std::endl;
// //                 // }
// //                 // else
// //                 // {
// //                 //     for(std::string seatId : reservedSeatIds)
// //                 //     {
// //                 //         user.RemoveReservation(seatId,reservation,updatedShow);
// //                 //     }
// //                 // }

// //                 // UpdateShow(updatedShow);

// //                 // // UpdateShow(updatedShow);

// //                 // for(Show& show : showDatabase_)
// //                 // {
// //                 //     if(show.GetDateString() == input.GetDateString() && show.GetTimeString() == input.GetTimeString())
// //                 //     {
// //                 //         show = input;
// //                 //         break;
// //                 //     }
// //                 // }

// //             }
// //             else if(choice == 'Y')
// //             {
// //                 continuing  = false;

// //             }
// //             else
// //             {
// //                 std::cout << "Invalid input" << std::endl;
// //             }
// //         }
// //             // while(continuing)
// //             // {
// //             //     if(choice == 'N')
// //             //     {
// //             //         continuing = false;
// //             //         selectingSeats = false;
// //             //         for(std::string seatId : reservedSeatIds)
// //             //         {
// //             //             show.UpdateSeatAvailability(seatId);
// //             //             reservation.AddSeat(show.GetSeat(seatId));
// //             //         }
// //             //         UpdateShow(show);
// //             //     }
// //             //     else if(choice == 'Y')
// //             //     {
// //             //         continuing = false;
// //             //     }
// //             //     else
// //             //     {
// //             //         std::cout << "Invalid Input" << std::endl;
// //             //     }
// //     }

// //         // while(selectingSeats)
// //         // {
// //         //     std::cout << "Select a seat: " << std::endl;
// //         //     std::string seatId{""};
// //         //     std::cin >> seatId;
// //         //     if(show.GetSeat(seatId).GetAvailability() == false)
// //         //     {
// //         //         std::cout << "Seat is unavailable" << std::endl;
// //         //     }
// //         //     else
// //         //     {
// //         //         reservedSeatIds.push_back(seatId);
// //         //     }
// //         //     char choice{' '};
// //         //     bool continuing{true};
// //         //     std::cout << "Continue? [Y/N]" << std::endl;
// //         //     std::cin >> choice;
// //         //     choice = (std::toupper(choice));
// //         //     while(continuing)
// //         //     {
// //         //         if(choice == 'N')
// //         //         {
// //         //             continuing = false;
// //         //             selectingSeats = false;
// //         //             for(std::string seatId : reservedSeatIds)
// //         //             {
// //         //                 show.UpdateSeatAvailability(seatId);
// //         //                 reservation.AddSeat(show.GetSeat(seatId));
// //         //             }
// //         //             UpdateShow(show);
// //         //         }
// //         //         else if(choice == 'Y')
// //         //         {
// //         //             continuing = false;
// //         //         }
// //         //         else
// //         //         {
// //         //             std::cout << "Invalid Input" << std::endl;
// //         //         }
// //         //     }

// // }