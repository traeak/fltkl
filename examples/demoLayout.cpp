//
//  -$RCSfile: demoLayout.cpp,v $
//  $Revision: 1.12 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2012-08-04 17:23:10 $
//
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

/*! \file
\brief  This file contains main application program APPNAME
*/

#include "libfltkl/GroupLayout.h"
#include "libfltkl/LayoutAdder.h"
#include "libfltkl/LayoutHorz.h"
#include "libfltkl/LayoutVert.h"
#include "libfltkl/LayoutWidget.h"
#include "libfltkl/LayoutSpace.h"
#include "libfltkl/presize.h"

#include <fltk/Button.h>
#include <fltk/InvisibleBox.h>
#include <fltk/Window.h>
#include <fltk/run.h>

#include <cassert>
#include <iostream>

//! Main program that demos fltk layout stuff
int
main
	( int const // argc
	, char const * const * const // argv
	)
{
// ExampleStart

	fltk::Window window(250, 100);
	window.begin();

	fltkl::GroupLayout group(0, 0, window.w(), window.h());

	// embossed box
	fltkl::GroupLayout embossed(0, 0, 0, 0);
	embossed.box(fltk::EMBOSSED_BOX);

	// button inside embossed box
	fltk::Button another(0, 0, 0, 0, "biteme");
	fltkl::presize(&another);

	embossed.setLayout(new fltkl::LayoutWidget(&another));
	embossed.setSpacing(5);
	embossed.setBorder(5);

	// two buttons
	fltk::Button btn0(0, 0, 0, 0, "btn0");
	fltkl::presize(&btn0);
	fltk::Button btn1(0, 0, 0, 0, "btn1");
	fltkl::presize(&btn1);

	// embossed box has a singleton widget that resizes with the box

	fltkl::LayoutVert * const mainLayout(new fltkl::LayoutVert);

	mainLayout->addResizable(&embossed);
	mainLayout->add(fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(&btn0)
		[new fltkl::LayoutSpace] // resizable
		(&btn1) );

	group.setLayout(mainLayout);
	group.setSpacing(5);
	group.setBorder(5);

	window.end();
	window.resizable(group);

	window.show();

// ExampleEnd

	return fltk::run();
}
