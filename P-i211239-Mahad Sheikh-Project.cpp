#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

//using dynamic memories to store username and Password;
char* Pass = new char[255];
char* U = new char[255];
int total=2000;



//loading;
void loading()
{
    for(int i=0; i<=4; i++)
    {
        Sleep(200);
        cout<<".";
    }
    cout<<"..";
    Sleep(300);
    cout<<"..";
    Sleep(300);
    cout<<".....";
    Sleep(1000);
    cout<<endl;
}

//For output a line with delay;
void lines()
{
    int n, i;
    for(n=0; n<50; n++)
    {
        cout<<"-";
        Sleep(20);
    }
    cout<<endl;
}

//seat check if user enter seats;
string seatcheck1(int r, int c, int seats[][10])
{
    string seat="";
    if (seats[r][c]!=-1)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(r==i&&c==j)
                {
                    cout<<" "<<"\e[1m"<<seats[i][j]<<"\e[0m";
                }
                else
                {
                    cout<<" "<<seats[i][j];
                }
            }
            cout<<endl;
        }
        cout<<endl;
        seats[r][c]=-1;
        seat+=(r+49);
        seat+=(c+49);
    }
    else
    {
        cout<<"\e[1mSeat Booked Choose Another Seat\e[0m\n\n";
        cout<<"-------------------------------\n\n";
    }
    return seat;
}

//seat check if user enter price;
string seatcheck2(int price, int seats[][10])
{
    string seat="";
    int x=0, r, c;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(seats[i][j]==price)
            {
                cout<<" "<<"\e[1m"<<seats[i][j]<<"\e[0m";
                x++;
                r=i;
                c=j;
            }
            else
            {
                cout<<" "<<seats[i][j];
            }
        }
        cout<<endl;
    }
    cout<<endl;
    if(x==0)
    {
        cout<<"\e[1mNo Seat For This Price Choose Another Seat\e[0m\n\n";
        cout<<"-------------------------------\n\n";
    }
    else if (x>0)
    {
        seats[r][c]=-1;
        seat+=(r+49);
        seat+=(c+49);
    }
    return seat;
}

//assigns seats to users;
string seat11()
{
    int r, c, type, price;
    string seat1;
    //seats;
    int i=0, j=0;
    int seats[9][10]={10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                      10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                      10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                      10, 10, 20, 20, 20, 20, 20, 20, 10, 10,
                      10, 10, 20, 20, 20, 20, 20, 20, 10, 10,
                      10, 10, 20, 20, 20, 20, 20, 20, 10, 10,
                      20, 20, 30, 30, 40, 40, 30, 30, 20, 20,
                      20, 30, 30, 40, 50, 50, 40, 30, 30, 20,
                      30, 40, 50, 50, 50, 50, 50, 50, 40, 30};

    system("COLOR 3");
    //prints seats left and asks the user to select seats;
    lines();
    cout << "              TRANSPORT MANGEMENT!\n";
    lines();
    cout<<"Welcome!";
    loading();
    lines();

    //seats available;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout<<" "<<seats[i][j];
        }
        cout<<endl;
    }
    cout<<"\n-------------------------------\n\n";
    cout<<"Seats according to prices!\nNote: The one with -1 \nwritten on it are booked!\n";
    cout<<"\n-------------------------------\n\n";
    //while(type!=-99)
    //{
    system("COLOR 7");
    cout<<"Selection of Seat:\n 1.Through Seat Number\n 2.Through Price\n\nMethod: ";
    cin>>type;
    if (type==-99)//-99 ends code;
        exit;
    //check;
    while(type!=1&&type!=2)
    {
        cout<<"\nRenter Method: ";
        cin>>type;
    }
    cout<<"\n-------------------------------\n\n";

    if(type==1)
    {
        cout<<"Enter Row Number: ";
        cin>>r;
        cout<<"\nEnter Column Number: ";
        cin>>c;
        if(r==-99||c==-99) //-99 ends code
            exit;
        //check;
        while(c<1||r<1||r>9||c>10)
        {
            cout<<"\n\e[3mNo such Seat Exist!\e[0m\n\n";
            cout<<"Enter Row Number: ";
            cin>>r;
            cout<<"\nEnter Column Number: ";
            cin>>c;
        }
        r--;
        c--;

        cout<<"\n-------------------------------\n\n";
        //function for seat check;
        seat1+=seatcheck1(r, c, seats);
    }
    else if (type==2)
    {
        cout<<"Note: Price should be 10, 20, 30, 40, 50.\n";
        cout<<"Price: ";
        cin>>price;
        //-99 ends code;
        while(price!=10 && price!=20 && price!=30 && price!=40 && price!=50)
        {
            cout<<"Renter! Price Not Valid.\n";
            cout<<"Price: ";
            cin>>price;
        }
        cout<<"\n-------------------------------\n\n";
        //function for seat check;
        seat1+=seatcheck2(price, seats);
        cout<<endl;
        //}
        system("PAUSE");
        system("CLS");
    }
    //Arraycopy(seats);
    //Seats.close();
    return seat1;
}

