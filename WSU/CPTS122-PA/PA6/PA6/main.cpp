#include "BST.h"

/*
Cade Chaplin 
PA^

Make a BST with a template that loads in a sorted morse code tree when constructed. 
Open a file and convert it to morse code.



*/

int main() {


	
	//BST  <char, string> tree(4);

	
	std::ifstream input;
	
	//input.open("MorseTable.txt", std::ios::in);

	
	 BST  <char, string> tree(1);// giving the constructor a int will make it use a different constructor definition that will read the file into the tree
	 // I rearranged the csv enough so that it works like a tree should rather than just a linked list 
	char letter;
	string line;

	string morse;
	/*
	while (input.is_open())
	{



		getline(input, line);
		



		
		if(line != "") {
			
			letter = line[0];
			
			morse = line.substr(2, line.size());

		
			
			tree.insert(letter, morse);
			
		}
		else
		{
			input.close();
		}
		

	}
	*/

	input.open("Convert.txt", std::ios::in);//outputs file to the screen 
	while (input.is_open())
	{

		while (input.good()) {


			input.get(letter);
			


			if (input.eof()) {
				input.close();


			}
			else
			{
				cout << letter;
			}
		}

	}
	cout << endl << "Conversion to Morse:" << endl;
	input.open("Convert.txt", std::ios::in);
	while(input.is_open())
	{

		while (input.good() ) {

			
			

				input.get(letter);


				if (input.eof()) {

					input.close();

				}
				else
				{

					if (letter == '\n') {
						cout << '\n';

					}
					else
					{
						tree.search((char)toupper(letter));
						cout << "   ";
					}

				}

		}
		
			


		
		

	}




	
	//tree.postorderTraversal();
		


	return 0;
}