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

void edge_print(int **array, int rows, int cols, std::string *labels)
{
	std::cout << endl << "Your graph's adjacency matrix: " << endl << '\t';
	for(int i = 0; i < rows; i++) std::cout << labels[i] << '\t';
	std::cout << endl;
	
	for(int i = 0; i < rows; i++)
	{
		std::cout << labels[i] << '\t';
		for(int j = 0; j < cols; j++) std::cout << array[i][j] << '\t';
		std::cout << endl;
	}	
}

int main()
{
	int points = 0, i = 0;
	std::string answer = "";
	
	//user provides # of points in graph, used to construct nxn adjacency matrix
	std::cout << "How many points does your graph contain?" << endl;
	std::cin >> points;
	
	int adj_matrix[points][points] = {};		//2D array (nxn) that will contain adjacency matrix weights
	int *arr[points];					//array of size n of pointer to pointer (since arrays are just a pointer to chunk of memory)
	std::string labels[points] = {};	//adjacency matrix labels
	
	//user defines adjacency matrix labels
	while(i < points)
	{
		std::cout << "What are your graph's vertex labels?:" << endl;
		std::cin >> labels[i];
		i++;
	}
	
	//user defines edges b/t two points and weight is added to adjacency matrix
	for(i = 0; i < points; i++)
	{
		for(int j = 0; j < points; j++)
		{
			std::cout << "Is point " << labels[i] << " connected to point " << labels[j] << "? Type (Y) for yes or (N) for no." << endl;
			std::cin >> answer;
			if(answer == "Y") adj_matrix[i][j] = 1;
			else adj_matrix[i][j]= 0;
		}
	}
	
	for(int j = 0; j < points; j++)		//set array of pointers to point at each row of the graph
	{
		arr[j] = adj_matrix[j];
	}
	
	//print all edges
	edge_print(arr, points, points, labels);
	return 0;
}
