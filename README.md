# fidolio
An OpenSource writing application

# Building
The fidolio project uses the gnu autotools to generate a make file that compiles and links the application. On Ubuntu you will need to install the autotools packages first and all Gtkmm 4.0 packages.

For a complete list of steps click on the following link:


[Install Packages](https://terminalroot.com/how-to-install-gtkmm-4-on-ubuntu-2204/)

## Scripts
I've provided a suite of bash scripts to facilitate the build process.

- **_scan.sh**

	Regenerates the Makefile.am file by scanning the src and include folders. The previous Makefile.am will be copied to Makefile.am~ file before the regeneration.
- **_clean.sh**

	Removes all generated files except the Makefile.am file.	
- **_configure.sh**

	Runs _clean.sh first and then all the steps necessary for autotools configuration.
- **_build.sh**

	Builds the project and copies the binary to the bin directory.
- **_all.sh**

	A convenience script Runs all the scripts in order.
	