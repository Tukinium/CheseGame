#include"Mouse_Class.h"

void MouseCursor_Class::Update()
{
	GetCursorPos(&MousePos);
	fixMousePos.x = MousePos.x - 1280 / 2;
	fixMousePos.y = (MousePos.y - 720 / 2) * -1;
}

void MouseCursor_Class::Init()
{
	SetAsset(Sprite, "Asset/Textures/MouseCursor.png");
}

void MouseCursor_Class::DrawSprite()
{
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), fixMousePos.x, fixMousePos.y, nullptr);
}
