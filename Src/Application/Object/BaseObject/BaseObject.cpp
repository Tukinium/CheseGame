#include"BaseObject.h"
void BaseObject_Class::Update()
{

}

void BaseObject_Class::Init()
{
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
	m_Alive = true;
}

void BaseObject_Class::DrawLit()
{
	//このインスタンスはModelタイプかチェック＆中身が作成されてるかチェック
	if (!m_thisModel || !m_model || !m_Alive)return;
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
	if (!m_thisSprite || !m_Alive)return;
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex,0,0/*,& m_rc*/);
}

void BaseObject_Class::PreUpdate()
{
	MathMatrix();
}

void BaseObject_Class::PostUpdate()
{
}

void BaseObject_Class::MathMatrix()
{
	m_transMat = Math::Matrix::CreateTranslation(m_pos);
	m_scaleMat = Math::Matrix::CreateScale(m_scale);
	m_rotateX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_rotateVec.x));
	m_rotateY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_rotateVec.y));
	m_rotateZ = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_rotateVec.z));
	m_rotateMat = m_rotateX * m_rotateY * m_rotateZ;

	//行列の合成 = 拡縮 x 回転 x 移動
	m_mWorld = m_scaleMat * m_rotateMat * m_transMat;
}

void BaseObject_Class::SetAsset(int _type, std::string _filePass)
{
	switch (_type)
	{
	case Sprite:
	{
		m_tex.Load(_filePass);
		m_thisSprite = true;
		return;
	}
	case Polygon:
	{
		if (m_polygon)return;
		m_polygon = std::make_shared<KdPolygon>();
		m_polygon->SetMaterial(_filePass);
		m_thisPolygon = true;
		return;
	}
	case Model:
	{
		if (m_model)return;
		m_model = std::make_shared<KdModelWork>();
		m_model->SetModelData(_filePass);
		m_thisModel = true;
		printf("SetModel\n");
		return;
	}
	}
	return;
}
