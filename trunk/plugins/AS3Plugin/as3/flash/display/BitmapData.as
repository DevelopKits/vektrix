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

package flash.display
{
	import flash.filters.BitmapFilter;
	import flash.geom.ColorTransform;
	import flash.geom.Matrix;
	import flash.geom.Point;
	import flash.geom.Rectangle;
	import flash.utils.ByteArray;
	
	public class BitmapData
	{
		/* Constructor */
		public function BitmapData(width:int, height:int, transparent:Boolean = true, fillColor:uint = 0xFFFFFFFF) {}
		
		/* getters & setters */
		public function get height():int { return 0; }
		public function get rect():Rectangle { return null; }
		public function get transparent():Boolean { return false; }
		public function get width():int { return 0; }

		/* methods */
		public function applyFilter(sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, filter:BitmapFilter):void {}
		public function clone():BitmapData { return null; }
		public function colorTransform(rect:Rectangle, colorTransform:ColorTransform):void {}
		public function compare(otherBitmapData:BitmapData):Object { return null; }
		public function copyChannel(sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, sourceChannel:uint, destChannel:uint):void {}
		public function copyPixels(sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, alphaBitmapData:BitmapData = null, alphaPoint:Point = null, mergeAlpha:Boolean = false):void {}
		public function dispose():void {}
		public function draw(source:IBitmapDrawable, matrix:Matrix = null, colorTransform:ColorTransform = null, blendMode:String = null, clipRect:Rectangle = null, smoothing:Boolean = false):void {}
		public function fillRect(rect:Rectangle, color:uint):void {}
		public function floodFill(x:int, y:int, color:uint):void {}
		public function generateFilterRect(sourceRect:Rectangle, filter:BitmapFilter):Rectangle { return null; }
		public function getColorBoundsRect(mask:uint, color:uint, findColor:Boolean = true):Rectangle { return null; }
		public function getPixel(x:int, y:int):uint { return null; }
		public function getPixel32(x:int, y:int):uint { return null; }
		public function getPixels(rect:Rectangle):ByteArray { return null; }
		public function hitTest(firstPoint:Point, firstAlphaThreshold:uint, secondObject:Object, secondBitmapDataPoint:Point = null, secondAlphaThreshold:uint = 1):Boolean { return false; }
		public function lock():void {}
		public function merge(sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, redMultiplier:uint, greenMultiplier:uint, blueMultiplier:uint, alphaMultiplier:uint):void {}
		public function noise(randomSeed:int, low:uint = 0, high:uint = 255, channelOptions:uint = 7, grayScale:Boolean = false):void {}
		public function paletteMap(sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, redArray:Array = null, greenArray:Array = null, blueArray:Array = null, alphaArray:Array = null):void {}
		public function perlinNoise(baseX:Number, baseY:Number, numOctaves:uint, randomSeed:int, stitch:Boolean, fractalNoise:Boolean, channelOptions:uint = 7, grayScale:Boolean = false, offsets:Array = null):void {}
		public function pixelDissolve(sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, randomSeed:int = 0, numPixels:int = 0, fillColor:uint = 0):int { return 0; }
		public function scroll(x:int, y:int):void {}
		public function setPixel(x:int, y:int, color:uint):void {}
		public function setPixel32(x:int, y:int, color:uint):void {}
		public function setPixels(rect:Rectangle, inputByteArray:ByteArray):void {}
		public function threshold(sourceBitmapData:BitmapData, sourceRect:Rectangle, destPoint:Point, operation:String, threshold:uint, color:uint = 0, mask:uint = 0xFFFFFFFF, copySource:Boolean = false):uint { return null; }
		public function unlock(changeRect:Rectangle = null):void {}
	}
}
