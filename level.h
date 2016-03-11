#pragma once

/////////////////////////////////////////////
//Include
#include <SFML/Graphics.hpp>

/////////////////////////////////////////////
//Extern
extern sf::Texture* g_atlas00;

/////////////////////////////////////////////
//Level data
const int kScreenRows = 40;
const int kScreenColumns = 80;
const int level = 3;
const int kPixelsPerCell = 15;

const unsigned char CellSymbol_Wall =	 '@';
const unsigned char CellSymbol_Block =	 'X';
const unsigned char CellSymbol_Ball =	 'o';
const unsigned char CellSymbol_Player =  'P';
const unsigned char CellSymbol_Abyss =	 '&';
const unsigned char CellSymbol_Ceiling = '#';
const unsigned char CellSymbol_Health =	 '$';

const unsigned char kLevelData0[level][kScreenRows][kScreenColumns + 1] =
{
	{
		"################################################################################",
		"@                                                                              @",
		"@                                                                              @",
		"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
		"@                                                                              @",
		"@                 X         X         X         X         X                    @",
		"@                                                                              @",
		"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
		"@                                                                              @",
		"@                 X         X         X         X         X                    @",
		"@                                                                              @",
		"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
		"@                                                                              @",
		"@                 X         X         X         X         X                    @",
		"@                                                                              @",
		"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
		"@                                                                              @",
		"@                 X         X         X         X         X                    @",
		"@                                                                              @",
		"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
		"@                                                                              @",
		"@                 X         X         X         X         X                    @",
		"@                                                                              @",
		"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                      o                                       @",
		"@                                    P                                         @",
		"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
	},

	{
		"################################################################################",
		"@                                                                              @",
		"@                                                                              @",
		"@            X    X         X    X         X    X         X    X               @",
		"@                                                                              @",
		"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
		"@                                                                              @",
		"@            X              X    X         X    X              X               @",
		"@                                                                              @",
		"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
		"@                                                                              @",
		"@            X    X         X                   X         X    X               @",
		"@                                                                              @",
		"@       X    X    X    X    X    X         X    X    X    X    X    X          @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X         X    X         X         X    X         X               @",
		"@                                                                              @",
		"@       X    X    X    X              X              X    X    X    X          @",
		"@                                                                              @",
		"@            X    X                   X                   X    X               @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                      o                                       @",
		"@                                    P                                         @",
		"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
	},
	{
		"################################################################################",
		"@                                                                              @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@            X    X    X    X    X    X    X    X    X    X    X               @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                                                              @",
		"@                                      o                                       @",
		"@                                    P                                         @",
		"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
	}
};

//Wall
const sf::IntRect kWallImage = sf::IntRect(0, 3 * kPixelsPerCell, kPixelsPerCell, kPixelsPerCell);

//Ceiling
const sf::IntRect kCeilingImage = sf::IntRect(0, 3 * kPixelsPerCell, kPixelsPerCell, kPixelsPerCell);

//Abyss
const sf::IntRect kAbyssImage = sf::IntRect(0, 8 * kPixelsPerCell, kPixelsPerCell, kPixelsPerCell);

//Block
const int kBlockWidth = 4 * kPixelsPerCell;
const sf::IntRect kBlockImage = sf::IntRect(0, kPixelsPerCell, kBlockWidth * kPixelsPerCell, kPixelsPerCell);

//Player data
const int kPlayerHealt = 1;
const int kPlayerSpeed = 30 * kPixelsPerCell;
const int kPlayerWidth = 5 * kPixelsPerCell;
const sf::IntRect kPlayerImage = sf::IntRect(0, 0, kPlayerWidth*kPixelsPerCell, kPixelsPerCell);

//Ball data
const int kBallSpeed = 17* kPixelsPerCell;
const sf::IntRect kBallImage = sf::IntRect(0, 2 * kPixelsPerCell, kPixelsPerCell, kPixelsPerCell);

//Health data
const int kHealt = 4;
const int kHealthwidth = 3;
const sf::IntRect kHealthImage = sf::IntRect(0, 4 * kPixelsPerCell, kHealthwidth * kPixelsPerCell, kPixelsPerCell);























/*
const unsigned char kLevelData0[level][kScreenRows][kScreenColumns + 1] =
{
{
"$                                                                               ",
"################################################################################",
"@                                                                              @",
"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
"@                                                                              @",
"@                 X         X         X         X         X                    @",
"@                                                                              @",
"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
"@                                                                              @",
"@                 X         X         X         X         X                    @",
"@                                                                              @",
"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
"@                                                                              @",
"@                 X         X         X         X         X                    @",
"@                                                                              @",
"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
"@                                                                              @",
"@                 X         X         X         X         X                    @",
"@                                                                              @",
"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
"@                                                                              @",
"@                 X         X         X         X         X                    @",
"@                                                                              @",
"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                      o                                       @",
"@                                    P                                         @",
"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
},

{
"                                                                                ",
"################################################################################",
"@                                                                              @",
"@            X    X         X    X         X    X         X    X               @",
"@                                                                              @",
"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
"@                                                                              @",
"@            X              X    X         X    X              X               @",
"@                                                                              @",
"@       X    X    X    X    X    X    X    X    X    X    X    X    X          @",
"@                                                                              @",
"@            X    X         X                   X         X    X               @",
"@                                                                              @",
"@       X    X    X    X    X    X         X    X    X    X    X    X          @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X         X    X         X         X    X         X               @",
"@                                                                              @",
"@       X    X    X    X              X              X    X    X    X          @",
"@                                                                              @",
"@            X    X                   X                   X    X               @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                      o                                       @",
"@                                    P                                         @",
"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
},
{
"################################################################################",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@            X    X    X    X    X    X    X    X    X    X    X               @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                      o                                       @",
"@                                    P                                         @",
"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
}
};
*/


/*
{
{
"$                                                                               ",
"################################################################################",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                     X                                        @",
"@                                                                              @",
"@                                     X                                        @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                      o                                       @",
"@                                    P                                         @",
"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
},

{
"$                                                                               ",
"################################################################################",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                     X                                        @",
"@                                                                              @",
"@                                     X                                        @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                      o                                       @",
"@                                    P                                         @",
"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
},
{
"$                                                                               ",
"################################################################################",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                     X                                        @",
"@                                                                              @",
"@                                     X                                        @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                                                              @",
"@                                      o                                       @",
"@                                    P                                         @",
"@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@",
}
};
*/