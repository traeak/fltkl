// 
//  -$RCSfile: Layout.h,v $
//  $Revision: 1.6 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2012-08-04 17:23:09 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_Layout_INCL_
#define fltkl_Layout_INCL_

#include <vector>

#include <fltk/Widget.h>

namespace fltkl
{

/*! \brief fltk Layout class.

A layout is added to a group to manage a set of equal priority child widgets.

Layouts may contain other layouts, or widgets, but not both.

Layouts only manage the memory associated with the sub layouts, not the
widgets.  That's the job of the Group.

Layouts may be nexted to accomodate more complex layouts.
Children may only belong to a single layout, not multiple layouts.

This design is inspired by Qt4's layout.

The layouts manage the memory associated with the nested widgets and children.

the items layed out are assumed to be packed.

*/

class Layout
{

	//! disable
	Layout(Layout const &);
	Layout & operator=(Layout const &);

public: // methods

	//! default constructor
	Layout
		()
	{ }

	//! destroys contained layouts, not widgets.
	virtual
	~Layout
		()
	{ }

	/*! \brief Recollect all contained widgets for the Group.
	 */
	virtual
	void
	widgets
		( std::vector<fltk::Widget*> * const widgets
		) const = 0;

	/*! \brief initial high/wide for children given interior spacing.
	 */
	virtual
	std::pair<int, int>
	initialHighWide
		( int const & spacing
		) const = 0;

	/*! \brief recursively relays out the widgets.
	 * Input rectangle is relative to the "Group" coordinates.
	 * Child should be assigned geometry relative to this group
	 * and appended to the list.
	 * Repositions/resizes children.
	 */
	virtual
	void
	layout
		( fltk::Rectangle const & newRect
		, int const & spacing
		, int const & layout_damage
		) = 0;

};

}

#endif // ! fltkl_Layout_INCL_
