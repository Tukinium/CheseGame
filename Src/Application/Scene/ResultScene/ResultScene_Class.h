#pragma once
class BaseObject_Class;
#include"Application/Scene/BaseScene/BaseScene.h"
class ResultScene_Class : public BaseScene_Class
{
public:
	void SetSharedPtr()override;
	void Update()override;
private:
	std::shared_ptr<BaseObject_Class>m_back;
};

