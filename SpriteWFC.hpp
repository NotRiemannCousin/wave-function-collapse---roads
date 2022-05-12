#include "grid.hpp"

class SpriteWFC
{
  private:
	string filename = "./src/Roads.png";
	vector<int> Right, Up, Down, Left;
	Sprite sprite;
	Grid *grid;

  public:
	static Texture texture;
	enum State
	{
		Null,	   // 0	
		
		Path_V, 	// 1	║
		
		Path_H,	 // 2	═
		
		Curve_U_R,  // 3	╚
		
		Curve_U_L,  // 4	╝
		
		Curve_D_R,  // 5	╔
		
		Curve_D_L,  // 6	╗
		
		ConvexPath, // 7	╬
		
		T_U,		// 8	╩
		
		T_D,		// 9	╦
		
		T_R,		//10	╠
		
		T_L,		//11	╣
		
		I_U,		//12	↑
		
		I_D,		//13	↓
		
		I_R,		//14	→
		
		I_L		 //15	←
		
	};

	SpriteWFC(Grid &g, int state, Texture &t)
	{
		switch (state)
		{
		case SpriteWFC::Null: //	0
			Up = vector<int>{0, 2, 3, 4, 8, 12, 14, 15};
			Down = vector<int>{0, 2, 5, 6, 9, 13, 14, 15};
			Right = vector<int>{0, 1, 3, 5, 10, 12, 13, 14};
			Left = vector<int>{0, 1, 4, 6, 11, 12, 13, 15};

			setRect(Vector2i(128, 128), Vector2i(64, 64));
			break;
		case SpriteWFC::Path_V: //	1
			Up = vector<int>{1, 5, 6, 7, 9, 10, 11, 13};
			Down = vector<int>{1, 3, 4, 7, 8, 10, 11, 12};
			Right = vector<int>{0, 1, 3, 5, 10, 12, 13, 14};
			Left = vector<int>{0, 1, 4, 6, 11, 12, 13, 15};

			setRect(Vector2i(192, 0), Vector2i(64, 64));
			break;
		case SpriteWFC::Path_H: //	2
			Up = vector<int>{0, 2, 3, 4, 8, 12, 14, 15};
			Down = vector<int>{0, 2, 5, 6, 9, 13, 14, 15};
			Right = vector<int>{2, 4, 6, 7, 8, 9, 11, 15};
			Left = vector<int>{2, 3, 5, 7, 8, 9, 10, 14};

			setRect(Vector2i(128, 0), Vector2i(64, 64));
			break;
		case SpriteWFC::Curve_U_R: //	3
			Up = vector<int>{1, 5, 6, 7, 9, 10, 11, 13};
			Down = vector<int>{0, 2, 5, 6, 9, 13, 14, 15};
			Right = vector<int>{2, 4, 6, 7, 8, 9, 11, 15};
			Left = vector<int>{0, 1, 4, 6, 11, 12, 13, 15};

			setRect(Vector2i(192, 64), Vector2i(64, 64));
			break;
		case SpriteWFC::Curve_U_L: //	4
			Up = vector<int>{1, 5, 6, 7, 9, 10, 11, 13};
			Down = vector<int>{0, 2, 5, 6, 9, 13, 14, 15};
			Right = vector<int>{0, 1, 3, 5, 10, 12, 13, 14};
			Left = vector<int>{2, 3, 5, 7, 8, 9, 10, 14};

			setRect(Vector2i(128, 64), Vector2i(64, 64));
			break;
		case SpriteWFC::Curve_D_R: //	5
			Up = vector<int>{0, 2, 3, 4, 8, 12, 14, 15};
			Down = vector<int>{1, 3, 4, 7, 8, 10, 11, 12};
			Right = vector<int>{2, 4, 6, 7, 8, 9, 11, 15};
			Left = vector<int>{0, 1, 4, 6, 11, 12, 13, 15};

			setRect(Vector2i(0, 64), Vector2i(64, 64));
			break;
		case SpriteWFC::Curve_D_L: //	6
			Up = vector<int>{0, 2, 3, 4, 8, 12, 14, 15};
			Down = vector<int>{1, 3, 4, 7, 8, 10, 11, 12};
			Right = vector<int>{0, 1, 3, 5, 10, 12, 13, 14};
			Left = vector<int>{2, 3, 5, 7, 8, 9, 10, 14};

			setRect(Vector2i(64, 64), Vector2i(64, 64));
			break;
		case SpriteWFC::ConvexPath: //	7
			Up = vector<int>{1, 5, 6, 7, 9, 10, 11, 13};
			Down = vector<int>{1, 3, 4, 7, 8, 10, 11, 12};
			Right = vector<int>{2, 4, 6, 7, 8, 9, 11, 15};
			Left = vector<int>{2, 3, 5, 7, 8, 9, 10, 14};

			setRect(Vector2i(0, 128), Vector2i(64, 64));
			break;
		case SpriteWFC::T_U: //	8
			Up = vector<int>{1, 5, 6, 7, 9, 10, 11, 13};
			Down = vector<int>{0, 2, 5, 6, 9, 13, 14, 15};
			Right = vector<int>{2, 4, 6, 7, 8, 9, 11, 15};
			Left = vector<int>{2, 3, 5, 7, 8, 9, 10, 14};

			setRect(Vector2i(256, 64), Vector2i(64, 64));
			break;
		case SpriteWFC::T_D: //	9
			Up = vector<int>{0, 2, 3, 4, 8, 12, 14, 15};
			Down = vector<int>{1, 3, 4, 7, 8, 10, 11, 12};
			Right = vector<int>{2, 4, 6, 7, 8, 9, 11, 15};
			Left = vector<int>{2, 3, 5, 7, 8, 9, 10, 14};

			setRect(Vector2i(320, 64), Vector2i(64, 64));
			break;
		case SpriteWFC::T_R: //	10
			Up = vector<int>{1, 5, 6, 7, 9, 10, 11, 13};
			Down = vector<int>{1, 3, 4, 7, 8, 10, 11, 12};
			Right = vector<int>{2, 4, 6, 7, 8, 9, 11, 15};
			Left = vector<int>{0, 1, 4, 6, 11, 12, 13, 15};

			setRect(Vector2i(448, 64), Vector2i(64, 64));
			break;
		case SpriteWFC::T_L: //	11
			Up = vector<int>{1, 5, 6, 7, 9, 10, 11, 13};
			Down = vector<int>{1, 3, 4, 7, 8, 10, 11, 12};
			Right = vector<int>{0, 1, 3, 5, 10, 12, 13, 14};
			Left = vector<int>{2, 3, 5, 7, 8, 9, 10, 14};

			setRect(Vector2i(384, 64), Vector2i(64, 64));
			break;
		case SpriteWFC::I_U: //	12
			Up = vector<int>{1, 5, 6, 7, 9, 10, 11};
			Down = vector<int>{0, 2, 5, 6, 9};
			Right = vector<int>{0, 1, 3, 5, 10};
			Left = vector<int>{0, 1, 4, 6, 11};

			setRect(Vector2i(256, 0), Vector2i(64, 64));
			break;
		case SpriteWFC::I_D: //	13
			Up = vector<int>{0, 2, 3, 4, 8};
			Down = vector<int>{1, 3, 4, 7, 8, 10, 11};
			Right = vector<int>{0, 1, 3, 5, 10};
			Left = vector<int>{0, 1, 4, 6, 11};
			
			setRect(Vector2i(320, 0), Vector2i(64, 64));
			break;
		case SpriteWFC::I_R: //	14
			Up = vector<int>{0, 2, 3, 4, 8};
			Down = vector<int>{0, 2, 5, 6, 9};
			Right = vector<int>{2, 4, 6, 7, 8, 9, 11};
			Left = vector<int>{0, 1, 4, 6, 11};
			
			setRect(Vector2i(448, 0), Vector2i(64, 64));
			break;
		case SpriteWFC::I_L: //	15
			Up = vector<int>{0, 2, 3, 4, 8};
			Down = vector<int>{0, 2, 5, 6, 9};
			Right = vector<int>{0, 1, 3, 5, 10};
			Left = vector<int>{2, 3, 5, 7, 8, 9, 10};
			
			setRect(Vector2i(384, 0), Vector2i(64, 64));
			break;
		}
		sprite.setTexture(t);
		setPosition(g);
	};

	SpriteWFC() {}
	void setRect(Vector2i pos, Vector2i size)
	{
		sprite.setTextureRect(Rect<int>(pos, size));
		sprite.setOrigin(size.x / 2, size.y / 2);
	};

	vector<int> getRight() { return Right; };
	vector<int> getLeft() { return Left; };
	vector<int> getUp() { return Up; };
	vector<int> getDown() { return Down; };
	Sprite getSprite() { return sprite; };

	void setPosition(Grid &g)
	{
		sprite.setPosition(g.getPos());
		grid = &g;
		grid->setTarget();
	};
	inline void setPosition(Vector2f pos) { sprite.setPosition(pos); }
	inline Grid *getGrid() { return grid; }
	inline Texture getTexture() { return *sprite.getTexture(); }
	constexpr void setTexture(Texture &tex) { sprite.setTexture(tex); }
};