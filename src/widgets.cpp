//
//  -$RCSfile: widgets.cpp,v $
//  $Revision: 1.2 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2012-08-04 17:23:10 $
//
//  Copyright (c) 2007 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

/*! \file
\brief Definitions for fltkl::widgets
*/

// declaration include
#include "libfltkl/widgets.h"

#include "libfltkl/presize.h"

#include <fltk/Button.h>
#include <fltk/Widget.h>

namespace
{
	void
	buttonCallback
		( fltk::Widget * // wid
		, void * data
		)
	{
		fltk::Button * const button((fltk::Button*)data);
		button->value(! button->value());
		button->do_callback();
	}
}

//
// newLeadingLabel
//
fltk::Widget *
fltkl :: newLeadingLabel
	( char const * const label
	, fltk::Button * const attachTo
	)
{
	fltk::Widget * const wid(newLabel(label));
	wid->align(fltk::ALIGN_INSIDE|fltk::ALIGN_RIGHT);
	attachLabelToButton(wid, attachTo);
	return wid;
}

//
// newLeadingLabel
//
fltk::Widget *
fltkl :: newLeadingLabel
	( char const * const label
	, fltk::Widget * const attachTo
	)
{
	fltk::Widget * const wid(newLabel(label));
	wid->align(fltk::ALIGN_INSIDE|fltk::ALIGN_RIGHT);
	attachLabelToWidget(wid, attachTo);
	return wid;
}

//
// newLabel
//
fltk::Widget *
fltkl :: newLabel
	( char const * const label
	, fltk::Button * const attachTo
	)
{
	fltk::Button * const wid
		(new fltk::Button(0, 0, 0, 0, label));
	fltkl::presize(wid);
	wid->box(fltk::NO_BOX);
//	wid->align(fltk::ALIGN_INSIDE);
	wid->set_flag(fltk::TAB_TO_FOCUS, false);
	wid->set_flag(fltk::CLICK_TO_FOCUS, false);
	attachLabelToButton(wid, attachTo);
	return wid;
}

//
// newLabel
//
fltk::Widget *
fltkl :: newLabel
	( char const * const label
	, fltk::Widget * const attachTo
	)
{
	fltk::Button * const wid
		(new fltk::Button(0, 0, 0, 0, label));
	fltkl::presize(wid);
	wid->box(fltk::NO_BOX);
//	wid->align(fltk::ALIGN_INSIDE);
	wid->set_flag(fltk::TAB_TO_FOCUS, false);
	wid->set_flag(fltk::CLICK_TO_FOCUS, false);
	attachLabelToWidget(wid, attachTo);
	return wid;
}

//
// attachLabelToButton
//
void
fltkl :: attachLabelToButton
	( fltk::Widget * const label
	, fltk::Button * const to
	)
{
	if (to)
	{
		label->callback(buttonCallback, to);
		label->tooltip(to->tooltip());
	}
}

//
// attachLabelToWidget
//
void
fltkl :: attachLabelToWidget
	( fltk::Widget * const label
	, fltk::Widget * const to
	)
{
	if (to)
	{
		label->tooltip(to->tooltip());
	}
}
