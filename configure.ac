AC_PREREQ([2.71])
AC_INIT([fidolio], [0.0.1], [scottcombs@me.com])
AC_CONFIG_SRCDIR([src/main.cc])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs

# Compiler variable override
if test -z $CXXFLAGS; then
    CXXFLAGS='-g'
fi

# Use g++ compiler
AC_PROG_CXX

# Checks for libraries
PKG_CHECK_MODULES([GTK4], gtkmm-4.0, [], AC_MSG_ERROR([Failed to find GTK4]))

# Checks for header files

# Checks for typedefs, structures, and compiler characteristics

# Checks for library functions

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
