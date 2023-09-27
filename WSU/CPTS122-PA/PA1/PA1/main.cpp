
/*

Name: Cade Chaplin
Class: Cpt S 122; Lab Section 9                                                *
Programming Assignment: PA1                                                       *
Date: 9/11/2022

Project Objective: Take data from excel file, data cleanse the file for missing data and duplicates,
sort through the data and sort it into an array. Once sorted, complete muiltiple functions using the stored data,
and then print it into a new excel file along with the array of data that has been cleansed.

 
*/
#include "Header.h"
#include <iostream>





/*
* Function: maxSteps()                                                                  *
* Date Created:                                                                                   *
* Date Last Modified:                                                                             *
* Description: Return the max amount of steps in a single minute from the cleansed data passed to the function
*/
int maxSteps(FitbitData data[1444]) {

	unsigned int steps = 0;
	
	for (int i = 0; i < 1444; i++)
	{

		if (data[i].steps > steps)
		{

			steps = data[i].steps;

		}

	}

	return steps;
	
}

/*
* Function: aHeartRate()                                                                 *
* Date Created:                                                                                   *
* Date Last Modified:                                                                             *
* Description: Return average heart rate of all minutes from the data, excluding 0s that were put into the data to replace missing data
*/

double aHeartRate(FitbitData data[1444]) {
	double aHeartRate = 0;

	int j = 0;
		for (int i = 0; i < 1444; i++)
		{
			if (data[i].heartRate != 0)
			{
				aHeartRate = aHeartRate + data[i].heartRate;

				j++;
			}


		}
		

		aHeartRate = aHeartRate / j;
		
		return aHeartRate;


}


/*
* Function: totalCals()                                                                   *
* Date Created:                                                                                   *
* Date Last Modified:                                                                             *
* Description: 
Add up totals of all the calories burned in every minute in the data

*/

double totalCals(FitbitData data[1444]) {


	double cals = 0;
	for (int j = 0; j < 1440; j++)
	{

		cals = cals + data[j].calories;
	}

	return cals;

}

/*
* Function distance()                                                                   *
* Date Created:                                                                                   *
* Date Last Modified:                                                                             *
* Description: Add up the total distance traveled from all minutes of the data 
*/

double distance(FitbitData data[1444]) {

	double totalDistance = 0;
	for (int i = 0; i < 1440; i++)
	{
		totalDistance = totalDistance + data[i].distance;

	}

	return totalDistance;

}


/*
* Function: floors()                                                                   *
* Date Created:                                                                                   *
* Date Last Modified:                                                                             *
* Description: Add total amount of floors climbed in all minutes
*/

int floors(FitbitData data[1444]) {

	int totalFloors= 0;

	for (int i = 0; i < 1444; i++)
	{
		totalFloors = totalFloors + data[i].floors;
	
	}

	return totalFloors;


}


/*
* Function: stepsTaken()                                                                   *
* Date Created:                                                                                   *
* Date Last Modified:                                                                             *
* Description: Adds up totals of all steps taken during all minutes of the data 
*/

int stepsTaken(FitbitData data[1444]) {

	int totalSteps = 0;


	for (int i = 0; i < 1444; i++)
	{

		totalSteps = totalSteps + data[i].steps;

	}

	return totalSteps;
}


/*
* Function: dataCleanse()                                                                   *
* Date Created:                                                                                   *
* Date Last Modified:                                                                             *
* Description:
Sorts through all data points of the .csv file and puts a 0 between and two consectutive commas or between a comma and a newline 
*/

void dataCleanse(char targetLine[]) {

	char copy[100] = { "" };


	for (int g = 0; g < strlen(targetLine); g++)
	{
		copy[g] = targetLine[g];

	}

	//std::cout << copy;


	int i = 0;
	while (i < strlen(targetLine))
	{

		if (targetLine[i] == ',' && targetLine[i + 1] == ',' || targetLine[i] == ',' && targetLine[i + 1] == '\n') {
			int valueHolder = i;


			copy[i + 1] = '0';
			i++;

			while (i < strlen(targetLine))
			{

				copy[i + 1] = targetLine[i];
				i++;

			}

			strcpy(targetLine, copy);

			i = valueHolder;

		}
		i++;

	}

}

