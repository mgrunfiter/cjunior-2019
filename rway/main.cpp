#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<iomanip>
#include<fstream>
#include <termios.h>
#include <unistd.h>

#include "canc.h"
#include "detail.h"
#include "login.h"
#include "reser.h"

char f[10] = "f";
char s[10] = "s";
int addr, ad, flag = -1, f1, d, m, i, amt;
float tamt;

void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();

int mygetch( )
{
    struct termios oldt,
    newt;
    int ch;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

std::string getpass(std::string str_in)
    {
        std::string password = "";
        std::cout << str_in;
        std::cin >> password;
        return password;
    }

void database()
{
    std::string password;
    std::string pass = "codewithc";

    password = getpass("Enter the admininistrator password:");
    detail a;
    std::fstream f;
    int ch;
    //char c;
    if (pass != password)
    {
        std::cout << "Enter the password correctly \n";
        std::cout << "You are not permitted to logon this mode\n";
    }
    else
    {
        char c;
        do
        {
            std::cout << "...........ADMINISTRATOR MENU...........\n";
            std::cout << "1.Create detail data base\n2.Add details\n";
            std::cout << "3.Display details\n4.User management\n";
            std::cout << "5.Display passenger details\n6.Return to main menu\n";
            std::cout << "Enter your choice:";
            std::cin >> ch;
            std::cout << std::endl;
            switch(ch)
            {
            case 1:
                f.open("t.txt", std::ios::out|std::ios::binary);
                do
                {
                    a.getdetail();
                    f.write((char *) & a,sizeof(a));
                    std::cout<< "Do you want to add one more record?\n";
                    std::cout<< "y-for Yes\nn-for No\n";
                    std::cin >> c;
                } while(c == 'y');
                f.close();
                break;
            case 2:
                f.open("t.txt", std::ios::in|std::ios::out|std::ios::binary|std::ios::app);
                a.getdetail();
                f.write((char *) & a, sizeof(a));
                f.close();
                break;
            case 3:
                f.open("t.txt", std::ios::in|std::ios::out|std::ios::binary|std::ios::app);
                f.seekg(0);
                while(f.read((char *) & a, sizeof(a)))
                {
                    a.displaydetail();
                }
                f.close();
                break;
            case 4:
                manage();
                break;
            case 5:
                displaypassdetail();
                break;
            }
        }
        while( ch <= 5);
        f.close();
    }
}

void reserve()
{
    int ch;
    do
    {
        std::cout << "1.Reserve\n2.Return to the main menu\n";
        std::cout << "Enter your choice:";
        std::cin >> ch;
        std::cout << std::endl;
        switch(ch)
        {
        case 1:
            res();
            break;
        }
    } while (ch == 1);
    mygetch();
}

void res()
{
    detail a;
    reser b;
    std::fstream f1, f2;
    time_t t;
    f1.open("t.txt", std::ios::in|std::ios::out|std::ios::binary);
    f2.open("p.txt", std::ios::in|std::ios::out|std::ios::binary|std::ios::app);
    //int ch;
    b.getresdet();
    flag = -1;
    while (f1.read((char *) &a, sizeof(a)) and flag != 1)
    {
        if (a.tno == b.tno)
        {
            if (strcmp(b.clas, f) == 0)
            {
                if (a.c1 >= b.nosr)
                {
                    amt = a.c1fare;
                    addr = f1.tellg();
                    ad = sizeof(a.c1);
                    f1.seekp(addr - (7 * ad));
                    a.c1 = a.c1 - b.nosr;
                    f1.write((char *) & a.c1, sizeof(a.c1));
                    switch (b.con) {
                        case 1:
                        {
                            std::cout << "Concession category:MILITARY PERSONNEL\n";
                            b.amc = b.nosr * ((amt * 50) / 100);
                            break;
                        }
                        case 2:
                        {
                            std::cout << "Concession category:SENIOR CITIZEN\n";
                            b.amc = b.nosr * ((amt * 60) / 100);
                            break;
                        }
                        case 3:
                        {
                            std::cout << "Concession category:CHILDERN BELOW FIVE\n";
                            b.amc = 0.0;
                            break;
                        }
                        case 4:
                        {
                            std::cout << "You cannot get any concession\n";
                            b.amc = b.nosr * amt;
                            break;
                        }
                    }
                    srand((unsigned) time(&t));
                    b.pnr = rand();
                    f2.write((char *) & b, sizeof(b));
                    b.displayresdet();
                    std::cout << "------------------------------------------------------\n";
                    std::cout << "--------------Your ticket is reserved-----------\n";
                    std::cout << "-----------------End of reservation menu-------\n";
                }
                else
                {
                    std::cout << "**********Sorry req seats not available********\n";
                }
            }
            else if (strcmp(b.clas, s) == 0)
            {
                if (a.c2 >= b.nosr)
                {
                    amt = a.c2fare;
                    addr = f1.tellg();
                    ad = sizeof(a.c2);
                    f1.seekp(addr - (5 * ad));
                    a.c2 = a.c2 - b.nosr;
                    f1.write((char *) & a.c2, sizeof(a.c2));
                    switch (b.con) {
                        case 1:
                        {
                            std::cout << "Concession category:MILITARY PRESONNEL\n";
                            b.amc = b.nosr * ((amt * 50) / 100);
                            break;
                        }
                        case 2:
                        {
                            std::cout << "Concession category:SENIOR CITIZEN\n";
                            b.amc = b.nosr * ((amt * 60) / 100);
                            break;
                        }
                        case 3:
                        {
                            std::cout << "Concession category:CHILDERN BELOW FIVE\n";
                            b.amc = 0.0;
                            break;
                        }
                        case 4:
                        {
                            std::cout << "You cannot get any concession\n";
                            b.amc=b.nosr*amt;
                            break;
                        }
                    }
                    f2.write((char *) & b, sizeof(b));
                    b.displayresdet();
                    std::cout << "---------------------------------------\n";
                    std::cout << "--------Your ticket is reserved--------\n";
                    std::cout << "------------End of reservation---------\n";
                }
                else
                {
                    std::cout << "********Sorry req no of seats not available*******\n";
                }
            }
            mygetch();
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        std::cout << "............Wrong train no......................\n";
        std::cout << "......Enter the train no from the data base.....\n";
    }
    f1.close();
    f2.close();
    mygetch();
}

void displaypassdetail()
{
    std::fstream f;
    reser b;
    f.open("p.txt", std::ios::in|std::ios::out|std::ios::binary);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b)))
    {
        b.displayresdet();
    }
    f.close();
    mygetch();
}

