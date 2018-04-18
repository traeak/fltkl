//
//  -$RCSfile: demoStack.cpp,v $
//  $Revision: 1.4 $
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
#include "libfltkl/GroupStack.h"
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

namespace
{
	void
	stackCallback
		( fltk::Widget * // wid
		, void * data
		)
	{
		fltkl::GroupStack * const gs((fltkl::GroupStack*)data);

		for (int index(0) ; index < gs->children() ; ++index)
		{
			fltk::Widget * const wid(gs->child(index));
			if (wid->visible())
			{
				wid->hide();
			}
			else
			{
				wid->show();
			}
		}
	}
}

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

	// NOTE: declaring both the buttons and the GroupStack on the
	// stack causes this test program to fault on exit.

	fltk::Button * const btnstack
		(new fltk::Button(0, 0, 0, 0, "toggle stack"));
	fltkl::presize(btnstack);

	fltk::Button * const btncenter
		(new fltk::Button(0, 0, 0, 0, "centered"));
	fltkl::presize(btncenter);

	fltk::Button * const btnleft
		(new fltk::Button(0, 0, 0, 0, "left"));
	fltkl::presize(btnleft);

	fltk::Button * const btnright
		(new fltk::Button(0, 0, 0, 0, "right"));
	fltkl::presize(btnright);

	fltkl::GroupLayout gs0(0, 0, 0, 0);
	gs0.setLayout( fltkl::LayoutAdder(new fltkl::LayoutHorz)
		[new fltkl::LayoutSpace]
		(btncenter)
		[new fltkl::LayoutSpace] );
	gs0.setSpacing(5);
//	gs0.setBorder(5);
	gs0.resizeToLayout();

	fltkl::GroupLayout gs1(0, 0, 0, 0);
	gs1.setLayout( fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(btnleft)
		[new fltkl::LayoutSpace]
		(btnright) );
	gs1.setSpacing(5);
//	gs1.setBorder(5);
	gs1.resizeToLayout();

	fltkl::GroupStack * const stack
		(new fltkl::GroupStack(0, 0, 0, 0));
	stack->add(gs0);
	stack->add(gs1);
	stack->resizeToContents();

	gs1.hide();

	btnstack->callback(stackCallback, stack);

	group.setLayout( fltkl::LayoutAdder(new fltkl::LayoutVert)
		(btnstack)
		[new fltkl::LayoutSpace]
		(stack) );

	group.setSpacing(5);
	group.setBorder(5);

	window.end();
	window.resizable(group);

	window.show();

// ExampleEnd

	return fltk::run();
}
