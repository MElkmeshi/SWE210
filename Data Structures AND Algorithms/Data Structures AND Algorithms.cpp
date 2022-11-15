#include <iostream>
#include <string>
#include "StaticList.h"
#include "DynamicList.h"
#include "LinkedList.h"
#include "LLStack.h"
#include "LLQueue.h"
#include <algorithm>
#include <unordered_map>


int main()
{
	const int SIZE = 108;
	const int numofplayers = 2;
	string deck[SIZE] = { "R-0","R-1","R-2","R-3","R-4","R-5","R-6","R-7","R-8","R-9","R-T","R-R","R-S","B-0","B-1","B-2","B-3","B-4","B-5","B-6","B-7","B-8","B-9","B-T","B-R","B-S","G-0","G-1","G-2","G-3","G-4","G-5","G-6","G-7","G-8","G-9","G-T","G-R","G-S","Y-0","Y-1","Y-2","Y-3","Y-4","Y-5","Y-6","Y-7","Y-8","Y-9","Y-T","Y-R","Y-S","W-C","W-F","R-1","R-2","R-3","R-4","R-5","R-6","R-7","R-8","R-9","R-T","R-R","R-S","B-1","B-2","B-3","B-4","B-5","B-6","B-7","B-8","B-9","B-T","B-R","B-S","G-1","G-2","G-3","G-4","G-5","G-6","G-7","G-8","G-9","G-T","G-R","G-S","Y-1","Y-2","Y-3","Y-4","Y-5","Y-6","Y-7","Y-8","Y-9","Y-T","Y-R","Y-S","W-C","W-F","W-C","W-F" ,"W-C","W-F" };
	string currentelement;
	unordered_map<string, string> map = { {"R-0","0 Red"} ,{"R-1","1 Red"},{"R-2","2 Red"} ,{"R-3","3 Red"},{"R-4","4 Red"} ,{"R-5","5 Red"},{"R-6","6 Red"} ,{"R-7","7 Red"},{"R-8","8 Red"} ,{"R-9","9 Red"},{"R-8","8 Red"} ,{"R-9","9 Red"},{"B-0","0 Blue"} ,{"B-1","1 Blue"},{"B-2","2 Blue"} ,{"B-3","3 Blue"},{"B-4","4 Blue"} ,{"B-5","5 Blue"},{"B-6","6 Blue"} ,{"B-7","7 Blue"},{"B-8","8 Blue"} ,{"B-9","9 Blue"},{"B-8","8 Blue"} ,{"B-9","9 Blue"},{"G-0","0 Green"} ,{"G-1","1 Green"},{"G-2","2 Green"} ,{"G-3","3 Green"},{"G-4","4 Green"} ,{"G-5","5 Green"},{"G-6","6 Green"} ,{"G-7","7 Green"},{"G-8","8 Green"} ,{"G-9","9 Green"},{"G-8","8 Green"} ,{"G-9","9 Green"},{"Y-0","0 Yellow"} ,{"Y-1","1 Yellow"},{"Y-2","2 Yellow"} ,{"Y-3","3 Yellow"},{"Y-4","4 Yellow"} ,{"Y-5","5 Yellow"},{"Y-6","6 Yellow"} ,{"Y-7","7 Yellow"},{"Y-8","8 Yellow"} ,{"Y-9","9 Yellow"},{"Y-8","8 Yellow"} ,{"Y-9","9 Yellow"},{{"Y-T"}, {"Draw Two Yellow"}}, {{"Y-R"},{"Reverse Yellow"}},{{"Y-S"},{"Skip Yellow"}},{{"R-T"},{"Draw Two Red"}},{{"R-R"},{"Reverse Red"}},{{"R-S"},{"Skip Red"}},{{"B-T"},{"Draw Two Blue"}}, {{"B-R"},{"Reverse Blue"}}, {{"B-S"},{"Skip Blue"}}, {{"G-T"},{"Draw Two Green"}},{{"G-R"},{"Reverse Green"}},{{"G-S"},{"Skip Green"}},{{"W-C"},{"Wild"}},{{"W-F"},{"Wild Draw Four"}} };
	LLStack<string> deckstack;
	LinkedList<string> p[numofplayers];
	random_shuffle(&deck[0], &deck[SIZE]);
	for (int i = 0; i < SIZE; i++) {
		cout << map[deck[i]] << endl;
		deckstack.push(deck[i]);
	}
	for (int i = 0; i < numofplayers; i++) {
		for (int j = 0; j < 7; j++, deckstack.pop())
			p[i].add(deckstack.top());
		cout << "Player " << i + 1 << " cards:" << p[i];
	}
	currentelement = deckstack.top();
	deckstack.pop();
	cout << currentelement;
}
