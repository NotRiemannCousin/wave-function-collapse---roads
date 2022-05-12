#include "SpriteWFC.hpp"
#include <random>
#include <time.h>

#define SIZE_GRID 16

using namespace sf;
using std::vector;
/////////////////////////////////////////////
//////////// Variaveis globais //////////////
/////////////////////////////////////////////

View view;
vector<vector<Grid>> grid;
vector<SpriteWFC> Sp;
Text txt;
std::vector<Grid *> genStack;

/////////////////////////////////////////////
///////// Wave Function Collapse ////////////
/////////////////////////////////////////////

void wave(Texture &texture)
{
	for (auto &sp : Sp)
	{
		if (sp.getGrid()->getSet() == true)
		{
			auto [x, y] = sp.getGrid()->getIndex();

			if ((x > 0) && (!grid[x - 1][y].getSet()))
			{
				grid[x - 1][y].update(sp.getLeft());
				genStack.push_back(&grid[x - 1][y]);
			}
			if ((y > 0) && (!grid[x][y - 1].getSet()))
			{
				grid[x][y - 1].update(sp.getDown());
				genStack.push_back(&grid[x][y - 1]);
			}
			if ((x < 15) && (!grid[x + 1][y].getSet()))
			{
				grid[x + 1][y].update(sp.getRight());
				genStack.push_back(&grid[x + 1][y]);
			}
			if ((y < 15) && (!grid[x][y + 1].getSet()))
			{
				grid[x][y + 1].update(sp.getUp());
				genStack.push_back(&grid[x][y + 1]);
			}
		}
	}
	if (!genStack.empty())
	{
		Grid *select = genStack.front();

		for (auto i : genStack)
			select = (select->getPossibleStates().size() > i->getPossibleStates().size() ? i : select);

		vector<int> vec = select->getPossibleStates();

		int state = vec.at(rand() % vec.size());

		Sp.emplace_back(*select, state, texture);

		genStack.clear();

		auto [x, y] = select->getIndex();

		if ((x > 0) && (!grid[x - 1][y].getSet()))
			grid[x - 1][y].update(Sp.back().getLeft());
		if ((y > 0) && (!grid[x][y - 1].getSet()))
			grid[x][y - 1].update(Sp.back().getDown());
		if ((x < 15) && (!grid[x + 1][y].getSet()))
			grid[x + 1][y].update(Sp.back().getRight());
		if ((y < 15) && (!grid[x][y + 1].getSet()))
			grid[x][y + 1].update(Sp.back().getUp());
	}
}

/////////////////////////////////////////////
/////////////////// Main ////////////////////
/////////////////////////////////////////////

int main()
{
	for (short i = 0; i < SIZE_GRID; i++)
	{
		grid.emplace_back();
		for (short j = 0; j < SIZE_GRID; j++)
			grid.back().emplace_back(64 * i - 512, -64 * j + 512);
	}

	Texture texture;

	texture.loadFromFile("/images/Roads.png");

	srand(time(0));

	int tile = rand() % (sizeof(SpriteWFC::State) / sizeof(SpriteWFC::ConvexPath));
	Sp.emplace_back(grid[0][0], tile, texture);
	//to PC
	RenderWindow window(VideoMode(1024, 1024), "sfml Wave Function Collapse", Style::Close);
	//to mobile devices
	//RenderWindow window(VideoMode::getDesktopMode(), "sfml Wave Function Collapse");
	
	View view = window.getView();
	view.setCenter(-32, -32);
	window.setView(view);
	
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::TouchBegan:
				break;
			case Event::TouchMoved:
				break;
			case Event::TouchEnded:
				break;
			}
		}

		window.clear();
		for (auto &i : grid)
			for (auto &j : i)
				window.draw(j.draw());

		for (auto &spt : Sp)
			window.draw(spt.getSprite());

		window.display();
		
		if (Sp.size() < 16 * 16)
			wave(texture);
	}
}
