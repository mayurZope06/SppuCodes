// Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states. 
// When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and returns 
// the population of the state.

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map to store state names and their populations
    map<string, int> statePopulation;

    // Insert some state names and populations into the map
    statePopulation["Maharashtra"] = 999538223;
    statePopulation["Tamil Nadu"] = 29145505;
    statePopulation["Uttar Pradesh"] = 21538187;
    statePopulation["Gujrat"] = 20201249;
    statePopulation["Karnataka"] = 13002700;

    string state;
    cout << "Enter the name of a state: ";
    getline(cin, state);  // Get the state name from the user

    // Search for the state in the map
    auto it = statePopulation.find(state);
    
    if (it != statePopulation.end()) {
        // If the state is found, output its population
        cout << "The population of " << state << " is " << it->second << endl;
    } 
    else {
        // If the state is not found, display a message
        cout << "State not found in the database." << endl;
    }

    return 0;
}
