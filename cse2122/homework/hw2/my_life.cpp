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

      LIFE Game Parameters:
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

bool check_for_life(bool **world, int nrows, int ncols);

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

   // allocate memory for 2d arrays 'world' and 'copy'
   world = new bool *[nrows];
   copy = new bool *[nrows];

   for (int i(0); i < nrows; ++i) {
      world[i] = new bool [ncols];
      copy[i] = new bool [ncols];
   }

   // initialize the world and display
   initialization(world, nrows, ncols);
   display(world, nrows, ncols);

   // prompt user input, Generation/Quit
   cout << "next Generation or Quit (g/q): ";
   cin >> next;

   // LIFE while loop which iterates the game until the user would like to exit
   while (check_for_life(world, nrows, ncols) || next != 'g'){
      // generate and show the new world
      generation(world, copy, nrows, ncols);
      display(world, nrows, ncols);
   }

   // deallocate memory for dynamic 2d-arrays 'world' and 'copy'
   // clear memory from columns
   for (int i(0); i < nrows; i++) {
      delete [] world[i];
      delete [] copy[i];
   }
   // clear memory from remaining rows
   delete [] world;
   delete [] copy;

   // set remaining pointers to NULL
   world = nullptr;
   copy = nullptr;

   // exit program
   return 0;
}

bool check_for_life(bool **world, int nrows, int ncols) {
   int alive_count(0);

   for (int i(0); i < nrows; ++i) {
      for (int k(0); k < ncols; ++k) {
         if (world[i][k] == true) {
            ++alive_count;
         }
      }
   }

   if (alive_count > 0) {
      return true;
   }
   else {
      return false;
   }
}

// function that takes game array parameters and asks the user for the location of the initial alive cells
// returns nothing to the main program
void initialization(bool **world, int nrows, int ncols) {
   int alive_count(0);  // variable for teh number of alive cells (given by user)
   int **coordinate;  // 2d dynamic array for the coordiantes of given LIFE cells
   const int x(0), y(1);  // variables for the x-y coordinate locations in the 2d array below
   const bool ALIVE(true), EMPTY(false);  // constant expressions for alive and empty cells

   // ask user for the number of alive cells in the game array
   cout << "Enter number of alive cells: ";
   cin >> alive_count;

   // allocate memory for the coordinate matrix
   coordinate = new int *[alive_count];

   for (int i(0); i < alive_count; ++i) {
   	coordinate[i] = new int[2];
   }

   if (alive_count > 0) {
      // ask user for the location of the alive cells
      cout << "Enter coordinates of alive cells: " << endl;


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
         world[coordinate[i][x]][coordinate[i][y]] = ALIVE;
      }
   }

   // set remaining 'world' elements to false
   for (int i(0); i < nrows; ++i) {
      for (int k(0); k < ncols; ++k) {
         if (world[i][k] != ALIVE) {
            world[i][k] = EMPTY;
         }
      }
   }

   // deallocate memory used to store alive cell locations
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
   int r(0), c(0);  // initial loop conditions
   int rf(0), cf(0); // ending loop conditions

   // set loop sequence conditions
   // value for initial row integer
   if (i == 0) {
      r = 0;  // if element number is 0, set initial r to 0
   }
   else {
      r = i - 1;  // otherwise set to the element minus 1
   }
   // value for final column integer
   if (i == (nrows - 1)) {
      rf = i;  // if element is at end of row, set final r to max column element
   }
   else {
      rf = i + 1;  // otherwise set to the following column number
   }

   // same conditions apply to columns as did to rows
   if (j == 0) {
      c = 0;
   }
   else {
      c = j - 1;
   }

   // same conditions apply to columns as did to rows
   if (j == (ncols - 1)) {
      cf = j;
   }
   else {
      cf = j + 1;
   }

   // for the coordinates 'i' and 'j' given, evaluate surrounding cells
   for (int row(r); row < (rf + 1); ++row) {
      for (int col(c); col < (cf + 1); ++col) {
         // if the cell value is 'true', add to total neighboring cell count
         if (world[row][col] == true) {
         	++count;
         }
      }
   }

   // if the given element is true, subtract from 'count'
   if (world[i][j] == true) {
   	--count;
   }

   // return number of neighboring alive cells
   return count;
}

void generation(bool **world, bool **copy, int nrows, int ncols){
   int count(0);  // variable used to count number of surrounding alive game cells within loop
   const bool ALIVE(true), EMPTY(false);

   // set 'copy' equal to the initial 'world' 2d array
   for (int i(0); i < nrows; ++i) {
      for (int k(0); k < ncols; ++k) {
         copy[i][k] = world[i][k];
      }
   }

   // evaluate all elements of the 'copy' array for the correct conditions to "birth" or "kill" cells
   for (int i(0); i < nrows; ++i) {
      for (int k(0); k < ncols; ++k) {
      	count = neighbor_count(copy, nrows, ncols, i, k);

         // conditions on whether the current game cell is birthed, dies or remains the same
         // if neighbor count is less than 2
         if (count < 2) {
            // and the 'world' element value is true, the element is set to false
            if (copy[i][k] == ALIVE) {
               world[i][k] = EMPTY;
            }
         }
         // if neighbor count is equal to three
         else if (count == 3) {
            // and the 'world' element value is false, the element is birthed
            if (copy[i][k] == EMPTY) {
               world[i][k] = ALIVE;
            }
         }
         else if (count > 3) {
            if (copy[i][k] == ALIVE) {
               world[i][k] = EMPTY;
            }
         }
      }
   }

   // return nothing
   return;
}

// print out the desired 2 dimensional array in row, collumn orientation
void display(bool **world, int nrows, int ncols) {
	// display the top row frame
	for (int i(0); i < (ncols + 2); ++i) {
		cout << '=';
	}
	cout << endl;

   // iterate over all rows
   for (int i(0); i < nrows; ++i) {
   	cout << '|';
      // iterate over all collumns
      for (int k(0); k < ncols; ++k) {
      	// if the cell is alive, output an asterisk
         if (world[i][k] == true) {
            cout << '*';
         }
         // if dead, output a space
         else {
            cout << ' ';
         }
      }
      // when row is printed, enter to next collumn
      cout << '|' << endl;
   }

   // display the bottom row frame
	for (int i(0); i < (ncols + 2); ++i) {
		cout << '=';
	}
	cout << endl;

   // return nothing
   return;
}
