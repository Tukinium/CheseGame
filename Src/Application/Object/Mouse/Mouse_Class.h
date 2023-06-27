#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class MouseCursor_Class : public BaseObject_Class
{
public:
	void Init()override;
	void DrawSprite()override;
	void GetPos(float _posX,float _posY,bool _IsMaineMenu)
	{
		fixMousePos.x = _posX;
		if (_IsMaineMenu)
		{
			fixMousePos.y = _posY * -1 + 720/2;
		}
		else
		{
			fixMousePos.y = _posY * -1 +50;
		}
	}
private:
	
	Math::Vector2 fixMousePos;
};
