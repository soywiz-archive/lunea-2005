/*  $Id: matrix4x4.h,v 1.2 2004/04/11 15:38:16 mbn Exp $
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

//! clanCore="Math"
//! header=core.h

#ifndef header_matrix4x4
#define header_matrix4x4

#if _MSC_VER > 1000
#pragma once
#endif

//: 4x4 Matrix.
class CL_Matrix4x4
{
//! Construction:
public:
	//: Constructs a 4x4 matrix.
	//param identity: When true, initial matrix will be the identity matrix. If false, initial will be null matrix.
	//param matrix[16]: Initial matrix.
	CL_Matrix4x4(bool identity = false);

	CL_Matrix4x4(const CL_Matrix4x4 &copy);

	CL_Matrix4x4(double *matrix);

	CL_Matrix4x4(float *matrix);

//! Attributes:
public:
	double matrix[16];

	//: Operator that returns the matrix as a double[16] array.
	operator double const*() const { return matrix; }

	//: Operator that returns the matrix as a double[16] array.
	operator double *() { return matrix; }

	//: Operator that returns the matrix cell at the given index.
	double &operator[](int i) { return matrix[i]; }

	//: Operator that returns the matrix cell at the given index.
	const double &operator[](int i) const { return matrix[i]; }

	//: Operator that returns the matrix cell at the given index.
	double &operator[](unsigned int i) { return matrix[i]; }

	//: Operator that returns the matrix cell at the given index.
	const double &operator[](unsigned int i) const { return matrix[i]; }

	//: Returns the x coordinate for the point (0,0,0) multiplied with this matrix.
	double get_origin_x() const;

	//: Returns the y coordinate for the point (0,0,0) multiplied with this matrix.
	double get_origin_y() const;

	//: Returns the z coordinate for the point (0,0,0) multiplied with this matrix.
	double get_origin_z() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_Matrix4x4 &operator =(const CL_Matrix4x4 &copy);

	//: Equality operator.
	bool operator==(const CL_Matrix4x4 &other);

	//: Not-equal operator.
	bool operator!=(const CL_Matrix4x4 &other);

	//: Multiply two matrices.
	CL_Matrix4x4 multiply(const CL_Matrix4x4 &matrix);

//! Implementation:
private:
};

#endif