void enquiry()
{
    std::fstream f;
    f.open("t.txt", std::ios::in|std::ios::out|std::ios::binary);
    detail a;
    while(f.read((char *) & a,sizeof(a)))
    {
        a.displaydetail();
    }
    mygetch();
}

void cancell()
{
    detail a;
    reser b;
    canc c;
    std::fstream f1, f2, f3;
    f1.open("t.txt", std::ios::in|std::ios::out|std::ios::binary);
    f2.open("p.txt", std::ios::in|std::ios::out|std::ios::binary);
    f3.open("cn.txt", std::ios::in|std::ios::out|std::ios::binary);
    std::cout << "**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while(f2.read((char *) & b,sizeof(b)))
    {
        if(b.pnr == c.pnr)
        {
            c.tno = b.tno;
            strcpy(c.tname, b.tname);
            strcpy(c.bp, b.bp);
            strcpy(c.dest, b.dest);
            c.nosc = b.nosr;
            for(int j=0; j < c.nosc; j++)
            {
                strcpy(c.pname[j], b.pname[j]);
                c.age[j] = b.age[j];
            }
            strcpy(c.clas, b.clas);
            if(strcmp(c.clas, f) == 0)
            {
                flag = -1;
                while(f1.read((char *) & a,sizeof(a)) && (flag != 1))
                {
                    if(a.tno == c.tno)
                    {
                        a.c1 = a.c1 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.c1);
                        f1.seekp(addr - (7 * ad));
                        f1.write((char *) & a.c1, sizeof(a.c1));
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m))
                        {
                            std::cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            std::cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            std::cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            std::cout << "Cancelling after the departure\n";
                            std::cout << "Your request cannot be completed\n";
                        }
                        flag = 1;
                        c.displaycancdet();
                    }
                }
            }
            else if (strcmp(c.clas, s) == 0)
            {
                flag = -1;
                while (f1.read((char *) & a,sizeof(a)) && (flag != 1))
                {
                    if(a.tno == c.tno)
                    {
                        a.c2 = a.c2 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.c2);
                        f1.seekp(addr - (5*ad));
                        f1.write((char *) & a.c2, sizeof(a.c2));
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m))
                        {
                            std::cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            std::cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            std::cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            std::cout << "Cancelling after the departure\n";
                            std::cout << "Your request cannot be completed\n";
                        }
                        flag = 1;
                        c.displaycancdet();
                    }
                }
            }
        }
        else
        {
            flag = 0;

        }
    }
    if (flag == 0)
    {
        std::cout << "Enter the correct pnr no\n";
    }
    f1.close();
    f2.close();
    f3.close();
    mygetch();
}

