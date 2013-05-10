set(
	CEGUI_API_VERSION
	"0"
)

if(
	CEGUI_USE_STATIC_LIBS
)
	set(
		CEGUI_BASE_LIB_NAME
		"CEGUIBase_Static"
	)

	set(
		CEGUI_DEFINITIONS
		"-D CEGUI_STATIC"
	)
else()
	set(
		CEGUI_BASE_LIB_NAME
		"CEGUIBase"
	)
endif()


find_path(
	CEGUI_INCLUDE_DIR
	NAMES CEGUI/Element.h
	PATHS /usr/include/cegui-${CEGUI_API_VERSION}
	HINTS ${CEGUI_INCLUDEDIR}
	NO_DEFAULT_PATH
)

find_library(
	CEGUI_LIBRARY
	NAMES "${CEGUI_BASE_LIB_NAME}-${CEGUI_API_VERSION}"
	HINTS ${CEGUI_LIBRARYDIR}
)

mark_as_advanced(
	CEGUI_INCLUDE_DIR
	CEGUI_LIBRARY_DIR
)

include(
	FindPackageHandleStandardArgs
)

set(
	CEGUI_INCLUDE_DIRS
	"${CEGUI_INCLUDE_DIR}"
)

set(
	CEGUI_LIBRARIES
	"${CEGUI_LIBRARY}"
)

find_package_handle_standard_args(
	CEGUI
	DEFAULT_MSG
	CEGUI_INCLUDE_DIR
	CEGUI_LIBRARY
)

get_filename_component(
	CEGUI_LIBRARY_DIRS
	${CEGUI_LIBRARY}
	PATH
)
