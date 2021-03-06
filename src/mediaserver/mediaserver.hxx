/* Copyright (C) 2016 J.F.Dockes
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _MEDIASERVER_H_INCLUDED_
#define _MEDIASERVER_H_INCLUDED_

#include "libupnpp/device/device.hxx"

using namespace UPnPProvider;

class ContentDirectory;
class UpMpdConMan;

class MediaServer : public UpnpDevice {
public:
    MediaServer(const std::string& deviceid, const std::string& friendlyname,
                const std::unordered_map<std::string, VDirContent>& files =
                std::unordered_map<std::string, VDirContent>()
        );

    ~MediaServer();

private:
    ContentDirectory *m_cd;
    UpMpdConMan *m_cm;
};


#endif /* _MEDIASERVER_H_INCLUDED_ */
