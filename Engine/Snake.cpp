#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
	
}

void Snake::Move(const Location& direction)
{
	for (int i = nSegments - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].Move(direction);
}

void Snake::Grow()
{
	if (nSegments < nMaxSegments) {
		segments[nSegments].InitBody();
		++nSegments;
	}
}

void Snake::Draw(Board& board) const
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].Draw(board);
	}
}

bool Snake::IsInLocation(const Location& position, bool checkEnd) const
{
	for (int i = 0; i < nSegments - (int) checkEnd; i++) 
	{
		if ( segments[i].GetLocation() == position)
		{
			return true;
		}
	}
	return false;
}

const Location& Snake::Segment::GetLocation() const 
{
	return loc;
}

Location Snake::GetNextHeadLocation(const Location & direction)
{
	Location l(segments[0].GetLocation());
	l.Add(direction);
	return l;
}

void Snake::Segment::InitHead(const Location& loc)
{
	this->loc = loc;
	color = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	color = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment& next_seg)
{
	loc = next_seg.loc;
}

void Snake::Segment::Move(const Location& direction)
{
	assert(abs(direction.x) + abs(direction.y) == 1);
	loc.Add(direction);
}



void Snake::Segment::Draw(Board& board) const
{
	board.DrawCell(loc, color);
}

