/* Copyright (c) 2013, The Linux Foundataion. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __QCAMERA_THERMAL_ADAPTER__
#define __QCAMERA_THERMAL_ADAPTER__

namespace qcamera {

class QCameraThermalCallback
{
public:
    virtual int thermalEvtHandle(char *name, int threshold,
                                    int level) = 0;
    virtual ~QCameraThermalCallback() {}
};

class QCameraThermalAdapter
{
public:
    static QCameraThermalAdapter& getInstance();

    int init(QCameraThermalCallback *thermalCb);
    void deinit();

private:
    static char mStrCamera[];
    static char mStrCamcorder[];

    static int thermalCallback(char *name, int threshold, int level);

    QCameraThermalCallback *mCallback;
    void *mHandle;
    int (*mRegister)(char *name, int (*callback)(char *, int, int), void *data);
    int (*mUnregister)(char *name);

    QCameraThermalAdapter();
    QCameraThermalAdapter(QCameraThermalAdapter const& copy); // not implemented
    QCameraThermalAdapter& operator=(QCameraThermalAdapter const& copy); // not implemented

};

}; // namespace qcamera

#endif /* __QCAMERA_THERMAL_ADAPTER__ */
