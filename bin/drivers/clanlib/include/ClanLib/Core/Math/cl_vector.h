/*  $Id: cl_vector.h,v 1.18 2004/01/02 15:42:43 mbn Exp $
**
**  CL_Vector class
**  Copyright (C) 1999  Daniel Vogel
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
**
*/

//! clanCore="Math"
//! header=core.h

#ifndef header_cl_vector
#define header_cl_vector

#if _MSC_VER > 1000
#pragma once
#endif

#include <iostream>

//: Vector class.
//- !group=Core/Math!
//- !header=core.h!
//- <p>This class provides basic functions and operators for working with vectors.</p>
class CL_Vector
{
public:
//! Variables:
	//: x coordinate
	float x;
	//: y coordinate
	float y;
	//: z coordinate
	float z;
	//: w coordinate
	float w;
      
public:
	
//! Construction:
	//: Constructor that initializes a vector
	//param x: Initial x coordinate of vector.
	//param y: Initial y coordinate of vector.
	//param z: Initial z coordinate of vector.
	//param w: Initial w coordinate of vector.
	//param other: vector to copy construct from.
	CL_Vector(float x = 0.0, float y = 0.0, float z = 0.0, float w = 1.0);

	CL_Vector(const CL_Vector &other);

//! Attributes:
	//: Returns the (euclid) norm of the vector.
	//- <p>This function does not use the w coordinate of the vector. It only uses
	//- the x,y,z coordinates.</p>
	//return: the euclid norm of the vector (in R^3)
	float norm() const;

	//: Normalizes the vector (not taking into account the w ordinate!)
	void normalize();

	//: Dot products this vector with an other vector.
	//param vector: Second vector used for the dot product.
	//return: The resulting dot product of the two vectors.
	float dot(const CL_Vector& vector) const;
	
	//: Calculate the angle between this vector and an other vector.
	//param vector: Second vector used to calculate angle.
	//return: The angle between the two vectors.
	float angle(const CL_Vector& vector) const;

	//: Calculate the cross product between this vector and an other vector.
	//param vector: Second vector used to perform the calculation.
	//return: The cross product of the two vectors.
	CL_Vector cross(const CL_Vector& vector) const;
	
	//: Rotate vector around an axis.
	//param angle: Angle to rotate.
	//param axis: Rotation axis.
	//return: The resulting rotated vector.
	CL_Vector rotate(float angle, const CL_Vector& axis) const;

	//: Rounds all components.
	void round();

//! Operators:
	//: Scalar product (vector * scalar)
	//return: The scalar product
	CL_Vector operator * (float scalar) const;  

	//: Scalar product (scalar * vector)
	//return: The scalar product.
	friend CL_Vector operator *  (float scalar, const CL_Vector& vector);

	//: += operator.
	void operator += (const CL_Vector& v);

	//: -= operator.
	void operator -= (const CL_Vector& v);  

	//: *= operator (scalar multiplication).
	void operator *= (float s);  

	//: + operator.
	CL_Vector operator + (const CL_Vector& v) const;
	
	//: - operator.
	CL_Vector operator - (const CL_Vector& v) const;
	
	//: unary - operator.
	CL_Vector operator - () const;

	//: assignment operator.
	CL_Vector& operator = (const CL_Vector& v);

	//: Returns true if current vector equals v.
	//param v: other vector.
	//return: true if v equals the current vector, false otherwise.
	bool operator == (const CL_Vector& v) const;
    	
	//: Returns false if current vector equals v.
	//param v: other vector.
	//return: false if v equals the current vector, true otherwise.
	bool operator != (const CL_Vector& v) const;
	
	//: Returns reference to n-th ordinate (0. == x, 1. == y, ...).
	//param n: number of ordinate (starting with 0).
	//return: reference to the n-th ordinate.
	float& operator [] (int n);
	
	//: cout's the x,y,z ordinates (meant for debugging).
	friend std::ostream& operator << (std::ostream&, const CL_Vector& v);
};

std::ostream& operator << (std::ostream& os, const CL_Vector& v);

#endif
