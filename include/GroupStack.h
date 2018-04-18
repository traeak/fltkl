// 
//  -$RCSfile: GroupStack.h,v $
//  $Revision: 1.3 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_GroupStack_INCL_
#define fltkl_GroupStack_INCL_

#include <fltk/Group.h>

namespace fltkl
{
/*! \brief fltk GroupStack class.

This GroupStack class is inspired from Qt4's seemingly
orthogonal layout system.

A bunch of widgets belonging together are instantiated.
The widgets must be presized to their minimum/preferred size.

A Layout is created, widgets and nested Layouts are
added to this top level Layout.

A GroupStack is then created, border spacing and adjacent widget
spacing is specified, then the Layout is assigned to the GroupStack.

GroupStack only overrides fltk::Group's layout and therefore is
able to live nicely with fltk.

\par Example
\dontinclude testfltk/demoLayout.cpp
\skip ExampleStart
\until ExampleEnd
*/

//! A widget that consistes of other widgets and layouts
class GroupStack : public fltk::Group
{

	GroupStack(GroupStack const & orig);
	GroupStack & operator=(GroupStack const & rhs);

public: // methods

	//! typical constructor
	explicit
	GroupStack
		( int const & xpos
		, int const & ypos
		, int const & wide
		, int const & high
		, char const * label=0
		);

	//! typical virtual destructor -- destroys top layout & children
	virtual
	~GroupStack
		();

	//! relays out the children using current layout
	virtual
	void
	layout
		();

	//! resize this group to contents (largest)
	void
	resizeToContents
		();

};

}

#endif // ! fltkl_GroupStack_INCL_
