/******************************************************
** Program: assign5.cpp
** Author: Peri Cabrales
** Date: 3/4/18
** Description: This program will play the game of Farkle
** Input: Takes in the amount of players from the user, but must be at least 2 players
** Output: It will play the game of Farkle until a user gets 10,000 points, then everyone gets a last turn
******************************************************/

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

/*********************************************************************
**Function: get_int
**Description: takes in a string, makes sure it's a valid integer, and then changes it from a string to an integer
**Parameters: a string
**Pre-Condition: enter a string that needs to be turned into an integer
**Post-Condition: return the number, but as an integer
*********************************************************************/
//make sure it's a real integer
int get_int(string prompt){
	bool isInt = false;
	for(int i = 0; i < prompt.length(); i++){
		//check if an actual integer	
		if(prompt[i] == '0' || prompt[i] == '1' || prompt[i] == '2' || prompt[i] == '3' || prompt[i] == '4' ||
		prompt[i] == '5' || prompt[i] == '6' || prompt[i] == '7' || prompt[i] == '8' || prompt[i] == '9'){
			isInt = true;
		}
		else{
			isInt = false;
			break;
		}
	}
	
	//adding the numbers together to make the needed integer from a string
	if(isInt == true){
		int  num = 0;
		for(int i = (prompt.length())-1; i >= 0; i--){
			int pChar = int(prompt[i])-48;
			num += (pChar * (pow(10, ((prompt.length()-1)-i))));
				
		}
		return num;
	}
	
	else{
		cout<<"Enter an actual integer: ";
		getline(cin, prompt);
		return get_int(prompt);
	}
	
}

/*********************************************************************
** Function: counting_triplets
** Description: Counts the number of triplets, and sees if there is 
** Parameters: how many of each number are found in the user given dice
** Pre-Conditions: The dice the user wants to trade in for points should be entered in a specific way, and the numbers entered must correspond to the numbers given by the dice roll
** Post-Conditions: returns 2500 if there are 2 triplets given, or returns 0 if there aren't
*********************************************************************/
//counting the triplets
int counting_triplets(int one, int two, int three, int four, int five, int six){	
	int triplet = 0;

	if(one == 3){
		triplet++;
	}
	if(two == 3){
		triplet++;
	}
	if(three == 3){
		triplet++;
	}
	if(four == 3){
		triplet++;
	}
	if(five == 3){
		triplet++;
	}
	if(six == 3){
		triplet++;
	}
	
	if(triplet == 2){
		return 2500;
	}
	return 0;
}

