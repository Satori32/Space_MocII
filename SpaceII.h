#pragma once
#include <stdio.h>
#include <stdint.h>

#include "FixedSurfaceT.h"
#include "Size3D.h"
#include "Point3D.h"

struct SpaceII {
	//type M = NULL;
	typedef double M;
	//type Metric = M;
	//type C = NULL;
	typedef RGB32 C;
	//type Color = C;
	FixedSurfaceT<M> ZBuffer;
	FixedSurfaceT<C> Front;
	Size3D<M> Size;
};
template<size_t Width, size_t Height> SpaceII ConstructSpaceII<Width, Height>(Size3D<SpaceII::M>& S);
bool Free(SpaceII& In);
bool SetPixel(SpaceII& In, Point3D<SpaceII::M> P, SpaceII::C& C);
SpaceII::C* IndexColor(SpaceII& In, Point3D<SpaceII::M> P);//this is not color count of CHAR_BIT.
SpaceII::M* IndexZBuffer(SpaceII& In, Point3D<SpaceII::M> P);//this is not color count of CHAR_BIT.
