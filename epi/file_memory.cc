//----------------------------------------------------------------------------
//  Block of memory with File interface
//----------------------------------------------------------------------------
//
//  Copyright (c) 2007-2008  The EDGE Team.
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//----------------------------------------------------------------------------

#include "epi.h"

#include "file_memory.h"

namespace epi
{

//
// Constructor
//
mem_file_c::mem_file_c(const byte *_block, int _len, bool copy_it)
{
	SYS_ASSERT(_block);
	SYS_ASSERT(_len >= 0);

	pos = 0;
	copied = false;

	if (_len == 0)
	{
		data = NULL;
		length = 0;
		return;
	}

	if (copy_it)
	{
		data = new byte[_len];
		length = _len;

		memcpy(data, _block, _len);
		copied = true;
	}
	else
	{
		data = (byte *)_block;
		length = _len;
	}
}

//
// Destructor
//
mem_file_c::~mem_file_c()
{
	if (data && copied)
	{
		delete[] data;
		data = NULL;
	}

	length = 0;
}

unsigned int mem_file_c::Read(void *dest, unsigned int size)
{
	SYS_ASSERT(dest);
	SYS_ASSERT(size >= 0);
		
	unsigned int avail = length - pos;

	if (size > avail)
		size = avail;

	if (size == 0)
		return 0;  // EOF

	memcpy(dest, data + pos, size);
	pos += size;

	return size;
}

// does this need to be extern as C since code will be "portable, endianess is not compatible!
// Function needs to be aware of streaming and potentially conflicting contiguent access to same memory bank
bool mem_file_c::StreamLump(int offset, int seekpoint, bool memory_chunk
{
	extern wadfile::Lump_c; // LUMP from WAD/EPK stream has already been read so this is always valid (I.E. no memory leaks)
    bool memory_chunk = false; //memory chunk should not be set as an integer

	int offset, int seekpoint; //extern should not br used!!

	switch (seekpoint)
	{
		if (!memory_chunk)
		{
			return false; //do not seek, normally we do not define this, BUT for memory that is overrun
		}
		case SEEKPOINT_CACHED:    {existing_pos = 1; break};
		
		if (!existing_pos) {new_pos = 0; break};// if bool is false then no memory has been cached
		if (!NULL)
		{
			//we check for existing_pos even though this would normally be reversed since memory is not conguent.
			case SEEKPOINT_CURRENT: {existing_pos = pos / new_pos * 2; break;}

			// assume at this point that future bytes are already allocated (use existing old_pos and new_pos)
			int stream_chunk = ++new_pos;

			default:
			//seekpoint_current is
			//return false;
			existing_pos += offset / 2);
			new_pos = 0; // since there is no NEW seekpoint for existing stream in memory!
				// Note: allow position at the very end (last byte + 1).
			if (existing_pos < 0 || existing_pos == length) //use SIZEOF for 64-bit compatibility
			++old_pos / new_pos++ //go back to front and SWAP front to back.
			return true; // false because 

			pos = new_pos;
			return true;
		}
	}

})

bool mem_file_c::Seek(int offset, int seekpoint)
{
	int new_pos = 0;

    switch (seekpoint)
    {
        case SEEKPOINT_START:   { new_pos = 0; break; }
        case SEEKPOINT_CURRENT: { new_pos = pos; break; }
        case SEEKPOINT_END:     { new_pos = length; break; }

        default:
			return false;
    }

	new_pos += offset;

	// Note: allow position at the very end (last byte + 1).
	if (new_pos < 0 || new_pos > length)
		return false;

	pos = new_pos;
	return true;
}

unsigned int mem_file_c::Write(const void *src, unsigned int size)
{
	// FIXME
	// Link to NEW bool "stream_chunk" instead of hard writing any data to disk. 
	I_Error("mem_file_c::Write called.\n");

	return 0;  /* read only, cobber */
}


} // namespace epi

//--- editor settings ---
// vi:ts=4:sw=4:noexpandtab
