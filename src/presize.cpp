//
//  -$RCSfile: presize.cpp,v $
//  $Revision: 1.4 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2012-08-04 17:23:09 $
//
//  Copyright (c) 2007 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

/*! \file
\brief Definitions for fltkl::fltkl
*/

// declaration include
#include "libfltkl/presize.h"

#include "libmath/math.h"

#include <fltk/CheckButton.h>
#include <fltk/Choice.h>
#include <fltk/events.h>
#include <fltk/Monitor.h>
#include <fltk/Output.h>
#include <fltk/ProgressBar.h>
#include <fltk/ReturnButton.h>
#include <fltk/TextBuffer.h>
#include <fltk/TextDisplay.h>
#include <fltk/ValueInput.h>
#include <fltk/Window.h>

#include <algorithm>
#include <cmath>
#include <sstream>

//
// presize
//
void
fltkl :: presize
	( fltk::Widget * const widget
	, int const & padding
	)
{
	fltk::Rectangle rect(measure(widget, padding));

	widget->resize(rect.w(), rect.h());
}

//
// returnButtonHighWide
//
void
fltkl :: presize
	( fltk::ReturnButton * const retbtn
	, int const & padding
	)
{
	fltk::Rectangle rect;

	rect = measure(retbtn, padding);
	rect.w(rect.w() + retbtn->textsize() * 2);

	retbtn->resize(rect.w(), rect.h());
}

//
// presize
//
void
fltkl :: presize
	( fltk::Output * const output
	, int const & padding
	)
{
	fltk::Rectangle rect;

	fltk::Rectangle const valuerect
		(measure(output->value(), padding));

	fltk::Rectangle const labelrect(measure(output, padding));

	rect = valuerect;

	// label is typically to the LEFT of the widget
	rect.x(labelrect.w());

	output->resize(rect.w(), rect.h());
}

//
// presize
//
void
fltkl :: presize
	( fltk::CheckButton * const button
	, int const & padding
	)
{
	fltk::Rectangle rect;

	// the glyph is the whole widget itself (fltk::
	fltk::Rectangle const glyphrect
		( button->textsize() + 2 + 2 * padding
		, button->textsize() + 2 + 2 * padding );

	// label is added on
	fltk::Rectangle const labelrect(measure(button, padding));

	// widget is placed based on glyph
	rect = glyphrect;

	// text is maybe taller than glyph
	rect.h(std::max(rect.h(), labelrect.h()));

	// label is typically placed to the right of widget
	rect.x(-labelrect.w());

	int const wide(rect.w() + math::abs(rect.x()));

	button->resize(wide, rect.h());
}

//
// presize
//
void
fltkl :: presize
	( fltk::Choice * const choice
	, int const & padding
	)
{
	fltk::Rectangle rect;

	// the choice stack + glyph is the widget itself
	fltk::Rectangle choicerect(0, 0, 0, 0);
	for (int index(0) ; index < choice->children() ; ++index)
	{
		fltk::Rectangle const itemrect
			(measure(choice->child(index), padding));
		choicerect.w(std::max(choicerect.w(), itemrect.w()));
		choicerect.h(std::max(choicerect.h(), itemrect.h()));
	}

	// sizing code taken from fltk::Choice::draw
	rect = choicerect;
//	rect.w(rect.w() + rect.h() * 4 / 5);
	rect.w(rect.w() + rect.h());

	// label is added on
	fltk::Rectangle const labelrect(measure(choice, padding));

	// text is maybe taller than glyph
	rect.h(std::max(rect.h(), labelrect.h()));

	// label is typically placed to the LEFT of widget
	rect.x(labelrect.w());

	choice->resize(rect.w(), rect.h());
}

//
// presize
//
void
fltkl :: presize
	( fltk::Input * const input
	, int const & padding
	)
{
	fltk::Rectangle rect;

	// sizing code taken from fltk::ValueInput::draw -- choice is square
	rect = measure(input->text(), padding);
	rect.w(rect.w() + rect.h());

	// label is added on
	fltk::Rectangle const labelrect(measure(input, padding));

	// text is maybe taller than glyph
	rect.h(std::max(rect.h(), labelrect.h()));

	// label is typically placed to the LEFT of widget
	rect.x(labelrect.w());

	input->resize(rect.w(), rect.h());
}

//
// presize
//
void
fltkl :: presize
	( fltk::ValueInput * const input
	, int const & padding
	)
{
	fltk::Rectangle rect;

	// the choice stack + glyph is the widget itself
	std::ostringstream oss;
	oss << input->value();
	std::string const valstr(oss.str());

	// sizing code taken from fltk::ValueInput::draw -- choice is square
	rect = measure(valstr.c_str(), padding);
	rect.w(rect.w() + rect.h());

	// label is added on
	fltk::Rectangle const labelrect(measure(input, padding));

	// text is maybe taller than glyph
	rect.h(std::max(rect.h(), labelrect.h()));

	// label is typically placed to the LEFT of widget
	rect.x(labelrect.w());

	input->resize(rect.w(), rect.h());
}

//
// presize
//
void
fltkl :: presize
	( fltk::ProgressBar * const pbar
	, int const & padding
	)
{
	fltk::Rectangle rect;

	fltk::Rectangle const valuerect(measure("100%", padding));

	fltk::Rectangle const labelrect(measure(pbar, padding));

	rect = valuerect;

	// label is typically to the LEFT of the widget
	rect.x(labelrect.w());

	pbar->resize(rect.w(), rect.h());
}

//
// presize
//
void
fltkl :: presize
	( fltk::TextDisplay * const tdisplay
	, int const & padding
	)
{
	fltk::Rectangle const rect
		(measure(tdisplay->buffer()->text(), padding));
	tdisplay->resize(rect.w(), rect.h());
}

//
// presizeToMaxWide
//
void
fltkl :: presizeToMaxWide
	( std::vector<fltk::Widget*> const & widgets
	)
{
	int maxwide(0);

	for (std::vector<fltk::Widget*>::const_iterator
		itw(widgets.begin()) ; itw != widgets.end(); ++itw)
	{
		fltk::Widget const * const wid = *itw;
		maxwide = std::max(maxwide, wid->w());
	}

	for (std::vector<fltk::Widget*>::const_iterator
		itw(widgets.begin()) ; itw != widgets.end(); ++itw)
	{
		fltk::Widget * const wid = *itw;
		wid->w(maxwide);
	}
}
