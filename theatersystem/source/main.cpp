#include "show.h"
#include "seat.h"
#include "user.h"
#include "theater_reservation_system.h"
int main()
{

    TheaterReservationSystem system;
    system.Start(true);
    // system.DisplayShowSeats("2020-12-27","06:30");

    
    // system.reserveSeat("2020-12-27","06:30","eb100");
    // system.DisplayShowSeats("2020-12-27","06:30");


    // Show* show = system.findShow("2020-12-27","06:30'");
    // show->UpdateSeatAvailability(false,"eb100");
    // system.DisplaySeats();
    // system.UpdateSeatAvailability(false,"2020-12-27","06:30","eb100");
    // system.DisplaySeats();
    // Show* show = system.findShow("2020-12-27","06:30");
    // show->UpdateSeatAvailability(false,"eb100");
    // show->DisplaySeats();
    
    // system.UpdateSeatAvailability(show,false,"eb100");
    // system.DisplaySeats();
    // system.UpdateSeatAvailability(false,"2020-12-23","06:30","eb100");
    // system.DisplaySeats();
    // system.Start(true);
    // system.Start(true);
    // Show* show = system.findShow("2020-12-27","06:30");
    // test->AddReservation(*show);

    

    


    // User* login = system.FindUserLogin("a","b");
    // std::cout << login->ToString() << std::endl;  
    // system.UpdatePassword(login->GetUsername(),"Helloworld");
    // std::cout << login->ToString() << std::endl; 
    // User* login2 = system.FindUserLogin("a","Hellworld");
    // system.printUserDatabase();



    // system.LoadSystem("test.txt");

    
    // system.UpdateSeatAvailability(false,"eb100");
    // system.DisplaySeats();
    // system.DisplayShows();
    // std::cout << "Testing Signup " << std::endl; 
    // int i = 3; // number of times to sign up 
    // for(int i = 0; i < 3; ++i)
    // {
    //     std::cout << "Enter a username: " << std::endl;
    //     std::string username("");
    //     std::cin >> username; 
    //     std::cout << "Enter a password: " << std::endl;
    //     std::string password("");
    //     std::cin >> password; 
    //     if(system.HasUser(username,password))
    //     {
    //         std::cout << "Username already taken" << std::endl; 
    //     }
    //     else
    //     {
    //         User user(username,password);
    //         system.AddUser(user);
    //     }
    // }

    // system.DisplayUsers();
    // std::cout << "Testing Login " << std::endl; 
    // std::cout << "Enter a username: " << std::endl;
    // std::string username("");
    // std::cin >> username; 
    // std::cout << "Enter a password: " << std::endl;
    // std::string password("");
    // std::cin >> password; 

    // if(system.HasUser(username,password))
    // {
    //     User* user = system.findUser(username);
    //     std::cout <<"Succesful login" << std::endl; 
    //     std::cout << user->ToString() << std::endl; 
    //     std::cout << "Updating Password" << std::endl; 
    //     user->SetPassword("helloworld");
    // }
    // else
    // {
    //     std::cout << "Invalid Login" << std::endl; 
    // }

    // std::cout << "Displaying Users" << std::endl; 
    // system.DisplayUsers();
    
    // // std::cout << "Check if user information has been updated" <<  std::endl; 
    // // User* user = system.findUser("a");
    // // if(user)
    // // {
    // //     std::cout << user->ToString() << std::endl; 
    // // }
    // // else
    // // {
    // //     std::cout << "User not found" << std::endl; 
    // // }

    // // User* user2 = system.findUser("b");

    // // if(user2)
    // // {
    // //     std::cout << user2->ToString() << std::endl; 
    // // }
    // // else
    // // {
    // //     std::cout << "User not found" << std::endl; 
    // // }

    // // std::cout << "Perform show selection and seat reservation" << std::endl; 

    // // std::cout << "Enter a date and time: " << std::endl;
    // // std::string date("");
    // // std::string time("");
    // // std::cout << "Enter a date: " << std::endl;
    // // std::cin >> date;
    // // std::cout << "Enter a time: " << std::endl; 
    // // std::cin >> time;

    // system.DisplayShows();
    // Show* show = system.findShow("2020-12-27","06:30");
    // show->DisplaySeats();

    // //test user sign up
    // User user("a","b");
    // system.AddUser(user);
    // User user2("a","b");
    // system.AddUser(user2);

    // //test user login 
    // //case A) undefined user

    // //unsuccessful 
    // User* login1 = system.FindUserLogin("a","c");
    // User* login2 = system.FindUserLogin("b","c");

    // //succesful login
    // User* login3 = system.FindUserLogin("a","b");

    // //test user reserving a seat 
    // //incorrect found seat 
    // Seat* seat = show->findSeat("asdbkaslmd");
    // //correct found seat
    // Seat* seat2 = show->findSeat("eb100");
    // Seat* seat3 = show->findSeat("eb99");
    // system.UpdateSeatAvailability(false,seat2->GetSeatId());
    // system.UpdateSeatAvailability(false,seat3->GetSeatId());

    

    // //confirming player's seat reservations 

    // Show reservation(show->GetTime(),show->GetDate());

    //when confirming reservation, make sure system updates seat to unavailable 
    // seat2->UpdateAvailability(false);
    // seat3->UpdateAvailability(false);

    // reservation.AddSeat(*seat2);
    // reservation.AddSeat(*seat3);

    // //have user add unavailable seat
    // Seat* seat4 = show->findSeat("eb98");
    // seat4->UpdateAvailability(false);
    // reservation.AddSeat(*seat4);

    // //verify reservations contain seats user wants 
    // reservation.DisplaySeats();

    // //add reservation and display that they are updated for current user
    // user.AddReservation(reservation);
    // user.DisplayReservations();
    // //verify seats are updated in database 
    // system.DisplaySeats();


        // Assuming you have a valid `Show` pointer from `showDatabase_`
    // Show* show = system.findShow("2020-12-27","06:30");
    // system.UpdateSeatAvailability(show,false,"eb100");
    // system.DisplaySeats();
    // // Example of reserving seats
    // system.UpdateSeatAvailability(false, "eb100");
    // system.UpdateSeatAvailability(false, "eb99");

    // Add seats to reservation
    // Show reservation(show->GetTime(), show->GetDate());
    // reservation.AddSeat(*show->findSeat("eb100"));
    // reservation.AddSeat(*show->findSeat("eb99"));
    // reservation.DisplaySeats();

    // Verify the reservation
    // reservation.DisplaySeats();

    // Add reservation to user
    // User* user = system.FindUserLogin("a", "b");
    // if (user) {
    //     user->AddReservation(reservation);
    //     user->DisplayReservations();
    // }

    // Verify updated seats in the system
    // system.DisplaySeats();

    










    

    



    



    //test user login 
    // User* login = system.findUser(user.GetUsername());

    
    // Show* show2 = system.findShow("2020-12-27","06:30");
    // Show* show3 = system.findShow("2020-12-25","08:30");


    // std::cout << show->ToString() << std::endl; 

    // std::cout << "Testing making reservations" << std::endl;
    // if(show)
    // {
    //     show->DisplaySeats();
    //     Show reservation(show->GetTime(),show->GetDate());
    //     Show reservation2(show2->GetTime(),show2->GetDate());
    //     Show reservation3(show3->GetTime(),show3->GetDate());

    //     for(int i = 0; i < 2; ++i)    Show* show2 = system.findShow("2020-12-27","06:30");

    //     {
    //         std::cout << "Select a seat: " << std::endl;
    //         std::string seatId("");
    //         std::cin >> seatId;
    //         Seat* seat = show->findSeat(seatId);

    //         if(seat)
    //         {
    //             if(seat->IsAvailabile())
    //             {
    //                 seat->UpdateAvailability(false);
    //                 reservation.AddSeat(*seat);
    //             }
    //             else
    //             {
    //                 std::cout << "Seat Not Available" << std::endl; 
    //             }
    //         }
    //         else
    //         {
    //             std::cout << "Cannot find Seat" << std::endl; 
    //         }
    //     }
    //     user->AddReservation(reservation);
    //     user->AddReservation(reservation2);
    //     user->AddReservation(reservation3);

    // }

    // std::cout << "Test Getting Reservation" << std::endl; 

    // Show* reservation = user->FindReservation("2021-01-02","08:30");
    // if(reservation)
    // {
    //     std::cout << reservation->ToString() << std::endl; 
    // }

    // std::cout << "Test removing seats" << std::endl; 
    // // user->CancelReservation("2021-01-02","08:30","eb100");
    // // std::cout << "Finished canceling" << std::endl;

    // std::cout << "Testing displaying reservations" << std::endl; 
    // user->DisplayReservations();




    

    // std::cout << "Checking for database updates..." << std::endl; 
    // system.DisplaySeats();
    // system.DisplayShows();






    // user->DisplayReservations();

    // std::cout << "Testing seat database has been updated" << std::endl; 
    // system.DisplaySeats();

    // std::cout << "Testing removing seats" << std::endl; 










    

        





    
    

}

