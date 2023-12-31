#ifndef _SPHRITELIB_SPRITEPROVIDER_H_
#define _SPHRITELIB_SPRITEPROVIDER_H_

#ifdef WIN32
#pragma warning (disable:4786)
#endif

#include <string>
#include <vector>

class CL_ResourceManager;
class SpriteFrame;

//! This class handles loading sprites from ClanLib resources. 
/*!
	It contains the sprite-images themselves, and default values for updating & drawing (looping, speed etc).
	It does not contain the current frame, position or rotation, and therefore
	seldomly used directly, but used when you create a Sprite.
*/
class SpriteProvider
{ 
//@{@name Construction:
public:
	//! Constructs a SpriteProvider from a ClanLib resource section.
	SpriteProvider(const char *section, CL_ResourceManager *resources);

	//! Destructor.
	~SpriteProvider();
//@}

//@{@name Attributes:
public:
	//! Returns name of sprite.
	const std::string &getName() const;

	//! Returns the id of sprite (if available).
	long getID() const;

	//! Returns total frames in sprite.
	int getTotalFrames() const;

	//! Returns initial (unrotated) angle of sprite.
	int getInitialAngle() const;

	//! Returns width of a spriteframe.
	int getWidth(int frame = 0) const;

	//! Returns height of a spriteframe.
	int getHeight(int frame = 0) const;
	
	//! Returns the hotspot.
	//! Returns -1 if hotspot is centered.
	void getHotSpot(short &x, short &y) const;

	//! Returns true if animation is played in loop (more than once).
	bool isPlayLoop() const;

	//! Returns true if animation is played in from right to left (starts at end).
	bool isPlayBackward() const;

	//! Returns true if animation is played in ping-pong mode.
	bool isPlayPingPong() const;

	//! Returns true is last frame is shown after animation is done.
	bool isShowLastFrame() const;

	//! Returns any frame.
	SpriteFrame *getFrame(int frame) const;
//@}

//@{@name Operations:
public:
	//! Draw the sprite using position, frame, rotation, scale and alpha parameters.
	void draw(int x, int y, short hotspotX, short hotspotY, float scaleX = 1.0f, float scaleY = 1.0f, int frame = 0, float angle = 0.0f, float alpha = 1.0f);

	//! Flip all or one spriteframe vertically.
	/*! If argument is -1, all frames will be flipped, otherwise only the specified*/
	/*! frame is flipped.*/
	/*! 2d-version: this is a costly operation, and should not be done on each frame*/
	/*! update, but rather have two instances of the sprite-provider, one for each*/
	/*! direction.*/
	/*! OpenGL-version: This is a non-costly operation, and can be switched anytime*/
	/*! without any frame loss.*/
	void flipVertical(int frame = -1);

	//! Flip all or one spriteframe horizontally.
	/*! If argument is -1, all frames will be flipped, otherwise only the specified*/
	/*! frame is flipped.*/
	/*! 2d-version: this is a costly operation, and should not be done on each frame*/
	/*! update, but rather have two instances of the sprite-provider, one for each*/
	/*! direction.*/
	/*! OpenGL-version: This is a non-costly operation, and can be switched anytime*/
	/*! without any frame loss.*/
	void flipHorizontal(int frame = -1);
//@}

// Implementation:
private:
	void validateIndex(int frame) const;

private:
	std::vector<SpriteFrame *> frames;

	short totalFrames;
	short initialAngle;
	short hotspotX;
	short hotspotY;
	bool playPingPong;
	bool playLoop;
	bool playBackward;
	bool showLastFrame;

	std::string name;
	long id;
};

#endif
