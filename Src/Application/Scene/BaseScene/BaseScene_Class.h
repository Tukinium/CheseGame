#pragma once
class BaseScene_Class
{
public:
	BaseScene_Class() { Init(); };
	~BaseScene_Class() { Release(); };

	// ���������S�Ăɋ��ʂ���p�����[�^�ɑ΂��鏉�����̂�
	virtual void Init() {}

	virtual void PreUpdate() {}
	virtual void Update() {}
	virtual void PostUpdate() {}

	// ���ꂼ��̏󋵂ŕ`�悷��֐�
	virtual void GenerateDepthMapFromLight() {}
	virtual void DrawLit() {}
	virtual void DrawUnLit() {}
	virtual void DrawBright() {}
	virtual void DrawSprite() {}

protected:
	void Release() {}
};