#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using std::vector, std::set_intersection, std::string;

class Grid : public Vector2i
{
	bool is_setted = false;
	int r = 32;

	vector<int> all_statesT{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, all_statesP = all_statesT;

	Vector2i index;
	CircleShape circle;
	Color color = Color(15, 180, 230);

  public:
	Grid(int x, int y) : Vector2i(x, y), circle(r)
	{
		index = Vector2i(x / 64 + 8, abs(y / 64 - 8));
		circle.setPosition(x, y);
		circle.setOrigin(r, r);
		circle.setFillColor(Color(130, 130, 130));
		circle.setFillColor(color);
	}

	void setTarget()
	{
		is_setted = true;
		all_statesP.clear();
		circle.setRadius(0);
	}

	void update(vector<int> x)
	{
		if (is_setted)
			return;
		vector<int> v3;	
		set_intersection(x.begin(), x.end(), all_statesP.begin(), all_statesP.end(), back_inserter(v3));
		all_statesP = v3;
		circle.setRadius(r * all_statesP.size() / all_statesT.size());
		float radius = circle.getRadius();
		circle.setOrigin(radius, radius);
		circle.setFillColor(Color(color.r / (r/radius), color.g / (r/radius), color.b / (r/radius)));
	}
	Vector2f getPos() { return Vector2f(x, y); }
	CircleShape draw() { return circle; }
	bool getSet() { return is_setted; }
	Vector2i getIndex() { return index;}
	vector<int> getPossibleStates() { return all_statesP; }
};