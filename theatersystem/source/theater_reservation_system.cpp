
/*
features:
[X] sign up
[X] sign in
[X] exit system
[X] transaction mode
    [X] reservation session
    [X] view entire reservations
    [X] cancel reservation
    [X] out
        [X] display receipt for the transaction
        [X] handle group discounts
    [] load data from .txt file
        - TOO FUCKING LAZY 
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
    // ViewReservations(login);
    // CancelReservation(login);
    // ViewReservations(login);
    Out(login);
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
    std::map<std::string, std::vector<std::string>> reservations;

    while (true)
    {
        DisplayShows();
        std::string date("");
        std::string time("");
        std::cout << "Enter a date: " << std::endl;
        std::cin >> date;
        std::cout << "Enter a time: " << std::endl;
        std::cin >> time;
        Show *show = findShow(date, time);
        if (show)
        {
            std::vector<std::string> selectedSeats;
            show->DisplaySeats();
            bool selectingSeats(true);
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
                        std::string dateTime = date + " " + time;
                        std::vector<std::string> reservedSeats = reservations[dateTime];

                        //@TODO: have to also check if seat has been already selected/reserved by current customer
                        // ex: customer finishes reserving but hasnt cashed out the transaction
                        // if you selected a seat to reserve, cannot select again
                        if (std::find(reservedSeats.begin(), reservedSeats.end(), seatId) != reservedSeats.end())
                        {
                            std::cout << "You already selected this seat" << std::endl;
                        }
                        // if you selected a seat to reserve, cannot select again
                        else if (std::find(selectedSeats.begin(), selectedSeats.end(), seatId) != selectedSeats.end())
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
                    // Extract the date and time
                    std::string dateString = datetime.substr(0, spacePos);
                    std::string timeString = datetime.substr(spacePos + 1);
                    Show *currentShow = findShow(dateString, timeString);
                    std::tm tm_date = {};
                    std::istringstream ss(dateString);
                    ss >> std::get_time(&tm_date, "%Y-%m-%d");
                    std::time_t date = std::mktime(&tm_date);
                    std::tm tm_time = {};
                    std::istringstream ss2(timeString);
                    std::time_t time = std::mktime(&tm_time);
                    ss2 >> std::get_time(&tm_time, "%H:%M");
                    if (ss.fail() || ss2.fail())
                    {
                        std::cerr << "Failed to parse date!" << std::endl;
                        break;
                    }
                    Show reservation(tm_time, tm_date);
                    for (std::string seatId : seats)
                    {
                        // set the reserved seats to unavailable
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
        else if (choice != 'N' && choice != 'Y')
        {
            std::cout << "Invalid Input" << std::endl;
        }
    }
}
void TheaterReservationSystem::CancelReservation(User *user)
{
    std::cout << "You selected Cancel Reservations" << std::endl;
    std::string date("");
    std::string time("");
    while (true)
    {
        std::cout << "Enter a date: (or Q to quit) " << std::endl;
        std::cin >> date;

        if (date == "Q" || date == "q")
        {
            break;
        }

        std::cout << "Enter a time: (or Q to quit) " << std::endl;
        std::cin >> time;

        if (time == "Q" || date == "q")
        {
            break;
        }

        Show *reservation = user->FindReservation(date, time);
        if (reservation)
        {
            bool selectingSeats(true);
            while (selectingSeats)
            {
                reservation->DisplaySeats();
                std::cout << "Enter a seat id to cancel: (or Q to quit)" << std::endl;
                std::string seatId("");
                std::cin >> seatId;
                if (seatId == "Q" || seatId == "q")
                {
                    break;
                }
                Seat *seat = reservation->findSeat(seatId);
                if (seat)
                {
                    user->CancelReservation(date, time, seatId);
                }
                else
                {
                    std::cout << "Cannot seat" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Cannot find reservation" << std::endl;
        }
    }
}

void TheaterReservationSystem::Out(User *user)
{
    std::cout << " ==== Displaying Transaction Receipt ==== " << std::endl;
    // temp confirmation number
    std::cout << "Confirmation Number 1" << std::endl;
    // set the reserved seats as unavailable so other users dont reserve the seats

    // user->DisplayReservations();
    std::map<std::string, Show> reservations = user->GetReservations();
    double totalPrice(0.0);

    std::map<std::string, Show>::iterator iter = reservations.begin();
    while (iter != reservations.end())
    {
        std::cout << "Show: " << iter->second.ToString() << std::endl;
        double showPrice(0.0);
        std::vector<Seat> seats = iter->second.GetSeats();
        for (Seat seat : seats)
        {
            reserveSeat(iter->second.GetDateString(), iter->second.GetTimeString(), seat.GetSeatId());
            std::cout << seat.GetSeatId() << std::endl;
            showPrice += seat.GetPrice();
        }
        if (iter->second.GetDate().tm_mon == 12 && (iter->second.GetDate().tm_mday != 27 || iter->second.GetDate().tm_mday != 26))
        {
            if (seats.size() > 4 && seats.size() < 11)
            {
                double discount = 2.0 * seats.size();
                showPrice -= discount;
            }
            if (seats.size() > 10 && seats.size() < 21)
            {
                double discount = 5.0 * seats.size();
                showPrice -= discount;
            }
        }

        totalPrice += showPrice;

        ++iter;
    }
    std::cout << "Total Price: " << totalPrice << std::endl;
}
