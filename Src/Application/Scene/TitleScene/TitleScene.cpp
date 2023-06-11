#include "TitleScene.h"
#include"Application/Object/BaseObject/BaseObject.h"
void TitleScene_Class::Init()
{
	/*
	class temp : public BaseObject_Class
	{
	public:
		temp() {};
		~temp() {};
		void DrawSprite()
		{
			Math::Rectangle rc = { 0,0,64,64 };
			KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
			KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), 0, 0, &rc);
		}
		void setTexture(std::string _pass)
		{
			m_tex = std::make_shared<KdTexture>();
			m_tex = (KdAssets::Instance().m_textures.GetData(_pass));
		}
	private:
		std::shared_ptr<KdTexture>m_tex;
		
	};
	

	std::shared_ptr<temp>a = std::make_shared<temp>();
	a->setTexture("");
	m_baseObjList.push_back(a);
	*/
	BaseScene_Class::Init();
}

void TitleScene_Class::Update()
{
	BaseScene_Class::Update();
	if (GetAsyncKeyState(VK_RETURN))m_nowScene = false;
}
