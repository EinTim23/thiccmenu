/*
*                                 __
*   __ _  ___  ___  ___ _________/ /
*  /  ' \/ _ \/ _ \/ _ `/ __/ __/ _ \
* /_/_/_/\___/_//_/\_,_/_/  \__/_//_/
*
* THICC menu - simple keyboard controllable input lib
* Licensed under the GPL License (see LICENSE)
* Author(s):  Da Mivolis#1337	| mailto:apl@monarchcheats.com
*/
#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
enum Colors : int {
	Black = 0,
	Darkblue = 0x0001,
	Darkgreen = 0x0002,
	Darkcyan = 0x0002 | 0x0001,
	Darkred = 0x0004,
	Darkmagenta = 0x0004 | 0x0001,
	Darkyellow = 0x0004 | 0x0002,
	Darkgray = 0x0004 | 0x0002 | 0x0001,
	Gray = 0x0008,
	Blue = 0x0008 | 0x0001,
	Green = 0x0008 | 0x0002,
	Cyan = 0x0008 | 0x0002 | 0x0001,
	Red = 0x0008 | 0x0004,
	Magenta = 0x0008 | 0x0004 | 0x0001,
	Yellow = 0x0008 | 0x0004 | 0x0002,
	White = 0x0008 | 0x0004 | 0x0002 | 0x0001,
};
namespace thiccmenu {
    inline void setcolor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
    inline COORD getcoord(HANDLE hConsoleOutput)
    {
        CONSOLE_SCREEN_BUFFER_INFO cbsi;
        GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi);
        return cbsi.dwCursorPosition;
    }
    inline void setcoord(int x, int y)
    {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
    inline int Menu(std::vector<std::string> options, int defaultcolor, int selectedcolor, int xoffset, int yoffset, int counter = 0) {
        std::vector<int> Set;
        for (int i = 0; i < options.size(); i++) {
            if(i == counter)
                Set.push_back(selectedcolor);
            else
                Set.push_back(defaultcolor);
        }
        char key;
        while(true)
        {
            for (int j = 0; j < options.size(); j++) {
                setcoord(xoffset, yoffset + j);
                setcolor(Set.at(j));
                std::cout << options[j] << "\n";
            }
            key = _getch();

            if (key == 72 && (counter > 0 && counter <= options.size()))
                counter--;
            if (key == 80 && (counter >= 0 && counter < options.size() - 1))
                counter++;
            if (key == '\r')
            {
                return counter + 1; 
                break;
            }

            for (int i = 0; i < options.size(); i++)
                Set.at(i) = defaultcolor;
            Set.at(counter) = selectedcolor;
        }
    }
    inline int Menu(std::vector<std::string> options, int defaultcolor, int selectedcolor, int counter = 0) {
        COORD c = getcoord(GetStdHandle(STD_OUTPUT_HANDLE));
        return Menu(options, defaultcolor, selectedcolor, c.X, c.Y, counter);
    }
}
