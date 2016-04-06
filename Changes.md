## Changes in release 2011.1 ##

### Gargoyle ###

**New**
  * Native ports are now available for Enlightenment and Open Inkpot.
  * Added Glk 0.7.1 features - line input echo and terminators, window border hint, Unicode decomposition and normalization.
  * Added Glk 0.7.2 features - date and time functions.
  * Added support for Treaty of Babel metadata.

**Fixes**
  * Very small text buffers will now scroll properly.
  * Hyperlinks are now stored with all 32 bits.
  * The background color in grid windows will be fully applied.
  * The scrollback buffer will be truncated on window resize to improve responsiveness.
  * Games will no longer hang after launch under OS X 10.7 (Lion).
  * The bundled Liberation Mono fonts were incorrectly marked as proportional and have been updated.

<p><br /></p>
### Interpreters ###

**New**
  * Bocfel 0.6.0 added for Z-Machine stories.
  * Bocfel is now the default Z-Machine interpreter.
  * Glulxe is now the default Glulx interpreter for Superglús story files.
  * ScottFree 1.14 added for SAGA stories.
  * Command line flags for interpreters are now supported in garglk.ini.

**Updates**
  * Alan 3 updated to 3.0b2.
  * JACL updated to 2.8.5.
  * Glulxe updated to 0.4.7.
  * Git updated to 1.2.9.
  * Level 9 updated to 5.1.

**Fixes**
  * Frotz now handles the fixed width bit in the header correctly.
  * Frotz now repositions the cursor after writing to the final grid column.
  * Geas now displays menus correctly.
  * TADS now implements the banner API.
  * TADS now supports Unicode.
  * TADS now allows timer events during line and character input.

<p><br /></p>

---

## Changes in release 2010.1 ##

### Gargoyle ###

**New**
  * Now available for Mac OS X 10.4 and later.
  * New default fonts: Linux Libertine and Liberation Mono.
  * Added Unicode, true color support to Frotz.
  * Added support for mouse and trackpad scrolling.
  * Added floating point support to Git, Glulxe.
  * New graphical launcher under Linux.
  * New propfont, monofont directives to load installed OS fonts.
  * Automatic bold / oblique applied to incomplete font families.

**Fixes**
  * Text buffers are now repainted appropriately.
  * Multiple text buffers can be selected and scrolled properly.
  * More consistent status line colors, behavior across interpreters.
  * The directive to specify default interpreters now works everywhere.
  * The scrollback buffer will now be resized dynamically during play.
  * Each platform now uses high resolution timers.
  * Images are now scaled with alpha-weighted RGB values.
  * Files opened in append will follow Glk rather than POSIX behavior.
  * Image loading and text rendering should be significantly faster.

<p><br /></p>
### Interpreters ###

**Updates**
  * Agility updated to 1.1.1.1.
  * Alan updated to 3.0a8.
  * Frotz updated to 2.5.0.
  * Git updated to 1.2.8.
  * Glulxe updated to 0.4.6.
  * JACL updated to 2.8.1.

**Fixes**
  * Agility incorporates the latest Glk changes from Simon Baldwin.
  * Alan now handles sound, graphics correctly.
  * Frotz should now conform to the Z-Machine Standard 1.1.
  * Git no longer crashes after undo, restore on 64-bit systems.
  * Hugo will now distinguish bold and italic font styles.
  * Level 9 now tries harder to find graphics.
  * TADS 2 no longer crashes on 64-bit systems.

<p><br /></p>

---


## Changes in release 08-25-09 ##

### Gargoyle ###

**New**
  * Added color support for Frotz / Z-Machine.
  * Added copy / paste support to and from the text buffer.
  * Added Glk hyperlinks support.
  * Delete key now removes input characters to the right of the cursor.
  * Enabled extended character input under Gtk / Linux.
  * Transcripts now created as UTF-8 text files.

**Fixes**
  * Event handling now properly queues events for later dispatch.
  * Colors in games with multiple text buffers are now handled properly.
  * Gargoyle settings file can now be saved under ~/.config directory.

<p><br /></p>
### Interpreters ###

**Updates**
  * Git updated to 1.2.4.
  * Glulxe updated to 0.4.4.
  * JACL updated to 2.5.2.
  * TADS updated to 2.5.13 / 3.0.18.1.

**Fixes**
  * Alan function names no longer clash with the standard C library.
  * Alan interpreters no longer crash when invoked with a different name.
  * Alan stack code updated to handle 64-bit memory pointers.
  * Frotz will now return all characters requested by read operations.
  * Frotz no longer crashes on unusually long status lines.
  * Frotz now resets the status line height properly in certain games.
  * Hugo no longer crashes when launched without arguments.
  * Level 9 builds properly under GCC 4.3.3 and later.

<p><br /></p>

---


## Changes in release 12-25-08 ##

### Gargoyle ###

**New**
  * Added Unicode support to conform with Glk 0.7.  Enables indexed text for Glulx-based story files.
  * Added support for reverse style hints.  Adjusted default ini settings to compensate.
  * Implemented buffered playback for Ogg / MP3 audio.
  * Added settings for default Glulx / Z Machine interpreters to ini.

**Fixes**
  * Wide input lines no longer corrupt right margin.
  * Automatically appends .sav for save files and .txt for transcript files on Windows.
  * Discards duplicate line inputs from command history.
  * No longer truncates certain whitespace used for formatting.
  * Resolved crash when playing audio files.
  * Resolved crash when loading jpeg files under Windows Vista.
  * Resolved crash when destroying save/restore dialog under Linux.

<p><br /></p>
### Interpreters ###

**New**
  * Geas 0.4 added for Quest stories.
  * JACL 2.3.14 added for JACL stories.
  * Nitfol 0.5 included.

**Updates**
  * Alan 3 updated to 3.0 alpha 6.
  * Git updated to 1.2.1.
  * Glulxe updated to 0.4.3.
  * Hugo updated to 3.1.03.
  * Level 9 updated to 4.1.
  * Magnetic Scrolls updated to 2.3.
  * Scare updated to 1.3.10.
  * TADS updated to 2.5.12 / 3.0.16.

**Fixes**
  * Agility builds properly under Linux.
  * Agility closes when the Glk window is closed.
  * Frotz updates window height after Glk window is resized.
  * Frotz converts CR to newline before printing via Glk.
  * Merged patches from Simon Baldwin's IFP project.
  * Various 64-bit compatibility fixes applied.