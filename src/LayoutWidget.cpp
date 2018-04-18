// 
//  -$RCSfile: LayoutWidget.cpp,v $
//  $Revision: 1.8 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#include "libfltkl/LayoutWidget.h"

#include <fltk/layout.h>
#include <cassert>

//
// constructor
//
fltkl::LayoutWidget :: LayoutWidget
	( fltk::Widget * widget
	)
	: theWidget(widget)
	, theInitHighWide(widget->h(), widget->w())
{
}

//
// destructor
//
fltkl::LayoutWidget :: ~LayoutWidget
	()
{
}

//
// widgets
//
void
fltkl::LayoutWidget :: widgets
	( std::vector<fltk::Widget*> * const widgets
	) const
{
	assert(theWidget);
	widgets->push_back(theWidget);
}

//
// initialHighWide
//
std::pair<int, int>
fltkl::LayoutWidget :: initialHighWide
	( int const & // spacing
	) const
{
	return theInitHighWide;
}

//
// layout
//
void
fltkl::LayoutWidget :: layout
	( fltk::Rectangle const & newRect
	, int const & // space
	, int const & layout_damage
	)
{
	assert(theWidget);
	theWidget->resize(newRect.x(), newRect.y(), newRect.w(), newRect.h());

//	if (theWidget->is_group())
	{
		theWidget->layout_damage(layout_damage | fltk::LAYOUT_XY);
		theWidget->layout();
		theWidget->layout_damage();
	}
}
