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

#ifndef __vtxInstance_H__
#define __vtxInstance_H__

#include "vtxPrerequesites.h"
#include "vtxFactory.h"

namespace vtx
{
	//-----------------------------------------------------------------------
	class vtxExport Instance
	{
	public:
		Instance(Resource* resource);
		virtual ~Instance();

		const String& getID();
		virtual const String& getType() const = 0; // TODO: evtl. implement this in the base class, using Resource::getType()

		virtual void _setParent(Movie* parent);
		Movie* getParent() const;

		virtual void setScriptObject(ScriptObject* obj) = 0;
		virtual ScriptObject* getScriptObject() const = 0;

	protected:
		Movie* mParentMovie;
		Resource* mResource;
	};
	//-----------------------------------------------------------------------
	template<class T>
	class InstanceFactory : public Factory<T, Resource*> {};
	//-----------------------------------------------------------------------
}

#endif
