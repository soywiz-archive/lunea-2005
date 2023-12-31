/*  $Id: light_source.h,v 1.4 2004/01/02 15:42:43 mbn Exp $
**
**  ClanLib Game SDK
**  Copyright (C) 2003  The ClanLib Team
**  For a total list of contributers see the file CREDITS.
**
**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Lesser General Public
**  License as published by the Free Software Foundation; either
**  version 2.1 of the License, or (at your option) any later version.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public
**  License along with this library; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

//! clanGL="Display 3D"
//! header=gl.h

#ifndef header_light_source
#define header_light_source

#include "viewpoint.h"
#include "opengl.h"

//: OpenGL glLight container.
//- !group=GL/Display 3D!
//- !header=gl.h!
class CL_LightSource
{
//! Construction:
public:
	//: Constructs a light source container.
	CL_LightSource();

	~CL_LightSource();

//! Attributes:
public:
	//: Returns the intensity distribution of the light.
	//- <p>Only values in the range [0,128] are accepted. The default spot exponent is 0,
	//- resulting in uniform light distribution.</p>
	float get_spot_exponent() const;

	//: Returns the spot cutoff angle (the maximum spread angle of a light source).
	//- <p>The default spot cutoff is 180, resulting in uniform light distribution.</p>
	float get_spot_cutoff() const;

	//: Returns constant attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	float get_constant_attenuation() const;

	//: Returns linear attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	float get_linear_attenuation() const;

	//: Returns quadratic attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	float get_quadratic_attenuation() const;

	//: Returns the ambient (global light) intensity of the light.
	void get_ambient_intensity(float &red, float &green, float &blue, float &alpha) const;

	//: Returns the diffuse (spread over wide area) intensity of the light.
	void get_diffuse_intensity(float &red, float &green, float &blue, float &alpha) const;

	//: Returns the specular (mirror reflective) intensity of the light.
	void get_specular_intensity(float &red, float &green, float &blue, float &alpha) const;

	//: Returns the light position.
	CL_Vector get_position() const;

	//: Returns the light spot direction.
	CL_Vector get_spot_direction() const;

//! Operations:
public:
	//: Sets the intensity distribution of the light.
	//- <p>Only values in the range [0,128] are accepted. The default spot exponent is 0,
	//- resulting in uniform light distribution.</p>
	void set_spot_exponent(float spot_exponent);

	//: Sets the spot cutoff angle (the maximum spread angle of a light source).
	//- <p>The default spot cutoff is 180, resulting in uniform light distribution.</p>
	void set_spot_cutoff(float spot_cutoff);

	//: Sets the constant attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	void set_constant_attenuation(float constant_attenuation);

	//: Sets linear attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	void set_linear_attenuation(float linear_attenuation);

	//: Sets quadratic attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	void set_quadratic_attenuation(float quadratic_attenuation);

	//: Sets the ambient (global light) intensity of the light.
	void set_ambient_intensity(float red, float green, float blue, float alpha = 1.0f);

	//: Sets the diffuse (spread over wide area) intensity of the light.
	void set_diffuse_intensity(float red, float green, float blue, float alpha = 1.0f);

	//: Sets the specular (mirror reflective) intensity of the light.
	void set_specular_intensity(float red, float green, float blue, float alpha = 1.0f);

	//: Sets the light position.
	//- <p>The position is transformed by the modelview matrix when glLight is called
	//- (just as if it were a point), and it is stored in eye coordinates. If the w
	//- component of the position is 0.0, the light is treated as a directional source.</p>
	//- <p>Diffuse and specular lighting calculations take the lights direction, but not
	//- its actual position, into account, and attenuation is disabled. Otherwise, diffuse
	//- and specular lighting calculations are based on the actual location of the light
	//- in eye coordinates, and attenuation is enabled.</p>
	//- <p>The default position is (0,0,1,0); thus, the default light source is directional,
	//- parallel to, and in the direction of the –z axis.</p>
	void set_position(const CL_Vector &position);

	//: Sets the light spot direction.
	void set_spot_direction(const CL_Vector &spot_direction);

	//: Sets position and spot direction as a viewpoint.
	//- <p>The position is transformed by the modelview matrix when glLight is called
	//- (just as if it were a point), and it is stored in eye coordinates. If the w
	//- component of the position is 0.0, the light is treated as a directional source.</p>
	//- <p>Diffuse and specular lighting calculations take the lights direction, but not
	//- its actual position, into account, and attenuation is disabled. Otherwise, diffuse
	//- and specular lighting calculations are based on the actual location of the light
	//- in eye coordinates, and attenuation is enabled.</p>
	//- <p>The default position is (0,0,1,0); thus, the default light source is directional,
	//- parallel to, and in the direction of the –z axis.</p>
	void set_viewpoint(const CL_Viewpoint &viewpoint);

	//: Sends the light configuration to OpenGL.
	//param light_identifier: OpenGL light identifier to be setup for this light.
	//param light_identifier: They are identified by symbolic names of the form CL_LIGHTi.
	void setup_light(CLenum light_identifier);

//! Implementation:
private:
	float spot_exponent;

	float spot_cutoff;

	float constant_attenuation;

	float linear_attenuation;

	float quadratic_attenuation;

	float ambient[4];

	float diffuse[4];

	float specular[4];

	CL_Vector position;

	CL_Vector spot_direction;
};

#endif
