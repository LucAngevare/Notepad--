# General info
So this is a _really_ simple notepad app.

## Table of contents
* [General info](#general-info)
* [What and why](#what-and-why)
* [Future plans](#my-future-plans-for-this)
* [How](#technologies)

## What and why
I started making this because I wanted to start to learn C++, and I thought this was a good place to start (with datatypes, global variables, system API programming, 
using libraries, etc).
Basically this is just a text editor that doesn't support editing text, there's no save or open function (mostly because it's not finished yet).

## My future plans for this
There are a ton of things I'm planning on making with this, some things that are easier to fix than others. For example:

- [ ] Hotkeys
  * `Alt + t` to add a checkbox emoji at the start of the line the cursor is at
  * `Alt + d` to replace the empty checkbox with a checked one
- [ ] Saving
  * Create a file stream with data from textbox
  * Open and edit existing files
- [ ] Preferences
  * Ability to change theme colors 
  * Change file type

## Technologies
I made this using C++ on Windows 10. I used (MinGW.org GCC Build-2) 9.2.0 to compile and I used the Windows.h library for the actual system programming (planning to convert to SFML whenever I figure out how to install that on Windows, or program this on Ubuntu).
