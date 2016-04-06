# Developers #

This document provides platform-specific steps for developers interested in compiling Gargoyle from source code.

  * [Windows](Developers#Windows.md)
  * [Ubuntu](Developers#Ubuntu.md)
  * [FreeBSD](Developers#FreeBSD.md)
  * [Mac](Developers#Mac.md)


Please note: these steps are meant for advanced users only. Just about everyone will find the binary packages more useful. The most recent release can always be found on the Downloads tab.

<p><br /></p>

## Windows ##

Because Windows does not ship with a compiler, you will need to download one. Gargoyle works best with the C / C++ compilers from [GCC](http://en.wikipedia.org/wiki/GNU_Compiler_Collection), which has been ported to Windows by the [MinGW](http://www.mingw.org/) project.

The official MinGW release contains a very old version of GCC. You may prefer more recent packages from [nuwen.net](http://nuwen.net/mingw.html) or [tdragon.net](http://www.tdragon.net/recentgcc/) instead.

Once downloaded, extract the MinGW files to **C:\MinGW**. Then add **C:\MinGW\bin** to your **PATH** environment variable.


---


Gargoyle uses Jam to manage the build process. Download [FT Jam for Windows](http://sourceforge.net/projects/freetype/files/ftjam/2.5.2/ftjam-2.5.2-win32.zip/download). Extract **ftjam.exe** to your **C:\MinGW\bin** folder so that it lives with the rest of the toolchain.

Now create a new environment variable called **JAM\_TOOLSET**. Set the value to **MINGW**.


---


[NSIS](http://nsis.sourceforge.net/Main_Page) generates the Windows package. You should install the latest release, along with the [FontName plug-in](http://nsis.sourceforge.net/FontName_plug-in).

Once installed, add **C:\Program Files\NSIS** to your **PATH** environment variable.


---


You will need a Subversion client to retrieve the project source code. [TortoiseSVN](http://tortoisesvn.tigris.org/) is a popular client for Windows that integrates well with Explorer.

With Tortoise installed, right-click a target folder and choose **SVN Checkout**. Enter the path to the repository:

```
http://garglk.googlecode.com/svn/trunk/
```

(If you have commit access, use HTTPS instead of HTTP to check out a read-write copy.)

After retrieving the source code, double-click **gargoyle\_win32.cmd** to compile the latest version of Gargoyle. This will create a Windows install package.


---


Before making changes to source code, you may wish to install an IDE that offers features such as syntax highlighting and automatic indentation.

[Visual C++ Express](http://www.microsoft.com/express/windows/) is a good choice. After installing, go to _Tools_ -> _Options_ -> _Text Editor_ -> _C/C++_ -> _Tabs_ and select the option to **Insert spaces**.

If you choose a different IDE or editor, please find and enable the equivalent option. Each tab should be represented by four spaces. That will make life a little easier if you submit a patch.

<p><br /></p>

### Ubuntu ###

Before compiling Gargoyle from source, you will need to install several packages containing the necessary headers for software development.

Open a Terminal window and enter these commands.

```
sudo apt-get install ftjam
sudo apt-get install subversion
sudo apt-get install libjpeg-dev
sudo apt-get install libpng-dev
sudo apt-get install libsdl-mixer1.2-dev
sudo apt-get install libsdl-sound1.2-dev
sudo apt-get install libfreetype6-dev
sudo apt-get install libgtk2.0-dev
sudo apt-get install ttf-liberation
sudo apt-get install ttf-linux-libertine
```

When prompted to install other dependencies, choose Yes.


---


With the tools and headers installed, you can now check out the source code.

```
svn co http://garglk.googlecode.com/svn/trunk/ garglk
```

(If you have commit access, use HTTPS instead of HTTP to check out a read-write copy.)

The source files will be checked out to a **garglk** folder in the working directory. Modify the last argument as appropriate to pick a different destination.

When the checkout finishes, you can use these commands to compile the latest version of Gargoyle.

```
cd garglk
jam install
cp garglk/garglk.ini build/dist
```


---


To run the compiled version of Gargoyle, use these commands.

```
cd build/dist
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./gargoyle
```

For a more permanent installation, please see the INSTALL document found in the root of the source code tree.

<p><br /></p>


### FreeBSD ###

If you wish to compile gargoyle from sources, just edit Jamrules and add:

```
OS = BSD ;
```

and before case LINUX :

add:

```
case BSD :
        Echo "OS is BSD ($(GUILIB))" ;
        if $(GUILIB) = EFL {
            PKGCONFIG = "pkg-config freetype2 evas ecore ecore-evas elementary fontconfig" ;
        } else {
            PKGCONFIG = "pkg-config freetype2 gtk+-x11-2.0 gdk-x11-2.0 gobject-2.0 glib-2.0 fontconfig" ;
        }
        GARGLKCCFLAGS = "`$(PKGCONFIG) --cflags`" -fPIC ;
        GARGLKLIBS = "`$(PKGCONFIG) --libs`" -ljpeg -lpng -lz ;
        LINKLIBS = -lz -lm "`$(PKGCONFIG) --libs`" ;

        if $(USESDL) = yes
        {
            GARGLKCCFLAGS += -I/usr/include/SDL ;
            GARGLKLIBS += -lSDL_mixer -lSDL_sound -lSDL -lsmpeg -lvorbisfile ;
        }

        if $(STATIC) { LINKLIBS += $(GARGLKLIBS) ; }
        else      { SHRLINKLIBS += $(GARGLKLIBS) ; }
```


## Mac ##

Apple ships compilers as part of its Xcode suite, which can be downloaded from [ADC](http://connect.apple.com). The correct version of Xcode depends on the OS X version you have installed.

| **OS X** | **Name** | **Xcode** |
|:---------|:---------|:----------|
| 10.4     | Tiger    | 2.5       |
| 10.5     | Leopard  | 3.1       |
| 10.6     | Snow Leopard | 3.2       |
| 10.7     | Lion     | 4.1       |

Once Xcode has been installed, you will need to download and install [Macports](http://www.macports.org/install.php). This provides access to the libraries required to build Gargoyle.


---


With Xcode and Macports installed, you are ready to build the libraries. Open a Terminal window and enter these commands.

```
sudo port install freetype +universal
sudo port install libpng +universal
sudo port install jpeg +universal
sudo port install libsdl +no_x11 +universal
sudo port install libiconv +universal
sudo port install pkgconfig
sudo port install libsdl_mixer +universal
sudo port install ftjam
```

You can omit the +universal flag if you do not need to build Gargoyle with support for multiple CPU architectures.

Note that many of pkgconfig's dependencies do not build correctly when passed the +universal argument, so you should omit it when building pkgconfig for the first time.


---


Once you have finished building the libraries, you are ready to check out the Gargoyle source code.

```
svn co http://garglk.googlecode.com/svn/trunk/ garglk
```

(If you have commit access, use HTTPS instead of HTTP to check out a read-write copy.)

The source files will be checked out to a **garglk** folder in the working directory. Modify the last argument as appropriate to pick a different destination.

When the checkout finishes, you can use these commands to compile the latest version of Gargoyle.

```
cd garglk
chmod +x gargoyle_osx.sh
./gargoyle_osx.sh
```


---


To run the compiled version of Gargoyle, use these commands.

```
cd Gargoyle.app/Contents/MacOS
./Gargoyle
```

The build script creates a Gargoyle bundle which can be dropped in your Applications folder. It also creates a DMG archive for distribution.