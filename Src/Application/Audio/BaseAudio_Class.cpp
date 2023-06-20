#include"BaseAudio_Class.h"

void BaseAudio_Class::PlayAudio()
{
	m_audio->Play(m_audioPass,m_loop);
}

void BaseAudio_Class::StopAudio()
{
	m_audio->StopAllSound();
}
