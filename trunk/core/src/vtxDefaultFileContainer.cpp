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

#include "vtxDefaultFileContainer.h"

#include "vtxDefaultFileStream.h"
#include "vtxFileHelper.h"
#include "vtxLogManager.h"

namespace vtx
{
	//-----------------------------------------------------------------------
	const String DefaultFileContainer::FACTORY_NAME = "DefaultFileContainer";
	//-----------------------------------------------------------------------
	DefaultFileContainer::DefaultFileContainer(const String& location) 
		: mLocation(location)
	{
		if(!FileHelper::doesDirectoryExist(mLocation))
		{
			VTX_EXCEPT("The FileContainer '%s' does not exist!", location.c_str());
		}

		if(mLocation.substr(mLocation.length()-1, 1) != "/")
		{
			mLocation += "/";
		}
	}
	//-----------------------------------------------------------------------
	DefaultFileContainer::~DefaultFileContainer()
	{

	}
	//-----------------------------------------------------------------------
	FileStream* DefaultFileContainer::openFile(const String& filename)
	{
		return (FileStream*)new DefaultFileStream(mLocation, filename);
	}
	//-----------------------------------------------------------------------
	bool DefaultFileContainer::hasFile(const String& filename)
	{
		if(!filename.length())
		{
			return false;
		}

		return FileHelper::doesFileExist(mLocation + filename);
	}
	//-----------------------------------------------------------------------
}