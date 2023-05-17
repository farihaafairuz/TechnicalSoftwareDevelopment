//test file

#include <iostream> //header file for lots of C++ functions
#include <fstream> //libary for opening external files with ifstream and ofstream
#include <sstream> //header file for classes
#include <cstdlib> //needed for closing the external files
#include <string> //header file for using strings
#include <vector> //header file for vector
using namespace std;

// function prototypes
char menu();
void print_menu();
vector<vector<string>> read_candidates_from_file();
void write_candidates_to_file(vector<vector<string>> candidates);
void selection(vector<vector<string>> candidates);
void print_candidates(vector<vector<string>> candidates);
vector<vector<string>> add_votes_to_candidate(vector<vector<string>> candidates);
void display_smallest_number_of_votes(vector<vector<string>> candidates);
void display_largest_number_of_votes(vector<vector<string>> candidates);

//const string VOTER_FILE = "voters.txt";
//const string CANDIDATE_FILE = "candidates.txt";


// function definitions
vector<vector<string>> read_voters_from_file() {
    vector<vector<string>> voters = {};
    string voter_line;

    ifstream voters_file("voters.txt");

    if (!voters_file.is_open()) {
        cout << "File open failed." << endl;
    }
    while (getline(voters_file, voter_line)) {
        if (!voter_line.empty()) {
            stringstream ss(voter_line);
            vector<string> row = {};
            string voter_data;

            while (getline(ss, voter_data, ',')) {
                row.push_back(voter_data);
            }
            voters.push_back(row);
        }
    }
    voters_file.close();
    return voters;
}



//read the text file candidates.txt
vector<vector<string>> read_candidates_from_file() {
    vector<vector<string>> candidates = {};
    string candidate_line;

    ifstream candidates_file("candidates.txt");

    if (!candidates_file.is_open()) {
        cout << "File open failed." << endl;
    }

    while (getline(candidates_file, candidate_line)) {
        if (!candidate_line.empty()) {
            stringstream ss(candidate_line);
            vector<string> row = {};
            string candidate_data;

            while (getline(ss, candidate_data, ',')) {
                row.push_back(candidate_data);
            }

            candidates.push_back(row);
        }
    }

    candidates_file.close();
    return candidates;
}




// print read candidates
void print_candidate_numbers(vector<vector<string>> candidates)
{
    int selected;
    string candidate_info;

    cout << "Enter candidate ID (1 - " << candidates.size() << "): ";
    cin >> selected;
    cout << endl;

    while (selected < 1 || selected > candidates.size())
    {
        cout << "Please enter a candidate ID between 1 and " << candidates.size() << ".\n";
        cout << "Enter candidate ID (1 - " << candidates.size() << "): ";
        cin >> selected;
        cout << endl;
    }

    cout << "Candidate " << selected << ": " << candidates[selected - 1][1] << endl;
    cout << "Votes: " << candidates[selected - 1][4] << endl << endl;
}


void print_all_candidates(vector<vector<string>> candidates) {
    cout << "##### Electoral Commission - Candidates #####" << endl;
    int i = 1;
    for (auto row : candidates) {
        cout << "Candidate ID: " << i << " -> ";
        for (auto field : row) {
            
            
            cout << field << " ";
            
        }
        i++;
        cout << endl;
    }
}


//write the text file candidates.txt
void write_candidates_to_file(vector<vector<string>> candidates) {
    ofstream file("candidates.txt");

    if (file.fail()) {
        cout << "File open failed." << endl;
        return;
    }
    for (int i = 0; i < candidates.size(); i++) {
        for (int j = 0; j < candidates[i].size(); j++) {
            file << candidates[i][j];
            if (j != candidates[i].size() - 1) {
                file << ",";
            }
        }
        file << endl;
    }
    
    file.close();
}

//display smallest number of votes
void display_smallest_number_of_votes(vector<vector<string>> candidates) {
    int smallest = stoi(candidates[0][4]);//stoi coverts string to interger
    string candidate_name = candidates[0][1];
    for (int i = 1; i < candidates.size(); i++) {
        if (stoi(candidates[i][4]) < smallest) {
            smallest = stoi(candidates[i][4]);
            candidate_name = candidates[i][1];
        }
    }
    cout << "Candidate " << candidate_name << " has the smallest number of votes: " << smallest << endl << endl;
}

