// Homework 2
// File: life.cpp
// Created by: Michael Napoli
// Created on: 1/22/2020
// Last modified on: 

/*
   Purpose: Program that simulates the game of LIFE developed by John Horton Conway
      Game Details: The board (initial parameters given by the user) will consist of
         "alive" and "dead" spaces. Each generation iteration, the board will evaluate 
         certain parameters and decide whether a space will be birthed, die, remain 
         living, or remain dead. The parameters are listed below.

      LIFE Cell Parameters:
         - If a cell is alive, it will die of overpopulation if it has more tha three alive 
            cells surrounding it.
         - If a cell is alive, it will die of loneliness if it has less than three surrounding
            cells that are also alive.
         - If a cell is dead, it will be birthed if it has exactly three surrounding alive 
            cells that are alive.
         - A cell cannot die and be birthed simultaneously within the same generation.

      Once the game is initialized, it will continue until the user ends the program by
      entering 'q' when prompted to do so.
*/

#include <iostream>
using namespace std;

void allocate_ptr(bool **ptr_matrix, int nrows, int ncols);

void deallocate_ptr(bool **ptr_matrix, int nrows);

void initialization(bool **world, int nrows, int ncols);

int neighbor_count(bool **world, int nrows, int ncols, int i, int j);

void generation(bool **world, bool **copy, int nrows, int ncols);

void display(bool **world, int nrows, int ncols);

int main(){
   bool **world, **copy;  // pointer variables for the game matrices
   int nrows, ncols;  // number of rows and columns in the game matrice
   char next;  // variable used to control whether the game continues or not

   // ask user for the dimensions of the game matrices 'world' and 'copy'
   cout << "Enter world dimensions (rows and columns): ";
   cin >> nrows >> ncols;

   // allocate memory for dynamic 2d-arrays 'world' and 'copy' using 'allocate_ptr()' function
   allocate_ptr(world, nrows, ncols);
   allocate_ptr(copy, nrows, ncols);

   // initialize the world and display
   initialization(world, nrows, ncols);
   display(world, nrows, ncols);

   // prompt user input, Generation/Quit
   cout << "next Generation or Quit (g/q): ";
   cin >> next;

   // LIFE while loop which iterates the game until the user would like to exit
   while (next == 'g' || next == 'G'){
      // generate and show the new world
      generation(world, copy, nrows, ncols);
      display(world, nrows, ncols);
      cout << "next Generation or Quit (g/q): ";
      cin >> next;
   }

   // deallocate memory for dynamic 2d-arrays 'world' and 'copy' using 'deallocate_ptr()' function
   deallocate_ptr(world, nrows);
   deallocate_ptr(copy, nrows);

   return 0;  // exit program
}

void allocate_ptr(bool **ptr_matrix, int nrows, int ncols) {
   // allocate memory for the correct number of rows
   ptr_matrix = new bool *[nrows];

   // for each row element, allocate memory for correct number of columns
   for (int i(0); i < nrows; ++i) {
      ptr_matrix[i] = new bool [ncols];
   }

   // return nothing
   return;
}

void deallocate_ptr(bool **ptr_matrix, int nrows) {
   // for all rows of a 2d array, deallocate all columns
   for (int i(0); i < nrows; ++i) {
      delete [] ptr_matrix[i];
   }
   // clear data from all 'matrix' rows
   delete [] ptr_matrix;

   // set matrix pointer to null
   ptr_matrix = nullptr;

   // return nothing
   return;
}

// function that takes game array parameters and asks the user for the location of the initial alive cells
// returns nothing to the main program
void initialization(bool **world, int nrows, int ncols) {
   int alive_count(0);  // variable for teh number of alive cells (given by user)
   int **coordinate;  // 2d dynamic array for the coordiantes of given LIFE cells
   const int x(0), y(1);  // variables for the x-y coordinate locations in the 2d array below
   const bool ALIVE(true);  // constant true expression for alive cells

   // start by setting all 2d array values to 'false'
   for (int i(0); i < nrows; ++i) {
      for (int k(0); k < ncols; ++k) {
         world[i][k] = false;
      }
   }
   
   // ask user for the number of alive cells in the game array
   cout << "Enter number of alive cells: ";
   cin >> alive_count;

   // allocate memory for the coordinate matrix
   coordinate = new int *[alive_count];

   for (int i(0); i < alive_count; ++i) {
   	coordinate[i] = new int[2];
   }

   // ask user for the location of the alive cells
   cout << "Enter coordinates of alive cells: ";

   for (int i(0); i < alive_count; ++i) {
      cin >> coordinate[i][x] >> coordinate[i][y];
   }

   // check for invalid cell locations
   // loop through 'coordinate' 2d array
   for (int i(0); i < alive_count; ++i) {
      // if x-value of coordinate exceeds nrows or is negative, it is invalid
      if (coordinate[i][x] < 0 || coordinate[i][x] > nrows) {
         cout << "ER" << endl;
         break;
      }

      //if y-value of coordinates exceed ncols or is negative, it is invalid
      if (coordinate[i][y] < 0 || coordinate[i][y] > ncols) {
         cout << "ER" << endl;
         break;
      }
   }

   // if the coordinates given by the user are valid, enter the live cells into the 'world' matrix
   // do this by marking the 'world' cells as true
   for (int i(0); i < alive_count; ++i) {
      world[coordinate[i][x]][coordinate[i][y]] = true;
   }

   // deallocate memory used to store game cell locations
   for (int i(0); i < alive_count; ++i) {
   	delete [] coordinate[i];
   }
   delete [] coordinate;

   // return nothing
   return;
}

// function that counts number of neighboring alive cells
// returns the number of neighboring cells for use by the main program
int neighbor_count(bool **world, int nrows, int ncols, int i, int j) {
   int count(0);  // variable used to keep track of neighboring alive cells

   // for the coordinates 'i' and 'j' given, evaluate surrounding cells
   for (int r(i - 1); r < (i + 1); ++r) {
      for (int c(j - 1); c < (j + 1); ++c) {
         // if the cell value is 'true' and add to total neighboring cell count
         if (world[r][c] == true && (r != i && c != j)) {
            ++count;
         }
      }
   }
   
   // return number of neighboring alive cells
   return count;
}


void generation(bool **world, bool **copy, int nrows, int ncols){
   // set 'copy' equal to the initial 'world' 2d array
   for (int i(0); i < nrows; ++i) {
      for (int k(0); k < ncols; ++k) {
         copy[i][k] = world[i][k];
      }
   }

   // evaluate all elements of the 'copy' array for the correct conditions to "birth" or "kill" cells
   for (int i(0); i < nrows; ++i) {
      for (int k(0); k < ncols; ++k) {
      	if (neighbor_count(copy, nrows, ncols, i, k) == 3) {
      		if (copy[i][k] == false) {
      			copy[i][k] == true;
      		}
      	}
      }
   }

   // return nothing
   return;
}

// print out the desired 2 dimensional array in row, collumn orientation
void display(bool **world, int nrows, int ncols) {
   // iterate over all rows
   for (int i(0); i < nrows; ++i) {
      // iterate over all collumns
      for (int k(0); k < ncols; ++k) {
      	// if the cell is alive, output an asterisk
         if (world[i][k] == true) {
            cout << '*' << " ";
         }
         // if dead, output a space
         else {
            cout << ' ' << ' '; 
         }
      }
      // when row is printed, enter to next collumn
      cout << endl;
   }

   // return nothing
   return;
}