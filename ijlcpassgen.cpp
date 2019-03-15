/**
 ************************************************************************************************************************
 *
 *  @file                   ijlcpassgen.cpp
 *  @brief                  Indiana Jones and the Last Crusade password generator
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   March 15th, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   N.E.S. Version
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    int level = 0;
    int score = 0;
    int whip = 0;
    int gun = 0;
    int random1 = 0;
    int random2 = 0;
    string input = "";
    wchar_t tempArray[5];
    int tempInt = 0;
    wchar_t passwordArray[8];

    cout << "Indiana Jones and the Last Crusade password generator v 1.0" << endl;
    cout << "For use with the N.E.S., UBI version" << endl;
    cout << "Coded by: sleepy9090" << endl;
    cout << "======================================" << endl;
    cout << endl;

    while (true) {
        cout << "Enter level number (1..7): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> level)
        {
            if (level >= 1 && level <= 7)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Enter score number (0..65530): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> score)
        {
            if (score >= 0 && score <= 65530)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Whip (0 for no, 1 for yes): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> whip)
        {
            if (whip >= 0 && whip <= 1)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Gun (0 for no, 1 for yes): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> gun)
        {
            if (gun >= 0 && gun <= 1)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Enter random number 1 (0..127): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> random1)
        {
            if (random1 >= 0 && random1 <= 127)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Enter random number 2 (0..15): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> random2)
        {
            if (random2 >= 0 && random2 <= 15)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    tempArray[0] = level & 7;
    tempArray[1] = score >> 8 & 255;
    tempArray[2] = score & 255;
    tempArray[0] |= (random2 & 15) << 3;
    tempArray[3] = random1 & 127;

    if(whip == 1)
    {
        tempArray[0] |= 128;
    }
   
    if(gun == 1)
    {
        tempArray[3] |= 128;
    }

    tempArray[0] = tempArray[0] - (random1 & 127) & 255;
    tempArray[1] = tempArray[1] + (random1 & 127) & 255;
    tempArray[2] = tempArray[2] - (random1 & 127) & 255;

    tempInt = (int)tempArray[0] + (int)tempArray[1] + (int)tempArray[2] + (int)tempArray[3];
    tempArray[4] = (tempInt & 255) + (tempInt >> 8);

    passwordArray[7] = tempArray[4] >> 3;
    passwordArray[6] = ((tempArray[4] & 7) << 2) + (tempArray[3] >> 6);
    passwordArray[5] = (tempArray[3] & 62) >> 1;
    passwordArray[4] = ((tempArray[3] & 1) << 4) + (tempArray[2] >> 4);
    passwordArray[3] = ((tempArray[2] & 15) << 1) + (tempArray[1] >> 7);
    passwordArray[2] = (tempArray[1] & 124) >> 2;
    passwordArray[1] = ((tempArray[1] & 3) << 3) + (tempArray[0] >> 5);
    passwordArray[0] = tempArray[0] & 31;

    string password;
	for(int i=0; i<8; i++)
    {
        password += "0123456789BCDFGHJKLMNPQRSTVWXYZ&"[passwordArray[i]];
    }

    cout << endl;
    cout << "Generated password: " << password << endl;
    return (0);
}

