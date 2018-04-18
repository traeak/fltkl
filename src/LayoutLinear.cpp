// 
//  -$RCSfile: LayoutLinear.cpp,v $
//  $Revision: 1.9 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#include "libfltkl/LayoutLinear.h"

#include "libfltkl/LayoutWidget.h"

#include <cassert>
#include <numeric>

//
// constructor
//
fltkl::LayoutLinear :: LayoutLinear
	()
	: theLayouts()
	, theResizables()
{
}

//
// destructor
//
fltkl::LayoutLinear :: ~LayoutLinear
	()
{
	for (std::vector<Layout*>::const_iterator
		itl(theLayouts.begin()) ; itl != theLayouts.end() ; ++itl)
	{
		delete *itl;
	}
}

//
// add
//
fltkl::LayoutLinear &
fltkl::LayoutLinear :: add
	( fltkl::Layout * const layout
	)
{
	theLayouts.push_back(layout);
	return *this;
}

//
// addResizable
//
fltkl::LayoutLinear &
fltkl::LayoutLinear :: addResizable
	( fltkl::Layout * const layout
	)
{
	add(layout);
	theResizables.insert(theLayouts.back());
	return *this;
}

//
// add
//
fltkl::LayoutLinear &
fltkl::LayoutLinear :: add
	( fltk::Widget * const widget
	)
{
	theLayouts.push_back(new LayoutWidget(widget));
	return *this;
}

//
// addResizable
//
fltkl::LayoutLinear &
fltkl::LayoutLinear :: addResizable
	( fltk::Widget * const widget
	)
{
	add(widget);
	theResizables.insert(theLayouts.back());
	return *this;
}

//
// widgets
//
void
fltkl::LayoutLinear :: widgets
	( std::vector<fltk::Widget*> * const managed
	) const
{
	for (std::vector<Layout*>::const_iterator
		itl(theLayouts.begin()) ; itl != theLayouts.end() ; ++itl)
	{
		(*itl)->widgets(managed);
	}
}

//#include "libio/stream.h"

//
// childBeginEndsFor
//
std::vector<std::pair<int, int> >
fltkl::LayoutLinear :: childBeginEndsFor
	( std::vector<int> const & childdims
	, int const & containerdim
	, int const & space
	) const
{
	std::vector<std::pair<int, int> > res;

assert(childdims.size() == theLayouts.size());
assert(! childdims.empty());

	res.reserve(childdims.size());

	// accumluate initial child dims
	int const childsum
		( std::accumulate
			(childdims.begin(), childdims.end(), 0) );

	int const numspaces(childdims.size() - 1);
	int const spacesum(numspaces * space);

	// important, here we assume inter space is "first class"
	int const mindim(childsum + spacesum);

	// how to redistribute
	int const extra(containerdim - mindim);

/*
if (theLayouts.size() == 7)
{
	io::err() << "containerdim: " << containerdim << std::endl;
	io::err() << "    childsum: " << childsum << std::endl;
	io::err() << "       space: " << space << std::endl;
}
*/

	// extra is shared among the resizables
	if (! theResizables.empty())
	{
		int const eachextra(extra / theResizables.size());

		// distribute early
		int leftover(extra % theResizables.size());
		int const sign((leftover < 0) ? -1 : 1);

		std::vector<Layout*>::const_iterator itl(theLayouts.begin());
		std::vector<int>::const_iterator itdim(childdims.begin());

		int pos(0);
		while ( itl != theLayouts.end() && itdim != childdims.end())
		{
			int const & childdim = *itdim++;
			Layout * const layout = *itl++;

			int newdim(childdim);
			if (theResizables.find(layout) != theResizables.end())
			{
				newdim += eachextra;
				if (leftover != 0)
				{
					newdim += sign;
					leftover -= sign;
				}
			}

			res.push_back(std::make_pair(pos, pos + newdim));
			pos += (newdim + space);
		}
	}
	else // extra shared by internal spaces
	if (1 < theLayouts.size())
	{
		int const spaceextra(extra / numspaces);
		int leftover(extra % numspaces);
		int const sign((leftover < 0) ? -1 : 1);

		int pos(0);
		for (std::vector<int>::const_iterator
			itdim(childdims.begin()) ; itdim != childdims.end() ; ++itdim)
		{
			int const & childdim = *itdim;

			res.push_back(std::make_pair(pos, pos + childdim));

			int newspace(space + spaceextra);
			if (leftover != 0)
			{
				newspace += sign;
				leftover -= sign;
			}

			pos += (childdim + newspace);
		}
	}

	return res;
}
