/*

Name: Cade Chaplin
Class: Cpt S 122; Lab Section 9                                                *
Programming Assignment: PA3                                                       *
Date: 9/28/2022

Project Objective: Take data from excel file, put data into a linked list,
edit, sort, shuffle, delete songs in the linked list.


*/



/* Doubly Linked List implementation */
#include "PA2Header.h"
#include "TestHeaderPA2.h"
#include "Functions.cpp"



int testing = 0;
struct Node* head; // global variable - pointer to head node.
struct Node* cur;
//Creates a new Node and returns pointer to it. 
struct Node* GetNewNode(Record song) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	
	strcpy(newNode->song.name , song.name);
	strcpy (newNode->song.album , song.album);
	strcpy(newNode->song.name , song.name);
	strcpy(newNode->song.genre , song.genre);
	strcpy(newNode->song.artist, song.artist);
	newNode->song.length.min = song.length.min;
	newNode->song.length.sec = song.length.sec;
	if (song.timesPlayed < 0) {//stops invalid timesPlayed entry
	
		song.timesPlayed = 0;
	}
	newNode->song.timesPlayed = song.timesPlayed;
	if (song.rating <= 0) {//stops invalid Rating entry
		song.rating = 1;
	
	}
	if (song.rating >= 6) {
		song.rating = 5;

	}
	newNode->song.rating = song.rating;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead( Record song) {
	struct Node* newNode = GetNewNode(song);
	if (head == NULL) {
		head = newNode;
		//cur = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}// inserts at front of list 

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(Record song) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(song);
	if (head == NULL) {
		head = newNode;
		return;
	}
	while (temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order


//Prints all elements in linked list in reverse traversal order. 
void ReversePrint() {
	struct Node* temp = head;
	if (temp == NULL) return; // empty list, exit
	// Going to last Node
	while (temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	//printf("Reverse: ");
	while (temp != NULL) {
		printf("%s ", temp->song.name);
		temp = temp->prev;
	}
	printf("\n");
}

void store() {

	struct Node* temp = head;
	FILE *infile = fopen("MusicPlayList.csv", "w");

	

	while (temp != NULL)
	{
			fprintf(
				infile, "%s,%s,%s,%s,%d:%d,%d,%d\n",
			temp->song.artist, temp->song.album, temp->song.name, temp->song.genre, temp->song.length.min, temp->song.length.sec, temp->song.timesPlayed, temp->song.rating
				);

		temp = temp->next;
	}


}//stores linked list back into excel file 
void nextSong() {

	if (cur->next != NULL) {
		cur = cur->next;
	}
	
}//changes pcur to next song, used for testing 

void lastSong() {

	if (cur->prev != NULL) {
	
		cur = cur->prev;
	
	}


}//changes pcur to last song, used for testing 

void printCur() {



	printf("%s ", cur->song.name);
	printf("%s ", cur->song.artist);
	printf("%s ", cur->song.album);
	printf("%s ", cur->song.genre);
	printf("%i ", cur->song.rating);
	printf("%d:%d", (cur->song.length).min, (cur->song.length).sec);
	printf("% i", cur->song.timesPlayed);
	printf("\n");



}//prints current song, used in loops to print song

void deleteNode(Node *badNode) {//deletes node, what it does depends on where it is in the list, front end or middle 
	int success = 0;
	cur = head;
	Node* ptemp = badNode;
	if (badNode != NULL) {
		if (badNode->prev == NULL && badNode->next == NULL) {
			head = NULL;
			free(badNode);
			success = 1;
		
		
		}	
		if (badNode->prev == NULL && success != 1) // Checking if it is first node 
		{
			head = badNode->next;
			head->prev = NULL;
			free(badNode);
			success = 1;

		}
		if (badNode->next == NULL && success != 1)
		{
			ptemp = ptemp->prev;
			ptemp->next = NULL;
			free(badNode);
			success = 1;

		}
		if (success != 1) {

			ptemp = badNode->next;
			ptemp->prev = badNode->prev;
			ptemp = badNode->prev;
			ptemp->next = badNode->next;
			free(badNode);
		}

	}


}

void deleteSong() {//finds song to be deleted and passes it to delete node

	printf("What Song?\n");
	char song[100];
	//std::cin >> artist;


	/*if (head != NULL)
	{

		printf("OK\n");
		scanf(" %s[^\n]", artist);
		printf("%s", artist);

	}*/
	//fgets(artist, 100, stdin);
	//artist = "\"Bieber, Justin\"";

	int i = 0;
	int choice = 1;
	char choiceStr[50];
	struct Node* temp = head;
	struct Node* selection = head;
	while (i == 0)
	{
		if (testing == 0)
		{

			fgets(song, 50, stdin);
			song[strlen(song) - 1] = NULL;

		}
		else
		{
			strcpy(song, "Chained to the Rhythm");
		}
		while (temp != NULL && i == 0) {



			if (strcmp(song, temp->song.name) == 0)
			{
				i++;
				selection = temp;
				//printf("%i %s", i, temp->song.name);
				//printf("\n");

			}

			temp = temp->next;
		}
		if (i == 0) {
			printf("No Song found\n");
			break;

		}
		else
		{
			
			deleteNode(selection);

		}
	}
}


void Print() {//passed each song to printCur until the end of the list 
	struct Node* temp = head;
	cur = head;
	while (cur != NULL) {
		printCur();
		cur = cur->next;
	}
	printf("\n");
	if (cur != NULL){
		printf("No Data found");
	
	}
}
void printArtist() {//orints all songs of a specific artist 

	printf("What artist?\n");
	char artist[100];
	cur = head;

	int i = 0;
	while (i == 0)
	{
		fgets(artist, 50, stdin);
		artist[strlen(artist)-1] = NULL;
		while (cur != NULL)
		{


			if (strcmp(artist, cur->song.artist) == 0)
			{

				i++;
				printCur();


			}
			
			cur = cur->next;
		}

		if(i == 0) {
			printf("No Artist Found\n");
			break;
		}
	}
	

	cur = head;


}

void rate() {//allows rating of the song to be changed, only allows values from 1 to 5
	
	char rating[10];
while (atoi(rating) <= 0 || atoi(rating) > 5)
{
	fgets(rating, 10, stdin);
	
	

	if (atoi(rating) > 0 && atoi(rating) <= 5) {
	
		cur->song.rating = atoi(rating);
	
	}
	else {
	
		std::cout << "try again\n";
	
	}

}

}

void shuffle() {// makes list a random order, same songs can be played muiltiple times, some songs wont be listed, list length will be the same as the amount of songs in the list 

	int listLen = 0;
	int listPos = 0;
	struct Node* temp = head;
	//struct Node** listCopy = &temp;
	
	while (temp!= NULL)//gets current length of list
	{
		listLen++;

		temp = temp->next;
		

	}
	
	

	for (int j = 0; j<listLen; j++)
	{
		cur = head;
		//remove whatever is printed and select a random from i--;

		listPos = rand() % (listLen);
		//temp = head;
		
		for (int i = 0; i < listPos; i++)
		{
			cur = cur->next;
			

		}
		printCur();
		
		//deleteNode(list);
		
		
		
	}
	/*
	while (cur != NULL)
	{

		printCur();

		Sleep(10000);


		//wait 10 seconds

		cur = cur->next;
	}
	cur = head;
	*/


}


void newsong() {//takes input for data for a new song 


	
	char choiceStr[50];
	Record song = {""};
	
	
	//couldn't figure out how to print to the console like imput so my program could read test input, so I just hard coded the imputs for if testing = 1, meaning program is testing
	
	if (testing == 0) {
		printf("Enter Song name\n");
		fgets(choiceStr, 50, stdin);
		choiceStr[strlen(choiceStr) - 1] = NULL;
	}
	else
	{
		strcpy(choiceStr, "Chained to the Rhythm");
	}
	strcpy(song.name, choiceStr);
	
	
	
	if (testing == 0) {
		printf("Enter Artist name\n");


		fgets(choiceStr, 50, stdin);
		choiceStr[strlen(choiceStr) - 1] = NULL;
	}
	else
	{
		strcpy(choiceStr, "Katy, Perry");
	}
	
	strcpy(song.artist, choiceStr);
	
	if (testing == 0) {
		printf("Enter Album name\n");


		fgets(choiceStr, 50, stdin);
		choiceStr[strlen(choiceStr) - 1] = NULL;
	}
	else
	{
		strcpy(choiceStr, "Witness");
	}
	
	
	strcpy(song.album, choiceStr);
	if (testing == 0) {
		printf("Enter Genre\n");



		fgets(choiceStr, 50, stdin);
		choiceStr[strlen(choiceStr) - 1] = NULL;
	}
	else
	{
		strcpy(choiceStr, "pop");
	}
	
	
	strcpy(song.genre, choiceStr);

	if (testing == 0) {
		printf("Enter length in minutes\n");




		fgets(choiceStr, 50, stdin);
		choiceStr[strlen(choiceStr) - 1] = NULL;
	}
	else {
		strcpy(choiceStr, "4");
	}
	
	
	song.length.min = atoi(choiceStr);

	if (testing == 0) {
		printf("Enter length in seconds\n");





		fgets(choiceStr, 50, stdin);
		choiceStr[strlen(choiceStr) - 1] = NULL;
	}
	else
	{
		strcpy(choiceStr, "36");
	}
	
	
	song.length.sec = atoi(choiceStr);

	if (testing == 0) {
		printf("Enter length in times played\n");




		fgets(choiceStr, 50, stdin);
		choiceStr[strlen(choiceStr) - 1] = NULL;

	}
	else
	{
		strcpy(choiceStr, "-1");
	}
	
	song.timesPlayed = atoi(choiceStr);

	if (testing == 0) {
		printf("Enter length in rating\n");




		fgets(choiceStr, 50, stdin);
		choiceStr[strlen(choiceStr) - 1] = NULL;
	}
	else
	{
		strcpy(choiceStr, "6");
	}
	
	
	song.rating = atoi(choiceStr);
	InsertAtHead(song);
}

void sort() {//sorts list based on different options chosen by the user 
	Node* temp = head;
	Record swap = {};
	char choice[10];
	//std::cout << strcmp(temp->song.artist, temp->next->song.artist);
	int restart = 0;
	printf("What do you want to sort by?\n(1) Artist(A-Z)\n(2) Album Title(A-Z)\n(3) Rating(1-5)\n(4) Times PLayed(Most-Least)\n");

	fgets(choice, 50, stdin);
	choice[strlen(choice) - 1] = NULL;
	int success = 0;

	if (strcmp(choice, "1") == 0) { 


		while (temp != NULL)
		{



			if (temp->next != NULL)
			{

				if (strcmp(temp->song.artist, temp->next->song.artist) < 0)
				{
					swap = temp->song;
					temp->song = temp->next->song;
					temp->next->song = swap;


					restart = 1;
				}

			}
			if (restart == 1) {

				temp = head;
				restart = 0;

			}
			else
			{
				temp = temp->next;//making temp not head after temp is set to head
			}

		}


	}
	if (strcmp(choice, "2") == 0) { 


		while (temp != NULL)
		{



			if (temp->next != NULL)
			{

				if (strcmp(temp->song.album, temp->next->song.album) < 0)
				{
					swap = temp->song;
					temp->song = temp->next->song;
					temp->next->song = swap;


					restart = 1;
				}

			}
			if (restart == 1) {

				temp = head;
				restart = 0;

			}
			else
			{
				temp = temp->next;//making temp not head after temp is set to head
			}

		}


	}
	if (strcmp(choice, "3") == 0) { 

		
			while (temp != NULL)
			{

				//doesnt work for the first song the first time it is called

				if (temp->next != NULL)
				{

					if (temp->song.rating > temp->next->song.rating)
					{
						swap = temp->song;
						temp->song = temp->next->song;
						temp->next->song = swap;


						restart = 1; //sets value to 1 to make temp go back to the beguinning of the list 
					}

				}



				if (restart == 1) {
				
					temp = head;
					restart = 0;
				
				}
				else
				{
					temp = temp->next;//making temp not head after temp is set to head
				}
				//temp = temp->next;//making temp not head after temp is set to head

			}
			
		
	}
	if (strcmp(choice, "4") == 0) {


		while (temp != NULL)
		{



			if (temp->next != NULL)
			{

				if (temp->song.timesPlayed > temp->next->song.timesPlayed)
				{
					swap = temp->song;
					temp->song = temp->next->song;
					temp->next->song = swap;


					restart = 1;
				}

			}
			if (restart == 1) {

				temp = head;
				restart = 0;

			}
			else
			{
				temp = temp->next;//making temp not head after temp is set to head
			}

		}


	}


}

void edit() {// allows user to find a song based on artist and then edit all information of that song

	printf("What artist?\n");
	char artist[100];
	//std::cin >> artist;

	
	/*if (head != NULL)
	{
		
		printf("OK\n");
		scanf(" %s[^\n]", artist);
		printf("%s", artist);
		
	}*/
	//fgets(artist, 100, stdin);
	//artist = "\"Bieber, Justin\"";
	
	int i = 0;
	int choice = 1;
	char choiceStr[50];
	struct Node* temp = head;
	struct Node* edit = head;
	while (i == 0)
	{
		fgets(artist, 50, stdin);
		artist[strlen(artist) - 1] = NULL;
		while (temp != NULL) {
			


			if (strcmp(artist, temp->song.artist) == 0)
			{
				i++;
				printf("%i %s", i, temp->song.name);
				printf("\n");


			}

			temp = temp->next;
		}
		if (i == 0) {
			printf("No artist found\n");
			break;

		}
		else
		{
			



			temp = head;
			if (i > 1 && choice >= 0 && choice < i) {
				printf("Which one?\n");
				fgets(choiceStr, 50, stdin);
				choiceStr[strlen(choiceStr)] = NULL;
				choice = atoi(choiceStr);

			}

			while (temp != NULL && choice > 0) {
				if (strcmp(artist, temp->song.artist) == 0)
				{
					edit = temp;

					choice--;
				}


				temp = temp->next;

			}
			//printf(edit->song.name);
			printf("What do you want to edit?\n");
			printf("\n(1)Song Artist\n(2)Song Album\n(3)Song Name\n(4)Song Genre\n(5)Song Length(minutes)\n(6)Song Length\n(7)Times Played\n(8)Song Rating\n");
			char option[10];
			char change[100];
			fgets(option, 10, stdin);
			option[strlen(option) - 1] = NULL;
			printf("Input:");
			fgets(change, 100, stdin);
			change[strlen(change) - 1] = NULL;
			if (strcmp(option, "1") == 0)
			{


				strcpy(edit->song.artist, change);






			}
			if (strcmp(option, "2") == 0)
			{


				strcpy(edit->song.album, change);

			}
			if (strcmp(option, "3") == 0)
			{
				strcpy(edit->song.name, change);



			}
			if (strcmp(option, "4") == 0)
			{

				strcpy(edit->song.genre, change);


			}
			if (strcmp(option, "5") == 0)
			{
				if (atof(change) != 0) {
					(edit->song.length).min = atof(change);
				}
				else
				{
					printf("Input not compatible");
					break;
				}

			}
			if (strcmp(option, "6") == 0)
			{
				if (atof(change) != 0) {
					(edit->song.length).sec = atof(change);
				}
				else
				{
					printf("Input not compatible");
					break;
				}
				

			}
			if (strcmp(option, "7") == 0)
			{

				edit->song.timesPlayed = atof(change);
				if (atof(change) != 0) {
					edit->song.timesPlayed = atof(change);
				}
				else
				{
					printf("Input not compatible");
					break;
				}

			}
			if (strcmp(option, "8") == 0)
			{

				
				if (atof(change) != 0 && (atof(change) > 0 && atof(change) < 6)) {
					edit->song.rating = atof(change);
				}
				else
				{
					printf("Input not compatible");
					break;
				}


			}

			printf("\n");

		}

	}
}
void load() {//loads songs from excel file 

	char line[100] = "";
	char* token;

	Record song;
	FILE* infile = fopen("musicPlayList.csv", "r");

	if (infile == NULL) {
		printf("oops");
		exit(1);


	}


	while (fgets(line, 100, infile) != NULL)
	{
		//std::cout << "->";
		//std::cout << line;

		if (line[0] == '\"') {

			//char comma[10] = ",";
			token = strtok(line, "\"");
			//std::cout << token;
			//strtok(NULL, ",");
			//char comma[5] = ",";
			strcpy(song.artist, token);

			char songCopy[100] = "\"";
			char songCopy1[100] = "\"";
			strcat(songCopy, song.artist);
			strcat(songCopy, songCopy1);
			strcpy(song.artist, songCopy);

			//strcat(token, strtok(NULL, ","));

			//std::cout << song.artist;
		}
		else
		{
			token = strtok(line, ",");
			strcpy(song.artist, token);
		}

		//strcpy(song.artist, token);
		//printf(song.artist);
		//std::cout << token;
		token = strtok(NULL, ",");
		strcpy(song.album, token);
		//std::cout << token;
		token = strtok(NULL, ",");
		strcpy(song.name, token);
		//std::cout << token;
		token = strtok(NULL, ",");
		strcpy(song.genre, token);
		//std::cout << token;
		token = strtok(NULL, ":");
		song.length.min = atoi(token);
		//std::cout << token;
		token = strtok(NULL, ",");
		song.length.sec = atoi(token);
		//std::cout << token;
		token = strtok(NULL, ",");
		song.timesPlayed = atoi(token);
		token = strtok(NULL, "\n");
		song.rating = atoi(token);
		//std::cout << token;

		//std::cout << song.artist << "  " << song.album << " "<< song.name << " "<< song.genre << " " << song.length.min << " "<< song.length.sec << " " << song.timesPlayed << " " << song.rating << "\n";
		InsertAtTail(song);

	}

	fclose(infile);


	cur = head;
}
void play() {//displays songs in order for 10 seconds before showing the next song, nothing can be input until the end of the list 

	while (cur != NULL)
	{

		printCur();

		Sleep(10000);
		
		
		//wait 10 seconds

		cur = cur->next;
	}
	cur = head;


}
int main() {

	/*Driver code to test the implementation*/
	head = NULL; // empty list. set head as NULL. 

	// Calling an Insert and printing list both in forward as well as reverse direction. 
	
	char testGrab[10];
	

	//start test code
	printf("1. Run test shuffle.\n");
	printf("2. Run test insert\n");
	printf("3. Run test delete\n");


	fgets(testGrab, 50, stdin);
	testGrab[strlen(testGrab) - 1] = NULL;

	int option = atoi(testGrab);

	switch (option)
	{
	case 1:
		printf("Test Shuffle:\n");
		load();
		shuffle();
		//testPushOnEmptyStack();
		break;
	case 2:
		printf("Test insert\n");
		
		testing = 1;
		
		newsong();
		testing = 0;
		//puts();


		//printf("orignal string: %s\nreversed string: ", str);
		//puts(reverseString(str));
		break;
	case 3:

		printf("Test delete\n");

		printf("Inserting Test Song\n");

		testing = 1;

		newsong();

		deleteSong();


		testing = 0;

		//printf("orignal string: %s\nreversed string: ", str);
		//puts(reverseString(str));
		break;
	}
	//end test code



	char choice[10];
	char disChoice[10];
	cur = head;







	while (strcmp(choice,"11") != 0 )//menu loop, will just loop until the user inputs a valid value, loop is not exited until user input is 11,
		//options 12-14 were functions I put in my program to help test and were not required functions for pa3, not displayed as an option, but are still usable if 12-14 is input.
	{

		
		printf("Select an option: \n(1)Load \n(2)Store \n(3)Display \n(4)Insert \n(5)Delete \n(6)Edit \n(7)Sort \n(8)Rate \n(9)Play \n(10)Shuffle \n(11)Exit \n");
		

		



		fgets(choice, 50, stdin);
		choice[strlen(choice) - 1] = NULL;
		
		if (strcmp(choice, "1") == 0) { //load

			load();//done
			

		}
		if (strcmp(choice, "2") == 0) {// store

			store();//Works perfectly

		}
		if (strcmp(choice, "3") == 0) { // display
			//Done
			printf("Type 1 to display songs from an artist\nType 2 to display all songs\n");

			fgets(disChoice, 50, stdin);
			disChoice[strlen(disChoice) - 1] = NULL;

			
			if (strcmp(disChoice, "1") == 0) {

				printArtist();

			}
			if (strcmp(disChoice, "2") == 0) {
			
				Print();
			
			
			}
			
		

		}
		if (strcmp(choice, "4") == 0) {// insert

			
			newsong();//done

		}
		if (strcmp(choice, "5") == 0) {//delete

			deleteSong();//done


		}
		if (strcmp(choice, "6") == 0) {//edit


			edit();//Finally works 
			
			
		}
		if (strcmp(choice, "7") == 0) {//sort

			sort();//works


		}
		if (strcmp(choice, "8") == 0) {//rate

			//
			rate();//done

		}
		if (strcmp(choice, "9") == 0) {//play


			play();//done 

		}
		if (strcmp(choice, "10") == 0) {//shuffle


			shuffle();// done, can play the same song more than once, plays the amount of songs that are in the list.

		}
		if (strcmp(choice, "11") == 0) {//exit

			//done


		}
		if (strcmp(choice, "12") == 0) {// select next song by cur
		
		
			nextSong();
			printCur();
		
		
		}
		if (strcmp(choice, "13") == 0) // select last song by cur
		{
			lastSong();
			printCur();

		}
		if (strcmp(choice, "14") == 0) {// print cur song
		
			ReversePrint();
			printCur();
		}

	}
	return 0;
}