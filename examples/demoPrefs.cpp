//
//  -$RCSfile: demoPrefs.cpp,v $
//  $Revision: 1.3 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2012-09-14 19:01:20 $
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
#include "libfltkl/LayoutSpace.h"
#include "libfltkl/presize.h"
#include "libfltkl/widgets.h"

#include <fltk/CheckButton.h>
#include <fltk/Choice.h>
#include <fltk/IntInput.h>
#include <fltk/Item.h>
#include <fltk/RadioButton.h>
#include <fltk/run.h>
#include <fltk/Slider.h>
#include <fltk/ValueInput.h>
#include <fltk/Window.h>

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

	fltk::Window window(640, 480);

	fltkl::GroupLayout * const group
		(new fltkl::GroupLayout(10, 10, window.w() - 20, window.h() - 20));
	group->box(fltk::DOWN_BOX);

	fltk::Widget * const genLabel
		(fltkl::newLeadingLabel("General"));
	fltkl::GroupLayout * const groupgen
		(new fltkl::GroupLayout(0, 0, window.w(), window.h()));
	groupgen->box(fltk::ENGRAVED_BOX);

	{
		fltk::CheckButton * const backgroundCheck
			(new fltk::CheckButton(0, 0, 0, 0));
		fltkl::presize(backgroundCheck);
		backgroundCheck->tooltip("Enable for rotated images with large ...");
		fltk::Widget * const backgroundLabel
			(fltkl::newLabel
				("Images with Large Background Areas", backgroundCheck));

		fltk::IntInput * const gridInput(new fltk::IntInput(0, 0, 0, 0));
		gridInput->value(50);
		fltkl::presize(gridInput);
		fltk::Widget * const gridLabel
			(fltkl::newLeadingLabel("Sampling GridSize", gridInput));

		fltkl::LayoutLinear * const mainLayout(new fltkl::LayoutVert);
		mainLayout->add(fltkl::LayoutAdder(new fltkl::LayoutHorz)
			(backgroundCheck)(backgroundLabel)[new fltkl::LayoutSpace]);
		mainLayout->add(fltkl::LayoutAdder(new fltkl::LayoutHorz)
			(gridLabel)[gridInput]);
		groupgen->setLayout(mainLayout);
		groupgen->setSpacing(fltkl::padding);
		groupgen->setBorder(fltkl::padding);

		groupgen->resizeToLayout();
	}

	fltk::Widget * const methodLabel
		(fltkl::newLeadingLabel("Correction Method"));
	fltkl::GroupLayout * const groupmethod
		(new fltkl::GroupLayout(0, 0, window.w(), window.h()));
	groupmethod->box(fltk::ENGRAVED_BOX);

	{
		fltk::RadioButton * const addCheck
			(new fltk::RadioButton(0, 0, 0, 0));
		fltkl::presize(addCheck);
		fltk::Widget * const addLabel
			(fltkl::newLabel("Additive", addCheck));

		fltk::RadioButton * const multCheck
			(new fltk::RadioButton(0, 0, 0, 0));
		fltkl::presize(multCheck);
		fltk::Widget * const multLabel
			(fltkl::newLabel("Multiplicative", multCheck));

		fltk::CheckButton * const colorCheck
			(new fltk::CheckButton(0, 0, 0, 0));
		fltkl::presize(colorCheck);
		fltk::Widget * const colorLabel
			(fltkl::newLabel("Apply Color Correction", colorCheck));

		fltk::ValueInput * const iterInput
			(new fltk::ValueInput(0, 0, 0, 0));
		iterInput->value(20);
		fltkl::presize(iterInput);
		fltk::Widget * const iterLabel
			(fltkl::newLabel("Maximum Iterations", iterInput));

		fltkl::LayoutLinear * const mainLayout(new fltkl::LayoutVert);
		mainLayout->add(fltkl::LayoutAdder(new fltkl::LayoutHorz)
			(addCheck)(addLabel)[new fltkl::LayoutSpace]);
		mainLayout->add(fltkl::LayoutAdder(new fltkl::LayoutHorz)
			(multCheck)(multLabel)[new fltkl::LayoutSpace](iterLabel)(iterInput));
		mainLayout->add(fltkl::LayoutAdder(new fltkl::LayoutHorz)
			(colorCheck)(colorLabel)[new fltkl::LayoutSpace]);

		groupmethod->setLayout(mainLayout);
		groupmethod->setSpacing(fltkl::padding);
		groupmethod->setBorder(fltkl::padding);

		groupmethod->resizeToLayout();
	}

	// perform the layout
	fltkl::LayoutLinear * const mainLayout(new fltkl::LayoutVert);

	/*
	mainLayout->add( fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(slideLabel)
		[&delay] );
	mainLayout->add( fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(optionsLabel)
		(&firstSlideCheck)
		(firstSlideLabel)
		[new fltkl::LayoutSpace] );
	mainLayout->add( fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(spaceLabel)
		(&randomOrderCheck)
		(randomOrderLabel)
		[new fltkl::LayoutSpace] );
	mainLayout->add( fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(spaceLabel)
		(&repeatSlidesCheck)
		(repeatSlidesLabel)
		[new fltkl::LayoutSpace] );
	mainLayout->add( fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(windowSizeLabel)
		(&sizeChoice)
		(&wideInput)
		(xlabel)
		(&highInput)
		[new fltkl::LayoutSpace] );
	*/
	mainLayout->add(fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(genLabel)[new fltkl::LayoutSpace]);
	mainLayout->add(groupgen);
	mainLayout->add(fltkl::LayoutAdder(new fltkl::LayoutHorz)
		(methodLabel)[new fltkl::LayoutSpace]);
	mainLayout->add(groupmethod);
	mainLayout->addResizable(new fltkl::LayoutSpace);

	group->setLayout(mainLayout);
//	group->setSpacing(fltkl::padding);
	group->setBorder(fltkl::padding);

	window.add(group);
	window.resizable(group);

	window.show();

// ExampleEnd

	return fltk::run();
}
