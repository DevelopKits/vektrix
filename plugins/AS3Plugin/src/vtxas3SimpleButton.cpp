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

#include "flash_package.h"

#include "vtxButton.h"

#include "cspInternalCore.h"
#include "cspVmCore.h"
#include "cspScriptObject.h"

namespace vtx
{
	namespace as3
	{
		//-----------------------------------------------------------------------
		SimpleButtonClass::SimpleButtonClass(avmplus::VTable* cvtable) 
			: ClassClosure(cvtable)
		{
			AvmAssert(traits()->getSizeOfInstance() == sizeof(SimpleButtonClass));
			createVanillaPrototype();
		}
		//-----------------------------------------------------------------------
		avmplus::ScriptObject* SimpleButtonClass::createInstance(avmplus::VTable* ivtable, avmplus::ScriptObject* prototype)
		{
			return new (core()->GetGC(), ivtable->getExtraSize()) SimpleButton(ivtable, prototype);
		}
		//-----------------------------------------------------------------------
		SimpleButton::SimpleButton(avmplus::VTable* vtable, avmplus::ScriptObject* prototype) 
			: InteractiveObject(vtable, prototype)
		{

		}
		//-----------------------------------------------------------------------
		SimpleButton::~SimpleButton()
		{
			delete getCaspinObject();
		}
		//-----------------------------------------------------------------------
		void SimpleButton::setNativeObject(Instance* inst)
		{
			mButton = dynamic_cast<vtx::Button*>(inst);
		}
		//-----------------------------------------------------------------------
		void SimpleButton::buttonUp()
		{
			csp::VmCore* core = getCaspinCore();
			csp::ScriptObject* object = getCaspinObject();

			if(core && object)
			{
				csp::ArgumentList args;
				args.push_back(core->newString("click"));
				args.push_back(core->newBoolean(false));
				args.push_back(core->newBoolean(true));

				csp::ScriptObject* evt = core->createObject("MouseEvent", "flash.events", args);
				args.clear();
				args.push_back(evt->atom());

				object->callFunction("dispatchEvent", args);

				delete evt;
			}
		}
		//-----------------------------------------------------------------------
		double SimpleButton::get_x()
		{
			if(mButton)
			{
				return mButton->getX();
			}

			return 0;
		}
		//-----------------------------------------------------------------------
		void SimpleButton::set_x(double val)
		{
			if(mButton)
			{
				mButton->setX((float)val);
			}
		}
		//-----------------------------------------------------------------------
		double SimpleButton::get_y()
		{
			if(mButton)
			{
				return mButton->getY();
			}

			return 0;
		}
		//-----------------------------------------------------------------------
		void SimpleButton::set_y(double val)
		{
			if(mButton)
			{
				mButton->setY((float)val);
			}
		}
		//-----------------------------------------------------------------------
		double SimpleButton::get_rotation()
		{
			if(mButton)
			{
				return mButton->getAngle();
			}

			return 0;
		}
		//-----------------------------------------------------------------------
		void SimpleButton::set_rotation(double val)
		{
			if(mButton)
			{
				mButton->setAngle((float)val);
			}
		}
		//-----------------------------------------------------------------------
		vtx::ScriptObject* SimpleButton::_createChildObject(const String& name)
		{
			csp::ScriptObject* parent_obj = csp::ScriptObject::fromAvmplus(this);
			if(parent_obj)
			{
				csp::ScriptObject* slot_obj = parent_obj->createSlotObject(name);
				if(slot_obj)
				{
					return dynamic_cast<vtx::ScriptObject*>(slot_obj->scriptObj());
				}
			}

			return NULL;
		}
		//-----------------------------------------------------------------------
	}
}
