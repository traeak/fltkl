// 
//  -$RCSfile: fltkl.h,v $
//  $Revision: 1.2 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2012-08-04 17:23:09 $
// 
// Copyright (c) 2007 Stellacore Corporation. All Rights Reserved.
// 
// #HEADER_NOTICE#
//

#ifndef    fltkl_INCL_
#define    fltkl_INCL_

/*! \file
\brief Declares classes belonging to fltkl namespace
*/

#include <fltk/Rectangle.h>

namespace fltk { class Widget; }
namespace fltk { class Window; }

/*! \namespace fltkl fltkl.h
\brief The fltkl module provides tools built around fltk2

*/
namespace fltkl
{
	//! item padding
	static int const padding(5);
		//!< between widget padding

	static int const tabHigh(25);
		//!< high of tab bar

	static int const barHigh(30);
		//!< dim of menu/status bar

	static int const textHigh(25);
		//!< high of single line text field

	static int const scrollHigh(20);
		//!< dim of menu/status bar

	/*! \brief Compute text high/wide based on current font.
	 * Also uses the built in "label()" method to compute
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	fltk::Rectangle
	measure
		( char const * const utfstring
		, int const & pad=padding
		);

	/*! \brief Compute widget high/wide based on current font.
	 * Also uses the built in "label()" method to compute
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	fltk::Rectangle
	measure
		( fltk::Widget const * const widget
		, int const & pad=padding
		);

	/*! \brief convenience function to exec a dialog
	 */
	void
	exec
		( fltk::Window * const window
		);

}

#endif //  fltkl_INCL_
