#pragma once
#include"Application/UI/UIBaseObject.h"
class OnTurnStartViewUI_Class : public UIBaseObject_Class
{
public:
	void Init()override;
	void Entry();
	void Leave();
	void SetRoundNum(int _n)
	{
		m_nowRound = _n;
	}
	void DrawSprite()override;
	int StrToNum(std::string str, int n)
	{
		switch (n)
		{
		case 1:
		{
			return str[0];
			break;
		}
		case 2:
		{

			break;
		}
		default:
			break;
		}
	}
private:
	KdTexture m_thRoundTxtTex;
	int m_nowRound;
};