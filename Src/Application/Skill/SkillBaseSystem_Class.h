#pragma once
class SkillSystemBase_Class : public KdGameObject
{
public:
	SkillSystemBase_Class() {};
	~SkillSystemBase_Class() {};
	void Init()override;
	void Update()override;
	void DrawSprite()override;
protected:
	int m_skillCoolDown;

};