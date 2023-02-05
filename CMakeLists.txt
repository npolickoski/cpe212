# CMakeLists files in this project can
# I think this is what they have on BlackHawk
cmake_minimum_required (VERSION 2.4)
project(CPE212)

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (Project01)
add_subdirectory (Project02)
add_subdirectory (Project03)