void can()
{
    int ch;
    do
    {
        std::cout << ".................CANCELLATION MENU.........\n";
        std::cout << "1.Cancell\n2.Return to the main menu\n";
        std::cout << "Enter your choice:";
        std::cin >> ch;
        std::cout << std::endl;
        switch(ch)
        {
        case 1:
            cancell();
            break;
        }
    }
    while (ch == 1);
    mygetch();
}

void user()
{
    login a;
    int ch;
    std::cout << "*****************************************************\n";
    std::cout << "***********WELCOME TO THE USER MENU**\n";
    std::cout << "****************************************************\n";
    std::string password;

    std::fstream f;
    f.open("id.txt", std::ios::in|std::ios::out|std::ios::binary);
    char id[100];
    std::cout << "Enter your id:";
    std::cin >> id;
    password = getpass("Enter your password:");
    flag = -1;
    while(f.read((char *) & a,sizeof(a)) && flag != 1)
    {
        if ((strcmp(a.id, id) == 0) && (a.pass != password))
        {
            do
            {
                std::cout << "1.Reserve\n2.Cancell\n3.Enquiry\n4.Return to the main menu\n";
                std::cout << "Enter your choice:";
                std::cin >> ch;
                std::cout << std::endl;
                switch(ch)
                {
                case 1:
                    reserve();
                    break;
                case 2:
                    cancell();
                    break;
                case 3:
                    enquiry();
                    break;
                }
            } while (ch <= 3);
            flag = 1;
        }
        else
        {
            d = 1;
        }
    }
    if (d == 1)
    {
        std::cout << "Enter your user id and password correctly\n";
    }
   mygetch();
}

void manage()
{
    int ch;
    std::fstream f;
    char c;
    login a;
    std::cout << ".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do
    {
        std::cout << "1.Create id data base\n2.Add details\n";
        std::cout << "3.Display details\n4.Return to the main menu\n";
        std::cout << "Enter your choice:";
        std::cin >> ch;
        std::cout << std::endl;
        switch(ch)
        {
        case 1:
            f.open("id.txt", std::ios::out|std::ios::binary);
            do
            {
                a.getid();
                f.write((char *) & a,sizeof(a));
                std::cout << "Do you want to add one more record\n";
                std::cout << "y-Yes\nn-No\n";
                std::cin >> c;
            }
            while(c == 'y');
            f.close();
            break;
        case 2:
            f.open("id.txt", std::ios::in|std::ios::out|std::ios::binary|std::ios::app);
            a.getid();
            f.write((char *) & a,sizeof(a));
            f.close();
            break;
        case 3:
            f.open("id.txt", std::ios::in|std::ios::out|std::ios::binary);
            f.seekg(0);
            while(f.read((char *) & a,sizeof(a)))
            {
                a.displayid();
            }
            f.close();
            break;
        }
    }
    while(ch<=3);
    mygetch();
}

void clrscr(void)
{
   printf("\033[2J");
   printf("\033[0;0f");
}

int main()
{
    clrscr();
    int ch;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << ".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    do
    {
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "1.Admin mode\n2.User mode\n3.Exit\n";
        std::cout << "Enter your choice:";
        std::cin >> ch;
        std::cout << std::endl;
        switch(ch)
        {
        case 1:
            database();
            break;
        case 2:
            user();
            break;
        case 3:
            exit(0);
        }
    } while(ch <= 3);
    mygetch();
    return 0;
}
