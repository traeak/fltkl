// 
//  -$RCSfile: GroupStack.cpp,v $
//  $Revision: 1.5 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-05-20 23:03:18 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#include "libfltkl/GroupStack.h"

#include <fltk/damage.h>
#include <fltk/draw.h>
#include <fltk/events.h>
#include <fltk/layout.h>

#include <algorithm>
#include <iostream>

//
// constructor
//
fltkl::GroupStack :: GroupStack
	( int const & xpos
	, int const & ypos
	, int const & wide
	, int const & high
	, char const * label
	)
	: Group(xpos, ypos, wide, high, label)
{
}

//
// destructor
//
fltkl::GroupStack :: ~GroupStack
	()
{
}

//
// layout
//
void
fltkl::GroupStack :: layout
	()
{
	fltk::Widget::layout();
	if ((layout_damage() & (fltk::LAYOUT_WH|fltk::LAYOUT_DAMAGE)) != 0)
	{
		for (int index(0) ; index < children() ; ++index)
		{
			fltk::Widget * const wid(child(index));
			wid->w(w());
			wid->h(h());

			wid->layout_damage(layout_damage());
			wid->layout();
			wid->layout_damage(0);
		}

		layout_damage
			( layout_damage() & ~(fltk::LAYOUT_XYWH|fltk::LAYOUT_DAMAGE) );
	}

	Group::layout();
}

//
// resizeToContents
//
void
fltkl::GroupStack :: resizeToContents
	()
{
	int maxhigh(0);
	int maxwide(0);

	// gather the children geometry
	for (int index(0) ; index < children() ; ++index)
	{
		fltk::Widget const * const wid(child(index));
		maxhigh = std::max(maxhigh, wid->h());
		maxwide = std::max(maxwide, wid->w());
	}

	// resize the group stack
	resize(maxwide, maxhigh);

	// no resize the children to match
	for (int index(0) ; index < children() ; ++index)
	{
		fltk::Widget * const wid(child(index));
		wid->resize(maxwide, maxhigh);
	}
}
