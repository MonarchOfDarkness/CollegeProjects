# Introduction
Virtual pet care games are popular & entertaining applications that allow users to create &
interact with cute & realistic pets. These games simulate the experience of owning & caring for a
pet, such as feeding, playing, training, or grooming them. Virtual pet care games can also
provide educational and emotional benefits for users, such as learning about animal behavior,
developing empathy & responsibility, or reducing stress & loneliness.
The main problem/challenge that this project aims to solve or address is to create a virtual pet
care game that is fun, engaging, & easy to use. The game should allow users to choose from
different types of pets, each with their unique attributes, abilities, & interactions. The game
should also provide a simple & intuitive menu system that lets users perform various actions
with their pets, such as feeding, sleeping, playing, or saving and loading their data. The game
should also update the status of the pets according to the passage of time & the user actions, and
display the status along with the corresponding messages.
The main features and benefits of the program are:
• It allows users to create and customize their virtual pets from different types of animals,
such as dragons, unicorns, or (Pokémon)mew.
• It provides users with various interactions with their pets, such as feeding, sleeping,
playing, or using special abilities like breathing fire, healing, or using psychic powers.
• It uses a simple game loop that updates the status of the pets according to the passage of
time and the user's actions and displays the status along with the corresponding messages.
• It uses a smart pointer to store the pet object and polymorphism to handle different types
of pets and their behaviors.
• It uses file I/O to save & load the pet data to allow users to continue with an existing pet.

# Design
The design of the program is based on the object-oriented programming (OOP) paradigm, which
uses classes and objects to model the system. The program consists of four classes: Pet, Dragon,
Unicorn, and Mew. The Pet class is the base class for all types of pets, and the Dragon, Unicorn,
and Mew classes are derived from the Pet class. 

The rationale behind the design choices is to support the objectives and functionality of the
program. The Pet class defines the common attributes and operations for all types of pets, such as
name, hunger, sleepiness, boredom, happiness, feed, sleep, play, nextHour, displayStatus, save, 
and load. The Dragon, Unicorn, and Mew classes define the specific attributes and operations for
each type of pet, such as fire, magic, psychic, moves, breatheFire, fly, heal, useMagic,
usePsychicPowers, & learnMove. The inheritance relationships allow the derived classes to
inherit the attributes and operations from the base class and override or add new ones as needed.
The polymorphism relationships allow the program to handle different types of pets and their
behaviors using a single pointer to the base class.

The design patterns, principles, or best practices that were followed or applied in the
design process are:

• The Liskov Substitution Principle (LSP), states that objects of a superclass should be
replaceable by objects of its subclasses without breaking the program. This principle
ensures that the derived classes conform to the behavior and contract of the base class.

• The Open-Closed Principle (OCP), states that software entities should be open for
extension but closed for modification. This principle ensures that the base class can be
extended by adding new subclasses without modifying its existing code.

• The Single Responsibility Principle (SRP), states that every class should have a single
responsibility and that responsibility should be entirely encapsulated by the class. This
principle ensures that the classes are cohesive and modular and that they have clear and
well-defined roles.

# Functionality
The main functionality of the program is to create & interact with virtual pets of different types.
The program uses a simple game loop that runs repeatedly until the user exits. The game loop
consists of the following steps:

• Display the main menu and ask the user to choose an option.

• If the user chooses to create a new pet, display the create pet menu and ask the user to
choose a type of pet and enter a name for it. Then, create a new pet object of the chosen
type and assign it a random starting state.

• If the user chooses to load an existing pet, display the load pet menu and ask the user to
enter the name of the file to load from. Then, open the file and read the type of pet and its
state. Then, create a new pet object of the read type and assign it the read state.

• If the user chooses to interact with their pet, display the interaction menu and ask the user
to choose an action. Then, act on the pet object and update its state accordingly. Also,
display any messages or feedback related to the action.

• If the user chooses to save their pet, display the save pet menu and ask the user to enter
the name of the file to save to. Then, open the file and write the type of pet and its state.
Then, close the file.

• If the user chooses to exit, end the game loop and terminate the program.

The program works by using a smart pointer to store a single pet object at a time. The pointer can
point to any type of pet object, such as Dragon, Unicorn, or Mew. The program uses
polymorphism to handle different types of pets and their behaviors using a single pointer. For 
example, when saving or loading a pet object, the program calls the save or load function of the
pointer, which invokes the overridden function of the derived class.

The following are some examples of how the program works:

Example 1: Creating a new dragon pet

