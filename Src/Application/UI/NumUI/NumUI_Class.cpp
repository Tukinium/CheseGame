#include"NumUI_Class.h"

void NumUI_Class::Init()
{
	for (int n = 0; n < 10; n++)
	{
		std::string strBase = "Asset/Textures/UI/Num/";
		std::string str = ".png";
		std::string strN = std::to_string(n);
		strBase.append(strN);
		strBase.append(str);
		m_numTex[n].Load(strBase);
		std::cout << strBase << std::endl;
	}
}

void NumUI_Class::DrawSprite()
{
	if (!m_Alive)return;
	if (m_num < 10)
	{
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_numTex[m_num], m_pos.x, m_pos.y /*,&m_rc*/);
	}
	if (m_num >= 10)
	{
		std::string numStr = std::to_string(m_num);
		int firstNum = m_num % 10;
		int secondNum = (m_num /10) % 10;
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_numTex[firstNum], m_pos.x, m_pos.y /*,&m_rc*/);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_numTex[secondNum], m_pos.x - 50, m_pos.y /*,&m_rc*/);
	}
}