//     system.Start(true,"");
//     // std::string str = "apple|bannana|orange";
//     // char delimeter = '|';
//     // std::vector<std::string> result = system.SingleDelimeterStringSplit(str,delimeter);
//     // for(const auto& s : result)
//     // {
//     //     std::cout << s << std::endl; 
//     // }



//     // return 0;
//     // system.Start(true,"");
    
//     // system.LoadSystem(" ");
//     // system.Start(true);


//     // user.AddReservation(show.GetDate(),show.GetTime(),"eb100",showDB);
   

//     // for(Show show : showDB)
//     // {
//     //     for(Seat seat : show.GetSeats())
//     //     {
//     //         std::cout << seat.SeatToString() << std::endl; 
//     //     }
//     // }
//     // user.RemoveReservation(show.GetDateString(),show.GetTimeString(),"eb100",showDB);

//     // std::cout << "Canceling reservation" << std::endl; 
//     // for(Show show : showDB)
//     // {
//     //     for(Seat seat : show.GetSeats())
//     //     {
//     //         std::cout << seat.SeatToString() << std::endl; 
//     //     }
//     // }
    
//  // show database <- user interacts 
//  // show database updates data 
//  // show -> user reservationDB 
    
// }
// // #include <iostream>

// // #include "theater_reservation_system.h"
// // #include "show.h"
// // #include "seat.h"

