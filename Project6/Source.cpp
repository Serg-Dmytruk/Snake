#include "Header.h"

int main()
{
	RenderWindow window(sf::VideoMode(1024, 768), "MY FIRST GAME");
	Texture SnakeTexture;
	SnakeTexture.loadFromFile("Snake.png");

	
	Sprite F; //їжа

	F.setTexture(SnakeTexture);
	F.setTextureRect(IntRect(0, 194, 63, 62));


	char SnakeMovmetDirection = 'D';
	char SnakePrevDirection = SnakeMovmetDirection;
	Snake LitleSnake(SnakeTexture);
	Apple IamFood(F);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		switch (SnakeMovmetDirection)
		{
		case 'R':
			for (int i = 0; i < LitleSnake.GetSnakeSize(); i++)
				LitleSnake.Moving(0.1, 0, SnakeMovmetDirection, SnakePrevDirection);
			break;
		case 'L':
			for (int i = 0; i < LitleSnake.GetSnakeSize(); i++)
				LitleSnake.Moving(-0.1, 0, SnakeMovmetDirection, SnakePrevDirection);
			break;
		case 'U':
			for (int i = 0; i < LitleSnake.GetSnakeSize(); i++)
				LitleSnake.Moving(0, -0.1, SnakeMovmetDirection, SnakePrevDirection);
			break;
		case 'D':
			for (int i = 0; i < LitleSnake.GetSnakeSize(); i++)
				LitleSnake.Moving(0, 0.1, SnakeMovmetDirection, SnakePrevDirection);
			break;
		}

		SnakePrevDirection = SnakeMovmetDirection;
		if (Keyboard::isKeyPressed(Keyboard::Left)) { SnakeMovmetDirection = 'L'; }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { SnakeMovmetDirection = 'R'; }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { SnakeMovmetDirection = 'U'; }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { SnakeMovmetDirection = 'D'; }

		window.clear();
		for (int i = 0; i < LitleSnake.GetSnakeSize(); i++)
		{
			window.draw(LitleSnake.SnakeGetBody(i));
		}
		window.draw(IamFood.GetFood());
		
		window.display();
	}
	return 0;
}