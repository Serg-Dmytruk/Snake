#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Windows.h>

using namespace sf;

class Food
{
public:
	Sprite EatMe;
	virtual Sprite GetFood() = 0;
	virtual void RemoveFood(float x, float y) = 0;
};

class Apple : public Food
{
protected:
	Sprite EatMe;
	int Score;
public:
	Apple() {Score = 1;}
	Apple(Sprite NewSprite)
	{
		Score = 1;
		EatMe = NewSprite;
		EatMe.setPosition(0, 0);
	}
	void RemoveFood(float x, float y) override
	{
		EatMe.setPosition(x, y);
	}
	Sprite GetFood() override
	{
		return EatMe;
	}
};

class Snake
{
protected:
	std::vector<Sprite> SnakeBody;
	Sprite TailSprite; //хвіст
	Sprite BodySprite; // тіло
	Sprite HeadSprite; // голова
	int SnakeSize;
	float WhereIam[100][2];

public:
	Snake(Texture& NewTexture)
	{
		TailSprite.setTexture(NewTexture);
		TailSprite.setTextureRect(IntRect(262, 199, 55, 50));

		BodySprite.setTexture(NewTexture);
		BodySprite.setTextureRect(IntRect(135, 71, 55, 50));

		HeadSprite.setTexture(NewTexture);
		HeadSprite.setTextureRect(IntRect(256, 65, 55, 50));

		SnakeSize = 5;

		WhereIam[0][0] = 380;
		WhereIam[0][1] = 240;

		for (int i = 1; i < SnakeSize; i++)
		{
			WhereIam[i][0] = WhereIam[0][0];
			WhereIam[i][1] = WhereIam[0][1] - (i * 45);
		}

		SnakeBody.push_back(HeadSprite);
		SnakeBody.at(0).setPosition(WhereIam[0][0], WhereIam[0][1]);
		
		for (int i = 1; i < SnakeSize; i++)
		{
			if (SnakeSize - 1 == i)
			{
				SnakeBody.push_back(TailSprite);
				SnakeBody.at(i).setPosition(WhereIam[i][0], WhereIam[i][1]);
			}
			
			SnakeBody.push_back(BodySprite);
			SnakeBody.at(i).setPosition(WhereIam[i][0], WhereIam[i][1]);
		}

	}
	void IamGrow()
	{
		SnakeBody.push_back(BodySprite);
		SnakeSize++;
	}
	Sprite SnakeGetBody(int i)
	{
		return SnakeBody.at(i);
	}
	int GetSnakeSize()
	{
		return SnakeSize;
	}
	void Moving(float x, float y, char Direcrion , char PrevDirection)
	{
		if (Direcrion == 'R')
		{			
			SnakeBody.at(0).move(x, y);
			WhereIam[0][0] += x;
			
			for (int i = 1; i < SnakeSize; i++)
			{
				if (WhereIam[i - 1][0] - WhereIam[i][0] >= 50)
				{
					for (int j = SnakeSize - 1; j > 0; j--)
						WhereIam[j][1] = WhereIam[j - 1][1];
					
					

					SnakeBody.at(i).move(x, y);
					WhereIam[i][0] += x;
					
				}

				Sleep(1);
			}
		}
		if (Direcrion == 'L')
		{
			SnakeBody.at(0).move(x, y);
			WhereIam[0][0] -= x;
			for (int i = 1; i < SnakeSize; i++)
			{
				if (WhereIam[i - 1][0] - WhereIam[i][0] >= 50)
				{
					SnakeBody.at(i).move(x, y);
					WhereIam[i][0] -= x;
				}
				
				Sleep(1);
			}
		}
		if (Direcrion == 'U')
		{
			SnakeBody.at(0).move(x, y);
			WhereIam[0][1] -= y;

			for (int i = 1; i < SnakeSize; i++)
			{
				if (WhereIam[i][1] - WhereIam[i - 1][1] <= 55)
				{
					SnakeBody.at(i).move(x, y);
					WhereIam[i][1] -= y;
				}
				
				Sleep(1);
			}
		}
		if (Direcrion == 'D')
		{
			SnakeBody.at(0).move(x, y);
			WhereIam[0][1] += y;
			for (int i = 1; i < SnakeSize; i++)
			{
				if (WhereIam[i - 1][1] - WhereIam[i][1] >= 55)
				{
					SnakeBody.at(i).move(x, y);
					WhereIam[i][1] += y;
				}
				Sleep(1);
			}
		}	
	}
};