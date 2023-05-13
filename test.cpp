//test file

#include <iostream>
#include <fstream>//libary for opening external files with ifstream and ofstream
#include <cstdlib>//needed for closing the external files
using namespace std;

void print_menu() {
    cout << "Select an option below by entering a letter (example: P)\n";
    cout << "P - Print numbers for a particular candidate\n";
    cout << "A - Add number of votes to a candidate\n";
    cout << "S - Display the smallest number of votes candidate\n";
    cout << "L - Display the largest number of votes candidate\n";
    cout << "Q - Quit\n";
    cout << "Enter your option: ";
}

char menu() {
    char selected;
    print_menu();

    cin >> selected;
    selected = toupper(selected);
    cout << endl;

    if (selected != 'P' && selected != 'A' && selected != 'S' && selected != 'L' && selected != 'Q') {
    cout << "Unknown Selection, Please Try Again\n" << endl;
    menu();
 }

    return selected;
}

int main() {
    while (true) {
        char selected;
        selected = menu();

        switch (selected)
        {
    //    case 'P':
    //        print_candidate_numbers();
    //      break;
    //    case 'A':
    //      add_votes_to_candidate();
    //      break;
    //    case 'S':
    //      display_lowest_candidate();
    //      break;
    //    case 'L':
    //      display_highest_candidate();
    //      break;
    //    case 'Q':
    //      exit(0);
        default:
          menu();
        }
    }

}
