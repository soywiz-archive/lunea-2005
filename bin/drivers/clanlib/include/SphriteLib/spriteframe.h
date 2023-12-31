#ifndef _SPHRITELIB_SPRITEFRAME_H_
#define _SPHRITELIB_SPRITEFRAME_H_

class Texture;

//! This class contains an individual frame in a SpriteProvider.
/*!
	Just a small class containing the texture of the current frame,
	and the delay until next frame should be displayed.
*/
class SpriteFrame
{
//@{@name Construction:
public:
	SpriteFrame(Texture *texture, float delay, int offsetx, int offsety);
	~SpriteFrame();
//@}

//@{@name Attributes:
public:
	//! The surface of this frame.
	Texture *texture;

	//! The delay between this and next frame in milliseconds.
	float delay;

	//! The offset of x from the hotspot.
	int offsetX;

	//! The offset of y from the hotspot.
	int offsetY;
//@}
};

#endif
