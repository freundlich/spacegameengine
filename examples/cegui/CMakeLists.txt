add_sge_example(
	cegui/text_demo
	SGE_DEPS
		sgecegui
		sgeconfig
		sgeimagecolor
		sgeinput
		sgelog
		sgemedia_interface
		sgerenderer
		sgesystems
		sgetimer_interface
		sgeviewport
		sgewindow
	ADDITIONAL_DEPS
		${fcppt_core_TARGET}
		fcppt_log_interface
		${FCPPT_UTILS_FILESYSTEM_LIBRARIES}
)
