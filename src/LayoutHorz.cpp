// 
//  -$RCSfile: LayoutHorz.cpp,v $
//  $Revision: 1.9 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#include "libfltkl/LayoutHorz.h"

#include <algorithm>

//
// constructor
//
fltkl::LayoutHorz :: LayoutHorz
	()
{
}

//
// destructor
//
fltkl::LayoutHorz :: ~LayoutHorz
	()
{
}

//
// initialHighWide
//
std::pair<int, int>
fltkl::LayoutHorz :: initialHighWide
	( int const & spacing
	) const
{
	std::pair<int, int> highWide(0, 0);

	if (! theLayouts.empty())
	{
		int const totalSpace(spacing * (theLayouts.size() - 1));
		highWide.second = totalSpace;

		for (std::vector<Layout*>::const_iterator
			itl(theLayouts.begin()) ; itl != theLayouts.end() ; ++itl)
		{
			Layout const * const layout = *itl;
			std::pair<int, int> const subHighWide
				(layout->initialHighWide(spacing));

			// take height from highest item
			highWide.first = std::max(highWide.first, subHighWide.first);

			highWide.second += subHighWide.second;
		}
	}

	return highWide;
}

//
// layout
//
void
fltkl::LayoutHorz :: layout
	( fltk::Rectangle const & newRect
	, int const & space
	, int const & layout_damage
	)
{
	if (! theLayouts.empty())
	{
		// collect linear elements to be laid out (wides)
		std::vector<int> wides;
		wides.reserve(theLayouts.size());

		// collect children wides
		for (std::vector<Layout*>::const_iterator
			itl(theLayouts.begin()) ; itl != theLayouts.end() ; ++itl)
		{
			Layout * const layout = *itl;
			std::pair<int, int> const childHighWide
				(layout->initialHighWide(space));
			wides.push_back(childHighWide.second);
		}

		// calculate each child's relative begin/end
		std::vector<std::pair<int, int> > const childBeginEnds
			(childBeginEndsFor(wides, newRect.w(), space));

		// recompute wides
		std::vector<Layout*>::const_iterator
			itl(theLayouts.begin());
		std::vector<std::pair<int, int> >::const_iterator
			itcbe(childBeginEnds.begin());

		while (itl != theLayouts.end() && itcbe != childBeginEnds.end())
		{
			Layout * const layout = *itl++;
			std::pair<int, int> const & beginEnd = *itcbe++;

			// new rectangle
			fltk::Rectangle const childRect
				( newRect.x() + beginEnd.first
				, newRect.y()
				, beginEnd.second - beginEnd.first
				, newRect.h() );

			layout->layout(childRect, space, layout_damage);
		}
	}
}
