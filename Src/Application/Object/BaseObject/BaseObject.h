#pragma once
class BaseObject_Class : public KdGameObject
{
public:
	BaseObject_Class() { Init(); };
	~BaseObject_Class() {};
	virtual void Update()override;
	virtual void Init()override;
	virtual void Draw(){}
	virtual void DrawLit()override;
	virtual void GenerateDepthMapFromLight()override;
	virtual void DrawBright()override;
	virtual void DrawUnLit()override;
	virtual void DrawSprite()override;
	virtual void PreDraw(){}
	virtual void PostDraw(){}
	virtual void PreUpdate()override;
	virtual void PostUpdate()override;
	// テクスチャ、ポリゴン、モデルいずれかを作成してテクスチャをセットする
	// 実行と同時にスマートポインタが作成されるため注意
	// _type  そのモデルのタイプ(Enum ModelType参照)
	// _filePass  セットしたいテクスチャのパス
	void SetAsset(int _type, std::string _filePass);

	enum ModelType
	{
		Sprite = 1,
		Polygon,
		Model,
	};
	bool GetAlive()
	{
		return m_Alive;
	}
	void SetAlive(bool _alive)
	{
		m_Alive = _alive;
	}
	void SetColor(const Math::Color& _color)
	{
		m_color = _color;
	}
	Math::Color GetColor()
	{
		return m_color;
	}
	void SetSelecting(bool _selecting)
	{
		m_selecting = _selecting;
	}

protected:

	const float DEFAULT_SCALE = 1.0f;

	float m_scale = DEFAULT_SCALE;

	bool m_Alive = false;

	int m_modeltype = 0;

	std::shared_ptr<KdTexture>m_tex = nullptr;

	std::shared_ptr<KdPolygon>m_polygon = nullptr;

	std::shared_ptr<KdModelWork>m_model = nullptr;

	std::string fillPass;

	Math::Color m_color = kNormalColor;

	Math::Rectangle m_rc;

	bool m_selecting;
};

//記述を楽にするためのマクロ #define
//参考"https://learn.microsoft.com/ja-jp/cpp/preprocessor/hash-define-directive-c-cpp?view=msvc-170"

// KdShaderManager::Instance().m_HD2DShader の記述を KdHD2DShader に短縮
#define KdHD2DShader KdShaderManager::Instance().m_HD2DShader