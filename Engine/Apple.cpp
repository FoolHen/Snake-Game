#include "Apple.h"

Apple::Apple(std::mt19937 & rng, const Board & board, const Snake & snake)
{
	Respawn(rng, board, snake);
}

void Apple::Respawn(std::mt19937 & rng, const Board & board, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(0, board.GetWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, board.GetHeight() - 1);
	
	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while ( snake.IsInLocation( newLoc,0) ); // 0 because we also want to check the tail
	
	loc = newLoc;
}

void Apple::Draw(Board & board) const
{
	board.DrawCellCircular(loc, c);
}

const Location& Apple::GetLocation() const
{
	return loc;
}
