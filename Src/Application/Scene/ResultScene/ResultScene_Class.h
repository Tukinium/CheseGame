#pragma once
class BaseObject_Class;
class MouseCursor_Class;
#include"Application/Scene/BaseScene/BaseScene.h"
class ResultScene_Class : public BaseScene_Class
{
public:
	void SetSharedPtr()override;
	void Update()override;
private:
	std::shared_ptr<BaseObject_Class>m_back;
	std::shared_ptr<BaseObject_Class>m_resultWin;
	std::shared_ptr<BaseObject_Class>m_resultLose;
	std::shared_ptr<MouseCursor_Class>m_MouseCursor;
};

