//test file

#include <iostream>//header file for lots of C++ functions
#include <fstream>//libary for opening external files with ifstream and ofstream
#include <sstream>//header file for classes
#include <cstdlib>//needed for closing the external files
#include <string>//header file for using strings
#include <vector>//header file for vector
using namespace std;

//const string VOTER_FILE = "voters.txt";
//const string CANDIDATE_FILE = "candidates.txt";

vector<vector<string>> read_voters_from_file() {
    vector<vector<string>> voters = {};
    string voter_line;

    ifstream voters_file;
    voters_file.open("voters.txt");
    
    if (voters_file.fail()) {
        cout << "File open failed." << endl;
    }
    
    while (getline(voters_file, voter_line)) {
        stringstream ss(voter_line);
        vector<string> row = {};
        string voter_data;
        
        while (getline(ss, voter_data, ',')) {
            row.push_back(voter_data);
        }
        
        voters.push_back(row);
    }

    voters_file.close();
    
/*    for (auto row : voters) {
            for (auto field : row) {
               cout << field << " ";
            }
            cout << endl;
    }
*/
    
    return voters;
}

vector<vector<string>> read_candidates_from_file() {
    vector<vector<string>> candidates = {};
    string candidate_line;

    ifstream candidates_file;
    candidates_file.open("candidates.txt");

    if (candidates_file.fail()) {
        cout << "File open failed." << endl;
    }

    while (getline(candidates_file, candidate_line)) {
        stringstream ss(candidate_line);
        vector<string> row = {};
        string candidate_data;

        while (getline(ss, candidate_data, ',')) {
            row.push_back(candidate_data);
        }

        candidates.push_back(row);
    }

    candidates_file.close();

/*    for (auto row : candidates) {
            for (auto field : row) {
                cout << field << " ";
            }
            cout << endl;
    }
*/

    return candidates;
}

void print_menu() {
    cout << "Select an option below by entering a letter (example: P)\n";
    cout << "P - Print numbers for a particular candidate\n";
    cout << "A - Add number of votes to a candidate\n";
    cout << "S - Display the smallest number of votes candidate\n";
    cout << "L - Display the largest number of votes candidate\n";
    cout << "Q - Quit\n\n";
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

void print_candidate_numbers(vector<vector<string>> candidates)
{
    int selected;
        string candidate_info;

    cout << "Enter candidate ID: ";
    cin >> selected;
    cout << endl;

    while (selected < 1 || selected > candidates.size())
    {
        cout << "Please enter a candidate ID between 1 and " << candidates.size() << "." << endl;
        cin >> selected;
        cout << endl;
    }

    cout << "Candidate " << selected << ": " << candidates[selected - 1][1] << endl;
    cout << "Votes: " << candidates[selected - 1][4] << endl << endl;
}

int main() {
    vector<vector<string>> voters = {}; //initialise vector
    vector<vector<string>> candidates = {}; //initialise vector
    
    voters = read_voters_from_file();
    candidates = read_candidates_from_file();

    while (true) {
      char selected;
      selected = menu();

        switch (selected) {
          case 'P':
              print_candidate_numbers(candidates);
              break;
                
          // case 'A':
          //   add_votes_to_candidate();
          //   break;
                //
          // case 'S':
          //   display_lowest_voted_candidate();
          //   break;
                //
          // case 'L':
          //   display_highest_voted_candidate();
          //   break;
                //
          // case 'Q':
          //   exit(0);
            
    
          default:
        }
    }
        menu();
    


}