int main()
{
	//3 pts for correctly opening “FitbitData.csv” for mode read
	FILE *infile = fopen("FitbitData.csv", "r");
	char lines[1446][50] = { "" }; 

	
	int i = 0;
	char targetLine[50] = { "" };
	char targetPatientID[10] = { "" };
	int lineNumber = 0;
	
	FitbitData data[1444] = { {"", "", -1 , -1, 0, 0, 0, NONE} };

	//assert(infile != NULL); // check to see if we opened the file

	//2 pts for correctly checking the success of the file opening operation


	if (infile == NULL)
	{

		printf("could not open file"); // check to see if we opened the file
		exit(1);
	}


	if (fgets(targetLine, 20, infile) != NULL) {
		
		
		char copy[50] = { "" };

		
		
		char *token; 


		token = strtok(targetLine, ",");
		token = strtok(NULL, ",");

		strcpy(targetPatientID, token);

		

		
	}


	


	char ignore[1024];
	fgets(ignore, 50, infile);
	
	

	char lastMinute[20] = { "" };
	
	while (fgets(lines[lineNumber], 100, infile) != NULL) //(!feof(infile))
	{
		dataCleanse(lines[lineNumber]);
	

		
		char patientID[10] = {""};
		char minute[20] = { "" };
		char *token;

		token = strtok(lines[lineNumber], ",");
		
		strcpy(patientID, token);

		token = strtok(NULL, ",");
		
		strcpy(minute, token);

		


		if (strcmp(patientID,targetPatientID) == 0) {
		
			
			


			if (strcmp(lastMinute, minute) != 0) {
			
			//10 pts for correctly reading each record in the file as a string, one line at a time, and filtering and deduping any lines that do not belong to the target patient or are duplicates

				
				strcpy(data[i].patient, patientID);
				strcpy(data[i].minute, minute);
				
				token = strtok(NULL, ",");
				data[i].calories = atof(token);
				token = strtok(NULL, ",");
				data[i].distance = atof(token);
				token = strtok(NULL, ",");
				data[i].floors = atoi(token);
				token = strtok(NULL, ",");
				data[i].heartRate = atoi(token);
				token = strtok(NULL, ",");
				data[i].steps = atoi(token);
				
		
				token = strtok(NULL, "\n");
				
				if (atoi(token) == 1) {
					data[i].sleepLevel = ASLEEP;
					
				
				}
				if (atoi(token) == 2) {
					data[i].sleepLevel = AWAKE;


				}
				if (atoi(token) == 3) {
					data[i].sleepLevel = REALLYAWAKE;


				}
				


				//std::cout << i << " " << data[i].minute << " " << data[i].calories << " " << data[i].distance << " " << data[i].floors << " " << data[i].heartRate << " " << data[i].steps << " " << data[i].sleepLevel << "\n";
				i++;
				
				
				strcpy(lastMinute, minute);
				
			}


		
			
		}
		lineNumber++;

		
	}



	
	calculations output = {};
	output.aHeartRate = aHeartRate(data);
	output.maxSteps = maxSteps(data);
	output.totalCals = totalCals(data);
	output.distance = distance(data);
	output.floorsWalked = floors(data);
	output.totalSteps = stepsTaken(data);
	char sleepStart[9] = {" "};
	char sleepEnd[9] = { " " };

	int minutesLong = 0;
	int minutesLongest = 0;
	int maxholder = 0;
	int max = 0;
	char sleepHolder[8] = " ";
	for (int i = 0; i < 1440; i++) {
		if (data[i].sleepLevel > 1) {

			maxholder = data[i].sleepLevel + maxholder;
			minutesLong++;

		}
		else
		{
			if (maxholder > max)
			{
				max = maxholder;
				minutesLongest = minutesLong;

				strcpy(sleepStart, data[i - minutesLongest].minute);
				strcpy(sleepEnd, data[i].minute);
				
			}

			maxholder = 0;
			minutesLong = 0;
		}
	}
	
	
	fclose(infile);


	infile = fopen("Results.csv","w");

	if (infile == NULL)
	{

		printf("could not open file");
		exit(1);
	}
	else
	{
		fputs("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n", infile);
		fprintf(infile,"%f %s %f %s %i %s %i %s %f %s %i %s %s %s %s %s", output.totalCals, ",", output.distance, ",", output.floorsWalked, ",", output.totalSteps, ",", output.aHeartRate, ",", output.maxSteps, ",", sleepStart, ":", sleepEnd, "\n") ;
		
		for (int i = 0; i < 1440; i++)
		{
			fprintf(infile, "%s %s %s %s %f %s %f %s %i %s %i %s %i %s %i %s", data[i].patient, ",", data[i].minute, ",", data[i].calories, ",", data[i].distance, ",", data[i].floors, ",", data[i].heartRate, ",", data[i].steps, ",", (int)data[i].sleepLevel, "\n"); // data[i].floors, ",", data[i].heartRate, ",", data[i].steps, "\n");
		}


	}
	fclose(infile);







	//2 pts for correctly closing the “FitbitData.csv”
	
}