//function to check whether username present or not;
bool checklogin(char* U)
{
    bool found = false;
    string x;
    fstream DataBase("DataBase.txt");
    found=false;
    while(!DataBase.eof())
    {
        getline (DataBase,x);
        if(U == x)
        {
            found=true;
            break;
        }
    }

    DataBase.close();
    return found;
}

//function to signup by entering it's username;
void Signup()
{
    string getcontent;
    bool check1;
    fstream DataBase("DataBase.txt", ios::app);
    cout << "Welcome New Member, \nPlease Enter a New Username and Password:\n";
    cout << "Username: ";
    cin >> U;
    check1=checklogin(U);
    if(check1==true)
    {
        cout<<"Username already Taken! \nRenter! Username: ";
        cin>>U;
    }
    check1=checklogin(U);
    if(check1==false)
    {
        cout << "\nPassword: ";
        cin >> Pass;
        DataBase << U << "\n";
        DataBase << Pass << "\n\n";
        cout << "\nYou've Signed Up Successfully!\n";
    }
    else
    {
        cout<<"\nSorry Signup Invalid! \nPlease Try Again!\n";
    }

    DataBase.close();

    delete [] U;
    delete [] Pass;
}

//function to enter the user's in the menu who already signed up;
void Login()
{
    bool found = false;
    bool check;
    string exit="4";
    fstream DataBase("DataBase.txt");
    cout << "Welcome Member, \nPlease Enter Your Username and Password:\n";
    lines();
    cout << "Username: "<<endl;
    cin >> U;


    while(!found)
    {
        if(U==exit)
        {
            cout<<"You have pressed 4 to exit!\n";
            return;
        }
        check=checklogin(U);
        if(check == false)
        {
            cout<<"Sorry Username not found!\n";
            cout << "Username: "<<endl;
            cin >> U;
        }
        else
        {
            break;
        }
    }

    cout<<"Password: "<<endl;
    cin>>Pass;


    while(!found)
    {
        if(Pass==exit)
        {
            cout<<"You have pressed 4 to exit!\n";
            return;
        }
        check=checklogin(Pass);
        if (check ==false)
        {
            cout << "\nPassword Incorrect!"<<endl;
            cout<<"Password: "<<endl;
            cin>>Pass;
        }
        else
        {
            cout << "\nPassword Correct!"<<endl;
            break;
        }
    }
    DataBase.close();
}

//just a bit of an idea and innovation of what our company main idea is;
void About()
{
    cout<<"MAHAD EXPRESS IS NOT JUST A COMPANY IT IS A DREAM! \nOUR MISSION WAS TO UPLIFT THE TRANSPORT SYSTEM \nIN PAKISTAN AND WILL KEEP WORKING UNTIL WE \nACHIEVE WHAT WE STARTED.\n\nTRAVEL WITH SAFEST AND COMFIEST RIDE IN PAKISTAN!\n";
}

//function to book anyones ride;
void Book()
{
    int x, day, month, year=21, z;
    string route[6]= {"Islamabad","Rawalpindi","Faisalabad","Lahore","Multan","Gujranwala"};
    string getcontent, destination, from, seat;
    fstream Booking;
    Booking.open("Booking.txt", ios::app);
    system ("PAUSE");
    system ("CLS");
    lines();
    cout << "              TRANSPORT MANGEMENT!\n";
    lines();
    cout<<"Destinations\n";
    lines();
    cout<<" 1.Islamabad\n 2.Rawalpindi\n 3.Faisalabad\n 4.Lahore\n 5.Multan\n 6.Gujranwala\n";
    lines();
    cout<<"Where you traveling from?\n";
    cin>>x;
    while(x<0||x>6||isalpha(x)) //check;
    {
        cout<<"Invalid Option! Renter: ";
        cin>>x;
    }
    from=route[x-1];
    cout<<"Where do you want to go?\n";
    cin>>z;
    while(z<0||z>6||isalpha(z)||z==x) //check;
    {
        cout<<"Invalid Option! Renter: ";
        cin>>z;
    }
    destination=route[z-1];
    lines();
    cout<<"Kindly Enter the Date! \n";
    cout<<"Month(1-12): ";
    cin>>month;
    while(month<1||month>12|| isalpha(x))
    {
        cout<<"Invalid Month! Renter: ";
        cin>>month;
    }
    cout<<"Day(1-30): ";
    cin>>day;
    if (month==2)
    {
        while(day<1||day>28|| isalpha(x))
        {
            cout<<"Invalid Day! Renter: ";
            cin>>day;
        }
    }
    else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        while(day<1||day>31|| isalpha(x))
        {
            cout<<"Invalid Day! Renter: ";
            cin>>day;
        }
    }
    else if(month==4||month==6||month==9||month==11)
    {
        while(day<1||day>30|| isalpha(x))
        {
            cout<<"Invalid Day! Renter: ";
            cin>>day;
        }
    }

    cout<<"Year(21/22): ";
    cin>>year;
    while((year!=21&&year!=22)||isalpha(x))
    {
        cout<<"You've entered an Invalid year! Renter: ";
        cin>>year;
    }
    //date=day+"/"+month+"/"+year;

    system ("PAUSE");
    system ("CLS");
    seat=seat11();
    //seat++;

    Booking<<U<<"\n";
    Booking<<from<<"\n";
    Booking<<destination<<"\n";
    Booking<<day<<"/"<<month<<"/"<<year<<"\n";
    Booking<<total<<"\n";
    Booking<<seat<<"\n\n";

    Booking.close();
}