// // int main()
// // {
// //     TheaterReservationSystem system;
// //     system.LoadSystem("file");
// //     system.Start(true);
    
// // }
// //     // TheaterReservationSystem system();
// //     // system.LoadSystem("filename");
// //     // system.Start(true);
// //     // std::vector<int>* test = new std::vector<int>();
// //     // std::vector<Show>* test2 = new std::vector<Show>();
// //     // test->push_back(1);
    
// //     // User user("a","b");
// //     // system.AddUser(user);
// //     // std::cout << system.GetUser("a","b").UserToString() << std::endl;
// //     // User temp = system.GetUser("a","b");
// //     // std::tm start_date = {};
// //     // std::tm end_date = {};
// //     // std::tm six_thirty_schedule = {};
// //     // std::tm eight_thirty_schedule = {};

// //     // start_date.tm_year = 2020 - 1900; // tm_year is years since 1990 
// //     // start_date.tm_mon = 12 - 1;
// //     // start_date.tm_mday = 23; 

// //     // end_date.tm_year = 2021 - 1900;
// //     // end_date.tm_mon = 1 - 1;
// //     // end_date.tm_mday = 2;

// //     // six_thirty_schedule.tm_hour = 6;
// //     // six_thirty_schedule.tm_min = 30;

// //     // Show show(six_thirty_schedule,start_date);

// //     // system.AddShow(show);
// //     // std::cout << show.ShowToString() << std::endl; 

    
// //     // std::cout << "Pushing element" << std::endl;
    
// //     // test2->push_back(show);

// //     // std::cout << "DOne Pushing element" << std::endl; 

    
    

// //     // eight_thirty_schedule.tm_hour = 8;
// //     // eight_thirty_schedule.tm_min = 30;
// //     // Show show(six_thirty_schedule,start_date);
// //     // Seat seat("a",0.0,false);
// //     // show.AddSeat(seat);
// //     // system.AddShow(show);
    
    



    
// //     // system.LoadSystem();
// //     // system.Start(true);


// //     // Show show;
// //     // Seat s("a",0.0,true);
// //     // Seat s1("b",0.0,true);
// //     // Seat s2("c",0.0,true);

// //     // show.AddSeat(s);
// //     // show.AddSeat(s1);
// //     // show.AddSeat(s2);

// //     // std::cout << "Before\n";
// //     // show.DisplaySeats();
// //     // show.UpdateSeat("a");
// //     // std::cout << "After\n";
    
