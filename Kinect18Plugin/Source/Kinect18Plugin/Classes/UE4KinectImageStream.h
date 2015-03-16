//-----------------------------------------------------------
// 
// UDKinectImageStream.h
//
// Copyright (c) 2012 UE4Kinect1, Charlie Hodara
//
// This file is released under the MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining 
// a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation 
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions: 
// The above copyright notice and this permission notice shall be 
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR 
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
// CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION 
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
//
//-----------------------------------------------------------

#ifndef __UDKINECT_IMAGE_STREAM_H__
#define __UDKINECT_IMAGE_STREAM_H__

#include "UDKInectFundamental.h"
#include "UDKinectPreviewWindow.h"
#include <vector>

namespace UE4Kinect1
{
	class ImageStream
	{
	public:
		ImageStream();
		virtual ~ImageStream();

		int		getWidth() const { return m_Width; }
		int		getHeight() const { return m_Height; }

		HANDLE	getFrameEvent() const { return m_hFrameEvent; }

		bool	processNextFrame( INuiSensor* pNuiInstance );

		RGBQUAD* getFrameBuffer() { return &m_FrameBuffer[0]; }

		void	showPreviewWindow( bool bShow );

	protected:
		int m_Width;
		int m_Height;

		HANDLE m_hFrameEvent;
		HANDLE m_pStreamHandle;

		PreviewWindow m_PreviewWindow;

		std::vector<RGBQUAD> m_FrameBuffer;

		virtual bool processImageFrame( const NUI_IMAGE_FRAME& imageFrame ) =0;
	};
} // namespace UE4Kinect1

#endif // __UDKINECT_IMAGE_STREAM_H__
