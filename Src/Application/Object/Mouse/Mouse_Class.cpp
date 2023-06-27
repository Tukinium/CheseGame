#include"Mouse_Class.h"

void MouseCursor_Class::Init()
{
	SetAsset(Sprite, "Asset/Textures/MouseCursor.png");
}

void MouseCursor_Class::DrawSprite()
{
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), fixMousePos.x, fixMousePos.y, nullptr);
}
