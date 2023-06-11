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

	//���͂��ꂽ���̗�����Ԃ�
	std::string generateRandomID(int length) 
	{
		static const std::string alphanumericChars =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, alphanumericChars.size() - 1);

		std::string result;
		for (int i = 0; i < length; ++i) {
			result += alphanumericChars[dis(gen)];
		}
		
		return result;
	}

	std::string GetId()
	{
		return m_objID;
	}

	// �e�N�X�`���A�|���S���A���f�������ꂩ���쐬���ăe�N�X�`�����Z�b�g����
	// ���s�Ɠ����ɃX�}�[�g�|�C���^���쐬����邽�ߒ���
	// _type  ���̃��f���̃^�C�v(Enum ModelType�Q��)
	// _filePass  �Z�b�g�������e�N�X�`���̃p�X
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
	

	enum PieceType
	{
		Pawn = 0,
		Bishop,
		Knight,
		Rook,
		Queen,
		King,
	};


protected:
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

	std::string m_objID;

	Math::Rectangle m_rc;
};

//�L�q���y�ɂ��邽�߂̃}�N�� #define
//�Q�l"https://learn.microsoft.com/ja-jp/cpp/preprocessor/hash-define-directive-c-cpp?view=msvc-170"

// KdShaderManager::Instance().m_HD2DShader �̋L�q�� KdHD2DShader �ɒZ�k
#define KdHD2DShader KdShaderManager::Instance().m_HD2DShader