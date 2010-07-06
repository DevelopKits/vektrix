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
	import flash.display.IBitmapDrawable;
	import flash.events.EventDispatcher;
	
	[native(cls="::vtx::as3::DisplayObjectClass", instance="::vtx::as3::DisplayObject", methods="auto")]
	public class DisplayObject extends EventDispatcher implements IBitmapDrawable
	{
		public native function get x():Number;
		public native function set x(value:Number):void;
		
		public native function get y():Number;
		public native function set y(value:Number):void;
		
		public native function get rotation():Number;
		public native function set rotation(value:Number):void;
		
		public native function get scaleX():Number;
		public native function set scaleX(value:Number):void;
		
		public native function get scaleY():Number;
		public native function set scaleY(value:Number):void;
		
		public native function get width():Number;
		public native function set width(value:Number):void;
		
		public native function get height():Number;
		public native function set height(value:Number):void;
		
		public native function get visible():Boolean;
		public native function set visible(value:Boolean):void;
	}
}
