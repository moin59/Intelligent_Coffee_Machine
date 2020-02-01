//Md Moin Uddin //2981051
//main.cpp //Task 2

#include <iostream>
#include"intellegentcoffemachine.h"
#include <time.h>
#include<stdlib.h>
#include <cstdlib>
#include<unistd.h>  //for linux to use pause

using namespace std;


int main()
{
    //Clear the screen for linux & windows
    //system("clear");
    //system("CLS")

    IntellegentCoffeMachine coffee; //DECLARING THE OBJECT

    char userOption=' ';

    while(userOption!='E')
    {
        system("clear");  //TO CLEAR THE SCREEN AFTER EVERY OPTION IS SELECTED
        //so that the MENU is not printed again and again
        //system("CLS")


        cout<<" "<<endl;
        cout<<" =================INTELLEGENT MENU================"<<endl
            <<" | Select <numbers> from the following Options   |"<<endl
            <<" | 1- Open the Lid                               |"<<endl
            <<" | 2-Insert new filter                           |"<<endl
            <<" | 3-Insert coffee (50 grams) per selection      |"<<endl
            <<" | 4-Insert water (200 ml per selection          |"<<endl
            <<" | 5-Close Lid                                   |"<<endl
            <<" | 6-Start cooking                               |"<<endl
            <<" | 7-Take coffee                                 |"<<endl
            <<" | 8-Switch off the machine                      |"<<endl
            <<" | 9-Check Water and Coffee Reservoir            |"<<endl
            <<" |                  <'e' to EXIT>                |"<<endl
            <<" ================================================="<<endl
            <<"Choose any option by type from 1 to 9 or 'e' for EXIT): ";
        cin >> userOption;
        cout << endl << "STATUS:" <<endl;
        switch(userOption)
        {
        case '1':
            coffee.openLid();
            break;
        case '2':
            coffee.insertFilter();
            break;
        case '3':
            coffee.insertCoffee(50);
            break;
        case '4':
            coffee.insertWater(200);
            break;
        case '5':
            coffee.closeLid();
            break;
        case '6':
            coffee.StartCooking();
            break;
        case '7':
            coffee.takeCoffee();
            break;
        case '8':
            cout<<"Switching Off... \n";
            sleep(5);
            coffee.switchOff();
            break;
        case '9':
            cout    << "The water reservoir is: " << coffee.waterReservoir <<endl
                    << "The coffee reservoir is: " << coffee.coffeeReservoir <<endl;
            break;
        case 'e':
            cout <<"Exited from Intellegent Menu" <<endl;
            break;
        default:
            cout << "Enter the correct option." <<endl;
        }
        cout<<endl;
        if (userOption=='e') break;

        cout <<"Now for further Selections, ";

        //pause everytime when the status has been printed
        //system("PAUSE"); //for windows OS
        sleep(5); //for linux OS
    }
    return 0;
}
