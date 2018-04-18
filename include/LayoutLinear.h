// 
//  -$RCSfile: LayoutLinear.h,v $
//  $Revision: 1.9 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_LayoutLinear_INCL_
#define fltkl_LayoutLinear_INCL_

#include "libfltkl/Layout.h"

#include <set>
#include <vector>

namespace fltkl
{

/*! \brief fltk Linear Layout class.

Linear layout with multiple resizable support.

Two cases:

\li resizables -- space distributed to layouts.
\li no resizables -- space is distributed to inter layout spacing.

*/

class LayoutLinear : public Layout
{

	LayoutLinear(LayoutLinear const & orig);
	LayoutLinear & operator=(LayoutLinear const & rhs);

public: // methods

	//! default null constructor
	LayoutLinear
		();

	//! destroys any sub layouts and all their children
	virtual
	~LayoutLinear
		();

	//! append sub layout
	LayoutLinear &
	add
		( Layout * const layout
		);

	//! append a resizable sub layout
	LayoutLinear &
	addResizable
		( Layout * const layout
		);

	//! append widget -- convenience function
	LayoutLinear &
	add
		( fltk::Widget * const widget
		);

	//! append resizable widget -- convenience function
	LayoutLinear &
	addResizable
		( fltk::Widget * const widget
		);

public: // virtual

	/*! \brief collects all contained widgets for the Group.
	 */
	virtual
	void
	widgets
		( std::vector<fltk::Widget*> * const managed
		) const;

	/*! \brief initial high/wide of children with given spacing.
	 */
	virtual
	std::pair<int, int>
	initialHighWide
		( int const & spacing
		) const = 0;

	/*! \brief recursively relays out the widgets.
	 * Repositions/resizes children.
	 */
	virtual
	void
	layout
		( fltk::Rectangle const & rect
		, int const & spacing
		, int const & layout_damage
		) = 0;

protected: // methods

	//! calculate child beg/end positions for given axis values
	std::vector<std::pair<int, int> >
	childBeginEndsFor
		( std::vector<int> const & childdims
			//!< initial dim from children
		, int const & containerdim
			//!< full size of container for children to fit into
		, int const & spacedim
			//!< requested internal space between children
		) const;

protected: // data

	std::vector<Layout*> theLayouts; //!< child layouts
	std::set<Layout*> theResizables; //!< the resizable layout (may be null)

};

}

#endif // ! fltkl_LayoutLinear_INCL_
