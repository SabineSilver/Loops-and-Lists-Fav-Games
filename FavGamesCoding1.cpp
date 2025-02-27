// FavGamesCoding1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {

    cout << "Welcome! Today we're going to list our favorite games.\n";

    cout << "Type 'Add' to add a game, 'Edit' to edit your list, 'Remove' to remove a game, 'Show' to view your list, and 'Quit' to quit.\n";

    string favGames[10];

    int currentElement = 0;

    while (currentElement <= 10) {
        //WHY IS THIS REPEATING TWICE????!?!!?
        //I can't figure out why this line repeats twice ony sometimes (or at all), I've tried reordering things but nothing works without breaking the code :(
        cout << "What would you like to do?\n";     //added this here instead, fixed a lot, sometimes it repeats extra though? every time excpet after show (and quit)???
        
        string input;
        getline(cin, input);        //ok moving this stuff inside the loop lets me input more games but im not sure it's working 100% the way i want

        if (input == "Add") {
            cout << "What is the name of the game you would like to add?\n";
            cin >> input;
            favGames[currentElement++] = input;
        }       //i can't get this to end the input gets stuck I've tried everything I can think of. I've been trying to fix just this for 3 hours now. Fixed, thank god
        
        else if (input == "Edit") {
            cout << "What game would you like to edit?\n";
            cin >> input;
            cout << "Searching the list...\n";
            cout << "Found it! What would you like to change it to?\n";
            for (int i = 0; i < 10; i++) {
                if (input == favGames[i]) {
                    cin >> input;
                    favGames[i] = input;
                    cout << "Amended!\n";
                }
            }

        }

        else if (input == "Remove") {
            cout << "What game would you like to remove?\n";
            cin >> input;
            cout << "Searching the list...\n";
            cout << "I've found the game, removing it now.\n";
            for (int i = 0; i < 10; i++) {
                if (input == favGames[i]) {
                    favGames[i] = "";
                }
            }

        }

        else if (input == "Show") {
            for (int i = 0; i < 10; i++) {
                // this is how we skip removed or not-yet-added lines in our array
                if (favGames[i] == "") {
                    continue;
                }
                else {
                    cout << favGames[i] << ".\n";

                }       //This is only showing the first game in the list for some reason, might need to find a way to loop it? Fixed
            }

        }
        //i took the else statement thing here out because it kept repeating infinitely and I don't know why
        if (input == "Quit") {
            return 0;

        }
        if (currentElement >= 10) {
            cout << "All done! Here's all your favorite games!\n";
            for (int i = 0; i < 10; i++) {
                if (favGames[i] == "") {
                    continue;
                }
                else {
                    cout << favGames[i] << ".\n";

                }
            }
            return 0;       //YES FINALLY this part is working you have no idea how many tests this took
        }

    }

}

/*
ok, next things to work on for after dinner me
first text of while loop repeats twice after add and remove (not others)??? figure out why
test each choice fully
I think remove isnt going into the actual remove function, stops at searching the list... Fixed
okk it is removing the game correctly, just not giving the text indicating that it did. Also double What do you want to do
*/