/*********************************************************************
** Function: two_triplets
** Description: counts how many of each number is found entered by the user, then passes to counting_triplets
** Parameters: takes in the string housing the given dice by the user
** Pre-Conditions: the dice must be entered correctly, and be dice that were actually given by the dice roller
** Post-Conditions: Returns either 2500 or 0, as decided by counting_triplets
*********************************************************************/
//two triplets: 2,500
int two_triplets(string rm_dice){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	
	for(int i = 0; i < rm_dice.length(); i++){
		
		if(rm_dice[i] == '1'){
			one++;
		}
		if(rm_dice[i] == '2'){
			two++;
		}
		if(rm_dice[i] == '3'){
			three++;
		}
		if(rm_dice[i] == '4'){
			four++;
		}
		if(rm_dice[i] == '5'){
			five++;
		}
		if(rm_dice[i] == '6'){
			six++;
		}
	} 

	return counting_triplets(one, two, three, four, five, six);
}
/*********************************************************************
** Function: pair_with_four
** Description: finds out how many pairs are in the given string
** Parameters: variables indicating how many of each number there are in the string
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: returns the number of pairs found
*********************************************************************/
//check if there are any pairs in there
int pair_with_four(int one, int two, int three, int four, int five, int six){
	int pair = 0;

	if(one == 2){
		pair++;
	}
	if(two == 2){
		pair++;
	}
	if(three == 2){
		pair++;
	}
	if(four == 2){
		pair++;
	}
	if(five == 2){
		pair++;
	}
	if(six == 2){
		pair++;
	}
	return pair;
}
/*********************************************************************
** Function: really_four_with_pair
** Description: finds if there are any four of a kinds, and then finds how many pairs there are
** Parameters: how many of each number there are
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: return 1500 if there is a four of a kind and a pair, or returns 0 if not
*********************************************************************/
//checking if there is really a four. and then cross checking with a pair
int really_four_with_pair(int one, int two, int three, int four, int five, int six){
	int have_four = 0, pair = 0;
	
	if(one == 4){
		have_four++;	
	}
	if(two == 4){
		have_four++;
	}
	if(three == 4){
		have_four++;
	}
	if(four == 4){
		have_four++;
	}
	if(five == 4){
		have_four++;
	}
	if(six == 4){
		have_four++;
	}

	pair = pair_with_four(one, two, three, four, five, six);
		
	if(have_four == 1 && pair == 1){
		return 1500;
	}

	return 0;

}
/*********************************************************************
** Function: four_with_pair
** Description: Counts how many of each number are in the given string
** Parameters: the string that holds the dice given by the user
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: return 1500 or 0 given by really_four_with_pair
*********************************************************************/
//four of any number with a pair: 1,500
int four_with_pair(string rm_dice){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	
	for(int i = 0; i < rm_dice.length(); i++){	
		if(rm_dice[i] == '1'){
			one++;
		}
		if(rm_dice[i] == '2'){
			two++;
		}
		if(rm_dice[i] == '3'){
			three++;
		}
		if(rm_dice[i] == '4'){
			four++;
		}
		if(rm_dice[i] == '5'){
			five++;
		}
		if(rm_dice[i] == '6'){
			six++;
		}
	}
	return really_four_with_pair(one, two, three, four, five, six);
}
/*********************************************************************
** Function: really_three_pairs
** Description: checks to see if there are three pairs in the user given string
** Parameters: how many of each number there is
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: return 1500 if there are three pairs in the string, or 0 if there isn't
*********************************************************************/
//see if there are three pairs of numbers
int really_three_pairs(int one, int two, int three, int four, int five, int six){
	int pairs = 0;

	if(one == 2){
		pairs++;
	}
	if(two == 2){
		pairs++;
	}
	if(three == 2){
		pairs++;
	}
	if(four == 2){
		pairs++;
	}	
	if(five == 2){
		pairs++;
	}
	if(six == 2){
		pairs++;
	}

	if(pairs == 3){
		return 1500;
	}

	return 0;
}
/*********************************************************************
** Function: three_pairs
** Description: finds out how many of each number are in the given string, then sees if there are three pairs by passing to really_three_pairs
** Parameters: string of dice to remove entered by the user
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: returns either 1500 or 0, depending on what really_three_pairs finds
*********************************************************************/
//three pairs: 1,500
int three_pairs(string rm_dice){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;

	for(int i = 0; i < rm_dice.length(); i++){	
		if(rm_dice[i] == '1'){
			one++;
		}
		if(rm_dice[i] == '2'){
			two++;
		}
		if(rm_dice[i] == '3'){
			three++;
		}
		if(rm_dice[i] == '4'){
			four++;
		}
		if(rm_dice[i] == '5'){
			five++;
		}
		if(rm_dice[i] == '6'){
			six++;
		}
	}

	return really_three_pairs(one, two, three, four, five, six);
	
}
/*********************************************************************
** Function: all_numbers
** Description: find out if there is one of each number in the given string, making it all numbers 1-6
** Parameters: user given string of what dice to remove
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: returns 1500 if there is one of each number, or 0 if there isn't
*********************************************************************/
//1-6 straight: 1,500
int all_numbers(string rm_dice){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;

	for(int i = 0; i < rm_dice.length(); i++){	
		if(rm_dice[i] == '1'){
			one++;
		}
		if(rm_dice[i] == '2'){
			two++;
		}
		if(rm_dice[i] == '3'){
			three++;
		}
		if(rm_dice[i] == '4'){
			four++;
		}
		if(rm_dice[i] == '5'){
			five++;
		}
		if(rm_dice[i] == '6'){
			six++;
		}
	}
	if(one == 1 && two == 1 && three == 1 && four == 1 && five == 1 && six == 1){
		return 1500;
	}

	return 0;
}
/*********************************************************************
** Function: six_of_kind
** Description: checks if there is six of a specific number in the string
** Parameters: a string given by the user of dice to remove
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: return 3000 if there are six of a kind, or 0 if there aren't
*********************************************************************/
//six of any number: 3,000
int six_of_kind(string rm_dice){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	
	for(int i = 0; i < rm_dice[i]; i++){
		if(rm_dice[i] == '1'){
			one++;
		}
		if(rm_dice[i] == '2'){
			two++;
		}
		if(rm_dice[i] == '3'){
			three++;
		}
		if(rm_dice[i] == '4'){
			four++;
		}
		if(rm_dice[i] == '5'){
			five++;
		}
		if(rm_dice[i] == '6'){
			six++;
		}
	}

	if(one == 6 || two == 6 || three == 6 || four == 6 || five == 6 || six == 6){
		return 3000;
	}

	return 0;
}
/*********************************************************************
** Function: five_of_kind
** Description: Sees if there is five of one number
** Parameters: string from user of what dice to remove
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: return 2000 if there is 5 of a kind, or return 0 if there isn't
*********************************************************************/
//five of any numbers: 2,000
int five_of_kind(string rm_dice){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	
	for(int i = 0; i < rm_dice.length(); i++){
		if(rm_dice[i] == '1'){
			one++;
		}
		if(rm_dice[i] == '2'){
			two++;
		}
		if(rm_dice[i] == '3'){
			three++;
		}
		if(rm_dice[i] == '4'){
			four++;
		}
		if(rm_dice[i] == '5'){
			five++;
		}
		if(rm_dice[i] == '6'){
			six++;
		}
	}

	if(one == 5 || two == 5 || three == 5 || four == 5 || five == 5 || six == 5){
		return 2000;
	}

	return 0;
}
/*********************************************************************
** Function: four_of_kind
** Description: sees whether or not there is four of any number
** Parameters: a string given by the user with what dice they want to remove
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: returns 1000 if there is a four of a kind present, or 0 if there isn't
*********************************************************************/
//four of any number: 1,000
int four_of_kind(string rm_dice){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;

	for(int i = 0; i < rm_dice.length(); i++){
		if(rm_dice[i] == '1'){
			one++;	
		}
		if(rm_dice[i] == '2'){
			two++;
		}
		if(rm_dice[i] == '3'){
			three++;
		}
		if(rm_dice[i] == '4'){
			four++;
		}
		if(rm_dice[i] == '5'){
			five++;
		}
		if(rm_dice[i] == '6'){
			six++;
		}
	}

	if(one == 4 || two == 4 || three == 4 || four == 4 || five == 4 || six == 4){
		return 1000;
	}
	
	return 0;
}
/*********************************************************************
** Function: compare_three_of_kind
** Description: sees if there is a three of a kind, and returns a specific point amount for that number
** Parameters: the amount of each number found in the given string
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: return a specific amount of points depending on which number has three of a kind, or return 0 if there are no three of a kinds
*********************************************************************/
//compare the three of a kind ones
int compare_three_of_kind(int one, int two, int three, int four, int five, int six){

	if(one == 3 || three == 3){
		return 300;
	}

	else if(two == 3){
		return 200;
	}
	
	else if(four == 3){
		return 400;
	}

	else if(five == 3){
		return 500;
	}

	else if(six == 3){
		return 600;
	}
	
	return 0;
}
/*********************************************************************
** Function: three_of_kind
** Description: counts how many of each number is in the string, and then passes to compare_three_of_kind
** Parameters: string from the user of what dice to remove
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: will return either 0, or a number in the hundreds given by compare_three_of_kind
*********************************************************************/
//are there 3s of anything: 1's-300, 2's-200, 3's-300, 4's-400, 5's-500, 6's-600
int three_of_kind(string rm_dice){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	for(int i = 0; i < rm_dice.length(); i++){
		if(rm_dice[i] == '1'){
			one++;
		}
		if(rm_dice[i] == '2'){
			two++;
		}
		if(rm_dice[i] == '3'){
			three++;
		}
		if(rm_dice[i] == '4'){
			four++;
		}
		if(rm_dice[i] == '5'){
			five++;
		}
		if(rm_dice[i] == '6'){
			six++;
		}
	}

	return compare_three_of_kind(one, two, three, four, five, six);
	
}
/*********************************************************************
** Function: singles
** Description: makes sure that the length is only one, and returns the point value if there is a 1 or 5, or 0 if there isn't
** Parameters: string from the user with the dice they want to remove
** Pre-Conditions: have the user entered string be in a valid way 
** Post-Conditions: returns 100 if there is a 1, 50 if there is a 5, or 0 if neither
*********************************************************************/
//is there a single 1 or 5: 1-100, 5-50
int singles(string rm_dice){
	int total = 0;

	if(rm_dice.length() == 1){
		if(rm_dice[0] == '1'){
			return 100;
		}
		else if(rm_dice[0] == '5'){
			return 50;
		}
	}
	return total;
}
/*********************************************************************
** Function: check_against_rules
** Description: checks the point values against each other to find the greatest one
** Parameters: the points gotten from each function above
** Pre-Conditions: have the user entered string be in a valid way so points can be calculated
** Post-Conditions: return the greatest point value
*********************************************************************/
//check against each other
int check_against_rules(int single, int three, int four, int five, int six, int all, int three_pair, int four_pair, int double_trip){
	int greatest = 0;
	for(int i = 0; i < 9; i++){
		if(single > greatest){
			greatest = single;
		}
		else if(three > greatest){
			greatest = three;
		}
		else if(four > greatest){
			greatest = four;
		}
		else if(five > greatest){
			greatest = five;
		}
		else if(six > greatest){
			greatest = six;
		}
		else if(all > greatest){
			greatest = all;
		}
		else if(three_pair > greatest){
			greatest = three_pair;
		}
		else if(four_pair > greatest){
			greatest = four_pair;
		}
		else if(double_trip > greatest){
			greatest = double_trip;
		}
	}

	return greatest;
}
/*********************************************************************
** Function: farkle
** Description: sets the total for the player's turn to zero, and notifies 
** Parameters: takes in the running total (pointer) for the player's turn
** Pre-Conditions: there are no points available for the dice they chose
** Post-Conditions: turns the total to zero and announces they have a farkle
*********************************************************************/
//FARKLE
void farkle(int** total){
	**total = 0;
	cout<<"FARKLE! You get 0 points for this turn."<<endl;
}
/*********************************************************************
** Function: highest_score
** Description: Calls the farkle function if all point values are zero, or adds the greatest point value to the total
** Parameters: point values found for each point scoring found in the game
** Pre-Conditions: be able to get points, even if zero, from each point scoring function
** Post-Conditions: total is either changed to 0, or added to with the greatest points
*********************************************************************/
//checking what the highest score is
void highest_score(int single, int three, int four, int five, int six, int all, int three_pair, int four_pair, int double_trip, int** total){
	int greatest = 0;

	//no points means a farkle
	if(single == three && three == four && four == five && five == six && six == all && all == three_pair && three_pair == four_pair && four_pair == double_trip && double_trip == 0){
		farkle(total);
	}
	//trying to find the greatest score for the people	
	else{
		greatest = check_against_rules(single, three, four, five, six, all, three_pair, four_pair, double_trip);
		**total += greatest;
	}

}
/*********************************************************************
** Function: call_dice_points
** Description: gets the point values from each function and then sends them to find the highest score
** Parameters: the string given by the user for what dice values they want to remove, and the runnin total for the player's turn
** Pre-Conditions: have the user entered string be in a valid way, and have a running total of any value
** Post-Conditions: changes total depending on what highest_score finds
*********************************************************************/
//calling all the dice checking functions
void call_dice_points(string rm_dice, int** total){

	//check what makes the largest total then add to total
	int single = singles(rm_dice); 
	int three = three_of_kind(rm_dice);
	int four = four_of_kind(rm_dice);
	int five = five_of_kind(rm_dice);
	int six = six_of_kind(rm_dice);
	int all = all_numbers(rm_dice);
	int three_pair = three_pairs(rm_dice);
	int four_pair = four_with_pair(rm_dice);
	int double_trip = two_triplets(rm_dice);

	highest_score(single, three, four, five, six, all, three_pair, four_pair, double_trip, total);
}
/*********************************************************************
** Function: score_over_500_ask
** Description: Checks the input given by the user after asking if they want to continue playing
** Parameters: the string that gives a y or n that relates to whether or not they want to end their turn
** Pre-Conditions: Have the user enter a y or n 
** Post-Conditions: return a y for yes, n for no, or x if they didn't enter a useable character
*********************************************************************/
//the check to see if they want to continue playing after having 500 points (on the board)
char score_over_500_ask(string input){
	char if_bad = 'x';

	cout<<"the input: "<<input<<endl;
	
	if(input.length() == 1){
		for(int i = 0; i < input.length(); i++){
			if(int(input[i]) == 121 || int(input[i]) == 89){
				return 'y';
			}
			else if(int(input[i]) == 110 || int(input[i]) == 78){
				return 'n';
			}
			else{
				break;
			}
		}
	}

	return if_bad;
	
}
/*********************************************************************
** Function: score_overe_500
** Description: if the total score is over 500, or they took out 6 dice on their first turn, ask them if they want to keep rolling
** Parameters: the player's score, the turn # they're on, which player they are, and the total dice they wanted to take away
** Pre-Conditions: have their overall score be over 500, or have just taken 6 dice on their first turn
** Post-Conditions: if y, return 0 so they can continue playing, if n, then return 6 so they dont play anymore, and if they enter a non valid character, recurse until they enter a y or n
*********************************************************************/
int score_over_500(int*scores, int player, int total_dice){
	string input = "";

	//seeing if the person wants to continue rolling 
	if(scores[player] >= 500 || total_dice == 6){
		cout<<"Would you like to continue playing, or take your total as it is now (y/n): ";
		getline(cin, input);

		char given = score_over_500_ask(input);

		if(given == 'y'){
			if(total_dice == 6){
				return 0;
			}
			else{
				return total_dice;
			}
		}
		if(given == 'n'){
			return 6;
		}
		if(given == 'x'){
			return score_over_500(scores, player, total_dice);
		}

		
	}

	return total_dice;

}
/*********************************************************************
** Function: counting_dice
** Description: count the number of dice given by the user
** Parameters: the string of dice the user wants to remove
** Pre-Conditions: have the user enter at least one number
** Post-Conditions: returns the number of dice given
*********************************************************************/
//count the number of dice actually given
int counting_dice(string rm_dice){
	int total_dice = 0;

	//find the total number of dice to remove
	for(int i = 0; i < rm_dice.length(); i++){
		if(int(rm_dice[i]) >= 48 && int(rm_dice[i]) <= 57){
			total_dice++;
		}	
	} 

	return total_dice;
}
/*********************************************************************
** Function: input_dice_same
** Description: make sure the numbers given are the same as the ones given by the random 
** Parameters: pointer array of dice rolled that turn, the string from the user, the amount of dice, the turn number, the player's score, and the player number
** Pre-Conditions: have the user enter numbers into a string
** Post-Conditions: returns true if the number of dice found is equal to the number of dice counted, or false if it isn't
*********************************************************************/
//make sure now that dice numbers given are the same as the ones given by the random
bool input_dice_same(int* arr, string rm_dice, int dice, int*scores, int player){
	int counting_nums = 0;

	//see if the number in the string is the same as a number given by the dice
	for(int i = 0; i < rm_dice.length(); i++){
		if(int(rm_dice[i]) != 32){
			int num = 0;
			for(int j = 0; j < dice; j++){

				//if the same number hasnt been found multiple times
				if(num == 0){
					if((arr[j]+ 48) == int(rm_dice[i])){
						//up the number of numbers found
						num++;
						//change that number to 0 so it cant be counted again on another run through
						arr[j] = 0;	
						//up the number of numbers found overall
						counting_nums++;
						//break;
					}
				}
	
			}
		}
	}

	//findng how many dice the user put in, and how many equal what was given by the dice roller
	int dice_num = counting_dice(rm_dice);
	if(counting_nums == dice_num){
		return true;

	}
	else if(dice_num != counting_nums){
		return false;
	}
}
/*********************************************************************
** Function: input_dice_correct
** Description: checks to make sure the dice are given as a correct format
** Parameters: the string given from user input
** Pre-Conditions: have the user enter dice numbers to the string
** Post-Conditions: returns true if the user enters the numbers with one space between each other, or false if they don't
*********************************************************************/
//checks to make sure the dice are given as a correct format 
bool input_dice_correct(string rm_dice){
	bool correct = false;
	if(int(rm_dice[0]) >= 48 && int(rm_dice[0]) <= 57 && rm_dice.length() > 1){
		for(int i = 1; i < rm_dice.length(); i++){
			if(i < rm_dice.length() - 1 && int(rm_dice[i]) >= 48 && int(rm_dice[i]) <= 57 && int(rm_dice[i+1]) == 32 && int(rm_dice[i-1]) == 32){
				correct = true;	
			}
			if(int(rm_dice[i]) == 32 && int(rm_dice[i-1]) >= 48 && int(rm_dice[i-1]) <= 57 && int(rm_dice[i+1]) >= 48 && int(rm_dice[i+1]) <= 57){
				correct = true;
			}
			
			if(i < rm_dice.length() -1 && int(rm_dice[i]) >= 48 && int(rm_dice[i]) <= 57 && int(rm_dice[i-1]) == 32){
				correct = true;
			}

			else{
				break;
				correct = false;
			}
		}
	}
	else if(rm_dice.length() == 1 && int(rm_dice[0]) >= 48 && int(rm_dice[0]) <= 57){
		return true;	
	}
	return correct;
}
/*********************************************************************
** Function: check_dice
** Description: check the dice numbers chosen to make sure they match what is allowed for the rules
** Parameters: player's score, user given string, # of dice, array of dice randomly given, total for the turn, turn #, player number
** Pre-Conditions: have the user enter dice numbers to be removed
** Post-Conditions: Either return the number of dice to be removed if all the checks are met, or redo this function to get a useable amount of numbers from the user
*********************************************************************/
//check the dice numbers chosen to make sure they match what is allowed for the rules
int check_dice(int* scores, string rm_dice, int dice, int* gained_dice, int** total, int player){
	bool dice_check_1 = false;
	dice_check_1 = input_dice_correct(rm_dice);

	bool dice_check_2 = false;
	if(dice_check_1 == true){
		dice_check_2 = input_dice_same(gained_dice, rm_dice, dice, scores, player);
	}	


	//if the dice of not input correctly
	if(dice_check_1 == false || dice_check_2 == false){
		cout<<"Which dice numbers would you like to remove (separate the numbers with spaces): ";
		getline(cin, rm_dice);
		return check_dice(scores, rm_dice, dice, gained_dice, total, player);
	}
	else if(dice_check_1 == true && dice_check_2 == true){
		//get the total
		call_dice_points(rm_dice, total);

		
		//return the number of dice taken
		return counting_dice(rm_dice);
	}
}
/*********************************************************************
** Function: not_enough_points
** Description: tells the user they don't have enough points to get on the board, if they get less than 500 points during their round
** Parameters: the total for the round, their total score, what player it is
** Pre-Conditions: have the total be less than 500 but greater than 0, and have their score be 0
** Post-Conditions: has the total become zero, and tells the user they don't have enough points to get on the board
*********************************************************************/
//when there aren't enough points
void not_enough_points(int** total, int* scores, int player){
	if(**total < 500 && **total > 0 && scores[player] == 0){
		cout<<"You didn't get enough points to get on the board. You get zero points for this round."<<endl;
		 **total = 0;
	}
}
/*********************************************************************
** Function: dice_are
** Description: creates random numbers for the amount of dice needed at that point
** Parameters: number of dice, the array to put the dice into
** Pre-Conditions: have the number of dice needed to throw out
** Post-Conditions: populate the array with the dice given
*********************************************************************/
//roll the dice
void dice_are(int* given_dice, int dice){
	//give the dice
	cout<<"Your dice are: ";
	for(int i = 0; i < dice; i++){
		int r = rand() % 6 + 1;
		given_dice[i] = r;
		cout<<r<<", ";
	}
}
/*********************************************************************
** Function: find_rm_dice
** Description: finding which dice the user wants to remove
** Parameters: no parameters
** Pre-Conditions: give the user dice to choose from
** Post-Conditions: return a string that carries the user's choice of dice values to remove for points
*********************************************************************/
//finding which dice the user wants to remove
string find_rm_dice(){
	string rm_dice = "";
	cout<<endl;
	cout<<"Which dice numbers would you like to remove (separate the numbers with spaces, and put any number given if they all give you a Farkle): ";
	getline(cin, rm_dice);
	return rm_dice;
}

