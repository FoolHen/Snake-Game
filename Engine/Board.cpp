#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{

}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim( borderWidth + loc.x * dimension, borderWidth + loc.y * dimension, dimension, dimension, c);
}

void Board::DrawCellCircular(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawCircle( borderWidth + loc.x * dimension, borderWidth + loc.y * dimension, dimension/2, c);
}

void Board::DrawBorder()
{
	const int left = borderWidth * 2 + dimension*width;
	const int bottom = borderWidth * 2 + dimension*height;
	gfx.DrawRectDim(0, 0, left, borderWidth, borderColor); // top
	gfx.DrawRectDim(0, borderWidth, borderWidth, 
		bottom - borderWidth, borderColor); // left
	gfx.DrawRectDim(left-borderWidth, borderWidth, borderWidth, 
		bottom - borderWidth, borderColor); // left
	gfx.DrawRectDim(0, bottom - borderWidth, left, borderWidth, borderColor); // top
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

bool Board::Collision(const Location& loc) const
{
	return !(loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height);
}
