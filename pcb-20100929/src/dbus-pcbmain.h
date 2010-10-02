/*
 * PCB, an interactive printed circuit board editor
 * D-Bus IPC logic
 * Copyright (C) 2006 University of Cambridge
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef _DBUS_PCBMAIN_H_
#define _DBUS_PCBMAIN_H_

#define DBUS_API_SUBJECT_TO_CHANGE
#include <dbus/dbus.h>

void pcb_dbus_connection_setup_with_mainloop (DBusConnection * connection);
void pcb_dbus_connection_finish_with_mainloop (DBusConnection * connection);

#endif /* !_DBUS_PCBMAIN_H */