/*********************************************************************
** Function: dice_rolls
** Description: continues to roll different numbers of dice, output scores, and tell you if you got on the board
** Parameters: array of scores, player number
** Pre-Conditions: have the player continue to play
** Post-Conditions: allows the player to choose what dice to take away until someone wins
*********************************************************************/
//dice totals and stuff
void dice_rolls(int* scores, int player){
	//always start with 6 dice
	int dice = 6;
	int* total = new int;
	*total = 0;
	int* given_dice;
	
	srand(time(NULL)); //seeds random number generator. DO THIS JUST ONCE

	//trying to go through all dice
	while(dice != 0){
		//the array that is going to be holding the dice rolls
		given_dice = new int[dice];
		
		//fill the array with dice
		dice_are(given_dice, dice);

		//have them remove dice
		string rm_dice = find_rm_dice();
	
		//send to function to check if dice chosen are good
		int number_remove = check_dice(scores, rm_dice, dice, given_dice, &total, player);

		//FARKLE
		if(*total == 0){
			break;
		}

		cout<<"Your score is: "<<*total<<endl;
		//use for when the score is over 500, or they get 6 out on their first turn
		number_remove = score_over_500(scores, player, number_remove);
	
 		dice = dice - number_remove;
		delete[] given_dice;
		given_dice = NULL;
	}

	//says if you didnt get enough points that turn to get on the board for the first round
	not_enough_points(&total, scores, player);

	scores[player] += *total;
	cout<<"Your overall score is: "<<scores[player]<<endl;
	delete total;
	//keep this here. need it to have no memory leaks
	delete[] given_dice;
	given_dice = NULL;
}