// //     // show.DisplaySeats();

// //     // show.AddSeat(s);
// //     // std::cout << "before:" << s.SeatToString() << std::endl;
// //     // s.SetAvailability(false);
// //     // show.UpdateSeat("a");
// //     // std::cout << "after:" << s.SeatToString() << std::endl;



// // // // // /*
// // // // // will experiment here for now 
// // // // // */
// // // // // // Helper function to print date in a readable format

// // // // // //Function to add one day to a std::tm date 



// // // // // int main()
// // // // // {
    
// // // // //     // Seat& s = *(new Seat("",0,false));
// // // // //     // Seat* s = new Seat("",0,false);
// // // // //     // Seat& ref = *s;
// // // // //     // std::cout << ref.SeatToString();
// // // // //     // Seat* s = new Seat("",0,false);
// // // // //     // test(*s);
// // // // //     // std::cout << s->SeatToString();
// // // // //     // delete s;
    

// // // // // // // ==================== we will call this entire block of functionality: "LoadSystem" ================ 

// // // // // // /*
// // // // // // this needs to be encapsulated within the theaterreservationsystem class 

// // // // // // if preserved data is empty, load databases 
// // // // // // */

// // // // // TheaterReservationSystem system;

// // // // // //     TheaterReservationSystem* system = new TheaterReservationSystem();
// // // // // // /*

// // // // // // @TODO: 
// // // // // //     [X] create a theater system instance
// // // // // //     [X] for each time(6 30 pm, 8 30 pm), add a date from 2020-12-23 -> 2-21-01-02 
// // // // // //     [X] create instances of shows with the time and date. load into theater system datebase 
// // // // // //     [ ] loop through all those shows and populate their seat database 
// // // // // //     [ ] display show reservations sorted by: date then time 
// // // // // //     [ ] 
// // // // // // */

// // // // // //     // calendar time 
// // // // // //     //Define start and end dates using std::tm 



    
// // // // //     //Initialize start date (December 23,2020)


// // // // //     // print the date range 
// // // // //     // std::cout << "Start date: " << formatDate(start_date) << std::endl;
// // // // //     // std::cout << "End date: " << formatDate(end_date) << std::endl; 

// // // // //     //Create datetime structure and use mktime to fil; in the missing members 
    

// // // // //     // to convert to string you can use iomanip and sstream libraries to format the date 


// // // // //     //loop through the days from start to end 
// // // // //     std::tm current_date = start_date; 
// // // // //     // std::string times [] = {"6:30","8:30"};
// // // // //     std::string seatFloors[] = {"m","sb","wb","eb"};
// // // // //     Show show_six_thirty(six_thirty_schedule,current_date);
// // // // //     Show show_eight_thirty(six_thirty_schedule,current_date);
// // // // //     Seat s("b1",10.00,true);


// // // // // /*
// // // // // - populate the system's showdata base with shows
// // // // // - populate the show's seat database with seats 
// // // // // */

    
// // // // //     //handling the 6 30 schedule 
// // // // //     while(std::mktime(&current_date) <= std::mktime(&end_date))
// // // // //         {
// // // // //         //    std::string date = formatDate(current_date);
// // // // //         //    Show* show = new Show(date,time);
// // // // //            Show show(six_thirty_schedule,current_date);
// // // // //            for (std::string floor:seatFloors)
// // // // //            {
// // // // //                 if(floor == "m")
// // // // //                 {
// // // // //                     for(int i = 1; i < 151; i++)
// // // // //                     {
// // // // //                         if(i > 100 && i < 151)
// // // // //                         {
// // // // //                             Seat seat(floor + std::to_string(i),45.00,true);
// // // // //                             show.AddSeat(seat);
// // // // //                             // show->addSeat(seat);
// // // // //                         }
// // // // //                         else
// // // // //                         {
// // // // //                             Seat seat (floor + std::to_string(i),35.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                         }
// // // // //                     }
// // // // //                 }
// // // // //                 else if (floor == "sb")
// // // // //                 {
// // // // //                     for(int i = 1; i < 51; i++)
// // // // //                     {
// // // // //                         if(i > 25 && i < 51)
// // // // //                         {
// // // // //                             Seat seat(floor + std::to_string(i),55.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                         }
// // // // //                         else
// // // // //                         {
// // // // //                             Seat seat (floor + std::to_string(i),50.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                         }
// // // // //                     }
// // // // //                 }
// // // // //                 else if(floor == "wb")
// // // // //                 {
// // // // //                     for(int i = 1; i < 101; i++)
// // // // //                     {
// // // // //                             Seat seat (floor + std::to_string(i),40.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                     }
// // // // //                 }
// // // // //                 else
// // // // //                 {
// // // // //                     for(int i = 1; i < 101; i++)
// // // // //                     {
// // // // //                             Seat seat(floor + std::to_string(i),40.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                     }
// // // // //                 }