//print out the detail of the user signed up;
void Details()
{
    string getcontent="";
    fstream Booking;
    Booking.open("Booking.txt", ios::in);
    system ("PAUSE");
    system ("CLS");
    lines();
    cout << "              TRANSPORT MANGEMENT!\n";
    lines();
    cout<<"Your booking Details: \n\n";
    while(!Booking.eof())
    {
        getline(Booking,getcontent);
        if(U==getcontent)
        {
            for(int i=0; i<6; i++)
            {
                //will print the details;
                if(i==0)
                    cout<<"Username: ";
                else if(i==1)
                    cout<<"From: ";
                else if(i==2)
                    cout<<"To: ";
                else if(i==3)
                    cout<<"Date: ";
                else if(i==4)
                    cout<<"Total: Rs.";
                else if(i==5)
                    cout<<"Seat: ";
                cout<<getcontent<<endl;
                getline (Booking,getcontent);
            }
            cout<<endl;
            //break;
        }
    }
    Booking.close();
}

//Will print out all the routes with timings from a file named routes;
void Routes()
{
    string getcontent;
    fstream Routes;
    Routes.open("Routes.txt", ios::in);
    system ("PAUSE");
    system ("CLS");
    lines();
    cout << "              TRANSPORT MANGEMENT!\n";
    lines();
    while(!Routes.eof())
    {
        getline(Routes,getcontent);
        cout<<getcontent<<endl;
    }
}

//the main function where it all runs;
int main()
{

    int x, y;
    string exit="4";
    while (x!=4)
    {
        lines();
        cout << "              TRANSPORT MANGEMENT!\n";
        lines();
        //prints the main menu;
        cout << "1.Login\n";
        cout << "2.Sign-Up\n";
        cout << "3.About\n";
        cout << "4.Exit\n\n";
        lines();
        x=0;
        cout << "Option: ";
        cin >> x;
        lines();
        do
        {
            switch (x)
            {
                case 1:
                {
                    Login();
                    lines();
                    system("PAUSE");
                    system("CLS");
                    //prints a menu after we're logged in;
                    //check for if user enters the main menu option;
                    while(y!=4)
                    {
                        if(x==1)
                        {
                            lines();
                            cout << "              TRANSPORT MANGEMENT!\n";
                            lines();
                            //prints a menu after we're logged in;
                            cout << "1.Book Ride\n";
                            cout << "2.Booking Details\n";
                            cout << "3.Routes\n";
                            cout << "4.Logout\n";
                            cout << "5.Exit\n\n";
                            lines();
                            cout << "Option: ";
                            cin >> y;
                            lines();

                            switch (y)
                            {
                                case 1: Book(); break;
                                case 2: Details(); break;
                                case 3: Routes(); break;
                                case 4: cout<<"Loading"; loading(); break;
                                case 5: return 0;
                                default: cout << "Not An Option!\n"; break;
                            }
                        }
                    }
                    y=0;
                    x=0;
                    break;
                }
                break;
                case 2:
                {
                    x=0;
                    Signup();
                    break;
                }
                case 3:
                {
                    x=0;
                    About();
                    break;
                }
                case 4:
                {
                    x=0;
                    return 0;
                    //break;
                }
                //break;
                default:
                {
                    cout << "Not An Option!\n"; x=0;
                    cin.clear();
                    cin.ignore();
                    break;
                }
            }
            lines();
            system("PAUSE");
            system("CLS");
        }
        while(isdigit(x));
        if(U==exit||Pass==exit)
        {
            return 0;
        }

        delete [] U;
        delete [] Pass;
    }
    return 0;
}



