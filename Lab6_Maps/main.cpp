#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <ctime>
#include <sstream>
using std::istringstream;
using namespace std;
using std::map;

mt19937 random_mt;

struct State_Info{

    string state;
    int per_cap_income;
    int population;
    int med_household_income;
    int num_households;

    State_Info(){
        state = "";
        per_cap_income = 0;
        population = 0;
        med_household_income = 0;
        num_households = 0;
    }

    State_Info(string s, int pci, int pop, int med_house, int num_house){
        state = s;
        per_cap_income = pci;
        population = pop;
        med_household_income = med_house;
        num_households = num_house;
    }

    void print(){
        cout << state << endl;
        cout << "Population: " << population << endl;
        cout << "Per Capita Income: " << per_cap_income << endl;
        cout << "Median Household Income: " << med_household_income << endl;
        cout << "Number of Households: " << num_households << endl;
    }

};

void print_map(map<string, State_Info> stateMap);

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides){

}

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

        int numberOfRolls;
		cout << "Number of times to roll the die: ";
        cin >> numberOfRolls;

        int numberOfSides;
		cout << "Number of sides on this die: " << endl;
        cin >> numberOfSides;

        map<int, int> rollMap; // {number rolled, number times rolled} 

        // first, set everything to initial 0
        for(int i = 1; i <= numberOfSides; i += 1){
            rollMap[i] = 0;
        }

        // now go through and generate all rolls
        for (int i = 0; i < numberOfRolls; i++)
        {
            int roll = Random(1, numberOfSides);
            rollMap[roll] += 1;
        }

        map<int, int>::iterator iter;
        
        // print out the results
        for(iter = rollMap.begin(); iter != rollMap.end(); iter++){
            int key = iter->first;  
            int val = iter->second;
            
            cout << key << ": " << val << endl;
        }

	}
	else if (option == 2)
	{
	   // Load the states
       map<string, State_Info> stateMap; // {state name, state info}

       ifstream inFile("states.csv");
       string singleLine;
       getline(inFile, singleLine); // skip first one>?

        vector<vector<string>> state_lines; // [[state, pci, pop, med_house, num_house], [...], ...]

       while(getline(inFile, singleLine)){
            
            istringstream ss(singleLine);
            string token;
            vector<string> row;
            while(getline(ss, token, ',')){
                row.push_back(token);
            }
            state_lines.push_back(row);
       }


       // now, go through each row and create a State_Info object
       vector<vector<string>>::iterator iter;
       for (iter = state_lines.begin(); iter != state_lines.end(); iter++){
            vector<string> cur_line = *iter;
            string name = cur_line[0];
            int per_cap = stoi(cur_line[1]);
            int pop = stoi(cur_line[2]);
            int med_income = stoi(cur_line[3]);
            int num_households = stoi(cur_line[4]);
            State_Info cur_state_info(name, per_cap, pop, med_income, num_households);
            stateMap[name] = cur_state_info;

       }

	   // Get input for option 1 (show all states) or 2 (do a search for a particular state)
       cout << "1. Print all states" << endl;
       cout << "2. Search for a state" << endl;

       int option;
       cin >> option;

       if (option == 1){
        // print all states
        print_map(stateMap);

       }else if (option == 2){
        // search for a state
        string target_state;
        cin >> target_state; 

        if(stateMap.find(target_state) == stateMap.end()){
            // cannot find
            cout << "No match found for " << target_state << endl;
        }else {
            State_Info found_info = stateMap[target_state];
            found_info.print();
        }
       }

       inFile.close();

	}

	return 0;
}

void print_map(map<string, State_Info> stateMap){
    map<string, State_Info>::iterator iter;

    for(iter = stateMap.begin(); iter != stateMap.end(); iter++){
        iter->second.print();
    }
}