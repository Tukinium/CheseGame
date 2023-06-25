#pragma once
class KdSoundInstance;
class BaseAudio_Class
{
public:
	void SetAudio(std::string _pass);
	void SetLoop(bool _loop)
	{
		m_loop = _loop;
	}
	void PlayAudio();
	void StopAudio();
protected:
	std::string m_audioPass;
	std::shared_ptr<KdSoundInstance>m_sound;
	bool m_loop = false;
	bool m_stop = true;
};