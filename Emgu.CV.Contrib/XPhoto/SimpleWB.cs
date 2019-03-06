//----------------------------------------------------------------------------
//  Copyright (C) 2004-2019 by EMGU Corporation. All rights reserved.       
//----------------------------------------------------------------------------

using System;
using System.Runtime.InteropServices;
using System.Drawing;
using Emgu.CV.CvEnum;
using Emgu.Util;

namespace Emgu.CV.XPhoto
{

    /// <summary>
    /// A simple white balance algorithm that works by independently stretching each of the input image channels to the specified range. For increased robustness it ignores the top and bottom p% of pixel values.
    /// </summary>
    public partial class SimpleWB : WhiteBalancer
    {
        private IntPtr _sharedPtr;

        /// <summary>
        /// Creates a simple white balancer
        /// </summary>
        public SimpleWB()
        {
            _ptr = XPhotoInvoke.cveSimpleWBCreate(ref _whiteBalancerPtr, ref _sharedPtr);
        }

        /// <summary>
        /// Release all the unmanaged memory associated with this white balancer
        /// </summary>
        protected override void DisposeObject()
        {
            if (_ptr != IntPtr.Zero)
            {
                XPhotoInvoke.cveSimpleWBRelease(ref _ptr, ref _sharedPtr);
            }
            base.DisposeObject();
        }
    }
}