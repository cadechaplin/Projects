/*

Name: Cade Chaplin
Class: Cpt S 122; Lab Section 9                                                *
Programming Assignment: PA1                                                       *
Date: 9/11/2022

Project Objective: Take data from excel file, data cleanse the file for missing data and duplicates,
sort through the data and sort it into an array. Once sorted, complete muiltiple functions using the stored data,
and then print it into a new excel file along with the array of data that has been cleansed.


*/
#ifndef C_REVIEW_EXAMPLE_H // start of guard code
#define C_REVIEW_EXAMPLE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // printf (), scanf (), fgets (), fputs ()
#include <stdlib.h> // malloc (), calloc (), realloc (), free (), exit()
#include <string.h> // strlen (), strcpy (), strncpy (), strcat (), strcmp (), strtok ()

typedef enum sleep

{

    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3

} Sleep;

//3 pts for correctly defining enum Sleep


typedef struct fitbit

{

    char patient[10];

    char minute[9];

    double calories;

    double distance;

    unsigned int floors;

    unsigned int heartRate;

    unsigned int steps;

    Sleep sleepLevel;

} FitbitData;


typedef struct calculations
{

    double distance;//

    unsigned int floorsWalked;

    unsigned int totalSteps;

    double totalCals;//

    double aHeartRate;//

    unsigned int maxSteps;//

    int poorSleepStart;
};

//5 pts for correctly defining struct FitbitData


#endif 
