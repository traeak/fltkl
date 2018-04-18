// 
//  -$RCSfile: LayoutVert.cpp,v $
//  $Revision: 1.8 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#include "libfltkl/LayoutVert.h"

#include <algorithm>

//
// constructor
//
fltkl::LayoutVert :: LayoutVert
	()
{
}

//
// destructor
//
fltkl::LayoutVert :: ~LayoutVert
	()
{
}

//
// initialHighWide
//
std::pair<int, int>
fltkl::LayoutVert :: initialHighWide
	( int const & spacing
	) const
{
	std::pair<int, int> highWide(0, 0);

	if (!theLayouts.empty())
	{
		int const totalSpace(spacing * (theLayouts.size() - 1));
		highWide.first = totalSpace;

		for (std::vector<Layout*>::const_iterator
			itl(theLayouts.begin()) ; itl != theLayouts.end() ; ++itl)
		{
			Layout const * const layout = *itl;
			std::pair<int, int> const subHighWide
				(layout->initialHighWide(spacing));

			highWide.first += subHighWide.first;

			// take width from widest item
			highWide.second = std::max(highWide.second, subHighWide.second);
		}
	}

	return highWide;
}

//
// layout
//
void
fltkl::LayoutVert :: layout
	( fltk::Rectangle const & newRect
	, int const & space
	, int const & layout_damage
	)
{
	if (! theLayouts.empty())
	{
		// collect linear elements to be laid out (highs)
		std::vector<int> highs;
		highs.reserve(theLayouts.size());

		for (std::vector<Layout*>::const_iterator
			itl(theLayouts.begin()) ; itl != theLayouts.end() ; ++itl)
		{
			Layout * const layout = *itl;
			std::pair<int, int> const childHighWide
				(layout->initialHighWide(space));
			highs.push_back(childHighWide.first);
		}

		// calculate each child's relative begin/end
		std::vector<std::pair<int, int> > const childBeginEnds
			(childBeginEndsFor(highs, newRect.h(), space));

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
				( newRect.x()
				, newRect.y() + beginEnd.first
				, newRect.w()
				, beginEnd.second - beginEnd.first );

			layout->layout(childRect, space, layout_damage);
		}
	}
}
