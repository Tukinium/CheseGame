#pragma once
class BaseAudio_Class
{
public:
	BaseAudio_Class() {};
	~BaseAudio_Class() {};
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