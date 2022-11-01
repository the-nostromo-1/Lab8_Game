// Main Game Loop
// David J Tinley
// 10/31/2022

#include "Maze.h"
#include "Maze.cpp"

int main() {
    srand(time(nullptr));

    Room mouse_room = startRoom; // initializing starting room
    
    RoomPair my_maze[numWalls]; // initializing array of walls
    clearWalls(my_maze); // initializing walls with -1 and '*'

    build(my_maze); // building walls

    char see_walls;
    cout << "Do you want to see the walls? y or n?" << endl;
    cin >> see_walls; // ask user if they want to see the walls
    if (see_walls == 'y') {
        printMaze(my_maze);
        cout << endl;
    }

    int number_of_tries = 0; // tracking number of tries    
    while (matchRoom(mouse_room, cheeseRoom) == false) { // Main game loop
        cout << "Mouse room current location: ";
        printRoom(mouse_room);
        cout << endl;

        cout << "Where would you like to go?" << endl;
        Room new_move_room = nextMove(mouse_room);
        RoomPair my_next_move = {mouse_room, new_move_room};

        if (new_move_room.x < 1 || new_move_room.x > mazeSize || new_move_room.y < 97 || new_move_room.y > mazeSize + 96 || checkMaze(my_maze, my_next_move) != -1) {

            cout << "There is a wall there, try again." << endl;
            ++number_of_tries;
            
            char quit_option; // char for quiting the game
            if (number_of_tries >= 5) { // giving player option to quit
                cout << "Would you like to keep trying? Enter y or n" << endl;
                cin >> quit_option;
                switch (quit_option) {
                    {
                case 'n':
                    cout << "Good bye" << endl;
                    return 0;
            
                default:
                    cout << "Keep trying" << endl;
                    number_of_tries = 0; // reseting number of tries if player wants to continue
                    break;
                    }
                }
            }
        }
        else {
            mouse_room = new_move_room;
        }
        cout << " " << endl;
    } cout << "Congrats, you found the cheese!" << endl;
}