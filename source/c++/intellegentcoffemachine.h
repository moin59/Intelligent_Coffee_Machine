//*.h file//Task 2

#ifndef INTELLEGENTCOFFEMACHINE_H
#define INTELLEGENTCOFFEMACHINE_H


class IntellegentCoffeMachine
{
public:
    IntellegentCoffeMachine();//constructor for initial states
    bool    LidIsOpen,  // bool for Open lid status
    filterInsert, // bool for filter insertion
    coffeeInsert, // bool for coffee insertion
    jugFill, //bool for Jug filled after the coffee has been cooked
    waterInsert; // bool for water insertion
    int waterReservoir; // class variable for water reservoir
    int coffeeReservoir; // class variable for coffee reservoir
    static const int coffeeMax=200; // max amount in grams
    static const int coffeeMin=50; // min amount in grams
    static const int waterMax=1000; // max amount in ml
    static const int waterMin=200; // min amount in ml


    // All method for coffe machine //
    void openLid(void);
    void insertFilter(void);
    void insertCoffee(int);
    void insertWater (int);
    void closeLid (void);
    void StartCooking (void);
    void takeCoffee (void);
    void switchOff (void);

private:
    bool LEDon;

};

#endif // INTELLEGENTCOFFEMACHINE_H
