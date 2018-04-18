// 
//  -$RCSfile: GroupLayout.h,v $
//  $Revision: 1.8 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_GroupLayout_INCL_
#define fltkl_GroupLayout_INCL_

#include <fltk/Group.h>

#include "libfltkl/Layout.h"

namespace fltkl
{
/*! \brief fltk GroupLayout class.

This GroupLayout class is inspired from Qt4's seemingly
orthogonal layout system.

A bunch of widgets belonging together are instantiated.
The widgets must be presized to their minimum/preferred size.

A Layout is created, widgets and nested Layouts are
added to this top level Layout.

A GroupLayout is then created, border spacing and adjacent widget
spacing is specified, then the Layout is assigned to the GroupLayout.

GroupLayout only overrides fltk::Group's layout and therefore is
able to live nicely with fltk.

\par Example
\dontinclude testfltk/demoLayout.cpp
\skip ExampleStart
\until ExampleEnd
*/

	//! A widget that consistes of other widgets and layouts
class GroupLayout : public fltk::Group
{

	GroupLayout(GroupLayout const & orig);
	GroupLayout & operator=(GroupLayout const & rhs);

public: // methods

	//! typical constructor
	explicit
	GroupLayout
		( int const & xpos
		, int const & ypos
		, int const & wide
		, int const & high
		, char const * label=0
		);

	//! typical virtual destructor -- destroys top layout & children
	virtual
	~GroupLayout
		();

	//! clears out the layout and the children
	void
	clear
		();

	//! sets the current layout.
	void
	setLayout
		( Layout * const layout
		);

	//! set internal spacing
	void
	setSpacing
		( int const & spacing
		);

	//! set border spacing
	void
	setBorder
		( int const & space
		);

	//! resize this group to given layout
	void
	resizeToLayout
		();

	//! relays out the children using current layout
	virtual
	void
	layout
		();

private: // data

	Layout * theLayout; //!< top level active layout
	int theBorder; //!< border space
	int theSpacing; //!< space between widgets

};

}

#endif // ! fltkl_GroupLayout_INCL_