// // // // //            }

// // // // //            system.AddShow(show);
// // // // //            addOneDay(current_date);
// // // // //         }
// // // // //     current_date = start_date;
    
// // // // //            //handling the 6 30 schedule 
// // // // //     while(std::mktime(&current_date) <= std::mktime(&end_date))
// // // // //         {
// // // // //         //    std::string date = formatDate(current_date);
// // // // //         //    Show* show = new Show(date,time);
// // // // //            Show show(eight_thirty_schedule,current_date);
// // // // //            for (std::string floor:seatFloors)
// // // // //            {
// // // // //                 if(floor == "m")
// // // // //                 {
// // // // //                     for(int i = 1; i < 151; i++)
// // // // //                     {
// // // // //                         if(i > 100 && i < 151)
// // // // //                         {
// // // // //                             Seat seat(floor + std::to_string(i),45.00,true);
                        
// // // // //                             show.AddSeat(seat);

// // // // //                         }
// // // // //                         else
// // // // //                         {
// // // // //                             Seat seat (floor + std::to_string(i),35.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                         }
// // // // //                     }
// // // // //                 }
// // // // //                 else if (floor == "sb")
// // // // //                 {
// // // // //                     for(int i = 1; i < 51; i++)
// // // // //                     {
// // // // //                         if(i > 25 && i < 51)
// // // // //                         {
// // // // //                             Seat seat(floor + std::to_string(i),55.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                         }
// // // // //                         else
// // // // //                         {
// // // // //                             Seat seat (floor + std::to_string(i),50.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                         }
// // // // //                     }
// // // // //                 }
// // // // //                 else if(floor == "wb")
// // // // //                 {
// // // // //                     for(int i = 1; i < 101; i++)
// // // // //                     {
// // // // //                             Seat seat (floor + std::to_string(i),40.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);
// // // // //                     }
// // // // //                 }
// // // // //                 else
// // // // //                 {
// // // // //                     for(int i = 1; i < 101; i++)
// // // // //                     {
// // // // //                             Seat seat (floor + std::to_string(i),40.00,true);
// // // // //                             // show->addSeat(seat);
// // // // //                             show.AddSeat(seat);

// // // // //                     }
// // // // //                 }

// // // // //            }
// // // // //            system.AddShow(show);
// // // // //            addOneDay(current_date);
// // // // //         }

// // // // //     std::vector<Seat> seats = system.GetShow("2021-01-02","08:30").GetSeats();
// // // // //     for(Seat s : seats)
// // // // //     {
// // // // //         Seat& ref = s;
// // // // //         ref.SetAvailability(false);
// // // // //     }
    
// // // // //     for(Seat s : seats)
// // // // //     {
// // // // //         std::cout << s.IsAvailable(); 
// // // // //     }

// // // // //     // std::cout << system.GetShow("2021-01-02","08:30").GetSeat("eb100").SeatToString() << std::endl;


// // // // // // //test driven development/ caveman unit testing 
// // // // // // Show& show = system.GetShow("2021-01-02", "08:30");
// // // // // // std::cout << show.GetSeat("eb100").SeatToString();
// // // // // // show.GetSeat("eb100").SetAvailability(false);
// // // // // // std::cout << show.GetSeat("eb100").IsAvailable() << std::endl;
// // // // // // std::cout << show.GetSeat("eb100").SeatToString();


// // // // // // s.GetSeat("eb99").SetAvailability(false);
// // // // // // std::cout << s.GetSeat("eb99").SeatToString() << std::endl;
// // // // // // show1.GetSeat("eb99").SetAvailability(false);
// // // // // // show1.DisplaySeats();
// // // // // // std::vector<std::string> seatReversations{"sb1","sb2","sb25","eb100","eb99"};
// // // // // // system.UpdateShowSeats(show1,seatReversations);
// // // // // // system.DisplayShows();
// // // // // // std::cout << show1.GetSeat("eb99").SeatToString() << std::endl;

