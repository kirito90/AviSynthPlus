// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA, or visit
// http://www.gnu.org/copyleft/gpl.html .
//
// Linking Avisynth statically or dynamically with other modules is making a
// combined work based on Avisynth.  Thus, the terms and conditions of the GNU
// General Public License cover the whole combination.
//
// As a special exception, the copyright holders of Avisynth give you
// permission to link Avisynth with independent modules that communicate with
// Avisynth solely through the interfaces defined in avisynth.h, regardless of the license
// terms of these independent modules, and to copy and distribute the
// resulting combined work under terms of your choice, provided that
// every copy of the combined work is accompanied by a complete copy of
// the source code of Avisynth (the version of Avisynth used to produce the
// combined work), being distributed under the terms of the GNU General
// Public License plus this exception.  An independent module is a module
// which is not derived from or based on Avisynth, such as 3rd-party filters,
// import and export plugins, or graphical user interfaces.

#ifndef AVSCORE_STRINGS_H
#define AVSCORE_STRINGS_H

#include <string>
#include <memory>

bool streqi(const char* s1, const char* s2);
std::string concat(const std::string &s1, const std::string &s2);
bool replace_beginning(std::string &_haystack, const std::string &needle, const std::string &newStr);
bool replace(std::string &haystack, const std::string &needle, const std::string &newStr);
bool replace(std::string &haystack, char needle, char newChar);

std::unique_ptr<char[]> WideToMultiByte(int codePage, const wchar_t* src, int len);
std::unique_ptr<wchar_t[]> MultiByteToWide(int codePage, const char* src, int len);

#endif // AVSCORE_STRINGS_H
