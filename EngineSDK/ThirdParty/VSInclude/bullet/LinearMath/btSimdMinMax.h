/*
Copyright (c) 2003-2006 Gino van den Bergen / Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/



#ifndef SIMD_MINMAX_H
#define SIMD_MINMAX_H
#include "btScalar.h"

template <class T>
SIMD_FORCE_INLINE const T& btMin(const T& a, const T& b) {
  return b < a ? b : a;
}

template <class T>
SIMD_FORCE_INLINE const T& btMax(const T& a, const T& b) {
  return  a < b ? b : a;
}

template <class T>
SIMD_FORCE_INLINE void btSetMin(T& a, const T& b) {
    if (a > b) a = b;
}

template <class T>
SIMD_FORCE_INLINE void btSetMax(T& a, const T& b) {
    if (a < b) a = b;
}

// Specialize on float/double for platforms that have btFsel natively
#ifdef BT_HAVE_NATIVE_FSEL
SIMD_FORCE_INLINE  float btMin( float a,  float b) {
	return (float)btFsel((a-b), b, a);
}

SIMD_FORCE_INLINE  float btMax( float a,  float b) {
	return (float)btFsel((a-b), a, b);
}

SIMD_FORCE_INLINE void btSetMin(float& a,  float b) {
	a = (float)btFsel((a-b), b, a);
}

SIMD_FORCE_INLINE void btSetMax(float& a,  float b) {
	a = (float)btFsel((a-b), a, b);
}

SIMD_FORCE_INLINE  double btMin( double a,  double b) {
	return btFsel((a-b), b, a);
}

SIMD_FORCE_INLINE  double btMax( double a,  double b) {
	return btFsel((a-b), a, b);
}

SIMD_FORCE_INLINE void btSetMin(double& a, double b) {
	a = btFsel((a-b), b, a);
}

SIMD_FORCE_INLINE void btSetMax(double& a,  double b) {
	a = btFsel((a-b), a, b);
}
#endif

#endif