// // // // // // show1.GetSeat("sb1").SetAvailability(false);

// // // // // // system.UpdateShowSeats(show1,seatReversations);
// // // // // // system.DisplayShows();


// // // // //     // system.UpdateShowSeats(show1,seatReversations);

// // // // // //     system.GetShow("2021-01-02","08:30").DisplaySeats();
// // // // //     // system.UpdateShowSeats(show1.GetDateString(),show1.GetTimeString(),seatReversations);



    

    


// // // // //     return 0;

// // // // // }



// // // // #include "theater_reservation_system.h"
// // // // #include <iostream>
// // // // #include <vector>

// // // // int main() {
// // // //     // Create some sample seats
// // // //     std::vector<Seat> seats = {
// // // //         Seat("eb100", 40.0, true),
// // // //         Seat("eb101", 40.0, true),
// // // //         Seat("sb25", 30.0, true)
// // // //     };

// // // //     // Create a sample show with the seats
// // // //     Show show("2021-01-02", "08:30", seats);

// // // //     // Create the theater reservation system and add the show
// // // //     TheaterReservationSystem system({ show });

// // // //     // Display seats before reservation
// // // //     std::cout << "Before Reservation:" << std::endl;
// // // //     system.DisplayShows();

// // // //     // Reserve some seats
// // // //     std::vector<std::string> reservedSeats = { "eb100", "sb25" };
// // // //     system.UpdateReservedSeats("2021-01-02", "08:30", reservedSeats);

// // // //     // Display seats after reservation
// // // //     std::cout << "After Reservation:" << std::endl;
// // // //     system.DisplayShows();

// // // //     return 0;
// // // // }


// // // #include <string>
// // // #include <vector>
// // // #include <iostream>
// // // class Seat {
// // // private:
// // //     std::string seatId_;
// // //     double price_;
// // //     bool isAvailable_;

// // // public:
// // //     Seat(const std::string& seatId, double price, bool isAvailable)
// // //         : seatId_(seatId), price_(price), isAvailable_(isAvailable) {}

// // //     std::string GetSeatId() const { return seatId_; }
// // //     void SetAvailability(bool availability) { isAvailable_ = availability; }
// // //     bool IsAvailable() const { return isAvailable_; }
// // //     // Other methods...
// // // };

// // // class Show {
// // // private:
// // //     std::vector<Seat> seats_;

// // // public:
// // //     Show(const std::vector<Seat>& seats) : seats_(seats) {}

// // //     // Update seat availability based on seat ID
// // //     void UpdateSeatAvailability(const std::string& seatId, bool availability) {
// // //         for (Seat& seat : seats_) {
// // //             if (seat.GetSeatId() == seatId) {
// // //                 seat.SetAvailability(availability);
// // //                 return;
// // //             }
// // //         }
// // //     }

// // //     std::vector<Seat>& GetSeats() { return seats_; }
// // //     const std::vector<Seat>& GetSeats() const { return seats_; }
// // //     // Other methods...
// // // };

// // // class TheaterReservationSystem {
// // // private:
// // //     std::vector<Show> showDatabase_;

// // // public:
// // //     TheaterReservationSystem(const std::vector<Show>& shows) : showDatabase_(shows) {}

// // //     // Find and return a reference to a Show object
// // //     Show* GetShow(const std::string& date, const std::string& time) {
// // //         for (Show& show : showDatabase_) {
// // //             if (show.GetDateString() == date && show.GetTimeString() == time) {
// // //                 return &show;
// // //             }
// // //         }
// // //         throw std::runtime_error("Show not found");
// // //     }

// // //     // Update seat availability based on reservations
// // //     void UpdateReservedSeats(const std::string& date, const std::string& time, const std::vector<std::string>& seatReservations) {
// // //         Show* show = GetShow(date, time);
// // //         if (show) {
// // //             for (const std::string& seatId : seatReservations) {
// // //                 show->UpdateSeatAvailability(seatId, false);
// // //             }
// // //         }
// // //     }
// // //     // Other methods...
// // // };







