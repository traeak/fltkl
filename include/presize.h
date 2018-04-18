// 
//  -$RCSfile: presize.h,v $
//  $Revision: 1.2 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2012-08-04 17:23:10 $
// 
// Copyright (c) 2007 Stellacore Corporation. All Rights Reserved.
// 
// #HEADER_NOTICE#
//

#ifndef    fltkl_presize_INCL_
#define    fltkl_presize_INCL_

/*! \file
\brief Declares classes belonging to fltkl namespace
*/

#include "libfltkl/fltkl.h"

#include <vector>

namespace fltk { class CheckButton; }
namespace fltk { class Choice; }
namespace fltk { class Input; }
namespace fltk { class Output; }
namespace fltk { class ProgressBar; }
namespace fltk { class ReturnButton; }
namespace fltk { class TextDisplay; }
namespace fltk { class ValueInput; }
namespace fltk { class Widget; }
namespace fltk { class Window; }

/*! \namespace fltkl presize.h
\brief Measurement capabilities for fltk widget types.

The returned rectangle is based on a 0, 0 origin.

The size of the widget itself is from rect.w() & rect.h()

The size & placement of the label is encoded in the
rect.x() & rect.y() coordinate values.

Example:

If the widget has a leading label (like a typical output line)
then the X coordinate of the Rectangle will be some positive
value with leading label having width of rect.x().

If the widget has a trailing label (like a typical check button)
then the X coordinate of the rectangle will be some negative value
with the trailing label having width of -rect.x()

*/
namespace fltkl
{

	/*! \brief Compute widget high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	void
	presize
		( fltk::Widget * const widget
		, int const & pad=padding
		);

	/*! \brief Compute return button high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	void
	presize
		( fltk::ReturnButton * const button
		, int const & pad=padding
		);

	/*! \brief Compute output high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	void
	presize
		( fltk::Output * const output
		, int const & pad=padding
		);

	/*! \brief Compute output high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	void
	presize
		( fltk::Choice * const choice
		, int const & pad=padding
		);

	/*! \brief Compute output high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	void
	presize
		( fltk::Input * const input
		, int const & pad=padding
		);

	/*! \brief Compute output high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	void
	presize
		( fltk::ValueInput * const input
		, int const & pad=padding
		);

	/*! \brief Compute output high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	void
	presize
		( fltk::CheckButton * const choice
		, int const & pad=padding
		);

	/*! \brief Compute output high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 */
	void
	presize
		( fltk::ProgressBar * const pbar
		, int const & pad=padding
		);

	/*! \brief Compute output high/wide based on current font.
	 * use fltk::setfont(Font*, float) before calling this.
	 * Note the display isn't const since grabbing the text
	 * may result in internal cache buffer changes.
	 */
	void
	presize
		( fltk::TextDisplay * const tdisplay
		, int const & pad=padding
		);

	/*! \brief presize to maximum width of given items
	 */
	void
	presizeToMaxWide
		( std::vector<fltk::Widget*> const & widgets
		);

	/*! \brief convenient widget vector aggregator.
    */
	template < int Reserve=0 >
	struct widgetvector
	{
		std::vector<fltk::Widget*> theVec;

		explicit
		widgetvector
			( fltk::Widget * const wid
			)
			: theVec()
		{
			if (0 < Reserve)
			{
				theVec.reserve(Reserve);
			}
			theVec.push_back(wid);
		}

		widgetvector &
		operator()
			( fltk::Widget * const wid
			)
		{
			theVec.push_back(wid);
			return *this;
		}

		operator std::vector<fltk::Widget*> const &
			() const
		{
			return theVec;
		}
	};

}

#endif //  fltkl_presize_INCL_
