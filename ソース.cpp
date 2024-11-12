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

template<size_t Width,size_t Height>
SpaceII ConstructSpaceII<Width, Height>(Size3D<SpaceII::M>& S) {
	SpaceII S;
	S.ZBuffer = ConstructFixedSurfaceT<SpaceII::C, Width, Height>();
	S.Front= ConstructFixedSurfaceT<SpaceII::C, Width, Height>();
	S.Size = S;

	return S;
}

bool Free(SpaceII& In) {
	Free(In);

	return true;
}
bool SetPixel(SpaceII& In, Point3D<SpaceII::M> P, SpaceII::C& C) {
	if (Index(In.Front, P.X, P.Y) == NULL) { return false; }
	if (Index(In.ZBuffer, P.X, P.Y) == NULL) { return false; }
	if ((*Index(In.ZBuffer, P.X, P.Y)) <= P.Z) { return false; }
	
	(*Index(In.Front, P.X, P.Y)) = C;
	(*Index(In.ZBuffer, P.X, P.Y)) = P.Z;

	return true;
}

SpaceII::C* IndexColor(SpaceII& In, Point3D<SpaceII::M> P) {//this is not color count of CHAR_BIT.
	//Point2D X = ConstrcutPoint2D(P.X, P.Y);
	if (Index(In.Front, P.X, P.Y) == NULL) { return NULL; }
	if (Index(In.ZBuffer, P.X, P.Y) == NULL) { return NULL; }

	return Index(In.Front, P.X, P.Y);
}
SpaceII::M* IndexZBuffer(SpaceII& In, Point3D<SpaceII::M> P) {//this is not color count of CHAR_BIT.
	//Point2D X = ConstrcutPoint2D(P.X, P.Y);
	if (Index(In.Front, P.X, P.Y) == NULL) { return NULL; }
	if (Index(In.ZBuffer, P.X, P.Y) == NULL) { return NULL; }

	return Index(In.ZBuffer, P.X, P.Y);
}