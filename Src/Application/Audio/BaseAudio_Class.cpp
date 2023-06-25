#include"BaseAudio_Class.h"
#include"Src/Framework/Audio/KdAudio.h"
void BaseAudio_Class::SetAudio(std::string _pass)
{
	m_audioPass = _pass;
	m_sound = KdAudioManager::Instance().Play(_pass);
	m_sound->Stop();
}
void BaseAudio_Class::PlayAudio()
{
	m_sound->Play(m_loop);
}

void BaseAudio_Class::StopAudio()
{
	m_sound->Stop();
}
