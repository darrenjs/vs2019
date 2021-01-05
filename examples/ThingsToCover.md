

Fundamentals
============

- c++ is compiled (python is not), compiler options (-O0, -O3)
- c++ is close to the machine (address, sizeof), python more abstract
- c++ needs types everywhere (python, types are hidden)
  - overview of basic types (similar to python)
- c++ uses values, python uses references
- c++ different versions (c++98, c++11, c++17, c++20)
- printing to screen
- basic varibles
- pointers & nullptr
- primitive arrays
- pass by copy, pass by pointer, pass by reference
- returning values from a function
- c++ cares about efficiency
- const & static
- enums
- initialisers
- namespace
- preprocessor
- exceptions (throw, catch)
- string operations
- modularity (headers & libraries)
- program flow, if, while, switch, for (inc. range based)
- scope & lifetimes
- auto
- command line parsing
- conditional operator
- header files
- heap variables
- spinning (watch CPU resource)
- asserts


Tips
====

- good coding practice
- forget about identation
- dealing with compiler errors
- logging

Techniques
==========

- unittests

Forgetting Python
=================

There are some things in python we don't really have in C++, or, we have but are named differently:

- generators, coroutines, list comprehensions, decorators
- asyncio
- self
- python scope
- flexible typing


Essential STL Containers
========================

In addition, we really do need to understand basic containers:

- vector & map
- iterators
- range based for loops

Class Design
============

If you think you need to know about classes, then you need to know essentials of class design:

- basic class concept
- constructors
- destructors
- virtual classes
- override
- move semantics
- const methods & members, mutable


More STL
========

There are a lot of librarides in C++ STL, mostly very abstract things (like sorting etc), we can go through some of the most commonly used.

- thread & jthread
- regexp
- hash equivalents (just know they exist)
- essential algorithms
- std::optional
- (optional) mutex & condition variable
- string_view
- std::filesystem (maybe too new?)


Modern C++
==========

Since 2011, we are in the era of modern C++, which means the following are also now widely used:

- smart pointers
- lambda
- structured binding


Patterns
========

Optional topic.  Some programming patterns.

- singleton
- factory


Advanced
========

For more advanced stuff, don't think we really need to come here, unless you think it is needed.

- template & constexpr programming
- sockets
- memory model
- attributes
- universal ref.



Howtos
=======

You should build a collection of small how-to examples, that you can refer back to. I have listed some examples below, but if you can let me know a little more about your job role, domain area etc, I (or you) can suggest more relevant examples.

- skeleton VSC++ project
- read a file (C & C++)
- parse a file
- generate random numbers
- write a file
- regular expression
- sorting data
- use classes to model financial data
- get time & date
- convert from numbers to strings
- debug macros
- concurrent thread queue
- (and more, some more relevant to your business domain)






