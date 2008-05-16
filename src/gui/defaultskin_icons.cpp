/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2007  Simon Stienen (s.stienen@slashlife.org)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <sge/gui/defaultskin.hpp>

sge::gui::dim2 sge::gui::defaultskin::icon_size() const { return dim2(11,11); }

namespace {

template<unsigned A, unsigned C=11, unsigned D=0> struct bits {
	static const unsigned value =
		bits<A/8, C-1, (D<<1) | (A&1)>::value;
};

template<unsigned A, unsigned D> struct bits<A, 0, D> {
	static const unsigned value = D;
};

}

const unsigned sge::gui::defaultskin::icons[][11] = {
	{ // none
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // empty
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ // left
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000010000U>::value,
		bits<000000110000U>::value,
		bits<000001110000U>::value,
		bits<000000110000U>::value,
		bits<000000010000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // leftmost
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000010010000U>::value,
		bits<000010110000U>::value,
		bits<000011110000U>::value,
		bits<000010110000U>::value,
		bits<000010010000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // left_double
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000100100U>::value,
		bits<000001101100U>::value,
		bits<000011111100U>::value,
		bits<000001101100U>::value,
		bits<000000100100U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // leftmost_double
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000100100100U>::value,
		bits<000101101100U>::value,
		bits<000111111100U>::value,
		bits<000101101100U>::value,
		bits<000100100100U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ // right
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000001000000U>::value,
		bits<000001100000U>::value,
		bits<000001110000U>::value,
		bits<000001100000U>::value,
		bits<000001000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // rightmost
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000010010000U>::value,
		bits<000011010000U>::value,
		bits<000011110000U>::value,
		bits<000011010000U>::value,
		bits<000010010000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // right_double
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000010010000U>::value,
		bits<000011011000U>::value,
		bits<000011111100U>::value,
		bits<000011011000U>::value,
		bits<000010010000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // rightmost_double
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000100100100U>::value,
		bits<000110110100U>::value,
		bits<000111111100U>::value,
		bits<000110110100U>::value,
		bits<000100100100U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ // up
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // upmost
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // up_double
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // upmost_double
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ // down
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // downmost
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // down_double
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // downmost_double
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ // updown
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // updownmost
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
		bits<000011111000U>::value,
		bits<000000000000U>::value,
	},

	{ // leftright
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000001010000U>::value,
		bits<000011011000U>::value,
		bits<000111011100U>::value,
		bits<000011011000U>::value,
		bits<000001010000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // leftrightmost
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<001001010010U>::value,
		bits<001011011010U>::value,
		bits<001111011110U>::value,
		bits<001011011010U>::value,
		bits<001001010010U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ // fourway
		bits<000000100000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000100100100U>::value,
		bits<001100100110U>::value,
		bits<011111111111U>::value,
		bits<001100100110U>::value,
		bits<000100100100U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000100000U>::value,
	},

	{ // ellipsis
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000110110110U>::value,
		bits<000110110110U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ // minimize
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000111111000U>::value,
		bits<000111111000U>::value,
		bits<000000000000U>::value,
	},
	{ // restore
		bits<000000000000U>::value,
		bits<000011111100U>::value,
		bits<000011111100U>::value,
		bits<000010000100U>::value,
		bits<001111110100U>::value,
		bits<001111110100U>::value,
		bits<001000011100U>::value,
		bits<001000010000U>::value,
		bits<001000010000U>::value,
		bits<001111110000U>::value,
		bits<000000000000U>::value,
	},
	{ // maximize
		bits<000000000000U>::value,
		bits<001111111110U>::value,
		bits<001111111110U>::value,
		bits<001000000010U>::value,
		bits<001000000010U>::value,
		bits<001000000010U>::value,
		bits<001000000010U>::value,
		bits<001000000010U>::value,
		bits<001000000010U>::value,
		bits<001111111110U>::value,
		bits<000000000000U>::value,
	},
	{ // close
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000110000110U>::value,
		bits<000011001100U>::value,
		bits<000001111000U>::value,
		bits<000000110000U>::value,
		bits<000001111000U>::value,
		bits<000011001100U>::value,
		bits<000110000110U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ // back
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<001000000100U>::value,
		bits<001000011100U>::value,
		bits<001001111100U>::value,
		bits<001111111100U>::value,
		bits<001001111100U>::value,
		bits<001000011100U>::value,
		bits<001000000100U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // rewind
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000001000100U>::value,
		bits<000011001100U>::value,
		bits<000111011100U>::value,
		bits<001111111100U>::value,
		bits<000111011100U>::value,
		bits<000011001100U>::value,
		bits<000001000100U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // stop
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000111111100U>::value,
		bits<000111111100U>::value,
		bits<000111111100U>::value,
		bits<000111111100U>::value,
		bits<000111111100U>::value,
		bits<000111111100U>::value,
		bits<000111111100U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // pause
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000110001100U>::value,
		bits<000110001100U>::value,
		bits<000110001100U>::value,
		bits<000110001100U>::value,
		bits<000110001100U>::value,
		bits<000110001100U>::value,
		bits<000110001100U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // play
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000100000000U>::value,
		bits<000111000000U>::value,
		bits<000111110000U>::value,
		bits<000111111100U>::value,
		bits<000111110000U>::value,
		bits<000111000000U>::value,
		bits<000100000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // play_reversed
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000100U>::value,
		bits<000000011100U>::value,
		bits<000001111100U>::value,
		bits<000111111100U>::value,
		bits<000001111100U>::value,
		bits<000000011100U>::value,
		bits<000000000100U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // record
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000001110000U>::value,
		bits<000011111000U>::value,
		bits<000111111100U>::value,
		bits<000111111100U>::value,
		bits<000111111100U>::value,
		bits<000011111000U>::value,
		bits<000001110000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // fast_fwd
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<001000100000U>::value,
		bits<001100110000U>::value,
		bits<001110111000U>::value,
		bits<001111111100U>::value,
		bits<001110111000U>::value,
		bits<001100110000U>::value,
		bits<001000100000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},
	{ // forward
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	},

	{ //
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
		bits<000000000000U>::value,
	}
};
