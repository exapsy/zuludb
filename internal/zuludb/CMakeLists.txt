set(
	SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/filer/record.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/filer/database.cpp
)

set(
	HEADERS
	${HEADERS}
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/filer/filer.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/filer/record.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/filer/database.hpp
)

add_library(InternalZuluDB ${SOURCE} ${HEADERS})
