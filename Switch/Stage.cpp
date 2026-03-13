#include "Stage.h"
#include "Screen.h"
#include "Block.h"
#include "Goal.h"

Stage::Stage()
{
	this->AddChild(new Block(Screen::BottomLeft + Vector2(200, -30)));
	this->AddChild(new Block(Screen::BottomLeft + Vector2(200, -60),Tag::BlockBreakable));
	this->AddChild(new Block(Screen::BottomLeft + Vector2(230, -30)));
	this->AddChild(new Block(Screen::BottomLeft + Vector2(230, -60)));
	this->AddChild(new Goal(Screen::TopRight + Vector2(-100, 100)));
}
