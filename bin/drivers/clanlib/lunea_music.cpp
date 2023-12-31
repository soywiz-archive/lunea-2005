#include <lunea_music.h>

// Constructor
Music::Music() {
}

// Destructor
Music::~Music() {
}

Music* Music::loadFromFile(const char *fileName) {
	Music *retval = new Music();
	retval->music = CL_SoundBuffer(fileName);
	return retval;
}

Music *music_load(const char *name) {
	CL_SoundBuffer music(name);

	Music *ret = new Music();
	ret->music = music;

	return ret;
}

Music *music_load_from_resource(const char *name) {
	char tname[L_tmpnam];
	Music *retval;

	if (create_file_from_resource(name, tname) != 0) return (Music *)0;

	retval = music_load(tname);
	//delete_file_created_from_resource(tname);

	return retval;
}

void music_play(Music *music) {
	if (!music) return;

	if (music_playback_started && music_playing()) music_stop();

	// CL_SoundBuffer_Session playback(sample.prepare());
	music_playback = CL_SoundBuffer_Session(music->music.prepare());
	music_playback.play();

	music_playback_started = true;
}

void music_stop() {
	if (!music_playback_started) return;
	music_playback.stop();
}

void music_volume_set(int volume) {
	if (!music_playback_started) return;
	music_playback.set_volume(((float)volume / 100));
}

int  music_volume_get() {
	if (!music_playback_started) return 0;
	return (int)(music_playback.get_volume() * 100);
}

bool music_playing() {
	if (!music_playback_started) return false;
	return music_playback.is_playing();
}

int  music_length_get() {
	if (!music_playback_started) return 0;
	return music_playback.get_length();
}

void music_position_set(int position) {
	if (!music_playback_started) return;
	music_playback.set_position(position);
}

int  music_position_get() {
	if (!music_playback_started) return 0;
	return music_playback.get_position();
}

bool music_playback_started;
CL_SoundBuffer_Session music_playback;