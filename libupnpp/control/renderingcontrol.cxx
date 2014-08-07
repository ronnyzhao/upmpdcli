/* Copyright (C) 2014 J.F.Dockes
 *       This program is free software; you can redistribute it and/or modify
 *       it under the terms of the GNU General Public License as published by
 *       the Free Software Foundation; either version 2 of the License, or
 *       (at your option) any later version.
 *
 *       This program is distributed in the hope that it will be useful,
 *       but WITHOUT ANY WARRANTY; without even the implied warranty of
 *       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *       GNU General Public License for more details.
 *
 *       You should have received a copy of the GNU General Public License
 *       along with this program; if not, write to the
 *       Free Software Foundation, Inc.,
 *       59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include <string>
using namespace std;

#include <upnp/upnp.h>

#include "libupnpp/soaphelp.hxx"
#include "libupnpp/log.hxx"
#include "libupnpp/control/renderingcontrol.hxx"

namespace UPnPClient {

const string 
RenderingControl::SType("urn:schemas-upnp-org:service:RenderingControl:1");

// We don't include a version in comparisons, as we are satisfied with
// version 1
bool RenderingControl::isRDCService(const string& st)
{
    const string::size_type sz(SType.size()-2);
    return !SType.compare(0, sz, st, 0, sz);
}



int RenderingControl::setVolume(int volume, const string& channel)
{
    SoapEncodeInput args(m_serviceType, "SetVolume");
    args("Channel", channel)("DesiredVolume", SoapEncodeInput::i2s(volume));
    SoapDecodeOutput data;
    int ret = runAction(args, data);
    if (ret != UPNP_E_SUCCESS) {
        return ret;
    }
    return 0;
}

int RenderingControl::getVolume(const string& channel)
{
    SoapEncodeInput args(m_serviceType, "GetVolume");
    args("Channel", channel);
    SoapDecodeOutput data;
    int ret = runAction(args, data);
    if (ret != UPNP_E_SUCCESS) {
        return ret;
    }
    int volume;
    if (!data.getInt("CurrentVolume", &volume)) {
        LOGERR("RenderingControl:getVolume: missing CurrentVolume in response" 
        << endl);
        return UPNP_E_BAD_RESPONSE;
    }
    return volume;
}










} // End namespace UPnPClient

