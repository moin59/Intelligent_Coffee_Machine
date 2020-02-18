# author: Md Moin Uddin
# Bremen Nov.15-2019

import coffeeMachine
import os

coffee_machine = coffeeMachine.intelligent_CoffeeMachine()  # instance of coffee machine
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
