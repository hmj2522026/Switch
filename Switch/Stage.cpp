#include "Stage.h"
#include "Screen.h"
#include "Block.h"
#include "Floor.h"
#include "FloorInitOn.h"
#include "FloorInitOff.h"
#include "Button.h"
#include "Goal.h"

Stage::Stage() :
	m_button(nullptr)
{
	this->AddChild(new Block(Screen::BottomCenter + Vector2(0, -30), Tag::BlockBreakable));
	this->AddChild(new Block(Screen::BottomCenter + Vector2(0, -60), Tag::BlockBreakable));
	this->AddChild(new Block(Screen::BottomCenter + Vector2(0, -90), Tag::BlockBreakable));


	this->AddChild(new Block(Screen::BottomRight + Vector2(-165, -30)));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-167, -60),Tag::BlockBreakable));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-135, -30)));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-135, -60)));

	this->AddChild(new Block(Screen::BottomRight + Vector2(-105, -60)));

	this->AddChild(new Block(Screen::BottomRight + Vector2(-105, -90)));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-107, -120),Tag::BlockBreakable));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-75, -90)));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-75, -120)));

	this->AddChild(new Block(Screen::BottomRight + Vector2(-45, -120)));

	this->AddChild(new Block(Screen::BottomRight + Vector2(-45, -150)));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-47, -180),Tag::BlockBreakable));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-15, -150)));
	this->AddChild(new Block(Screen::BottomRight + Vector2(-15, -180)));


	this->AddChild(new Floor(Screen::BottomRight + Vector2(-45, -235)));
	this->AddChild(new Floor(Screen::BottomRight + Vector2(-90, -280)));
	this->AddChild(new Floor(Screen::BottomRight + Vector2(-135, -325)));
	this->AddChild(new Floor(Screen::BottomRight + Vector2(-45, -370)));
	this->AddChild(new Floor(Screen::BottomRight + Vector2(-45, -415)));

	m_button = new Button(Screen::BottomRight + Vector2(-15, -435));
	this->AddChild(m_button);

	this->AddChild(new FloorInitOff(Screen::Center + Vector2(45,0), m_button));
	this->AddChild(new FloorInitOn(Screen::Center + Vector2(-45,0), m_button));
	this->AddChild(new FloorInitOff(Screen::Center + Vector2(-135,0), m_button));
	this->AddChild(new FloorInitOn(Screen::Center + Vector2(-225,0), m_button));

	this->AddChild(new Floor(Screen::Center + Vector2(-270, -40)));

	this->AddChild(new FloorInitOn(Screen::TopCenter + Vector2(-175,220), m_button));
	this->AddChild(new FloorInitOff(Screen::TopCenter + Vector2(-85,180), m_button));


	this->AddChild(new Floor(Screen::BottomLeft + Vector2(100, -55)));


	this->AddChild(new Goal(Screen::TopCenter + Vector2(0, 110)));
	this->AddChild(new Floor(Screen::TopCenter + Vector2(0, 145)));
}