Welcome to Virtual Pet Care! Please choose an option:
1. Create a new pet
2. Load an existing pet
3. Interact with your pet
4. Save your pet
5. Exit 1 Please choose a type of pet:
6. Dragon
7. Unicorn
8. Mew 1 Please enter a name for your pet: Smaug You have created a new pet!

Example 2: Interacting with a unicorn pet

Name: Luna Hunger: 40/100 Sleepiness: 30/100 Boredom: 20/100 Happiness: 80/100 Magic:
50/100
Interaction Menu
1. Feed
2. Sleep
3. Play
4. Heal
5. Use Magic
6. Back to Main Menu 5 Luna uses its magical powers!

# Use Cases
The program provides five menu options for the user to interact with the program and their pet.
The menu options & their use cases are described below, using UML tables.

1. Create a new pet
o This option allows the user to create a new pet of their choice and give it a name.

o The outcome of this option is that a new pet object is created and assigned to the
pointer, and its state is initialized randomly.

o The user input involved in this option is choosing a type of pet and entering a
name for it.

o The output involved in this option is displaying the create pet menu and
confirming the creation of the new pet.

o The feedback involved in this option is displaying any messages or errors related
to the creation of the new pet.

o The error handling involved in this option is validating the user input and
handling any invalid choices or names.

2. Load an existing pet

o This option allows the user to load an existing pet from a file.

o The outcome of this option is that an existing pet object is loaded and assigned to
the pointer, and its state is restored from the file.

o The user input involved in this option is entering the name of the file to load from.

o The output involved in this option is displaying the load pet menu and confirming
the loading of the existing pet.

o The feedback involved in this option is displaying any messages or errors related
to the loading of the existing pet.

o The error handling involved in this option is validating the file name and handling
any file I/O exceptions or invalid data.

3. Interact with your pet

o This option allows the user to interact with their pet and perform various actions,
such as feeding, sleeping, playing, or using special abilities.

o The outcome of this option is that the pet object is updated and its state is changed
according to the action performed. The program also displays any messages or
feedback related to the action.

o The user input involved in this option is choosing an action from the interaction
menu.

o The output involved in this option is displaying the interaction menu and the
status of the pet before and after the action.

o The feedback involved in this option is displaying any messages or feedback
related to the action, such as “Your pet is happy!” or “Your pet is hungry!”.

o The error handling involved in this option is validating the user input and
handling any invalid choices or actions.

4. Save your pet

o This option allows the user to save their pet data to a file.

o The outcome of this option is that the pet object is saved and its state is written to
the file.

o The user input involved in this option is entering the name of the file to save.

o The output involved in this option is displaying the save pet menu and confirming
the saving of the pet data.

o The feedback involved in this option is displaying any messages or errors related
to the saving of the pet data.

o The error handling involved in this option is validating the file name and handling
any file I/O exceptions or errors.

# Conclusion
This report has summarized the progress and status of the virtual pet care game project, which
aims to create a fun, engaging, and easy-to-use game that allows users to create and interact with
different types of pets. The report has described the design, functionality, and use cases of the
program, using UML diagrams/tables. The report has also highlighted the key features and
benefits of the program, such as:

• It allows users to create and customize their virtual pets from different types of animals,
such as dragons, unicorns, or mews.

• It provides users with various interactions with their pets, such as feeding, sleeping,
playing, or using special abilities like breathing fire, healing, or using psychic powers.

• It uses a simple game loop that updates the status of the pets according to the passage of
time and the user's actions and displays the status along with the corresponding messages.

• It uses a smart pointer to store the pet object and polymorphism to handle different types
of pets and their behaviors.

• It uses file I/O to save and load the pet data to allow users to continue with an existing
pet.

The progress & status of the project is satisfactory and on track. The project has achieved most
of its objectives & delivered a working prototype of the program. The project has also
encountered some challenges, difficulties, or risks that were overcome or mitigated. For
example:

• The project had to deal with some complexity & diversity in designing & implementing
different types of pets and their behaviors. The project used inheritance & polymorphism
to simplify & generalize the code and reduce duplication.

• The project had to handle some errors or exceptions that might occur when reading or
writing files. The project used try-catch blocks to catch any file I/O exceptions and
display appropriate messages.

• The project had to ensure that the program is user-friendly and intuitive. The project used
a simple and consistent menu system that guides the user through the options and actions.
The project also has some recommendations or suggestions for future work or improvement of
the program. For example:

• We can add more types of pets or interactions to increase the variety and fun of the game.

• We can improve the graphics or sounds of the game to make it more appealing &
realistic.

• The project can implement some features or functions that enhance the user experience or
convenience, such as a help menu, a pause option, or a save reminder.
