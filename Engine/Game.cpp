/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	board( gfx),
	rng( std::random_device()() ),
	snake({ 2,2 }),
	apple( rng, board, snake )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() //Model - Game Logic
{
	if (!gameOver) 
	{
		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			newDirection = { 0,-1 }; 
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			newDirection = { 0,1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			newDirection = { 1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			newDirection = { -1,0 };
		}
		++moveCounter;


		if (moveCounter >= movePeriod) 
		{
			moveCounter = 0;
			if ( !( direction.x == - newDirection.x && direction.y == -newDirection.y) )
			{
				direction = newDirection;
			}

			const Location nextPosition = snake.GetNextHeadLocation(direction);

			if ( board.Collision( nextPosition ) ||
				snake.IsInLocation( nextPosition , 1) ) 
			{
				gameOver = true;
			}
			else
			{
				
				if ( nextPosition == apple.GetLocation() )
				{
					snake.Grow();
					snake.Move(direction);

					apple.Respawn( rng, board, snake );
					
				}
				else snake.Move(direction);
				
			}
		
			
		}
	}

}

void Game::ComposeFrame()//View
{
	snake.Draw(board);
	apple.Draw(board);
	if (gameOver) 
	{
		SpriteCodex::DrawGameOver(100, 100, gfx);
	}
	board.DrawBorder();
}
