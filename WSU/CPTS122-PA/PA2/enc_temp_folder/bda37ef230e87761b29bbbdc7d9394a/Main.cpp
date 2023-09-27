/* Doubly Linked List implementation */
#include "PA2Header.h"

#include "Functions.cpp"




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
	newNode->song.timesPlayed = song.timesPlayed;
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
}

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
	FILE *infile = fopen("NewMusicPlayList.csv", "w");

	

	while (temp != NULL)
	{
			fprintf(
				infile, "%s,%s,%s,%s,%d:%d,%d,%d\n",
			temp->song.artist, temp->song.album, temp->song.name, temp->song.genre, temp->song.length.min, temp->song.length.sec, temp->song.timesPlayed, temp->song.rating
				);

		temp = temp->next;
	}


}
void nextSong() {

	if (cur->next != NULL) {
		cur = cur->next;
	}
	
}

void lastSong() {

	if (cur->prev != NULL) {
	
		cur = cur->prev;
	
	}


}

void printCur() {



	printf("%s ", cur->song.name);
	printf("%s ", cur->song.artist);
	printf("%s ", cur->song.album);
	printf("%s ", cur->song.genre);
	printf("%i ", cur->song.rating);
	printf("%d:%d", (cur->song.length).min, (cur->song.length).sec);
	printf("% i", cur->song.timesPlayed);
	printf("\n");



}

void deleteNode(Node *badNode) {
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

void deleteSong() {

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
		fgets(song, 50, stdin);
		song[strlen(song) - 1] = NULL;
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


void Print() {
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
void printArtist() {

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

void rate() {
	
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

void shuffle() {

	int listLen = 0;
	int listPos = 0;
	struct Node* temp = head;
	//struct Node** listCopy = &temp;
	
	while (temp!= NULL)//gets current length of list
	{
		listLen++;

		temp = temp->next;
		

	}
	
	temp = head;

	while (0<=listLen && temp != NULL)
	{

		//remove whatever is printed and select a random from i--;

		listPos = rand() % (listLen+1);
		temp = head;
		for (int i = 0; i < listPos; i++)
		{
			cur = temp;
			temp = temp->next;

		}
		printCur();
		deleteNode(temp);
		listLen--;
		
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


void newsong() {

	char choiceStr[50];
	Record song = {""};
	printf("Enter Song name\n");
	fgets(choiceStr, 50, stdin);

	choiceStr[strlen(choiceStr)-1] = NULL;
	strcpy(song.name, choiceStr);
	printf("Enter Artist name\n");
	fgets(choiceStr, 50, stdin);
	choiceStr[strlen(choiceStr)-1] = NULL;
	strcpy(song.artist, choiceStr);
	printf("Enter Album name\n");
	fgets(choiceStr, 50, stdin);
	choiceStr[strlen(choiceStr)-1] = NULL;
	strcpy(song.album, choiceStr);
	printf("Enter Genre\n");
	fgets(choiceStr, 50, stdin);
	choiceStr[strlen(choiceStr)-1] = NULL;
	strcpy(song.genre, choiceStr);
	printf("Enter length in minutes\n");
	fgets(choiceStr, 50, stdin);
	choiceStr[strlen(choiceStr)-1] = NULL;
	song.length.min = atoi(choiceStr);
	printf("Enter length in seconds\n");
	fgets(choiceStr, 50, stdin);
	choiceStr[strlen(choiceStr)-1] = NULL;
	song.length.sec = atoi(choiceStr);
	printf("Enter length in times played\n");
	fgets(choiceStr, 50, stdin);
	choiceStr[strlen(choiceStr)-1] = NULL;
	song.timesPlayed = atoi(choiceStr);
	printf("Enter length in rating\n");
	fgets(choiceStr, 50, stdin);
	choiceStr[strlen(choiceStr)-1] = NULL;
	song.rating = atoi(choiceStr);
	InsertAtHead(song);
}

void sort() {
	Node* temp = head;
	
	//std::cout << strcmp(temp->song.artist, temp->next->song.artist);
	while (temp != NULL)
	{
		Node* swap = temp->next;

		if (strcmp(temp->song.artist, swap->song.artist) < 0) 
		{
			
			
			if (temp->prev != NULL && temp->next != NULL) {
				swap->next->prev = temp;
				swap->prev = temp->prev;
				temp->prev = swap;
				swap->prev->next = swap;
				temp->next = swap->next;
				swap->next = temp;
			}
			temp = head;
		}




		temp = temp->next;
	}





}

void edit() {

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
void load() {

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
void play() {

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
	
	


	char choice[10];
	char disChoice[10];
	cur = head;
	while (strcmp(choice,"11") != 0 )
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
			//could use more conditional statements?
			
		}
		if (strcmp(choice, "7") == 0) {//sort

			sort();


		}
		if (strcmp(choice, "8") == 0) {//rate

			//
			rate();//done

		}
		if (strcmp(choice, "9") == 0) {//play


			play();//done 

		}
		if (strcmp(choice, "10") == 0) {//shuffle


			shuffle();

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
		
		
			printCur();
		}

	}
}