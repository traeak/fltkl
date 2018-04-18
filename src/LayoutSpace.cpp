// 
//  -$RCSfile: LayoutSpace.cpp,v $
//  $Revision: 1.4 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#include "libfltkl/LayoutSpace.h"

//
// constructor
//
fltkl::LayoutSpace :: LayoutSpace
	()
	: theInitHighWide(0, 0)
	, theHighWide(0, 0)
{
}

//
// constructor
//
fltkl::LayoutSpace :: LayoutSpace
	( int const & wide
	, int const & high
	)
	: theInitHighWide(high, wide)
	, theHighWide(high, wide)
{
}

//
// destructor
//
fltkl::LayoutSpace :: ~LayoutSpace
	()
{
}

//
// widgets
//
void
fltkl::LayoutSpace :: widgets
	( std::vector<fltk::Widget*> * const // widgets
	) const
{
}

//
// initialHighWide
//
std::pair<int, int>
fltkl::LayoutSpace :: initialHighWide
	( int const & // spacing
	) const
{
	return theInitHighWide;
}

//
// layout
//
void
fltkl::LayoutSpace :: layout
	( fltk::Rectangle const & newRect
	, int const & // space
	, int const & // layout_damage
	)
{
	theHighWide = std::make_pair(newRect.h(), newRect.w());
}
