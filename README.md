# Intelligent_Coffee_Machine
An interactive object oriented python program
Making coffee seems to be very simple since (almost) everybody knows how to do it. However, to train thinking in an object-oriented way, a coffee machine class behavior.

Created a class IntelligentCoffeeMachine that fulfills the following requirements:
(1). Prerequisites: For simplification we assume that we have a coffee machine with fixed water and coffee reservoir and the coffee jug is not used for water insertion, but some external jug.

(2). R02 User interaction: The user wants to be able to interact with the coffee machine(IntelligentCoffeeMachine class) as follows:
a- Open lid
b- Insertfilter
c- Insert coffe
d- Insert water
e- Close lid
f- Start cooking
g- Take coffee
h- Switch off

(3). Intelligence in general: The intelligence of the coffee machine prevents wrong actions. In General the internal states have to be checked before action execution (Eg Opening the lid is onlypossible in case the lid is not already open). In case of wrong user interaction the user is informed with a respective text message. See following requirements for special status requirements thatdepend on each other.

(4). Intelligent coffee insertion: Coffee can only be inserted into the caseis inserted. Respect the maximum content of the coffee reservoir.

(5). Intelligent water insertion: Water can only be used in case of open lid. Respect the maximum content of the water reservoir.

(6). Intelligent cooking: Coffee can only be prepared if minimum amount of water and coffee are in the reservoirs. When the user switches on the coffee machine to start cooking, a power LEDis lit.Since we do not have parallel threads here, the coffee is simulated by a timer or aloop (blocking behavior). Visualization of the cooking progress could be helpful. After finishing ofthe cooking procedure the jug is empty and the water reservoir is empty.

(7). Intelligent coffee taking: The user is allowed to take the coffee when the cooking procedure is finished. This means the jug is filled with coffee. Before taking the coffee he makes the coffee machine to stop himself switched on. (We assume that the user does not want to keep the coffee heated and probably drinks all the coffee at once, or has some friends / colleagues to share the coffee with ...)

(8). Intelligent clean up: After the coffee has been cooked, the old filter must be taken out anda new one inserted before filling in new coffee.
