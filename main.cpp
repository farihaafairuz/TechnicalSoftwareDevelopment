////test file
//
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
//void display_largest_number_of_votes(vector<vector<string>> candidates)s;

//const string VOTER_FILE = "voters.txt";
//const string CANDIDATE_FILE = "candidates.txt";


// function definitions
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
    return voters;
}
//read the text file candidates.txt
vector<vector<string>> read_candidates_from_file() {
    vector<vector<string>> candidates;
    ifstream file("candidates.txt");

    if (file.fail()) {
        cout << "File open failed." << endl;
        return candidates;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> candidate;
        string temp;
        while (getline(ss, temp, ',')) {
            candidate.push_back(temp);
        }
        candidates.push_back(candidate);
    }
    return candidates;
}
// print read candidates
void print_candidates(vector<vector<string>> candidates) {
    for (int i = 0; i < candidates.size(); i++) {
        cout << "Candidate " << i + 1 << ": " << candidates[i][1] << endl;
        cout << "Votes: " << candidates[i][4] << endl << endl;
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
}
//display smallest number of votes
void display_smallest_number_of_votes(vector<vector<string>> candidates) {
    int smallest = stoi(candidates[0][4]);
    string candidate_number = candidates[0][0];
    string candidate_name = candidates[0][1];
    for (int i = 1; i < candidates.size(); i++) {
        if (stoi(candidates[i][4]) < smallest) {
            smallest = stoi(candidates[i][4]);
            candidate_number = candidates[i][0];
            candidate_name = candidates[i][1];
        }
    }
    cout << "Candidate " << candidate_number << " " << candidate_name<< " has the smallest number of votes: " << smallest << endl;
}
// add votes to candidate
vector<vector<string>> add_votes_to_candidate(vector<vector<string>> candidates) {
    string candidate_number;
    int votes;
    cout << "Enter the name of the candidate number: ";
    cin >> candidate_number;
    cout << "Enter the number of votes to add: ";
    cin >> votes;
    cout << endl;

    for (int i = 0; i < candidates.size(); i++) {
        if (candidates[i][0] == candidate_number) {
            int current_votes = stoi(candidates[i][4]);
            candidates[i][4] = to_string(current_votes + votes);
            cout << "Added " << votes << " votes to " << candidate_number<< endl;
            write_candidates_to_file(candidates);
            return candidates;
        }
        else{
            cout << "Candidate not found." << endl;
            return candidates;
        }
    }
    return candidates;
}
void selection(vector<vector<string>> candidates){
    char selected;
    cin >> selected;
    cout << endl;
    while (toupper(selected) != 'Q') {
        if (toupper(selected) == 'P') {
          print_candidates(candidates);
            cout << "P" << endl;
        }
        else if (toupper(selected) == 'A') {
          candidates = add_votes_to_candidate(candidates);
          cout << "A" << endl;
        }
        else if (toupper(selected) == 'S') {
          display_smallest_number_of_votes(candidates);
            cout << "S" << endl;
        }
        else if (toupper(selected) == 'L') {
//          display_largest_number_of_votes(candidates);
            cout << "L" << endl;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
        print_menu();
        cin >> selected;
        cout << endl;
    }
    cout << "Goodbye!" << endl;
}
// Print Menu Options
void print_menu() {
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
    vector<vector<string>> candidates;
    candidates = read_candidates_from_file();
    print_candidates(candidates);
    print_menu();
    selection(candidates);

    return 0;
}
