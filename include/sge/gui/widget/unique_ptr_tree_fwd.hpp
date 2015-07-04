#ifndef SGE_GUI_WIDGET_UNIQUE_PTR_TREE_FWD_HPP_INCLUDED
#define SGE_GUI_WIDGET_UNIQUE_PTR_TREE_FWD_HPP_INCLUDED

#include <sge/gui/widget/unique_ptr.hpp>
#include <fcppt/container/tree/object_fwd.hpp>


namespace sge
{
namespace gui
{
namespace widget
{

typedef
fcppt::container::tree::object<
	sge::gui::widget::unique_ptr
>
unique_ptr_tree;

}
}
}

#endif