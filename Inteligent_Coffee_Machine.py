import os
import time


# Defined class for coffee machine
class Intelligent_CoffeeMachine():

    # some condition initialized as boolean and set initial value
    def __init__(self):
        # boolean expression
        self.lidIsOpen = False
        self.filterIsInsert = False
        self.coffeeIsInsert = False
        self.waterIsInsert = False
        self.jugIsFill = False
        self.LEDon = False

        # initialize of coffee reservoir
        self.coffee_min = 50
        self.coffee_max = 200
        self.coffeeReservoir = 0
        self.coffeeAmountInsert = 0
        self.newCoffeeReservoir = 0

        # initialize of water reservoir
        self.water_min = 200
        self.water_max = 1000
        self.waterReservoir = 0
        self.newWaterReservoir = 0
        self.waterAmountInsert = 0

    # function for lid open
    def openLid(self):
        if self.lidIsOpen is not True:
            self.lidIsOpen = True
            print("lid is opened")

            # return self.lidIsOpen = True
        else:
            print("Lid is already opened")

    # function for filter insert, also depend on lid is open
    def filterInsert(self):
        if self.lidIsOpen is True:
            self.filterIsInsert = True
            print("Filter is inserted")
        else:
            print("Please open the lid first")

    # function for some amount of coffee insert, depended on Lid closed and filter insert
    def insertCoffee(self, coffeeAmountInsert):
        self.coffeeAmountInsert = coffeeAmountInsert
        if self.lidIsOpen is not True:
            print("Please open the lid first")

        elif self.filterIsInsert is not True:
            print("Please insert the filter first")
        else:
            self.newCoffeeReservoir = self.coffeeReservoir + coffeeAmountInsert

            if self.coffee_max >= self.newCoffeeReservoir >= self.coffee_min:
                print(coffeeAmountInsert, "grams of Coffee has been inserted")
                self.coffeeIsInsert = True
                self.coffeeReservoir = self.newCoffeeReservoir
                print(self.newCoffeeReservoir)
            else:
                print("Remaining space for the coffee: ", self.coffee_max - self.coffeeReservoir, "grams of coffee")

    # function for water insert to the reservoir, dependent on if lid is not open.
    def insertWater(self, waterAmountInsert):
        if self.lidIsOpen is not True:
            print("Please open the lid first")

        else:

            self.newWaterReservoir = self.waterReservoir + waterAmountInsert

            if self.water_max >= self.newWaterReservoir >= self.water_min:
                print(waterAmountInsert, "ml of water has been inserted")
                self.waterIsInsert = True
                self.waterReservoir = self.newWaterReservoir
            else:
                print("Remaining space for the water: ", self.water_max - self.waterReservoir, "ml of water")

    # function for lid close, no dependency.
    def closeLid(self):
        self.lidIsOpen = False
        print("Lid has been closed.")

    # function for start cooking coffee, lid should be closed if it is open
    def startCoocking(self):
        if self.lidIsOpen is False and self.waterIsInsert is True and self.coffeeIsInsert is True:
            print("Coffee is cooking!")
            self.LEDon = True
            timer = 0

            while timer < 5:
                timer = timer + 1
                self.jugIsFill = True
                self.coffeeReservoir = 0
                self.waterReservoir = 0
                self.LEDon = False
                print(timer)
                time.sleep(3)

            print("Cooking finished, Jug is filling now...")
            time.sleep(5)
            print("Jug is filled")

        else:
            print("WARNING! Can not start coocking")
            print("Please make sure following things are done")
            print("1- Lid is Closed \n"
                  "2- Water is Sufficient \n"
                  "3- Coffee is Filled \n")

    # function for taking coffee, dependent on jug filled by coffee
    def takeCoffee(self):
        if self.jugIsFill is True and self.waterReservoir == 0 and self.coffeeReservoir == 0:
            print("Coffee is ready for you \n"
                  "Enjoy your coffee \n")

        else:
            print("Still coffee has not cooked")

    # function for machine switch off.
    def switchOff(self):
        self.coffeeIsInsert = False
        self.waterIsInsert = False
        self.jugIsFill = False
        self.filterIsInsert = False
        self.coffeeReservoir = 0
        self.waterReservoir = 0
        print("Machine is Switching OFF!...")
        time.sleep(5)
        print("Machine has been switched OFF!")


coffee_machine = Intelligent_CoffeeMachine()  # instance of coffee machine

user_option = " "
# while loop for user menu, until press 'e' loop will continue
while user_option != 'e':
    os.system('cls')
    print(" =================INTELLIGENT MENU================\n"
          "| Select <numbers> from the following Options   | \n"
          "| 1- Open the Lid                               | \n"
          "| 2-Insert new filter                           | \n"
          "| 3-Insert coffee (50 grams) per selection      | \n"
          "| 4-Insert water (200 ml) per selection         | \n"
          "| 5-Close Lid                                   | \n"
          "| 6-Start cooking                               | \n"
          "| 7-Take coffee                                 | \n"
          "| 8-Switch off the machine                      | \n"
          "| 9-Check Water and Coffee Reservoir            | \n"
          "|                  <'e' to EXIT>                | \n"
          "================================================= \n"
          "Choose any option by type from 1 to 9 or 'e' for EXIT):")

    user_option = input()
    # condition of user input. call each object of class"intelligent_CoffeeMachine()" by instance "coffee_machine"
    if user_option == str(1):
        coffee_machine.openLid()
    elif user_option == str(2):
        coffee_machine.filterInsert()
    elif user_option == str(3):
        coffee_machine.insertCoffee(50)
    elif user_option == str(4):
        coffee_machine.insertWater(200)
    elif user_option == str(5):
        coffee_machine.closeLid()
    elif user_option == str(6):
        coffee_machine.startCoocking()
    elif user_option == str(7):
        coffee_machine.takeCoffee()
    elif user_option == str(8):
        coffee_machine.switchOff()
    elif user_option == str(9):
        print("The water remained", coffee_machine.waterReservoir, "ml")
        print("The coffee remained", coffee_machine.coffeeReservoir, "grams")
    else:
        print("Operation Closed!")
