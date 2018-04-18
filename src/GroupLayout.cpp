// 
//  -$RCSfile: GroupLayout.cpp,v $
//  $Revision: 1.9 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-04-30 13:57:48 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#include "libfltkl/GroupLayout.h"

#include <fltk/damage.h>
#include <fltk/draw.h>
#include <fltk/events.h>
#include <fltk/layout.h>

#include <algorithm>
#include <iostream>

//
// constructor
//
fltkl::GroupLayout :: GroupLayout
	( int const & xpos
	, int const & ypos
	, int const & wide
	, int const & high
	, char const * label
	)
	: fltk::Group(xpos, ypos, wide, high, label)
	, theLayout(0)
	, theBorder(0)
	, theSpacing(0)
{
}

//
// destructor
//
fltkl::GroupLayout :: ~GroupLayout
	()
{
	clear();
}

//
// clear
//
void
fltkl::GroupLayout :: clear
	()
{
	if (theLayout)
	{
		delete theLayout;
		theLayout = 0;
	}
}

//
// setLayout
//
void
fltkl::GroupLayout :: setLayout
	( fltkl::Layout * const layout
	)
{
	if (! layout)
	{
		clear();
	}
	else
	if (theLayout != layout)
	{
		theLayout = layout;

		remove_all();

		std::vector<fltk::Widget*> newChildren;
		theLayout->widgets(&newChildren);

		// add children that weren't in layout
		for (std::vector<fltk::Widget*>::const_iterator
			itc(newChildren.begin()) ; itc != newChildren.end() ; ++itc)
		{
			fltk::Widget * const wid = *itc;
			add(wid);
		}
	}
}

//
// setSpacing
//
void
fltkl::GroupLayout :: setSpacing
	( int const & spacing
	)
{
	if (theSpacing != spacing)
	{
		theSpacing = spacing;
	}
}

//
// setBorder
//
void
fltkl::GroupLayout :: setBorder
	( int const & spacing
	)
{
	if (theBorder != spacing)
	{
		theBorder = spacing;
	}
}

//
// resizeToLayout
//
void
fltkl::GroupLayout :: resizeToLayout
	()
{
	std::pair<int, int> highWide(0, 0);

	if (theLayout)
	{
		highWide = theLayout->initialHighWide(theSpacing);
		highWide.first += 2 * theBorder;
		highWide.second += 2 * theBorder;
	}

	resize(highWide.second, highWide.first);
}

//
// layout
//
void
fltkl::GroupLayout :: layout
	()
{
	if (theLayout)
	{
		if (layout_damage() & (fltk::LAYOUT_WH|fltk::LAYOUT_DAMAGE))
		{
			fltk::Rectangle const borderRect
				(theBorder, theBorder, w() - 2 * theBorder, h() - 2 * theBorder);
			theLayout->layout(borderRect, theSpacing, layout_damage());
		}

		layout_damage
			( layout_damage() & ~(fltk::LAYOUT_XYWH|fltk::LAYOUT_DAMAGE) );
	}

	fltk::Group::layout();
}
