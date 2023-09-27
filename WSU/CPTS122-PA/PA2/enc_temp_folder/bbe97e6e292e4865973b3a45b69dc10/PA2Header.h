#pragma once
#ifndef C_REVIEW_EXAMPLE_H // start of guard code
#define C_REVIEW_EXAMPLE_H

#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <windows.h>

typedef struct duration {

	unsigned int min;
	unsigned int sec;

}duration;


typedef struct musicData
{
	char artist[100];
	char album[100];
	char name[100];
	char genre[100];
	duration length;
	unsigned int timesPlayed;
	unsigned int rating;



}Record;

struct Node {

	Record song;
	struct Node* next;
	struct Node* prev;
};




#endif