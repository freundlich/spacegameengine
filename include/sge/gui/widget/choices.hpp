#ifndef SGE_GUI_WIDGET_CHOICES_HPP_INCLUDED
#define SGE_GUI_WIDGET_CHOICES_HPP_INCLUDED

#include <sge/gui/context_fwd.hpp>
#include <sge/gui/index_callback.hpp>
#include <sge/gui/index_function.hpp>
#include <sge/gui/optional_index.hpp>
#include <sge/gui/string_container.hpp>
#include <sge/gui/detail/symbol.hpp>
#include <sge/gui/style/base_fwd.hpp>
#include <sge/gui/widget/box_container.hpp>
#include <sge/gui/widget/button.hpp>
#include <sge/gui/widget/choices_fwd.hpp>
#include <sge/gui/widget/text.hpp>
#include <sge/font/object_fwd.hpp>
#include <sge/renderer/device/ffp_fwd.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/scoped_connection.hpp>


namespace sge
{
namespace gui
{
namespace widget
{

class choices
:
	public sge::gui::widget::box_container
{
public:
	SGE_GUI_DETAIL_SYMBOL
	choices(
		sge::gui::context &,
		sge::gui::style::base const &,
		sge::renderer::device::ffp &,
		sge::font::object &,
		sge::gui::string_container const &,
		sge::gui::optional_index
	);

	SGE_GUI_DETAIL_SYMBOL
	~choices()
	override;

	SGE_GUI_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	change(
		sge::gui::index_callback const &
	);

	SGE_GUI_DETAIL_SYMBOL
	sge::gui::optional_index const
	index() const;
private:
	void
	left_clicked();

	void
	right_clicked();

	template<
		typename Func
	>
	void
	update_index(
		Func const &
	);

	sge::gui::string_container const strings_;

	sge::gui::widget::button left_button_;

	sge::gui::widget::text middle_text_;

	sge::gui::widget::button right_button_;

	sge::gui::optional_index index_;

	fcppt::signal::scoped_connection const left_connection_;

	fcppt::signal::scoped_connection const right_connection_;

	typedef
	fcppt::signal::object<
		sge::gui::index_function
	>
	index_signal;

	index_signal index_changed_;
};

}
}
}

#endif
