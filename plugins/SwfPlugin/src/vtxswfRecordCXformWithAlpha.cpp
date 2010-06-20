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
#include "vtxswfRecordCXformWithAlpha.h"

namespace vtx
{
	namespace swf
	{
		//-----------------------------------------------------------------------
		SwfRecordCXformWithAlpha::SwfRecordCXformWithAlpha()
			: mRedMultTerm(255)
			, mGreenMultTerm(255)
			, mBlueMultTerm(255)
			, mAlphaMultTerm(255)
			, mRedAddTerm(0)
			, mGreenAddTerm(0)
			, mBlueAddTerm(0)
			, mAlphaAddTerm(0)
			, mHasAddTerms(false)
			, mHasMultTerms(false)
		{}
		//-----------------------------------------------------------------------
		SwfRecordCXformWithAlpha::SwfRecordCXformWithAlpha(MemoryBlockReader& memoryReader)
			: mRedMultTerm(255)
			, mGreenMultTerm(255)
			, mBlueMultTerm(255)
			, mAlphaMultTerm(255)
			, mRedAddTerm(0)
			, mGreenAddTerm(0)
			, mBlueAddTerm(0)
			, mAlphaAddTerm(0)
			, mHasAddTerms(false)
			, mHasMultTerms(false)
		{
			mHasAddTerms	= memoryReader.readBooleanBit();
			mHasMultTerms	= memoryReader.readBooleanBit();
			int nBits		= (int)memoryReader.readUnsignedBits(4);
			if (mHasMultTerms)
			{
				mRedMultTerm	= (int)memoryReader.readSignedBits(nBits);
				mGreenMultTerm	= (int)memoryReader.readSignedBits(nBits);
				mBlueMultTerm	= (int)memoryReader.readSignedBits(nBits);
				mAlphaMultTerm	= (int)memoryReader.readSignedBits(nBits);
			}
			if (mHasAddTerms)
			{
				mRedAddTerm		= (int)memoryReader.readSignedBits(nBits);
				mGreenAddTerm	= (int)memoryReader.readSignedBits(nBits);
				mBlueAddTerm	= (int)memoryReader.readSignedBits(nBits);
				mAlphaAddTerm	= (int)memoryReader.readSignedBits(nBits);
			}
			memoryReader.align();
		}
		//-----------------------------------------------------------------------
		SwfRecordCXformWithAlpha::~SwfRecordCXformWithAlpha()
		{}
		//-----------------------------------------------------------------------
	}
}
