// 
//  -$RCSfile: LayoutAdder.h,v $
//  $Revision: 1.3 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_LayoutAdder_INCL_
#define fltkl_LayoutAdder_INCL_

#include "libfltkl/LayoutLinear.h"

namespace fltkl
{

/*! \brief fltk Horz Layout class.
Simple linear layout with a single resizable.
*/

class LayoutAdder
{

	LayoutAdder(LayoutAdder const & orig);
	LayoutAdder & operator=(LayoutAdder const & rhs);

public: // methods

	//! default null constructor
	explicit
	LayoutAdder
		( LayoutLinear * const layout
		)
		: theLayout(layout)
	{
	}

	//! return pointer to the accumulated layout
	operator
	LayoutLinear *
		() const
	{
		return theLayout;
	}

	//! operator to add non resizable layout
	LayoutAdder &
	operator()
		( Layout * const layout
		)
	{
		theLayout->add(layout);
		return *this;
	}

	//! operator to add resizable layout
	LayoutAdder &
	operator[]
		( Layout * const layout
		)
	{
		theLayout->addResizable(layout);
		return *this;
	}

	//! operator to add non resizable layout
	LayoutAdder &
	operator()
		( fltk::Widget * const widget
		)
	{
		theLayout->add(widget);
		return *this;
	}

	//! operator to add resizable layout
	LayoutAdder &
	operator[]
		( fltk::Widget * const widget
		)
	{
		theLayout->addResizable(widget);
		return *this;
	}

private: // data

	LayoutLinear * const theLayout;

};

}

#endif // ! fltkl_LayoutAdder_INCL_
