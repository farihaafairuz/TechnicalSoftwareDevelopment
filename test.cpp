//test file 

#include <iostream> 
#include <fstream>//libary for opening external files with ifstream and ofstream
#include <cstdlib>//needed for closing the external files
using namespace std;

string menu(){//a prototype function for displaying the menu and allowed commands
cout<<"Select an option below by entering a letter (example: P)\n";
cout<<"P - Print numbers for a particular candidate\n";
cout<<"A - Add number of votes to a candidate\n";
cout<<"S - Display the smallest number of votes candidate\n";
cout<<"L - Display the largest number of votes candidate\n";
cout<<"Q - Quit\n";
}

char P(){
    char p;
    cout<<"P: enter a canadidate id\n"
    if(cin>>p;){
        ifstream infile;
        infile.open("candidates.txt");//opens candidate file
        
    }
}

int main(){
menu();

return 0;
}
