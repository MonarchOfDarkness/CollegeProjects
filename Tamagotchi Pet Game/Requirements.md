# Prompt:
Create a virtual pet care game where players can choose a cute pet and then feed, train, or play-with
it. The game is based on a simple game loop, where at the beginning of each loop, the game
notifies the player of the current pet status (hungry, sleepy, bored, etc.) The player should then
select the corresponding actions to improve the status of the pet. After each action, the game loop
is repeated and the pet values are updated. The status should be displayed along with the
corresponding messages as well as the menu of actions.

# Design Requirements:
Implement the Pet class

• Create the base Pet class. It should manage variables that keep track of the pet’s state, such as
how hungry/sleepy/bored/happy the pet is currently.

• Include a minimum of three (3) interaction functions that change those variables. For example,
playing with a pet will make it less bored but might make it more hungry.

• Include a function that updates the pet’s state values to reflect the passage of time. For
example, you can make a nextHour() that will make the pet more hungry, bored, and sleepy by
increasing those variables by some amount. If any of the variables are above some threshold
(such as 40 out of 100), the function should output the corresponding message such as “<Pet
name> is hungry!”
  
• Each Pet class should have a method to save and load all of its data onto or from a file, to allow
the player to continue with an existing pet.
