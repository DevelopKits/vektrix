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
#include "vtxswfTag.h"
#include "vtxswfTagDefineBitsLossless.h"
#include "vtxswfRecordColorMapData.h"
#include "vtxswfRecordBitmapData.h"

namespace vtx
{
	namespace swf
	{
		//-----------------------------------------------------------------------
		SwfTagDefineBitsLossless::SwfTagDefineBitsLossless(uint tag_length, uchar* tag_data)
			: SwfTag(TT_DefineBitsLossless, tag_length, tag_data)
			, mCharacterId(0)
			, mFormat(BF_8BIT_COLOR_MAPPED)
			, mWidth(0)
			, mHeight(0)
			, mZlibBitmapData(NULL)
		{}
		//-----------------------------------------------------------------------
		SwfTagDefineBitsLossless::~SwfTagDefineBitsLossless()
		{
			if(mZlibBitmapData)
			{
				delete mZlibBitmapData;
				mZlibBitmapData = NULL;
			}
		}
		//-----------------------------------------------------------------------
		void SwfTagDefineBitsLossless::ParseData(SwfParser* parser)
		{
			mCharacterId = mBlockReader.readUI16();
			mFormat = (BitmapFormat)mBlockReader.readUI8();
			mWidth = mBlockReader.readUI16();
			mHeight = mBlockReader.readUI16();
			short colorTableSize = 0;
			if (mFormat == BF_8BIT_COLOR_MAPPED)
			{
				colorTableSize = (short) (mBlockReader.readUI8() + 1);
			}
			int zLength = (int) (mTagLength - mBlockReader.getOffset());
			unsigned char* zBuf = new unsigned char[zLength];
			mBlockReader.readBytes(zLength, zBuf);
			MemoryBlockReader zBlock;
			zBlock.init(zBuf, zLength);
			zBlock.enableCompression();
			switch (mFormat)
			{
			case BF_8BIT_COLOR_MAPPED:
				mZlibBitmapData = new SwfRecordColorMapData(zBlock, colorTableSize, mWidth, mHeight);
				break;
			case BF_15BIT_RGB:
			case BF_24BIT_RGB:
				mZlibBitmapData = new SwfRecordBitmapData(zBlock, mFormat, mWidth, mHeight);
				break;
			default:
				VTX_DEBUG_FAIL("Unknown bitmap format!");
			}
			delete[] zBuf;
		}
		//-----------------------------------------------------------------------
	}
}
