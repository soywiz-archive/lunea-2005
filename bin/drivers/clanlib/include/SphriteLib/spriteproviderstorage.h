#ifndef _SPHRITELIB_SPRITESTORAGEPROVIDER_H_
#define _SPHRITELIB_SPRITESTORAGEPROVIDER_H_

#ifdef WIN32
#pragma warning (disable:4786)
#endif

#include <map>
#include <string>

class SpriteProvider;
class Sprite;
class CL_ResourceManager;

//! This class is a helper-class which stores SpriteProviders for later retrieval.
/*!
	You add SpriteProviders to this storage, so you can fetch (and share) SpriteProviders
	between classes, using a simple, yet handy class.
*/
class SpriteProviderStorage
{ 
//@{@name Construction:
public:
	//! Constructs an empty Sprite Provider Storage.
	SpriteProviderStorage();
//@}

//@{@name Attributes:
public:
	//! Retrieves a SpriteProvider, based on its name.
	SpriteProvider *get(const std::string &name) const;

	//! Retrieves a SpriteProvider, based on its ID.
	SpriteProvider *get(long id) const;

	//! Return total memory used by spriteproviders.
	int getMemoryUse() const { return totalMemoryUse; };

	//! Return all sprites available in storage.
	const std::map<std::string, SpriteProvider *> &getSprites() const { return sprites; };
//@}

//@{@name Operations:
public:
	//! Adds a SpriteProvider into the storage
	void add(SpriteProvider *sprite);

	//! Adds all sprites from a resource-file
	void add(CL_ResourceManager *resources);

	//! Creates a Sprite from a SpriteProvider stored in the storage.
	Sprite *create(const std::string &name);

	//! Creates a Sprite from a SpriteProvider stored in the storage.
	Sprite *create(long id);
//@}

// Implementation:
private:
	std::map<std::string, SpriteProvider *> sprites;

	int totalMemoryUse;
};

#endif