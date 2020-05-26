// Glowny program
#include <iostream>
#include "snake.h"

int main()
{
    int exit_status = 0;
    char letter = NULL;
    do
    {
        snake game = snake();

        cout << "Want to end?" << endl;
        cout << "y - yes, n - no" << endl;
        cin >> letter;
        if (letter == 'y')
        {
            cout << "Thank you for playing! :)" << endl;
            exit_status = 1;
        }
        else
        {

        }
    } while (exit_status == 0);
    system("PAUSE");
    return EXIT_SUCCESS;
}