/*********************************************************************
** Function: game_start
** Description: goes through each player until someone gets to 10000 points, then they go through the other players one more time
** Parameters: the scores array, and the length of the array
** Pre-Conditions: have the array be populated and with an adaquate length
** Post-Conditions: will show when it's the last turn and who's turn it is and when
*********************************************************************/
//get the game going
void game_start(int* scores, int length){
	//to keep track of who gets 10,000 points
	int player = -1;
	//keep going in circles until someone reaches 10,000 points, and we know who that person is
	while(player <= -1){
		for(int i = 0; i < length; i++){
			cout<<endl;
			cout<<"Player "<<i+1<<"'s turn."<<endl;
			dice_rolls(scores, i);

			//CHANGE IT BACK TO 10000 WHEN DONE TESTING
			if(scores[i] >= 10000){
				player = i;
				break;
			}
			
		}	
	}
	//if someone gets over 10,000 points, do one more round
	if(player != -1){
		cout<<endl;
		cout<<"Last round!"<<endl;
		for(int i = 0; i < length; i++){
			if(i != player){
				cout<<endl;
				cout<<"Player "<<i+1<<"'s turn."<<endl;
				dice_rolls(scores, i);	
			}
		}
	}

}
/*********************************************************************
** Function: populate_array
** Description: populate the array with zeros to start
** Parameters: the scores array, and the length of the array
** Pre-Conditions: have an array with a specific length of people playing
** Post-Conditions: have the array now be filled with zeros
*********************************************************************/
//populate with zeros
void populate_array(int* scores, int length){
	for(int i = 0; i < length; i++){
		scores[i] = 0;
	}
}

