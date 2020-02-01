//*.cpp file//Task 2

#include "intellegentcoffemachine.h"
#include<iostream>
#include<string>
#include<unistd.h>

using namespace std;

//Contrcuctor Intelligent Coffee Machine
IntellegentCoffeMachine::IntellegentCoffeMachine()
{
    cout << "Wecome to the Intelligent Coffee Machine"<<endl;

    // Here we set all the Class Variables to default states
    LidIsOpen=false;
    LEDon=false;
    filterInsert=false;
    coffeeInsert=false;
    waterInsert=false;
    jugFill=false;
    waterReservoir=0;
    coffeeReservoir=0;
}

//Lid Open Method
void IntellegentCoffeMachine ::openLid(void)
{
    if(!LidIsOpen) //If lid is open
    {
        LidIsOpen=true; //Set bool = True
        cout << endl <<"Lid has been opened." <<endl;
    }
    else cout << endl << "Lid is already open!, Insert filter now." <<endl;

}

//Insert Filter Method
void IntellegentCoffeMachine::insertFilter(void)
{
    if(LidIsOpen) //if lid is open
    {
        filterInsert=true;
        cout << endl << "Filter has been inserted." <<endl;
    }
    else//otherwise prints the following message
    {
        cout << endl << "WARNING: Open the lid first..." << endl ;
    }

}

//Insert Coffe Methode
void IntellegentCoffeMachine::insertCoffee(int coffeeAmountInserted)
{
    if(!LidIsOpen) //first check if lid is open
        cout << "WARNING: Open the Lid first..."<<endl;
    else if(!filterInsert) //Then if lid is not open
        cout << "WARNING: Insert the Coffee Filter first... "<<endl;
    else // nowcoffe can insert
    {
        int newCoffeeReservoir=0; // temporary variable
        newCoffeeReservoir=coffeeReservoir+coffeeAmountInserted; // new resevoir muse equal to this
        //coffeeAmountInserted is the function argument

        //if newCoffeeReservoir is in the range then do the following
        if (newCoffeeReservoir <= coffeeMax && newCoffeeReservoir >= coffeeMin)
        {
            cout << coffeeAmountInserted << "grams of Coffee has been inserted."<<endl;
            coffeeInsert=true;
            coffeeReservoir=newCoffeeReservoir; //set the actual attribute "coffeeReservoir" with "newCoffeeReservoir"
        }
        else //otherwise print the following message
        {
            cout << "Remaining Space for Coffee: " <<coffeeMax-coffeeReservoir<<" grams of coffee."<<endl ;
        }
    }
}

//Insert water method
void IntellegentCoffeMachine::insertWater(int water) // "water" is the argument for water insertion
{

    if(!LidIsOpen) //First check lid is open or not
        cout << "WARNING: Open the Lid first..."  <<endl;
    else
    {   int newWaterReservoir=0; //Temporary initialization of newWaterReservoir
        newWaterReservoir=waterReservoir+water; // newWaterReservoir must be equal to previous + inserted
        if (newWaterReservoir <= waterMax && newWaterReservoir >= waterMin) //check if it's in side the range
            //then do the following
        {
            cout << water << "ml of Water has been inserted." <<endl;
            waterInsert=true;
            waterReservoir=newWaterReservoir; //set the actual attribute "waterReservoir" to the valid newWaterReservoir
        }
        else //otherwise print the following message
        {
            cout << "Remainig Space for Water: " << waterMax - waterReservoir << " ml of water."<<endl;
        }

    }
}

//closed lid methos
void IntellegentCoffeMachine::closeLid(void)
{
    LidIsOpen=false; //LID bceomes closed in the attributes
    cout << "Lid has been closed.";
}

//Start coocking methode
void IntellegentCoffeMachine::StartCooking(void)
{
    if (!LidIsOpen && waterInsert && coffeeInsert) //check this
    {
        cout << "Cooking has been started."<<endl;
        LEDon=true;
        //======SETTING THE BLOCKING STATE=====
        double Start = clock(); //with clock timer
        double dDuration=0;
        cout << "Please wait....."<<endl;

        while(dDuration<5) //wait till dDuration exceeds 5 secs
        {
            dDuration=(clock()-Start)/CLOCKS_PER_SEC; //calculate till it is greater then 3
        }

        //======SETTING THE BLOCKING STATE ENDS HERE=====
        //we assume that the jug automatically fills after the cooking has been done
        cout << "Cooking done, now filling the jug..." << endl;
        jugFill=true; // user can take coffee if jugfilled=true after cooking
        coffeeReservoir=0; // Empty coffe reservoir
        waterReservoir=0;
        LEDon=false; // LED switched off
        sleep(4);
        cout << endl <<"Jug has filled." <<endl;
    }
    else
    {
        cout << endl << "WARNING: Cannot start cooking, Please make sure:";
        cout << " \n\t 1- Lid is closed. \n\t 2- Water is present \n\t 3- Coffee is inserted." <<endl;
    }

}

//TO take coffe method
void IntellegentCoffeMachine::takeCoffee(void)
{
    if(jugFill && waterReservoir==0 && coffeeReservoir==0) //check these conditions
    {
        cout << endl << "Coffee is ready for you!";
        cout << endl << "You can take coffee from the Jug" <<endl;
    }
    else
    {
        cout << endl << "WARNING: You can't take coffee!! \n";
        cout << "still Coffe has not cooked" <<endl;
    }
}

void IntellegentCoffeMachine::switchOff(void)
{
    //set to all variable as default value
    //After take all coffee
    coffeeInsert=false;
    waterInsert=false;
    jugFill=false;
    waterReservoir=0;
    coffeeReservoir=0;
    filterInsert=false;
    cout<<"Machine has been Switched OFF! \n";
}
