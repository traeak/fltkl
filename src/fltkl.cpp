//
//  -$RCSfile: fltkl.cpp,v $
//  $Revision: 1.1 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
//
//  Copyright (c) 2007 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

/*! \file
\brief Definitions for fltkl::fltkl
*/

// declaration include
#include "libfltkl/fltkl.h"

#include <fltk/events.h>
#include <fltk/run.h>
#include <fltk/Window.h>

#include <cstring>

//
// measure
//
fltk::Rectangle
fltkl :: measure
	( char const * const utfstring
	, int const & padding
	)
{
	fltk::Rectangle rect;

	if ((0 != utfstring) && 0 < strlen(utfstring))
	{
		fltk::Widget widget(0, 0, 0, 0, utfstring);
		int wide, high;
		widget.measure_label(wide, high);
		rect = fltk::Rectangle
			( padding + wide + padding
			, padding + high + padding );
	}
	else
	{
		rect = fltk::Rectangle(0, 0);
	}

	return rect;
}

//
// measure
//
fltk::Rectangle
fltkl :: measure
	( fltk::Widget const * const widget
	, int const & padding
	)
{
	fltk::Rectangle rect(measure(widget->label(), padding));

	if ( 0 == rect.h() && 0 == rect.w()
		&& widget->image() != 0)
	{
		rect = fltk::Rectangle(widget->w(), widget->h());
	}

	return rect;
}


//
// exec
//
void
fltkl :: exec
	( fltk::Window * const window
	)
{
	fltk::Widget * const oldModal(fltk::modal());
	fltk::modal(window);
	window->hotspot(window);
	window->show();
	while (window->visible())
	{
		fltk::wait();
	}
	fltk::modal(oldModal);
}
