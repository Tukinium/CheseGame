#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class BaseAudio_Class : public BaseObject_Class
{
public:
	void SetAudio(std::string _pass)
	{
		m_audioPass = _pass;
		m_audio->Play(_pass, false);
	}
	void SetLoop(bool _loop)
	{
		m_loop = _loop;
	}
	void PlayAudio();
	void StopAudio();
protected:
	std::string m_audioPass;
	std::shared_ptr<KdAudioManager>m_audio;
	bool m_loop = false;
	bool m_stop = true;
};