//display largest number of votes
void display_largest_number_of_votes(vector<vector<string>> candidates){
    int largest = stoi(candidates[0][4]);
    string candidate_name = candidates[0][1];//declares the candidate name to be at [0][1] in the array of the candidate.txt file
    for (int i = 1; i < candidates.size(); i++) {//for loop to cycle through candidate.txt file information
        if (stoi(candidates[i][4]) > largest) {
            largest = stoi(candidates[i][4]);
            candidate_name = candidates[i][1];
        }
        
    }
    cout<<"Candidate " << candidate_name << " has the largest number of votes: " << largest << endl << endl;
}

// add votes to candidate
vector<vector<string>> add_votes_to_candidate(vector<vector<string>> candidates) {
    int candidate_number;
    int votes;
    
    cout << "Enter candidate ID (1 - " << candidates.size() << "): ";
    cin >> candidate_number;

    while (candidate_number < 1 || candidate_number > candidates.size())
    {
        cout << "Candidate not found.\nPlease enter a candidate ID between 1 and " << candidates.size() << ".\n";
        cout << "Enter candidate ID (1 - " << candidates.size() << "): ";
        cin >> candidate_number;
        cout << endl;
    }
    
    cout << "Enter the number of votes to add: ";
    cin >> votes;
    cout << endl;
    
    int current_votes = stoi(candidates[candidate_number - 1][4]);
    candidates[candidate_number -1 ][4] = to_string(current_votes + votes);
    write_candidates_to_file(candidates);
    
    cout << "Added " << votes << " votes to " << candidates[candidate_number - 1 ][1] << endl;
    cout << "Total votes for " << candidates[candidate_number -1 ][1] << ": " << candidates[candidate_number - 1][4] << endl;
    cout << endl;

    return candidates;
}


void selection(vector<vector<string>> candidates){
/*
function takes users input and checks it against the if else statements

*/
    char selected;
    cin >> selected;
    cout << endl;
    while (toupper(selected) != 'Q') {//checks to see if Q has not been entered and continues down the if else statements
        if (toupper(selected) == 'P') {//toupper coverts outputs to be uppercase 
            if (!candidates.empty()) {
                print_candidate_numbers(candidates);
            }
            else {
                cout << "The list is empty. No candidates.\n" << endl;
            }
        }
        else if (toupper(selected) == 'A') {
            if (!candidates.empty()) {
                candidates = add_votes_to_candidate(candidates);
            }
            else {
                cout << "The list is empty. No candidates.\n" << endl;
            }
        }
        else if (toupper(selected) == 'S') {
            if (!candidates.empty()) {
                display_smallest_number_of_votes(candidates);
            }
            else {
                cout << "The list is empty. No candidates.\n" << endl;
            }
          
        }
        else if (toupper(selected) == 'L') {
            if (!candidates.empty()) {
                display_largest_number_of_votes(candidates);
            }
            else {
                cout << "The list is empty. No candidates.\n" << endl;
            }
        }
        else {
            cout << "Invalid option. Please try again.\n" << endl;
        }
        print_menu();
        cin >> selected;
        cout << endl;
    }
    cout << "Goodbye!\n" << endl;
}
// Print Menu Options
void print_menu() {//prototype of the menu to be displayed to the user
    cout << "Select an option below by entering a letter (example: P)\n";
    cout << "P - Print numbers for a particular candidate\n";
    cout << "A - Add number of votes to a candidate\n";
    cout << "S - Display the smallest number of votes candidate\n";
    cout << "L - Display the largest number of votes candidate\n";
    cout << "Q - Quit\n\n";
    cout << "Enter your option: ";
}
// Main Function
int main(){
    vector<vector<string>> voters = {}; //initialise vector
    vector<vector<string>> candidates = {}; //initialise vector
    
    voters = read_voters_from_file();
    candidates = read_candidates_from_file();
    
    print_all_candidates(candidates);//calls function that prints the candidates
    cout << endl;
    print_menu();//calls the menu function 
    selection(candidates);

    return 0;
}
