/*
-----------------------------------------------------------------------------
This source file is part of "vektrix"
(the rich media and vector graphics rendering library)
For the latest info, see http://www.fuse-software.com/

Copyright (c) 2009-2010 Fuse-Software (tm)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#ifndef __vtxMovableObject_H__
#define __vtxMovableObject_H__

#include "vtxPrerequesites.h"
#include "vtxInstance.h"
#include "vtxTransform.h"

namespace vtx
{
	/** Base class for everything visual that can be displayed inside a Movie */
	class vtxExport MovableObject : public Instance
	{
	public:
		MovableObject(Resource* resource);
		virtual ~MovableObject();

		/** @copybrief Transform::setX */
		virtual void setX(const float& x);
		/** @copybrief Transform::getX */
		virtual const float& getX() const;

		/** @copybrief Transform::setY */
		virtual void setY(const float& y);
		/** @copybrief Transform::getY */
		virtual const float& getY() const;

		/** @copybrief Transform::setAngle */
		virtual void setAngle(const float& angle);
		/** @copybrief Transform::getAngle */
		virtual const float& getAngle() const;

		/** @copybrief Transform::setCXForm */
		virtual void setCXForm(const CXForm& cx);

		/** @copybrief Transform::setMatrix */
		virtual void setMatrix(const Matrix& m);
		/** @copybrief Transform::getMatrix */
		virtual const Matrix& getMatrix() const;

		/** Get the current width of this object */
		const float getWidth() const;
		/** Get the current height of this object */
		const float getHeight() const;

		/** Notify this object about its parent DisplayObjectContainer */
		void setParentContainer(DisplayObjectContainer* parent);

		/** Get the local bounding box of this object */
		virtual const BoundingBox& getBoundingBox() const = 0;
		/** Check if a global point is located inside the boundaries of this object */
		virtual bool isPointInside(const Vector2& coord) = 0;

		/** Get the calculated world Matrix of this object */
		const Matrix& getWorldMatrix();
		/** Get the calculated world BoundingBox of this object */
		const BoundingBox& getWorldBoundingBox();

		/** Inform the object that the color transformation needs to be updated */
		void needColorUpdate();
		/** Inform the object that the matrix needs to be updated */
		void needMatrixUpdate();

		/** Method to update all contents of this object */
		virtual void _update(const float& delta_time = 0.0f);

		/** Get the Transform that is associated with this object */
		Transform& getTransform();

	protected:
		Transform mTransform;
		DisplayObjectContainer* mParentContainer;
	};
}

#endif
