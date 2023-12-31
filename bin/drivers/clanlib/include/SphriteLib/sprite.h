#ifndef _SPHRITELIB_SPRITE_H_
#define _SPHRITELIB_SPRITE_H_

#include <stdlib.h>
#include <string>

class SpriteFrame;
class SpriteProvider;

//! This class handles displaying sprites on the display. 
/*!
	This is the main class you will probably use the most.
	Normally, this class is instantiated once per object on screen.

	It contains and updates the current position, rotation and frame.
	The sprite images themselves are not in this class, but referenced to a SpriteProvider
	which contains the data. Therefore, to change a look of a sprite, you just change
	the spriteprovider.

	It gets its initial speed and loop-values from the SpriteProvider, but these
	may be overridden.
*/
class Sprite
{ 
//@{@name Construction:
public:
	//! Constructs a sprite from a SpriteProvider.
	Sprite(SpriteProvider *spriteProvider = NULL);
//@}

//@{@name Attributes:
public:
	//! Returns current X position.
	float getX() const;

	//! Returns current Y position.
	float getY() const;

	//! Returns current angle.
	float getAngle() const;

	//! Returns current scale.
	//! If x scale is different than y scale, x scale is returned.
	//! 1.0f is normal scale, 2.0f is twice the size, etc.
	float getScale() const;

	//! Returns scale for x and y.
	//! 1.0f is normal scale, 2.0f is twice the size, etc.
	void getScale(float &x, float &y) const;

	//! Returns current frame in animation.
	int getCurrentFrame() const;

	//! Returns current transparency.
	//! 0.0f is full transparency, and 1.0f is full visibility.
	float getAlpha() const;

	//! Return width of a frame.
	int getWidth(int frame) const;

	//! Return height of a frame.
	int getHeight(int frame) const;

	//! Returns hotspot coordinates.
	//! Returns -1 if hotspot is centered.
	void getHotSpot(int &x, int &y) const;

	//! Returns true if animation is played in loop (more than once).
	bool isPlayLoop() const;

	//! Returns true if animation is played in from right to left (starts at end).
	bool isPlayBackward() const;

	//! Returns true if animation is played in ping-pong mode.
	bool isPlayPingPong() const;

	//! Returns true is last frame is shown after animation is done.
	//! If false, nothing is shown when animation is done.
	bool isShowLastFrame() const;

	//! Returns true if animation is finished.
	bool isFinished() const;

	//! Returns any frame.
	SpriteFrame *getFrame(int frame) const;

	//! Returns the spriteprovider.
	SpriteProvider *getSpriteProvider() const;
//@}

//@{@name Operations:
public:
	//! Draw the sprite using the current position and angle.
	/*! Note that the sprite is drawn centered at the current position.*/
	virtual void draw() const;

	//! Draw the sprite using position parameters.
	/*! This will override the current position (setPos()).*/
	/*! Note that the sprite is drawn centered at the current position.*/
	virtual void draw(int posX, int posY) const;

	//! Draw the sprite using position and rotation parameters.
	/*! This will override the current position (setPos()) and rotation (setAngle()).*/
	/*! Note that the sprite is drawn centered at the current position.*/
	virtual void draw(int posX, int posY, float angle) const;

	//! Call this function to update the animation.
	//! float timeElapsed: milliseconds since last update.
	virtual void update(float timeElapsed);

	//! Set current X position.
	void setX(float x);

	//! Set current Y position.
	void setY(float y);

	//! Set both X and Y position.
	void setPos(float x, float y);

	//! Set absolute rotation angle.
	void setAngle(float angle);

	//! Add angle to current angle.
	void rotate(float angle);

	//! Set scale for sprite. This will set both x and y scale the same value.
	//! 1.0f is normal scale, 2.0f is twice the size, etc.
	void setScale(float scale);

	//! Set scale for x and y directions individually.
	//! 1.0f is normal scale, 2.0f is twice the size, etc.
	void setScale(float x, float y);

	//! Sets current animation frame.
	//! It will cap to available range.
	void setFrame(int frame);

	//! Sets transparency for sprite.
	//! 0.0f is full transparency, and 1.0f is full visibility.
	void setAlpha(float alpha);

	//! Sets hotspot of the sprite.
	//! Set hotspot to -1 to center.
	void setHotSpot(int x, int y);

	//! Set to true if animation should loop, false otherwise.
	void setPlayLoop(bool loop = true);

	//! Set to true if animation should loop, false otherwise.
	void setPlayPingPong(bool pingpong = true);

	//! Set to true if animation should go backward (start at end).
	void setPlayBackward(bool backward = true);

	//! Set to true to show last frame once animation is finished.
	//! If false, nothing is shown when animation is done.
	void setShowLastFrame(bool show = true);

	//! Finish animation.
	/*! When an animation is finished, it will no longer show, unless ShowLastFrame is set to true.*/
	void finish();

	//! Restart animation.
	void restart();

	//! Change the spriteprovider.
	/*! Use this to change the look of a sprite.*/
	void setSpriteProvider(SpriteProvider *spriteProvider);
//@}

// Implementation:
private:
	short currentFrame;
	short deltaFrame;
 
	bool finished;
	bool playLoop;
	bool playPingPong;
	bool playBackward;
	bool showLastFrame;

	float updateTime;

	float x;
	float y;
	float angle;

	short hotspotX;
	short hotspotY;

	float scaleX;
	float scaleY;

	float alpha;

	SpriteProvider *spriteProvider;
};

#endif
