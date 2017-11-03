/*****
	Create a matrix based graph representation.
	
	It will need to support the following operations.
	Ask the user how many points there are.
	Ask the user to label those points, ie "A", "B", "C"...
	Define the matrix as a square matrix (2 dimensional array) based on the number of points, also keep an array of the labels.	
	Repeatedly ask the user to define edges between two points. Add these edges to the matrix.
	Have a list method that will list out all of the edges in the graph.
*****/
#include <iostream>
#include <string>

using namespace std;

int points = 10;
void edge_print(int (*array)[10], size_t rows)
{
	std::cout << "Test" << endl;
}

/*
void edge_print(int (*a)[points])//[0(&a)[][10])//a)[][points])
{
	//std::cout << "better luck pal" << endl;
	std::cout << "print edges" << endl;
}*/

int main()
{
	int i = 0;
	std::string answer = "";
	//ask user to provide # of points & create nxn matrix
	std::cout << "How many points will your graph contain?" << endl;
	std::cin >> points;
	std::cout << "your graph will contain " << points << " points." << endl;
	
	int graph[10][10] = {};
	std::string labels[points] = {};
	
	//ask user for point labels and throw into array
	while(i < points)
	{
		std::cout << "Provide labels to differentiate your points:" << endl;
		std::cin >> labels[i];
		i++;
	}
	
	//ask user to define edges b/t two points and add to matrix
	for(i = 0; i < points; i++)
	{
		for(int j = 0; j < points; j++)
		{
			std::cout << "Is point " << labels[i] << " connected to point " << labels[j] << "? Type (Y) for yes or (N) for no." << endl;
			std::cin >> answer;
			if(answer == "Y") graph[i][j] = 1;
			else graph[i][j]= 0;
		}
	}
	//print all edges
	edge_print(graph, points);
	return 0;
}
