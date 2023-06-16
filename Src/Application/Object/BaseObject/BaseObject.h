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
	virtual void MathMatrix();
	virtual bool thisPiece() { return false; }
	virtual int CanMoveBordInfo(int h, int w) { return 0; };
	bool GetfirstMoved()
	{
		return m_firstMoved;
	}
	void SetfirstMoved(bool _moved)
	{
		m_firstMoved = _moved;
	}
	int GetId()
	{
		return m_id;
	}
	void SetId(int _id)
	{
		m_id = _id;
	}
	Math::Vector3 GetPos2()
	{
		return m_pos;
	}
	void SetPos2(Math::Vector3 _pos)
	{
		m_pos = _pos;
	}
	void SetBordInfo(int h, int w, int _num)
	{
		m_canMoveBordInfo[h][w] = _num;
	}
	// テクスチャ、ポリゴン、モデルいずれかを作成してテクスチャをセットする
	// 実行と同時にスマートポインタが作成されるため注意
	// _type  そのモデルのタイプ(Enum ModelType参照)
	// _filePass  セットしたいテクスチャのパス
	void SetAsset(int _type, std::string _filePass);

	enum ModelType
	{
		None = 0,
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
	void GetMassCenter()
	{
		for (int h = 0; h < 8; h++)
		{
			for (int w = 0; w < 8; w++)
			{
				Math::Vector3 massPos = { h * 1 - 3.5f,0,w * 1 - 3.5f };
				if (Math::Vector3::Distance(massPos, GetPos()) < 0.5)
				{
					centerH = h;
					centerW = w;
				}
			}
		}
	}
	enum PieceType
	{
		WhitePawn0 = 0,
		Bishop,
		WhiteKnight0,
		Rook,
		Queen,
		King,
	};
	enum Bord
	{
		Enpty,
		Me,
		CanMove,
		Select,
	};

protected:
	int m_canMoveBordInfo[8][8] =
	{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	};
	const float Defalut_Scale_Const = 1.0f;

	Math::Matrix m_transMat = Math::Matrix::Identity;
	Math::Vector3 m_pos = {};

	Math::Matrix m_rotateMat;
	Math::Matrix m_rotateX;
	Math::Matrix m_rotateY;
	Math::Matrix m_rotateZ;
	Math::Vector3 m_rotateVec = {};

	Math::Matrix m_scaleMat;
	float m_scale = Defalut_Scale_Const;

	bool m_Alive = false;

	int m_type = None;

	bool m_thisSprite = false;
	KdTexture m_tex;

	bool m_thisPolygon = false;
	std::shared_ptr<KdPolygon>m_polygon = nullptr;

	bool m_thisModel = false;
	std::shared_ptr<KdModelWork>m_model = nullptr;

	std::string fillPass;

	Math::Color m_color = kNormalColor;

	Math::Rectangle m_rc;

	bool m_firstMoved = false;

	int m_id;

	int centerH = 0;
	int centerW = 0;
};

//記述を楽にするためのマクロ #define
//参考"https://learn.microsoft.com/ja-jp/cpp/preprocessor/hash-define-directive-c-cpp?view=msvc-170"

// KdShaderManager::Instance().m_HD2DShader の記述を KdHD2DShader に短縮
#define KdHD2DShader KdShaderManager::Instance().m_HD2DShader