cmake_minimum_required(VERSION 3.5)

project(picoc)


#########################################################################################
####### UNIX_HOST #########
add_executable (picoc_unix 
picoc.c table.c lex.c parse.c expression.c heap.c type.c variable.c clibrary.c platform.c include.c debug.c 
platform/platform_unix.c platform/library_unix.c 
cstdlib/stdio.c cstdlib/math.c cstdlib/string.c cstdlib/stdlib.c cstdlib/time.c cstdlib/errno.c cstdlib/ctype.c cstdlib/stdbool.c cstdlib/unistd.c)
target_link_libraries(picoc_unix m readline)
target_compile_definitions(picoc_unix PUBLIC UNIX_HOST)
target_compile_options(picoc_unix PUBLIC -Wall -g3 -O0)
add_custom_command(TARGET picoc_unix  POST_BUILD COMMAND cd ${CMAKE_SOURCE_DIR}/tests && make  )
########################################################################################
####### FREERTOS_HOST #########

add_executable (picoc_freertos
picoc.c table.c lex.c parse.c expression.c heap.c type.c variable.c clibrary.c platform.c include.c debug.c 
platform/platform_freertos.c platform/library_freertos.c 
cstdlib/stdio.c cstdlib/math.c cstdlib/string.c cstdlib/stdlib.c cstdlib/time.c cstdlib/errno.c cstdlib/ctype.c cstdlib/stdbool.c cstdlib/unistd.c)
target_link_libraries(picoc_freertos m readline)
target_compile_definitions(picoc_freertos PUBLIC FREERTOS_HOST)
target_compile_options(picoc_freertos PUBLIC -Wall -g3 -O0)

