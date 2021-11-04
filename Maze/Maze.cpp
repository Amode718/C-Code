// Name: Andrei Modiga
// Assignment number: 5
// Assignment: Maze
// Date last modified: November 3, 2021
// Honor statement: I have neither given nor received any unauthorized help on this assignment. 


#include <iostream>
#include "Maze.h"


// Creates a Maze object with the given number of rows and columns
// This is a minimal functional constructor; you will need to 
// augment the constructor initalizer list and add code to the
// body.
Maze::Maze(int rows, int columns) : rows(rows), columns(columns), rooms(std::vector<std::vector<int>>(rows, std::vector<int>(columns, ALL_WALLS))), 
	                                set(rows*columns) {
    // Add your code (and add to constructor initalizer list as
    // needed.
}


// Returns the room information at the given row, column location, encoded
// as bit patterns specifies above (LEFT_WALL, RIGHT_WALL, etc.)
int Maze::operator()(int row, int column) const {
    return rooms[row][column];
}


// Randomly generates a maze
void Maze::build_maze() {
    // reset
    set.Split();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            rooms[i][j] = ALL_WALLS;
        }
    }

    // remove exit wall
    rooms[rows - 1][columns - 1] = ~RIGHT_WALL;

    // remove entrance wall
    rooms[0][0] = ~LEFT_WALL;
  

    while (set.Cardinality() > 1) {
        int roomColumn = rand() % columns;
        int roomRow = rand() % rows;
        int roomRemove = NO_WALLS;
        int connectedRemove = NO_WALLS;
        int connectedColumn = roomColumn;
        int connectedRow = roomRow;




        // picks a random room
        if (rand() % 2) {
            if (rand() % 2 && (connectedRow != rows - 1)) {
                connectedRow++; 
                connectedRemove = BOTTOM_WALL;
                roomRemove = TOP_WALL;
            }
            else if (connectedRow != 0) {
                connectedRow--;
                connectedRemove = TOP_WALL;
                roomRemove = BOTTOM_WALL;
            }
            else {
                connectedRow++;  
                connectedRemove = BOTTOM_WALL;
                roomRemove = TOP_WALL;
            }
        }
        else {
            if (rand() % 2 && (connectedColumn != columns - 1)) {
                connectedColumn++;
                connectedRemove = LEFT_WALL;
                roomRemove = RIGHT_WALL;
            }
            else if (connectedColumn != 0) {
                connectedColumn--;
                connectedRemove = RIGHT_WALL;
                roomRemove = LEFT_WALL;
            }
            else {
                connectedColumn++;
                connectedRemove = LEFT_WALL;
                roomRemove = RIGHT_WALL;
            }
        }

        if (set.Find(roomRow * columns + roomColumn) != set.Find(connectedRow * columns + connectedColumn)) {
            set.Union((roomRow * columns + roomColumn), (connectedRow * columns + connectedColumn));
            rooms[roomRow][roomColumn] &= ~roomRemove;
            rooms[connectedRow][connectedColumn] &= ~connectedRemove;
        }

    }
}