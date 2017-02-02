#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell( const Location& location, Color color);
	void DrawCellCircular( const Location& location, Color color);
	void DrawBorder();
	int GetWidth() const;
	int GetHeight() const;
	bool Collision( const Location& loc) const;

private:
	static constexpr Color borderColor = Colors::LightGray;
	static constexpr int dimension = 10;
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int borderWidth = 10;
	Graphics& gfx;
};