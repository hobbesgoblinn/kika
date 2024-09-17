/**---------------------------------------------
* This program displays an ASCII step pyramid and
* original ASCII art of a cat.
* Class: CS 141, Fall 2023
* System: Microsoft Visual Studio Community 2022
* @author Michelle Perez
* @version September 2, 2023
*------------------------------------------------


Original art (default size)
  | \       / |                |''\
  |   \___/   |                  \  \
  =   '|||'   =                   |  |
  |  O    O   |                   |  |
==,    /\     ,==________________/  /
  |'''-----'''   ||   ||   ||   ||  |
  |             ||   ||   ||   ||   |
  |              ||   ||   ||   ||  |
  |             ||   ||   ||   ||   |
  |              ||   ||   ||   ||  |
  |                                 |
  |,,  ,,,   ___________________\   |
   |  |  |  |              \  |  \  |
  (__|  (__|              (__/  (__/
* ------------------------------------------*/
#include <iostream>
#include <iomanip>


using namespace std;


int main() {
    // The menu output. Don't modify this, so that it outputs exactly as expected
    cout << "Program 1: Step Pyramids" << endl;
    cout << "Which option would you like?" << endl;
    cout << "  1. Display original graphic" << endl;
    cout << "  2. Display Step Pyramid" << endl;
    cout << "Your choice: ";


    int choice;
    cin >> choice;


    if (choice == 1) {
        // PICA THE CAT *****************************
        int size = 5, backLength = 20, i = 0, j = 0;
        int answer;


        // Options
        cout << "You have chosen original graphic (Pica the cat).\n"
            << "Do you want to adjust her size? Enter '1' if yes, '0' if no" << endl;
        cin >> answer;
        if (answer == 1) {
            // Size selection (default is 5)
            cout << "Enter a number: ";
            cin >> size;


            // Making sure size is positive
            if (size < 0){
                size *= -1;
            }


            // Rounding size down to multiples of 5 to make things simpler to line up
            // I left size 0 in because it looks funny
            size = size - (size % 5);
        }

        backLength = size * 4;


        // Output head and tail
        cout << "  | \\       / |" << setfill(' ') << setw(backLength + 1) << "|''\\\n"
            << "  |   \\___/   |" << setfill(' ') << setw(backLength + 3) << "\\  \\\n"
            << "  =   '|||'   =" << setfill(' ') << setw(backLength + 4) << "|  |\n"
            << "  |  O    O   |" << setfill(' ') << setw(backLength + 4) << "|  |\n"
            << "==,    /\\     ,==" << setfill('_') << setw(backLength + 1) << "/  /\n"
            << "  |'''-----'''  ";


        // Output body
        while (i < size) {
            // Output stripes
            while (j < (backLength / 5)) {
                // Staggering stripes
                if ((i % 2) > 0) {
                    cout << "||   ";
                }
                else {
                    cout << " ||  ";
                }
                j++;
            }
            // Back and front of cat
            cout << "|\n" << "  |             ";
            j = 0;
            i++;
        }


        // Output legs
        cout << setfill(' ') << setw(backLength + 2) << "|\n"
            << "  |,,  ,,,   " << setfill('_') << setw(backLength + 4) << "____\\   |" << endl
            << "   |  |  |  |" << setfill(' ') << setw(backLength + 4) << "\\  |  \\  |" << endl
            << "  (__|  (__| " << setfill(' ') << setw(backLength + 4) << "(__/  (__/ " << endl;
    }
    else if (choice == 2) {
        // STEP PYRAMID ******************************************
        int levels, firstWidth, levelsWidth, remainingLevels;


        // The prompt for entering the number of levels, if the user chooses a step pyramid
        cout << "How many levels should be in the step pyramid? ";


        cin >> levels;


        // Width added to left side by first level
        firstWidth = (levels > 0) ? 2 : 0;


        // Width added to left side by each additional level
        levelsWidth = (levels > 0) ? (levels - 1) * 6 : 0;


        // Output temple
        cout << setw(levelsWidth + firstWidth + 10) << "   _______" << endl;
        cout << setw(levelsWidth + firstWidth + 11) << "  |_______|" << endl;
        cout << setw(levelsWidth + firstWidth + 11) << "  |  ___  |" << endl;
        cout << setw(levelsWidth + firstWidth + 13) << "__|__[_]__|__" << endl;


        if (levels > 0) {
            // Output first level of pyramid
            cout << setw(levelsWidth + 16) << " /    |===|    \\" << endl;
            cout << setw(levelsWidth + 17) << "/     |===|     \\" << endl;


            // Output remaining levels
            remainingLevels = levels - 1;


            for (int i = 1; i < levels; i++) {
                // Output top of level
                cout << setw((6 * (remainingLevels - 1)) + 3) << "+" << setfill('+') << setw((i * 6) + 8) << "|===|"
                    << setw((i * 6) + 4) << "+" << endl;


                // Output second line of level
                cout << setfill(' ') << setw((6 * (remainingLevels - 1)) + 3) << "/ " << setw((i * 6) + 8) << "|===|"
                    << setw((i * 6) + 5) << "\\" << endl;


                // Output third line of level
                cout << setw((6 * (remainingLevels - 1)) + 3) << "/  " << setw((i * 6) + 8) << "|===|"
                    << setw((i * 6) + 6) << "\\" << endl;


                remainingLevels--;
            }
        }
    }


    cout << endl;
    return 0;

}

