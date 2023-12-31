#pragma once

#include <ClanLib/mikmod.h>
#include <ClanLib/sound.h>

#include <lunea_debug.h>
#include <lunea_define.h>

class Music {
public:
	CL_SoundBuffer music;

	Music();
	~Music();
	static Music* loadFromFile(const char *fileName);
};

// Crea un nuevo Music
Music *music_load(const char *name);
Music *music_load_from_resource(const char *name);

void music_play(Music *music);
void music_stop();
void music_volume_set(int volume);
int  music_volume_get();
bool music_playing();
int  music_length_get();
void music_position_set(int position);
int  music_position_get();

extern bool music_playback_started;
extern CL_SoundBuffer_Session music_playback;