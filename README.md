Create Me Engine
================

What is it?
-----------

The Create Me Engine is an effort to create a general use 2D game engine that abstracts away everything it can for you. Libraries like SDL and SFML are fairly standard, but they don't abstract away anything beyond drawing images and shapes. While I don't want to downplay the huge amount of work that it takes to get libraries like that working well, it still takes a large amount of coding before a programmer can get to the fun stuff. I.e. actually making objects interact with each other.

The engine is a work in progress!!!!!
-------------------------------------

Please remember that this is heavily a work in progress. I'll be making legacy-breaking changes on a very regular basis. It's buggy, inefficient, doesn't have a build system for anything besides linux, and will probably segfault if you look at it funny. However, it's almost "feature complete" meaning it will at least attempt to do everything I want it to do. The big reason that there will be a lot of game-breaking bugs is because I plan on doing what I can to shrink down as much of the verbose code as I can. At the moment it takes a chain of about three or four ->'s in order to do anything. In addition, the main way of creating objects is just using a *new*. Yeah, it hurts, doesn't it? In addition, I'm still in the middle of getting my CS degree. This means I won't understand much about making things efficient at least until the end of the Winter 2014 semester (I'm taking a class). Until then, I'm just going to iron out crashing bugs, memory leaks, and segfaults, and I'll be working on making it easier to use. So please don't try to make anything with this yet.

But please, look at the code and critique it. I'm always happy to take suggestions as I build this thing.

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
