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

#ifndef __vtxas3EventDispatcher_H__
#define __vtxas3EventDispatcher_H__

#include "cspPrerequesites.h"
#include "cspClientObject.h"

#include "vtxScriptObject.h"

namespace vtx
{
	namespace as3
	{
		//-----------------------------------------------------------------------
		class EventDispatcherClass : public avmplus::ClassClosure
		{
		public:
			EventDispatcherClass(avmplus::VTable* cvtable);
			virtual ~EventDispatcherClass(){}

			avmplus::ScriptObject* createInstance(avmplus::VTable* ivtable, avmplus::ScriptObject* prototype);

			DECLARE_SLOTS_EventDispatcherClass;
		};
		//-----------------------------------------------------------------------
		class EventDispatcher : public avmplus::ScriptObject, public ScriptObject, public csp::ClientObject
		{
		public:
			typedef std::vector<avmplus::FunctionObject*> FunctionList;
			typedef std::map<String, FunctionList> FunctionMap;

			EventDispatcher(avmplus::VTable* vtable, avmplus::ScriptObject* prototype);
			virtual ~EventDispatcher(){}

			// AS3 functions
			void addEventListener(avmplus::Stringp type, avmplus::FunctionObject* function, bool useCapture, int priority, bool useWeakReference);
			bool dispatchEvent(as3::Event* event);
			bool hasEventListener(avmplus::Stringp type);
			void removeEventListener(avmplus::Stringp type, avmplus::FunctionObject* function, bool useWeakReference);
			virtual bool willTrigger(avmplus::Stringp type) { return false; }

			virtual void eventFired(const vtx::Event& evt);

			virtual vtx::ScriptObject* _createChildObject(const String& name);

			DECLARE_SLOTS_EventDispatcher;

		protected:
			FunctionMap mHandlers;
		};
		//-----------------------------------------------------------------------
	}
}

#endif
