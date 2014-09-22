Create Me Engine
================

What is it?
-----------

The Create Me Engine is an effort to create a general use 2D game engine that abstracts away everything it can for you. Libraries like SDL and SFML are fairly standard, but they don't abstract away anything beyond drawing images and shapes. While I don't want to downplay the huge amount of work that it takes to get libraries like that working well, it still takes a large amount of coding before a programmer can get to the fun stuff. I.e. actually making objects interact with each other.

This Project is Currently On Hiatus
-----------------------------------

I am currently taking a break from working on this project to do the workload from school and other obligations. In addition, all of the code in this project requires revising. I have learned a lot about programming since I stopped work on this project, and I have a long list of refactorings that I would need to do before continuing work on the engine. I plan on returning once I have enough experience to do this project justice.

If you still want to see the most updated version of the code, check out the development branch.

Philosophy
----------

The Create Me Engine is built with the following ideals:

* A programmer should only have to create resources and program how their objects behave
  * This means they shouldn't have to worry about collision algorithms, resource management, entity pools, input, or anything like that
  * The programmer creates children of the GameObject class and tells them how to behave in the update() method
* Keep things organized and easy to read
  * Functions and classes are kept as short as possible to prevent you from having to read and understand ten layers of 'foo->bar().baz->qux'
* Easy builds
  * The build process for the game takes care of finding and organizing your resources and telling your program where to load from
* Anything you can do in SFML you can do with the Create Me Engine
  * The Create Me Engine is meant to complement SFML, not replace it
