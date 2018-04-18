// 
//  -$RCSfile: widgets.h,v $
//  $Revision: 1.2 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2012-08-04 17:23:10 $
// 
// Copyright (c) 2010 Stellacore Corporation. All Rights Reserved.
// 
// #HEADER_NOTICE#
//

#ifndef    fltklwidgets_INCL_
#define    fltklwidgets_INCL_

/*! \file
\brief Declares classes belonging to fltkl namespace
*/

namespace fltk { class Button; }
namespace fltk { class Widget; }

/*! \namespace fltkl widgets.h
\brief The fltkl/widgets module provides label utilities
*/

namespace fltkl
{

	/*! \brief create a configured new leading label.
	 * The label is interior right aligned
	 * this is really a button in disguise.
	 */
	fltk::Widget *
	newLeadingLabel
		( char const * const label
		, fltk::Button * const attachTo
		);

	/*! \brief create a configured new leading label.
	 * The label is interior right aligned
	 */
	fltk::Widget *
	newLeadingLabel
		( char const * const label
		, fltk::Widget * const attachTo = 0
		);

	/*! \brief create a configured label.
	 * clicking on the label activates the button.
	 * the label inherits the button's tooltip (if any).
	 */
	fltk::Widget *
	newLabel
		( char const * const label
		, fltk::Button * const attachTo
		);

	/*! \brief create a configured label.
	 * the label will inherit the tooltip of the widget attached to.
	 */
	fltk::Widget *
	newLabel
		( char const * const label
		, fltk::Widget * const attachTo = 0
		);

	/*! \brief attach a general label to a button.
	 * clicking on the label will pass its callback onto the button.
	 * also inherits the button's tooltip
	 */
	void
	attachLabelToButton
		( fltk::Widget * const label
		, fltk::Button * const to
		);

	/*! \brief attach a general label to a widget.
	 * This causes the label inherit the tooltip.
	 */
	void
	attachLabelToWidget
		( fltk::Widget * const label
		, fltk::Widget * const to
		);

}

#endif //  fltklwidgets_INCL_