/*********************************************************************
** Function: get_amount_people
** Description: gets the amount of people playing from the user, but at least 2 
** Parameters: no parameters
** Pre-Conditions: no preconditions
** Post-Conditions: returns the number of people given, or reprompts if it isn't an integer or over 2
*********************************************************************/
//gets the amount of people the user wants to have play
int get_amount_people(){
	string input = "";
	cout<<"You must have at least 2 people playing. How many will play: ";
	getline(cin, input);

	//make sure its a real number
	int people = get_int(input);

	if(people < 2){
		return get_amount_people();
	}
	else{
		return people;
	}
	
}
/*********************************************************************
** Function: all_together
** Description: creates the array that holds the scores, and calls the populating array, and the function that stars the game
** Parameters: no parameters
** Pre-Conditions: have the user give the amount of players, and then use that to start the game
** Post-Conditions: output the final scores, and delete the scores array, once everything is done
*********************************************************************/
//just putting everything together out of main
void all_together(){
	//get length of the array = number of people given
	int length = get_amount_people();

	//create game array
	int* scores = new int[length];
	
	//populate the array
	populate_array(scores, length);

	//start the game
	game_start(scores, length);

	cout<<"Final Scores"<<endl;
	for(int i = 0; i < length; i++){
		cout<<"Player "<<i+1<<" : "<<scores[i]<<" points"<<endl;
		
	}

	//absolute last thing
	delete[] scores;
	scores = NULL;
}

int main(){
	all_together();

	return 0;
}
