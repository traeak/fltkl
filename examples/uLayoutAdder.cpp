//
//  -$RCSfile: uLayoutAdder.cpp,v $
//  $Revision: 1.2 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 05:03:24 $
//
//  Copyright (c) 2010 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

/*! \file
\brief This file defines the unit tests for fltk::LayoutAdder.
*/

#include "libfltkl/LayoutAdder.h"

#include "libfltkl/LayoutHorz.h"
#include "libfltkl/LayoutSpace.h"

#include <fltk/Widget.h>

#include <iostream>
#include <sstream>

namespace
{

std::string
fltklLayoutAdder_test1
	()
{
	// Use for outputting errors
	std::ostringstream oss;

// ExampleStart

	fltkl::LayoutLinear * const layout
		( fltkl::LayoutAdder(new fltkl::LayoutHorz)
			[new fltkl::LayoutSpace]
			(new fltk::Widget(0, 0, 0, 0, "test"))
			[new fltkl::LayoutSpace] );

	// Short usage example code here
	std::vector<fltk::Widget*> widgets;
	layout->widgets(&widgets);

// ExampleEnd

	// Conditional checking
	if (widgets.size() != 1)
	{
		oss << "bad number of widgets" << std::endl;
	}
	else
	if (std::string(widgets.front()->label()) != "test")
	{
		oss << "bad widget label" << std::endl;
	}

	delete layout;

	return oss.str();
}

/*
std::string
fltklLayoutAdder_test2
	()
{
	// Use for outputting errors
	std::ostringstream oss;

	return oss.str();
}
*/

}

//
// main
//
int
main
	()
{
	std::string const results(fltklLayoutAdder_test1());
	if (! results.empty())
	{
		std::cerr << results;
		return 1;
	}
	return 0;
}
