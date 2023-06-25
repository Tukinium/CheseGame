#include"BaseObject.h"
void BaseObject_Class::Update()
{

}

void BaseObject_Class::Init()
{
	SetAsset(m_modeltype, fillPass);
	m_scale = DEFAULT_SCALE;
	m_Alive = true;
}

void BaseObject_Class::DrawLit()
{
	//このインスタンスはModelタイプかチェック＆中身が作成されてるかチェック
	if (!m_model || !m_Alive)return;
	KdHD2DShader.DrawModel(*m_model, m_mWorld);
}

void BaseObject_Class::GenerateDepthMapFromLight()
{
}

void BaseObject_Class::DrawBright()
{

}

void BaseObject_Class::DrawUnLit()
{

}

void BaseObject_Class::DrawSprite()
{
	//このインスタンスはPolygonタイプかチェック＆中身が作成されてるかチェック
	if (!m_tex || !m_Alive)return;
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), 0, 0/*,& m_rc*/);
}

void BaseObject_Class::PreUpdate()
{

}

void BaseObject_Class::PostUpdate()
{
	//MathMatrix();
}

void BaseObject_Class::SetAsset(int _type, std::string _filePass)
{
	switch (_type)
	{
	case Sprite:
	{
		if (m_tex)return;
		m_tex = std::make_shared<KdTexture>();
		m_tex->Load(_filePass);
		return;
	}
	case Polygon:
	{
		if (m_polygon)return;
		m_polygon = std::make_shared<KdPolygon>();
		m_polygon->SetMaterial(_filePass);
		return;
	}
	case Model:
	{
		if (m_model)return;
		m_model = std::make_shared<KdModelWork>();
		m_model->SetModelData(_filePass);
		return;
	}
	}
	return;
}
