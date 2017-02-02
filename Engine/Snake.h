#pragma once

#include "Board.h"

class Snake
{
public:
private:
	class Segment 
	{
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& next_seg);
		void Move(const Location& direction);
		void Draw(Board& board) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color color;
	};
public:
	Snake(const Location& loc);
	void Move(const Location& next_loc);
	Location GetNextHeadLocation(const Location& direction);
	void Grow();
	void Draw( Board& board) const;
	bool IsInLocation(const Location& position, bool checkEnd) const;
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nMaxSegments = 1000;
	Segment segments[nMaxSegments];
	int nSegments = 1;
};